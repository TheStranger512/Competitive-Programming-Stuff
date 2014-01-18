/* 
 * 450. Enormous Input Test
 * File:   INTEST.cpp
 * Author: Andy Huang
 * Created on June 15, 2012, 8:35 PM
 */

#include <stdio.h>

namespace Input {

const int buffer_size = 1 << 20;
char input_buffer[buffer_size + 1];
const int char_to_int[58] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47,
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c;
  do {
    c = next_char();
  } while (c < '0');
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return ans;
}

}

namespace Output {
const char digit_to_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const int buffer_size = 1 << 16; //make sure its big enough
char output_buffer[buffer_size];
unsigned int output_index = 0;

inline void write_flush() {
  fwrite(output_buffer, sizeof (char) , output_index, stdout);
  output_index = 0;
}

inline void write_char(char c) {
  output_buffer[output_index++] = c;
}

inline void write_int(int num) {
  if (num >= 10)
    write_int(num / 10);
  write_char(digit_to_char[num % 10]);
}

}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n, k;
  n = Input::next_int();
  k = Input::next_int();
  int cur, ans = 0;
  ;
  while (n--) {
    cur = Input::next_int();
    if (cur % k == 0)
      ans++;
  }
  Output::write_int(ans);
  Output::write_flush();
  return 0;
}

