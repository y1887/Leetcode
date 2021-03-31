// https://leetcode.com/problems/maximal-square/
// ref: https://leetcode.com/problems/maximal-square/discuss/1102375/Easy-tabulation-method-in-C%2B%2B

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        if (N==1 && M==1)
            return matrix[0][0] - '0';
        
        int dp[301][301] = {{0}}, ans = 0;
        
        // Dealing with the border first.
        for (int i=0; i<N; i++){
            dp[M-1][i] = matrix[M-1][i] - '0';
            ans = max(ans, dp[M-1][i]);
        }
        for (int i=0; i<M; i++){
            dp[i][N-1] = matrix[i][N-1] - '0';
            ans = max(ans, dp[i][N-1]);
        }
        // Scan the matrix from right-bottom to left-top
        for (int i=(M-2); i>=0; i--){
            for (int j=(N-2); j>=0; j--){
                if (matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]));
                    ans = max(ans, dp[i][j]);
                }else
                    dp[i][j] = 0;
            }
        }
        return ans*ans;
    }
};
/**
* Runtime: 20 ms, faster than 91.12% of C++ online submissions for Maximal Square.
* Memory Usage: 11.4 MB, less than 64.35% of C++ online submissions for Maximal Square.
*/


// Another Solution: Use matrix directly.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        if (N==1 && M==1)
            return matrix[0][0] - '0';
        
        int ans = 0;
        // Border condition
        for (int i=0; i<M; i++)
                ans = max(ans, matrix[i][N-1]-'0');
        for (int i=0; i<N; i++)
            ans = max(ans, matrix[M-1][i]-'0');
        
        // Calculate on the matrix directly.
        for (int i=(M-2); i>=0; i--){
            for (int j=(N-2); j>=0; j--)
            {   
                if (matrix[i][j] == '1'){
                    int diagonal = matrix[i+1][j+1] - '0';
                    int right = matrix[i][j+1] - '0';
                    int down = matrix[i+1][j] - '0';
                    int update = 1 + min(diagonal, min(right, down));
                    matrix[i][j] = update + '0';
                    ans = max(ans, update);
                }
            }
        }
        return ans*ans;
    }
};
/**
* Runtime: 20 ms, faster than 91.12% of C++ online submissions for Maximal Square.
* Memory Usage: 11.1 MB, less than 77.25% of C++ online submissions for Maximal Square.
*/
