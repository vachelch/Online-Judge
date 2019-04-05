class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        content_map = {}
        for path in paths:
        	path = path.split()
        	dir_path, files = path[0], path[1:]
        	for file in files:
        		name, content = file.split('(')
        		content = content[:-1]
        		if content not in content_map:
        			content_map[content] = [ dir_path + '/' + name]
        		else:
        			content_map[content].append(dir_path + '/' + name)

        return [val for _, val in content_map.items() if len(val) > 1]
