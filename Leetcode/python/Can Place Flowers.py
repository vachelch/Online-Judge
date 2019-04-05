class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        l = len(flowerbed)
        if l <= 2:
            if sum(flowerbed) >0:
                if n>0:
                    return False
                else:
                    return True
            else:
                if n <= 1:
                    return True
                else:
                    return False
        count = 0
        for i in range(l):
            if i == 0:
                if flowerbed[0]== 0 and flowerbed[1]== 0:
                    flowerbed[0] = 1
                    count +=1
            elif i == l-1:
                if flowerbed[l-1]== 0 and flowerbed[l-2]== 0:
                    flowerbed[l-1] = 1
                    count +=1
            elif flowerbed[i-1]== 0 and flowerbed[i]== 0 and flowerbed[i+1]== 0:
                flowerbed[i] = 1
                count += 1
                
        if count >= n:
            return True
        else: return False








