import torch
import argparse
import random
import math
import operator
import sys
from random import shuffle
from collections import Counter

_HASH_LEN = 21
_WINDOW_SIZE = 5

_TEST_WORD = ['narrowmindedness', 'department', 'campfires', 'knowing', 'urbanize', 'imperfection', 'principality', 'abnormal', 'secondary', 'ungraceful']

def hsF(num):
    if num == '0':
        return 1
    else:
        return -1

def tt(num):
    if num == '0':
        return 1
    else:
        return 0

def subword(word):
    sub = []
    for i in range(3, 7):
        for j in range(len(word) - (i - 1)):
            if i >len(word):
                break
            sub.append(sampledHash(word[j:j+i]))
    sub.append(sampledHash(word))
    return sub

def sampledHash(word):
    return hash(word) & ((1 << _HASH_LEN) -1)

def wordVector(word, W_in):
    vec = subword(word)
    val = torch.zeros(1, 64)
    for item in vec:
        val += W_in[item]
    return val

def cosineSim(wv1, wv2):
    mul = torch.mul(wv1, wv2)
    #mulabs = torch.sqrt(torch.sum(torch.mul(mul, mul)))
    wv1abs = torch.rsqrt(torch.sum(torch.mul(wv1, wv1)))
    wv2abs = torch.rsqrt(torch.sum(torch.mul(wv2, wv2)))
    return mul * wv1abs * wv2abs

def test(wordList, vocab, w2i, i2w, W_in):
    for w in wordList:
        cosList = {}
        for voc in vocab:
            wordVec = wordVector('<' + w + '>', W_in)
            vocabVec = wordVector(voc, W_in)
            cosList[w2i[voc]] = cosineSim(wordVec, vocabVec)
        sortedArr = sorted(cosList.items(), key=operator.itemgetter(1), reverse = True)[0:5]
        print("===============================================")
        print("The most similar words to \"" + w + "\"")
        for item in sortedArr:
            print(i2w[item[0]][1:-1] + '\t: ' + str(item[1].float()))
        print("===============================================")
        print()

    return

def sim(testword, word2ind, ind2word, matrix):
    length = (matrix*matrix).sum(1)**0.5
    wi = word2ind[testword]
    inputVector = matrix[wi].reshape(1,-1)/length[wi]
    sim = (inputVector@matrix.t())[0]/length
    values, indices = sim.squeeze().topk(5)
    
    print()
    print("===============================================")
    print("The most similar words to \"" + testword + "\"")
    for ind, val in zip(indices,values):
        print(ind2word[ind.item()]+":%.3f"%(val,))
    print("===============================================")
    print()

def printProgress (iteration, total, prefix = '', suffix = '', decimals = 1, barLength = 100): 
    formatStr = "{0:." + str(decimals) + "f}" 
    percent = formatStr.format(100 * (iteration / float(total))) 
    filledLength = int(round(barLength * iteration / float(total))) 
    bar = '#' * filledLength + '-' * (barLength - filledLength) 
    sys.stdout.write('\r%s |%s| %s%s %s' % (prefix, bar, percent, '%', suffix)), 
    if iteration == total: 
        sys.stdout.write('\n') 
    sys.stdout.flush()

def subsampling(word_seq):
###############################  Output  #########################################
# subsampled : Subsampled sequence                                               #
##################################################################################
    t = 1.0e-5
    #word_seq => corpus
    stats = Counter(word_seq)
    subsampled = []
    for i in range(len(word_seq)):
        p = 1 - math.sqrt(t/(stats[word_seq[i]]/len(word_seq)))
        if random.random() >= p:
            subsampled.append(word_seq[i])
    return subsampled

def skipgram_NS(centerWord, inputMatrix, outputMatrix):
################################  Input  ##########################################
# centerWord : Index of a centerword (type:int)                                   #
# inputMatrix : Weight matrix of input (type:torch.tesnor(V,D))                   #
# outputMatrix : Activated weight matrix of output (type:torch.tesnor(K,D))       #
###################################################################################

###############################  Output  ##########################################
# loss : Loss value (type:torch.tensor(1))                                        #
# grad_in : Gradient of inputMatrix (type:torch.tensor(1,D))                      #
# grad_out : Gradient of outputMatrix (type:torch.tesnor(K,D))                    #
###################################################################################
    #0: ans, others: negative samples
    K, D = outputMatrix.size()
    inputVector = inputMatrix[centerWord]
    
    errfunc = torch.sigmoid(outputMatrix[0].reshape(1, D).mm(inputVector.view(D, 1)))
    grad_in = torch.zeros(1, D)
    grad_in += -1 * (1 - errfunc) * outputMatrix[0]
    grad_out = torch.ones(K, D)
    grad_out[0] = grad_out[0] * ( -1 * (1 - errfunc) * inputVector)

    for i in range(K):
        if i > 0:
            errfunc *= 1 - torch.sigmoid(outputMatrix[i].reshape(1, D).mm(inputVector.view(D, 1)))
            grad_out[i] = grad_out[i] * (torch.sigmoid(outputMatrix[i].reshape(1, D).mm(inputVector.view(D, 1))) * inputVector)
        grad_in += torch.sigmoid(outputMatrix[i].reshape(1, D).mm(inputVector.view(D, 1))) * outputMatrix[i]
        
    loss = -torch.log(errfunc)

    return loss, grad_in, grad_out

