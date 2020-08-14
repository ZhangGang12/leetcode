class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //思路和上一题类似也是用双指针，不过不需去重，但是也可以去重
        int res = INT_MAX;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i && nums[i] == nums[i-1] )continue;
            for(int j = i+1, k = nums.size() - 1; j < k; j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                while(j < k - 1 && nums[i] + nums[j] + nums[k-1] >= target) k--;
                int t1 = nums[i] +nums[j] + nums[k];
                if(j < k - 1) {
                    int t2 = nums[i] + nums[j] + nums[k-1] ;
                    if(res > abs(t2 - target)) res = abs(t2-target), ans = t2;
                    }
                if(res > abs(t1-target) ) res = abs(t1-target) , ans = t1;
            }
        }
        return ans;
    }
};