// Q no 55 (Leetcode)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = 0;   // creating to make count for maximum reach
        for(int i = 0; i < nums.size(); i++){            // iterating through all the elements
            if(maxreach < i) return false;              // if max reach is less than curr element we cant reach last element
            maxreach = max(maxreach, nums[i] + i);
        }
        return true;
    }
};
