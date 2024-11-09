#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <inttypes.h> 



int strcompare(char* from, char* to);

size_t count_fsize(char* filePath)
{
    size_t _file_size = 0;
    FILE* fd = fopen(filePath, "rb");
    if (fd == NULL) {
        perror("Ошибка при открытии файла");
        return (size_t)-1;
    }
    fseek(fd, 0, SEEK_END);
    _file_size = ftell(fd);
    fclose(fd);
    return _file_size;
}

// возвращает количество строк после почищенных пустых строк подряд
size_t preprocess(char* text) {
    bool lastWasNewline = false;
    char* writePtr = text;
    size_t lineCount = 1;
    for (char* readPtr = text; *readPtr != '\0'; ++readPtr) {
        if (*readPtr == '\n') {
            if (!lastWasNewline) {
                *writePtr++ = '\n';
                lastWasNewline = true;
            }
        }
        else {
            *writePtr++ = *readPtr;
            lastWasNewline = false;
        }
    }

    *writePtr = '\0'; // Завершаем строку

    // Замена всех \n на \0
    for (writePtr = text; *writePtr != '\0'; ++writePtr) {
        if (*writePtr == '\n') {
            lineCount++;
            *writePtr = '\0';
        }
    }

    return lineCount;
}

// НЕ ВЫДЕЛЯЕТ НИКАКУЮ ПАМЯТЬ, ИСПОЛЬЗУЙТЕ С УМОМ
void fill_string_array(char* buf, size_t str_count, char** text)
{
    if ((buf == nullptr) || (text == nullptr))
    {
        return;
    }
    size_t index = 0;
    char* current = buf;
    
    while (index < str_count) {
        text[index] = current;
        index++;
        // Продвигаемся к следующей строке
        while (*current != '\0') {
            current++;
        }
        current++; // Переходим к началу следующей строки
    }
}

void print_text(char** text,size_t str_count) {
    for (size_t i = 0; i< str_count; ++i) {
        //std::cout << "Stroke" << i + 1 << text[i];
        printf("Stroke %zu: %s\n", i + 1, text[i]);
       
    }
}
// Вспомогательная функция для обмена указателей на строки
void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// Функция разбиения для алгоритма quicksort
int partition(char** arr, int low, int high) {
    char* pivot = arr[high]; // Опорный элемент — последний элемент массива
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Сравниваем строки лексикографически
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Реализация quicksort
void quicksort(char** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Индекс опорного элемента
        quicksort(arr, low, pi - 1);  // Рекурсивно сортируем левую часть
        quicksort(arr, pi + 1, high); // Рекурсивно сортируем правую часть
    }
}

int main()
{
    // 1) прочитать размер файла
    size_t file_size = count_fsize((char*)"C:\\Users\\Arseny\\source\\repos\\ConsoleApp1\\Project2\\Onegin.txt");//компилятору не нравилось приведение const char* к char*
    // 2) выделить память под буфер
    char* text_buf = (char*)calloc(1, file_size);
    text_buf[file_size] = '\0';
    // 3) скопировать файл с диска в буффер в оперативной памяти
    FILE* input = fopen("C:\\Users\\Arseny\\source\\repos\\ConsoleApp1\\Project2\\Onegin.txt", "rb");
    fread(text_buf, 1, file_size, input); // надо погуглить как пользоваться этой функцией
    // 4) препроцессинг
    // заменить множество \n подряд на 1 \n, заменить все \n на \0
    size_t str_count = preprocess(text_buf);
    /*for (int i = 0; i < file_size; ++i) {
        if (*(text_buf + i) != '\r')
            std::cout << *(text_buf+i);
    }*/
    
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
