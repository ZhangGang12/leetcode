#include <iostream>
#include <vector>

int maxProfit(vector<int>& prices) {
        //思路：将数组分割成两部分，以i为分割点，第一部分为i前面，第二部分为i后面
        //两部分分别按照上一题的思路进行求解，然后i依次从0开始枚举，所有情况都能考虑到
        int n = prices.size();
        if(n < 2) return 0;
        vector<int> f(n);
        for(int i = 1, minp = prices[0]; i < n; i++)
        {
            //在i天之间卖出, f[0] = 0所以从1开始
            f[i] = max(f[i-1], prices[i] -  minp);
            minp = min(minp, prices[i]);            
        }

        int res = f[n-1];
        //在i天的时候买入但是最后一天卖入无效所以从n-2开始
        for(int i = n - 2, maxp =prices[n-1]; i >= 0; i--)
        {
            res = max(f[i] + maxp - prices[i], res);
            maxp = max(prices[i],maxp);
        }
        return res;
}

int main()
{
    //此处为测试点，请自行测试
    return 0;
}