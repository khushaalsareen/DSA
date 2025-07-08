
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());
        // Min-heap for event end days
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int res = 0, n = events.size(), i = 0;
        // Find the last possible day
        int lastDay = 0;
        for (auto& e : events) lastDay = max(lastDay, e[1]);
        // Go through each day
        for (int day = 1; day <= lastDay; ++day) {
            // Add all events starting today
            while (i < n && events[i][0] == day)
                minHeap.push(events[i++][1]);
            // Remove events that have already ended
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();
            // Attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                res++;
            }
        }
        return res;
    }
};
