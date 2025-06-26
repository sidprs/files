#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class RingBuffer {
 public:
  explicit RingBuffer(int capacity)
      : head_{0},
        tail_{0},
        size_{0},
        capacity_(capacity),
        data_{new int[capacity]},
        vec_{capacity} {}

  ~RingBuffer() = default;
  RingBuffer(const RingBuffer&) = default;
  RingBuffer& operator=(const RingBuffer&) = default;
  RingBuffer& operator=(RingBuffer&&) = default;

  // 1 2 3 4
  //   T   H

  int pop() {
    // the oldest val
    if (this->size_ == 0) {
      throw new std::logic_error("cant pop dumbass its empty");
    }

    int val = data_[this->head_];
    this->head_ = (this->head_ + 1) % this->capacity_;
    --this->size_;

    return val;
  }

  void push(int val) {
    if (this->size_ == this->capacity_) {
      this->head_ = (this->head_ + 1) % this->capacity_;
    } else {
      this->size_++;
    }
    this->data_[this->tail_] = val;
    this->tail_ = (this->tail_ + 1) % capacity_;
  }

 private:
  int head_;
  int tail_;
  int capacity_;
  int* data_;
  size_t size_;
  std::vector<int> vec_;
};

int main(int argc, char* argv[]) {
  int* a = new int[5];

  RingBuffer r(4);

  r.push(1);
  // r.push(2);
  // r.push(3);
  // r.push(4);
  // r.push(5);
  std::cout << r.pop() << std::endl;

  return 0;
}
