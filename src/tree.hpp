#ifndef TREE_HPP
#define TREE_HPP
#include "node.hpp"
#include <string>

class Tree {
private:
    Node* root;
    void deleteTree(Node* node);
    Node* findById(Node* node, int id);
    Node* findCurrentBoss(Node* node);
    Node* findInSubtree(Node* node, bool allowJail);
    bool isValid(Node* node, bool allowJail);

public:
    Tree();
    ~Tree();
    void loadCSV(const std::string& filename);
    void insert(Node* newNode);
    void showSuccession(Node* node);
    void updateBoss();
    void editNode(int targetId);
    Node* getRoot();
};
#endif
