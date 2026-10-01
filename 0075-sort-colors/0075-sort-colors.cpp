class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int i = -1;

        // Move all 0s to the beginning
        for (int j = 0; j < n; j++) {

            if (nums[j] == 0) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        // Position after all 0s
        int k = i + 1;

        // Move all 1s after 0s
        for (int j = k; j < n; j++) {

            if (nums[j] == 1) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
    }
};
