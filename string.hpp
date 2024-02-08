#pragma once
#include<iosfwd>
#include <cstring> // For strlen, strcpy, etc.
#include <iostream>
using namespace std;

class String{
private:
    char* buf; 
    explicit String(int length);
public:
    explicit String(const char* s = "");

    String(const String& s);


    void swap(String& s);

    String& operator=(String s);

 
    char& operator[](int index);

    const char& operator[](int index) const;

    int size() const;

    String reverse() const;

    int indexOf(char c) const;

    int indexOf(String s) const;

    bool operator==(String s) const;
    bool operator!=(String s) const;
    bool operator<(String s) const;
    bool operator<=(String s) const;
    bool operator>(String s) const;
    bool operator>=(String s) const;

    String operator+(String s) const;

    String& operator+=(String s);

    void print(ostream& out) const;

  
    void read(istream& in);

    ~String();

    bool in_bounds(int i) const {
        return i >= 0 && i < strlen(buf);
    }

  
    static char* strcpy(char* dest, const char* src);
    static char* strdup(const char* src);
    static char* strncpy(char* dest, const char* src, int n);
    static char* strcat(char* dest, const char* src);
    static char* strncat(char* dest, const char* src, int n);
    static int strcmp(const char* left, const char* right);
    static int strncmp(const char* left, const char* right, int n);
    static void strrev(char* dest, const char* src);
    static const char* strchr(const char* str, char c);
    static const char* strstr(const char* haystack, const char* needle);
};

ostream& operator<<(ostream& out, String s);
istream& operator>>(istream& in, String& s);
