class Solution:
    def beautifulSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        vowels = ["a", "e", "i", "o", "u"]
        pre_vowels = [0] * (n + 1)
        pre_consonants = [0] * (n + 1)

        for i in range(n):
            if s[i] in vowels:
                pre_vowels[i + 1] = pre_vowels[i] + 1
                pre_consonants[i + 1] = pre_consonants[i]
            else:
                pre_vowels[i + 1] = pre_vowels[i]
                pre_consonants[i + 1] = pre_consonants[i] + 1

        ans = 0
        for i in range(n):
            for j in range(i, n):
                vowel_count = pre_vowels[j + 1] - pre_vowels[i]
                consonant_count = pre_consonants[j + 1] - pre_consonants[i]
                if vowel_count == consonant_count and (consonant_count**2 % k == 0):
                    ans += 1

        return ans
