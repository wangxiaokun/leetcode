class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            for (size_t j = i+1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int> res;
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
    }
};