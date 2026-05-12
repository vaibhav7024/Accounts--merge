class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        map<string,string>parent;
        map<string,string>owner;
        map<string,set<string>> unions;

        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                parent[acc[i][j]]=acc[i][j];
                owner[acc[i][j]]=acc[i][0];
            }
        }
        for(int i=0;i<n;i++){
            string p=find(acc[i][1],parent);
            for( int j=2;j<acc[i].size();j++){
                parent[find(acc[i][j],parent)]=p;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                unions[find(acc[i][j],parent)].insert(acc[i][j]);
            }
        }
        vector<vector<string>> res;
        for(auto p: unions){
            vector<string> emails(p.second.begin(),p.second.end());
            emails.insert(emails.begin(),owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
    string find(string& s, map<string,string>& p){
        if(p[s]==s) return s;
        return p[s]=find(p[s],p);
    }
};
