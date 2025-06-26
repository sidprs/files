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
  int index;
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
        tail_{0} {}

  bool isEmpty(int index) { return true; }

  void insert(int key, int val) {
    int index = key % this->capacity_;
    if (isEmpty(index)) {
      this->table_[index].value = val;
      this->table_[index].index = index;
    } else {
      while (!isEmpty(index)) {
        index = index + 1 % this->capacity_;
      }
      this->table_[index].value = val;
      this->table_[index].index = index;
    }
  }

 private:
  slot *table_;
  int size_;
  int capacity_;
  int head_;
  int tail_;
};

int main(int argc, char *argv[]) { return 0; }
