class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int size = input.size();
        vector<int> result;
        
        for(int i=0; i<size; i++){
            char opt = input[i];
            if (opt == '*' || opt == '+' || opt == '-'){
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));    
                vector<int> result2 = diffWaysToCompute(input.substr(i+1)); 
            
                if (opt == '*'){
                    for(int j=0; j< result1.size(); j++)
                        for(int k=0; k< result2.size(); k++)
                            result.push_back(result1[j] * result2[k]);
                }
                if (opt == '+'){
                    for(int j=0; j< result1.size(); j++)
                        for(int k=0; k< result2.size(); k++)
                            result.push_back(result1[j] + result2[k]);
                }
                if (opt == '-'){
                    for(int j=0; j< result1.size(); j++)
                        for(int k=0; k< result2.size(); k++)
                            result.push_back(result1[j] - result2[k]);
                }
            }
        }
        if (result.empty())
            result.push_back(stoi(input));
        return result;
    }
};