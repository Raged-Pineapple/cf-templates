#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int i, j;
    int matrix[5][5];
    
    // Loop through the matrix using 0-indexing
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 1) {
                // We found the position of 1, no need to continue scanning
                break;
            }
        }
        if(matrix[i][j] == 1) {
            break;  // Found '1', exit outer loop
        }
    }
    
    // The target position is (2, 2) (3rd row, 3rd column in 0-indexed terms)
    int sum = abs(i - 2) + abs(j - 2);
    
    cout << sum << endl;
    
    return 0;
}
