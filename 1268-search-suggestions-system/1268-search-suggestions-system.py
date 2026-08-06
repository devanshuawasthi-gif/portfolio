class Solution:
    def suggestedProducts(self, products, searchWord):
        products.sort()
        ans = []

        prefix = ""

        for ch in searchWord:
            prefix += ch
            temp = []

            for word in products:
                if word.startswith(prefix):
                    temp.append(word)
                if len(temp) == 3:
                    break

            ans.append(temp)

        return ans