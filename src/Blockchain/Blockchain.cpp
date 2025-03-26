#include "Blockchain.h"

Blockchain::Blockchain() {
    this->blocks = std::vector<Block>();
}

Blockchain::~Blockchain() {
    // TODO destructor
}


void Blockchain::insert(Block block) {
    this->blocks.push_back(block);
}

void Blockchain::print() {
    std::cout << " == Blockchain == " << std::endl;
    for (auto& block : this->blocks)
        block.print();
    std::cout << std::endl;
}

Block* Blockchain::tail() {
    if (this->blocks.empty())
        return NULL;
    return &(*(this->blocks.rbegin()));
}