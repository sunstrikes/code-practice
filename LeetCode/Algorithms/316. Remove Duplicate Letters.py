import collections
class Solution(object):
    def removeDuplicateLetters(self, s):
        counter = collections.Counter(s)
        res = set()
        stack = list()
        for c in s:
            counter[c]-=1
            if c in res:
                continue
            while stack and stack[-1]>c and counter[stack[-1]]:
                res.remove(stack.pop())
            res.add(c)
            stack.append(c)
        return ''.join(stack)    