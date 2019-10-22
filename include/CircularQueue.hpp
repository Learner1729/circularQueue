#pragma once

#include <cstddef>

using namespace std;

/**
 * A ring-buffer with a fixed capacity.
 */
template <typename T> class CircularQueue {
public:
  /** Construct a queue with the capacity */
  CircularQueue(int capacity = 1);

  /** Reallocate the pointer */
  ~CircularQueue() { delete[] _ptr; }

  /**
   * Insert a vector to the back of the queue..... 
   * NOTE: Based on function definition, I have considered inserting a
   * element to the back of the queue
   * If the buffer is full, then the element is not inserted.
   *
   * Runtime: O(1) with no memory allocation required.
   *
   * @return Whether the element is inserted.
   */
  bool push(const T &v);

  /**
   *  Remove and return the element from the head of the queue by
   *  copying into the provided pointer.
   *
   * Runtime: O(1) with no memory allocation required.
   *
   *  If the queue is empty, return false.
   */
  bool pop(T *v);

  /**
   * Check whether the queue is empty
   */
  bool isEmpty() { return (_front == -1 && _rear == -1); }

  /**
   * Check whether the queue is full
   */
  bool isFull() { return ((_rear + 1) % _size == _front); }

  /** 
   * Current number of elements in the queue
   *
   * Runtime: O(1) with no memory allocation required.
   */
  int size() const {  return _currentCount; }

  /**
   * Maximum capacity of the ring-buffer.
   *
   * Runtime: O(1) with no memory allocation required.
   */
  int capacity() const { return _size; }

 private:
  int _size; // stores the maximum capacity of the queue
  int _rear; // points to the first element of the queue
  int _front; // points to the last element of the queue
  int _currentCount; // total number of elements currently in the queue
  T *_ptr; // queue pointer
};

template <typename T> 
CircularQueue<T>::CircularQueue(int capacity) {
  _size = capacity;
  _ptr = new T[_size];
  _front = -1;
  _rear = -1;
  _currentCount = 0;
}

template <typename T> 
bool CircularQueue<T>::push(const T &v) {
  if(isFull()) {
    cout << "Queue full!!" << "\n";
    return false;
  } else if (isEmpty()) {
      _rear = 0;
      _front = 0;
  } else {
      _rear = (_rear + 1) % _size;
  }
  _ptr[_rear] = v;
  cout << "Adding " << v << "\n";
  _currentCount += 1;
  return true;
}

template <typename T>
bool CircularQueue<T>::pop(T *v) {
  T element;
  if(isEmpty()) {
    return false;
  } else if(_front == _rear) {
    element = _ptr[_front];
    cout << "Removing " << _ptr[_front] << "\n";
    _front = -1;
    _rear = -1;
  } else {
    element = _ptr[_front];
    cout << "Removing " << _ptr[_front] << "\n";
    _front = (_front + 1) % _size;
  }
  *v = element;
  _currentCount -= 1;
  return true;
}
