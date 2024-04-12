from distutils.core import setup
from distutils.extension import Extension

import os
# Set Py_DEBUG to 1
os.environ['Py_DEBUG'] = '1'

os.environ["CC"] = "g++-8.1.0"

_DEBUG = True
_DEBUG_LEVEL = 1

pextent_module = Extension('pextent', sources=['pextent.cpp'] ) 
     ## , extra_compile_args=["-Wall", "-DDEBUG=%s" % _DEBUG_LEVEL, "-UNDEBUG"])
     ## , extra_compile_args=["-Wall", "-Wextra", "-g","-g3", "-O0", "-DDEBUG=%s" % _DEBUG_LEVEL, "-UNDEBUG"])

setup(
    name='pextent',
    version='0.1.0',
    description='Python Package with Hello World C Extension',
    ext_modules=[pextent_module],
    
)

