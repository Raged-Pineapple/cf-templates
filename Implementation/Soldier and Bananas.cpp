#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,n,w;
	cin>>k>>n>>w;
	int ans = w*(w+1)*k/2;
	if(n>ans)cout<<0<<endl;
	else cout<<ans-n<<endl;
	return 0;
}
