class Solution {
public:
    void res(vector<int>& nums, vector<int>& current, vector<bool>& visited, vector<vector<int>>& result){
         if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                current.push_back(nums[i]);

                res(nums, current, visited, result);

                current.pop_back();
                visited[i] = false;
            }
        
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;      
        vector<bool> visited(nums.size(), false); 
        res(nums, current, visited, result);
        return result;
    }
};
