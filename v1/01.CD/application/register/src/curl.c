#include <curl/curl.h>
#include <stdio.h>
int main(){
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_URL, "http://itkv5-api.vnpttiengiang.vn/v1/api/camera/registerdevice");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    const char *data = "{\n    \"name\": \"VNPT-Camera\",\n    \"moadel\": \"VNPT-KV5-CAM\",\n    \"udid\": \"123-456-789\",\n    \"user_key\": \"2\",\n    \"version\": \"0.01\",\n    \"timestamp\": \"2020-08-08T17:11:21.355590\",\n    \"wifi_address\": \"xxx\",\n    \"mac_address\": \"xxx\",\n    \"local_ip\": \"192.168.0.0\",\n    \"access_token\": \"h4MPpoECZBYVXkq6mggf2sjAAccwd4Gq\"\n}\n";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    res = curl_easy_perform(curl);
  }
  curl_easy_cleanup(curl);
  return 0;
}