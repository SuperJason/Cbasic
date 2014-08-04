#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char g_string[] = "abcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffgggggghijkllll";

#if 0
#define deb_prt printf
#else
#define deb_prt
#endif

char *num_to_str(char *p, int num)
{
  char *p_end = p;
  char *p_start = p;
  char *p_move;
  int digit_value = 0;

  deb_prt(" -- %s() line: %d, p(0x%X): %c, num: %d\n", __func__, __LINE__, p, *p, num);

  if (num <= 0) {
    return p_end;
  }

  digit_value = num % 10;
  num = num / 10;
  *p_start = digit_value + '0';
  p_end++;

  while (num > 0) {
    for (p_move = p_end; p_move > p_start; p_move--) {
      *p_move = *(p_move - 1) ;
    }
    digit_value = num % 10;
    num = num / 10;
    *p_start = digit_value + '0';
    p_end++;
  }

  deb_prt(" -- %s() line: %d, p_end(0x%X): %c\n", __func__, __LINE__, p_end, *p_end);
  return p_end;

}

int compress_string(char *str)
{
  int count = 1;
  char *p_new_str = str + 1;
  char *p_ori_str = str + 1;
  char current_char = *str;

  while ('\0' != *p_ori_str) {
    deb_prt(" -- %s() line: %d, current_char: %c, p_new_str(0x%X): %c, p_ori_str(0x%X): %c\n", __func__, __LINE__, current_char, p_new_str, *p_new_str, p_ori_str, *p_ori_str);
    if(current_char != *p_ori_str) {
      current_char = *p_ori_str;
      if (count > 1) {
        p_new_str = num_to_str(p_new_str, count);
        count = 1;
      }
      *p_new_str = *p_ori_str;
      p_new_str++;
    } else {
      count++;
    }
    p_ori_str++;
  }

  if (count > 1) {
    p_new_str = num_to_str(p_new_str, count);
  } 
  *p_new_str = '\0';

  return 0;
}

int main(int argc, char *argv[])
{
  char *p_string;
  int str_len = strlen(g_string);

  p_string = malloc(str_len + 1);
  memset(p_string, 0, str_len + 1);
  strcpy(p_string, g_string);

  printf("origin string: %s\n", p_string);
  compress_string(p_string);
  printf("string after compress: %s\n", p_string);

  return 0;
}
