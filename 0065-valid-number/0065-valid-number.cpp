class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool exponentSeen = false;
        bool exponentDigitSeen = true;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digitSeen = true;

                if (exponentSeen)
                    exponentDigitSeen = true;
            }
            else if (c == '.') {

                if (dotSeen || exponentSeen)
                    return false;

                dotSeen = true;
            }
            else if (c == 'e' || c == 'E') {
                if (exponentSeen || !digitSeen)
                    return false;

                exponentSeen = true;
                exponentDigitSeen = false;
            }
            else if (c == '+' || c == '-') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }
        return digitSeen && exponentDigitSeen;
    }
};