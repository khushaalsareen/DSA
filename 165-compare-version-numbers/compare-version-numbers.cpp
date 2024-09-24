class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>v1,v2;
        int i = 0;
        while(i<version1.size()){
            string temp="";
            int j = i;
            while( j<version1.size() && version1[j]!='.'){
                temp.push_back(version1[j]);
                j++;
            }
            v1.push_back(temp);
            i = j+1;
        }
        i = 0;
         while(i<version2.size()){
            string temp="";
            int j = i;
            while( j<version2.size() && version2[j]!='.'){
                temp.push_back(version2[j]);
                j++;
            }
            v2.push_back(temp);
            i = j+1;
        }
        int len1 = v1.size();
        int len2 = v2.size();
        if(len1>len2){
            while(len1!=len2){
                v2.push_back("0");
                len2++;
            }
        }
        else if(len1<len2){
            while(len1!=len2){
                v1.push_back("0");
                len1++;
            }
        }
        i = 0; 
        while(i<v1.size()){
            if(stoi(v1[i])>stoi(v2[i]))
            return 1;
            else if(stoi(v1[i])<stoi(v2[i]))
            return -1;
            else
            i++;
        }
        return 0;
    }
};