/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 static int minDepth(struct TreeNode* __root)
 {
     if ( __root )
     {
         int height_of_left_tree = minDepth ( __root->left );
 
         int height_of_right_tree = minDepth ( __root->right );
 
         if ( height_of_left_tree && height_of_right_tree ) return 1 + (height_of_left_tree < height_of_right_tree ? height_of_left_tree : height_of_right_tree);
 
         else if ( height_of_left_tree ) return 1 + height_of_left_tree;
 
         else if ( height_of_right_tree ) return 1 + height_of_right_tree;
 
         return 1;
     }
 
     return 0;
 }