// https://leetcode.com/problems/01-matrix/
#define MAX 10001

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        // First pass: updating from its top and left cell.
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++){
                if (matrix[i][j]){
                    matrix[i][j] = MAX;   // initialize
                    if (i > 0)
                        matrix[i][j] = min(matrix[i][j], matrix[i-1][j]+1);
                    if (j > 0)
                        matrix[i][j] = min(matrix[i][j], matrix[i][j-1]+1);
                }
            }
        
        // Second pass: updating from its bottom and right cell.
        for (int i=(M-1); i>=0; i--)
            for (int j=(N-1); j>=0; j--){
                if (matrix[i][j]){   
                    if (i < (M-1))
                        matrix[i][j] = min(matrix[i][j], matrix[i+1][j]+1);
                    if (j < (N-1))
                        matrix[i][j] = min(matrix[i][j], matrix[i][j+1]+1);
                }
            }
        
        return matrix;
    }
};
/**
* Runtime: 52 ms, faster than 97.81% of C++ online submissions for 01 Matrix.
* Memory Usage: 26.1 MB, less than 92.57% of C++ online submissions for 01 Matrix.
*/