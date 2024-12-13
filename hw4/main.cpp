#include "lib.h"

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <inttypes.h> 

int main()
{
    // 1) прочитать размер файла
    size_t file_size = count_fsize("Onegin.txt");//компилятору не нравилось приведение const char* к char*
    // 2) выделить память под буфер
    char* text_buf = (char*)calloc(1, file_size);
    text_buf[file_size] = '\0';
    // 3) скопировать файл с диска в буффер в оперативной памяти
    FILE *input = fopen("Onegin.txt", "rb");
    fread(text_buf, 1, file_size, input); // надо погуглить как пользоваться этой функцией
    // 4) препроцессинг
    // заменить множество \n подряд на 1 \n, заменить все \n на \0
    size_t str_count = preprocess(text_buf);
    
    // 5) время заводить массив
    char** text = (char**)calloc(str_count, sizeof(char*));
    // 6) заполняем массив
    fill_string_array(text_buf, str_count, text);
    // 7) сортировать массив с помощью qsort
    // qsort(); // нужно грамотно вызвать эту функци
    quicksort(text, 0, str_count - 1);
    // 8) вывести массив
    print_text(text,str_count);
    return 0;
}
