import py_array_lib

import tkinter as tk
import tkinter.messagebox as box

def fill(length):
    global arr
    arr = py_array_lib.fill_array_with_fib(length)
    arr += ['------------------'] * (max_fib_length - length)
    update(0)


def ent(var):
    if var == 0:
        try:
            number = int(ent_entry.get())
            if number <= 0 or number > max_fib_length:
                raise ValueError
            fib_length = number
            ent_entry.delete(0, last='end')
            if fib_length == -1:
                ent_label.config(text='Введите длину массива:')
            else:
                ent_label.config(text='Длина массива введена:')
                ent_entry.insert(0, '{}'.format(fib_length))
                fill(fib_length)
                ent_entry.config(state='readonly')
            update(0)
        except ValueError:
            if ent_entry.get() != '':
                ent_entry.delete(0, last='end')
                box.showwarning(title='Warning!', message='Неправильный ввод! Длина - целое число от 1 до max_fib_length')
    elif var == 1:
        try:
            start_array = list(map(int, start_array_entry.get().split()))
            new_array = py_array_lib.transer_unique(start_array)
            result = ""
            for element in new_array:
                result += (str(element) + " ")
            new_array_entry.config(state='normal')
            new_array_entry.delete(0, last='end')
            new_array_entry.insert(0, result)
            new_array_entry.config(state='readonly')
        except ValueError:
            if (start_array_entry.get() != ''):
                start_array_entry.delete(0, last='end')
                new_array_entry.config(state='normal')
                new_array_entry.delete(0, last='end')
                new_array_entry.config(state='readonly')
                box.showerror(title='Warning!', message='Неправильный ввод! Чтобы ввести массив, водите целые числа через пробел')


def delete(var):
    if var == 0:
        ent_entry.config(state='normal')
        ent_entry.delete(0, last='end')
        fib_length = -1
        ent_label.config(text='Введите длину массива:')
        for j in range(max_fib_length):
            arr[j] = '------------------'
        update(0)
    if var == 1:
        start_array_entry.delete(0, 'end')
        new_array_entry.config(state='normal')
        new_array_entry.delete(0, last='end')
        new_array_entry.config(state='readonly')


def update(var):
    if var == 0:
        for j in range(max_fib_length):
            entry_arr[j].config(state='normal')
            entry_arr[j].delete(0, last='end')
            entry_arr[j].insert(0, str(arr[j]))
            entry_arr[j].config(state='readonly')


def enter(event):
    ent(0)

def enter_array(event):
    ent(1)

max_fib_length = 47
init_fib_length = 10
frame_width = 1500
frame_height = 550

arr = ['------------------'] * max_fib_length
fib_length = init_fib_length
window = tk.Tk()
window.geometry("{}x{}".format(frame_width, frame_height))
window.title("Лаб.12: работа с библиотеками. Задание 2")
main_label = tk.Label(
    master=window,
    font='Times 14',
    text='Задание 1: Инициализация массива числами Фиббоначчи'
)

main_label.grid(row=0, column=0, columnspan=10)

ent_label = tk.Label(
    master=window,
    font='Times 14',
    text='Введите длину массива: '
)
ent_label.grid(row=1, column=0)

ent_entry = tk.Entry(
    master=window,
    font='Times 14',
    width=10
)
ent_entry.bind("<Return>", enter)
ent_entry.grid(row=1, column=1)

del_button = tk.Button(
    master=window,
    font='Times 14',
    text='Очистить',
    command=lambda t=0: delete(t)
)
del_button.grid(row=2, column=0)

ent_button = tk.Button(
    master=window,
    font='Times 14',
    text='Ввод',
    command=lambda t=0: ent(t)
)
ent_button.grid(row=3, column=0)
label_arr = list()
arr_label1 = tk.Label(
    master=window,
    font='Times 14',
    text='a[i]'
)
arr_label1.grid(row=5, column=0)

arr_label2 = tk.Label(
    master=window,
    font='Times 14',
    text='i'
)
arr_label2.grid(row=6, column=0)
label_arr.append(arr_label1)
label_arr.append(arr_label2)
entry_arr = list()
cur_row=5
cur_column = 0
for i in range(max_fib_length):
    label = tk.Label(master=window, font='Times 14', text=str(i))
    label.grid(row=cur_row, column=1+cur_column)
    entry = tk.Entry(master=window, font='Times 14', width=12)
    entry.insert(0, '------------------')
    entry.config(state='readonly')
    entry_arr.append(entry)
    entry.grid(row=cur_row + 1, column=1+cur_column)
    cur_column += 1
    if (i + 1) % 10 == 0 :
        cur_row += 2
        cur_column = 0
        label = tk.Label(master=window, font='Times 14', text='a[i]')
        label.grid(row=cur_row, column=0)
        label_arr.append(label)
        label = tk.Label(master=window, font='Times 14', text='i')
        label.grid(row=cur_row + 1, column=0)
        label_arr.append(label)
        
        
part_two_label = tk.Label(master=window, font='Times 14', text='------------------------------------'
                                                               '-----------------------------------'
                                                               '------------------------------------'
                                                               '-----------------------------------'
                                                               '------------------------------------'
                                                               '-----------------------------------'
                                                               '------------------------------------')
part_two_label.grid(row=24, column=0, columnspan=20)
second_task_label = tk.Label(
    master=window,
    font='Times 14',
    text='Задание 2: Перемещение из одного массива в другой только первые вхождения чисел'
)
second_task_label.grid(row=25, column=0, columnspan=10)

start_array = list()
new_array = list()

start_array_label = tk.Label(
    master=window,
    font='Times 14',
    text='Введите исходный массив:'
)
start_array_label.grid(row=26, column=0)
start_array_entry = tk.Entry(
    master=window,
    font='Times 14',
    width=100
)
start_array_entry.bind("<Return>", enter_array)
start_array_entry.grid(row=26, column=1, columnspan=20)

new_array_label = tk.Label(
    master=window,
    font='Times 14',
    text='Получившийся массив:'
)
new_array_label.grid(row=27, column=0)
new_array_entry = tk.Entry(
    master=window,
    font='Times 14',
    width=100
)
new_array_entry.config(state='readonly')
new_array_entry.grid(row=27, column=1, columnspan=20)

clean_button = tk.Button(
    master=window,
    font='Times 14',
    text='Очистить',
    command=lambda t=1: delete(t)
)
clean_button.grid(row=28, column=0)

transfer_button = tk.Button(
    master=window,
    font='Times 14',
    text='Сформировать',
    command=lambda t=1: ent(t)
)
transfer_button.grid(row=29, column=0)



window.mainloop()