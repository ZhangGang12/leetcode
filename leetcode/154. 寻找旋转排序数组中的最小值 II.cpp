    int minArray(vector<int>& numbers) {
        //如何套公式？
        //由于数组中有重复的元素，为了使得重复旋转后的数组尾部一定小于数组的第一个元素
        //所以需要进行去重
        int l = 0, r = numbers.size() - 1;
        while(l < r && numbers[r] == numbers[l]) r--;
        //对于元素较少的数组，可以直接采用顺序递归
        if(r - l + 1 < 5)
        {
            int res = INT_MAX;
            for(int i = l; i <= r; i++)
            {
                res = min(res, numbers[i]);
            }
            return res;
        }
        //判断尾巴元素是否大于头元素，如果是说明l~r是递增的
        if(numbers[0] < numbers[r]) return numbers[0];
        while(l < r)
        {
            int mid = l + r >> 1;
            if(numbers[0] <= numbers[mid]) l = mid + 1;
            else r = mid;
        }
        return numbers[r];
    }