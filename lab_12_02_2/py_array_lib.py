import ctypes

lib = ctypes.CDLL('libarray.so')

# void fill_array(double *arr, int n);
_fill_array_with_fib = lib.fill_array_with_fib

_fill_array_with_fib.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fill_array_with_fib.restype = (ctypes.c_int)

def fill_array_with_fib(n):
  arr = (ctypes.c_int * n)()
  
  m = _fill_array_with_fib(arr, n)
  result_list =  list(arr)
  return result_list[0 : m]


_transfer_unique = lib.transfer_unique

_transfer_unique.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_transfer_unique.restype = (ctypes.c_int)

def transer_unique(src):
  src_arr = (ctypes.c_int * len(src))(*src)
  dst_arr = (ctypes.c_int * len(src))()

  n = _transfer_unique(src_arr, dst_arr, len(src))

  result_list = list(dst_arr)

  return result_list[0 : n]

def transer_unique_second(src):
  src_arr = (ctypes.c_int * len(src))(*src)
  dst_arr = None

  n = _transfer_unique(src_arr, dst_arr, len(src))

  dst_arr = (ctypes.c_int * n)()

  n = _transfer_unique(src_arr, dst_arr, len(src))

  result_list = list(dst_arr)

  return result_list[0 : n]
