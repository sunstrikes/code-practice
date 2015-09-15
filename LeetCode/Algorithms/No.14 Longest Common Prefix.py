class Solution(object):
    def longestCommonPrefix(self, strs):
        xiao = 0
        sub_str = ""
        for i in strs:
            if len(i) > xiao:
                xiao = len(i)
        for i in range(1, xiao+1):
            tmp = strs[0][:i]
            flag = True
            for item in strs:
                if item.find(tmp) !=0:
                    flag = False
                    break
            if flag:
                sub_str = tmp
        return sub_str
