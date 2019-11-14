#ifndef STRING_HH
#define STRING_HH

class String {
public:

  String(const char* str="") : _s(0) { insert(str) ; }
  String(const String& a)  : _s(0) { insert(a._s) ; }
  ~String() { delete[] _s ; }

  int length() const { return _len ; }
  const char* data() const { return _s ; }

private:

  char* _s ;
  int _len ;

  void insert(const char* str) { // private helper function
     _len = strlen(str) ;
     if (_s) delete[] _s ; 
     _s = new char[_len+1] ;
    strcpy(_s,str) ;
  }

} ;

#endif 
