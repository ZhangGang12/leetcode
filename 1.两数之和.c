/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 输入数组， 输入数组大小，输入target，输出数组大小*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //哈希表
    
}


// @lc code=end

/*暴力法
    int i = 0, j = 0;
    int *result = NULL;
    for(i = 0; i < numsSize - 1; i++){
        for( j = i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                result = (int*)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                returnSize[0] = 2;
                return result;
            }
        }
    }
    returnSize[0] = 0;
    return result;
    */

