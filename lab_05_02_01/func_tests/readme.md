## **Тесты для лаб.работы №5, Задача 2, Вариант 1**
====
## **Задание**
Написать программу, которая считывает из текстового файла вещественные числа и
выполняет над ними некоторые вычисления согласно варианту. 

При решении задачи массивы не использовать. Имя файла берётся из аргументов командной строки.

Решение любой из этих задач выполняется минимум за два просмотра файла.

1. найти количество чисел, значение которых больше среднего арифметического минимального и максимального чисел;

## Входные данные
Запуск программы из командной строки в формате
```bash
./main.exe <filename>
```

## Выходные данные
Целое число result

## Позитивные тесты

- 01 - в файле содержатся только вещественные положительные числа
- 02 - не только положительные
- 03 - не только числа

## Негативные тесты

- 01 - filename неверно
- 02 - в файле не содержатся числа