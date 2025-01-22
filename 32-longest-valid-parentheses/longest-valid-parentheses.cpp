class Solution {
public:
    int longestValidParentheses(string s) {
    int left = 0, right = 0, maxLength = 0;

    // Left-to-right pass
    for (char c : s) {
        if (c == '(') left++;
        else right++;
        if (left == right) maxLength = max(maxLength, 2 * right);
        else if (right > left) left = right = 0;
    }

    // Right-to-left pass
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') left++;
        else right++;
        if (left == right) maxLength = max(maxLength, 2 * left);
        else if (left > right) left = right = 0;
    }

    return maxLength;
}

};