
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Jun 20th
 *
 *      Bladez - Qt C++ Version Bladez 1.0
 *      Github : FrazorBladezSharp
 *
 * Contact email  : frazor.sharp@virginmail.com
 * Website        : 
 * Twitch         : FrazorBladezSharp
 * Youtube        : Frazor Sharp
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#include <QGuiApplication>

#include "Src/Server/ServerService.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    printf("Welcome to Bladez World.\n");
    printf("Test to send a datagram to udp port 2020 \n");

    ServerService server;
    server.sendDatagrams();

    return a.exec();
}
