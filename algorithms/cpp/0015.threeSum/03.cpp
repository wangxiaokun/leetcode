vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> vecRes;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        map<int, int> mymap;

        for (size_t j = i+1; j < nums.size(); ++j)
        {
            if (mymap.end() == mymap.find(nums[j]))
            {
                mymap[nums[j]] = j;
            }

            int tmp = 0 - nums[i] - nums[j];

            if ((mymap.end() != mymap.find(tmp)) && (mymap[tmp] != j))
            {
                vector<int> vecTmp;
                vecTmp.push_back(nums[i]);
                vecTmp.push_back(nums[j]);
                vecTmp.push_back(tmp);
                sort(vecTmp.begin(), vecTmp.end());
                vecRes.push_back(vecTmp);
            }
        }
    }

    sort(vecRes.begin(), vecRes.end());
    vecRes.erase(unique(vecRes.begin(), vecRes.end()), vecRes.end());

    return vecRes;
}
