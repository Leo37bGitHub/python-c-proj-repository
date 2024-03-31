// square.cpp
#define DLL_EXPORT __declspec(dllexport)


#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <fstream>

//#include <string>



extern "C" {
    DLL_EXPORT double square(double x) {
        return x * x;
    }
	
	DLL_EXPORT void printMessage(const char* message) {
        //OutputDebugStringA(message); // Use OutputDebugStringA for ANSI strings
		//AllocConsole();
		//printf("%s\n", "aaaaaa");
		std::cout << "aaaaaa" << std::endl;
		printf("%s\n", message); // Use printf for standard output
		fflush(stdout); // Flush the standard output stream
		return;
    }
	
	DLL_EXPORT void printMessage2() {
        //OutputDebugStringA(message); // Use OutputDebugStringA for ANSI strings
		//AllocConsole();
		const char* str = "zzzzz";
		printf("%s\n", str);
		//std::cout << "bbbbb" << std::endl;
		//std::cerr << "bbbbb" << std::endl;
		//fprintf(stderr, "bbbb");
		//std::ofstream logfile("log.txt", std::ios_base::app);
		/*
		if (logfile.is_open()) {
            logfile << "bbbbbb" << std::endl;
            logfile.close();
        }
		*/
		//printf("%s\n", message); // Use printf for standard output
		fflush(stdout); // Flush the standard output stream
		return;
    }
}


 void log_message(const char* message) {
        std::ofstream logfile("log.txt", std::ios_base::app);
        if (logfile.is_open()) {
            logfile << message << std::endl;
            logfile.close();
        }
    }


