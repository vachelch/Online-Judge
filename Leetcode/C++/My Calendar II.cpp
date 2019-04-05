class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }

    vector<vector<int>> once_;
    vector<vector<int>> double_;


    bool book(int start, int end) {
    	int l_d = double_.size();
    	int l_o = once_.size();
        //check triple booking
    	for(int i=0; i<l_d; i++){
    		int s = double_[i][0];
			int e = double_[i][1];

			//triple booking
			if(!(end <= s || start >= e)) return false;
    	}

    	//check double booking
    	int is_double = 0;
		for(int j=0; j<l_o; j++){
			int s_o = once_[j][0];
			int e_o = once_[j][1];
			
			//double booking, update once_, double_
			if(!(end <= s_o || start >= e_o)){
				once_[j] = {min(s_o, start), max(e_o, end)};
				double_.push_back({max(s_o, start), min(e_o, end)});
				is_double = 1;
			}
		}
		if(is_double)
			return true;

		//first booking
		once_.push_back({start, end});
		return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */