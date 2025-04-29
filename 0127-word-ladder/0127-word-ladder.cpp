class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordset(wordList.begin(),wordList.end());
        if(!wordset.count(endWord)) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            auto[word,steps] = q.front();
            q.pop();
            if(word == endWord) return steps;
            for(int i = 0;i<word.length();i++)
            {
                string newWord = word;
                for(char ch = 'a';ch <='z';ch++){
                    newWord[i] = ch;
                    if(wordset.count(newWord))
                    {
                        wordset.erase(newWord);
                        q.push({newWord,steps+1});
                    }
                }
            }
        }
        
        return 0;
    }
};