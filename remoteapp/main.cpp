/**
 * Created my Misha Lytvynyuk, xchg.ca, @2015
 */


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "bluetoothmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Bluetoothmanager btManager;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_btManager", &btManager);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    btManager.connect();

    return app.exec();
}

