#include "util.h"

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        for (size_t j = i+1; j < nums.size(); ++j)
        {
            for (size_t k = j+1; k < nums.size(); ++k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    sort(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                    break;
                }
            }
        }
    }

    sort(res.begin(), res.end());
    vector<vector<int>>::iterator iter = unique(res.begin(), res.end());
    res.erase(iter, res.end());

    return res;
}

int main()
{
     vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Duration duration;
    duration.click();

    vector<vector<int>> res = threeSum(nums);

    duration.print();

    printVec(res);
}

