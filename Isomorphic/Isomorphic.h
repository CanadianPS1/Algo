#include <iostream>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <string>
#include <vector>
class Isomorphic{
    public:
    /*
        Loop through all letters
            Loop through all letters in the array
                if the current letter is inside the vector break
                push up an incromenter
            if the current letter was in the array then we add the incromenter to our string
            if it wasnt in the array then we add it in and add the incromenter to the string
            push up index and reset incromenter
        return the string

        Time O(n^2) double loop
        Space O(n^2) i think this is n^2 but im extremly unsure about it
    */
    std::string GetExactPattern(std::string word){
        std::vector<char> letters;
        std::vector<int> indexes;
        std::string order = "";
        std::string answer;
        int count = 0;
        int index = 0;
        for(char letter : word){
            bool letterInVector = false;
            for(char i : letters){
                if(i == letter){
                    letterInVector = true;
                    break;
                }
                count++;
            }
            if(!letterInVector){
                letters.push_back(letter);
                if(index != 0) answer += " ";
                answer += std::to_string(count);
            }else{
                if(index != 0) answer += " ";
                answer += std::to_string(count);
            }
            index++;
            count = 0;
            
        }
        return answer;
    }
    /*
        loop through each char in the word
            if the current char isnt inside the map
                add it in with the value of 1 and add  thast letter into the letter order
            if it is in the map
                increse the value of that chars amounts
                erase that letter from the order
                add that letter back into the order (this would put it at the end)
        loop through each letter in the order
            if it isnt the first iteration then we put a space after the last letter
            concatinate that letters number into our answer
            push the incromenter
        return our answer

        Time O(n)
        Memory O(n^2)
    */
    std::string GetLoosePattern(std::string word){
        std::unordered_map<char, int> isomorphs;
        std::string order = "";
        std::string answer;
        int count = 0;
        for(char letter : word){
            if(isomorphs.find(letter) == isomorphs.end()){
                isomorphs.insert({letter, 1});
                order += letter;
            }else{
                isomorphs[letter] = isomorphs[letter] + 1;
                order.erase(std::remove(order.begin(), order.end(), letter), order.end());
                order += letter;
            }
        }
        for(char letter : order){
            if(count != 0) answer += " ";
            answer += std::to_string(isomorphs[letter]);
            count++;
        }
        return answer;
    }
    /*
        loop through all the words in the array
            grab the exact patern for the current word
            if that words patern matches another then we add that word to the patern
            if it didnt then we add the patern and the word into the map
        return the map

        Time O(n^3)
        Space O(n^3)
    */
    std::unordered_map<std::string, std::string> FindExactIsomorphs(std::vector<std::string> words){
        std::unordered_map<std::string, std::string> isomorphs;
        for(std::string word : words){
            std::string looseIsomorph = GetExactPattern(word);
            if(isomorphs.find(looseIsomorph) != isomorphs.end()) isomorphs[looseIsomorph] = isomorphs[looseIsomorph] + " " + word;
            else isomorphs.insert({looseIsomorph, word});
        }
        return isomorphs;
    }
    /*
        loop through all the words in the array
            grab the loose patern for the current word
            if that words patern matches another then we add that word to the patern
            if it didnt then we add the patern and the word into the map
        return the map

        Time O(n^2)
        Space O(n^2)
    */
    std::unordered_map<std::string, std::string> FindLooseIsomorphs(std::vector<std::string> words){
        std::unordered_map<std::string, std::string> isomorphs;
        for(std::string word : words){
            std::string looseIsomorph = GetLoosePattern(word);
            if(isomorphs.find(looseIsomorph) != isomorphs.end()) isomorphs[looseIsomorph] = isomorphs[looseIsomorph] + " " + word;
            else isomorphs.insert({looseIsomorph, word});
        }
        return isomorphs;
    }
};