class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        pass
        def is_valid(row, col, board):
            for i in range(row):
                if board[i][col] == 'Q':
                    return False
            
            for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
                if board[i][j] == 'Q':
                    return False
            
            for i, j in zip(range(row, -1, -1), range(col, n)):
                if board[i][j] == 'Q':
                    return False
            
            return True
        
        def backtrack(row):
            if row == n:
                result.append([''.join(row) for row in board])
                return
            
            for col in range(n):
                if is_valid(row, col, board):
                    board[row][col] = 'Q'  
                    backtrack(row + 1)    
                    board[row][col] = '.'

        result = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        backtrack(0)
        return result
