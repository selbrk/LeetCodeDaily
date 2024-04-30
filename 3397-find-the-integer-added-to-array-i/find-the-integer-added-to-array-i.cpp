class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int min1 = 2000, min2 = 2000, n = nums1.size();
        for(int i = 0; i < n; i++) {
            min1 = min(nums1[i], min1);
            min2 = min(nums2[i], min2);
        }
        return min2 - min1;
    }
};