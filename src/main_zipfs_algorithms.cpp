#include "zipfs.h"
#include <algorithm>

namespace homework19 {

    std::vector<char> readBook(const std::string& fileName) {
        std::vector<char> result;
        std::ifstream file(fileName);

        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return result;
        }

        char c;
        
        while (file.get(c)) {
            if (std::isalpha(c) || std::isspace(c)) {
                result.push_back(c);
            } else {
                result.push_back(' ');
            }
        }

        return result;
    }

    std::vector<std::pair<std::string, int>> computeWordFrequency(const std::vector<char>& book) {
        std::string book_data(book.begin(), book.end());
        std::stringstream ss(book_data);
        std::string word;

        std::vector<std::pair<std::string, int>> frequencies;

        while (ss >> word) {
            auto it = std::find_if(frequencies.begin(), frequencies.end(),
            [&word](const auto& pair) { return pair.first == word; });
            if (it != frequencies.end()) {
                it->second++;
            } else {
                frequencies.emplace_back(word, 1); 
            }
        }

        return frequencies;
    }

    int countUniqueWords(const std::vector<char>& book) {
        std::string book_data(book.begin(), book.end());
        std::stringstream ss(book_data);
        std::string word;

        std::vector<std::string> uniqueWords;

        while (ss >> word) {
            if (std::find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) {
                uniqueWords.push_back(word);
            }
        }

        return uniqueWords.size();
    }

    void sortFrequencies(std::vector<std::pair<std::string, int>>& frequencies) {
        std::sort(frequencies.begin(), frequencies.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });
    }

    void outputFrequenciesToFile(const std::vector<std::pair<std::string, int>>& frequencies, const std::string& fileName) {
        std::ofstream outputFile(fileName);

        if (!outputFile.is_open()) {
            std::cerr << "Error opening output file" << std::endl;
            return;
        }

        int rank = 1;
        for (const auto& [word, frequency] : frequencies) {
            outputFile << rank << " " << frequency << " " << word << std::endl;
            rank++;
        }
    }

    void printHapaxLegomena(const std::vector<std::pair<std::string, int>>& frequencies) {
        std::vector<std::string> hapaxLegomena;

        for (const auto& entry : frequencies) {
            if (entry.second == 1) {
                hapaxLegomena.push_back(entry.first);
                // std::cout << entry.first << std::endl;
            }
        }
    }
}

int main() {
    std::vector<char> text = homework19::readBook("pg2701.txt");
    auto freq = homework19::computeWordFrequency(text);
    int unique = homework19::countUniqueWords(text);
    homework19::sortFrequencies(freq);
    homework19::outputFrequenciesToFile(freq, "word_freqs_algo.txt");

    std::vector<char> text2 = homework19::readBook("principito.txt");
    auto freq2 = homework19::computeWordFrequency(text2);
    int unique2 = homework19::countUniqueWords(text2);
    homework19::sortFrequencies(freq2);
    homework19::outputFrequenciesToFile(freq2, "word_freqs2_algo.txt");

    homework19::printHapaxLegomena(freq);
    return 0;
}
