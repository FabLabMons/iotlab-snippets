#include <HttpClient.h>

String contentType = "text/plain";
String postData = "type=pushed";

client.post("/switch/events", postData);

// read the status code and body of the response
statusCode = client.responseStatusCode();
response = client.responseBody();