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
public:
    Block(std::vector<Transaction>& transactions, Block* prev);
    ~Block();

    int getBlockNumber();
    void setMiner(char minerId);
    void print();
};

#endif