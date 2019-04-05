class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        res = {}
        for cpdomain in cpdomains:
            num, site = cpdomain.split()
            num = int(num)
            site_arr = site.split('.')
            
            suffix = site_arr[-1]
            if suffix not in res:
                res[suffix] = num
            else:
                res[suffix] += num
            for i in range(len(site_arr)-2, -1, -1):
                suffix = site_arr[i] + '.' + suffix
                if suffix not in res:
                    res[suffix] = num
                else:
                    res[suffix] += num
        
        res_arr = []
        for domain, count in res.items():
            s = str(count) + " " + domain
            res_arr.append(s)
        
        return res_arr