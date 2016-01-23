class Solution(object):
    def calculate(self,s):
        s = s+'+'
        res, num, sign, stack = 0, 0, 1, []
        for ss in s:
            if ss.isdigit():
                num = 10*num + ord(ss) - ord('0')
            elif ss in '+-':
                if stack and stack[-1] in '*/':
                    md, val = stack.pop(),stack.pop()
                    num = val*num if md == '*' else val/num
                res,num,sign = res+sign*num, 0, [-1, 1][ss=="+"]
            elif ss in '*/':
                if stack and stack [-1] in '*/':
                    md, val = stack.pop(), stack.pop()
                    num = val*num if md == "*" else val/num
                stack.extend([num,ss])
                num = 0
        return int(res)