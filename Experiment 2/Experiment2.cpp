#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        return power(x, exp);
    }
private:
    double power(double base, long long exp) {
        if (exp == 0) return 1;
        if (exp == 1) return base;

        double half = power(base, exp / 2);
        if (exp % 2 == 0)
            return half * half;
        else
            return base * half * half;
    }
};
int main() {
    Solution sol;
    cout << sol.myPow(2, 10) << endl;   
    cout << sol.myPow(2, -2) << endl;   
    return 0;
}
