class Solution:
    def dfs(self, needs, total):
        if any([n<0 for n in needs]) : return 

        self.mn = min(self.mn, total)

        for s in self.special:
            init_price = 0
            for i in range(len(needs)):
                needs[i] = needs[i] - s[i]
                init_price += s[i] * self.price[i]
            self.dfs(needs, total + s[-1] - init_price)
            for i in range(len(needs)):
                needs[i] = needs[i] + s[i]
            
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        self.price = price
        self.special = special
        self.mn = 2000000000
    
        total = 0        
        for i in range(len(price)):
            total += price[i] * needs[i]
        
        self.dfs(needs, total)
        
        return self.mn
