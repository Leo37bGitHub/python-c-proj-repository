#include <stdio.h>
#include <windows.h>

// Define function pointer types for the functions in your DLL
typedef double (*SquareFunc)(double);
typedef void (*PrintMessageFunc)(const char*);
typedef void (*PrintMessageFunc2)();

int main() {
    // Load the DLL
    HINSTANCE hDLL = LoadLibrary("square.dll");
    if (hDLL == NULL) {
        fprintf(stderr, "Failed to load DLL.\n");
        return 1;
    }

    // Get function pointers for the functions in the DLL
    SquareFunc square = (SquareFunc)GetProcAddress(hDLL, "square");
    PrintMessageFunc printMessage = (PrintMessageFunc)GetProcAddress(hDLL, "printMessage");
    PrintMessageFunc2 printMessage2 = (PrintMessageFunc2)GetProcAddress(hDLL, "printMessage2");
    if (square == NULL || printMessage == NULL || printMessage2 == NULL) {
        fprintf(stderr, "Failed to get function pointers.\n");
        return 1;
    }

    // Call the square function
    double result = square(4);
    printf("Square of 4: %f\n", result);
    
    // Call the printMessage function
    const char* message = "Hello, world!";
    printMessage(message);
    
    // Call the printMessage2 function
    printMessage2();

    // Unload the DLL
    FreeLibrary(hDLL);

    return 0;
}