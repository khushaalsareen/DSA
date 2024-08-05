class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int m = words[0].size();  // Length of each word (assuming all words are of the same length)
        int n = words.size();     // Number of words in the list
        int tl = m * n;           // Total length of concatenated words (length of the substring we are looking for)

        unordered_map<string, int> mp1; // Map to store the count of each word in the `words` list
        vector<int> ans;                // Vector to store the starting indices of valid substrings

        // Populate the map with the frequency of each word in the `words` list
        for (auto word : words) {
            mp1[word]++;
        }

        // If the total length of words is greater than the length of `s`, return empty result
        if (tl > s.size()) {
            return ans;
        }

        // Iterate over each possible starting point within the first `m` characters of `s`
        for (int i = 0; i < m; i++) {

            unordered_map<string, int> mp2; // Map to track words seen in the current sliding window
            int left = i;                   // Left pointer for the sliding window

            // Iterate over the string `s` in steps of `m` characters
            for (int j = i; j <= s.size() - m; j += m) {
                string temp = s.substr(j, m); // Extract a substring of length `m` from `s`

                // Check if the extracted substring is a valid word from the list
                if (mp1.find(temp) != mp1.end()) {
                    mp2[temp]++; // Increment the count of the current word in the sliding window

                    // If the current word count exceeds the expected count, adjust the left pointer
                    while (mp2[temp] > mp1[temp]) {
                        mp2[s.substr(left, m)]--; // Remove the leftmost word from the sliding window
                        left += m;                // Move the left pointer to the right
                    }

                    // Check if the current window length matches the total length of concatenated words
                    if (j - left + m == tl) {
                        ans.push_back(left);     // Add the starting index to the result
                        mp2[s.substr(left, m)]--; // Remove the leftmost word as we move the window
                        left += m;               // Move the left pointer to the right
                    }
                } else {
                    // If the word is not in the list, reset the window and move left pointer
                    mp2.clear(); // Clear the sliding window map
                    left = j + m; // Move the left pointer to the next possible start
                }
            }
        }
        
        return ans; // Return the list of starting indices of valid substrings
    }
};