class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        241
        """
        res= []
        isNum = True
        for i in range(len(input)):
            if input[i] == '+' or input[i] =='-' or input[i] == '*':
                isNum = False
                left = self.diffWaysToCompute(input[0:i])
                right = self.diffWaysToCompute(input[i+1:len(input)])
                for j in range(len(left)):
                    for k in range(len(right)):
                        if input[i] == '+':
                            res.append(left[j]+right[k])
                        if input[i] == '-':
                            res.append(left[j]-right[k])
                        if input[i] == '*':
                            res.append(left[j]*right[k])
        if isNum:
            res.append(int(input))
        return res