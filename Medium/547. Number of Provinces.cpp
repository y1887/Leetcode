// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 1)
            return 1;
        
        set<int> s;
        // Record each node's parent (0==itself).
        int arr[202] = {0};  
        
        for (int i=1; i<=n; i++){
            for (int j=i; j<=n; j++){
                if ((i==j) && arr[i]==0){
                    arr[i] = i;
                    s.insert(i);
                }
                if (i!=j && isConnected[i-1][j-1]){
                    if (arr[j] == 0)
                        arr[j] = arr[i];
                    else if (arr[j] < arr[i]){
                        s.erase(arr[i]);
                        for (int p=1; p<j; p++)
                            if (isConnected[i-1][p-1])
                                arr[p] = arr[j];
                    }
                    else if (arr[i] < arr[j]){
                        s.erase(arr[j]);
                        for (int p=1; p<i; p++)
                            if (isConnected[p-1][j-1])
                                arr[p] = arr[i];
                    }
                }
            }
        }
        return s.size();
    }
};

/**
* Runtime: 16 ms, faster than 99.10% of C++ online submissions for Number of Provinces.
* Memory Usage: 13.7 MB, less than 77.03% of C++ online submissions for Number of Provinces.
*/