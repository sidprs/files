#include <iostream>

/*

K % capacity


*/

using namespace std;

template <typename K, typename V>
struct HashMap {
  K key;
  V val;
  bool occupied;
};

struct slot {
  int key;
  int value;
  bool occupied;
};

class Map {
 public:
  explicit Map(int capacity)
      : capacity_{capacity},
        table_(new slot[capacity]),
        size_{0},
        head_{0},
        tail_{0} {
    for (int i = 0; i < capacity_; i++) {
      this->table_[i].value = 0;
      this->table_[i].key = 0;
      this->table_[i].occupied = false;
    }
  }

  bool isEmpty(int index) { return !this->table_[index].occupied; }

  void look_up(int key) {
    int index = key % capacity_;
    int start = index;

    while (this->table_[index].occupied) {
      if (this->table_[index].key == key) {
        std::cout << " found " << index;
        std::cout << " val " << this->table_[index].value << std::endl;
        return;
      } else {
        index = (index + 1) % this->capacity_;
      }
      if (index == start) {
        std::cout << "not found" << std::endl;
        break;
      }
    }
  }

  void insert(int key, int val) {
    int index = key % this->capacity_;
    while (!isEmpty(index)) {
      index = (index + 1) % this->capacity_;
    }
    this->table_[index].value = val;
    this->table_[index].key = key;
    this->table_[index].occupied = true;
  }

  void print() {
    for (int i = 0; i < this->capacity_; i++) {
      std::cout << " index " << i;
      // std::cout << " key " << this->table_[i].index;
      std::cout << " key " << this->table_[i].key;
      std::cout << " val " << this->table_[i].value << std::endl;
    }
  }

 private:
  slot *table_;
  int size_;
  int capacity_;
  int head_;
  int tail_;
};

int main(int argc, char *argv[]) {
  Map r(5);
  r.insert(4, 1);
  r.insert(9, 99);
  r.print();
  r.look_up(4);  // Should print value 1
  r.look_up(9);  // Should print value 99
  r.look_up(8);  // Should print not found

  return 0;
}
