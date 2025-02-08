// what are the constraints on the value of index?
// Since it is 1e9 so we can't use array bcoz constructing an array of that bmuch size is not possible
// How to go from 1st min --> 2nd min --> 3rd min

class NumberContainers {
    unordered_map<int,int> changeMap;
    unordered_map<int,set<int>> findMap;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // inserting something new
       if(changeMap.find(index)==changeMap.end()){
        changeMap[index] = number;
        findMap[number].insert(index);
       }
       else{
        // replacing an already existing index
        int oldNum = changeMap[index];
        findMap[oldNum].erase(index);
        if(findMap[oldNum].size()==0)
        findMap.erase(oldNum);
        changeMap[index] = number;
        findMap[number].insert(index);
       }
    }
    
    int find(int number) {
        if(findMap.find(number)==findMap.end())
        return -1;
        return *findMap[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */