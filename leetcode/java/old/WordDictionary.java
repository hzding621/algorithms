class TrieNode {
	// Initialize your data structure here.
	public TrieNode() {
		children = new TrieNode[26];
	}

	public boolean hasChild(char c) {
		int index = (int) (c - 'a');
		return children[index] != null;
	}

	public void insertChild(char c) {
		int index = (int) (c - 'a');
		children[index] = new TrieNode();
	}

	public TrieNode getChild(char c) {
		int index = (int) (c - 'a');
		return children[index];
	}

	public void markAsWord() {
		isWord = true;
	}

	public boolean isWord() {
		return isWord;
	}

	boolean isWord;
	TrieNode[] children;
}

public class WordDictionary {
	private TrieNode root;

	public WordDictionary() {
		root = new TrieNode();
	}

	// Adds a word into the data structure.
	public void addWord(String word) {
		TrieNode it = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			if (!it.hasChild(c))
				it.insertChild(c);
			it = it.getChild(c);
		}
		it.markAsWord();
	}

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
		return recursiveSeach(word, 0, root);
    }

	private boolean recursiveSeach(String word, int startIndex, TrieNode n) {
		if (n == null)
			return false;
		if (startIndex == word.length())
			return n.isWord();
		char c = word.charAt(startIndex);
		if (c != '.')
			return recursiveSeach(word, startIndex+1, n.getChild(c));
		for (int i=0; i<26; i++)
			if (recursiveSeach(word, startIndex+1, n.getChild((char)('a'+i))))
				return true;
		return false;
	}
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
