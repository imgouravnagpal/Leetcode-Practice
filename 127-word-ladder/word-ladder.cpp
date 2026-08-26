class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (!wordDict.count(endWord)) return 0;

        queue<pair<string,int>> pq;
        pq.push({beginWord, 1});          // start count at 1 (word count, not edges)
        wordDict.erase(beginWord);        // treat wordDict as "unvisited" set

        while (!pq.empty()) {
            auto [word, dist] = pq.front(); pq.pop();

            if (word == endWord) return dist;

            for (int i = 0; i < (int)word.size(); i++) {
                char original = word[i];              // save it
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;
                    word[i] = c;
                    if (wordDict.count(word)) {
                        wordDict.erase(word);          // mark visited
                        pq.push({word, dist + 1});
                    }
                }
                word[i] = original;                    // restore before next i
            }
        }
        return 0;
    }
};