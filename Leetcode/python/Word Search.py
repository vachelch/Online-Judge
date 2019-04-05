class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m = len(board)
        if m == 0: return False
        n = len(board[0])
        if n==0: return False
        visited = [[0 for i in range(n)] for j in range(m)]
        l = len(word)

        def search(i, j, word, index):
            if index == l: return True
            if 0 <= i< m and 0 <= j < n and board[i][j] == word[index] and not visited[i][j]:
                visited[i][j] = 1
                if search(i-1, j, word, index+1) or search(i+1, j, word, index+1) or search(i, j-1, word, index+1) or search(i, j+1, word, index+1):
                    return True
                visited[i][j] = 0

            return False

        for i in range(m):
            for j in range(n):
                if search(i, j, word, 0):
                    return True

        return False

        


