#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int max_index = 0, min_index = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[max_index]) max_index = i;
        if (nums[i] <= nums[min_index]) min_index = i; 
    }

    // Calculate the total swaps
    /*the distance between the max element and the first position is equal to max element' index itself,
    now the min element should be shifted to the last index,so it has to effectively go to ((n-1)-min_index),because we have to move it to the last
    */
    int swaps = max_index + (n - 1 - min_index);
    if (max_index > min_index) swaps--;
    /* Adjust for overlap:-
    ovrelap means,for ex if the larger element is to the right of the smallest element,so while bringin the largest element to the left,all the positions are shifted to right by 1,even the position of the smallest element
    ex)[4, 1, 5, 2, 3]
    now 5 has to have 2 shifts to get to the first position
    [5, 4, 1, 2, 3],now 1 has to go to the end so 2 shifts earlier it had to be the shifted to the right most wouldbe 3,now it is 3-1
    so we adjust the position by 1 before returning the ans
*/
    cout << swaps << endl;
    return 0;
}
