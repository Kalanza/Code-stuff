/*Programmer's Poem


The poem above is meant to be read:

Waka waka bang splat tick tick hash

Caret quote back tick dollar dollar dash

Bang splat equal at dollar underscore

Percent splat waka waka tilde number four

Ampersand bracket bracket dot dot slash

Vertical bar curly bracket comma comma CRASH

Challenge
In this challenge, you need to determine the rhyme scheme used by a passage. A rhyme scheme for a passage with 
�
n lines is a string of uppercase letters of length 
�
n, where the 
�
�
ℎ
i 
th
  letter in the string corresponds to the 
�
�
ℎ
i 
th
  line in the passage. The rules for creating the string are:

1) The lines that rhyme will be labelled with upper-case letters except for X.

2) The first set of lines that rhyme should be labelled with an A. The second set are labelled with a B, and so on, skipping the letter X.

3) Lines that do not rhyme with any other line should be labelled with an X.

Standard input
The input will begin with two space-separated integers 
�
n and 
�
m.

Each of the next 
�
n lines will contain a list of space-separated words that rhyme. The words will consist of lowercase letters only.

Then there will be a blank line.

The next 
�
m lines contain the passage to analyze.

Standard output
Output the rhyme scheme for the passage.

Constraints and notes
1
≤
�
≤
100
1≤n≤100
2
≤
�
≤
50
2≤m≤50
Each rhyming group will contain between 1 and 100 words, inclusive.

Each word will be made of between 1 and 15 lower-case letters, inclusive.

No word will appear in more than one group of rhyming words.

Each line of the passage will contain between 1 and 100 words, inclusive. The passage will contain only upper- and lower-case letters.

Comparisons should ignore case.

Two words should only be treated as rhyming, if they appear in the same list of rhyming words.

A word rhymes with itself, if and only if, it appears in one of the lists of rhyming words.*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

std::string findRhymeScheme(int n, int m, std::vector<std::vector<std::string>>& rhymingWords, std::vector<std::string>& passage) {
    std::unordered_map<std::string, char> rhymeScheme;

    for (int i = 0; i < n; ++i) {
        for (const auto& word : rhymingWords[i]) {
            rhymeScheme[word] = 'A' + i;  // Assign uppercase letters A, B, C, ... to rhyming words
        }
    }

    std::string output;
    char rhymeIndex = 'A';  // Start with 'A'

    for (const auto& line : passage) {
        std::set<char> lineRhyme;

        std::string word;
        std::istringstream iss(line);
        while (iss >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (rhymeScheme.find(word) != rhymeScheme.end()) {
                lineRhyme.insert(rhymeScheme[word]);
            }
        }

        if (lineRhyme.size() == 1) {
            output += *lineRhyme.begin();
        } else {
            if (lineRhyme.empty()) {
                output += rhymeIndex;
                ++rhymeIndex;
            } else {
                output += 'X';
            }
        }
    }

    return output;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::string>> rhymingWords(n);
    for (int i = 0; i < n; ++i) {
        std::string word;
        while (std::cin >> word) {
            if (word.empty()) break;
            rhymingWords[i].push_back(word);
        }
    }

    std::vector<std::string> passage(m);
    for (int i = 0; i < m; ++i) {
        std::cin.ignore();
        std::getline(std::cin, passage[i]);
    }

    std::string result = findRhymeScheme(n, m, rhymingWords, passage);
    std::cout << result << std::endl;

    return 0;
}