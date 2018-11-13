/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */
class Solution {
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    struct setEqual{
        bool operator() (const Connection& key1, const Connection& key2) const 
        {
            return key1.city1==key2.city1 && key1.city2==key2.city2 && key1.cost==key2.cost;
        }
    }; 
     
    struct setHash{
        size_t operator() (const Connection& key) const 
        {
            auto h1 = hash<string>{}(key.city1);
            auto h2 = hash<string>{}(key.city2);
            auto h3 = hash<int>{}(key.cost);
            return h1^h2^h3;
        }
    }; 
     
    vector<Connection> lowestCost(vector<Connection>& connections) {
        /* Kruscal Algorithm */
        vector<Connection> ans;
        sort(connections.begin(), connections.end(), 
        [](Connection& a, Connection& b){
            if( a.cost != b.cost ) return a.cost < b.cost;
            if( a.city1 != b.city1 ) return a.city1 < b.city1;
            return a.city2 < b.city2;
        });
        for( auto connection : connections )
        {
            if( !root.count(connection.city1) ) {
                root[connection.city1] = connection.city1;
                connected_size++;
            }
            if( !root.count(connection.city2) ) {
                connected_size++;
                root[connection.city2] = connection.city2;
            }
        }
        for( auto const& connection : connections )
        {
            string root_city1 = find_root(connection.city1);
            string root_city2 = find_root(connection.city2);
            if( root_city1 != root_city2 )
            {
                //mst.insert(connection);
                connected_size--;
                ans.push_back(connection);
                root[root_city1] = root_city2;
            }
        }
        //vector<Connection> ans(mst.begin(),mst.end());
        return (connected_size == 1) ? ans : vector<Connection>();
    }
    
    string find_root(string node)
    {   
        string res;
        if( root[node] == node ) return node;
        else res = find_root(root[node]);
        return res;
    }
    
    int connected_size = 0;
    unordered_map<string,string> root;
    unordered_set<Connection, setHash, setEqual> mst;
};
