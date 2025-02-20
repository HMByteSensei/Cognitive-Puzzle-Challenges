class Solution {
int tp_sum(const std::vector<int> &nums, int mid) {
    int count = 0;
    for(int i=0, j=1; j<nums.size(); j++) {
        if(nums[j] - nums[i] > mid) {
            i++; j--;
        } else {
            count += (j - i);
        }
    }
    return count;
}
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums[nums.size() - 1];
        
        while(left < right) {
            int mid = left + ((right - left) / 2);
            int count = tp_sum(nums, mid);
            std::cout << mid << "    count-> " << count << "\n";
            if(count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
//         // i = svako koji; m = 1-index last index in each step
//         int i = 1, m = nums.size() - 1, n = nums.size() - 1;
//         // int elements = nums.size() - 1;
//         while(m < k) {
//             // std::cout << m << "    " << k << "\n";
//             m = m + (n - i);
//             i++;
//         }
//         // elements = elements - (i - 1);
        
//         if(k >= n)
//             k -= m - (n - (i - 1));
        
//         std::priority_queue<int> pq;
//         std::sort(nums.begin(), nums.end());
        
//         int tmp = i-1;
//         for(; i >= tmp; i--)
//             for(int j=0; j+i<=n; j++) {
//                 if(!pq.empty() && pq.top() > nums[i+j] - nums[j] && pq.size() >= k) {
//                     pq.pop();
//                 } 
//                 if(pq.empty() || pq.size() < k) {
//                     pq.push(nums[i+j] - nums[j]);    
//                 }
//                 std::cout << nums[i+j] - nums[j]<<"      i+j" << i+j<<"   j:"<<j<<"\n";
//             }
        
//         std::cout << "m: "<< m << "\t m- (n-i): " << k << "\telements: " << "\ti: " << i;
//         return pq.top();
//     }
};
