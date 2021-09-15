## **Тесты к лаб. работе №5, Задание 3**

## Формулировка задания

В этой задаче нет вариантов, номера варианта в названии папки нет. Требуется напи-
сать программу, совершающую действие над двоичным файлом целых чисел int в ответ
на вызов с ключом:

1. создавать файл и заполнять его случайными числами (аргументы в произвольной
форме, например, app.exe c number file; создание не проверяется :));

2. выводить числа из файла на экран (app.exe p file);

3. упорядочивать числа в файле (app.exe s file).

Прежде чем приступать к реализации сортировки файла, необходимо реализовать
функцию get_number_by_pos, которая по заданной позиции позволяет прочитать число
в указанной позиции, и функцию put_number_by_pos, которая позволяет записать число
на указанную позицию с затиранием. Функцию упорядочивания необходимо реализовать
с использованием этих функций.
В начале файла, содержащего исходный код программы, должен располагаться мно-
гострочный комментарий, в котором необходимо указать детали реализации этой задачи:
как минимум, выбранные целочисленный тип, алгоритм сортировки, «направление» упо-
рядочивания.

## Запуск программы
Скомпилируем программу при помощи команды
```bash
gcc -std=c99 -Wall -Werror -Wfloat-equal -Wvla -Wfloat-conversion -g3 main.c c_file_binary.c p_file_binary.c s_file_binary.c check_file_size.c
```
Программа имеет 3 режима:

1) Создание файла. Запуск при помощи 
```bash
./a.exe c <number_of_elements> <file_name>
```

2) Вывод данных из файла. Запуск при помощи
```bash
./a.exe p <file_name>
```

3) Сортировка чисел. Запуск при помощи
```bash
./.a.exe s <file_name>
```

## Позитивные тесты

Примечание: 1 режим программы тестируется вручную при помощи просмотра файла посредством 2 режима. Протестировать 1 режим не получится в силу случайности того, что наполняет файл.

- 01 - проверка вывода бинарного файла, 10 чисел
- 02 - 1 число

Примечание: 3 режим программы протестирован вручную. Входные данные:
- 01 - файл с 1 числом
- 02 - файл с 2 числами
- 03 - файл с 10 числами

## Негативные тесты

- 01 - проверка 2-го режима: неверно переданное имя файла
- 02 - проверка 2-го режима: не подходящий для операции файл
- 03 - проверка 3-го режима: неверно переданное имя файла
- 04 - неверные аргументы в командной строке