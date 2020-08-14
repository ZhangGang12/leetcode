class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        for(int i = 0; i < nums.size(); ++i)
        {
            //去重
            if(i && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size(); ++j)
            {
                //去重
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                for(int k = j + 1, m = nums.size() - 1; k < m; ++k)
                {
                    if(k > j + 1 && nums[k] == nums[k-1]) continue;
                    while(k < m - 1 && nums[i] + nums[j] + nums[k] + nums[m-1] >= target) --m;
                    int sum = nums[i] + nums[j] +nums[k] + nums[m];
                    if(sum == target) res.push_back({nums[i], nums[j], nums[k], nums[m]});
                }
            }
        }
        return res;
    }
};