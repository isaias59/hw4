#include "string.hpp"
#include "gtest/gtest.h"

TEST(StringFunction, strlen) {
    const char* str = "Hello";
    ASSERT_EQ(String::strlen(str), 5);
}

TEST(StringFunction, strcpy) {
    const char* src = "Hello";
    char dest[10];
    String::strcpy(dest, src);
    ASSERT_STREQ(dest, "Hello");
}

TEST(StringFunction, strdup) {
    const char* source = "Hello, world!";
    char* duplicated = String::strdup(source);
    
    ASSERT_NE(duplicated, nullptr);
    
    ASSERT_STREQ(duplicated, source);
    
    std::free(duplicated);
}

TEST(StringFunction, strncpy) {
    const char* src = "Hello";
    char dest[10];
    String::strncpy(dest, src, 3);
    ASSERT_STREQ(dest, "Hel");
}

TEST(StringFunction, strcat) {
    char dest[10] = "Hello";
    const char* src = ", world!";
    String::strcat(dest, src);
    ASSERT_STREQ(dest, "Hello, world!");
}

TEST(StringFunction, strncat) {
    char dest[15] = "Hello";
    const char* src = ", world!";
    String::strncat(dest, src, 3);
    ASSERT_STREQ(dest, "Hello, w");
}

TEST(StringFunction, strcmp) {
    const char* str1 = "Hello";
    const char* str2 = "Hello";
    ASSERT_EQ(String::strcmp(str1, str2), 0);
}

TEST(StringFunction, strncmp) {
    const char* str1 = "Hello";
    const char* str2 = "Hello";
    ASSERT_EQ(String::strncmp(str1, str2, 3), 0);
}

TEST(StringFunction, reverse_cpy) {
    const char* src = "Hello";
    char dest[10];
    String::reverse_cpy(dest, src);
    ASSERT_STREQ(dest, "olleH");
}

TEST(StringFunction, strchr) {
    const char* str = "Hello";
    ASSERT_STREQ(String::strchr(str, 'e'), "ello");
}

TEST(StringFunction, strstr) {
    const char* str = "Hello, world!";
    ASSERT_STREQ(String::strstr(str, "world"), "world!");
}

