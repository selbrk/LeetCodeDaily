class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        words = sentence.split()
        for i in range(len(words)):
            if words[i][0] == '$':
                if words[i][1:].isdigit():
                    value = float(words[i][1:])
                    withDiscount = value * (1 - discount / 100)
                    words[i] = f'${withDiscount:.2f}'
        return " ".join(words)

        