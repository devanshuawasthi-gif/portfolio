class Solution:
    def maxVowels(self, s, k):
        vowels = "aeiou"
        count = 0

        #Count vowel
        for i in range(k):
            if s[i] in vowels:
                count += 1
        maximum = count

        #slide the window
        for i in range(k, len(s)):
            if s[i] in vowels:
                count += 1
            if s[i - k] in vowels:
                count -= 1
            if count > maximum:
                maximum = count
        return maximum
