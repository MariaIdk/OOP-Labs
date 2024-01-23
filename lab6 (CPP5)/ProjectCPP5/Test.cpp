#include "sentence.h"
#include "test.h"
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

bool testSentenceProcessing() {
    std::stringstream input("Hello, world! How are you? How feeling you?");

    std::vector<std::string> sentencesWithoutComma;


    std::string line;
    while (std::getline(input, line)) {
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

    // Проверяем, что вектор содержит правильное количество предложений без запятых
    assert(sentencesWithoutComma.size() == 2);

    // Проверяем, что содержимое вектора соответствует ожидаемым предложениям
    assert(sentencesWithoutComma[0] == " How are you?");
    assert(sentencesWithoutComma[1] == " How feeling you?");
    return true;
}
