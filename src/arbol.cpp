#include "tree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Tree::Tree() : root(nullptr) {}

Tree::~Tree() { deleteTree(root); }

void Tree::deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

Node* Tree::findById(Node* node, int id) {
    if (!node || node->id == id) return node;
    Node* found = findById(node->left, id);
    if (found) return found;
    return findById(node->right, id);
}

void Tree::insert(Node* newNode) {
    if (!root) { root = newNode; return; }
    Node* boss = findById(root, newNode->id_boss);
    if (boss) {
        newNode->parent = boss;
        if (!boss->left) boss->left = newNode;
        else if (!boss->right) boss->right = newNode;
    }
}

void Tree::loadCSV(const string& filename) {
    ifstream file(filename);
    string line, val;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, val, ','); int id = stoi(val);
        Node* n = new Node(id);
        getline(ss, n->name, ',');
        getline(ss, n->last_name, ',');
        getline(ss, val, ','); n->gender = val[0];
        getline(ss, val, ','); n->age = stoi(val);
        getline(ss, val, ','); n->id_boss = stoi(val);
        getline(ss, val, ','); n->is_dead = (val == "1");
        getline(ss, val, ','); n->in_jail = (val == "1");
        getline(ss, val, ','); n->was_boss = (val == "1");
        getline(ss, val, ','); n->is_boss = (val == "1");
        insert(n);
    }
}

bool Tree::isValid(Node* node, bool allowJail) {
    if (!node || node->is_dead) return false;
    if (!allowJail && node->in_jail) return false;
    return true;
}

Node* Tree::findInSubtree(Node* node, bool allowJail) {
    if (!node) return nullptr;
    if (isValid(node, allowJail)) return node;
    Node* res = findInSubtree(node->left, allowJail);
    if (res) return res;
    return findInSubtree(node->right, allowJail);
}

Node* Tree::findCurrentBoss(Node* node) {
    if (!node) return nullptr;
    if (node->is_boss) return node;
    Node* found = findCurrentBoss(node->left);
    if (found) return found;
    return findCurrentBoss(node->right);
}

void Tree::updateBoss() {
    Node* boss = findCurrentBoss(root);
    if (!boss) return;

    if (boss->is_dead || boss->in_jail || boss->age > 70) {
        Node* replacement = nullptr;
        replacement = findInSubtree(boss->left, false);
        if (!replacement) replacement = findInSubtree(boss->right, false);
        
        if (!replacement) replacement = findInSubtree(boss, true);

        if (replacement) {
            boss->is_boss = false;
            boss->was_boss = true;
            replacement->is_boss = true;
            cout << "\n[!] SUCCESSION: " << replacement->name << " is the new Boss.\n";
        }
    }
}

void Tree::editNode(int id) {
    Node* target = findById(root, id);
    if (!target) { cout << "Member not found.\n"; return; }
    cout << "Editing " << target->name << ". New age: ";
    cin >> target->age;
    cout << "Is dead (0/1): "; cin >> target->is_dead;
    cout << "In jail (0/1): "; cin >> target->in_jail;
    updateBoss(); 
}

void Tree::showSuccession(Node* node) {
    if (!node) return;
    if (!node->is_dead) cout << "- " << node->name << " " << node->last_name << (node->is_boss ? " [BOSS]" : "") << endl;
    showSuccession(node->left);
    showSuccession(node->right);
}

Node* Tree::getRoot() { return root; }
