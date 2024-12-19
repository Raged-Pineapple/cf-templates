#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	vector<int>arr(n);
	map<int,int>mpp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		mpp[arr[i]] = i+1;
	}
	for(int i=1;i<=n;i++){
		cout<<mpp[i]<<' ';
	}
	cout<<endl;
	return 0;
}
