#include <stdlib.h>

typedef struct
{
    char *ptr;
    size_t len;
} CurlResonseStruct;

typedef struct
{
    unsigned int userId;
    unsigned int id;
    char *title;
    bool completed;
} TodoStruct;

int call_url(char *url, CurlResonseStruct *response);