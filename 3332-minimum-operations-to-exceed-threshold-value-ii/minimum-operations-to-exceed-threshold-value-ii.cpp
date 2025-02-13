class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long> > pq (nums.begin(),nums.end());
        int ans=0;
        long long f,s;
        while(pq.top()<k)  {
            f=pq.top(); pq.pop(); 
            s=pq.top(); pq.pop();
            pq.push(s+2*f);
            ans++;
        }
        return ans;
    }
};