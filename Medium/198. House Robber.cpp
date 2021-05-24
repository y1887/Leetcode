// DP: 取或不取
class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        int arr[101];
        arr[0] = 0;
        arr[1] = nums[0];
        
        for (int i=1; i<N; i++){
            arr[i+1] = max(arr[i], (nums[i]+arr[i-1]));
            cout << arr[i+1] << " ";
        }
        return arr[N];
    }
};