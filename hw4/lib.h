#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>



size_t count_fsize(const char* filePath);

// Возвращает количество строк после почищенных пустых строк подряд
size_t preprocess(char* text);

// НЕ ВЫДЕЛЯЕТ НИКАКУЮ ПАМЯТЬ, ИСПОЛЬЗУЙТЕ С УМОМ
void fill_string_array(char* buf, size_t str_count, char** text);

void print_text(char** text, size_t str_count);

// Функция разбиения для алгоритма quicksort
int partition(char** arr, int low, int high);

// Реализация quicksort
void quicksort(char** arr, int low, int high);