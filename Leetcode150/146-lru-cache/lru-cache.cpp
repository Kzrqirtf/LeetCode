// class LRUCache {
// public:
//     int c;
//     list<pair<int, int>> s;
//     unordered_map<int, list<pair<int,int>>::iterator> m;
//     LRUCache(int capacity) {
//         c = capacity;
//     }
    
//     int get(int key) {
//         if(m.find(key) == m.end()) return -1;
//         auto j = *m[key];
//         s.erase(m[key]);
//         s.push_front(j);
//         m[key] = s.begin();
//         return j.second;
//     }
    
//     void put(int key, int value) {
//         if(m.find(key) == m.end()) {
//             if(s.size() == c) {
//                 auto j = s.back();
//                 s.pop_back();
//                 m.erase(j.first);
//             }
//         } else {
//             s.erase(m[key]);
//         }
//         s.push_front({key, value});
//         m[key] = s.begin();
//     }
// };
class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k,int v){
            key=k;
            value=v;
            prev = nullptr;  // Initialize prev to nullptr
            next = nullptr;
        }
    };
    int c;
    Node* head=new Node(-1,-1);
    Node* tail = new Node(-1,-1);;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        c = capacity;
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }
    void deletenode(Node* node){
        Node* a=node->prev;
        Node* b=node->next;
        a->next=b;
        b->prev=a;
    }
    void addnode(Node* node){
        Node* a= head->next;
        node->next = a;
        a->prev=node;
        head->next=node;
        node->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            auto a = mp[key];
            int ans = a->value;
            mp.erase(key);
            deletenode(a);
            addnode(a);
            mp[key]=head->next;
            return ans;
        }
        return -1;
        
    }
    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        if(mp.size()==c){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        Node* a=new Node(key,value);
        addnode(a);
        mp[key]=head->next;
        
    }
    
};

