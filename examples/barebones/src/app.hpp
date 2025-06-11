/* src/app.hpp */
#ifndef APP_HPP
#define APP_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "bismuth/core/base.hpp"

namespace bismuth
{

class App : public AppBase
{
public:
    App();
    virtual ~App();
};

} // namespace bismuth

#endif // APP_HPP