/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (64.11%)
 * Likes:    11030
 * Dislikes: 122
 * Total Accepted:    922.8K
 * Total Submissions: 1.4M
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
  int pass;
  int end;
  std::unordered_map<char, TrieNode *> nexts;

  TrieNode() {
    pass = 0;
    end = 0;
  }
};

class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *cur = root;
    cur->pass++;
    for (int i = 0; i < word.size(); i++) {
      auto it = cur->nexts.find(word.at(i));
      // 没有这个树，添加子节点
      if (it == cur->nexts.end()) {
        TrieNode *child = new TrieNode();
        root->nexts.insert({word.at(i), child});
        cur = child;
      } else {
        it->second->pass++;
        cur = it->second;
      }
    }
    cur->end++;
  }

  int word_count(string word) {
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); i++) {
      if (cur->nexts.find(word.at(i)) == cur->nexts.end()) {
        return 0;
      }
      cur = cur->nexts[word.at(i)];
    }
    return cur->end;
  }

  bool search(string word) {
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); i++) {
      if (cur->nexts.find(word.at(i)) == cur->nexts.end()) {
        return false;
      }
      cur = cur->nexts[word.at(i)];
    }
    return true;
  }

  int startsWith_count(string prefix) {
    TrieNode *cur = root;
    for (int i = 0; i < prefix.size(); i++) {
      if (cur->nexts.find(prefix.at(i)) == cur->nexts.end()) {
        return 0;
      }
      cur = cur->nexts[prefix.at(i)];
    }
    return cur->pass;
  }

  bool startsWith(string prefix) {
    TrieNode *cur = root;
    for (int i = 0; i < prefix.size(); i++) {
      if (cur->nexts.find(prefix.at(i)) == cur->nexts.end()) {
        return false;
      }
      cur = cur->nexts[prefix.at(i)];
    }
    return true;
  }

  void deleteWord(string word) {
    if (!search(word))
      return;

    TrieNode *cur = root;
    cur->pass--;
    for (int i = 0; i < word.size(); i++) {
      if (--(cur->nexts[word.at(i)]->pass) == 0) {
        // 必须要析构后续节点，在这里删除
        cur->nexts.erase(cur->nexts.find(word.at(i)));
        return;
      }
      cur = cur->nexts[word.at(i)];
    }
    cur->end--;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
