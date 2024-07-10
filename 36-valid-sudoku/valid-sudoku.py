from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Check rows
        for row in board:
            s = set()
            for n in row:
                if n == '.':
                    continue
                if n in s:
                    return False
                s.add(n)
        
        # Check columns
        for i in range(9):
            s = set()
            for j in range(9):
                if board[j][i] == '.':
                    continue
                if board[j][i] in s:
                    return False
                s.add(board[j][i])
        
        # Check 3x3 sub-boxes
        d = [set() for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                r, c = i // 3, j // 3
                box = 3 * r + c
                if board[i][j] in d[box]:
                    return False
                d[box].add(board[i][j])
        
        return True
