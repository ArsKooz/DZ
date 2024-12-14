#include "lib.h"
#include <cassert>
#include <iostream>
#include <cstring>


size_t count_fsize(const char* filePath)
{
    FILE *file = fopen(filePath, "rb");

    assert(file != nullptr && "проблемы с файлом в count_fsize");
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fclose(file);
    return file_size;
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
        if (std::strcmp(arr[j], pivot) < 0) {
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