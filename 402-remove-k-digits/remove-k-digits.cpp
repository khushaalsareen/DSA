class Solution {
public:
   string removeKdigits(string num, int k) {
    stack<char> s;

    // Build the number using a greedy approach
    for (int i = 0; i < num.size(); i++) {
        while (!s.empty() && k > 0 && s.top() > num[i]) {
            s.pop();
            k--;
        }
        s.push(num[i]);
    }

    // If k is still greater than 0, remove from the end of the stack
    while (!s.empty() && k > 0) {
        s.pop();
        k--;
    }

    // Build the resulting string
    string ans = "";
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    // Reverse to get the correct order
    reverse(ans.begin(), ans.end());

    // Remove leading zeros
    int i = 0;
    while (i < ans.size() && ans[i] == '0') {
        i++;
    }

    // If the result is empty or only contains zeros, return "0"
    ans = ans.substr(i);
    return ans.empty() ? "0" : ans;
}
};