#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>
#include <curl/curl.h>
#include "curl-helper.h"

// curl https://jsonplaceholder.typicode.com/todos/15
// https://curl.se/libcurl/c/example.html
/*
response:
    {
        "userId": 1,
        "id": 15,
        "title": "ab voluptatum amet voluptas",
        "completed": true
    }
*/

int main() {
    CurlResonseStruct resp;
    resp.ptr = malloc(1);
    resp.len = 0;

    char *myUrl = "https://jsonplaceholder.typicode.com/todos/3";

    int apa = call_url(myUrl, &resp);

    printf("----------------------------\n");
    printf("%s\n", resp.ptr);
    printf("----------------------------\n");

    free(resp.ptr);

    return apa;
}