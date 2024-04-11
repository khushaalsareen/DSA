class Solution {
public:
   string removeKdigits(string num, int k) {
    stack<char> s;
    int i;
    for (i = 0; i < num.size(); i++) {
        while (!s.empty() && num[i] < s.top() && k > 0) {
            s.pop();
            k--;
        }
        s.push(num[i]);
    }
    // Handle the case when k is greater than the size of num
    while (k > 0 && !s.empty()) {
        s.pop();
        k--;
    }
    string ans = "";
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    // Remove leading zeros
    int j = 0;
    while (j < ans.size() && ans[j] == '0') {
        j++;
    }
    ans = (j == ans.size()) ? "0" : ans.substr(j);
    return ans;
}
};