import torch
import argparse
import random
import math
from random import shuffle
from collections import Counter
from huffman import HuffmanCoding

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

def Analogical_Reasoning_Task(embedding):
#######################  Input  #########################
# embedding : Word embedding (type:torch.tesnor(V,D))   #
#########################################################
    
    pass

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

def skipgram_HS(centerWord, contextCode, inputMatrix, outputMatrix):
################################  Input  ##########################################
# centerWord : Index of a centerword (type:int)                                   #
# contextCode : Code of a contextword (type:str)                                  #
# inputMatrix : Weight matrix of input (type:torch.tesnor(V,D))                   #
# outputMatrix : Activated weight matrix of output (type:torch.tesnor(K,D))       #
###################################################################################

###############################  Output  ##########################################
# loss : Loss value (type:torch.tensor(1))                                        #
# grad_in : Gradient of inputMatrix (type:torch.tensor(1,D))                      #
# grad_out : Gradient of outputMatrix (type:torch.tesnor(K,D))                    #
###################################################################################
    V, D = inputMatrix.size()
    K, _ = outputMatrix.size()
    inputVector = inputMatrix[centerWord].reshape(D, 1)   #(D, 1)
    p = 1
    grad = torch.ones(K, D)
    grad2 = torch.zeros(1, D)
    for i in range(len(contextCode)):
        p *= torch.sigmoid(hsF(contextCode[i]) * outputMatrix[i].reshape(1, D).mm(inputVector))
        grad[i] = grad[i] * (torch.sigmoid(outputMatrix[i].reshape(1, D).mm(inputVector))-tt(contextCode[i])) * inputMatrix[centerWord]
        grad2 += (torch.sigmoid(outputMatrix[i].reshape(1, D).mm(inputVector))-tt(contextCode[i])) * outputMatrix[i]
    loss = - torch.log(p)

    grad_out = grad
    grad_in = grad2
    

    return loss, grad_in, grad_out



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


def CBOW_HS(contextWords, centerCode, inputMatrix, outputMatrix):
################################  Input  ##########################################
# contextWords : Indices of contextwords (type:list(int))                          #
# centerCode : Code of a centerword (type:str)                                    #
# inputMatrix : Weight matrix of input (type:torch.tesnor(V,D))                   #
# outputMatrix : Activated Weight matrix of output (type:torch.tesnor(K,D))       #
###################################################################################

###############################  Output  ##########################################
# loss : Loss value (type:torch.tensor(1))                                        #
# grad_in : Gradient of inputMatrix (type:torch.tensor(1,D))                      #
# grad_out : Gradient of outputMatrix (type:torch.tesnor(K,D))                    #
###################################################################################

    V, D = inputMatrix.size()
    K, _ = outputMatrix.size()
    inputVector = inputMatrix[contextWords].sum(0).reshape(D, 1)
    
    p = 1
    grad = torch.ones(K, D)
    grad2 = torch.zeros(1, D)
    for i in range(len(centerCode)):
        p *= torch.sigmoid(hsF(centerCode[i]) * outputMatrix[i].reshape(1, D).mm(inputVector))
        grad[i] = grad[i] * (torch.sigmoid(outputMatrix[i].reshape(1, D).mm(inputVector))-tt(centerCode[i])) * inputMatrix[contextWords].sum(0)
        grad2 += (torch.sigmoid(outputMatrix[i].reshape(1, D).mm(inputVector))-tt(centerCode[i])) * outputMatrix[i]
    loss = - torch.log(p)

    grad_out = grad
    grad_in = grad2

    return loss, grad_in, grad_out


def CBOW_NS(contextWords, inputMatrix, outputMatrix):
################################  Input  ##########################################
# contextWords : Indices of contextwords (type:list(int))                          #
# inputMatrix : Weight matrix of input (type:torch.tesnor(V,D))                   #
# outputMatrix : Activated Weight matrix of output (type:torch.tesnor(K,D))       #
###################################################################################

###############################  Output  ##########################################
# loss : Loss value (type:torch.tensor(1))                                        #
# grad_in : Gradient of inputMatrix (type:torch.tensor(1,D))                      #
# grad_out : Gradient of outputMatrix (type:torch.tesnor(K,D))                    #
###################################################################################
    V, D = inputMatrix.size()
    K, _ = outputMatrix.size()
    inputVector = inputMatrix[contextWords].sum(0)    
    
    errfunc = torch.sigmoid(outputMatrix[0].reshape(1, D).mm(inputVector.view(D, 1)))
    for i in range(K):
        if i > 0:
            errfunc *= 1 - torch.sigmoid(outputMatrix[i].reshape(1, D).mm(inputVector.view(D, 1)))
        
    loss = -torch.log(errfunc)

    grad = torch.ones(K, 1) * errfunc
    grad[0] -= 1
    grad_out = grad.mm(inputVector.view(1, -1))
    
    grad_in = grad.view(1, -1).mm(outputMatrix.view(1, -1))

    return loss, grad_in, grad_out


def word2vec_trainer(input_seq, target_seq, numwords, codes, stats, mode="CBOW", NS=20, dimension=100, learning_rate=0.025, epoch=3):
# train_seq : list(tuple(int, list(int))

