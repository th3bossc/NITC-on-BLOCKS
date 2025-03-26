#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "../Block/Block.h"
#include <iostream>
class Blockchain {
private:
    std::vector<Block> blocks;

public:
    Blockchain();
    ~Blockchain();
    void insert(Block block);
    void print();

    Block* tail();

};


#endif