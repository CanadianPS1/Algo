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
        Global Array size n type packed int 5 bits
        void Method(int amount of solutions, int y)
            array solution size n type packed int 5 bits
            for i; i < n; i++
                if IsSafeHere(i, y)
                    pack the int into 5 bits
                    array at i = packed int
                    Method(n, y+ 1)
                else
                    Array at i = null
                    return
        bool IsSafeHere(int x, int y)
            for each array
                if array[i] = x or y 
                    return false
                else if
                else if
                else return true    
        GetAllSolutions return solutions
        GetAmountOfSolutions return Array
*/
#include <vector>
#include <array>
class NQueens{
    public:
    struct PackedVector{
        std::vector<int> vector;
    };

    PackedVector packedVector;
    void Sort(int n, int y){
        if(y >= n) return;
        for(int i = 0; i < n; i++){
            if(IsSafeHere(i,y)){
                //TODO make it
            }else{
                //TODO make the array stuff
                return;
            }
        }
    }
    bool IsSafeHere(int x, int y){
        return true;
    }
    std::vector<int> GetAllSolutions(){return packedVector.vector;}
    int GetAmountOfSolutions(){return packedVector.vector.size();}
};