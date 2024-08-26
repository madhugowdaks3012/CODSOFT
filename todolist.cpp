#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256

typedef struct {
    char description[MAX_TASK_LENGTH];
} Task;

void addTask(Task tasks[], int *taskCount);
void viewTasks(const Task tasks[], int taskCount);
void deleteTask(Task tasks[], int *taskCount);

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\nTo-Do List Manager\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Error: Task list is full.\n");
        return;
    }

    printf("Enter task description: ");
    fgets(tasks[*taskCount].description, MAX_TASK_LENGTH, stdin);
    tasks[*taskCount].description[strcspn(tasks[*taskCount].description, "\n")] = '\0';

    (*taskCount)++;
    printf("Task added successfully.\n");
}

void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\nTasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i].description);
    }
}

void deleteTask(Task tasks[], int *taskCount) {
    int taskNumber;

    if (*taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    printf("Enter the number of the task to delete: ");
    scanf("%d", &taskNumber);
    getchar();

    if (taskNumber < 1 || taskNumber > *taskCount) {
        printf("Error: Invalid task number.\n");
        return;
    }

    for (int i = taskNumber - 1; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*taskCount)--;
    printf("Task deleted successfully.\n");
}
