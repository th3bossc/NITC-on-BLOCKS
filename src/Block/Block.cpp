#include "Block.h"

Block::Block(std::vector<Transaction>& transactions, Block* prev) {
    this->blockNumber = blockNumber;
    this->merkleRoot = MerkleTree(transactions);
    this->prevBlockHash = prevBlockHash;
    this->transactions = transactions;

    if (prev) {
        this->blockNumber = prev->blockNumber + 1;
        this->prevBlockHash = prev->blockHash;
    }
    else {
        this->blockNumber = 1;
        this->prevBlockHash = "0";
    }
    this->blockHash = Sha256::generateHash(this->prevBlockHash + std::to_string(this->blockNumber) + this->merkleRoot.get());
}

Block::~Block() {
    // TODO implement destructor
}

int Block::getBlockNumber() {
    return this->blockNumber;
}

void Block::print() {
    std::cout << blockNumber << std::endl;
    std::cout << blockHash << std::endl;
    std::cout << '[';
    for (auto& transaction : transactions)
        transaction.print();
    std::cout << ']';
    std::cout << std::endl;
    std::cout << merkleRoot.get() << std::endl;
}