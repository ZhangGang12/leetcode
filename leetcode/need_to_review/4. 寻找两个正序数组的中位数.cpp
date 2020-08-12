class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size() + nums2.size();
        if(k%2) return find(nums1, 0, nums2, 0, k/2 + 1);
        else {
            int left = find(nums1, 0, nums2, 0, k/2);
            int right = find(nums1, 0, nums2, 0, k/2 + 1);
            return (left + right) / 2.0;
        }
    }

    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
    {
        if(nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);

        if(nums1.size() == i)
        {
            return nums2[j + k - 1];
        }
        if(k == 1)
        {
            return min(nums1[i], nums2[j]);
        }
        int pos1 = min((int)nums1.size(), i + k/2), pos2 = j + k/2;
        if(nums1[pos1 - 1] > nums2[pos2 - 1])
        {
            return find(nums1, i, nums2, pos2, k - (pos2 - j) );
        }else return find(nums1, pos1, nums2, j, k - (pos1 - i));
    }
};