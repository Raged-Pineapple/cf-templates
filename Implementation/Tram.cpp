#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	vector<int>a(n);
	vector<int>b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	int maxcap = 0;
	int num = 0;
	for(int i=0;i<n;i++){
		maxcap = max(maxcap,num);
		num+=b[i]-a[i];
	}
	cout<<maxcap<<endl;
	return 0;
}
