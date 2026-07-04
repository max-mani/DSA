class RandomizedSet {
    vector<int> out;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        out.push_back(val);
        mp[val] = out.size() - 1;
        return true;
    }
    bool remove(int val) {
        auto i = mp.find(val);
        if (i == mp.end()) return false;
        out[i->second] = out.back();
        out.pop_back();
        mp[out[i->second]] = i->second;
        mp.erase(val);
        return true;
    }
    int getRandom() {
        return out[rand()%out.size()];
    }
};