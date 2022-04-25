# Debjyoti Ghosh

    
 # 105. Construct Binary Tree from Preorder and Inorder Traversal

    
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: list[int], inorder: list[int]) -> TreeNode:
        
        if not preorder or not inorder:
            return None
        
        root = TreeNode(preorder[0])
        idx = inorder.index(preorder[0])
        
        root.left = self.buildTree(preorder[1 : idx+1], inorder[: idx])
        root.right = self.buildTree(preorder[idx+1 : ], inorder[idx+1 : ])
        
        return root