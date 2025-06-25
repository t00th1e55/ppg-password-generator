#include "password_generator.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

bool is_numeric(const char *str) {
    if (str == NULL || *str == '\0') {
        return false;
    }
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return false;
        }
        str++;
    }
    return true;
}

void print_help(const char *program_name) {
    const char* border = "===========================================\n";
    
    fprintf(stderr, "\n%s", border);
    fprintf(stderr, "    PPG Crack - Password Generator\n");
    fprintf(stderr, "    Created by: t00th1e55\n");
    fprintf(stderr, "    Date: 2025/06/25\n");
    fprintf(stderr, "%s\n", border);
    
    fprintf(stderr, "  Username: Techniker\n\n");
    fprintf(stderr, "  Usage: %s <4-digit number>\n\n", program_name);
    fprintf(stderr, "  Options:\n");
    fprintf(stderr, "    -h, --help     Show this help message\n");
    fprintf(stderr, "\n%s\n", border);
}

void generate_password(const char *technician_code, char *output) {
    int output_index = 0;
    int previous_digit = INITIAL_PASSWORD_DIGIT;

    for (int i = 0; i < TECHNICIAN_CODE_LENGTH; ++i) {
        int current_digit = technician_code[i] - '0';
        int sum = previous_digit + current_digit;

        if (i < TECHNICIAN_CODE_LENGTH - 1) {
            output_index += snprintf(output + output_index, 
                                  MAX_PASSWORD_LENGTH - output_index, 
                                  "%d", sum % 10);
        } else {
            output_index += snprintf(output + output_index, 
                                  MAX_PASSWORD_LENGTH - output_index, 
                                  "%d", sum);
        }
        
        previous_digit = output[output_index - 1] - '0';
    }
}

void setup_console(void) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
}
