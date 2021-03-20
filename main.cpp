#include <iostream>
#include <bulk/Bulk.h>

int main(int argc, char **argv) {
    std::cout << "Hello, World!" << std::endl;
    if (argc < 2) {
        std::cerr << "Invalid count argument" << std::endl;
        exit(EXIT_FAILURE);
    }

    try {
        int count = std::stoi(argv[1]);
        if (count == 0) {
            std::cerr << "Argument is zero" << std::endl;
            exit(EXIT_FAILURE);
        }
        Settings settings(std::cin, std::cout, std::cout, count);
        Bulk bulk(settings);

        bulk.run();

//        RunBulk(count);
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
