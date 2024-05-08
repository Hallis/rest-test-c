#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char responseRow[100];
    char responseJson[2000];
    char *cur = responseJson, *const end = responseJson + sizeof responseJson;

    printf("Fetching data\n");

    // curl https://jsonplaceholder.typicode.com/todos/15
    /*
    response:
        {
            "userId": 1,
            "id": 15,
            "title": "ab voluptatum amet voluptas",
            "completed": true
        }
    */

    fp = popen("curl -S -s https://jsonplaceholder.typicode.com/todos/15", "r");
    if (fp == NULL)
    {
        printf("Failed to run command\n");
        exit(1);
    }

    while (fgets(responseRow, sizeof(responseRow), fp) != NULL)
    {
        cur += snprintf(cur, end - cur, "%s", responseRow);
    }
    pclose(fp);

    printf("Slutlig json: %s\n", responseJson);

    return 0;
}