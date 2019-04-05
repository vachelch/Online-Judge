class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<vector<int>>res;
    bool book(int start, int end) {
        for(int i = 0; i< res.size(); i++){
        	int s = res[i][0];
        	int e = res[i][1];
        	if (!(start >= e || end <= s)) return false;
        }
        res.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */