class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        // if(nums[left] > nums[right]) {
        //     int mid = left + (right - left) / 2;
        //     if(nums[mid] <= nums[left] && nums[right] > nums[mid]) {
        //         left++;
        //     } else {
        //         left = mid+1;
        //     }
        // }
        while(nums[left] > nums[right]) {
                left++;      
        }
        
        if(target > nums[right]) {
            right = left - 1;
            left = 0;
        }
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
