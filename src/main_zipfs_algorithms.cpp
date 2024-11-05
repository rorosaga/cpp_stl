#include "zipfs.h"
#include <algorithm>

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
