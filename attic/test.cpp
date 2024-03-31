#include <iostream>
#include <Windows.h>

// Define function pointer types for the functions in your DLL
typedef double (*SquareFunc)(double);
typedef void (*PrintMessageFunc)(const char*);
typedef void (*PrintMessageFunc2)();

int main() {
    // Load the DLL
    HINSTANCE hDLL = LoadLibrary("square.dll");
    if (hDLL == NULL) {
        std::cerr << "Failed to load DLL." << std::endl;
        return 1;
    }

    // Get function pointers for the functions in the DLL
    SquareFunc square = reinterpret_cast<SquareFunc>(GetProcAddress(hDLL, "square"));
    PrintMessageFunc printMessage = reinterpret_cast<PrintMessageFunc>(GetProcAddress(hDLL, "printMessage"));
	PrintMessageFunc2 printMessage2 = reinterpret_cast<PrintMessageFunc2>(GetProcAddress(hDLL, "printMessage2"));
    if (square == NULL || printMessage == NULL || printMessage2 == NULL) {
        std::cerr << "Failed to get function pointers." << std::endl;
        return 1;
    }

    // Call the square function
    double result = square(4);
    std::cout << "Square of 4: " << result << std::endl;

    // Call the printMessage function
    const char* message = "Hello, world!";
    printMessage(message);
	printMessage2();

    // Unload the DLL
    FreeLibrary(hDLL);

    return 0;
}