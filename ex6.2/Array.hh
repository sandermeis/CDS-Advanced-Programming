#ifndef ARRAY_HH
#define ARRAY_HH
#include <iostream>

template<class T>
class Array {
   public:
    Array(int size,T def) : _size(size),_default(def) {
        _arr = new T[_size];
    }

    Array(const Array& other) : _size(other._size),_default(other._default) {
        _arr = new T[other._size];

        // Copy elements
        for (int i = 0; i < _size; i++) {
            _arr[i] = other._arr[i];
        }
    }

    ~Array() {
        delete[] _arr;
    }

    Array& operator=(const Array& other) {
        if (&other == this) return *this;
        _default=other._default;
        if (_size != other._size) {
            resize(other._size);
        }
        for (int i = 0; i < _size; i++) {
            _arr[i] = other._arr[i];
        }
        return *this;
    }

    T& operator[](int index) {
      if(index>_size){
        resize(index);
      }
        return _arr[index];
    }

    int size() const { return _size; }

    void resize(int newSize) {
        // Allocate new array
        T* newArr = new T[newSize];

        // Copy elements
        for (int i = 0; i < newSize+1; i++) {
          if (i < _size){
            newArr[i] = _arr[i];
          } else {
            newArr[i] = _default;
          }
        }

        // Delete old array and install new one
        delete[] _arr;
        _size = newSize;
        _arr = newArr;
    }

   private:
    int _size;
    T* _arr;
    T _default;
};

#endif
