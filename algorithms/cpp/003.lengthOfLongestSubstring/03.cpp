class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int a[128]={0};
        for (int i=0,j=0; j<s.length();++j) {
            i=std::max(a[s[j]],i);
            printf("i:%d, j:%d\n", i,j);
            res=std::max(res, j-i+1);
            a[s[j]]=j+1;
        }
        return res;
    }
};