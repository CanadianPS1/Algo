/*
            STORING THE ANSWERS
        
        vector of
            array of int : 5 bits size n
                5 bit integer
        
        so each index of the vector is a solution
        each row of the array is an X value

        you get the cordnits of each piece by grabing the index and the value at the index
        so the Y is the index and the X is the value at the index

        i can do this by bit packing with structs, if i only let each int have a size of 5 bits i belive i can store from 
        0-31 but my computer could technicly only do up to 19 because i have 62 gigs of ram and it would take around 60


            Finding the answers
        
        Global Vector, solutions type of a struct packed array
        void Method(int amount of solutions, int y)
            array solution size n type packed int 5 bits
            for i; i < n; i++
                if IsSafeHere(i, y)
                    pack the int into 5 bits

                    Method(n, y+ 1)
                else return
        bool IsSafeHere(int x, int y)

*/