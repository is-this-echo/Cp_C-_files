
# 106. Construct Binary Tree from Inorder and Postorder Traversal


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, inorder: list[int], postorder: list[int]) -> TreeNode:
        
        if not inorder or not postorder: 
            return None 
        
        root = TreeNode(postorder[-1])
        idx = inorder.index(postorder[-1])
        
        tree_size = len(postorder)
        
        root.left = self.buildTree(inorder[:idx], postorder[:idx])
        root.right = self.buildTree(inorder[idx+1:], postorder[idx:tree_size-1])
        # root.right = self.buildTree(inorder[idx+1:], postorder[idx:-1])
        
        return root