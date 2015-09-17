__author__ = 'SunStrike'
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        flag = True
        stack = []
        for i in s:
            if i == '(' or i == '{' or i == '[':
                stack.append(i)
            if len(stack) == 0 and (i == ')' or i == '}' or i == ']'):
                return False
            elif i == ')':
                if stack.pop() != '(':
                    flag = False
            elif i == ']':
                if stack.pop() != '[':
                    flag = False
            elif i == '}':
                if stack.pop() != '{':
                    flag = False
        if len(stack) != 0:
            flag = False
        return flag