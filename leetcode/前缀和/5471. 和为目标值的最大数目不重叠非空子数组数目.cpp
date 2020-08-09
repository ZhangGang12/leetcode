    /**第201场周赛题目
     * 利用优化的前缀和方法。
     * 采用贪心的思想，用hashmap记录前n项和的下标
     * 
    */
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0, end = -1;
        int ret = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(mp.count(sum - target))
            {
                if(mp[sum - target] + 1 > end)
                {
                    ret ++;
                    end = i;
                }
            }
            mp[sum] = i;
        }
        return ret;