class MyHashSet {
private:
    int** niz;
    int vel;
    int size;
    
    int hashFunction(int key) {
    }
public:
    MyHashSet() : vel(0), size(1000) {
        niz = new int[1000]{-1};
    }
    
    void add(int key) {
        if(vel >= size) {
            int tmp[size * 2]{};
            for(int i=0; i<size; i++) {
                tmp[i] = (*niz)[i];
            }
            *niz = tmp;
            size *= 2;
        }
        if(!((*niz)[hashFunction(key)] == key)) {
            (*niz)[hashFunction(key)] = key
        }
    }
    
    void remove(int key) {
        
    }
    
    bool contains(int key) {
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
