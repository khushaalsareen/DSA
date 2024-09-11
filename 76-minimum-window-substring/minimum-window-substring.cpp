class Solution {
public:
   string minWindow(string s, string t) {
    int m = s.size();
    int n = t.size();

    if (n > m) return ""; // If t is longer than s, no solution possible

    unordered_map<char, int> freq, map;
    // Populate freq map with characters from t
    for (auto ch : t) {
        freq[ch]++;
    }

    int cnt = 0; // Number of characters matched
    int minLen = 1e9; // Length of the minimum window
    int start = 0; // Start index of the result window
    int i = 0, j = 0; // Two pointers for sliding window

    while (j < m) {
        char ch = s[j];
        map[ch]++;

        // If the current character is in t and we have enough of it in the window
        if (freq.find(ch) != freq.end() && map[ch] <= freq[ch]) {
            cnt++;
        }

        // When all characters are matched, try to minimize the window
        while (cnt == n) {
            if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
            }

            char chLeft = s[i];
            map[chLeft]--;

            // If a character from t is removed and it's less than required in the window
            if (freq.find(chLeft) != freq.end() && map[chLeft] < freq[chLeft]) {
                cnt--;
            }

            i++; // Shrink the window from the left
        }

        j++; // Expand the window from the right
    }

    return minLen == 1e9 ? "" : s.substr(start, minLen);
}

};