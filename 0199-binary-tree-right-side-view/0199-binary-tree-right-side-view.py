class Solution:
    def rightSideView(self, root):
        if not root:
            return []
        ans = []
        queue = deque([root])

        while queue:
            size = len(queue)

            for i in range(size):
                node = queue.popleft()
                # last node of this evel
                if i == size - 1:
                    ans.append(node.val)
                
                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)
        return ans