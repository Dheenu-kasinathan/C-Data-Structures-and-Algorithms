#include <iostream>
#include<string>
#include<stack>
#include<math.h>

using namespace std;

int evaluateString(string s){
    stack<int> stk;
    stack<char> opt;

    for (int i =0; i < s.length() ; i++){
        if(s[i] != '+' && s[i] != '*'){
            int temp = 0;
            while(i < s.length() && isdigit(s[i])){
                temp = (temp*10) + (s[i]-'0');
                i++;
            }
            stk.push(temp);
            if (s[i] != 0)
                opt.push(s[i]);
        }
    }
    int answer = 0;
    
    while(!stk.empty()){
        if(opt.top() == '*'){
            opt.pop();
            int temp_0 = 0 ;
            int temp_1 = stk.top();
            stk.pop();
            int temp_2 = stk.top();
            stk.pop();
            temp_0 = temp_1 * temp_2;
            stk.push(temp_0);
            if(opt.empty()){
                answer += stk.top();
                stk.pop();
            }
        }
        else if(opt.top() == '+'){
            opt.pop();
            answer += stk.top();
            stk.pop();
            if(opt.empty()){
                answer += stk.top();
                stk.pop();
            }
        }
    }
    return answer;
}

int main(){
    string s = "3*5+11+5*20+9*2*4+135";
    int value = evaluateString(s);
    cout<<endl;
    cout<<"the final answer is: " << value<<endl;
}
