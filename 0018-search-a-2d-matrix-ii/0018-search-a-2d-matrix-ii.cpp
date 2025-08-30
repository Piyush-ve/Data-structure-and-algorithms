class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        
        int cols = matrix[0].size();
        int low = 0, high = rows * cols - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midVal = matrix[mid / cols][mid % cols]; // map 1D index to 2D
            
            if (midVal == target) return true;
            else if (midVal < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
