// https://leetcode.com/problems/subarray-sum-equals-k/
// Bottom-up. using map.
// record sum of all of previous element.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        int ans = 0, mysum = 0;
        map<int, int> mymap;
        
        for (int i=0; i<N; i++){
            mysum += nums[i];
            if (mysum == k)
                ans ++;
            
            if (mymap.count(mysum-k))
                ans += mymap[mysum-k];
            
            mymap[mysum] ++;
        }
        return ans;
    }
};

/**
* Runtime: 92 ms, faster than 30.85% of C++ online submissions for Subarray Sum Equals K.
* Memory Usage: 38.1 MB, less than 46.05% of C++ online submissions for Subarray Sum Equals K.
*/