#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;  
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        vector<int> round_numbers;
        int place_value = 1;  // Used to calculate the place value 

        while (n > 0) {
            int digit = n % 10; 
            if (digit != 0) {
                round_numbers.push_back(digit * place_value);
            }
            n /= 10; 
            place_value *= 10;  // Move to the next place value
        }

        
        cout << round_numbers.size() << endl;
        for (int num : round_numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
