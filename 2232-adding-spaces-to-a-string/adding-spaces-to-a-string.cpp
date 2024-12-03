class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
    string ans;
    ans.reserve(s.size() + spaces.size()); // Pre-allocate memory
    int i = 0; // Index in the string
    for (int space : spaces) {
        ans.append(s.substr(i, space - i)); // Append substring before space
        ans.push_back(' '); // Add space
        i = space; // Update starting index
    }
    ans.append(s.substr(i)); // Append remaining part of the string
    return ans;
}

};