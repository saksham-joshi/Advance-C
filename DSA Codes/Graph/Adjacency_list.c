#include<stdio.h>
#include<stdlib.h>


#define NO_OF_NODES (unsigned short int) 3


struct Node
{
    int _node_num;
    int* _list;
} 
NODE_ARRAY__[NO_OF_NODES];



inline void destroyNodeArray()
{
    struct Node* node_array_iterator = NODE_ARRAY__;

    for(int i = 0 ; i < NO_OF_NODES ; ++i , ++node_array_iterator) free(node_array_iterator->_list);
}

inline void displayGraph()
{
    printf("\n |+| Edges in the given graph are :- ");

    struct Node* node_array_iterator = NODE_ARRAY__;

    for(int i = 0 ; i < NO_OF_NODES ; ++i , ++node_array_iterator)
    {
        int* list_iterator = node_array_iterator->_list;

        char current_node = 65 + node_array_iterator->_node_num;

        printf("\n\t> ");

        for(int j = 0 ; j < NO_OF_NODES && *list_iterator != -1 ; ++j , ++list_iterator)
        {
            printf("%c%c | ",current_node, 65 + *list_iterator);
        }
        
    }
}



int main(void)
{
    struct Node *node_array_iterator = NODE_ARRAY__;

    for(int i = 0 ; i < NO_OF_NODES ; ++i)
    {
        node_array_iterator->_node_num = i;
        node_array_iterator->_list = (int*) calloc(NO_OF_NODES , sizeof(struct Node));

        printf("\n ==> Enter the nodes connected with '%c' which are adjacent to nodes(enter -1 to stop) :- \n", 65+i);

        int* list_iterator = node_array_iterator->_list;

        for(int j = 0 ; j < NO_OF_NODES ; ++j , ++list_iterator)
        {
            printf("\t->_");
            scanf_s("%d", list_iterator);
            if(*list_iterator == -1) break;
        }
        
        ++node_array_iterator;
    }

    displayGraph();

    destroyNodeArray();

    printf("\n\n |=| Program executed successfully! |=|");

    return 0;
}