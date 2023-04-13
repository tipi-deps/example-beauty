#include <beauty/beauty.hpp>

int main()
{
    // Create a server
    beauty::server server;

    // Add a default '/' route
    server.add_route("/")
        .get([](const auto& req, auto& res) {
            res.body() = "It's work ;) ... it works! :)";
        });

    // Add a '/person/:id' route
    server.add_route("/person/:id")
        .get([](const auto& req, auto& res) {
            auto id = req.a("id").as_string();
            res.body() = "You asked for the person id: " + id;
        });

    // Open the listening port
    server.listen(8085);
        // Listen will automatically start the loop in a separate thread

    // Wait for the server to stop
    server.wait();
}