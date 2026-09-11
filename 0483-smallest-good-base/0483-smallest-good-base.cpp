class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);

        for (int digits = 60; digits >= 2; digits--) {
            long long base = pow(num, 1.0 / (digits - 1));

            for (long long k = max(2LL, base - 1); k <= base + 1; k++) {

                long long sum = 1;
                long long power = 1;
                bool valid = true;

                for (int i = 1; i < digits; i++) {
                    if (power > (num - 1) / k) {
                        valid = false;
                        break;
                    }
                    power *= k;
                    if (sum > num - power) {
                        valid = false;
                        break;
                    }

                    sum += power;
                }
                if (valid && sum == num) {
                    return to_string(k);
                }
            }
        }
        return to_string(num - 1);
    }
};