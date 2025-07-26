/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m-1;
        int row = 0;
        int col = m-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(matrix[row][mid]==target) return true;
            if(left==right&&row<n)
            {
                left = 0;
                right = m-1;
                row++;     
                       }
            else if (matrix[row][mid]<target) 
            {
                left= mid+1;
            }
            else if (matrix[row][mid]>target) 
            {
                right = mid-1;
            }
        }
        return false;
    }
};*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();       // Number of rows
        int n = matrix[0].size();    // Number of columns
        int row = 0;

        while (row < m) {
            int left = 0;
            int right = n - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (matrix[row][mid] == target) return true;
                else if (matrix[row][mid] < target) left = mid + 1;
                else right = mid - 1;
            }

            row++;  // Move to next row only after binary search is done
        }

        return false;
    }
};
