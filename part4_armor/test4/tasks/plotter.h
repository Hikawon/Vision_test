//
// Created by nirvana on 2025/9/15.
//

#ifndef HELLO_OOP_PLOTTER_H
#define HELLO_OOP_PLOTTER_H

#include <netinet/in.h>  // sockaddr_in

#include <nlohmann/json.hpp>
#include <string>

namespace auto_aim
{
class Plotter
{
public:
  Plotter(std::string host = "127.0.0.1",uint16_t port =9870);

  ~Plotter();

  void plot(const nlohmann::json & json);

private:
  int socket_;
  sockaddr_in destination_;
};
}// namespace auto_aim

#endif //HELLO_OOP_PLOTTER_H
