/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare);
    int* dp = (int*) malloc (numsSize * sizeof(int));
    int* prev = (int*) malloc (numsSize * sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        prev[i] = -1;
        for(int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                dp[i] = 1 + dp[j];
                prev[i] = j;
            }
        }
    }
    int last_index = -1, size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (dp[i] > size) {
            size = dp[i];
            last_index = i;
        }
    }
    *returnSize = size;
    int* ans = (int*) malloc(size * sizeof(int));
    for(int i = size - 1; i >= 0; i--) {
        ans[i] = nums[last_index];
        last_index = prev[last_index];
    }
    return ans;
}