#ifndef STRING_HH
#define STRING_HH
#include <cstring>

class String {
   public:
    String(const char* str = "") : _s(0) { insert(str); }
    String(const String& a) : _s(0) { insert(a._s); }
    ~String() { delete[] _s; }

    String operator=(const String& other) {
        if (this != &other) {
            insert(other._s);
        }
        return *this;
    };

    String& operator+=(const String& other);

    operator const char*() const {
        return _s;
    }

    String& operator()(int start, int stop) {
        int l = stop-start+1;
        if ((stop <= _len) && (start >= 0)) {
            char* temp = new char[l+1];
            for (int i = start; i < stop+1; i++) {
                temp[i-start] = _s[i];
            }
            temp[l] = '\0';
            if (_s) delete[] _s;
            _s = temp;
            _len = l;
            return *this;
        }
        return *this; // This should actually return an error, instead we just return unmodified object
    }

    int length() const { return _len; }
    const char* data() const { return _s; }

   private:
    char* _s;
    int _len;

    void insert(const char* str) {  // private helper function
        _len = strlen(str);
        if (_s) delete[] _s;
        _s = new char[_len + 1];
        strcpy(_s, str);
    }
};

String operator+(const String&, const String&);

#endif
