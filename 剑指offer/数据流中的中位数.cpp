class Solution {
public:
    priority_queue<int, vector<int>> heap_max;
    priority_queue<int, vector<int>, greater<int>> heap_min;
    
    void Insert(int num)
    {
        if (heap_max.size() == 0) heap_max.push(num);
        else if (heap_min.size() == 0){
            if (num >= heap_max.top()){
                heap_min.push(num);
            }
            else{
                int tmp = heap_max.top();
                heap_max.pop();

                heap_min.push(tmp);
                heap_max.push(num);
            }
        } 
        else if (heap_max.size() == heap_min.size()){
            if(num <= heap_min.top()){
                heap_max.push(num);
            }
            else{
                int mn = heap_min.top();
                heap_min.pop();

                heap_max.push(mn);
                heap_min.push(num);
            }       
        }
        else{
            if(num >= heap_max.top()){
                heap_min.push(num);
            }
            else{
                int mx = heap_max.top();
                heap_max.pop();

                heap_min.push(mx);
                heap_max.push(num);
            }
        }
    }

    double GetMedian()
    { 
        if (heap_min.size() == heap_max.size()){
            double two = 2.0;
            return (heap_min.top() + heap_max.top()) / two;
        }
        else
            return heap_max.top();
    }

};