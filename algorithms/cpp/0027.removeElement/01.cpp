class Solution {
public:
    /*int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove_if(nums.begin(),
                                  nums.end(),
                                  [=](int v){return v==val;}),
                    nums.end());
        return nums.size();
    }*/
    
    int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
