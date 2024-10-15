class Trie {
    Trie[] ch;
    boolean isWord;
    public Trie() {
        isWord = false;
        ch = new Trie[26];
    }
    
    public void insert(String word) {
        Trie tmp = this;
        for(int i=0; i<word.length(); i++) {
            // Trie tmp2 = tmp.ch[word.getCharAt(i) - 'a'];
            if(tmp.ch[word.charAt(i) - 'a'] == null) {
                tmp.ch[word.charAt(i) - 'a'] = new Trie();
            }
            tmp = tmp.ch[word.charAt(i) - 'a'];
        }
        tmp.isWord = true;
    }
    
    public boolean search(String word) {
        Trie tmp = this;
        int i=0;
        while(i<word.length() && tmp.ch[word.charAt(i) - 'a'] != null) {
            tmp = tmp.ch[word.charAt(i) - 'a'];
            i++;
        }
        return tmp.isWord && i == word.length();
    }
    
    public boolean startsWith(String word) {
        Trie tmp = this;
        int i=0;
        while(i<word.length() && tmp.ch[word.charAt(i) - 'a'] != null) {
            tmp = tmp.ch[word.charAt(i) - 'a'];
            i++;
        }
        return i == word.length();
    }
}
