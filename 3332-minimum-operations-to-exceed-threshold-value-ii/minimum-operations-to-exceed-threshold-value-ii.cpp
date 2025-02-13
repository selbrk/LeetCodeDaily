class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(int &x:nums) pq.push((long long)x);
        int ans=0;
        while(pq.top()<k)  {
            long long f=pq.top(); pq.pop(); 
            long long s=pq.top(); pq.pop();
            pq.push(s+2*f);
            ans++;
        }
        return ans;
        return 0;

    }
};