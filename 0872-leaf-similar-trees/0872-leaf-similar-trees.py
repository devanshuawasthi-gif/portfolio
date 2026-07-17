class Solution(object):
    def leafSimilar(self,  root1, root2):
        def getLeaves(root, leaves):
            if root is None:
                return
            if root.left is None and root.right is None:
                leaves.append(root.val)
                return
            getLeaves(root.left, leaves)
            getLeaves(root.right, leaves)
        leaves1 = []
        leaves2 = []
        getLeaves(root1, leaves1)
        getLeaves(root2, leaves2)
        return leaves1 == leaves2
        
            
        