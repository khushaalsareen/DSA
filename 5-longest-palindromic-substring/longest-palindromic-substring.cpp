class Solution {
public:
    int findLength(string &nums1, string &nums2, int &ansI, int &ansJ) {
    int s1 = nums1.size();
    int s2 = nums2.size();
    int ans = 0;

    vector<int> prev(s2 + 1, 0);
    vector<int> curr(s2 + 1, 0);

    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                curr[j] = 1 + prev[j - 1]; // f(i-1,j-1,nums1,nums2);
            } else {
                curr[j] = 0;
            }

            // Update the answer and check if the indices match the palindromic condition
            if (curr[j] > ans) {
                int startInOriginal = i - curr[j];
                int startInReversed = s2 - j; // Corresponding index in the reversed string

                // Only update if it's a valid palindrome
                if (startInOriginal == startInReversed) {
                    ansI = i;
                    ansJ = j;
                    ans = curr[j];
                }
            }
        }
        prev = curr;
    }

    return ans;
}

string longestPalindrome(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    int ansI = -1, ansJ = -1;
    int len = findLength(s, reversed, ansI, ansJ);

    // Extract the substring
    return s.substr(ansI - len, len);
}

};