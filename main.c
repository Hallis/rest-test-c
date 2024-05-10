#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>
#include <curl/curl.h>

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

int main()
{
    CURL *curlHandle;
    CURLcode res;
    char *myUrl = "https://jsonplaceholder.typicode.com/todos/7";

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curlHandle = curl_easy_init();
    if (curlHandle)
    {
        curl_easy_setopt(curlHandle, CURLOPT_URL, myUrl);

        // TODO: Ersätt med lämplig oauth-verifiering?
        curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, 0L);

        // cache the CA cert bundle in memory for a week
        curl_easy_setopt(curlHandle, CURLOPT_CA_CACHE_TIMEOUT, 604800L);

        // Perform the request, res gets the return code
        res = curl_easy_perform(curlHandle);

        // Check for errors
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        // always cleanup
        curl_easy_cleanup(curlHandle);
    }

    curl_global_cleanup();

    return 0;
}