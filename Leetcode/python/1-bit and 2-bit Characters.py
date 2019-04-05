class Solution:
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        i=0
        while i< len(bits) - 2:
            if(bits[i] == 1):
                i += 2
            else:
                i += 1
        
        if i == len(bits) - 1:
            return True
        #else i == len(bits) - 2
        elif bits[i] == 0:
            return True 
        else: 
            return False
            