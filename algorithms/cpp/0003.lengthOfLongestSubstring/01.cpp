class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        for (int i=0; i<s.length(); ++i) {
            int _res=0;
            int a[128]={0};
            for (int j=i; j<s.length(); ++j) {
                if (0==a[s[j]]) {
                    a[s[j]]=1;
                    _res++;
                    if (j == s.length()) break;
                }
                else break;
                res=std::max(res, _res);
            }
        }
        return res;
    }
};