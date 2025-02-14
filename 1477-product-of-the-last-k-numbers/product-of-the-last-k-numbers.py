class ProductOfNumbers:

    def __init__(self):
        self.pref_mult = [1]
        self.pref_zero = [0]


    def add(self, num: int) -> None:
        self.pref_mult.append((num or 1) * self.pref_mult[-1])
        self.pref_zero.append(self.pref_zero[-1] + (num==0))


    def getProduct(self, k: int) -> int:
        zero_count = self.pref_zero[-1] - self.pref_zero[-1-k]
        if zero_count: return 0
        return self.pref_mult[-1] // self.pref_mult[-1-k]
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)