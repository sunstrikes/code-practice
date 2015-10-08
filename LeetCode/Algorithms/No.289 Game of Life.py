class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        tmp =[]
        for i in range(m):
            tmp.append([0]*n)
        for i in range(m):
            for j in range(n):
                num = self.judge(board,i,j)
                if num < 2:
                    tmp[i][j] = 0
                elif (num == 2 or num == 3) and board[i][j] ==1:
                    tmp[i][j] = 1
                elif num>3:
                    tmp[i][j] = 0
                elif board[i][j] == 0 and num == 3:
                    tmp[i][j] = 1
        for i in range(m):
            for j in range(n):
                board[i][j]  = tmp[i][j]
    def judge(self,board,x,y):
        res = 0
        for i in range(x-1,x+2):
            for j in range(y-1,y+2):
                if i<0 or j<0 or i>len(board)-1 or j > len(board[0]) -1 or (i==x and j==y):
                    continue
                else:
                    if board[i][j] == 1:
                        res+=1
        return res