# Xavier initialization of weight matrices
    W_in = torch.randn(numwords, dimension) / (dimension**0.5)
    numword2 = 2**25
    if NS == 0:
        W_out = torch.randn(numword2, dimension) / (dimension**0.5)
    else:
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
            if mode=="CBOW":
                if NS==0:
                    #Only use the activated rows of the weight matrix
                    #activated should be torch.tensor(K,) so that activated W_out has the form of torch.tensor(K, D)
                    idx = 0
                    activated = []
                    for item in codes[output]:
                        activated.append(idx)
                        if item == '0':
                            idx = idx * 2 + 1
                        else:
                            idx = idx * 2 + 2
                    L, G_in, G_out = CBOW_HS(inputs, codes[output], W_in, W_out[activated])
                    W_in[inputs] -= learning_rate*G_in
                    W_out[activated] -= learning_rate*G_out
                else:
                    #Only use the activated rows of the weight matrix
                    #activated should be torch.tensor(K,) so that activated W_out has the form of torch.tensor(K, D)
                    activated =[output]
                    sampleArr = random.sample(range(len(stats)), NS)
                    for i in sampleArr:
                        activated.append(stats[i])
                    L, G_in, G_out = CBOW_NS(inputs, W_in, W_out[activated])
                    W_in[inputs] -= learning_rate*G_in
                    W_out[activated] -= learning_rate*G_out

            elif mode=="SG":
                if NS==0:
                    #Only use the activated rows of the weight matrix
                    #activated should be torch.tensor(K,) so that activated W_out has the form of torch.tensor(K, D)
                    idx = 0
                    activated = []
                    for item in codes[output]:
                        activated.append(idx)
                        if item == '0':
                            idx = idx * 2 + 1
                        else:
                            idx = idx * 2 + 2
                    L, G_in, G_out = skipgram_HS(inputs, codes[output], W_in, W_out[activated])
                    W_in[inputs] -= learning_rate*G_in.squeeze()
                    W_out[activated] -= learning_rate*G_out
                else:
                    #Only use the activated rows of the weight matrix
                    #activated should be torch.tensor(K,) so that activated W_out has the form of torch.tensor(K, D)
                    activated =[output]
                    sampleArr = random.sample(range(len(stats)), NS)
                    for j in sampleArr:
                        activated.append(stats[j])
                    L, G_in, G_out = skipgram_NS(inputs, W_in, W_out[activated])
                    W_in[inputs] -= learning_rate*G_in.squeeze()
                    W_out[activated] -= learning_rate*G_out

                
            else:
                print("Unkwnown mode : "+mode)
                exit()
            losses.append(L.item())
            if i%50000==0:
            	avg_loss=sum(losses)/len(losses)
            	print("Loss : %f" %(avg_loss,))
            	losses=[]

    return W_in, W_out

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

def main():
    parser = argparse.ArgumentParser(description='Word2vec')
    parser.add_argument('mode', metavar='mode', type=str,
                        help='"SG" for skipgram, "CBOW" for CBOW')
    parser.add_argument('ns', metavar='negative_samples', type=int,
                        help='0 for hierarchical softmax, the other numbers would be the number of negative samples')
    parser.add_argument('part', metavar='partition', type=str,
                        help='"part" if you want to train on a part of corpus, "full" if you want to train on full corpus')
    args = parser.parse_args()
    mode = args.mode
    part = args.part
    ns = args.ns

	#Load and preprocess corpus
    print("loading...")
    if part=="part":
        text = open('text8',mode='r').readlines()[0][:1000000] #Load a part of corpus for debugging
    elif part=="full":
        text = open('text8',mode='r').readlines()[0] #Load full corpus for submission
    else:
        print("Unknown argument : " + part)
        exit()

    print("preprocessing...")
    corpus = subsampling(text.split())
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


    #Code dict for hierarchical softmax
    freqdict={}
    freqdict[0]=10
    for word in vocab:
        freqdict[w2i[word]]=stats[word]
    codedict = HuffmanCoding().build(freqdict)

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
    window_size = 5
    if mode=="CBOW":
        for j in range(len(words)):
            if j<window_size:
                input_set.append([0 for _ in range(window_size-j)] + [w2i[words[k]] for k in range(j)] + [w2i[words[j+k+1]] for k in range(window_size)])
                target_set.append(w2i[words[j]])
            elif j>=len(words)-window_size:
                input_set.append([w2i[words[j-k-1]] for k in range(window_size)] + [w2i[words[len(words)-k-1]] for k in range(len(words)-j-1)] + [0 for _ in range(j+window_size-len(words)+1)])
                target_set.append(w2i[words[j]])
            else:
                input_set.append([w2i[words[j-k-1]] for k in range(window_size)] + [w2i[words[j+k+1]] for k in range(window_size)])
                target_set.append(w2i[words[j]])
    if mode=="SG":
        for j in range(len(words)):
            if j<window_size:
                input_set += [w2i[words[j]] for _ in range(window_size*2)]
                target_set += [0 for _ in range(window_size-j)] + [w2i[words[k]] for k in range(j)] + [w2i[words[j+k+1]] for k in range(window_size)]
            elif j>=len(words)-window_size:
                input_set += [w2i[words[j]] for _ in range(window_size*2)]
                target_set += [w2i[words[j-k-1]] for k in range(window_size)] + [w2i[words[len(words)-k-1]] for k in range(len(words)-j-1)] + [0 for _ in range(j+window_size-len(words)+1)]
            else:
                input_set += [w2i[words[j]] for _ in range(window_size*2)]
                target_set += [w2i[words[j-k-1]] for k in range(window_size)] + [w2i[words[j+k+1]] for k in range(window_size)]

    print("Vocabulary size")
    print(len(w2i))
    print()

    #Training section
    emb,_ = word2vec_trainer(input_set, target_set, len(w2i), codedict, freqtable, mode=mode, NS=ns, dimension=64, epoch=1, learning_rate=0.01)
    testwords = ["one", "are", "he", "have", "many", "first", "all", "world", "people", "after"]
    for tw in testwords:
    	sim(tw,w2i,i2w,emb)
    Analogical_Reasoning_Task(emb)

main()