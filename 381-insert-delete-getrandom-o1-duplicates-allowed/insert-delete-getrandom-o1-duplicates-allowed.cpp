class RandomizedCollection {
public:
        unordered_map<int,vector<int>>m;
        vector<pair<int,int>>v;
    RandomizedCollection() {
       
    }
    
    bool insert(int val) {
      bool flag = false;
      if(m.find(val)==m.end())
         flag = true;

      int size = 0;
      if(flag==false){
        auto it = m.find(val);
        size = it->second.size();
      }
      v.push_back({val,size});
      int idx = v.size() - 1;
      m[val].push_back(idx);

      return flag;
    }
    
   bool remove(int val) {
    if (m.find(val) == m.end())
        return false;

    int idx = m[val].back();  // Get the index of the element to be removed
    m[val].pop_back();  // Remove the index from the map
    if (m[val].empty())
        m.erase(val);  // If there are no more occurrences of val, remove it from the map

    // Swap the element to be deleted with the last element in v
    int last_idx = v.size() - 1;
    if(idx==last_idx){
        v.pop_back();
        return true;
    }
    pair<int, int>& p1 = v[idx];  // Element to be removed
    pair<int, int>& p2 = v.back();  // Last element in v

    // Update the index of the last element in the map to point to its new position
    m[p2.first][p2.second] = idx;

    // Swap the elements
    swap(v[idx], v[last_idx]);
    v.pop_back();  // Remove the last element from v

    return true;
}

    
    int getRandom() {
        return v[rand()%v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */