from distutils.core import setup, Extension

import os

# Set Py_DEBUG to 1
os.environ['Py_DEBUG'] = '1'

pextent_module = Extension('pextent', sources=['pextent.c'])



setup (name='pextent',
       version='0.1.0',
       description='Python Package with Hello World C Extension',
       ext_modules = [pextent_module])