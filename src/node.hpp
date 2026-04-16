#ifndef NODE_HPP
#define NODE_HPP
#include <string>

struct Node {
    int id;
    std::string name;
    std::string last_name;
    char gender;
    int age;
    int id_boss;
    bool is_dead;
    bool in_jail;
    bool was_boss;
    bool is_boss;

    Node *left, *right, *parent;

    Node(int _id) : id(_id), left(nullptr), right(nullptr), parent(nullptr) {}
};
#endif
