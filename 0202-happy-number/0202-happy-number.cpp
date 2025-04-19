class Solution {
public:
    int findsq(int n) {
        int sq = 0;
        while(n > 0) {
            int digit = n % 10;
            sq += digit * digit;
            n /= 10;
        }
        return sq;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = findsq(n);

        while(fast != 1 && slow != fast) {
            slow = findsq(slow);
            fast = findsq(findsq(fast));
        }

        return fast == 1;
    }
};
