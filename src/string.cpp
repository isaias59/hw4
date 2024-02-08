#include "string.hpp"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stdexcept>


char* String::strcpy(char* dest, const char* src) {
    char* save = dest;
    while ((*dest++ = *src++));
    return save;
}

char* String::strdup(const char* src) {
    char* dup = new char[strlen(src) + 1];
    strcpy(dup, src);
    return dup;
}

char* String::strncpy(char* dest, const char* src, int n) {
    char* save = dest;
    while (n-- && (*dest++ = *src++));
    *dest = '\0';
    return save;
}

char* String::strcat(char* dest, const char* src) {
    strcpy(dest + strlen(dest), src);
    return dest;
}

char* String::strncat(char* dest, const char* src, int n) {
    strncpy(dest + strlen(dest), src, n);
    dest[strlen(dest) + n] = '\0';
    return dest;
}

int String::strcmp(const char* left, const char* right) {
    while (*left && (*left == *right)) {
        left++;
        right++;
    }
    return *(const unsigned char*)left - *(const unsigned char*)right;
}

int String::strncmp(const char* left, const char* right, int n) {
    while (n-- && *left && (*left == *right)) {
        left++;
        right++;
    }
    return n < 0 ? 0 : *(const unsigned char*)left - *(const unsigned char*)right;
}

void String::strrev(char* dest, const char* src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i) {
        dest[i] = src[len - 1 - i];
    }
    dest[len] = '\0';
}

const char* String::strchr(const char* str, char c) {
    while (*str != c && *str) str++;
    return (*str) ? str : nullptr;
}

const char* String::strstr(const char* haystack, const char* needle) {
    if (!*needle) return haystack;
    const char* p1;
    const char* p2;
    const char* p1_advance = haystack;
    for (p2 = &needle[1]; *p2; ++p2) {
        p1_advance++; 
    }
    for (p1 = haystack; *p1_advance; p1++) {
        bool matched = true;
        for (p2 = needle; *p2; ++p2) {
            if (*(p1 + (p2 - needle)) != *p2) {
                matched = false;
                break;
            }
        }
        if (matched) return p1;
    }
    return nullptr;
}


String::String(const char* s) : buf(strdup(s)) {}

String::String(const String& s) : buf(strdup(s.buf)) {}

String::String(int length) : buf(new char[length + 1]) {
    buf[length] = '\0';
}

String::~String() {
    delete[] buf;
}

String& String::operator=(String s) {
    swap(s);
    return *this;
}

void String::swap(String& s) {
    std::swap(buf, s.buf);
}

char& String::operator[](int index) {
    if (!in_bounds(index)) throw std::out_of_range("Index out of range");
    return buf[index];
}

const char& String::operator[](int index) const {
    if (!in_bounds(index)) throw std::out_of_range("Index out of range");
    return buf[index];
}

int String::size() const {
    return strlen(buf);
}

String String::reverse() const {
    String temp(size());
    strrev(temp.buf, buf);
    return temp;
}

int String::indexOf(char c) const {
    const char* result = strchr(buf, c);
    return result ? result - buf : -1;
}

int String::indexOf(String s) const {
    const char* result = strstr(buf, s.buf);
    return result ? result - buf : -1;
}

bool String::operator==(String s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(String s) const {
    return !(*this == s);
}

bool String::operator<(String s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>(String s) const {
    return s < *this;
}

bool String::operator<=(String s) const {
    return !(s < *this);
}

bool String::operator>=(String s) const {
    return !(*this < s);
}

String String::operator+(String s) const {
    String temp(size() + s.size());
    strcpy(temp.buf, buf);
    strcat(temp.buf, s.buf);
    return temp;
}

String& String::operator+=(String s) {
    char* new_buf = new char[size() + s.size() + 1];
    strcpy(new_buf, buf);
    strcat(new_buf, s.buf);
    delete[] buf;
    buf = new_buf;
    return *this;
}

void String::print(std::ostream& out) const {
    out << buf;
}

void String::read(std::istream& in) {
    char buffer[1024]; 
    in >> buffer;
    *this = String(buffer);
}

std::ostream& operator<<(std::ostream& out, String s) {
    s.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}
