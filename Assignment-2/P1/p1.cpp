#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

bool check(int n, string str){
    stack<char> s;
    char a;
    for (int i=0; i<n; i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            s.push(str[i]);
            continue;
        }
        else if((str[i]==')' || str[i]==']' || str[i]=='}') && s.empty()==1){
            return false;
        }
        if(str[i]==')'){
            a=s.top();
            s.pop();
            if (a=='{' || a=='['){
                return false;
            }
            continue;
        }
        if(str[i]==']'){
            a=s.top();
            s.pop();
            if (a=='{' || a=='('){
                return false;
            }
            continue;
        }
        if(str[i]=='}'){
            a=s.top();
            s.pop();
            if (a=='(' || a=='['){
                return false;
            }
            continue;
        }
    }
    return s.empty();
}

int main(){
    int n;
    string s;
    cin>>n>>s;
    cout<<check(n,s);
	
}
