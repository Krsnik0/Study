import torch
import argparse
import random
import math
import operator
import sys
import csv
import copy
from random import shuffle
from collections import Counter

_HASH_LEN = 21

def sampledHash(word):
    return hash(word) & ((1 << _HASH_LEN) -1)

def printProgress (iteration, total, prefix = '', suffix = '', decimals = 1, barLength = 100): 
    formatStr = "{0:." + str(decimals) + "f}" 
    percent = formatStr.format(100 * (iteration / float(total))) 
    filledLength = int(round(barLength * iteration / float(total))) 
    bar = '#' * filledLength + '-' * (barLength - filledLength) 
    sys.stdout.write('\r%s |%s| %s%s %s' % (prefix, bar, percent, '%', suffix)), 
    if iteration == total: 
        sys.stdout.write('\n') 
    sys.stdout.flush()

def classifyTest(W_in, W_out):
    text = open('test.csv', mode = 'r', encoding = 'utf-8').readlines()

    print("Test preprocessing...")
    readcsv = csv.reader(text)
    text_list = list(readcsv)

    #Make training set
    print("Test build training set...")
    input_set = []
    target_set = []
    for text in text_list:
        target_set += text[0]
        #delete word '-'
        title = text[1].split()
        news = text[2].split()
        for word in title:
            if word == '-':
                del title[title.index(word)]
        for word in news:
            if word == '-':
                del news[news.index(word)]
        #make input data set with pre-processed hash value
        input_tmp = []
        for i in range(len(title) - 1):
            input_tmp += [sampledHash(title[i] + '-' + title[i + 1])]
        for j in range(len(news) - 1):
            input_tmp += [sampledHash(news[j] + '-' + news[j + 1])]
        input_set.append(input_tmp)
    
    print("Test input size")
    print(len(input_set))

    f = open('test_result.txt', 'w')
    i = 0
    numans = 0
    for inputs, answer in zip(input_set, target_set):
        i += 1
        value = list(W_out.mm((W_in[inputs].sum(0)).view(-1, 1)).squeeze())
        predict = value.index(max(value))
        if int(answer) == (predict + 1):
            numans += 1
            f.write('#' + str(i) + ' - Collect answer: Predict: ' + str(predict + 1) + ', Answer: ' + str(answer) + '\n')
        else:
            f.write('#' + str(i) + ' - Wrong answer: Predict: ' + str(predict + 1) + ', Answer: ' + str(answer) + '\n')
        printProgress(i, len(input_set), 'Progress:', 'Complete', 1, 50)
    print('\n Result: ' + str(numans) + ' is collect, ' + "%0.2f%%" %(numans/len(input_set)*100) + 'accuracy')
    f.write('\n Result: ' + str(numans) + ' is collect, ' + "%0.2f%%" %(numans/len(input_set)*100) + 'accuracy')
    f.close()
        
def learning(answer, inputMatrix, outputMatrix):
################################  Input  ##########################################
# answer : Index of a type. 1-World 2-Sports 3-Business 4-Sci/Tech(type:int)      #
# inputMatrix : Weight matrix of input (type:torch.tesnor(K,D))                   #
# outputMatrix : Activated weight matrix of output (type:torch.tesnor(4,D))       #
###################################################################################

###############################  Output  ##########################################
# loss : Loss value (type:torch.tensor(1))                                        #
# grad_in : Gradient of inputMatrix (type:torch.tensor(K,D))                      #
# grad_out : Gradient of outputMatrix (type:torch.tesnor(4,D))                    #
###################################################################################
    _, D = inputMatrix.size()
    inputVector = inputMatrix.sum(0)
    out = outputMatrix.mm(inputVector.view(D, 1))
    expout = torch.exp(out)
    softmax = expout / expout.sum()         #(4, 1)

    loss = -torch.log(softmax[answer - 1])  #answer : 1~4, we should change this to idx

    grad = softmax
    grad[answer - 1] -= 1

    grad_in = grad.view(1,-1).mm(outputMatrix)
    grad_out = grad.mm(inputVector.view(1,-1))

    return loss, grad_in, grad_out

def fastText_classifier(input_seq, target_seq, numAns, dimension=100, learning_rate=0.025, epoch=3):
# Xavier initialization of weight matrices
    W_in = torch.randn((1 << _HASH_LEN), dimension) / (dimension**0.5)
    W_out = torch.randn(numAns, dimension) / (dimension**0.5)
    i=0
    losses=[]
    print("# of training samples")
    print(len(input_seq))
    print()
    #stats = torch.LongTensor(stats)

    for _ in range(epoch):
        #Training word2vec using SGD(Batch size : 1)
        for inputs, output in zip(input_seq,target_seq):
            i+=1
            #Only use the activated rows of the weight matrix
            #activated should be torch.tensor(K,) so that activated W_out has the form of torch.tensor(K, D)
            L, G_in, G_out = learning(int(output), W_in[inputs], W_out)
            W_in[inputs] -= learning_rate*G_in.squeeze()
            W_out -= learning_rate*G_out

            losses.append(L.item())

            printProgress(i, len(input_seq), 'Progress:', 'Complete', 1, 50)
            if i%10000==0:
            	avg_loss=sum(losses)/len(losses)
            	print(" Loss : %f" %(avg_loss,))
            	losses=[]

    return W_in, W_out

def main():
    parser = argparse.ArgumentParser(description='fastClassify')
    parser.add_argument('part', metavar='partition', type=str,
                        help='"part" if you want to train on a part of corpus, "full" if you want to train on full corpus')
    args = parser.parse_args()
    part = args.part

	#Load and preprocess corpus
    print("loading...")
    if part=="part":
        text = open('train.csv', mode = 'r', encoding = 'utf-8').readlines()[:10000] #Load a part of corpus for debugging, total is 120000
    elif part=="full":
        text = open('train.csv', mode = 'r', encoding = 'utf-8').readlines() #Load full corpus for submission
    else:
        print("Unknown argument : " + part)
        exit()

    print("preprocessing...")
    readcsv = csv.reader(text)
    text_list = list(readcsv)

    #Make training set
    print("build training set...")
    input_set = []
    target_set = []
    for text in text_list:
        target_set += text[0]
        #delete word '-'
        title = text[1].split()
        news = text[2].split()
        for word in title:
            if word == '-':
                del title[title.index(word)]
        for word in news:
            if word == '-':
                del news[news.index(word)]
        #make input data set with pre-processed hash value
        input_tmp = []
        for i in range(len(title) - 1):
            input_tmp += [sampledHash(title[i] + '-' + title[i + 1])]
        for j in range(len(news) - 1):
            input_tmp += [sampledHash(news[j] + '-' + news[j + 1])]
        input_set.append(input_tmp)
    
    print("Input size")
    print(len(input_set))
    print("Hash table size")
    print(_HASH_LEN)
    print()

    #Training section
    W_in, W_out = fastText_classifier(input_set, target_set, numAns = 4, dimension=64, epoch=1, learning_rate=0.01)

    print("Training end")
    print()
    print()

    classifyTest(W_in, W_out)    


main()