/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        for(int i = 0; i < len/2; i++){
            int temp = nums[i];
            nums[i] = nums[len-i-1];
            nums[len-i-1] = temp;
        }
        for(int i = 0; i < k/2; i++){
            int temp = nums[i];
            nums[i] = nums[k-i-1];
            nums[k-i-1] = temp;
        }
        for(int i = 0; i < (len-k)/2; i++){
            int temp = nums[k+i];
            nums[i+k] = nums[len-i-1];
            nums[len-i-1] = temp;
        }
    }
};
// @lc code=end
/*
 *1、暴力法：最简单的方法是旋转 k 次，每次将数组旋转 1 个元素。
 *2、使用额外的数组
 *3、使用环替换
 *4、反转
 *1、2的方法比较简单无脑，就不写代码，3、4代码如下：
 */
/*3、环替换
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        int count = 0;
        for(int start = 0; count < len; ++start){
            int cur = start;
            int prev = nums[start];
            do{
                int next = (cur + k)%len;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                cur = next;
                count++;
            }while(start != cur);
        }
    }
*/
/*   4、反转
 *  例子  n= 7 k = 3
 *  原始数组                  : 1 2 3 4 5 6 7
 *  反转所有数字后             : 7 6 5 4 3 2 1
 *  反转前 k 个数字后          : 5 6 7 4 3 2 1
 *  反转后 n-k 个数字后        : 5 6 7 1 2 3 4
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        for(int i = 0; i < len/2; i++){
            int temp = nums[i];
            nums[i] = nums[len-i-1];
            nums[len-i-1] = temp;
        }
        for(int i = 0; i < k/2; i++){
            int temp = nums[i];
            nums[i] = nums[k-i-1];
            nums[k-i-1] = temp;
        }
        for(int i = 0; i < (len-k)/2; i++){
            int temp = nums[k+i];
            nums[i+k] = nums[len-i-1];
            nums[len-i-1] = temp;
        }
    }
 */

