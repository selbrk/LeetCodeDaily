class Solution:
    def __init__(self):
        self.d = {
                "2": "abc",
                "3": "def",
                "4": "ghi",
                "5": "jkl",
                "6": "mno",
                "7": "pqrs",
                "8": "tuv",
                "9": "wxyz"
            }
        self.ans = []
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        self.helper(digits, 0)
        return self.ans
    def helper(self, digits, index, current = ""):
        if index == len(digits):
            self.ans.append(current)
            return
        for letter in self.d[digits[index]]:
            self.helper(digits, index + 1, current + letter)
        
    

        