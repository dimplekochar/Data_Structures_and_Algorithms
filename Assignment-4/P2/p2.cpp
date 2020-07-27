#include <iostream>
#include <stack>
using namespace std;
  
void median(int arr[], char com[], int n){ 
    int k=0, i=1;
    stack <int> a, b;
    if (arr[k]<=arr[k+1]){
        a.push(arr[k]);
        b.push(arr[k+1]);
    }
    else{
        a.push(arr[k+1]);
        b.push(arr[k]);
    }
    while (com[i]=='m'){
        cout << arr[k];
        i++;
    }
    i++;
    k=k+2;
    for (int l=i; l<n; l++){
        if (com[l]=='c'){
            if(arr[k]>=a.top() && arr[k]<=b.top()){
                a.push(arr[k]);
                k++;
            }
            else if(arr[k]>b.top()){
                int t=b.top();
                while(arr[k]>t && !b.empty()){
                    t= b.top();
                    a.push(t);
                    b.pop();
                }
                b.push(arr[k]);
                k++;
            }
            else if(arr[k]<a.top()){
                int t=a.top();
                while(arr[k]<t && !a.empty()){
                    t= a.top();
                    b.push(t);
                    a.pop();
                }
                a.push(arr[k]);
                k++;
            }
        }
        else if (com[l]=='m'){
            if (a.size()==b.size()){
                cout << (a.top()+b.top())/2 << " ";
            }
            else if (b.size()>a.size()){
                while(b.size()>a.size()){
                    int t= b.top();
                    a.push(t);
                    b.pop();
                }
                if ((a.size()+b.size())%2==0)
                    cout << (a.top()+b.top())/2 << " ";
                else if ((a.size()+b.size())%2==1)
                    cout << a.top() << " ";
            }
            else if (a.size()>b.size()){
                while(a.size()>b.size()){
                    int t= a.top();
                    b.push(t);
                    a.pop();
                }
                if ((a.size()+b.size())%2==0)
                    cout << (a.top()+b.top())/2 << " ";
                else if ((a.size()+b.size())%2==1)
                    cout << b.top() << " ";
            }
        }
    }
   
} 
int main(){ 
   int n, j=0;
   cin >> n;
   int arr[n]; 
   char com[n]; 
   for (int i=0; i<n; i++){
   	cin >> com[i];
   	if (com[i]=='c'){
   		cin >> arr[j];
   		j++;
	}
   }
   median(arr, com, n);
} 