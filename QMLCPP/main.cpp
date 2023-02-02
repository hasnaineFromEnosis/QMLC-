#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include <QDateTime>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQuickView view;
    QQmlContext *context = view.engine()->rootContext();
    context->setContextProperty("_aString", QString("KDAB"));
    context->setContextProperty("_aSize", QSize(800,600));
    context->setContextProperty("_background", QColor(Qt::lightGray));

    view.setSource(QUrl("qrc:/Secondary.qml"));
    view.setTitle("Yo");
    view.show();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
