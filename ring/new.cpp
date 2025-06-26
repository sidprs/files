// ring_buffer.hpp
#pragma once
#include <cstddef>    // std::size_t
#include <stdexcept>  // std::logic_error

class RingBuffer {
 public:
  explicit RingBuffer(std::size_t capacity)
      : capacity_{capacity},
        data_{new int[capacity]},  // raw array, no STL
        head_{0},
        tail_{0},
        size_{0} {}

  // Rule-of-five – disable copies, allow moves
  RingBuffer(const RingBuffer&) = delete;
  RingBuffer& operator=(const RingBuffer&) = delete;
  RingBuffer(RingBuffer&& other) noexcept { steal(other); }
  RingBuffer& operator=(RingBuffer&& other) noexcept {
    if (this != &other) {
      cleanup();
      steal(other);
    }
    return *this;
  }

  ~RingBuffer() { cleanup(); }

  // true FIFO push; overwrites oldest when full
  void push(int value) {
    this->data_[this->tail_] = value;
    this->tail_ = (this->tail_ + 1) % this->capacity_;

    if (this->size_ < this->capacity_) {
      ++this->size_;
    } else {
      // buffer was full → we just overwrote the oldest element
      this->head_ = (this->head_ + 1) % this->capacity_;
    }
  }

  // pop oldest; O(1)
  int pop() {
    if (this->empty())
      throw std::logic_error("RingBuffer::pop() on empty buffer");

    int value = this->data_[this->head_];
    this->head_ = (this->head_ + 1) % this->capacity_;
    --this->size_;
    return value;
  }

  int front() const { return this->peek_at(this->head_); }
  bool empty() const { return this->size_ == 0; }
  bool full() const { return this->size_ == this->capacity_; }
  std::size_t size() const { return this->size_; }
  std::size_t capacity() const { return this->capacity_; }

 private:
  std::size_t capacity_;
  int* data_;
  std::size_t head_;  // index of oldest element
  std::size_t tail_;  // index of next write
  std::size_t size_;  // number of valid elements

  int peek_at(std::size_t idx) const { return this->data_[idx]; }

  void cleanup() { delete[] this->data_; }

  // move helpers
  void steal(RingBuffer& other) noexcept {
    this->capacity_ = other.capacity_;
    this->data_ = other.data_;
    this->head_ = other.head_;
    this->tail_ = other.tail_;
    this->size_ = other.size_;

    other.data_ = nullptr;
    other.size_ = other.capacity_ = other.head_ = other.tail_ = 0;
  }
};
