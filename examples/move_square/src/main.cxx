/* main.cpp */
#include "app.hpp"

using namespace bismuth;

int main(int argc, char* argv[])
{
    App *app = new App();
    app->Initialize(); // initialize the app. creates the interface, etc

    return 0;
}