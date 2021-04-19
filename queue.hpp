#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  int priority;
  Element *next = nullptr;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> Head, Tail = nullptr;
};




/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q {.Head = nullptr, .Tail = nullptr};
  return q;
}

template <typename T>
bool isEmpty(Queue<T> q) {
  if(q.Head == nullptr && q.Tail == nullptr) return 1;
  else return 0;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> prev, help, newElement = new Element<T>{.data = value, .priority = priority};
  prev = help = q.Head;
  
  if(isEmpty(q)){
    // std::cout<<"empty";
    q.Head = q.Tail = newElement;
  } 
  else{
    while(newElement->priority <= help->priority){
      // std::cout<<"next, ";
      if(help->next == nullptr){ break;}
      prev = help;
      help = help->next;
      
    }
    if(help == q.Head && newElement->priority > help->priority){
      std::cout<<"add head";
      newElement->next = q.Head;
      q.Head = newElement;
    }
    else if(help == q.Tail && newElement->priority < help->priority){
      std::cout<<"add tail";
      q.Tail->next = newElement;
      q.Tail = newElement;
    }
    else{
      std::cout<<"add middle";
      prev->next = newElement;
      if(prev != help) newElement->next = help;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  if(isEmpty(q)) return NULL;
  return q.Head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  if(isEmpty(q)) return;
  if(q.Tail == q.Head){
    std::cout<<"tail = head";
    q.Head = q.Tail = nullptr;
  }
  else{
    std::cout<<"yeees";
    q.Head = q.Head->next;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
