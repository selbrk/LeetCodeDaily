class Solution {
public:
    int ceil3(int k) {
        if(k % 3 == 0) return k / 3;
        return k / 3 + 1;
    }


    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int&x: nums) pq.push(x);

        long long ans = 0;
        int tp;
        while(k--) {
            tp = pq.top();
            pq.pop();
            ans+=tp;
            pq.push(ceil3(tp));
        }

        return ans;
    }
};