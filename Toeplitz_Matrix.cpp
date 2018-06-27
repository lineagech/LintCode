// Write your code here
    	int m = matrix.size();
    	if( m == 0 ) return false;
    	int n = matrix[0].size();
    	if( n == 0 ) return false;
    	
    	int dx = 1;
    	int dy = 1;
    	/* the first column */
    	for( int i = 0; i < m; i++ )
    	{
    		int start_x = i, start_y = 0;
    		while( start_x+dx < m && start_y+dy < n )
    		{
    			if( matrix[start_x+dx][start_y+dy] != matrix[start_x][start_y] )
    				return false;
    			start_x = start_x + dx;
    			start_y = start_y + dy;
    		}
    	}
    	/* the first row */
    	for( int i = 0; i < n; i++ )
    	{
    		int start_x = 0, start_y = i;
    		while( start_x+dx < m && start_y+dy < n )
    		{
    			if( matrix[start_x+dx][start_y+dy] != matrix[start_x][start_y] )
    				return false;
    			start_x = start_x + dx;
    			start_y = start_y + dy;
    		}
    	}
    	return true;
