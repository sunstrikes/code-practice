"""
my solution runs 972ms, too slow. Orz
class Solution(object):
    def findOrder(self, num, pre):
        imp = {}
        res = []
        for i in range(num):
            imp[i] = 0
        for i in pre:
            imp[i[0]] += 1
        while len(imp):
            for item, value in imp.items():
                if value == 0:
                    begin = item
                    res.append(item)
                    imp.pop(item)
                    break
            else:
                return []
            for x in range(len(pre)):
                if pre[x][1] == begin:
                    imp[pre[x][0]] -= 1
        return res

solu = Solution()
print(solu.findOrder(1,[]))

"""
#80ms dfs solution
class Solution(object):    
    def findOrder(self,numCourses, prerequisites):
        def dfs(i, visited, graph, ret):
            #Stop visiting checked nodes
            if visited[i] == 1:
                return True
            #If cycle is detected, return False
            if visited[i] == -1:
                return False
    
            visited[i] = -1
            for n in graph[i]:
                if not dfs(n, visited, graph, ret):
                    return False
            #collecting results
            ret.append(i)
    
            visited[i] = 1
            return True
    
        #Initializing graph data
        visited = [0] * numCourses
        graph = {x:[] for x in xrange(numCourses)}
        for p in prerequisites:
            graph[p[1]].append(p[0])
    
        #collecting topological order
        ret = []
        for i in xrange(numCourses):
            if not dfs(i, visited, graph, ret):
                return []
    
        return ret[::-1]