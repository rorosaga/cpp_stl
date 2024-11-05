#include"zipfs.h"

namespace homework17{

    std::vector<char> readBook(std::string fileName){
        std::vector<char> result;
        std::ifstream file(fileName);

        if (!file.is_open()){
            std::cerr<<"Error opening file"<<std::endl;
            return result;
        };

        char c;

        while(file.get(c)) {
            if (std::isalpha(c) || std::isspace(c)){
                result.push_back(c);
            } else {
                result.push_back(' ');
            }
        }

        return result;
    }

    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book){
        std::map<std::string, int> result;
        std::string book_data(book.begin(), book.end());
        std::stringstream ss(book_data);
        std::string word;

        for (int i = 0; ss >> word; i++){
            result[word]++;
        }

        // checking the output
        // for (auto& word: result){
        //     std::cout<<word.first<<" -- "<<word.second<<std::endl;
        // }

        return result;
    }

    int countUniqueWords(const std::vector<char>& book){
        std::set<std::string> result;
        std::string book_data(book.begin(), book.end());
        std::stringstream ss(book_data);
        std::string word;

        for (int i = 0; ss >> word; i++){
            result.insert(word);
        }

        // checking the output
        // std::cout<<"Unique words: "<<result.size()<<std::endl;

        return result.size();
    }

    std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies){
        std::multimap<int, std::string, std::greater<>> sortedFrequencies;

        for (const auto& entry : frequencies) {
            sortedFrequencies.insert(std::make_pair(entry.second, entry.first));
        }

        return sortedFrequencies;

    }

    void outputFrequenciesToFile(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies, const std::string& fileName) {
        std::ofstream outputFile(fileName);
        int rank = 1;

        if (!outputFile.is_open()) {
            std::cerr << "Error opening output file" << std::endl;
            return;
        }

        for (const auto& [frequency, word] : sortedFrequencies) {
            outputFile << rank << " " << frequency << " " << word << std::endl;
            rank++;
        }
    }

    // void cppLogLogPlot(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies) {
    //     using namespace sciplot;
    //     std::vector<int> ranks;
    //     std::vector<int> frequencies;

    //     for (const auto& [frequency, word] : sortedFrequencies) {
    //         ranks.push_back(ranks.size() + 1);
    //         frequencies.push_back(frequency);
    //     }

    //     // Create a Plot2D object
    //     Plot2D plot;

    //     plot.xlabel("Rank");
    //     plot.ylabel("Frequency");

    //     plot.drawCurve(ranks, frequencies).label("Word Frequency Distribution");

    //     // Create figure to hold plot
    //     Figure fig = {{plot}};
    //     // Create canvas to hold figure
    //     Canvas canvas = {{fig}};
    //     canvas.save("cpp_plot.png");

    // }

    void printHapaxLegomena(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies) {
        std::vector<std::string> hapaxLegomena;

        for (const auto& entry : sortedFrequencies) {
            if (entry.first == 1) {
                hapaxLegomena.push_back(entry.second);
                // std::cout << entry.second << std::endl;
            }
        }
    }

}