def word2vec_trainer(input_seq, target_seq, numwords, stats, NS=20, dimension=100, learning_rate=0.025, epoch=3):
    # train_seq : list(tuple(int, list(int))

# Xavier initialization of weight matrices
    W_in = torch.randn((1 << _HASH_LEN), dimension) / (dimension**0.5)
    W_out = torch.randn(numwords, dimension) / (dimension**0.5)
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
            activated =[output]
            sampleArr = random.sample(range(len(stats)), NS)
            for j in sampleArr:
                activated.append(stats[j])
            L, G_in, G_out = skipgram_NS(inputs, W_in, W_out[activated])
            W_in[inputs] -= learning_rate*G_in.squeeze()
            W_out[activated] -= learning_rate*G_out

            losses.append(L.item())
            printProgress(i, len(input_seq), 'Progress:', 'Complete', 1, 50)
            if i%50000==0:
            	avg_loss=sum(losses)/len(losses)
            	print(" Loss : %f" %(avg_loss,))
            	losses=[]

    return W_in, W_out

def main():
    parser = argparse.ArgumentParser(description='Word2vec')
    parser.add_argument('ns', metavar='negative_samples', type=int,
                        help='0 for hierarchical softmax, the other numbers would be the number of negative samples')
    parser.add_argument('part', metavar='partition', type=str,
                        help='"part" if you want to train on a part of corpus, "full" if you want to train on full corpus')
    args = parser.parse_args()
    part = args.part
    ns = args.ns

    if ns <= 0:
        print("Invalid argument: " + ns + "\n(put num over 0, 20 is recommended")
        exit()

	#Load and preprocess corpus
    print("loading...")
    if part=="part":
        text = open('text8',mode='r').readlines()[0][:5000000] #Load a part of corpus for debugging
    elif part=="full":
        text = open('text8',mode='r').readlines()[0] #Load full corpus for submission
    else:
        print("Unknown argument : " + part)
        exit()

    print("preprocessing...")
    corpus = subsampling(text.split())
    #corpus = text.split()
    corpus = [('<' + w + '>') for w in corpus]
    stats = Counter(corpus)
    words = []


    #Discard rare words
    for word in corpus:
        if stats[word]>4:
            words.append(word)

    vocab = set(words)

    #Give an index number to a word
    w2i = {}
    w2i[" "]=0
    i = 1
    for word in vocab:
        w2i[word] = i
        i+=1
    i2w = {}
    for k,v in w2i.items():
        i2w[v]=k

    #Frequency table for negative sampling
    freqtable = [0,0,0]
    for k,v in stats.items():
        f = int(v**0.75)
        for _ in range(f):
            if k in w2i.keys():
                freqtable.append(w2i[k])

    #Make training set
    print("build training set...")
    input_set = []
    target_set = []
    
    for j in range(len(words)):
        hashValue = subword(words[j])
        if j<_WINDOW_SIZE:
            for item in hashValue:
                input_set += [item for _ in range(_WINDOW_SIZE*2)]    
                target_set += [0 for _ in range(_WINDOW_SIZE-j)] + [w2i[words[k]] for k in range(j)] + [w2i[words[j+k+1]] for k in range(_WINDOW_SIZE)]
        elif j>=len(words)-_WINDOW_SIZE:
            for item in hashValue:
                input_set += [item for _ in range(_WINDOW_SIZE*2)]
                target_set += [w2i[words[j-k-1]] for k in range(_WINDOW_SIZE)] + [w2i[words[len(words)-k-1]] for k in range(len(words)-j-1)] + [0 for _ in range(j+_WINDOW_SIZE-len(words)+1)]
        else:
            for item in hashValue:
                input_set += [item for _ in range(_WINDOW_SIZE*2)]
                target_set += [w2i[words[j-k-1]] for k in range(_WINDOW_SIZE)] + [w2i[words[j+k+1]] for k in range(_WINDOW_SIZE)]

    print("Vocabulary size")
    print(len(w2i))
    print()

    #Training section
    W_in , _ = word2vec_trainer(input_set, target_set, len(w2i), freqtable, NS=ns, dimension=64, epoch=1, learning_rate=0.01)

    test(_TEST_WORD, vocab, w2i, i2w, W_in)

main()