#include "tree.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

tree* add_node(tree* Tree, int element, int weight){
    tree *cur = Tree, *par;
    tree *node = (tree*) malloc(sizeof(tree));

    if(!node) return NULL;
    node->left = NULL;
    node->right = NULL;
    node->weigth = weight;
    node->id = element;
    if(!Tree) return node;

    do {
        par = cur;

        cur = element <= par->id ? par->left: par->right;
    }while (cur);

    if(element <= par->id)
        par->left = node;
    else
        par->right = node;
    return Tree;
}

tree* min_node(tree* Tree){
    tree *t = Tree;
    if (!Tree) return NULL;
    while (t->left) t = t->left;
    return  t;
}

int remove_node(tree** Tree, int element){
   if(!*Tree) return -1;

   if (element < (*Tree)->id) return remove_node(&(*Tree)->left, element);
   else if (element > (*Tree)->id) return remove_node(&(*Tree)->right, element);
   else if ((*Tree)->left && (*Tree)->right){
       tree* T = min_node((*Tree)->right);
       (*Tree)->id = T->id;
       (*Tree)->weigth = T->weigth;
       remove_node(&(*Tree)->right, (*Tree)->id);
   }
   else{
       tree* t = *Tree;
       *Tree = (*Tree)->left ? (*Tree)->left : (*Tree)->right;
       free(t);
   }
   return 0;
}

void show(tree *t, int n) {
    if (t != NULL) {
        show(t->left, n + 1);
        std::cout << std::setw(n * 3)<< t->id<<"("<<t->weigth<<")"<< std::endl;
        show(t->right, n + 1);
    }
}

int dfs(tree* t, int curr_weight){
    int id = -1;
    if(curr_weight == 0){
        return t->id;
    }else{
        if(t){
           if(t->left && t->left->weigth != 0){
               id = std::max(dfs(t->left, curr_weight + t->left->weigth),-1);
           }if(t->right && t->right->weigth != 0){
               id = std::max(dfs(t->right, curr_weight + t->right->weigth),-1);
           }
        }
    }
    return id;

}




void zero_way(tree* t){
    if (t->weigth == 0){
        std::cout<<"Nothing\n";
        return;
    }
    int id1 = dfs(t, t->weigth);
    if (id1 == -1) {
        std::cout<<"Nothing\n";
        return;
    }
    tree* cur = t, *par;
    while(cur->id != id1){
        par = cur;
        std::cout<<par->id<<"-";
        cur = id1 <= par->id ? par->left: par->right;
    }
    std::cout<<cur->id<<"\n";
}

void console_command(){
    std::cout<<"1 el weight - add element\n";
    std::cout<<"2 el - delete element\n";
    std::cout<<"3 - show\n";
    std::cout<<"4 - find zero way\n";
    std::cout<<"5 - cancel\n";
}