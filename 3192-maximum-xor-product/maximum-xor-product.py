class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        mod = 10**9 + 7
        flag = True
        no1, no2 = 0, 0  # no2 >= no1
        for i in range(50, n - 1, -1):
            if i >= n:
                # xor with 0
                if (1 << i) & a:
                    no1 += 1 << i
                if (1 << i) & b:
                    no2 += 1 << i
                
        if no1 == no2:
            flag = False
        if no1 > no2:
            no1, no2 = no2, no1

        for i in range(n - 1, -1, -1):
            if (1 << i) & a == (1 << i) & b:
                no1 += pow(2, i, mod)
                no2 += pow(2, i, mod)
                no1 %= mod
                no2 %= mod
            elif flag:
                no1 += pow(2, i, mod)
                no1 %= mod
            else:
                no2 += pow(2, i, mod)
                no2 %= mod
                flag = True
        no1 %= mod
        no2 %= mod

        return no1 * no2 % mod
