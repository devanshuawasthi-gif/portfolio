class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0 , end = nums.size()-1 , mid;

        while (start <= end)
        {
            mid = start + (end - start)/2;

            if (nums[mid]==target){ // if the curr idx is the target , return 
                return mid;
            }

            // check if the left side is sorted 

            if (nums[start] <= nums [mid]){
                // check if the nums present in the sorted left side 
                // eg start -> mid
                if ( nums[start] <= target  && target<= nums[mid]){
                    end = mid -1 ; // move the end to search the left side only
                }
                else {
                    start = mid +1;
                    // else move the start to search the right side 
                }
            }
            
            else {
                // else right side must be sorted 
                // eg mid -> end 
                if ( nums[mid]<= target && target <= nums[end]){
                    start = mid + 1 ; // move start to find the right side 
                }
                else {
                    end = mid -1 ;
                }
            }

        }
        return -1;
    }
};