#!/usr/bin/env python3
# encoding: utf-8

'''
from distutils.core import setup, Extension

pextent_module = Extension('pextent', sources = ['pextent.c'])

setup(name='pextent',
      version='0.1.0',
      description='Hello world module written in C',
      ext_modules=[pextent_module])
      
'''
######
import os

##from setuptools import setup, Extension
from distutils.core import setup
from distutils.extension import Extension

# Set Py_DEBUG to 1
os.environ['Py_DEBUG'] = '1'

print('running setup.py')

os.environ["CC"] = "g++-8.1.0"

_DEBUG = True
_DEBUG_LEVEL = 1
# extra_compile_args = sysconfig.get_config_var('CFLAGS').split()
extra_compile_args = ["-Wall", "-Wextra"]
if _DEBUG:
    extra_compile_args += ["-g3", "-O0", "-DDEBUG=%s" % _DEBUG_LEVEL, "-UNDEBUG"]
else:
    extra_compile_args += ["-DNDEBUG", "-O3"]

extra_compile_args += ["/Zi"]

# extra_link_args += ["/DEBUG"]

print('extra_compile_args=', extra_compile_args)

pextent_module= Extension('pextent', sources=['pextent.c'])

setup(
    name='pextent',
    version='0.1.0',
    description='Python Package with Hello World C Extension',
    ##py_limited_api=True,
    ##extra_compile_args=extra_compile_args,
    ext_modules = [pextent_module]
)


