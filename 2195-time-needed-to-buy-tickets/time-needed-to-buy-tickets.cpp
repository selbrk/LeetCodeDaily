class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int val = tickets[k];
        int ans = 0;
        
        for(int i = 0; i<n; i++) {
            if(i <= k)
                ans += min(val, tickets[i]);
            else 
                ans += min(val-1, tickets[i]);
            
        }
        return ans;
    }
};