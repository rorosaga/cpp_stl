#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

namespace homework{

    std::vector<char> readBook(std::string fileName){
        std::vector<char> result;
        std::ifstream file(fileName);

        char c;

        while(file.get(c)) {
            if (std::isalpha(c)){
                result.push_back(c);
            } else {
                result.push_back(' ');
            }
        }

        return result;
    }
}

int main() {
    std::vector<char> text = homework::readBook("pg2701.txt");
    for (auto& word: text){
        std::cout<<word;
    }
    return 0;
}