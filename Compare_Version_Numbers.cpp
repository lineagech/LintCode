class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream sv1(version1);
        stringstream sv2(version2);
        string l1, l2;
        while( true )
        {
            int int_v1 = 0, int_v2 = 0;
            if(sv1.peek() != EOF) {
                getline(sv1, l1, '.');
                stringstream t1(l1); 
                t1 >> int_v1;
            }
            if(sv2.peek() != EOF) {
                getline(sv2, l2, '.');  
                stringstream t2(l2); 
                t2 >> int_v2;
            }
            if( int_v1 > int_v2 ) return 1;
            else if( int_v1 < int_v2 ) return -1;
            if(sv1.peek() == EOF && sv2.peek() == EOF) return 0;
        }

        return 0;
    }
};
