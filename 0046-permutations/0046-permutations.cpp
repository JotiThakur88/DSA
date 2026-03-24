class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& result) {
        
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);   // Choose
            
            backtrack(start + 1, nums, result); // Explore
            
            swap(nums[start], nums[i]);   // Backtrack
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};