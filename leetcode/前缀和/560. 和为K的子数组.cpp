/**暴力思路，计算出前缀和，然后枚举每一个可能的值
 * 优化：利用hashmap记录前缀和，然后查找当前和与k的差值是否在集合中
 * 下面注释部分为暴力做法TLE， 上面为优化做法。
*/
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            pre += nums[i];
            if(mp.count(pre-k)) count += mp[pre-k];
            mp[pre]++;
        }
        return count;
        /*
        int n = nums.size();
        vector<int> f(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            f[i] = f[i-1] + nums[i-1];
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(f[j+1] - f[i] == k ) res ++;
            }
        }
        return res;*/
    }