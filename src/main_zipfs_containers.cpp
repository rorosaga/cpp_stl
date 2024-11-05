#include "zipfs.h"

int main() {
    std::vector<char> text = homework17::readBook("pg2701.txt");
    std::map<std::string, int> freq = homework17::computeWordFrequency(text);
    int unique = homework17::countUniqueWords(text);
    std::multimap<int, std::string, std::greater<>> sorted = homework17::sortFrequencies(freq);
    homework17::outputFrequenciesToFile(sorted, "word_freqs.txt");
    // homework17::cppLogLogPlot(sorted);

    std::vector<char> text2 = homework17::readBook("principito.txt");
    std::map<std::string, int> freq2 = homework17::computeWordFrequency(text2);
    int unique2 = homework17::countUniqueWords(text2);
    std::multimap<int, std::string, std::greater<>> sorted2 = homework17::sortFrequencies(freq2);
    homework17::outputFrequenciesToFile(sorted2, "word_freqs2.txt");

    homework17::printHapaxLegomena(sorted);
    return 0;
}
