class Solution {
    unordered_map<string, int> mpp; // Stores distance from beginWord
    vector<vector<string>> ans;     // Stores all shortest sequences
    string b;                       // Begin word
    int sz;                         // Word length

    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return {}; // Early return if endWord not present

        queue<string> q;
        b = beginWord;
        sz = beginWord.size();
        q.push(beginWord);
        mpp[beginWord] = 1;

        st.erase(beginWord);
        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> wordsThisLevel;

            for (int k = 0; k < size; k++) {
                string word = q.front(); q.pop();
                int steps = mpp[word];

                for (int i = 0; i < sz; i++) {
                    char original = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if (st.count(word)) {
                            if (mpp.find(word) == mpp.end()) {
                                mpp[word] = steps + 1;
                                q.push(word);
                                wordsThisLevel.insert(word);
                            }
                        }
                    }
                    word[i] = original;
                }
            }

            for (auto& w : wordsThisLevel) {
                st.erase(w); // Erase only after level finishes
            }
        }

        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq = { endWord };
            dfs(endWord, seq);
        }

        return ans;
    }
};
