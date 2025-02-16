#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "util.h"
#include "changehere.h"
#include "colors.h"
#define MAX_SENTENCE_LENGTH 256 // Max length of each sentence
#define MAX_LIST_SIZE 100       // Max number of sentences

#ifdef _WIN32
#include <direct.h> // Windows-specific
#include <io.h>
#define mkdir(path) _mkdir(path) // Use _mkdir for Windows
#else
#include <sys/stat.h> // POSIX standard
#include <sys/types.h>
#include <unistd.h> // For getcwd()
#endif

// Global Variables
char true = 1;
char false = 0;
clock_t start, end;
time_t t;
char weekDay[6];
char day[4];
char month[5];
char year[6];
char work[6] = "/work";
char infoFile[9] = "/info.md";
char gitIgnoreFile[] = "/.gitignore";
char *baseDir = NULL;
char isDefault = 1;
int countG = 0;
const char *rootDir = "/TIME LINE";
// End

void initialize()
{ // Set current time to &t
    time(&t);

    // Get the ctime string
    char *time_str = ctime(&t);

    // Print the original ctime string
    // printf("Original ctime string: %s", time_str);

    // Extract components using indexing
    // Week Day
    weekDay[0] = '(';
    weekDay[1] = time_str[0];
    weekDay[2] = time_str[1];
    weekDay[3] = time_str[2];
    weekDay[4] = ')';
    weekDay[5] = '\0'; // Null-terminate the string
    // printf("Extracted Weekday: %s\n", weekDay);
    // Day
    day[0] = '/';
    day[1] = time_str[8];
    day[2] = time_str[9];
    day[3] = '\0';
    // printf("Extracted day: %s\n", day);
    // Month
    month[0] = '/';
    month[1] = time_str[4];
    month[2] = time_str[5];
    month[3] = time_str[6];
    month[4] = '\0';
    // printf("Extracted Month: %s\n", month);
    // Year
    year[0] = '/';
    year[1] = time_str[20];
    year[2] = time_str[21];
    year[3] = time_str[22];
    year[4] = time_str[23];
    year[5] = '\0';
    // printf("Extracted year: %s\n", year);
}
void create_directory(const char *path)
{
    if (path == NULL || strlen(path) == 0)
    {
        fprintf(stderr, "Error: Path is NULL or empty.\n");
    }

#ifdef _WIN32
    if (_mkdir(path) == 0)
    {
        // Success
    }
    else
    {
        perror("Error creating directory");
        // Failure
    }
#else
    if (mkdir(path, 0777) == 0)
    {
        // success("Directory Created"); // 0777 sets full access permissions
        // Success
    }
    else
    {
        if (errno != EEXIST)
        {
            perror("ERR");
            // Directory already exists; we ignore this error.
        }
    }
#endif
}
// Returns the current dir of the system
char *parentdir()
{
    static char parent_dir[1024];
    char cwd[1024];

// Get the current working directory
#ifdef _WIN32
    if (_getcwd(cwd, sizeof(cwd)) == NULL)
#else
    if (getcwd(cwd, sizeof(cwd)) == NULL)
#endif
    {
        perror("Error getting current working directory");
        return NULL;
    }

    // Find the last directory separator
    char *last_separator = strrchr(cwd, '/');
    if (last_separator == NULL)
    {
        last_separator = strrchr(cwd, '\\'); // Handle Windows backslashes
    }

    if (last_separator == NULL)
    {
        fprintf(stderr, "Error: Unable to find parent directory (current dir might be root).\n");
        return NULL;
    }

    // Copy the parent directory path
    size_t parent_len = last_separator - cwd;
    strncpy(parent_dir, cwd, parent_len);
    parent_dir[parent_len] = '\0'; // Null-terminate the string

    return parent_dir;
}
// Function to print all stored sentences
void print_list(char *list[], int count)
{
    int index = 0;
    error("\n####################################################################");
    success("\nYour work you need to complete within Today:\n");
    while (index < count)
    { // Loop through all 8 elements
        if (list[index] != NULL)
        {
            normal("  %d. %s\n", index + 1, list[index]);
            countG = index + 1;
        }
        if (index == count - 1)
        {
            error("####################################################################\n\n");
        }
        index++;
    }
}

// Function to free allocated memory
void free_list(char *list[], int count)
{
    for (int i = 0; i < count; i++)
    {
        free(list[i]);
    }
}
void create_gitignore(const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error: Unable to create .gitignore file.\n");
        return;
    }

    // Write common ignore patterns
    const char *patterns[] = {
        "# Ignore macOS system files",
        ".DS_Store",
        " *.DS_Store",
        " *.DS_Store.*",
        "",
        "# Ignore build artifacts",
        "*.o",
        "*.exe",
        "*.out",
        "bin/",
        "obj/",
        "",
        "# Ignore Node.js dependencies",
        "node_modules/",
        "",
        "# Ignore Python cache files",
        "__pycache__/",
        "*.pyc",
        "*.pyo",
        "",
        "# Ignore log files",
        "*.log",
        "",
        "# Ignore IDE settings",
        ".vscode/",
        ".idea/",
        "*.swp",
        NULL // Marks the end of the array
    };

    for (int i = 0; patterns[i] != NULL; i++)
    {
        fprintf(file, "%s\n", patterns[i]);
    }

    fclose(file);
    printf(".gitignore file created successfully.\n");
}

