class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        mod = 10**9 + 7
        flag = True
        no1, no2 = 0, 0  # no2 >= no1
        for i in range(49, n - 1, -1):
            if i >= n:
                if (1 << i) & a:
                    no1 |= 1 << i
                if (1 << i) & b:
                    no2 |= 1 << i
                
        if no1 == no2:
            flag = False
        if no1 > no2:
            no1, no2 = no2, no1

        for i in range(n - 1, -1, -1):
            if (1 << i) & a == (1 << i) & b:
                no1 |= 1 << i
                no2 |= 1 << i
            elif flag:
                no1 |= 1 << i
            else:
                no2 |= 1 << i
                flag = True
        no1 %= mod
        no2 %= mod

        return no1 * no2 % mod
