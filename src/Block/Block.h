#ifndef BLOCK_H
#define BLOCK_H

#include "../Transaction/Transaction.h"
#include "../MerkleTree/MerkleTree.h"
#include <string>
#include "../Sha3/Sha256.h"
#include <vector>
#include <iostream>
#include "../Miner/Miner.h"
class Block {
private:
    int blockNumber;
    MerkleTree merkleRoot;
    std::string blockHash;
    std::string prevBlockHash;
    std::vector<Transaction> transactions;
    int nonce;
    char minerId;

    Block* _prev;
    Block* _next;
public:
    Block(std::vector<Transaction>& transactions, Block* prev);
    Block(Block* prev);
    ~Block();

    void insert(Transaction transaction);
    int getBlockNumber();
    void setMiner(char minerId);
    void print();
    bool empty();
    bool full();

    Block* prev();
    Block* next();
};

#endif