class Solution {
public:
    /**
     * @param accounts: List[List[str]]
     * @return: return a List[List[str]]
     */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // write your code here
        unordered_map<string,string> root;
        unordered_map<string,string> hash; //root, name
        vector<vector<string>> ans;
        for( auto account : accounts )
        {
            string name = account[0];
            string root_account = account[1];
            bool merge = false;
            // determine there is a existing account that has the same email
            for( int i=1; i<account.size(); i++ )
            {
                if( root.count(account[i]) ) {
                    root_account = getRoot(account[i], root);
                    merge = true;
                    break;
                }
            }
            // then merge or create a new group
            for( int i=1; i<account.size(); i++ )
            {   
                string old_root = (root.count(account[i])) ? getRoot(account[i], root) : account[i];
                root[old_root] = root_account;
                if(old_root != root_account) hash.erase(old_root);
            }
            if( !merge ) {
                hash[root_account] = name;
            }

        }
        for( auto it : hash )
        {
            string name = it.second;
            string root_account = it.first;
            ans.push_back({name});
            for( auto it2 : root ) 
            {
                if( getRoot(it2.second,root) == root_account ) {
                    ans.back().push_back(it2.first);
                }     
            }
            sort(ans.back().begin()+1, ans.back().end());
        }
        return ans;
    }
    string getRoot( string node, unordered_map<string,string>& root )
    {
        while( root[node] != node ) 
            node = root[node];
        return node;
    }
    
};
