#include <iostream>
#include <unordered_map>
#include <array>
class Isomorphic{
    public:
    std::string GetExactPattern(std::string word){
        return "";
    }
    std::string GetLoosePattern(std::string word){
        std::unordered_map<char, int> isomorphs;
        for(char letter : word){
            if(isomorphs.find(letter) == isomorphs.end()) isomorphs.insert({letter, 1});
            else isomorphs[letter] = isomorphs.at(letter)++;
        }
        return "";
    }
    std::unordered_map<std::string, std::string> FindExactIsomorphs(std::string words[]){
        std::unordered_map<std::string, std::string> isomorphs;
        return isomorphs;
    }
    std::unordered_map<std::string, std::string> FindLooseIsomorphs(std::string words[]){
        std::unordered_map<std::string, std::string> isomorphs;
        return isomorphs;
    }
};