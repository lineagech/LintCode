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
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here
        if( node == NULL ) return NULL;
        UndirectedGraphNode* clone_node = new UndirectedGraphNode(node->label);
        hash[node->label] = clone_node;
        helper(node, clone_node);
        return clone_node;
    }
    
    void helper(UndirectedGraphNode* node, UndirectedGraphNode* clone_node)
    {
        for( auto neighbor : node->neighbors )
        {   
            UndirectedGraphNode* clone_neighbor;
            if( hash.find( neighbor->label ) == hash.end() ) {
                clone_neighbor = new UndirectedGraphNode(neighbor->label);
                clone_node->neighbors.push_back(clone_neighbor);
                hash[neighbor->label] = clone_neighbor;
                helper(neighbor, clone_neighbor);
            }
            else {
                clone_neighbor = (hash.find(neighbor->label))->second;
                clone_node->neighbors.push_back(clone_neighbor);
            }
        }
    }
    
    unordered_map<int,UndirectedGraphNode*> hash;
};
