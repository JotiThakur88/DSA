class Solution {
public:
    // Check if we can ship within 'days' using 'capacity'
    bool canShip(vector<int>& weights, int days, int capacity) {
        int currentLoad = 0;
        int requiredDays = 1;
        
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                requiredDays++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        
        return requiredDays <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canShip(weights, days, mid)) {
                right = mid; // try smaller
            } else {
                left = mid + 1; // increase capacity
            }
        }
        
        return left;
    }
};