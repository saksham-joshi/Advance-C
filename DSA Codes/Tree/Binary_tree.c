#include "Tree.h"
#include<conio.h>

#define printTree( __message , __order_func , __root_node ) \
        printf (" \n | " __message " -- [ " ); \
        __order_func( __root_node ); \
        puts(" ]");


inline static void insertNode ( NodePtr_t __root , NodeData_t __data)
{
    if ( !__root )
    {
        errno = EPERM;
        perror("Root node is null");
        return;
    }

    NodePtr_t new_node = generateNode( __data );

    if ( ! new_node ) return;

    do 
    {
        if ( ! __root->_left ) { __root->_left = new_node; break; }

        else if ( ! __root->_right ) { __root->_right = new_node; break; }

        else 
        {
            printf("\n Press 1 to go left, else to go right :- ");

            __root = ( _getche() == '1') ? __root->_left : __root->_right;
        }

    } while ( 1 ) ;
    
}

static NodePtr_t searchTree( NodePtr_t __root , NodeData_t __value)
{
    if ( __root && __root->_data != __value )
    {
        NodePtr_t output = searchTree( __root->_left , __value);

        if ( output ) return output;

        return searchTree( __root->_right , __value);
    }

    // if @__root is NULL or @__value is found at __root.
    return __root;
}

inline static NodePtr_t extractLeafNode ( NodePtr_t __node )
{
    if ( __node )
    {
        NodePtr_t output = NULL;

        if ( isLeafNode( __node->_left) )
        {
            output = __node->_left;
            __node->_left = NULL;
        }
        else if ( isLeafNode( __node->_right ) )
        {
            output = __node->_right;
            __node->_right = NULL;
        }
        else 
        {
            output = extractLeafNode( __node->_left );

            if ( output ) return output;

            output = extractLeafNode( __node->_right);
        }

        return output;
    }

    return NULL;
}

inline static _Bool baseDeleteNodeFromTree( NodePtr_t __root , NodeData_t __value )
{
    // if root is not null
    if ( __root )
    {

        // and root's left's data is same as __value
        if ( __root->_left && __root->_left->_data == __value )
        {
            // and root's left is leaf node
            if ( isLeafNode( __root->_left ))
            {
                free( __root->_left);
                __root->_left = NULL;
                
            }

            // and root's left is not a leaf  nodee
            else 
            {
                NodePtr_t leaf_node = extractLeafNode( __root->_left );

                leaf_node->_left = __root->_left->_left;
                leaf_node->_right = __root->_left->_right;

                free( __root->_left );
                __root->_left = leaf_node;
            }

            return TRUE;
        }

        // and root's left's data is same as __value
        else if ( __root->_right && __root->_right->_data == __value )
        {

            // and it is a leaf node
            if ( isLeafNode( __root->_right) )
            {
                free ( __root->_right);
                __root->_right = NULL;
            }

            // and it is not a leaf node
            else 
            {
                NodePtr_t leaf_node = extractLeafNode( __root->_right );

                leaf_node->_left = __root->_right->_left;
                leaf_node->_right = __root->_right->_right;

                free( __root->_right );
                __root->_right = leaf_node;
            }
            
            return TRUE;

        }

        // root->_left or root->_right are null or data is not found in them.
        
        if ( baseDeleteNodeFromTree( __root->_left , __value) ) return TRUE;

        return baseDeleteNodeFromTree( __root->_right , __value );

    }

    return FALSE;
}

inline static _Bool deleteNodeFromTree( BinaryTree* __tree , NodeData_t __value )
{
    if ( !__tree->_root )
    {
        errno = EPERM;
        perror("Root node is null");

        return FALSE;
    }

    // if __value is found at root
    else if ( __tree->_root && __tree->_root->_data == __value)
    {
        NodePtr_t new_root = NULL;

        // if  and left and right is non-null
        if ( __tree->_root->_left && __tree->_root->_right )
        {
            
            // and left node is leaf node 
            if ( isLeafNode( __tree->_root->_left) )
            {
                new_root = __tree->_root->_left;
                new_root->_right = __tree->_root->_right;
            }

            // and right node is leaf node 
            else if ( isLeafNode( __tree->_root->_right ) )
            {
                new_root = __tree->_root->_right;
                new_root->_left = __tree->_root->_left;
            }

            // and both left and right node are not leaf node
            else 
            {
                new_root = extractLeafNode( __tree->_root );
                new_root->_left = __tree->_root->_left;
                new_root->_right = __tree->_root->_right;
            }

            free ( __tree->_root );
            __tree->_root = new_root;
        }

        // if __value is at root and only left is non-null
        else if ( __tree->_root->_left )
        {
            new_root = __tree->_root->_left;
            free( __tree->_root);
            __tree->_root = new_root;
        }

        // if __value is at root and only right is non-null
        else if ( __tree->_root->_right )
        {
            new_root = __tree->_root->_right;
            free ( __tree->_root );
            __tree->_root = new_root;
        }

        // if __value is at root and both left and right are null
        else 
        {
            free ( __tree->_root );
            __tree->_root = NULL;
        }

        return TRUE;

    }

    return baseDeleteNodeFromTree( __tree->_root , __value );    
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

            case 3 : printf_s("\n\t\t [ Value deletion %ssuccessful ]", deleteNodeFromTree( &tree , getInput("\n ==> Enter the value to delete :- ") ) ? "" : "not "); break;
            
            case 4 : printf_s("\n\t\t [ Value %sfound ]", searchTree( tree._root , getInput("\n ==> Enter the value to search :- ") ) ? "" : "not "); break;

            case 5 : printTree ("In-order", inOrderPrint, tree._root ); break;

            case 6 : printTree ("Pre-order", preOrderPrint, tree._root ); break;

            case 7 : printTree ("Post-order", postOrderPrint, tree._root ); break;

            case 8 : printf("\n Height of tree = %u" , heightOfTree( tree._root ) ); break;

            default: printf("\n |=| Invalid choice!"); return 0;
        }

        if ( ! errno ) printf("\n\t |+| Operation done Succesfully |+| \n");
        else errno = 0;
    }

    destroyTree( tree._root );

    return 0;

}