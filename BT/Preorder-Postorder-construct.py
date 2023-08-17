
# 889. Construct Binary Tree from Preorder and Postorder Traversal


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructFromPrePost(self, preorder: list[int], postorder: list[int]) -> TreeNode:
        # pre:  1 | 2 4 5 | 3 6 7  root->left->right
        # post: 4 5 2 | 6 7 3 | 1  left->right->root

        """
        For preorder & postorder traversal lists, the root node is very easy to find, but 
        unlike inorder traversal there is an issue of finding elements for the left and right subtrees.
        After studying some examples, one can observe a pattern where the left child of the root node in preorder list(index=1) is at the end of left subtree in postorder list.
        Therefore, we get the index of the left child to partition the elements of the left and right subtree using < idx = postorder.index(preorder[1]) > and its pretty much straightforward from this point onwards.

        """
        if not preorder or not postorder:
            return None

        if len(preorder) == 1:
            return TreeNode(preorder[0])

        root = TreeNode(preorder[0])
        idx = postorder.index(preorder[1])

        root.left = self.constructFromPrePost(preorder[1 : idx+2], postorder[ : idx+1])
        root.right = self.constructFromPrePost(preorder[idx+2 : ], postorder[idx+1 : -1])

        return root