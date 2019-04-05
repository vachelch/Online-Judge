class Solution {
public:
    bool back_trace(char* matrix, int rows, int cols, int cur, int idx, char* str){
        if (idx == strlen(str)) return true;
        int r = cur/cols;
        int c = cur%cols;
        if (r< 0 || r >= rows || c < 0 || c >= cols) return false;
        if (matrix[cur] != str[idx]) return false;

        matrix[cur] = ~matrix[cur];
        int rp[] = {0, 0, -1, 1};
        int cp[] = {-1, 1, 0, 0};
        for(int i=0; i< 4; i++){
            int r_ = r + rp[i];
            int c_ = c + cp[i];
            int next = r_ * cols + c_;
            if (back_trace(matrix, rows, cols, next, idx+1, str)){
                return true;
            }
        }
        matrix[cur] = ~matrix[cur];
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        for(int i=0; i< rows*cols; i++){
            if (back_trace(matrix, rows, cols, i, 0, str)) return true;
        }
        return false;
    }
};







class Solution {
public:
    bool doHavePath(char* matrix, int rows, int cols, int m_idx, char* str, int s_idx){
        if (m_idx >= rows*cols || m_idx< 0 || matrix[m_idx] != str[s_idx]) return false;
        if (s_idx == strlen(str)-1) return true;
        
        matrix[m_idx] = ~matrix[m_idx];
        int r = m_idx / cols, c = m_idx % cols;
        int r_plus[] = {0, 0, 1, -1};
        int c_plus[] = {1, -1, 0, 0};
        
        for(int i=0; i< 4; i++){
            int r_new = r + r_plus[i], c_new = c + c_plus[i];
            int idx = r_new*cols + c_new;
            if (doHavePath(matrix, rows, cols, idx, str, s_idx+1))
                return true;
        }
        
        matrix[m_idx] = ~matrix[m_idx];
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        for(int i=0; i< rows*cols; i++){
            if(doHavePath(matrix, rows, cols, i, str, 0)) return true;
        }
        
        return false;
    }


};