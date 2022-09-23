#include<iostream>
#include<string>
#include<cstring>

class String {
private:
    char* str;
    size_t size;
    size_t capacity;

    void resize(int new_capacity);  //ќн будет увеличивать capacity в 2 раза
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
    // дописать все методы
    String tolower()const;
    String toupper()const;
    void reverse(int start, int end);
    int find(const String& other);
};

String::String(const char* s): 
    size(strlen(s)), capacity(size*2), str(new char[strlen(s)*2]){ 
    for (int i = 0; i < size; ++i) {
        str[i] = s[i];
    }
}
String::String(const String& s) {
    size = s.size;
    capacity = s.capacity;
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
    size = other.size;
    capacity = other.capacity;
    for (int i = 0; i < size; ++i) {
        str[i] = other.str[i];
    }
    return *this;
}

int main() {
    String s = "jdfhgj";
    s.print();

    return 0;
}