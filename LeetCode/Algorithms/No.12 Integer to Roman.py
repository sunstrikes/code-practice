class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        string = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        val = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        #num = int(input('input a number'))
        result = ""
        for i in range(len(string)):
            while num >= val[i]:
                result += string[i]
                num -= val[i]
            if num == 0:
             break
        return result

