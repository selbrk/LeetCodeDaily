class Solution {
public:
    int toInt(array<int,4>& curr) {
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            ans *= 10;
            ans += curr[i];
        }
        return ans;
    }

    int openLock(vector<string>& deadends, string target) {
        int to_change[4] = {0,1,2,3}, amount[2] = {1,9};
        int n = deadends.size();

        
        unordered_set<int> vis, forbidden;
        array<int,4> temp;

        for(auto& s : deadends){
            temp = {s[0] -'0', s[1] -'0', s[2] -'0', s[3] -'0'};
            forbidden.insert(toInt(temp));
        }
        
        queue<pair<int,array<int,4>>> q;
        q.push({0, {0,0,0,0}});
        array<int,4> targetArray = {target[0] - '0', target[1] - '0', target[2] -'0', target[3] - '0'};        

        int current_level;
        array<int, 4> current_state, next_state;
        while(!q.empty()) {
            current_level = q.front().first;
            current_state = q.front().second;
            vis.insert(toInt(current_state));

            q.pop();

            if(toInt(current_state) == toInt(targetArray))
                return current_level;
            
            if(forbidden.count(toInt(current_state)))
                continue;
            
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 2; j++) {
                    next_state = current_state;
                    (next_state[to_change[i]] += amount[j]) %= 10;
                    if(!vis.count(toInt(next_state))){
                        vis.insert(toInt(next_state));
                        q.push({current_level+1, next_state});
                    }

                }
            }
        }
        return -1;
    }
};