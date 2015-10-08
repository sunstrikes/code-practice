class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []
        total = 2**n
        for i in range(total):
            res.append(self.bin_to_gray(i))
        return res
    def bin_to_gray(self,n):
        string  = bin(n)[2:]
        res = []
        res.append(string[0])
        for i in range(0,len(string)-1):
            res.append(self.XOR(string[i],string[i+1]))
        res_str = ''.join(res)
        return int(res_str,2)

    def XOR(self,str1,str2):
        if str1==str2:
            return '0'
        else:
            return '1'
