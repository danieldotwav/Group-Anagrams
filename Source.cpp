// Question: Given an array of strings strs, group the anagrams together. You can return the answer in any order.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);
void printOriginalVector(vector<string> original);
void printGroupAnagrams(vector<vector<string>> anagrams);
void testCases();

int main() {
    testCases();

	return 0;
}

// Algorithm
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;
    vector<vector<string>> sorted;
    string alphabetized;

    // Group the anagrams based on the sorted characters as the keys
    for (const string& word : strs) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagrams[sortedWord].push_back(word);
    }

    // Extract the grouped anagrams into the sorted vector of vectors
    for (const auto& entry : anagrams) {
        sorted.push_back(entry.second);
    }
    return sorted;
}

void printOriginalVector(vector<string> original) {
    cout << "[";
    for (size_t i = 0; i < original.size(); ++i) {
        cout << original[i];

        if (i != original.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

void printGroupAnagrams(vector<vector<string>> anagrams) {
    cout << "[";
    for (size_t i = 0; i < anagrams.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < anagrams[i].size(); ++j) {
            cout << anagrams[i][j];
            if (j != anagrams[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != anagrams.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n\n";
}

void testCases() {
    cout << "Typical Case\n\n";
    vector<string> vector_1{ "eat", "tea", "tan", "ate", "nat", "bat" };
    cout << "Original Vector: ";
    printOriginalVector(vector_1);
    cout << "Grouped Vectors: ";
    printGroupAnagrams(groupAnagrams(vector_1));

    cout << "Empty Input\n\n";
    vector<string> vector_2{};
    cout << "Original Vector: ";
    printOriginalVector(vector_2);
    cout << "Grouped Vectors: ";
    printGroupAnagrams(groupAnagrams(vector_2));

    cout << "Single Word\n\n";
    vector<string> vector_3{ "hello" };
    cout << "Original Vector: ";
    printOriginalVector(vector_3);
    cout << "Grouped Vectors: ";
    printGroupAnagrams(groupAnagrams(vector_3));

    cout << "All Words are Anagrams\n\n";
    vector<string> vector_4{ "abc", "bca", "cab", "bac" };
    cout << "Original Vector: ";
    printOriginalVector(vector_4);
    cout << "Grouped Vectors: ";
    printGroupAnagrams(groupAnagrams(vector_4));

    cout << "No Anagrams\n\n";
    vector<string> vector_5{ "abc", "def", "ghi" };
    cout << "Original Vector: ";
    printOriginalVector(vector_5);
    cout << "Grouped Vectors: ";
    printGroupAnagrams(groupAnagrams(vector_5));

    cout << "Words of Different Lengths\n\n";
    vector<string> vector_6{ "abc", "de", "f", "cba", "ed" };
    cout << "Original Vector: ";
    printOriginalVector(vector_6);
    cout << "Grouped Vector: ";
    printGroupAnagrams(groupAnagrams(vector_6));

    cout << "Case Sensitivity\n\n";
    vector<string> vector_7{ "b", "B", "bb", "aB", "Ab", "bB" };
    cout << "Original Vector: ";
    printOriginalVector(vector_7);
    cout << "Grouped Vector: ";
    printGroupAnagrams(groupAnagrams(vector_7));

    cout << "Special Characters and Numbers\n\n";
    vector<string> vector_8{ "123", "321", "!@#", "#@!", "abc", "bca" };
    cout << "Original Vector: ";
    printOriginalVector(vector_8);
    cout << "Grouped Vector: ";
    printGroupAnagrams(groupAnagrams(vector_8));

    cout << "Duplicates in the Input\n\n";
    vector<string> vector_9{ "eat", "tea", "eat", "ate" };
    cout << "Original Vector: ";
    printOriginalVector(vector_9);
    cout << "Grouped Vector: ";
    printGroupAnagrams(groupAnagrams(vector_9));

    cout << "Long Words\n\n";
    vector<string> vector_10{ "character", "charter", "caterhr", "rachetr", "tracehr" };
    cout << "Original Vector: ";
    printOriginalVector(vector_10);
    cout << "Grouped Vector: ";
    printGroupAnagrams(groupAnagrams(vector_10));
}
