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

int max_element_with_positive_weight(tree* Tree){
    if (Tree){
        if(Tree->weigth == 1) {
            if (Tree->right)
                return std::max(Tree->id, max_element_with_positive_weight(Tree->right));
            else
                return Tree->id;
        }else if(Tree->weigth != 1 && !Tree->right && !Tree->left){
            return -99999999;
        }else if(Tree->left && Tree->right){
            return std::max(max_element_with_positive_weight(Tree->left), max_element_with_positive_weight(Tree->right));
        }else if(Tree->left){
            return max_element_with_positive_weight(Tree->left);
        }else if(Tree->right){
            return max_element_with_positive_weight(Tree->right);
        }
    }

}

void console_command(){
    std::cout<<"1 el weight - add element\n";
    std::cout<<"2 el - delete element\n";
    std::cout<<"3 - show\n";
    std::cout<<"4 - max element with positive weight\n";
    std::cout<<"5 - cancel\n";
}