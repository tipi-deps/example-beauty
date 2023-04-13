#include <beauty/beauty.hpp>

#include <iostream>

int main()
{
    // Create a client
    beauty::client client;

    // Request an URL
    auto[ec, response] = client.get("http://127.0.0.1:8085");

    // Check the result
    if (!ec) {
        if (response.is_status_ok()) {
            // Display the body received
            std::cout << response.body() << std::endl;
        } else {
            std::cout << response.status() << std::endl;
        }   
    } else {
        // An error occurred
        std::cout << ec << ": " << ec.message() << std::endl;
    }
}