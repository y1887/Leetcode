class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (N < 3 || nums.back() < 0 || nums.front() > 0)
            return ans;
        
        for (int i=0; i<(N-2); i++){
            if (nums[i] > 0)   break;
            if (i > 0 && nums[i] == nums[i-1])   continue;
            int target = 0 - nums[i];
            int ptr1 = i+1;
            int ptr2 = N-1;
            
            while (ptr1 < ptr2){
                int summ = nums[ptr1] + nums[ptr2];
                if (summ == target){
                    ans.push_back({nums[i], nums[ptr1], nums[ptr2]});
                    while (ptr1 < ptr2 && nums[ptr1] == nums[ptr1+1])
                        ptr1 ++;
                    while (ptr1 < ptr2 && nums[ptr2] == nums[ptr2-1])
                        ptr2 --;
                    ptr1 ++;
                    ptr2 --;
                }
                else if (summ < target)
                    ptr1 ++;
                else
                    ptr2 --;
            }
        }
        return ans;
    }
};

// https://www.cnblogs.com/grandyang/p/4481576.html