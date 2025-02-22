#include "Tree.h"

inline static void insertNode ( NodePtr_t __root , NodeData_t __value )
{
    if ( __root )
    {
        while ( __root && __root->_data != __value)
        {
            if ( __root->_right && __root->_data < __value ) __root = __root->_right;
            
            else if ( __root->_left && __root->_data > __value ) __root = __root->_left;

            else
            {
                NodePtr_t new_node = generateNode ( __value );

                if ( new_node ) (__root->_data < __value) ? ( __root->_right = new_node ): ( __root->_left = new_node );

                break;
            }
        }
    }
    else 
    {
        errno = EPERM;
        perror("Cannot insert value because root node is null");
    }
}

inline static NodePtr_t searchTree( NodePtr_t __root , NodeData_t __value )
{
    if ( __root )
    {
        if ( __root->_data == __value ) return __root;

        else if ( __root->_data < __value ) return searchTree( __root->_right , __value);

        else return searchTree( __root->_left , __value );
    }

    return NULL;
}


static NodePtr_t findReplacementNode ( NodePtr_t __node)
{
    NodePtr_t iterator = __node;
    NodePtr_t output = NULL;

    while ( iterator )
    {
        // if ( isHalfNode( iterator->_right ))
        // {
        //     output = iterator->_right;
        //     iterator->_right = iterator->_right->_left ? iterator->_right->_left : iterator->_right->_right;
        //     break;
        // }
        if ( iterator->_right && isLeafNode( iterator->_right ) )
        {
            output = iterator->_right;
            iterator->_right = NULL;
            break;
        }
        else if ( iterator->_left && isLeafNode( iterator->_left) )
        {
            output = iterator->_left;
            iterator->_left = NULL;
            break;
        }
        
                        
        iterator = iterator->_right ? iterator->_right : iterator->_left;
    }

    puts("Found replacement node");

    return output;
}

inline static void baseDeleteFromTree( NodePtr_t* __parent_pointer , NodePtr_t __node_to_delete )
{
    if ( isLeafNode( __node_to_delete) )
    {
        *__parent_pointer = NULL;
        free( __node_to_delete );
    }
    else if ( isHalfNode( __node_to_delete ) )
    {
        *__parent_pointer = __node_to_delete->_left ? __node_to_delete->_left : __node_to_delete->_right;
        free(__node_to_delete);
    }
    else 
    {
        // if __node_to_delete is a full node
        *__parent_pointer = findReplacementNode( __node_to_delete );
        (*__parent_pointer)->_left = __node_to_delete->_left;
        (*__parent_pointer)->_right = __node_to_delete->_right;
        free ( __node_to_delete );
    }
}

inline static _Bool deleteFromTree ( BinaryTree* __tree , NodeData_t __value )
{
    if ( __tree->_root )
    {
        NodePtr_t new_root = NULL;

        if ( __tree->_root->_data == __value )
        {
            if ( isLeafNode( __tree->_root ) )
            {
                free( __tree->_root );
                __tree->_root = NULL;

                return TRUE;
            }

            else if ( !__tree->_root->_left ) new_root = __tree->_root->_right;
    
            else if ( !__tree->_root->_right ) new_root = __tree->_root->_left;

            // if both left and right are not null
            else 
            {
                // checking if one of the left or right is a leaf or half node ...
                if ( isLeafNode( __tree->_root->_left) || isHalfNode( __tree->_root->_left ) )
                {
                    new_root = __tree->_root->_left;
                    __tree->_root->_left = NULL;
                }
                else if ( isLeafNode ( __tree->_root->_right ) || isHalfNode( __tree->_root->_right ) ) 
                {
                    new_root = __tree->_root->_right;
                    __tree->_root->_right = NULL;
                }

                // now we are confirmed that left and right node are neither leaf nor half node 
                else new_root = findReplacementNode( __tree->_root->_left);
                
            }

            new_root->_left = __tree->_root->_left;
            new_root->_right = __tree->_root->_right;

            free( __tree->_root );
            __tree->_root = new_root;

            return TRUE;
        }

        else 
        {
            NodePtr_t iterator = __tree->_root;

            while ( iterator )
            {
                if ( iterator->_left && iterator->_left->_data == __value )
                {
                    baseDeleteFromTree( &iterator->_left , iterator->_left);
                    return TRUE;
                }

                else if ( iterator->_right && iterator->_right->_data == __value )
                {
                    baseDeleteFromTree( &iterator->_right , iterator->_right);
                    return TRUE;
                }
                
                else if (iterator->_data > __value ) iterator = iterator->_left;

                else if ( iterator->_data < __value ) iterator = iterator->_right;

                else iterator = NULL;
            }
        }

    }

    return FALSE;
}

int main ( void )
{ 
    BinaryTree tree = { 0 };

    unsigned short int choice;

    while ( 1 )
    {
        printf_s(
            "\n [1] Generate Tree"
            "\n [2] Insert"
            "\n [3] Delete"
            "\n [4] Search"
            "\n [5] In-order Print"
            "\n [6] Pre-order Print"
            "\n [7] Post-order Print"
            "\n [8] Get Height\n\t->_"
        );

        scanf_s("%hu", &choice);

        switch(choice)
        {
            case 1 : destroyTree( tree._root ); tree._root = generateNode( getInput(" \n ==> Enter the value for new root :- ") ); break;

            case 2 : insertNode( tree._root , getInput("\n ==> Enter the value :- ")); break;

            case 3 : printf_s("\n\t\t [ Value deletion %ssuccessful ]", deleteFromTree( &tree , getInput("\n ==> Enter the value to delete :- ") ) ? "" : "not "); break;
            
            case 4 : printf_s("\n\t\t [ Value %sfound ]", searchTree( tree._root , getInput("\n ==> Enter the value to search :- ") ) ? "" : "not "); break;

            case 5 : printTree ("In-order", inOrderPrint, tree._root ); break;

            case 6 : printTree ("Pre-order", preOrderPrint, tree._root ); break;

            case 7 : printTree ("Post-order", postOrderPrint, tree._root ); break;

            case 8 : printf("\n Height of tree = %u" , heightOfTree( tree._root ) ); break;

            default: printf("\n |=| Invalid choice!"); return 0;
        }

        if ( errno ) errno = 0;
        else printf("\n\t |+| Operation done Succesfully |+| \n");
    }

    destroyTree( tree._root );

    return 0;

}