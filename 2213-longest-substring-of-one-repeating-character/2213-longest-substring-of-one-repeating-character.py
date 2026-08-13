class Solution:
    def longestRepeating(self, s, queryCharacters, queryIndices):
        n = len(s)
        s = list(s)
        tree = [[0, 0, 0, 0, 0, 0] for _ in range(4 * n)]
        def merge(node):
            left = tree[node * 2]
            right = tree[node * 2 + 1]
            lchar = left[0]
            rchar = right[1]
            prefix = left[2]
            suffix = right[3]
            best = max(left[4], right[4])
            if left[1] == right[0]:
                best = max(best, left[3] + right[2])
                if left[2] == left[5]:
                    prefix = left[5] + right[2]
                if right[3] == right[5]:
                    suffix = right[5] + left[3]
            tree[node] = [
                lchar,
                rchar,
                prefix,
                suffix,
                best,
                left[5] + right[5]
            ]
        def build(node, l, r):
            if l == r:
                c = ord(s[l]) - ord('a')
                tree[node] = [
                    c,
                    c,
                    1,
                    1,
                    1, 
                    1   
                ]
                return
            mid = (l + r) // 2
            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)
            merge(node)
        def update(node, l, r, pos, char):
            if l == r:
                c = ord(char) - ord('a')
                tree[node] = [
                    c,
                    c,
                    1,
                    1,
                    1,
                    1
                ]
                return
            mid = (l + r) // 2
            if pos <= mid:
                update(node * 2, l, mid, pos, char)
            else:
                update(node * 2 + 1, mid + 1, r, pos, char)
            merge(node)
        build(1, 0, n - 1)
        answer = []
        for i in range(len(queryIndices)):
            index = queryIndices[i]
            char = queryCharacters[i]
            s[index] = char
            update(1, 0, n - 1, index, char)
            answer.append(tree[1][4])
        return answer