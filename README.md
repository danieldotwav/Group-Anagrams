# Group Anagrams

## Overview
The "Group Anagrams" project is a C++ implementation designed to efficiently categorize a list of strings into groups of anagrams. An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Algorithm
The core function `groupAnagrams` takes a vector of strings and groups anagrams together. The process involves two primary steps:

1. **Sorting and Categorization**: For each word in the input vector, the algorithm sorts the characters of the word (thus alphabetizing them) and uses this sorted version as a key in an unordered map. The original word is then appended to the vector corresponding to this key.

2. **Extraction**: The algorithm iterates over the unordered map, pushing each vector of grouped anagrams into a final `vector<vector<string>>` which is then returned.

### Code Snippet
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;
    vector<vector<string>> sorted;

    for (const string& word : strs) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagrams[sortedWord].push_back(word);
    }

    for (const auto& entry : anagrams) {
        sorted.push_back(entry.second);
    }
    return sorted;
}
```

## Complexity Analysis
### Time Complexity
- **O(NK log K)**: Here, `N` is the number of strings, and `K` is the maximum length of a string in the input list. The algorithm iterates through each string (`O(N)`) and sorts it (`O(K log K)`).

### Space Complexity
- **O(NK)**: The space complexity mainly comes from storing the sorted strings and the unordered map. Each string is stored once in its sorted form and once in the unordered map.

## Potential Improvements
1. **String Hashing**: Instead of sorting each word, a hash function could be used to generate a unique key for each group of anagrams. This can potentially reduce the time complexity, depending on the hash function's efficiency.

2. **Optimized Data Structures**: Depending on the typical size and nature of input data, different data structures could be more efficient. For example, a trie might be used for storing sorted words.

3. **Parallel Processing**: For very large datasets, parallel processing of the initial sorting and categorization step could significantly speed up the algorithm.

## Auxiliary Functions
The project also includes auxiliary functions for displaying vectors and vector of vectors, aiding in testing and visualization of the algorithm's output.

## Conclusion
"Group Anagrams" is a practical implementation showcasing efficient categorization of strings into anagrams using modern C++ techniques. While the current implementation balances efficiency and readability, ongoing improvements can adapt it for more specialized or performance-critical applications.
