#include "KSP_reverse_vector.h"

void reverse_vector(std::vector<char>& v, size_t start, size_t end) {
    if (start >= end) {
        return; // 
    }
    char temp = v[start];
    v[start] = v[end];
    v[end] = temp;
    reverse_vector(v, start + 1, end - 1); // recursive call
}

void reverse_vector(std::vector<char>& v) {
    reverse_vector(v, 0, v.size() - 1);
}

