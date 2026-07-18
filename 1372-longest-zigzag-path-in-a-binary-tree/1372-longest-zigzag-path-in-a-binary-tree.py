class Solution:
    def longestZigZag(self, root):
        self.ans = 0
        def dfs(node, leftLength, rightLength):
            if not node:
                return
            self.ans = max(self.ans, leftLength, rightLength)
            # move to left child
            dfs(node.left, 0, leftLength + 1)
            #move to right child
            dfs(node.right, rightLength + 1, 0)
        dfs(root, 0, 0)
        return self.ans