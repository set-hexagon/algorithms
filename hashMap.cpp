#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

class hashMap {
    std::vector<int> map;
    int size;
    const int EMPTY = std::numeric_limits<int>::min();
    public:
        void makeHashMap(std::vector<int> arr) {
            this->size = arr.size();
            this->map.assign(size, EMPTY);
            for (auto& elm:arr) {
                int id = hash(elm);
                // stores element via linear probing
                while (this->map[id] != EMPTY) id = (id+1)%size;
                this->map[id] = elm;
            }
        }

        int find(int elm) {
            int id =  hash(elm);
            int startId = id;
            while (this->map[id] != elm) {
                id = (id+1) % size;
                if (id == startId) return -1;
            }
            return id;
        }

        void print() {
            int i = 0;
            for (auto& elm:this->map){
                std::cout << "[" << i++ << "] --> " << elm << std::endl;
            }
        }

    private:
        int hash(int elm) {
            return (elm%size + size)%size;
        }
};

int main() {
    std::vector<int> arr = {234,4,23,1245,433,245,19435,32,420};
    hashMap hm;
    hm.makeHashMap(arr);
    hm.print();
    return 0;
}
