/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
//s = "3[a]2[bc]", 返回 "aaabcbc".
//s = "3[a2[c]]", 返回 "accaccacc".
//s = "2[abc]3[cd]ef", 返回 
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
       //辅助栈解法
       stack<int> numStack;
       stack<string> resStack;
       int num = 0;
       string res;
       for(int i = 0; i < s.size(); i++){
           if(isalpha(s[i])){
               res.push_back(s[i]);
           }else if(isdigit(s[i])){
               num = num*10 + s[i] - '0';
           }else if(s[i] == '['){
               resStack.push(res);
               res = "";
               numStack.push(num);
               num = 0;
           }else {
               for (int j = 0; j < numStack.top(); j++){
                   resStack.top() += res;
               }
               numStack.pop();
               res = resStack.top();
               resStack.pop();
           }
       }
       return res;
    }
};
// @lc code=end
//递归解法
/*
int num = 0;
       string res;
       for (int i = 0; i < s.size(); i++){
           if(isalpha(s[i])){
               res.push_back(s[i]);
           }else if(isdigit(s[i])){
               num = num * 10 + s[i] - '0';
           }else if('[' == s[i]){ //进入递归
                int cnt = 0;
                string inner;
                i++;
                while(s[i] != ']' || cnt != 0){
                    if('[' == s[i]) cnt++;
                    if(']' == s[i]) cnt--;
                   inner.push_back(s[i]); 
                   ++i;
                }
                string innerRes = decodeString(inner);
                while(num > 0){
                    res += innerRes;
                    --num;
                }
           }
       }
       return res;
*/
