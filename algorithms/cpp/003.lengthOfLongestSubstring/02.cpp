class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        for (int i=0; i<s.length(); ++i) {
            int a[128]={0};
            for (int j=i; j<s.length(); ++j) {
                if (0==a[s[j]]) {
                    a[s[j]]=1;
                    if (j == s.length()) break;
                }
                else break;
                res=std::max(res, j-i+1);
            }
        }
        return res;
    }
};