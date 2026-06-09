#include <cstdlib>
#include <iostream>
#include "includes.hpp"

static void usage(const char *prog)
{
    std::cerr << "Usage: " << prog << " <port> <password>\n";
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    unsigned short port = static_cast<u_int16_t>(std::atoi(argv[1]));
    if (port == 0)
    {
        std::cerr << "Invalid port\n";
        return EXIT_FAILURE;
    }

    try
    {
        Irc irc(port, argv[2]);
        irc.run();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Server error: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
