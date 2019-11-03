# NLP Assignment #2
Korea Univ.COSE461 Assignment #2

implement of Neural Network, NOT using numpy.

__What I Did__
- Implement CBOW
- Implement Skip-gram

Implement skip-gram and CBOW models in word2vec.py
If you run "word2vec.py", you can train and test your models.
--------------------------------------------------------------------------------------------------
How to run

python word2vec.py [mode] [partition]

mode : "SG" for skipgram, "CBOW" for CBOW
partition : "part" if you want to train on a part of corpus (fast training but worse performance), 
             "full" if you want to train on full corpus (better performance but very slow training)

Examples) 
python word2vec.py SG part
python word2vec.py CBOW part
python word2vec.py SG full
python word2vec.py CBOW full