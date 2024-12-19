#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long n;
	cin>>n;
	int cnt4 = 0;
	int cnt7 = 0;
	while(n>0){
		int ld = n%10;
		if(ld == 4)cnt4++;
		else if(ld == 7)cnt7++;
		n/=10;
	}
	int sum = cnt4+cnt7;
	bool flag = true;
	if(sum == 0) flag = false;
	while(sum>0){
		int last = sum%10;
		if(sum!=4 && sum!=7)flag = false;
		sum/=10;
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
