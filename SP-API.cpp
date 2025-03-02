#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp" // nlohmann/json

// ... Funções para autenticação e assinatura AWS Signature Version 4 ...

int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        std::string url = "https://sellingpartnerapi-eu.amazon.com/orders/v0/orders"; // Exemplo de endpoint
        std::string accessToken = "YOUR_ACCESS_TOKEN"; // Obtenha o token de acesso

        // ... Gerar cabeçalhos de autenticação ...
        struct curl_slist *headers = nullptr;
        std::string authHeader = "Authorization: Bearer " + accessToken;
        headers = curl_slist_append(headers, authHeader.c_str());
        headers = curl_slist_append(headers, "x-amz-access-token: " + accessToken);
        headers = curl_slist_append(headers, "x-amz-date: 20231027T120000Z"); // Exemplo, gere uma data real.
        headers = curl_slist_append(headers, "x-amz-security-token: YOUR_SECURITY_TOKEN");
        headers = curl_slist_append(headers, "x-amz-content-sha256: YOUR_SHA256");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        std::string responseBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void *contents, size_t size, size_t nmemb, std::string *s) {
            s->append((char *)contents, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            std::cout << "Resposta:" << std::endl;
            std::cout << responseBuffer << std::endl;

            // Processar a resposta JSON usando nlohmann/json
            try {
                nlohmann::json jsonResponse = nlohmann::json::parse(responseBuffer);
                // Extrair dados do JSON
                // ...
            } catch (const nlohmann::json::parse_error& e) {
                std::cerr << "Erro ao analisar JSON: " << e.what() << std::endl;
            }

        } else {
            std::cerr << "curl_easy_perform() falhou: " << curl_easy_strerror(res) << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return 0;
}#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp" // nlohmann/json

// ... Funções para autenticação e assinatura AWS Signature Version 4 ...

int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        std::string url = "https://sellingpartnerapi-eu.amazon.com/orders/v0/orders"; // Exemplo de endpoint
        std::string accessToken = "YOUR_ACCESS_TOKEN"; // Obtenha o token de acesso

        // ... Gerar cabeçalhos de autenticação ...
        struct curl_slist *headers = nullptr;
        std::string authHeader = "Authorization: Bearer " + accessToken;
        headers = curl_slist_append(headers, authHeader.c_str());
        headers = curl_slist_append(headers, "x-amz-access-token: " + accessToken);
        headers = curl_slist_append(headers, "x-amz-date: 20231027T120000Z"); // Exemplo, gere uma data real.
        headers = curl_slist_append(headers, "x-amz-security-token: YOUR_SECURITY_TOKEN");
        headers = curl_slist_append(headers, "x-amz-content-sha256: YOUR_SHA256");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        std::string responseBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void *contents, size_t size, size_t nmemb, std::string *s) {
            s->append((char *)contents, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            std::cout << "Resposta:" << std::endl;
            std::cout << responseBuffer << std::endl;

            // Processar a resposta JSON usando nlohmann/json
            try {
                nlohmann::json jsonResponse = nlohmann::json::parse(responseBuffer);
                // Extrair dados do JSON
                // ...
            } catch (const nlohmann::json::parse_error& e) {
                std::cerr << "Erro ao analisar JSON: " << e.what() << std::endl;
            }

        } else {
            std::cerr << "curl_easy_perform() falhou: " << curl_easy_strerror(res) << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return 0;
}