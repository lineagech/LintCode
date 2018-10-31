/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) {
        // write your code here
        unordered_map<UndirectedGraphNode*, bool> visited;
        queue<UndirectedGraphNode*> queue;
        int step = 0;
        if( s == NULL || t == NULL ) return -1;
        if( s == t ) return 0;
        for( auto node : graph )
        {
            visited[node] = false;
        }
        queue.push(s);
        
        while( !queue.empty() )
        {   
            int queue_size = queue.size();
            step++;
            for( int i = 0; i < queue_size ; i++ )
            {
                UndirectedGraphNode* source = queue.front();
                queue.pop();
                for( auto neighbor : source->neighbors )
                {
                    if( neighbor == t ) return step;
                    else 
                    {
                        if( !visited[neighbor] )
                        {
                            queue.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
