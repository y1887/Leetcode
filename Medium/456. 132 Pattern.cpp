class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();
        if (N < 3)
            return false;
        
        int medium = INT_MIN;
        int flag = 0;
        // stack: Large element
        stack<int> st;
        // nums[i]: small
        for (int i=(N-1); i>=0; i--){
            if (nums[i] < medium){
                flag = 1;
                break;
            }
            while (!st.empty() && nums[i] > st.top()){
                // make medium as large as it can
                medium = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return flag;
    }
};
// https://www.cnblogs.com/grandyang/p/6081984.html
// O(N**2)
/*
        int mn = 1000000001;
        int flag = 0;
        // nums[i]: max
        // nums[j]: medium
        for (int i=0; i<N; i++){
            mn = min(mn, nums[i]);
            if (mn == nums[i])
                continue;
            for (int j=(N-1); j>i; j--){
                if (nums[j] > mn && nums[j] < nums[i]){
                    cout << mn << "/" << nums[j] << "/" << nums[i];
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        return flag;
*/
/*
        int i=0, j=0, k=0;
        int flag = 0;
        
        while (i < (N-2)){
            while (i < (N-2) && nums[i] >= nums[i+1])
                i ++;
            j = i+1;
            while (j < (N-1) && nums[j] <= nums[j+1])
                j ++;
            k = j+1;
            while (k < N){
                if (nums[k] > nums[i] && nums[k] < nums[j]){
                    flag = 1;
                    break;
                }
                k ++;
            }
            if (flag)   break;
            i = j+1;
        }
        return flag;
*/
// http://www.cs.toronto.edu/~mhsadi/code-repository/12-132Pattern.html