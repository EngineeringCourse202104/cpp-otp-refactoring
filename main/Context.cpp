#include "Context.h"

#include <iostream>
#include <map>

std::map<std::string, std::string> Context::profiles{{"joey", "91"}, {"mei", "99"}};

Context::Context()
{
    // profiles = {
    //         {"joey", "91"},
    //         {"mei",  "99"}
    // };
}

std::string Context::getPassword(const std::string userName)
{

    return profiles[userName];
}
