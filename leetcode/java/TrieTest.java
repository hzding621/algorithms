public class TrieTest {
	public static void main(String[] args) {
		Trie dict = new Trie();
		dict.insert("goodlord");
		System.out.println(dict.search("goodlor"));
		System.out.println(dict.startsWith("goodd"));
	}
}