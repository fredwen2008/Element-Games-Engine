#include <iostream>
#include "../../../Server/Networking.h"

int main(int argc, char **argv) {
    EGServer::Networking *n = new EGServer::Networking;
    while (true) {
        n->update();
    }
    return 0;
}
