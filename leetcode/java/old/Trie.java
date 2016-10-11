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

public class Trie {
	private TrieNode root;

	public Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	public void insert(String word) {
		TrieNode it = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			if (!it.hasChild(c))
				it.insertChild(c);
			it = it.getChild(c);
		}
		it.markAsWord();
	}

	// Returns if the word is in the trie.
	public boolean search(String word) {
		TrieNode it = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			if (!it.hasChild(c))
				return false;
			it = it.getChild(c);
		}
		return it.isWord();
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	public boolean startsWith(String prefix) {
		TrieNode it = root;
		for (int i = 0; i < prefix.length(); i++) {
			char c = prefix.charAt(i);
			if (!it.hasChild(c))
				return false;
			it = it.getChild(c);
		}
		return true;
	}
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");