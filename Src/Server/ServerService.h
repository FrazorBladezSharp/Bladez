
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
#pragma once

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QByteArray>

class ServerService : public QObject
{
    Q_OBJECT

        QUdpSocket* m_udpSocket;

    public:
        explicit ServerService();
        ~ServerService();
        void sendDatagrams();
        void readPendingDatagrams();
 
    private:
        QByteArray CreateTheDatagram();
        void processTheDatagram(QNetworkDatagram datagram);
};