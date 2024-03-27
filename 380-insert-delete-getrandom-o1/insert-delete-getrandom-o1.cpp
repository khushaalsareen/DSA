class RandomizedSet {
        unordered_map<int,int>m;
        vector<int>v;
public:
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
        return false;

        v.push_back(val);
        int idx = v.size() - 1;
        m[val] = idx;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end())
        return false;

        int idx = m[val];
        m.erase(val);
        if(idx == v.size()-1)
        v.pop_back();
        else{
            swap(v[idx],v[v.size()-1]);
            m[v[idx]] = idx;
            v.pop_back();
        }
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */