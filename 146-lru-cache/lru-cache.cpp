class LRUCache {
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mpp;
    int n;

    void makemostrecentlyused(int key) {
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
    }

public:
    LRUCache(int capacity) { this->n = capacity; }

    int get(int key) { 
        if(mpp.find(key) != mpp.end()){
            makemostrecentlyused(key) ;
            return mpp[key].second ;
            
        }
        return -1 ;
     }

    void put(int key, int value) {
       if(mpp.find(key) == mpp.end()){
            dll.push_front(key);
            mpp[key] = {dll.begin() , value} ;
            n-- ;
        }
        else{
            mpp[key].second = value ;
            makemostrecentlyused(key) ;
        }
         if(n<0){
            mpp.erase(dll.back());
            dll.pop_back() ;

            n++ ;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */