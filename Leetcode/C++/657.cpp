class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> ordinate;
        ordinate['U'] = 0;
        ordinate['D'] = 0;
        ordinate['L'] = 0;
        ordinate['R'] = 0;
        
        for(int i=0; i< moves.size(); i++)
            ordinate[moves[i]] ++;
        
        if (ordinate['U'] == ordinate['D'] && ordinate['L'] == ordinate['R'])
            return true;
        else
            return false;
    }
};