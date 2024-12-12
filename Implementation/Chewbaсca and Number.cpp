#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;  // Read the input as a string
    
    // Loop through each character of the string
    for (int i = 0; i < x.size(); i++) {
        int digit = x[i] - '0';  // Convert character to integer
        
        // Invert the digit only if it results in a smaller number
        if (i == 0 && digit == 9) {
            continue;  // Do not invert the first digit if it's 9
        }
        
        // Otherwise, choose the smaller between the digit and its inverted value
        if (digit > 4) {
            x[i] = '9' - digit;  // Invert the digit
        }
    }
    
    cout << x << endl;  // Output the result
    return 0;
}
