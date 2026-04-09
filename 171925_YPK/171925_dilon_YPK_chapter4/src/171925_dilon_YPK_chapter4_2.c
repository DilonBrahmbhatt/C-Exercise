#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>
void displayAttributes(const char *filename) {
    struct stat fileStat;

   if (stat(filename, &fileStat) < 0) {
        printf("Error: Cannot read file attributes.\n");
        return;
    }

    printf("\n--- Attributes of '%s' ---\n", filename);
    printf("Read by Owner   : %s\n", (fileStat.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Write by Owner  : %s\n", (fileStat.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Execute by Owner: %s\n", (fileStat.st_mode & S_IXUSR) ? "Yes" : "No");
    printf("Read by Group   : %s\n", (fileStat.st_mode & S_IRGRP) ? "Yes" : "No");
    printf("Write by Group  : %s\n", (fileStat.st_mode & S_IWGRP) ? "Yes" : "No");
    printf("Read by Others  : %s\n", (fileStat.st_mode & S_IROTH) ? "Yes" : "No");
    printf("Write by Others : %s\n", (fileStat.st_mode & S_IWOTH) ? "Yes" : "No");
    printf("File Size       : %ld bytes\n", fileStat.st_size);
}

void changeAttributes(const char *filename) {
    int choice;
    mode_t newMode = 0;

    printf("\n--- Set New Permissions ---\n");
    printf("Enter 1 for Yes, 0 for No:\n");

    int r, w, x;

    printf("Owner Read?    : "); scanf("%d", &r); if (r) newMode |= S_IRUSR;
    printf("Owner Write?   : "); scanf("%d", &w); if (w) newMode |= S_IWUSR;
    printf("Owner Execute? : "); scanf("%d", &x); if (x) newMode |= S_IXUSR;
    printf("Group Read?    : "); scanf("%d", &r); if (r) newMode |= S_IRGRP;
    printf("Group Write?   : "); scanf("%d", &w); if (w) newMode |= S_IWGRP;
    printf("Others Read?   : "); scanf("%d", &r); if (r) newMode |= S_IROTH;
    printf("Others Write?  : "); scanf("%d", &w); if (w) newMode |= S_IWOTH;

    if (chmod(filename, newMode) == 0)
        printf("\nAttributes updated successfully!\n");
    else
        printf("\nError: Could not update attributes.\n");
}

void file_Attributes() {
    char filename[100];
    int choice;

    printf("Enter filename: ");
    scanf("%s", filename);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Display Attributes\n");
        printf("2. Change Attributes\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayAttributes(filename); break;
            case 2: changeAttributes(filename); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

}
