vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> vecRes;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0) break;
        if ((i > 0) && (nums[i] == nums[i-1])) continue;

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int target = nums[i] + nums[j] + nums[k];

            if (0 == target)
            {
                vecRes.push_back({nums[i], nums[j], nums[k]});
                //cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                while ((j < k) && (nums[j] == nums[j+1])) ++j;
                while ((j < k) && (nums[k] == nums[k-1])) --k;
                ++j; --k;
            }
            else if (target < 0) ++j;
            else --k;
        }
    }

    return vecRes;
}
