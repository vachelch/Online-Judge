class Solution:
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        ban = set(banned)
        paragraph = re.sub(r'[!?\',;.]', '', paragraph)
        words = paragraph.lower().split()
        
        
        word_dict = {}
        mx = 0
        for word in words:
            if word not in ban:
                if word in word_dict:
                    word_dict[word] += 1
                else:
                    word_dict[word] = 1
                    
                if word_dict[word] > mx:
                    common = word
                    mx = word_dict[word]
        
        return common
                    
            
        