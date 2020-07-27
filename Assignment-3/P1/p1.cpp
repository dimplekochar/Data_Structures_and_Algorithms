#include <iostream>
#include <map>
using namespace std;

class sparse_poly{
public:
	map <long long, long long> poly;

	sparse_poly(){};
	void add(sparse_poly p1, sparse_poly p2){
		map<long long, long long>::iterator ip1=(p1.poly).begin();
    	map<long long, long long>::iterator ip2=(p2.poly).begin();

    	poly.clear();

    	while(ip1!=(p1.poly).end()){
       		poly[ip1->first]+=ip1->second;
       		ip1++;
       	}
    	while(ip2!=(p2.poly).end()){
        	poly[ip2->first]+=ip2->second;
        	ip2++;
		}
	}
	void output(){
    	map<long long, long long>::iterator iter1=poly.begin();
		if (iter1 == poly.end()) return;
		while (iter1!=poly.end()){
        	cout << iter1->second << " ";
        	iter1++;
        }
    	cout <<endl;
    	map<long long, long long>::iterator iter2=poly.begin();
    	while (iter2!=poly.end()){
        	cout << iter2->first << " ";
        	iter2++;
        }
    	cout <<endl;
	}
};

int main(){
	sparse_poly q1, q2, q3;
	int n1, n2;
	cin>>n1;
	long long a[n1], b[n1]; 
	for (int i=0; i<n1; i++){
		cin >> a[i];
	}
	for (int i=0; i<n1; i++){
		cin >> b[i];
	}
	for (int i=0; i<n1; i++){
		q1.poly[b[i]]=a[i];
	}
	cin>>n2;
	long long c[n2], d[n2]; 
	for (int i=0; i<n2; i++){
		cin >> c[i];
	}
	for (int i=0; i<n2; i++){
		cin >> d[i];
	}
	for (int i=0; i<n2; i++){
		q2.poly[d[i]]=c[i];
	}
    q3.add(q1, q2);
    q3.output();

    return 0;
	
}