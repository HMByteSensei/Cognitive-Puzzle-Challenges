public class MyHashSet {
    private bool[] niz;
    
    public MyHashSet() {
        niz = new bool[1000001];
    }
    
    public void Add(int key) {
        niz[key] = true;
    }
    
    public void Remove(int key) {
        niz[key] = false;
    }
    
    public bool Contains(int key) {
        return niz[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.Add(key);
 * obj.Remove(key);
 * bool param_3 = obj.Contains(key);
 */
