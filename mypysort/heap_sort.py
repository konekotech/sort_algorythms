import ctypes
import numpy as np

def sort(array: np.ndarray) -> np.ndarray:
    # Ensure array is of type np.int32
    array = np.asarray(array, dtype=np.int32)
    heap_sort_lib = ctypes.cdll.LoadLibrary('/app/clibs/heap_sort/build/libs/libheap_sort.so')
    sort_func = heap_sort_lib.sort
    sort_func.restype = ctypes.c_void_p
    sort_func.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
    sort_func(array.ctypes.data_as(ctypes.POINTER(ctypes.c_int)), len(array))
    return array
