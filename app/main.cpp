// Including the necessary header file
#include <cstddef>
#include <iostream>
#include <CircularQueue.hpp>

using namespace std;

int main() {

  cout << "INT CircularQueue....." << "\n";
  cout << "======================" << "\n";
  // creating a queue of capacity 4
  CircularQueue<int> q1(4);
  int firstElement;
  bool status;

  cout << "Queue size is " << q1.size() << "\n";
  status = q1.push(1);
  status = q1.push(2);
  status = q1.push(3);
  cout << "Queue size is " << q1.size() << "\n";
  q1.pop(&firstElement);
  cout << "Removed Element: " << firstElement << "\n";
  cout << "Queue size is " << q1.size() << "\n";
  status = q1.push(4);
  status = q1.push(5);
  
  cout << "Queue size is " << q1.size() << "\n";

  if (q1.isEmpty())
    cout << "Queue Is Empty\n";
  else
    cout << "Queue Is Not Empty\n";

  status = q1.push(6);

  cout << "string CircularQueue....." << "\n";
  cout << "======================" << "\n";
  CircularQueue<string> q2(4);
  string element;

  cout << "Queue size is " << q2.size() << "\n";
  q2.push("abc");
  q2.push("b");
  q2.push("c");
  cout << "Queue size is " << q2.size() << "\n";
  q2.pop(&element);
  cout << "Removed Element: " << element << "\n";
  cout << "Queue size is " << q2.size() << "\n";
  status = q2.push("d");
  status = q2.push("e");
  
  cout << "Queue size is " << q2.size() << "\n";

  if (q2.isEmpty())
    cout << "Queue Is Empty\n";
  else
    cout << "Queue Is Not Empty\n";
  status = q2.push("f");


  return 0;
}
