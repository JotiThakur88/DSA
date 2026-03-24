class Solution {
public:
    // Check if substring is palindrome
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    void backtrack(int start, string &s, vector<string> &path, 
                   vector<vector<string>> &result) {
        
        // If we reached end → valid partition
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        
        for (int end = start; end < s.size(); end++) {
            
            // Check palindrome
            if (isPalindrome(s, start, end)) {
                
                // Choose
                path.push_back(s.substr(start, end - start + 1));
                
                // Explore
                backtrack(end + 1, s, path, result);
                
                // Backtrack
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        
        backtrack(0, s, path, result);
        return result;
    }
};