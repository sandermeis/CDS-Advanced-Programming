#ifndef ARRAY_HH
#define ARRAY_HH

class Array {
public:

  Array(int size) : _size(size) {
    _arr = new double[_size] ;
  }


  Array(const Array& other) : _size(other._size) {
    _arr = new double[other._size] ;

    // Copy elements
    for (int i=0 ; i<_size ; i++) {
      _arr[i] = other._arr[i] ;
    }
  }

  ~Array() {
    delete[] _arr ;
  }


  Array& operator=(const Array& other) 
  {
    if (&other==this) return *this ;
    if (_size != other._size) {
      resize(other._size) ;
    }
    for (int i=0 ; i<_size ; i++) {
      _arr[i] = other._arr[i] ;
    }
    return *this ;
  }

  double& operator[](int index) {
    return _arr[index] ;
  }
  const double& operator[](int index) const {
    return _arr[index] ;
  }

  int size() const { return _size ; }

  void resize(int newSize) {
    // Allocate new array
    double* newArr = new double[newSize] ;

    // Copy elements
    for (int i=0 ; i<_size ; i++) {
      newArr[i] = _arr[i] ;
    }

    // Delete old array and install new one
    delete[] _arr ;
    _size = newSize ;
    _arr = newArr ;
  }


private:
  int _size ;
  double* _arr ;
} ;

#endif
