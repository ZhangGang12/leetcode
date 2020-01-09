/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            N *= -1;
            x = 1/x;
        }
        return fast(x,N);
    }
    double fast(double x, long long n){
        if(0 == n) return 1;
        double half = myPow(x, n/2);
        if(n%2){
            return half*half*x;
        }else{
            return half*half;
        }
    }
};
// @lc code=end
//暴力法
/* 
       if(n == 0) return 1;
        double res = x;
        bool neg = false;
        if(n < 0) {
            neg = true;
            n *= -1;
            }
        while(n > 1){
            res *= x;
            --n;
        }
        if(neg) res = 1/res;
        return res;
    */
