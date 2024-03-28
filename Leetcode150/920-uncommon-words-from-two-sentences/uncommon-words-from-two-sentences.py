class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        l=[]
        k=s1.split(" ")
        a=s2.split(" ")
        d={}
        for word in k:
            if word not in d:
                d[word]=1
            else:
                d[word]+=1
        for word in a:
            if word not in d:
                d[word]=1
            else:
                d[word]+=1
        for i in d:
            if d[i]==1:
                l.append(i)
        return l
        