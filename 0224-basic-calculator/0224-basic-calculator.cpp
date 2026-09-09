class Solution {
public:
    int calculate(string s) {
        long long result = 0;
        long long num = 0;
        int sign = 1;

        stack<long long> st;

        for (int i = 0; i < s.length(); i++) {

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if (s[i] == '+' || s[i] == '-') {
                result += sign * num;
                num = 0;

                sign = (s[i] == '+') ? 1 : -1;
            }

            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (s[i] == ')') {
                result += sign * num;
                num = 0;

                int prevSign = st.top();
                st.pop();
                long long prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }

        result += sign * num;

        return result;
    }
};