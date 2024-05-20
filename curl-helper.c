#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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


size_t writefunc(void *ptr, size_t size, size_t nmemb, CurlResponseStruct *s)
{
    size_t new_len = s->len + size * nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    if (s->ptr == NULL)
    {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr + s->len, ptr, size * nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size * nmemb;
}

int call_url(char *myUrl, CurlResponseStruct *jsonResponse, TodoStruct *todoResponse)
{
    CURL *curl_handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl_handle = curl_easy_init();
    if (curl_handle)
    {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, "skv_correlation_id: 123412341234");
        chunk = curl_slist_append(chunk, "Authorization: Bearer eyYo123.1234.1234");
        chunk = curl_slist_append(chunk, "client_id: icc-client-id");
        chunk = curl_slist_append(chunk, "client_secret: icc-client-secret");

        // set our custom set of headers
        curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, chunk);

        curl_easy_setopt(curl_handle, CURLOPT_URL, myUrl);

        // TODO: Ersätt med CURLOPT_XOAUTH2_BEARER på SKV
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0L);

        // cache the CA cert bundle in memory for a week
//        curl_easy_setopt(curl_handle, CURLOPT_CA_CACHE_TIMEOUT, 604800L);

        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, jsonResponse);

        // some servers do not like requests that are made without a user-agent
        // field, so we provide one
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        // Perform the request, res gets the return code
        res = curl_easy_perform(curl_handle);

        // Check for errors
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        // always cleanup
        curl_easy_cleanup(curl_handle);

        // free the custom headers
        curl_slist_free_all(chunk);
    }

    curl_global_cleanup();

//  todoResponse->id = 10;
//    todoResponse->userId = 20;
//    strncpy(todoResponse->title, "Hell YEAH! AMERICA!!!", 21);
//    todoResponse->completed = true;

   
    return 0;
}