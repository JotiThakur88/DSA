class Solution {
public:
    // Check if we can place m balls with at least 'dist' gap
    bool canPlace(vector<int>& position, int m, int dist) {
        int count = 1; // first ball placed
        int lastPos = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= dist) {
                count++;
                lastPos = position[i];
            }
            
            if (count >= m) return true;
        }
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int left = 1;
        int right = position.back() - position[0];
        
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canPlace(position, m, mid)) {
                ans = mid;        // possible → try bigger
                left = mid + 1;
            } else {
                right = mid - 1; // not possible → reduce
            }
        }
        
        return ans;
    }
};