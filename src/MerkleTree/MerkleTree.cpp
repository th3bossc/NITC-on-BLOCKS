#include "MerkleTree.h"

MerkleTree::MerkleTree() {
    this->root = NULL;
    this->numNodes = 0;
}

MerkleTree::MerkleTree(std::vector<Transaction> transactions) {
    this->root = NULL;
    this->numNodes = 0;
    for (auto& transaction : transactions)
        this->insert(transaction);
}

MerkleTree::~MerkleTree() {
    // TODO do later
}

bool MerkleTree::insert(Transaction transaction) {
    if (this->numNodes == 0) {
        std::string h1 = transaction.hash();
        auto newNode = this->createRootNode(h1, NULL, NULL);
        if (!newNode)
            return false;
    }
    else if (this->numNodes == 1) {
        std::string h1 = this->root->get();
        std::string h2 = transaction.hash();
        auto newNode = this->createLeafNode(h2);
        if (!newNode)
            return false;
        auto sumHash = this->createRootNode(Sha256::generateHash(h1 + h2), this->root, newNode);
        if (!sumHash)
            return false;
    }
    else if (this->numNodes == 2) {
        std::string h1h2__Value = this->root->get();
        std::string h3 = transaction.hash();
        auto newNode = this->createLeafNode(h3);
        if (!newNode)
            return false;
        auto sumHash = this->createRootNode(Sha256::generateHash(h1h2__Value + h3), this->root, newNode);
        if (!sumHash)
            return false;
    }
    // else if (this->numNodes == 3) {
    //     std::string h1h2__Value = this->root->getLeft()->get();
    //     auto h3Node = this->root->getRight();
    //     std::string h3 = h3Node->get();
    //     std::string h4 = transaction.hash();
    //     std::string h3h4__Value = h3 + h4;


    //     auto newNode = this->createLeafNode(h4);
    //     if (!newNode)
    //         return false;
    //     auto sumHash = this->createInternalNode(Sha256::generateHash(h3h4__Value), h3Node, newNode);
    //     if (!sumHash)
    //         return false;
    //     auto h1h2h3__Node = this->root;
    //     auto newRoot = this->createRootNode(Sha256::generateHash(h1h2__Value + h3h4__Value), this->root->getLeft(), newNode);
    //     if (!newRoot)
    //         return false;
    //     delete h1h2h3__Node;

    // }
    else {
        return false;
    }
    numNodes++;
    return true;
}

std::string MerkleTree::get() {
    return this->root->get();
}

void MerkleTree::print() {
    // TODO print stuff
}

int MerkleTree::length() {
    return this->numNodes;
}

MerkleNode* MerkleTree::createInternalNode(std::string value, MerkleNode* left, MerkleNode* right) {
    return new MerkleNode(value, left, right);
}

MerkleNode* MerkleTree::createRootNode(std::string value, MerkleNode* left, MerkleNode* right) {
    auto node = new MerkleNode(value, left, right);
    this->root = node;
    return node;
}

MerkleNode* MerkleTree::createLeafNode(std::string value) {
    return new MerkleNode(value);
}


MerkleNode::MerkleNode(std::string value, MerkleNode* left, MerkleNode* right) {
    this->value = value;
    this->left = left;
    this->right = right;
}

MerkleNode::MerkleNode(std::string value) {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}

MerkleNode::~MerkleNode() {
    // TODO do destructor
}

std::string MerkleNode::get() {
    return this->value;
}

MerkleNode* MerkleNode::getLeft() {
    return this->left;
}

MerkleNode* MerkleNode::getRight() {
    return this->right;
}



