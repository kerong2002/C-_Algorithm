//2023/04/01 kerong
/*
   Algorithm : Postfix
    Time complexity: O(n)
   Space complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
int evalPostfix(vector<string> tokens) {
    stack<int>  s;
    for(int x=0;x<tokens.size();x++){
        if(isdigit(tokens[x][tokens[x].length()-1])){
            s.push(stoi(tokens[x]));
        }
        else{
            int top2 = s.top();
            s.pop();
            int top1 = s.top();
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
    int result = s.top();
    s.pop();
    return result;
}

int main(){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalPostfix(tokens);
    return 0;
}
