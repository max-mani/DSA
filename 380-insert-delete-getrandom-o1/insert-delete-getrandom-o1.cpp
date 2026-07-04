class RandomizedSet {
    vector<int> out;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (mp.count(val)) return false;
        out.push_back(val);
        mp[val] = out.size() - 1;
        return true;
    }
    bool remove(int val) {
        auto it = mp.find(val);
        if (it == mp.end()) return false;
        int i = it->second;
        int ed = out.back();
        out[i] = ed;
        mp[ed] = i;
        out.pop_back();
        mp.erase(it);
        return true;
    }
    int getRandom() {
        return out[rand()%out.size()];
    }
};