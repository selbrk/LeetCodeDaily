class Solution {
public:
    int nthUglyNumber(int n) {
        int primes[] = {2,3,5};
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> used;
        pq.push(1ll);
        long long fst, tmp;
        while(n--) {
            fst = pq.top(); pq.pop();
            for(int &prime : primes) {
                tmp = fst * prime;
                if(used.count(tmp)) continue;
                pq.push(tmp);
                used.insert(tmp);
            }
        }
        return fst;

    }
};