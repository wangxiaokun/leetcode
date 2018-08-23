class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        map<int, int> mymap;
        
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (mymap.end() == mymap.find(nums[i]))
            {
                mymap[nums[i]] = i;
            }
            
            int tmp = target - nums[i];
            
            if ((mymap.end() != mymap.find(tmp)) && (mymap[tmp] != i))
            {
                res.push_back(mymap[tmp]);
                res.push_back(i);
                break;
            }
        }

        return res;
    }
};