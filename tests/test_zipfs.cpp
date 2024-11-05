#include "zipfs.h"
#include "gtest/gtest.h"


// Test for computing word frequency
TEST(ZipfsLawTests, ComputeWordFrequency) {
    std::vector<char> book = homework17::readBook("test.txt");

    std::map<std::string, int> freq = homework17::computeWordFrequency(book);
    EXPECT_EQ(freq["hello"], 3);
    EXPECT_EQ(freq["bye"], 2);
    EXPECT_EQ(freq["this"], 1);
    EXPECT_EQ(freq["is"], 1);
}

// // Test for counting unique words
// TEST(ZipfsLawTests, CountUniqueWords) {
//     std::vector<char> book = homework17::readBook("test.txt");
//     int uniqueWords = homework17::countUniqueWords(book);
//     EXPECT_EQ(uniqueWords, 7); // Unique words count
// }

// Test for sorting frequencies
TEST(ZipfsLawTests, SortFrequencies) {
    std::vector<char> book = homework17::readBook("test.txt");
    std::map<std::string, int> freq = homework17::computeWordFrequency(book);
    std::multimap<int, std::string, std::greater<>> sortedFreq = homework17::sortFrequencies(freq);

    auto it = sortedFreq.begin();
    EXPECT_EQ(it->first, 3);
    EXPECT_EQ(it->second, "hello");
    ++it;
    EXPECT_EQ(it->first, 2);
    EXPECT_EQ(it->second, "bye");
}

// // Test for hapax legomena
// TEST(ZipfsLawTests, PrintHapaxLegomena) {
//     std::vector<char> book = homework17::readBook("test.txt");
//     std::map<std::string, int> freq = homework17::computeWordFrequency(book);
//     std::multimap<int, std::string, std::greater<>> sortedFreq = homework17::sortFrequencies(freq);
//     testing::internal::CaptureStdout();
//     homework17::printHapaxLegomena(sortedFreq);
//     std::string output = testing::internal::GetCapturedStdout();

//     EXPECT_NE(output.find("Number of hapax legomena:"), std::string::npos);
//     EXPECT_NE(output.find("a"), std::string::npos);
//     EXPECT_NE(output.find("and"), std::string::npos);
//     EXPECT_NE(output.find("is"), std::string::npos);
// }
