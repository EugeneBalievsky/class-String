#include<iostream>
#include<string>
#include<cstring>

class String {
private:
    char* str;
    size_t size;
    size_t capacity;

    void resize(int new_capacity);
public:
    String() : size(1), capacity(1), str(new char[capacity]) {
    }
    String(const char* s);
    String(const String& s);
    ~String();

    String& operator=(const String& other);

    friend bool operator==(const String& left, const String& right);
    friend bool operator<(const String& left, const String& right);
    friend bool operator!=(const String& left, const String& right);
    friend bool operator<=(const String& left, const String& right);
    friend bool operator>=(const String& left, const String& right);
    friend bool operator>(const String& left, const String& right);

    friend String operator+(const String& left, const String& right);
    friend String operator+(const String& left, char c);
    String& operator+=(const String& right);
    String& operator+=(char c);

    void print();
    //ћетод должен вернуть новую строку, в которой все буквы верхнего регистра стали буквами нижнего регистра
    String tolower()const;

    //ћетод должен вернуть новую строку, в которой все буквы верхнего регистра стали буквами верхнего регистра
    String toupper()const;

    //–азворот строки
    void reverse(int start, int end);   //pos - с какой позиции, end - по какую (включительно)

    //»щет первое вхождение строки other в строку, к которой примен€етс€ метод.
    //≈сли вхождени€ нет - то возвращаем -1
    /*
     ѕример:
     String s = "abcbabccc";
     String other = "bab";
     std::cout << s.find(); //¬ыведет 3
     */
    int find(const String& other);

};

String::String(const char* s) :
    size(strlen(s)), capacity(size * 2), str(new char[strlen(s) * 2]) {
    for (int i = 0; i < size; ++i) {
        str[i] = s[i];
    }
}
String::String(const String& s) :
    size(s.size), capacity(s.capacity), str(new char[s.capacity]) {
    for (int i = 0; i < size; ++i) {
        str[i] = s.str[i];
    }

}
void String::resize(int new_capacity) {
    capacity = new_capacity;
    char* new_str = new char[capacity];
    for (int i = 0; i < size; ++i) {
        new_str[i] = str[i];
    }
    delete[] str;
    str = new_str;
}
String::~String() {
    delete[] str;
}
void String::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << str[i];
    }
    std::cout << '\n';
}
String& String::operator=(const String& other) {
    if (str = other.str) {
        return *this;
    }
    String new_string;
    new_string.size = other.size;
    new_string.capacity = other.capacity;
    for (int i = 0; i < size; ++i) {
        new_string.str[i] = other.str[i];
    }
    return new_string;
}
bool operator == (const String& left, const String& right) {
    if (left.size == right.size) {
        for (int i = 0; i < left.size; ++i) {
            if (left.str[i] != right.str[i]) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}
bool operator != (const String& left, const String& right) {
    return !(left == right);
}
bool operator < (const String& left, const String& right) {
    if (left == right) {
        return false;
    }
    for (int i = 0; i < std::max(left.size, right.size); ++i) {
        if (left.str[i] > right.str[i]) {
            return false;
        }
    }
    return true;
}
bool operator <=(const String& left, const String& right) {
    return left == right || left < right;
}
bool operator > (const String& left, const String& right) {
    return !(left <= right);
}
bool operator >= (const String& left, const String& right) {
    return !(left < right);
}
String operator+(const String& left, const String& right) {
    String s;
    s.size = left.size + right.size;
    s.capacity = left.capacity + right.capacity;
    s.str = new char[s.capacity];
    for (int i = 0; i < left.size ; ++i) {
        s.str[i] = left.str[i];
    }
    for (int i = left.size; i < s.size; ++i) {
        s.str[i] = right.str[i- left.size];
    }
    return s;
}
String operator+(const String& left, char c) {
    String s;
    s.size = left.size + 1; 
    s.capacity = left.capacity + 1;
    s.str = new char[s.capacity];
    for (int i = 0; i < s.size - 1; ++i) {
        s.str[i] = left.str[i];
    }
    s.str[s.size - 1] = c;
    return s;
}
String& String::operator += (const String& right) {
    
    return *this;
}
String& String:: operator+=(char c) {
    *this = *this + c;
    return *this;
}

int main() {
    String s = "kjhh";
    String ss("acdsahkh");
    s.print();
    ss.print();

    if (s > ss) {
        std::cout << "yes"<<'\n';
    }
    else
        std::cout << "no"<<'\n';

    String dd = s + ss;
    dd.print();

    String d = ss + 'a';
    d.print();

    d += 's';
    d.print();



    return 0;
}