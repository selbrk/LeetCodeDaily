class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(a,b):
            if b == 0: return a
            return gcd(b, a % b)

        freq = list(Counter(deck).values())
        return True if reduce(gcd, freq) > 1 else False

        