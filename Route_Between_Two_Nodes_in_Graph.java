/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) {
 *         label = x;
 *         neighbors = new ArrayList<DirectedGraphNode>();
 *     }
 * };
 */


public class Solution {
    /*
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    public boolean hasRoute(ArrayList<DirectedGraphNode> graph, DirectedGraphNode s, DirectedGraphNode t) {
        // write your code here
        Queue<DirectedGraphNode> queue = new LinkedList<DirectedGraphNode>();
        HashMap<Integer, Boolean> visited = new HashMap<Integer, Boolean>();
        for( DirectedGraphNode node : graph )
        {
            visited.put(node.label, false);
        }
        if( s.label == t.label ) return true;
         
        queue.offer(s);
        visited.put(s.label, true);
        
        while( !queue.isEmpty() )
        {
            int queue_size = queue.size();
            for( int i = 0; i < queue_size; i++ )
            {
                DirectedGraphNode curr = queue.poll();
                for( DirectedGraphNode next : curr.neighbors )
                {   
                    if( next.label == t.label ) return true; 
                    if( visited.get(next.label) == false )
                    {
                        queue.offer(next);
                        visited.put(next.label, true);
                    }
                }
            }
        }
        
        return false;
    }

}
