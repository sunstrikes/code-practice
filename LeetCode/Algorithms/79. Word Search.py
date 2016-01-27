class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m = len(board)
        if m == 0 or len(board[0])==0:
            return True
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                if self.check(board,word,i,j):
                    return True
        return False
    def check(self,board,word,i,j):
        if len(word) == 0:
            return True
        if i<0 or j<0 or i>=len(board) or j >= len(board[0]):
            return False
        if word[0] == board[i][j]:
            c = word[0]
            board[i][j] = 0
            if self.check(board,word[1:],i+1,j) or self.check(board,word[1:],i-1,j)\
                 or self.check(board,word[1:],i,j+1) or self.check(board,word[1:],i,j-1):
                return True
            board[i][j] = c
        return False
