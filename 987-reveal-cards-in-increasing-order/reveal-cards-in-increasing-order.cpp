/*
1,2,3,4,5

*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n, -1);

        sort(deck.begin(), deck.end());

        int empty = 0, counter = 0, ix = 0;
        while(counter != n) {
            if(ans[ix] == -1) {
                if(empty % 2 == 0) {
                    ans[ix] = deck[counter];
                    counter++;
                }
                empty++;
            }
            ix++;
            ix %= n;
        }



        return ans;

    }
};