#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <vector>
#include <random>
#include <iostream>


auto main(int argc, char **argv) -> int
{
    auto count = 20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c, --count", count, fmt::format("Create a vector with the given size default: {}",count));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    std::vector <int> v(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> verteilung(1, 100);
    for (int i = 0; i < count; ++i) {
        v[i] = verteilung(gen);
    }
    std::cout << "Mein Vektor mit zufälligen Zahlen: ";
    for (int i = 0; i < count; ++i) {
        std::cout << v[i] << " ";
    }
    for (int i = 0; i < count; i++)
    {
        int min_pos = i;
        for (int j = i+1; j < count; j++){
            if (v[j] < v[min_pos])
                min_pos = j; 
        std::cout <<v[j] << " ";
        }
              
    }
   
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
