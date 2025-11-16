class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<pair<char,int>> stk;
        for(int i = 0 ; i <s.size(); i++){
            char c= s[i];
            if(c == ')'){
                if(stk.empty()){
                    stk.push({c, 1});
                    continue;
                }
                auto t = stk.top();
                if(t.first == '('){
                    if(t.second >= k){
                        int ind = i;
                        int cnt = 0;
                        while(ind  < s.size() && s[ind] == ')' && cnt < k){
                            ind++;
                            cnt++;
                        }
                        if(cnt== k){
                            while( cnt > 0){
                                stk.pop();
                                cnt--;
                            }
                            i = ind-1;
                            cout << "i : "<<i  << endl;
                        }else stk.push({c, 1});
                    }else{
                        stk.push({c, 1});
                    }
                }else{
                    stk.push({c, t.second +1});
                }
            }else{ // (
                if(stk.empty()){stk.push({c, 1});continue;}
                auto t = stk.top();
                if(t.first == '(')stk.push({c, t.second +1});
                else stk.push({c, 1});
            }
        }
        string res;
        while(!stk.empty()){
            res = res + stk.top().first;
            stk.pop();
        } 
        reverse(res.begin(), res.end());
        return res;
    }
};