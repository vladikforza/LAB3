// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_SHARE_POINT_HPP_
#define INCLUDE_SHARE_POINT_HPP_

#include <iostream>

template <typename T>
class Shared_point {
 public:
  Shared_point();
  explicit Shared_point(T* ptr);
  Shared_point(Shared_point<T>& other);
  Shared_point<T> operator= (Shared_point<T>& other);
  ~Shared_point();
  size_t use_count() const;
  bool unique() const;
 private:
  T* ptr;
  size_t *count;
};

template<typename T>
Shared_point<T>::Shared_point(){
  ptr = nullptr;
  count = nullptr;
}

template<typename T>
Shared_point<T>::Shared_point(T* _ptr)
{
  ptr = _ptr;
  count = new size_t(1);
}

template<typename T>
Shared_point<T>::Shared_point(Shared_point<T>& other){
  count = other.count;
  ptr = other.ptr;
  (*count)++;
}

template<typename T>
Shared_point<T> Shared_point<T>::operator=(Shared_point<T>& other){
  if (this != &other) {
    if (*count == 1) {
      delete count;
      delete ptr;
    } else {
      (*count)--;
    }
    ptr = other.ptr;
    count = other.count;
    (*count)++;
  }
  return *this;
}

template<typename T>
Shared_point<T>::~Shared_point(){
  if (count) {
    if (*count == 1) {
      delete count;
      delete ptr;
    } else {
      (*count)--;
    }
  }
}

template<typename T>
size_t Shared_point<T>::use_count() const{
  return (count) ? *count : 0;
}

template<typename T>
bool Shared_point<T>::unique() const{
  return (*count == 1);
}

#endif // INCLUDE_SHARE_POINT_HPP_
