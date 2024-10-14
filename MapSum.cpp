class MapSum {
    std::unordered_map<char, MapSum*> mapa;
    std::unordered_map<std::string, int> rijeci;
    int broj;
public:
    MapSum() : broj(0) {}
    
    void insert(string key, int val) {
        MapSum *tmp = this;
        int past_num = rijeci[key];
        rijeci[key] = val;
        for(char c : key) {
            if(tmp->mapa.find(c) == tmp->mapa.end()) {
                tmp->mapa[c] = new MapSum();
            }
            tmp->mapa[c]->broj += val - past_num;
            tmp = tmp->mapa[c];
        }
    }
    
    int sum(string prefix) {
        MapSum *tmp = this;
        for(char c : prefix) {
            if(tmp->mapa.find(c) == tmp->mapa.end()) { return 0; }
            tmp = tmp->mapa[c];
        }
        return tmp->broj;
    }
};
