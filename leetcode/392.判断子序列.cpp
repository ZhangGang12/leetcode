

bool isSubsequence(string s, string t) {
        //简单做法dp
        int m = s.size(), n = t.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m+1));
        dp[0][0] = true;
        s = ' ' + s, t = ' ' + t;
        for(int  i = 1; i <= n; i++)
            for(int j = 0; j <= m; j++)
            {
                if(!j) dp[i][j] = true;
                else{
                    if(t[i] == s[j])     // aab   aabb
                    {                    // aab   aab
                        dp[i][j] = dp[i-1][j-1] || dp[i-1][j];  
                    }else {                     // aab
                        dp[i][j] = dp[i-1][j];  // aa
                    }
                    /* 这里是上面代码的简化
                        dp[i][j] = dp[i-1][j];
                        dp[i][j] = dp[i][j] || t[i] == s[j] ? dp[i-1][j-1] : false;
                        */ 
                }
            }
            return dp[n][m];
    }
    //双指针贪心做法  因为只匹配一个字符所以从前往后遍历，绝对可以遍历完
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }