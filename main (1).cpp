class Solution {
public:
       vector<int> findSubstring(string s, vector<string>& words) {
        //map to count each time word occurs 
        unordered_map<string, int> counts;
        //result vector
        vector<int> indexes;
        for (string word : words)
        counts[word]++;
        int n = s.length(), num = words.size();
        if (n == 0 || num == 0) return indexes;
        int len = words[0].length();
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
     /*
        The goal is to get substrings from the s string that are the same length as a word from the words vector and check its occurence in the map.
        If each substring exists in the map and we finish iterating through the length of the number of words in words, then add the starting index of the window to the result (j)
        Otherwise exit because either the word isn't a valid word from the words bank or the number of times a word was seen in S goes over the amount of times it can be a valid result. 
        Do this for each index sliding the window up by one until we get to n-windowsize 
     */
};