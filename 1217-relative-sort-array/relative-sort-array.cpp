class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }

        priority_queue<pair<int,int>> pq;
        for(int& x : arr1)
            if(mp.count(x))
                pq.push({-mp[x], x});
            else
                pq.push({-1001 - x, x});
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        

    }
};