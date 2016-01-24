class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        num = []
        res = 0
        for val in tokens:
            if val[0].isdigit() or (len(val)>1 and val[1].isdigit()):
                num.append(float(val))
            else:
                op1,op2 = num.pop(),num.pop()
                if val =="+":
                    num.append(op1+op2)
                if val =="-":
                    num.append(op2-op1)
                if val =="*":
                    num.append(op1*op2)
                if val =="/":
                    num.append(int(op2/op1))
        return int(num[0])