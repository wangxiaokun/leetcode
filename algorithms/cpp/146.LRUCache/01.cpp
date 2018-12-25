class LRUCache {
   
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        //std::cout<<"get():"<<key<<std::endl;
        auto iter1 = map_.find(key);
        if (map_.end() == iter1) return -1;

        int value = iter1->second;
        auto iter2 = std::find(deque_.begin(), deque_.end(), key);
        deque_.erase(iter2);
        //print();
        deque_.push_back(key);
        //print();
        return value;
    }
    
    void put(int key, int value) {
        //std::cout<<"put():"<<key<<"-"<<value<<std::endl;
        auto iter = std::find(deque_.begin(), deque_.end(), key);
        if (deque_.end() == iter) {
            if (deque_.size() >= capacity_) {
                //std::cout<<"---------"<<deque_.front()<<std::endl;
                map_.erase(deque_.front());
                deque_.pop_front();
            }                 
        }
        else {
            deque_.erase(iter);
        }
        
        map_[key] = value;
        deque_.push_back(key);   
        //print();
    }
    
    void print() {
        for(auto& iter:map_)
        {
            std::cout<<"--> map:"<<iter.first<<"-"<<iter.second<<std::endl;
        }
        
        for(auto& iter:deque_)
        {
            std::cout<<"--> deque:"<<iter<<std::endl;
        }
    }
    
private:
    int capacity_;
    std::deque<int> deque_;
    std::unordered_map<int, int> map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */