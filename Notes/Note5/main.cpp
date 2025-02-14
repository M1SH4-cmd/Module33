#include <iostream>
#include <boost/asio.hpp>
int main() {

    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    t.wait();
    std::cout << "Hello, 5 seconds are lost" << std::flush;

    return 0;
}
