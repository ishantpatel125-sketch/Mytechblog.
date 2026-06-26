#include "crow.h" // Includes the Crow HTTP Framework Library
#include <fstream>
#include <sstream>
#include <iostream>

// Helper function to safely read the HTML dashboard file from disk
std::string get_html_content(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "<h1>Error 404: Website file (index.html) not found in system directory.</h1>";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    // Initialize the high-performance C++ Web Application instance
    crow::SimpleApp app;

    // Define the Root Network Route ("/")
    CROW_ROUTE(app, "/")
    ([](const crow::request& req, crow::response& res) {
        // Read the dynamic troubleshooting matrix HTML layout file
        std::string html_payload = get_html_content("index.html");
        
        // Define clean network response parameters
        res.set_header("Content-Type", "text/html");
        res.write(html_payload);
        res.end();
    });

    std::cout << "==================================================\n";
    std::cout << "🚀 OMNICOMPUTE C++ BACKEND ENGINE ACTIVE\n";
    std::cout << "🌐 Access live environment: http://localhost:8080\n";
    std::cout << "==================================================\n";

    // Set production port routing parameters and initialize server thread loops
    app.port(8080)
       .multithreaded()
       .run();
       
    return 0;
}
