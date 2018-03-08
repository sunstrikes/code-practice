class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        minn = 0;
    }

    int get(int key) {
        if (_kv.count(key) == 0){
            return -1;
        }
        auto time = _kv[key].second++;
        _time[key].erase(_p[key]);
        _time[time+1].push_back(key);
        _p[key] = --_time[time+1].end();
        if (_time[minn].size() == 0)
            minn++;
        return _kv[key].first;
    }

    void put(int key, int value) {
        if (_capacity <= 0) {return;}
        if (get(key) != 0){
            m[key].first = value;
            return;
        }
        int dell = 0;
        if(_kv.size() < _capacity)

        else{
            dell = *_time[minn].begin();
            _p.erase(dell);
            _kv.erase(dell);
            _time[minn].pop_front();
        }
            

    }
private:
    int minn;
    std::unordered_map<int, pair<int,int>> _kv;//second存最近被访问的次数
    std::unordered_map<int, list<int>> _time;
    std::unordered_map<int, list<int>::iterator> _p;
    int _capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
