// https://leetcode.com/problems/3sum-closest/
// 減枝

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int diff = INT_MAX;
        int ans = INT_MAX;
        
        for (int i=0; i<(N-2); i++){
            int j=i+1, k=N-1;
            while (j < k){
                // optimize
                if (nums[i]*3 > target){
                    ans = min((nums[i]+nums[i+1]+nums[i+2]), ans);
                    break;
                }
                //
                int tmpSum = nums[i] + nums[j] + nums[k];
                int tmpdiff = abs(tmpSum - target);
                if (tmpdiff < diff){
                    diff = tmpdiff;
                    ans = tmpSum;
                }
                if (tmpSum < target)
                    j ++;
                else
                    k --;
            }
        }
        return ans;
    }
};

/**
* Runtime: 12 ms, faster than 46.65% of C++ online submissions for 3Sum Closest.
* Memory Usage: 9.9 MB, less than 6.48% of C++ online submissions for 3Sum Closest.
*/