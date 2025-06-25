#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <stdbool.h>

#define TECHNICIAN_CODE_LENGTH 4
#define MAX_PASSWORD_LENGTH 10
#define INITIAL_PASSWORD_DIGIT 4

// Function declarations
bool is_numeric(const char *str);
void generate_password(const char *technician_code, char *output);
void print_help(const char *program_name);
void setup_console(void);

#endif // PASSWORD_GENERATOR_H
