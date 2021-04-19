/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 */

#include <iostream>

#include "queue.hpp"

using namespace strukdat::priority_queue;

void REQUIRE(bool x){
  if(x) std::cout<<"TRUE\n";
  else std::cout<<"FALSE\n";
}

int main()
{
  auto q = new_queue<int>();
  enqueue(q, 1, 5);//3 1 4 2 5
  std::cout<<top(q);
  enqueue(q, 2, 3);
  std::cout<<top(q);
  enqueue(q, 3, 7);
  std::cout<<top(q);
  enqueue(q, 4, 5);
  std::cout<<top(q);
  enqueue(q, 5, 1);
  std::cout<<top(q);

  dequeue(q);//1 4 2 5
  REQUIRE(top(q) == 1);

  dequeue(q);//4 2 5
  std::cout<<top(q);
  REQUIRE(top(q) == 4);

  dequeue(q);//2 5
  std::cout<<top(q);
  REQUIRE(top(q) == 2);

  dequeue(q);
  REQUIRE(top(q) == 5);
  return 0;
}
