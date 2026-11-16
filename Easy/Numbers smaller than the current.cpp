/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Constraints specify 0 <= nums[i] <= 100
        vector<int> freq(101, 0);
        
        // Step 1: Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Build prefix sum where smaller[v] = count of numbers < v
        vector<int> smaller(101, 0);
        for (int v = 1; v <= 100; ++v) {
            smaller[v] = smaller[v - 1] + freq[v - 1];
        }
        
        // Step 3: Map each element in nums to its precomputed count
        vector<int> ans;
        ans.reserve(nums.size());
        for (int num : nums) {
            ans.push_back(smaller[num]);
        }
        
        return ans;
    }
};
