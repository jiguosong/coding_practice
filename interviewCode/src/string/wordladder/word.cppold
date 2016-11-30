/*
 * word.cpp
 *
 *  Created on: Nov 12, 2016
 *      Author: songjiguo
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <limits.h>

using namespace std;

class word {
public:
	virtual void run() = 0;
	virtual ~word(){};
};

/* word_ladder I */
class word_ladder : public word {
public:
	void run() override {
		cout << "word_ladder I\n";
		string beginWord = "hit";
		string endWord = "cog";
		unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
		int ans = ladderLength(beginWord, endWord, wordList);
		cout << ans;
	}

	static word_ladder &instance() {
		word_ladder *p = new word_ladder();
		return *p;
	}

	~word_ladder(){};
private:
	word_ladder(){};
	word_ladder(const word_ladder &other);
	const word_ladder &operator=(const word_ladder &other);

	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList);
};


int word_ladder::ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
	if(!beginWord.size() || !endWord.size() || !wordList.size()) return 0;
	unordered_map<string, int> map;
	queue<string> queue;
	queue.push(beginWord);
	map[beginWord] = 1;

	while(!queue.empty()) {
		string tmp = queue.front();
		queue.pop();
		for(int i = 0; i < tmp.size(); ++i){
			string newword = tmp;
			for(char c = 'a'; c < 'z'; ++c) {
				newword[i] = c;
				if(newword == endWord) return map[tmp] +1;
				if(wordList.find(newword) != wordList.end() && map.find(newword) == map.end()) {
					queue.push(newword);
					map[newword] = map[tmp] + 1;
				}
			}
		}
	}

	return 0;
}


/* word_ladder I */
class word_ladder2 : public word {
public:
	void run() override {
		cout << "word_ladder II\n";
		string beginWord = "hit";
		string endWord = "cog";
		unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
		vector<vector<string>> ans = findLadders(beginWord, endWord, wordList);
		for(vector<string> e:ans) {
			for(string s:e) cout << s << ' ';
			cout << endl;
		}
	}

	static word_ladder2 &instance() {
		word_ladder2 *p = new word_ladder2();
		return *p;
	}

	~word_ladder2(){};
private:
	word_ladder2(){};
	word_ladder2(const word_ladder2 &other);
	const word_ladder2 &operator=(const word_ladder2 &other);

	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict);

};


vector<vector<string>> word_ladder2::findLadders(string start, string end, unordered_set<string> &dict)
{
	vector<vector<string> > res;
	dict.insert(end);
	vector<string> p;
	p.push_back(start);
	queue<vector<string> > paths;
	paths.push(p);
	int level = 1, minLevel = INT_MAX;
	unordered_set<string> words;
	while (!paths.empty()) {
		vector<string> path = paths.front();
		paths.pop();
		if (path.size() > level) {
			for (string w : words) dict.erase(w);
			words.clear();
			level = path.size();
			if (level > minLevel) break;
		}
		string last = path.back();
		for (int i = 0; i < last.size(); ++i) {
			string newLast = last;
			for (char ch = 'a'; ch <= 'z'; ++ch) {
				newLast[i] = ch;
				if (dict.find(newLast) != dict.end()) {
					words.insert(newLast);
					vector<string> nextPath = path;
					nextPath.push_back(newLast);
					if (newLast == end) {
						res.push_back(nextPath);
						minLevel = level;
					} else paths.push(nextPath);
				}
			}
		}
	}
	return res;
}


/* word_search I */

/* word_ladder I */
class word_search : public word {
public:
	void run() override {
		cout << "word_search I\n";
		string word = "ABCCED";
		vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
									   {'S', 'F', 'C', 'S'},
									   {'A', 'D', 'E', 'E'}};
		bool ans = exist(board, word);
		cout << ans;
	}

	static word_search &instance() {
		word_search *p = new word_search();
		return *p;
	}

	~word_search(){};
private:
	word_search(){};
	word_search(const word_search &other);
	const word_search &operator=(const word_search &other);
	bool exist(vector<vector<char>> &board, string word);
	bool search_helper(vector<vector<char>> &board, string word, int level, int i, int j, vector<vector<bool>> &visited);

};

bool word_search::exist(vector<vector<char>> &board, string word)
{
	if(word.empty()) return true;
	if(board.empty() || board[0].empty()) return false;
	int m = board.size();
	int n = board[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));

	int found = false;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (search_helper(board, word, 0, i, j, visited)) return true;
		}
	}

	return false;
}


bool word_search::search_helper(vector<vector<char>> &board, string word, int level,
					int i, int j, vector<vector<bool>> &visited)
{
	if(level == word.size()) return true;
	if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
	  visited[i][j] == true || word[level] != board[i][j]) return false;

	visited[i][j] = true;

	bool res = search_helper(board, word, level+1, i-1, j, visited) ||
				search_helper(board, word, level+1, i, j-1, visited) ||
				search_helper(board, word, level+1, i+1, j, visited) ||
				search_helper(board, word, level+1, i, j+1, visited);

	visited[i][j] = false;
	return res;
}



class word_search2 : public word{
public:
	void run() override {
		cout << "word search 2" << endl;
	}

	static word_search2 &instance() {
		static word_search2 *p = new word_search2;
		return *p;
	}

	~word_search2(){};

private:
	word_search2(){};
	word_search2(const word_search2 &other);
	word_search2 &operator=(const word_search2 &other);
	vector<string> findWords(vector<vector<char> >& board, vector<string>& words);
};

vector<string> word_search2::findWords(vector<vector<char> >& board, vector<string>& words)
{
	vector<string> res;
	return res;
}


class word_factory {
public:
	static word &solution(const string name) {
		if(name == "word ladder") {
			word &p = word_ladder::instance();
			return p;
		}

		if(name == "word ladder 2") {
			word &p = word_ladder2::instance();
			return p;
		}

		if(name == "word search") {
			word &p = word_search::instance();
			return p;
		}

		if(name == "word search 2") {
			word &p = word_search2::instance();
			return p;
		}

	}
};

int main(int argc, char argv[])
{
	word_factory test;
	test.solution("word ladder").run();
	cout << endl;
	test.solution("word ladder 2").run();
	cout << endl;
	test.solution("word search").run();
	cout << endl;
	test.solution("word search 2").run();
}
