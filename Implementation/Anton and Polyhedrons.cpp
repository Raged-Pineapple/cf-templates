#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string,int>mpp;
    mpp["Tetrahedron"] = 4;
    mpp["Octahedron"] = 8;
    mpp["Dodecahedron"] = 12;
    mpp["Cube"] = 6;
    mpp["Icosahedron"] = 20;
    int t;
    cin>>t;
    int ans=0;
    while(t--){
        string s;
        cin>>s;
        ans+=mpp[s];
    }
    cout<<ans<<endl;
    return 0;
    
}
