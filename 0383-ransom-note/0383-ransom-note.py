class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        # Create a dictionary to store character counts
        dictionary = {}

        # Iterate through the magazine and count characters
        for char in magazine:
            if char not in dictionary:
                dictionary[char] = 1
            else:
                dictionary[char] += 1

        # Iterate through the ransom note and check character counts
        for char in ransomNote:
            if char in dictionary and dictionary[char] > 0:
                dictionary[char] -= 1
            else:
                return False
        
        return True