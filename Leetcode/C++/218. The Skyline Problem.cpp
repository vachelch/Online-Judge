// pay attention on left edge line and right edge line
class Solution {
public:
    struct cmp{
        bool operator() (pair<int, int> &a, pair<int, int> &b){
            return a.first >= b.first;
        }    
    };
    
    map <int, int> height2cnt;
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        priority_queue<int, vector<int>, less<int> > height_heap;
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> node_heap;
        vector<pair<int, int> > res;
        
        int i=0;
        while(i < buildings.size()){
            // no right line, and meet new building left line 
            if (node_heap.empty()){
                res.push_back(make_pair(buildings[i][0], buildings[i][2]));

                height_heap.push(buildings[i][2]);
                height2cnt[buildings[i][2]] ++;
                node_heap.push(make_pair(buildings[i][1], buildings[i][2]));
                i++;
            }

            // past building right line is ahead
            else if (buildings[i][0] < node_heap.top().first){
                if (buildings[i][2] > height_heap.top()){
                    if (!res.empty() && res.back().first == buildings[i][0])
                        res.back().second = max(res.back().second, buildings[i][2]);
                    else
                        res.push_back(make_pair(buildings[i][0], buildings[i][2]));
                };
                
                height_heap.push(buildings[i][2]);
                height2cnt[buildings[i][2]] ++;
                node_heap.push(make_pair(buildings[i][1], buildings[i][2]));
                i++;
            }

            // meet new building left line and past building right line together
            else if (buildings[i][0] == node_heap.top().first){
                pair<int, int> tmp;
                pair<int, int> mx = node_heap.top();
                while(!node_heap.empty() && buildings[i][0] == node_heap.top().first){
                    tmp = node_heap.top();
                    if (mx.second < tmp.second)
                        mx = tmp;

                    node_heap.pop();
                    // to handle the pop problem
                    height2cnt[tmp.second] --;

                    while(!height_heap.empty() && height2cnt[height_heap.top()] == 0){
                        height_heap.pop();
                    }
                }
                
                if (buildings[i][2] != mx.second && (height_heap.empty() || buildings[i][2] > height_heap.top())){
                    if (!res.empty() && res.back().first == buildings[i][0])
                        res.back().second = max(res.back().second, buildings[i][2]);
                    else
                        res.push_back(make_pair(buildings[i][0], buildings[i][2]));
                }

                height_heap.push(buildings[i][2]);

                height2cnt[buildings[i][2]] ++;
                node_heap.push(make_pair(buildings[i][1], buildings[i][2]));
                i++;
            }

            // past building right line is ahead 
            else if(buildings[i][0] > node_heap.top().first){
                pair<int, int> tmp = node_heap.top();
                node_heap.pop();
                

                // to handle the pop problem
                height2cnt[tmp.second] --;
                while(!height_heap.empty() && height2cnt[height_heap.top()] == 0){
                    height_heap.pop();
                }


                if (height_heap.empty()){
                    if (!res.empty() && res.back().first == tmp.first)
                        res.back().second = 0;
                    else
                        res.push_back(make_pair(tmp.first, 0));
                }
                else if (tmp.second > height_heap.top()){
                    if (!res.empty() && res.back().first == tmp.first)
                        res.back().second = min(height_heap.top(), res.back().second);
                    else
                        res.push_back(make_pair(tmp.first, height_heap.top()));
                }   
            }
        }
        
        // only edge right exist
        while(!node_heap.empty()){
            pair<int, int> tmp = node_heap.top();
            node_heap.pop();

            // to handle the pop problem
            height2cnt[tmp.second] --;
            while(!height_heap.empty() && height2cnt[height_heap.top()] == 0)
                height_heap.pop();

            if (height_heap.empty()){
                if (!res.empty() && res.back().first == tmp.first)
                    res.back().second = 0;
                else
                    res.push_back(make_pair(tmp.first, 0));
            }
            else if (tmp.second > height_heap.top()){
                if (!res.empty() && res.back().first == tmp.first)
                    res.back().second = min(height_heap.top(), res.back().second);
                else
                    res.push_back(make_pair(tmp.first, height_heap.top()));
            } 
        }
        
        return res;
        
    }
};


"""
Step 1:
    Use a multimap to sort all boundary points. For a start point of an interval, let the height be positive; otherwise, let the height be negative. Time complexity: O(n log n)
Step 2:
    Use a multiset (rather than a heap/priority_queue) to maintain the current set of heights to be considered. If a new start point is met, insert the height into the set, otherwise, delete the height. The current max height is the back() element of the multiset. For each point, the time complexity is O(log n). The overall time complexity is O(n log n).
Step 3:
    Delete the points with equal heights. Time: O(n)
"""
// concise solution
// multiset, multimap get the initial order of two same values
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {

        // Step 1:
        multimap<int, int> coords;
        for (const vector<int> & building : buildings) {
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], -building[2]);
        }

        // Step 2:
        multiset<int> heights = { 0 };
        map<int, int> corners;
        for (const pair<int, int> & p : coords) {
            if (p.second > 0) {
                heights.insert(p.second);
            }
            else {
                heights.erase(heights.find(-p.second));
            }
            int cur_y = *heights.rbegin();
            corners[p.first] = cur_y;
        }

        // Step 3:
        function<bool(pair<int, int> l, pair<int, int> r)> eq2nd = [](pair<int, int> l, pair<int, int> r){ return l.second == r.second;  };
        vector<pair<int, int>> results;
        unique_copy(corners.begin(), corners.end(), back_insert_iterator<vector<pair<int, int>>>(results), eq2nd);
        return results;
    }
};
