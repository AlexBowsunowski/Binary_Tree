//
// Created by aleksandr on 02.05.2021.
//

#ifndef TASK8_TREE_H
#define TASK8_TREE_H

typedef struct link {
    int id;
    int weigth;
    link *left, *right;
}tree;

tree* add_node(tree* Tree, int element, int weight);
tree* min_node(tree* Tree);
int remove_node(tree**Tree, int element);
void show(tree* Tree, int n);
void zero_way(tree* Tree);
void console_command();

#endif //TASK8_TREE_H
