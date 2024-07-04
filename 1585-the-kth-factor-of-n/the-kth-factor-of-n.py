class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        small, big = [], []
        i = 1
        while i * i < n:
            if n % i == 0:
                small.append(i)
                big.append(n // i)
            i+=1
        if i * i == n:
            small.append(i)
        a, b = len(small), len(big)
        print(f"{a=}\n {b=}\n {small=}\n {big=}")
        if a + b < k:
            return -1
        if k <= a:
            return small[k-1]
        k -= a
    
        return big[b - k]
        