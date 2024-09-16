class MapSum {
    HashMap<Character, MapSum> mapa;
    int sum;
    HashMap<String, Integer> skup;
    public MapSum() {
        mapa = new HashMap<>();
        sum = 0;
        skup = new HashMap<>();
    }
    
    public void insert(String key, int val) {
        MapSum tmp = this;
        if(skup.containsKey(key)) {
            int old_val = skup.get(key);
            for(int i=0; i<key.length(); i++) {
                tmp = tmp.mapa.get(key.charAt(i));
                tmp.sum = (tmp.sum - old_val) + val;
            }
        } else {
            for(int i=0; i<key.length(); i++) {
                if(!tmp.mapa.containsKey(key.charAt(i))) {
                    tmp.mapa.put(key.charAt(i), new MapSum());
                }
                tmp = tmp.mapa.get(key.charAt(i));
                tmp.sum += val;
            }
        }
        skup.put(key, val);
    }
    
    public int sum(String prefix) {
        MapSum tmp = this;
        int i=0;
        while(i<prefix.length() && tmp.mapa.containsKey(prefix.charAt(i))) {
            tmp = tmp.mapa.get(prefix.charAt(i));
            i++;
        }
        return (i == prefix.length() ? tmp.sum : 0);
    }
}
