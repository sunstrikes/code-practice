class Solution(object):
    def isValidSudoku(self, b):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        length = 9
        set1 = set([])
        set2 = set([])
        for i in range(9):
            set1.clear()
            set2.clear()
            for j in range(9):
                if b[i][j]!='.':
                    if b[i][j] not in set1:
                        set1.add(b[i][j])
                    else:
                        return False
                if b[j][i]!='.':
                    if b[j][i] not in set2:
                        set2.add(b[j][i])
                    else:
                        return False
        for i in range(0,9,3):
            for j in range(0,9,3):
                set2.clear()
                for k in range(3):
                    for l in range(3):
                        if b[i+k][j+l]!='.':
                            if b[i+k][j+l] not in set2:
                                set2.add(b[i+k][j+l])
                            else:
                                return False
        return True