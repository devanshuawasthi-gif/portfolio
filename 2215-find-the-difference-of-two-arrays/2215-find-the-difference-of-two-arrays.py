class Solution:
    def findDifference(self, nums1, nums2):
        set1 = set(nums1)
        set2 = set(nums2)
        ans1 = []
        ans2 = []
        for x in set1:
            if x not in set2:
                ans1.append(x)
        for x in set2:
            if x not in set1:
                ans2.append(x)
        return [ans1, ans2]