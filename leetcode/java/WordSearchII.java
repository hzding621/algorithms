import java.util.*;

class TrieNode {
	// Initialize your data structure here.
	public TrieNode() {
		children = new TrieNode[26];
	}

	public boolean hasChild(char c) {
        if (c < 'a' || c > 'z')
            return false;
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

class Trie {
	private TrieNode root;

	public Trie() {
		root = new TrieNode();
	}

    public TrieNode getRoot() {
        return root;
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

public class WordSearchII {
    public static List<String> findWords(char[][] board, String[] words) {
        List<String> result = new ArrayList<String>();
        Trie trie = new Trie();
        for (String s: words)
            trie.insert(s);
        int m = board.length;
        if (m == 0) return result;
        int n = board[0].length;
        if (n == 0) return result;
        Set<String> foundWords = new HashSet<String>();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                dfs(board, i, j, foundWords, trie.getRoot(), new StringBuilder());
            }
        }
        for (String s: foundWords)
            result.add(s);
        return result;
    }

    private static void dfs(char[][] board, int i, int j, Set<String> foundWords, TrieNode node, StringBuilder sb) {
        if (node.isWord())
            foundWords.add(sb.toString());
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length)
            return;
        char c = board[i][j];
        board[i][j] = '*';
        if (node.hasChild(c)) {
            sb.append(c);
            TrieNode child = node.getChild(c);
            dfs(board, i+1, j, foundWords, child, sb);
            dfs(board, i-1, j, foundWords, child, sb);
            dfs(board, i, j+1, foundWords, child, sb);
            dfs(board, i, j-1, foundWords, child, sb);
            sb.deleteCharAt(sb.length()-1);
        }
        board[i][j] = c;
    }

    public static void main(String[] args) {
        char[][] board = {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i','f','l','v'}
        };
        String[] words = {"eat","oath"};
        List<String> l = findWords(board, words);
        for (String s: l) {
            System.out.println(s);
        }
    }
}
