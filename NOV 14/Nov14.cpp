class Solution {
public:
    bool canDistribute(int maxVal, int n, vector<int>& q) {
        int count = 0;
        for (int quantity : q) {
            count += (quantity + maxVal - 1) / maxVal; 
            if (count > n) return false; 
        }
        return count <= n;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int left = 1; 
        int right = *max_element(q.begin(), q.end()); 

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(mid, n, q)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
