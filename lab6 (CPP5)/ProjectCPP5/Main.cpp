#include "sentence.h"
#include "test.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>

int main() {
    setlocale(LC_ALL, "Russian");
    if (testSentenceProcessing()) {
        std::cout << "Юнит-тесты пройдены успешно!" << std::endl;
    }
    else {
        std::cerr << "Юнит-тесты не пройдены!" << std::endl;
    }

    std::string filePath = "C:/Users/Мария/Desktop/ооп/6/text.txt";
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::vector<std::string> sentencesWithoutComma;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::string currentSentence;
        for (char c : line) {
            currentSentence += c;
            if (isEndOfSentence(c)) {
                if (!containsComma(currentSentence)) {
                    sentencesWithoutComma.push_back(currentSentence);
                }
                currentSentence.clear();
            }
        }
    }

    inputFile.close();

    for (const auto& sentence : sentencesWithoutComma) {
        std::cout << sentence << std::endl;
    }

    return 0;
}
