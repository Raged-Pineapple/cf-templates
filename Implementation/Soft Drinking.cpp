/*Overall the friends have 4 * 5 = 20 milliliters of the drink, it is enough to make 20 / 3 = 6 toasts.
  The limes are enough for 10 * 8 = 80 toasts and the salt is enough for 100 / 1 = 100 toasts.
  However, there are 3 friends in the group, so the answer is min(6, 80, 100) / 3 = 2.*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drink = k * l;               // Total milliliters of drink
    int lime = c * d;                // Total slices of lime
    int salt = p;                    // Total grams of salt

    int availDrink = drink / nl;     // Toasts possible with drink
    int availLime = lime;            // Toasts possible with limes
    int availSalt = salt / np;       // Toasts possible with salt

    // Find the minimum among the available toasts and divide by the number of friends
    int toast = min(availDrink,min(availLime, availSalt));
    cout << toast/n << endl;
    return 0;
}
