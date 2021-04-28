#ifndef MAIN_LOGPRINTER
#define MAIN_LOGPRINTER
#include <iostream>
#include <string>

struct ILogPrinter
{
  public:
    virtual void log(const std::string& msg) = 0;
};

class LogPrinter : public ILogPrinter
{
  public:
    void log(const std::string& msg) override { std::cout << "LOG： " << msg << std::endl; }
};

#endif /* MAIN_LOGPRINTER */
