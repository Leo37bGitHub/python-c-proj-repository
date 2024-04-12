// pextent.c

///#ifdef _DEBUG
///#define _DEBUG_WAS_DEFINED
///#undef _DEBUG
///#endif

#include <Python.h>
#include <windows.h>
#include <wchar.h>  // Include wchar_t definition
#include <iostream>


////#include "spdlog/spdlog.h"

///#ifdef _DEBUG_WAS_DEFINED
///#define _DEBUG
///#undef _DEBUG_WAS_DEFINED
///#endif

///#ifdef _DEBUG
///#       define Py_DEBUG
///#endif



const char* pystart = 
"print('Start')\n\
import pextent\n\
print(dir(pextent))\n\
print(pextent.hello_world())";

static PyObject* hello_world(PyObject* self, PyObject* args) {
	
	WIN32_FIND_DATAW findFileData;
    HANDLE hFind;
    
    // Specify the directory path
    LPCWSTR directoryPath = L"C:\\leoData\\GITHUB\\python-c-proj-repository\\*.*";

	///////spdlog::info("Welcome to spdlog!");
    
	//LPCWSTR directoryPath = L"*";
	//printf("%ws\n", directoryPath);                        

    // Find the first file in the directory
	
    //hFind = FindFirstFile(directoryPath, &findFileData);
	hFind = FindFirstFileW(L"C:\\leoData\\GITHUB\\python-c-proj-repository\\*.*", &findFileData);
	//hFind = FindFirstFileA("C:\\leoData\\GITHUB\\python-c-proj-repository", &findFileData);
    
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            printf("%ws\n", findFileData.cFileName);
        } while (FindNextFileW(hFind, &findFileData) != 0);
        
        FindClose(hFind);
    } else {
        printf("Failed to find files.\n");
    }
    
    //return 0;
	
	
    printf("Hello, world!\n");
	std::cout << "hello Leonid" << std::endl;
     Py_RETURN_NONE;
}



static PyMethodDef methods[] = {
    {"hello_world", hello_world, METH_NOARGS, "Print hello world"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "pextent",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_pextent(void) {
    return PyModule_Create(&module);
}

//////////////////////////////
int main()
{
	printf("Leonid Test Programm for Python 3.8\n");

	Py_Initialize();

	static struct PyModuleDef moduledef = {
		PyModuleDef_HEAD_INIT,
		"pextent",
		PyDoc_STR("pextent Module"),
		-1,
		methods
	};


	PyObject* pextent = PyImport_AddModule("pextent"); //create main module
	if (!pextent)
	{
		printf("Could not add the module pextent in Python.");
		return 0;
	}

	PyModule_AddFunctions(pextent, methods);

	if (PyRun_SimpleString(pystart) == -1)
	{
		printf("Could not run pystart.");
		return 0;
	}

	return 1;
}