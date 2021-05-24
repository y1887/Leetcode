// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1)
            return 1;
        
        // Catalan number : (2n, n)/(n+1)
        unsigned long long int up = 1;
        unsigned long long int down = 1;
        for (int i=2; i<=n; i++){
            up *= (i+n);
            down *= i;
            if (up % down == 0){
                up = up/down;
                down = 1;
            }
        }
        return up/down;
        
//         int arr[20] = {0};
//         arr[0] = 1;
//         arr[1] = 1;
        
//         for (int i=2; i<=n; i++){
//             for (int j=0; j<i; j++){
//                 arr[i] += arr[j] * arr[i-j-1];
//             }
//         }
//         return arr[n];
    }
};

// Recursion
/*
        if (n == 0 || n == 1)
            return 1;
        
        int S = 0;
        for (int i=0; i<n; i++){
            S += numTrees(i) * numTrees(n-1-i);
        }
        return S;
*/