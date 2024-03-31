# mainExt.py



debug = True

import sys
import os

pid = os.getpid()

print('pid=', pid)

# Append the root folder of your project to sys.path
root_dir = os.path.dirname(os.path.abspath(__file__))
print('root_dir=', root_dir)
sys.path.append(root_dir)

'''
# Specify the directory path
directory_path = "C:/leoData/GITHUB/python-c-proj-repository"

# Check if the directory exists
if os.path.exists(directory_path):
    # List all files and directories in the specified directory
    files_and_directories = os.listdir(directory_path)

    # Print each file and directory
    for item in files_and_directories:
        print(item)
else:
    print("Directory does not exist.")
'''
# Add the directory containing the DLL to the Python module search path
#dll_dir = 'C:\leoData\GITHUB\python-c-proj-repository'
#sys.path.append(dll_dir)

# Now import the module
import pextent

pextent.hello_world()
