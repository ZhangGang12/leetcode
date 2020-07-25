#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    //本题本质上是一个数学题目（找规律）
    //分析过程：设置f[i] 为i个节点组成的二叉搜索树的个数
    // 显然 f[1] = 1;
    // 对于新的一行，我们从第一个开始枚举，然后左右两边可以被分为已经计算的结果，累加起来就可以得到新的结果
    // f[2] = f[0] * f[1] + f[1] * f[0] = 2
    // f[3] = f[0] * f[2] + f[1] * f[1] + f[2] * f[0] = 5;
    //f[n] = f[0] * f[n-1] + f[1] * f[n - 2] + .. + f[n-1]*f[0] = 
    vector<int> f(n+1);
    f[0] = 1; //方便计算
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            f[i] += f[j]*f[i-1-j];
        }
        }
    return f[n];
}