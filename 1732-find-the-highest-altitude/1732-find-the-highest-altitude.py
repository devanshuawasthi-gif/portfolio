class Solution:
    def largestAltitude(self, gain):
        altitude = 0
        highest = 0
        for g in gain:
            altitude += g
            if altitude > highest:
                highest = altitude
        return highest
        