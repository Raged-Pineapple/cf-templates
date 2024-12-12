*/we should find the median of the 3 integers given bcz,mean that is average doesnt guarantee min distance everytime
General Principle:
For absolute differences, the median minimizes the sum of distances.
For squared differences, the mean minimizes the sum of distances.*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x1,x2,x3;
    cin>>x1>>x2>>x3;
    int pos[] = {x1,x2,x3};
    sort(pos,pos+3);
    int ans = pos[1];
    int dist = abs(x1-ans)+abs(x2-ans)+abs(x3-ans);
    cout<<dist<<endl;
    return 0;
}

