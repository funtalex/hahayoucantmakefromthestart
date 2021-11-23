#ifndef BIGINT_H
#define BIGINT_H
#include <vector>
#include <iostream>
#include <vector>

class BigInteger {
public:
  //constructors
  BigInteger() {}
  BigInteger(int num) : num_present(std::vector<int>(1) = { num }), cnt_digits(1), capacity(1) {}
  
  //add operations
  BigInteger& operator+=(const BigInteger& add) {
    int carry = 0;
    for (size_t i = 0; i < max(cnt_digits, add.cnt_digits); ++i) {
      int cur_sum = get(i) + get(add, i) + carry;
      carry = cur_sum / num_system;
      put(i, cur_sum % num_system);
    }
    if (!carry)
      put(cnt_digits, carry);
  }
  //comparison operators
  friend bool operator<(const BigInteger&, const BigInteger&);
  friend bool operator==(const BigInteger&, const BigInteger&);

  BigInteger& operator-=(const BigInteger& sub) {
    int carry = 0;
    if (*this >= sub) {
      for (size_t i = 0; i < cnt_digits; ++i) {
        int cur_res = num_present[i] + carry;
        if (i < sub.cnt_digits)
          cur_res -= sub.num_present[i];
        if (cur_res < 0) {
          carry = -1;
          cur_res += num_system;
        }
        else {
          carry = 0;
        }
        num_present[i] = cur_res;
      }
    }
    else {
      put
    }
  }

private:
  std::vector<int> num_present;
  size_t cnt_digits = 0;
  size_t capacity = 0;
  size_t num_system = 1e9;

  int max(int a, int b) {
    if (a > b)
      return a;
    return b;
  }

  void put(size_t i, int value) {
    if (i < capacity)
      num_present[i] = value;
    else {
      num_present.push_back(value);
      ++capacity;
      ++cnt_digits;
    }
  }

  int get(size_t i) {
    if (i < cnt_digits) {
      return num_present[i];
    }
    else {
      return 0;
    }
  }
  int get(const BigInteger& num, size_t i) {
    if (i < num.cnt_digits) {
      return num.num_present[i];
    }
    else {
      return 0;
    }
  }
};

BigInteger operator+(const BigInteger& first, const BigInteger& second) {
  BigInteger copy = first;
  copy += second;
  return copy;
}

bool operator<(const BigInteger& first, const BigInteger& second) {
  if (first.num_present.size() < second.num_present.size())
    return true;
  if (first.cnt_digits > second.cnt_digits)
    return false;
  for (int i = first.cnt_digits - 1; i >= 0; ++i) {
    if (first.num_present[i] != second.num_present[i]) {
      return first.num_present[i] < second.num_present[i];
    }
  }
  return false;
}

bool operator>(const BigInteger& first, const BigInteger& second) {
  return second < first;
}

bool operator==(const BigInteger& first, const BigInteger& second) {
  if (first.cnt_digits != second.cnt_digits)
    return false;
  for (size_t i = 0; i < first.cnt_digits; ++i) {
    if (first.num_present[i] != second.num_present[i])
      return false;
  }
  return true;
}

bool operator!=(const BigInteger& first, const BigInteger& second) {
  return !(first == second);
}

bool operator<=(const BigInteger& first, const BigInteger& second) {
  return (first == second || first < second);
}

bool operator>=(const BigInteger& first, const BigInteger& second) {
  return (second < first || first == second);
}

#endif BIGINT_H
