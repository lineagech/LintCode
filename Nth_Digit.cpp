/*
        0-9: 9
        10-99: 90*2
        100-999: 900*3
        1000-9999: 9000*4
        10000-99999: 90000*5
        ...
        10^n - 10^(n+1) - 1
        */
        int num_len = 1;
        int count = 9;
        int base = 1;
        while(n > (long long)num_len*(long long)count)
        {
            n -= num_len*count;
            num_len++;
            count *= 10;
            base *= 10;
        }
        long long num = (n-1) / num_len;
        string str_num = to_string( base + num );
        cout << count << endl;
        return (str_num[ (n-1) % num_len ]-'0');
