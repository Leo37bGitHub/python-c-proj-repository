# main.py
import os
import ctypes
import ctypes.util


# Specify the file name
file_name = 'square.dll'

# Get the full path to the file
file_path = os.path.join(os.path.dirname(__file__), file_name)

# Check if the file exists
if os.path.isfile(file_path):
    print(f"Found {file_name} at: {file_path}")
    # Now you can proceed to load the file using ctypes.CDLL()
else:
    print(f"Could not find {file_name}")


dll_path = os.path.join(os.path.dirname(__file__), 'square.dll')

print("ctypes.RTLD_GLOBAL=", ctypes.RTLD_GLOBAL)
print("ctypes.RTLD_LOCAL=", ctypes.RTLD_LOCAL)
print("ctypes.DEFAULT_MODE=", ctypes.DEFAULT_MODE)

# Allocate a console
##kernel32 = ctypes.windll.kernel32
##kernel32.AllocConsole()

square_lib = ctypes.CDLL(dll_path, winmode = 0x0)
#square_lib = ctypes.windll.LoadLibrary('C:\\leoData\\GITHUB\\python-c-proj-repository\\square.dll')


# Declare the argument and return types of the square function
square_lib.square.argtypes = [ctypes.c_double]
square_lib.square.restype = ctypes.c_double

# Call the square function
result = square_lib.square(4)
print(result)  # Output: 16.0

try:
    # Define the argument and return types for the PrintMessage function
    ##square_lib.printMessage2.argtypes = [ctypes.c_char_p]
    square_lib.printMessage2.argtypes = []
    square_lib.printMessage2.restype = ctypes.c_int

    # Call the PrintMessage function with the message
    ##message = b'Hello, world!'
    print('before printMessage2')
    ret = square_lib.printMessage2()
    # Wait for user input before exiting
    input("Press Enter to exit...")
    print('ret=', ret)
    
except Exception as e:
    print(f"An error occurred: {e}")



