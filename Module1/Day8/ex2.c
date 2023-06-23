#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void convertToUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}


void convertToLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}


void convertToSentenceCase(char *str) {
    int firstChar = 1;

    while (*str) {
        if (firstChar) {
            *str = toupper((unsigned char)*str);
            firstChar = 0;
        } else {
            *str = tolower((unsigned char)*str);
        }

        if (*str == '.' || *str == '!' || *str == '?')
            firstChar = 1;

        str++;
    }
}


void performFileCopy(const char *sourcePath, const char *destinationPath, char caseOption) {
    FILE *sourceFile, *destinationFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

  
    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        exit(1);
    }

    destinationFile = fopen(destinationPath, "wb");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        exit(1);
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (caseOption == 'u')
            convertToUpperCase(buffer);
        else if (caseOption == 'l')
            convertToLowerCase(buffer);
        else if (caseOption == 's')
            convertToSentenceCase(buffer);

        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        printf("Options:\n");
        printf("  -u : Convert file content to uppercase\n");
        printf("  -l : Convert file content to lowercase\n");
        printf("  -s : Convert file content to sentence case\n");
        printf("  (No option) : Perform a normal copy\n");
        return 1;
    }

    char *option = argv[1];
    char *sourcePath = argv[2];
    char *destinationPath = argv[3];

    if (option[0] == '-') {
        char caseOption = option[1];
        performFileCopy(sourcePath, destinationPath, caseOption);
    } else {
        performFileCopy(sourcePath, destinationPath, '\0');
    }

    return 0;
}