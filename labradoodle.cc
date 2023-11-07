/*Labradoodle
Time limit: 12500 ms
Memory limit: 256 MB

Sporks, labradoodles, and chocoholics are all examples where two words are blended into one. Your challenge to determine whether a word is a blended word given a dictionary of words.

For this challenge, we assume that the blended word is created as follows:

1) A dictionary word is chosen and a prefix with at least length 3 is taken from this word

2) Another (maybe the same) dictionary word is chosen and a suffix with at least length 3 is taken from this word

The prefix and the suffix are combined to create the blended word. If the prefix ends with the same letter that the suffix starts with, one of these matching letters may be dropped.

Standard Input
Input begins with two-space separated integers n and m. The next n lines contain a word from the dictionary, consisting of lowercase letters only. The remaining m lines contain words, consisting only of lowercase letters, that may be blended words.

Standard Output
For each of the potential blended words, output one of the following:

ambiguous, if there is more than one dictionary word pair that could create the blended word
none, if no dictionary word pairs could create the blended word
Otherwise. the dictionary word that contributes the prefix, followed by a space, followed by the dictionary word that provides the suffix.
Constraints and notes
1
≤
�
≤
10
,
000
1≤n≤10,000
1
≤
�
≤
10
,
000
1≤m≤10,000
Each dictionary word will be made up of lowercase ASCII letters and have between 1 and 50 characters, inclusive.

Each potential blended word will be made up of lowercase ASCII letters and have between 1 and 100 characters, inclusive.

Note that none of the potential blended words will also be dictionary words. However, the same dictionary word can provide both the prefix and the suffix of a blended word.

Input	Output	Explanation
6 7
spoon
fork
labrador
poodle
form
car
spork
labradoodle
fordle
cardor
lark
spoooon
labradabrador
spoon fork
labrador poodle
ambiguous
car labrador
none
spoon spoon
labrador labrador
For "spork", we can combine the prefix "spo" from "spoon" with the suffix "ork" from "fork". Since the prefix ends with the same letter as the suffix, we can combine these letters and use only one "o".

"fordle" is ambiguous because it can be made with "fork" and "poodle" as well as "form" and "poodle".

"lark" cannot be a blended word because it is too short.

With "spoooon" and "labradabrador" note that a blended word can use the same word for the prefix and suffix.*/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

bool single(const std::string& word, const std::vector<std::string>& dictionary) {
    int len_word = word.length();
    std::unordered_map<std::string, std::set<std::string>> prefix_count;
    std::unordered_map<std::string, std::set<std::string>> suffix_count;

    if (len_word < 6) {
        std::string prefix = word.substr(0, 3);
        std::string suffix = word.substr(len_word - 3);

        std::set<std::string> prefix_name;
        std::set<std::string> suffix_name;

        for (const std::string& dict_word : dictionary) {
            if (dict_word.compare(0, 3, prefix) == 0) {
                prefix_name.insert(dict_word);
            }
            if (dict_word.length() >= suffix.length() && dict_word.compare(dict_word.length() - suffix.length(), suffix.length(), suffix) == 0) {
                suffix_name.insert(dict_word);
            }
        }

        if (prefix_name.size() == 1 && suffix_name.size() == 1) {
            std::cout << *prefix_name.begin() << " " << *suffix_name.begin() << std::endl;
            return true;
        } else if (prefix_name.size() > 1 || suffix_name.size() > 1) {
            std::cout << "ambiguous" << std::endl;
            return true;
        }

        std::cout << "none" << std::endl;
        return false;
    }

    for (int prefix_len = 3; prefix_len <= len_word - 2; prefix_len++) {
        std::string prefix = word.substr(0, prefix_len);
        std::string suffix = word.substr(prefix_len);

        if (prefix_count.find(prefix) == prefix_count.end()) {
            std::set<std::string> prefix_name;
            for (const std::string& dict_word : dictionary) {
                if (dict_word.compare(0, prefix_len, prefix) == 0) {
                    prefix_name.insert(dict_word);
                }
            }
            prefix_count[prefix] = prefix_name;
        }

        if (suffix_count.find(suffix) == suffix_count.end()) {
            std::set<std::string> suffix_name;
            for (const std::string& dict_word : dictionary) {
                if (dict_word.length() >= suffix.length() && dict_word.compare(dict_word.length() - suffix.length(), suffix.length(), suffix) == 0) {
                    suffix_name.insert(dict_word);
                }
            }
            suffix_count[suffix] = suffix_name;
        }

        std::set<std::string>& prefix_name = prefix_count[prefix];
        std::set<std::string>& suffix_name = suffix_count[suffix];

        if (prefix_name.size() == 1 && suffix_name.size() == 1) {
            std::cout << *prefix_name.begin() << " " << *suffix_name.begin() << std::endl;
            return true;
        } else if (prefix_name.size() > 1 || suffix_name.size() > 1) {
            std::cout << "ambiguous" << std::endl;
            return true;
        }
    }

    std::cout << "none" << std::endl;
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> dictionary(n);

    for (int i = 0; i < n; i++) {
        std::cin >> dictionary[i];
    }

    for (int i = 0; i < m; i++) {
        std::string blended_word;
        std::cin >> blended_word;
        single(blended_word, dictionary);
    }

    return 0;
}
