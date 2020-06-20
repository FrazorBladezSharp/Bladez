
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Jun 20th
 *
 *      Bladez - Qt C++ Version Bladez 1.0
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
#include "ServerService.h"
#include <QDebug>

ServerService::ServerService()
    : m_udpSocket(new QUdpSocket(this))
{
    m_udpSocket->bind(QHostAddress::LocalHost, 20201);

    connect(m_udpSocket, &QUdpSocket::readyRead,
             this, &ServerService::readPendingDatagrams);
    
    qDebug("ServerService Constructed. \n");
}

ServerService::~ServerService()
{
    delete m_udpSocket;
    qDebug("ServerService Destroyed. \n");
}

void ServerService::sendDatagrams()
{
    QByteArray message = CreateTheDatagram();
    QUdpSocket* tempSocket = new QUdpSocket(this);
    tempSocket->bind(QHostAddress::LocalHost, 2020);
    tempSocket->writeDatagram(message, QHostAddress::LocalHost, 2020);
    qDebug("Datagram Sent. \n");
}

void ServerService::readPendingDatagrams()
{
    while (m_udpSocket->hasPendingDatagrams()) 
    {
        QNetworkDatagram datagram = m_udpSocket->receiveDatagram();
        processTheDatagram(datagram);
    }
}
 
/////////////////////// Private //////////////////////////

QByteArray ServerService::CreateTheDatagram()
{
    QByteArray stuff("This is a test message.");
    return stuff;
}

void ServerService::processTheDatagram(QNetworkDatagram datagram)
{
    qDebug() << "Data Recieved : " << datagram.data();
    QByteArray message = datagram.data();
    QHostAddress sender = datagram.senderAddress();
    qDebug() << "Sent By : " << sender;

    int val = datagram.data().toInt();
    if (val == 0)
    {
        exit(0);
    }
}
