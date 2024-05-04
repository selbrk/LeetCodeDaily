class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        // 1, 1, 2 ,3
        vector<bool> vis(people.size(), false);
        int ans = 0;
        for (int i = 0; i < people.size(); i++) {
            if (vis[i])
                continue;
            ans++;
            vis[i] = true;
            int left = limit - people[i];
            // find the greatest element less than or equal to left
            int l = i + 1, r = people.size() - 1;
            while (l <= r) {
                if (r - l <= 1) {
                    if (people[r] <= left && !vis[r]) {
                        vis[r] = true;
                        break;
                    }
                    if (people[l] <= left && !vis[l]) {
                        vis[l] = true;
                        break;
                    }
                    break;
                }
                int mid = (l + r) / 2;
                if (people[mid] <= left && !vis[mid])
                    l = mid;
                else
                    r = mid - 1;
            }
        }

        return ans;
    }
};