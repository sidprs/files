#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct node {
  T value;
  int index;
};

template <typename T>
class RingBuffer {
 public:
  RingBuffer();
  ~RingBuffer();
  void pushNode(node<T>);
  void popFront();
  node<T> findAtIndexNode(int index);

 private:
  std::vector<node<T>> elements;
};

int main() { return 0; }
