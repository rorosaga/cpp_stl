#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
// #include <sciplot/sciplot.hpp>

namespace homework17{
    /**
     * @brief Read a book from a file and return a vector of characters
     * @param fileName The name of the file to read
     * @return A vector of characters
     */
    std::vector<char> readBook(std::string fileName);

    /**
     * @brief Compute the frequency of words in a book
     * @param book A vector of characters representing the book
     * @return A map with the frequency of each word
     */
    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book);

    /**
     * @brief Count the number of unique words in a book
     * @param book A vector of characters representing the book
     * @return The number of unique words
     */
    int countUniqueWords(const std::vector<char>& book);

    /**
     * @brief Sort the frequencies of words in a book
     * @param frequencies A map with the frequency of each word
     * @return A multimap with the frequencies sorted
     */
    std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies);

    /**
     * @brief Output the frequencies of words to a file
     * @param sortedFrequencies A multimap with the frequencies sorted
     * @param fileName The name of the file to write
     */
    void outputFrequenciesToFile(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies, const std::string& fileName);

    // /**
    //  * @brief Output the frequencies of words to a file in log-log scale
    //  * @param sortedFrequencies A multimap with the frequencies sorted
    //  */
    // void cppLogLogPlot(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies);

    /**
     * @brief Print the hapax legomena
     * @param sortedFrequencies A multimap with the frequencies sorted
     */
    void printHapaxLegomena(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies);
}

namespace homework19{

    /**
     * @brief Read a book from a file and return a vector of characters
     * @param fileName The name of the file to read
     * @return A vector of characters
     */
    std::vector<char> readBook(const std::string& fileName);

    /**
     * @brief Compute the frequency of words in a book
     * @param book A vector of characters representing the book
     * @return A vector of pairs with the frequency of each word
     */
    std::vector<std::pair<std::string, int>> computeWordFrequency(const std::vector<char>& book);

    /**
     * @brief Count the number of unique words in a book
     * @param book A vector of characters representing the book
     * @return The number of unique words
     */
    int countUniqueWords(const std::vector<char>& book);

    /**
     * @brief Sort the frequencies of words in a book
     * @param frequencies A vector of pairs with the frequency of each word
     */
    void sortFrequencies(std::vector<std::pair<std::string, int>>& frequencies);

    /**
     * @brief Output the frequencies of words to a file
     * @param frequencies A vector of pairs with the frequency of each word
     * @param fileName The name of the file to write
     */
    void outputFrequenciesToFile(const std::vector<std::pair<std::string, int>>& frequencies, const std::string& fileName);

    /**
     * @brief Print the hapax legomena
     * @param frequencies A vector of pairs with the frequency of each word
     */
    void printHapaxLegomena(const std::vector<std::pair<std::string, int>>& frequencies);
}