class NumberContainers {
public:
    map<int, set<int>> indexes;
    map<int, int> container;
    NumberContainers() {}

    void change(int index, int number) {
        if (container.find(index) != container.end())
            indexes[container[index]].erase(index);
        indexes[number].insert(index);
        container[index] = number;
    }

    int find(int number) { 
        if (indexes.count(number) && indexes[number].size())
            return *indexes[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */