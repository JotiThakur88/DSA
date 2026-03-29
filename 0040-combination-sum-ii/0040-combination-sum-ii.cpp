class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& path) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Stop if number exceeds target
            if (candidates[i] > target) break;

            // Choose
            path.push_back(candidates[i]);

            // Recurse (i+1 because each element used once)
            backtrack(candidates, target - candidates[i], i + 1, path);

            // Backtrack
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrack(candidates, target, 0, path);
        return result;
    }
};