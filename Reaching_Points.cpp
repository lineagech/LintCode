class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(true)
        {
            if( sx!=tx && sy!=ty && tx!=0 && ty!=0)
            {
                if(tx > ty) tx%=ty;
                else ty %= tx;
            }
            else if(sx == tx)
            {
                return ((ty-sy)>=0 && (ty-sy)%tx == 0);
            }
            else if(sy == ty)
            {
                return ((tx-sx)>=0 && (tx-sx)%ty == 0);
            }
            else
            {
                return (sx==tx && sy==ty);
            }
        }
    }
};
