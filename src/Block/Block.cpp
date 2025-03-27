#include "Block.h"

Block::Block(std::vector<Transaction>& transactions, Block* prev) {
    this->merkleRoot = MerkleTree(transactions);
    this->transactions = transactions;

    if (prev) {
        this->blockNumber = prev->blockNumber + 1;
        this->prevBlockHash = prev->blockHash;
    }
    else {
        this->blockNumber = 1;
        this->prevBlockHash = "0";
    }

    std::stringstream ss;
    ss << this->prevBlockHash << this->blockNumber << this->merkleRoot.get();

    std::string hash = Sha256::generateHash(ss.str());

    int nonce = 0;
    while (true) {
        std::string hashWithNonce = Sha256::generateHash(hash + std::to_string(nonce));
        if (hashWithNonce.back() == '0') {
            break;
        }

        nonce++;
    }

    this->blockHash = hash;
    this->nonce = nonce;

    this->_prev = prev;
    this->_next = NULL;
    if (prev != NULL)
        prev->_next = this;
}

Block::Block(Block* prev) {
    this->merkleRoot = MerkleTree();
    this->transactions = std::vector<Transaction>();

    if (prev) {
        this->blockNumber = prev->blockNumber + 1;
        this->prevBlockHash = prev->blockHash;
    }
    else {
        this->blockNumber = 1;
        this->prevBlockHash = "0";
    }


    this->_prev = prev;
    this->_next = NULL;
    if (prev != NULL)
        prev->_next = this;
}

Block::~Block() {
    // TODO implement destructor
}

void Block::insert(Transaction transaction) {
    this->transactions.push_back(transaction);
    this->merkleRoot.insert(transaction);

    std::stringstream ss;
    ss << this->prevBlockHash << this->blockNumber << this->merkleRoot.get();

    std::string hash = Sha256::generateHash(ss.str());

    int nonce = 0;
    while (true) {
        std::string hashWithNonce = Sha256::generateHash(hash + std::to_string(nonce));
        if (hashWithNonce.back() == '0') {
            break;
        }

        nonce++;
    }

    this->blockHash = hash;
    this->nonce = nonce;
}


int Block::getBlockNumber() {
    return this->blockNumber;
}

void Block::setMiner(char minerId) {
    this->minerId = minerId;
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
    std::cout << nonce << ' ' << minerId << std::endl;
}

bool Block::empty() {
    return this->merkleRoot.length() == 0;
}

bool Block::full() {
    return this->merkleRoot.length() == NUM_TRANSACTIONS_PER_NODE;
}

Block* Block::prev() {
    return _prev;
}

Block* Block::next() {
    return _next;
}