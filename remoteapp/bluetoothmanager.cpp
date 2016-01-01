/**
 * Created my Misha Lytvynyuk, xchg.ca, @2015
 */

#include "bluetoothmanager.h"

#include <QDebug>
#include <QBluetoothLocalDevice>
#include <QBluetoothUuid>
#include <QIODevice>

static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");

Bluetoothmanager::Bluetoothmanager(QObject *parent) : QObject(parent),
    m_localDevice(),
    m_btSocket(new QBluetoothSocket(parent)),
    m_command(0),
    m_timer(new QTimer(parent))
{
    QBluetoothLocalDevice localDevice;
    QString localDeviceName;

    // Check if Bluetooth is available on this device
    if (localDevice.isValid()) {

        // Turn Bluetooth on
        localDevice.powerOn();

        // Read local device name
        localDeviceName = localDevice.name();

        // Make it visible to others
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // Get connected devices
        m_remotes = localDevice.connectedDevices();

        qWarning() << "List of devices count" << m_remotes.size() << " Apparently always 0 on Android and iOS";

        QObject::connect(&m_localDevice, &QBluetoothLocalDevice::deviceConnected, this, &Bluetoothmanager::onDeviceConnected);
        QObject::connect(&m_localDevice, &QBluetoothLocalDevice::deviceDisconnected, this, &Bluetoothmanager::onDeviceDisconnected);

        //m_timer->setInterval(100); // every 100ms send the code;
    }
}

void Bluetoothmanager::connect()
{
    QBluetoothAddress btAddress("00:12:04:23:60:88"); // My specific device MAC address, yours WILL be different
    QString uuid("00001101-0000-1000-8000-00805F9B34FB");
    m_btSocket->connectToService(QBluetoothAddress(btAddress), QBluetoothUuid(uuid), QIODevice::ReadWrite);

    QObject::connect(m_btSocket, &QBluetoothSocket::connected, this, []() {
        qWarning() << "Connected to service";
    });

   qWarning() << "Connected to service" << m_btSocket->isOpen();
   qWarning() << "Connected to service" << m_btSocket->error();
   //qWarning() << "Connected to service" << m_btSocket->isOpen();
}

void Bluetoothmanager::setCommand(const int command)
{
    m_command = command;
    m_btSocket->write((char*)&m_command,1); // this is very crude I know
}

void Bluetoothmanager::onDeviceConnected(const QBluetoothAddress &address)
{
    qWarning() << "Connected:" << address.toString();
}

void Bluetoothmanager::onDeviceDisconnected(const QBluetoothAddress &address)
{
    qWarning() << "Disconnected:" << address.toString();
}



