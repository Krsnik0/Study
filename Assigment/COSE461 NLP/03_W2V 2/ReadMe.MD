# Word2Vec Implementation
## Hierarchical Softmax
- Assign binary code(Huffman coding)
- Train with only weights connected to the activated nodes
- Return : cost value and gradient of two word vectors
## Negative Sampling
- Frequency table
- Random sampling during training
- Return : cost value and gradient of two word vectors
## Subsampling
- Read(preprocess) corpus and make dictionary
- Subsample corpus in every epoch