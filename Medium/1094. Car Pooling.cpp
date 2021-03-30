// https://leetcode.com/problems/car-pooling/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if (trips.size() == 0)
            return true;
        if (trips[0][0] > capacity)
            return false;
        
        int arr[1001] = {0};
        int count = 0, flag = 1;
        int start = trips[0][1], end = 0;
        
        for (int i=0; i<trips.size(); i++){
            arr[trips[i][1]] += trips[i][0];
            arr[trips[i][2]] -= trips[i][0];
            start = min(start, trips[i][1]);
            end = max(end, trips[i][2]);
        }
        for (int i=start; i<=end; i++){
            count += arr[i];
            if (count > capacity){
                flag = 0;
                break;
            }
        }
        return flag;
    }
};
/**
* Runtime: 8 ms, faster than 98.12% of C++ online submissions for Car Pooling.
* Memory Usage: 9.4 MB, less than 63.41% of C++ online submissions for Car Pooling.
*/