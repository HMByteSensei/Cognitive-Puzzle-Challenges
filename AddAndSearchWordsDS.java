import java.util.AbstractMap;
class WordDictionary {
    boolean isWord = false;
    HashMap<Character, WordDictionary> mapa = new HashMap<>();
    
    public WordDictionary() {}
    
    public void addWord(String word) {
        WordDictionary tmp = this;
        for(int i=0; i<word.length(); i++) {
            if(!tmp.mapa.containsKey(word.charAt(i))) {
                tmp.mapa.put(word.charAt(i), new WordDictionary());
            }
            tmp = tmp.mapa.get(word.charAt(i));
        }
        tmp.isWord = true;
    }
    
    public boolean search(String word) {
        WordDictionary tmp = this;
        for(int i=0; i<word.length(); i++) {
            if(word.charAt(i) == '.') {
                for(var kv : tmp.mapa.entrySet()) {
                    if(kv.getValue().search(word.substring(i+1))) {
                        return true;
                    }
                }
                return false;
            } else {
                if(!tmp.mapa.containsKey(word.charAt(i))) {
                    return false;
                }
                tmp = tmp.mapa.get(word.charAt(i));
            }
        }
        return tmp.isWord;
    }
}
