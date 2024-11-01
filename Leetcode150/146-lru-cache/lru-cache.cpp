class LRUCache {
public:
    int c;
    list<pair<int, int>> s;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        auto j = *m[key];
        s.erase(m[key]);
        s.push_front(j);
        m[key] = s.begin();
        return j.second;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()) {
            if(s.size() == c) {
                auto j = s.back();
                s.pop_back();
                m.erase(j.first);
            }
        } else {
            s.erase(m[key]);
        }
        s.push_front({key, value});
        m[key] = s.begin();
    }
};
