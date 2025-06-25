/**
 * PPG Crack - Password Generator
 * 
 * Author: t00th1e55
 * Date: 2025/06/25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password_generator.h"

int main(int argc, char *argv[]) {
    setup_console(); // Initialize console for proper output
    
    // Check for help flag or no arguments
    if (argc != 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help(argv[0]);
        return EXIT_FAILURE;
    }

    const char *technician_code = argv[1];
    char password[MAX_PASSWORD_LENGTH] = {0};

    // Validate input
    if (strlen(technician_code) != TECHNICIAN_CODE_LENGTH || !is_numeric(technician_code)) {
        fprintf(stderr, "Error: Input must be exactly 4 digits.\n");
        return EXIT_FAILURE;
    }

    // Generate and print password
    generate_password(technician_code, password);
    printf("%s\n", password);

    return EXIT_SUCCESS;
}