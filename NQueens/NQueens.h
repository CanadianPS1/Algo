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

        Time : O(n factorial)
        Size : O(n factorial)
*/
#include <vector>
#include <cstdint>
#include <cmath>
class NQueens{
    public:
    std::vector<std::vector<uint8_t>> solutions;
    void FindQueen(uint8_t n, uint8_t y, std::vector<uint8_t> solution){
        if(y >= n){
            solutions.push_back(solution);
            return;
        }
        for(uint8_t i = 0; i < n; i++){
            if(IsSafeHere(i, y, solution)){
                solution[y] = i;
                FindQueen(n, y + 1, solution);
            }else continue;
        }
    }
    bool IsSafeHere(uint8_t x, uint8_t y, std::vector<uint8_t> solution){
        for(uint8_t i = 0; i < y; i++){
            if(solution[i] == x) return false;
            if(abs(i - y) == abs(solution[i] - x)) return false;
        }
        return true;
    }
    std::vector<std::vector<uint8_t>> GetAllSolutions(){return solutions;}
    std::vector<uint8_t> GetNSolution(int n){return solutions[n];}
    int GetAmountOfSolutions(){return solutions.size();}
};