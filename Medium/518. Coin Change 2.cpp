// https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int way[5001] = {0};
        int N = coins.size();
        
        if (amount == 0)
            return 1;
        if (N == 0)
            return 0;
        
        way[0] = 1;
        // Bottom up
        for (int i=0; i<N; i++){
            for (int j=coins[i]; j<= amount; j++)
                way[j] += way[j-coins[i]];
        }
        return way[amount];
    }
};

/**
* Runtime: 4 ms, faster than 99.51% of C++ online submissions for Coin Change 2.
* Memory Usage: 6.7 MB, less than 98.43% of C++ online submissions for Coin Change 2.
*/