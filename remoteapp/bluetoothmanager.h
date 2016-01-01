/**
 * Created my Misha Lytvynyuk, xchg.ca, @2015
 */

#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include <QObject>

#include <QBluetoothAddress>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>
#include <QTimer>

class Bluetoothmanager : public QObject
{
    Q_OBJECT

public:
    explicit Bluetoothmanager(QObject *parent = 0);

    void connect();

signals:

public slots:
    void setCommand(const int command);

private slots:
    void onDeviceConnected(const QBluetoothAddress &address);
    void onDeviceDisconnected(const QBluetoothAddress &address);

private:
     QList<QBluetoothAddress> m_remotes;
     QBluetoothLocalDevice m_localDevice;
     QBluetoothSocket *m_btSocket;

     int m_command;

     QTimer *m_timer;
};

#endif // BLUETOOTHMANAGER_H
