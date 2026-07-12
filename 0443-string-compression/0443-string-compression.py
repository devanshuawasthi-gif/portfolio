class Solution:
    def compress(self, chars):
        ans = []
        count = 1

        for i in range(len(chars)):
            if i < len(chars) - 1 and chars[i] == chars[i + 1]:
                count += 1
            else:
                ans.append(chars[i])

                if count > 1:
                    for digit in str(count):
                        ans.append(digit)

                count = 1

        for i in range(len(ans)):
            chars[i] = ans[i]

        return len(ans)