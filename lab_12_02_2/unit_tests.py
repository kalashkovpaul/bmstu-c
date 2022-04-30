import py_array_lib

def test_with_zero():
    error_count = 0
    result = py_array_lib.fill_array_with_fib(0)
    if len(result) != 0:
        error_count += 1
    return error_count

def test_with_one():
    error_count = 0
    result = py_array_lib.fill_array_with_fib(1)
    if len(result) != 1 or result[0] != 0:
        error_count += 1
    return error_count

def test_with_five():
    error_count = 0
    result = py_array_lib.fill_array_with_fib(5)
    if result != [0, 1, 1, 2, 3]:
        error_count += 1
    return error_count

def test_fill_array_with_fib():
    error_count = 0
    error_count += test_with_zero()
    error_count += test_with_one()
    error_count += test_with_five()
    return error_count

def test_with_unique():
    error_count = 0
    result = py_array_lib.transer_unique((1, 2, 3, 4, 5))
    if result != [1, 2, 3, 4, 5]:
        error_count += 1
    return error_count

def test_with_one_not_unique():
    error_count = 0
    result = py_array_lib.transer_unique((1, 2, 3, 4, 5, 3))
    if result != [1, 2, 3, 4, 5]:
        error_count += 1
    return error_count

def test_with_all_not_unique():
    error_count = 0
    result = py_array_lib.transer_unique((1, 2, 3, 4, 5, 5, 4, 3, 2, 1))
    if result != [1, 2, 3, 4, 5]:
        error_count += 1
    return error_count


def test_transfer_unique():
    error_count = 0
    error_count += test_with_unique()
    error_count += test_with_one_not_unique()
    error_count += test_with_all_not_unique()
    return error_count      

def test_with_unique_second():
    error_count = 0
    result = py_array_lib.transer_unique_second((1, 2, 3, 4, 5))
    if result != [1, 2, 3, 4, 5]:
        error_count += 1
    return error_count

def test_with_one_not_unique_second():
    error_count = 0
    result = py_array_lib.transer_unique_second((1, 2, 3, 4, 5, 3))
    if result != [1, 2, 3, 4, 5]:
        error_count += 1
    return error_count

def test_with_all_not_unique_second():
    error_count = 0
    result = py_array_lib.transer_unique_second((1, 2, 3, 4, 5, 5, 4, 3, 2, 1))
    if result != [1, 2, 3, 4, 5]:
        error_count += 1
    return error_count


def test_transfer_unique_second():
    error_count = 0
    error_count += test_with_unique_second()
    error_count += test_with_one_not_unique_second()
    error_count += test_with_all_not_unique_second()
    return error_count      

def main():
    error_count = 0
    error_count += test_fill_array_with_fib()
    error_count += test_transfer_unique()
    error_count += test_transfer_unique_second()
    print(error_count)

main()