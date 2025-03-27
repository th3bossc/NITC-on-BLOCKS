#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "../Block/Block.h"
#include <iostream>
#include <algorithm>
class Blockchain {
private:
    Block* _head;
    Block* _tail;
    std::vector<Miner> miners;
    int blockReward;

    void appendBlock(Block* block);

public:
    Blockchain();
    Blockchain(std::vector<Miner>& miners, int blockReward);
    ~Blockchain();
    void insert(Transaction& transaction);
    void attachMiner(Miner& miner);
    void detachMiner(Miner& miner);
    void print();
    Miner* getMinerForBlock(Block& block);

    void validate();

    Block* tail();

};


#endif