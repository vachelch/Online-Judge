class Solution:
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses.sort()
        heaters.sort()
        cur = 0
        l_heater = len(heaters)
        mx = 0
        for h in houses:

            while cur<=l_heater-2 and h >= heaters[cur]:
                cur += 1

            if cur == 0:
                mx = max(abs(heaters[0] - h), mx)
            else:
                mx = max(min(abs(heaters[cur]-h), abs(heaters[cur-1]-h)), mx)

        return mx

