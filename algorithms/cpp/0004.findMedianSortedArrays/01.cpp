#include <iterator>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dst;
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(dst));
        int size = dst.size();
        return (size%2==0)?((double)(dst[size/2]+dst[size/2-1])/2):(dst[size/2]);
    }
};
