__author__ = 'SunStrike'
class Solution(object):
    buttons = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }

    def travel(self, string, index, ret):
        if index == len(string):
            ret.append(string)
        else:
            tmp = self.buttons[string[index]]
            for i in range(len(tmp)):
                string2 = string.replace(string[index], tmp[i], 1)
                #string[index] = tmp[i]
                self.travel(string2, index+1, ret)



    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        ret = []
        string = str(digits)
        if string == '':
            return ret
        else:
            self.travel(string, 0, ret)
            return ret
