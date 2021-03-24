// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.size();
        if (l == 0 || l == 1)
            return l;
        
        int p=0, q=0, flag, n=0;
        for (int i=1; i<l; i++){
            flag = -1;
            for (int j=p; j<=q; j++){
                if (s[i] == s[j]){
                    flag = j;
                    break;
                }
            }
            // No repeating
            if (flag == -1)
                q ++;
            // Repeating
            else{
                p = flag + 1;
                q = i;
            }
            n = max(q-p+1, n);
        }
        return n;
    }
};
/**
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring Without Repeating Characters.
* Memory Usage: 6.9 MB, less than 95.83% of C++ online submissions for Longest Substring Without Repeating Characters.
*/