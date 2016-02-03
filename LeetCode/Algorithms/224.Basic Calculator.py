class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.replace(' ','')
        stack = []
        ans = 0
        num = 0
        sign = 1
        for i in range(len(s)):
            if s[i].isdigit():
                num = num*10 + int(s[i])
                continue
            stack.append(sign * num)
            num = 0
            if s[i] == '+':
                sign = 1
            elif s[i] == '-':
                sign = -1
            elif s[i] == '(':
                if sign == 1:
                    stack.append('+')
                else:
                    stack.append('-')
                sign = 1
            elif s[i] == ')':
                tmp = 0
                while stack[-1] != '+' and stack[-1] != '-':
                    tmp += stack.pop()
                if stack[-1] == '-':
                    tmp = -tmp
                stack.pop()
                stack.append(tmp)
        if num != 0:
            stack.append(sign*num)
        while stack:
            ans += stack.pop()
        return ans