#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include <string>
#include "../Transaction/Transaction.h"
#include <vector>

class MerkleNode {
private:
    std::string value;
    MerkleNode* left;
    MerkleNode* right;

public:
    MerkleNode(std::string value, MerkleNode* left, MerkleNode* right);
    MerkleNode(std::string value);
    ~MerkleNode();

    std::string get();
    MerkleNode* getLeft();
    MerkleNode* getRight();
};

class MerkleTree {
private:
    MerkleNode* root;
    int numNodes;
    MerkleNode* createRootNode(std::string value, MerkleNode* left, MerkleNode* right);
    MerkleNode* createLeafNode(std::string value);
    MerkleNode* createInternalNode(std::string value, MerkleNode* left, MerkleNode* right);
public:
    MerkleTree();
    MerkleTree(std::vector<Transaction> transactions);
    ~MerkleTree();

    bool insert(Transaction transaction);
    std::string get();
    void print();
    int length();
};

#endif