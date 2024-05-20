#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char *ptr;
    size_t len;
} CurlResponseStruct;

typedef struct
{
    unsigned int userId;
    unsigned int id;
    char title[35+1];
    bool completed;
} TodoStruct;

int call_url(char *url, CurlResponseStruct *response, TodoStruct *todoResponse);
