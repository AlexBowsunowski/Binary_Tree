#include <iostream>
#include "tree.h"

int main() {
    std::cout<<"0 count_elem- generate random tree\n";
    tree* Tree = NULL;
    int count;
    std::cin>>count;
    for(int i = 0; i < count; ++i){
        int weight = rand() % 3 - 1;
        int num = rand() % 41 - 20;
        Tree = add_node(Tree, num, weight);
    }
    show(Tree, 3);

    console_command();
    int check;
    std::cin>>check;
    int el, weig, a;
    while(check != 5){
        switch (check) {
            case 1:
                std::cin>>el>>weig;
                Tree = add_node(Tree, el, weig);
                break;
            case 2:
                std::cin>>el;
                a = remove_node(&Tree, el);
                std::cout<<a;
                break;
            case 3:
                show(Tree, 3);
                break;
            case 4:
                a = max_element_with_positive_weight(Tree);
                std::cout<<a<<"\n";
                break;
            default:
                break;
        }
        console_command();
        std::cin>>check;
    }
    return 0;
}
