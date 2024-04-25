
class Solution:
    def anagram(self, word1, word2):
        return sorted(list(word1)) == sorted(list(word2))
    def removeAnagrams(self, words: List[str]) -> List[str]:
        stack = [words[0]]
        for i in range(1, len(words)):
            if self.anagram(stack[-1], words[i]):
                continue
            stack.append(words[i])

        return stack
        
        