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
    CurlResponseStruct resp;
    resp.ptr = malloc(1);
    resp.len = 0;
    TodoStruct todoResponse = {
        .userId = 0,
        .id = 0,
        .title = "",
        .completed = false
    };

    char *myUrl = "https://jsonplaceholder.typicode.com/todos/3";

    int apa = call_url(myUrl, &resp, &todoResponse);

    printf("============================\n");
    printf("%s\n", resp.ptr);
    printf("----------------------------\n");
    printf("id     = %d\n", todoResponse.id);
    printf("userid = %d\n", todoResponse.userId);
    printf("title  = %s\n", todoResponse.title);
    printf("complete = %s\n", todoResponse.completed ? "yes" : "no");
    printf("============================\n");

    free(resp.ptr);

    return apa;
}