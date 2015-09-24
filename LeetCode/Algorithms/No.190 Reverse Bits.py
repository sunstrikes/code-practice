class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        ll = []
        res = ''
        binary = bin(n)[2:]
        if len(binary)<32:
            tmp = '0'*(32 - len(binary))
            binary = tmp + binary
        ll = list(binary)
        ll.reverse()
        for i in ll:
            res = res + i
        return int(res, 2)