# mainExt.py



debug = True

import sys
import os


import sys
sys.path.insert(0, 'C:/leoData/GITHUB/python-c-proj-repository')

pid = os.getpid()

print('pid=', pid)


##import ptvsd
##port=3000
##ptvsd.enable_attach(address =('127.0.0.1', port))
##ptvsd.wait_for_attach()



# Your existing code continues from here
# This is where your main logic should be

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

##breakpoint()
import pextent


pextent.hello_world()
