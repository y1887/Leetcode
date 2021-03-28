// https://leetcode.com/problems/2-keys-keyboard/
// Prime factorization

class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        else if (n <= 5)
            return n;
        
        int A[1002] = {0};
        for (int i=2; i<=5; i++)
            A[i] = i;
        
        // Find largest factor
        // Top-Down Approach
        if (n%2 == 0)
            return minSteps(n/2) + 2;
        else
        {
            int id = 0;
            for (int i=3; i<=sqrt(n); i+=2){
                if (n%i == 0){
                    id = i;
                    break;
                }
            }
            if (!id)
                return n;
            else
                return minSteps(n/id) + id;
        }
    }
};

/**
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for 2 Keys Keyboard.
* Memory Usage: 6 MB, less than 58.55% of C++ online submissions for 2 Keys Keyboard.
*/