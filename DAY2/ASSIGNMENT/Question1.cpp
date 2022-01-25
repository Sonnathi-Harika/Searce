
// Online IDE - Code Editor, Compiler, Interpreter

vector<int> getMax(vector<string> operations) {
    stack<int>s;
    vector<int>ans;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='1'){
            int len=operations[i].length();
            string temp=operations[i].substr(2,len-2);
            int num=stoi(temp);
            s.push(num);
            continue;
        }
        if(operations[i][0]=='2'){
            s.pop();
            continue;
        }
        if(operations[i][0]=='3'){
            ans.push_back(s.top());
            continue;
        }
    }
    return ans;
}
