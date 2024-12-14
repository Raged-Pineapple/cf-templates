#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            // Odd rows are fully filled with '#'
            cout << string(m, '#') << endl;
        } else {
            /* Even rows alternate between rightmost and leftmost '#'
            It works like 2,6,10,14 ..have #in right
            4,8,12,.... have # in left.there is no clear pattern in i thats why 
            so we start checking for (i/2) as it results in 1,2,3,4 and now even odd concept*/
            
            if ((i / 2) % 2 == 1) {
                cout << string(m - 1, '.') + "#" << endl; // '#' at the right
            } else {
                cout << "#" + string(m - 1, '.') << endl; // '#' at the left
            }
        }
    }

    return 0;
}
