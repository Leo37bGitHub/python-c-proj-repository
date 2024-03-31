// square.c

#include <stdio.h>
#include <windows.h>

// Define function pointer type for the function to allocate console
typedef void (*AllocateConsoleFunc)();

// Declare the function to allocate console
void allocateConsoleWrapper();

// Define the DLL_EXPORT macro if not already defined
#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

// Define the function to allocate console
void allocateConsoleWrapper() {
    AllocConsole();
}


    DLL_EXPORT double square(double x) {//
        return x * x;
    }
	
	DLL_EXPORT void printMessage(const char* message) {
        // Allocate a console if one is not already allocated
        allocateConsoleWrapper();
		printf("%s\n", message); // Use printf for standard output
		fflush(stdout);
		return;
    }
	
	DLL_EXPORT int printMessage2() {
		
        // Allocate a console if one is not already allocated
        allocateConsoleWrapper();
		const char* str = "zzzzz";
		int result = printf("%s\n", str);
		fflush(stdout);
		return result;
		if (result < 0) {
           // Handle error if printf returns a negative value
           perror("printf failed");
           return -1; // Return an error code
        }
           return result; // Return the number of characters printed
		
       }



 


