class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int tot = 0;
        queue<int>q;
        unordered_set<int>s;
        s.insert(0);
        q.push(0);
        vector<int>directions = {x,-x,y,-y};
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == target)
            return true;
            for(int i = 0;i<4;i++){
                int newTot = node + directions[i];
                if(newTot>=0 && newTot<=x+y && s.find(newTot)==s.end()){
                    s.insert(newTot);
                    q.push(newTot);
                }
            }
        }
        return false;
    }
};