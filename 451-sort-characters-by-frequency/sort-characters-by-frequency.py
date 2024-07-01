class Solution:
    def frequencySort(self, s: str) -> str:
        counter = Counter(s)

        v = sorted(counter.items(), key = lambda x: -x[1])
        ans = ""
        for letter, freq in v:
            ans += letter * freq
        
        return ans

        