void createMarkdownFile(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        error("Error opening file!\n");
        return;
    }

    // Writing greetings
    fprintf(file, "# 🌟 Your Task Planner for Today! 🌟\n\n");
    fprintf(file, "---\n\n");
    fprintf(file, "### 💪 Stay motivated and push yourself to complete your tasks! \U0001F3C6\n\n");

    // Writing instructions
    fprintf(file, "## 📝 How to Use\n\n");
    fprintf(file, "- ✅ To mark a task as completed, replace '[ ]' with '[x]'.\n");
    fprintf(file, "- ❌ To mark a task as uncompleted, replace '[x]' with '[ ]'.\n");
    fprintf(file, "---\n\n");

    // Writing task list
    fprintf(file, "## 📌 Tasks to Complete\n\n");
    // int taskCount = sizeof(todoList) / sizeof(todoList[0]);
    for (int i = 0; i < countG; i++)
    {
        if (todoList[i] != NULL)
        {
            fprintf(file, "- [ ] %s\n", todoList[i]);
        }
    }

    // Adding completed tasks count
    fprintf(file, "\n---\n\n");
    fprintf(file, "## 📊 Task Completion Summary\n\n");
    fprintf(file, "- ✅ Completed tasks: 0/%d\n", countG);
    fprintf(file, "\n---\n\n");

    // Writing the 12-hour format table
    fprintf(file, "## ⏳ Schedule\n\n");
    fprintf(file, "| 🕒 Time       | 🏁 Task |\n");
    fprintf(file, "|--------------|---------|\n");

    const char *timePeriods[] = {"AM", "PM"};
    for (int i = 0; i < 2; i++)
    { // AM and PM
        for (int hour = 0; hour < 12; hour++)
        {
            int displayHour = (hour == 0) ? 12 : hour; // Convert 0 to 12
            fprintf(file, "| %02d:00 %s  |                    |\n", displayHour, timePeriods[i]);
        }
    }

    fclose(file);
    normalMag("Markdown file [info.md] created successfully!\n");
}
void generate()
{
    if (countG > 0)
    {
        baseDir = parentdir();
        // success(baseDir);
        char base[1024];
        strcpy(base, baseDir);
        strcat(base, rootDir);

        success(base);
        create_directory(base);
        char base1[1024];
        strcpy(base1, base);
        strcat(base1, gitIgnoreFile);
        create_gitignore(base1);

        strcat(base, year);
        // success(base);
        create_directory(base);

        strcat(base, month);
        // success(base);
        create_directory(base);

        strcat(base, day);
        strcat(base, weekDay);
        // success(base);
        create_directory(base);

        char base2[1024];
        strcpy(base2, base);
        // success(base2);
        strcat(base2, infoFile);
        createMarkdownFile(base2);

        strcat(base, work);
        // success(base);
        create_directory(base);

        if (!isDefault)
        {
            free_list(todoList, countG);
        }
    }
}

void getDefaultList()
{
    int count = sizeof(todoList) / sizeof(todoList[0]);
    print_list(todoList, count);
}
void interrupt()
{
    char input;
    normal("\nWould you like to edit the TODO list? (y/n)\n\n");
    normal("Enter 'y' to edit or 'n' to continue with the default list.\n\n");
    scanf("%s", &input);
    getchar();
    if (input == 'y' || input == 'Y')
    {
        getUserList();
        return;
    }
    normalMag("\nYou are proceeding with default list...\n");
    getDefaultList();
    return;
}

void startCount()
{
    start = clock();
}

void endCount()
{
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    speed("\nProcessing time taken: %.4f seconds.\n", time_taken);
}

// Function to get sentences from user until "done" is entered
void get_sentences(char *list[])
{

    char buffer[MAX_SENTENCE_LENGTH];

    normalMag("\nPlease enter what work you would like to accomplish for today:\n\n");
    normal("(Then, press the \"ENTER\" key to continue)");

    while (countG < MAX_LIST_SIZE)
    {
        normal("  > ");
        fgets(buffer, MAX_SENTENCE_LENGTH, stdin);

        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Check if the user entered "done"
        if (strcmp(buffer, "d") == 0)
        {
            break;
        }

        // Allocate memory and store sentence
        list[countG] = malloc(strlen(buffer) + 1);
        if (list[countG] == NULL)
        {
            normal("Memory allocation failed!\n");
        }

        strcpy(list[countG], buffer);
        normal("(Type \"d\" to finish or press \"ENTER\" key)");
        countG++;
    }
}

void getUserList()
{
    char *sentence_list[MAX_LIST_SIZE];
    // Get sentences from user
    get_sentences(sentence_list);
    if (countG > 0)
    {
        // Copy elements from sentence_list to todoList
        for (int i = 0; i < countG; i++)
        {
            todoList[i] = strdup(sentence_list[i]); // Allocate and copy the string
            if (todoList[i] == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                // Exit on failure
            }
        }

        isDefault = false;
        // Print stored sentences
        print_list(sentence_list, countG);

        // Free allocated memory
        free_list(sentence_list, countG);
    }
    else
    {
        error("Please add one or more task!");
    }
}
