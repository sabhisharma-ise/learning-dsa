// Evaluation of Postfix Expression

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int isOperand (char x) {
        
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return 0;
        else 
            return 1;
    }
    
    
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;

        for (int i = 0; i < S.length(); i++) {
            
            if (isOperand(S[i])) {
                st.push(S[i] - '0');
            }
            
            else {
                int y = st.top();
                st.pop();
                
                int x = st.top();
                st.pop();
                
                int res = -1;
                if (S[i] == '+') {
                    res = x + y;
                }
                else if (S[i] == '-') {
                    res = x - y;
                }
                else if (S[i] == '*') {
                    res = x * y;
                }
                else if (S[i] == '/') {
                    res = x / y;
                }
                
                st.push(res);
            }
        }
        
        return st.top();
    }

    int main () {


        string s = "231*+9-";

        cout << evaluatePostfix(s);

        return 0;
    }