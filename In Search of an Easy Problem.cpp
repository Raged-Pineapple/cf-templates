#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = false;
    while(n>0){
        int num;
        cin>>num;
        if(num == 1) flag=true;
        n--;
    }
    if(flag == true) cout<<"HARD"<<endl;
    else cout<<"EASY";
    return 0;
}
