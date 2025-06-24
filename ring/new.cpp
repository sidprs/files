#include <iostream>
#include <vector>

using namespace std;

class RingBuffer {
 public:
  explicit RingBuffer(size_t capacity)
      : capacity_{capacity},
        data_{new int[capacity]},
        size{0},
        head{0},
        tail{0} {}

  // rule of 5
  // default, parameterized, move, copy, delete

 private:
  int capacity;
  int size;
  int head;
  int tail;
  int capacity_;
  int data[capacity];
};

int main() { return 0; }
