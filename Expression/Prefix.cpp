//2023/04/10 kerong
/*
   Algorithm : Prefix
    Time complexity: O(n)
   Space complexity: O(n)
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int evalPrefix(vector<string> tokens) {
    stack<int>  s;
    for(int x=tokens.size()-1;x>=0;x--){
        if(isdigit(tokens[x][tokens[x].length()-1])){
            s.push(stoi(tokens[x]));
        }
        else{
            int top1 = s.top();
            s.pop();
            int top2 = s.top();
            s.pop();
            int ans = 0;
            switch(tokens[x][0]){
                case '+':
                    ans = top1 + top2;
                    break;
                case '-':
                    ans = top1 - top2;
                    break;
                case '*':
                    ans = top1 * top2;
                    break;
                case '/':
                    ans = top1 / top2;
                    break;
            }
            s.push(ans);
        }
    }
    return s.top();
}

int main(){
    //2*3 - 4/5
    vector<string> tokens = {"-", "*", "2", "3", "/", "4", "5"};
    cout << evalPrefix(tokens);
    return 0;
}
