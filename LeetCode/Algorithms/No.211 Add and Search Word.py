'''
import collections
class WordDictionary(object):
    def __init__(self):
        self.len2words = collections.defaultdict(list)

    def addWord(self, word):
        self.len2words[len(word)].append(word)

    def search(self, word):
        words = self.len2words[len(word)]
        for i, char in enumerate(word):
            words = [w for w in words if char in ('.', w[i])]
            if not words: return False
        return True
'''
class WordDictionary(object):
    def __init__(self):
        self.chars = {}  #each char is the key and each key has a dict as its value

    def addWord(self, word):
        curr = self.chars
        for c in word:
            if c not in curr:
                curr[c] = {}
            curr = curr[c]
        curr['#'] = {}  #indicate the end of a word


    def search(self, word):
        return self.search_dfs(word, self.chars)


    def search_dfs(self, word, curr):
        if len(word)==0:
            return '#' in curr
        c = word[0]
        if c == '.':
            for char in curr:
                if self.search_dfs(word[1:], curr[char]):
                    return True
            return False
        # now c is a-z
        if c in curr:
            return self.search_dfs(word[1:], curr[c])
        return False