/**
	Problem:Word Ladder
	Link:https://leetcode.com/problems/word-ladder/
	Reference:https://leetcode.com/discuss/42006/easy-76ms-c-solution-using-bfs
**/

/**
	Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

	Only one letter can be changed at a time
	Each intermediate word must exist in the word list
	For example,
	Given:
	beginWord = "hit"
	endWord = "cog"
	wordList = ["hot","dot","dog","lot","log"]
	As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
	return its length 5.

	Note:
	Return 0 if there is no such transformation sequence.
	All words have the same length.
	All words contain only lowercase alphabetic characters.
**/

//One direction BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		wordList.insert(endWord);
		queue<string> visitList;
		wordNeighbor(beginWord,visitList,wordList);
		int resL = 2;
		string cache;
		while(!visitList.empty()){
			int qLength = visitList.size();
			for(int i=0; i<qLength; i++){
				cache = visitList.front();
				visitList.pop();
				if(cache == endWord)
					return resL;
				wordNeighbor(cache,visitList,wordList);
			}
			resL++;
		}
		return 0;
    }
private:
	void wordNeighbor(string word, queue<string> &visitList, unordered_set<string>& wordList){
		int length = word.size();
		for(int i=0; i<length; i++){
			char letter = word[i];
			for(int j=0; j<26; j++){
				word[i] = 'a' + j;
				auto pointer = wordList.find(word);
				if(pointer!=wordList.end()){
					visitList.push(word);
					wordList.erase(word);
				}
			}
			word[i] = letter;
		}
	}
};
