class Solution:
    def closeStrings(self, word1, word2):
        if len(word1) != len(word2):
            return False

        freq1 = {}
        freq2 = {}

        for ch in word1:
            freq1[ch] = freq1.get(ch, 0) + 1

        for ch in word2:
            freq2[ch] = freq2.get(ch, 0) + 1

        if set(freq1.keys()) != set(freq2.keys()):
            return False

        return sorted(freq1.values()) == sorted(freq2.values())
