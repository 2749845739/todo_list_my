#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "todolist.h"
#include "todomodel.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  //把C++类注册成qml的model,在qml界面中展示
  qmlRegisterType<ToDoModel>("ToDo", 1, 0, "ToDoModel");
  ToDoList toDoList;

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  //  QObject::connect(
  //      &engine, &QQmlApplicationEngine::objectCreated, &app,
  //      [url](QObject *obj, const QUrl &objUrl) {
  //        if (!obj && url == objUrl) QCoreApplication::exit(-1);
  //      },
  //      Qt::QueuedConnection);
  //  engine.load(url);

  engine.rootContext()->setContextProperty(QStringLiteral("toDoList"),
                                           &toDoList);
  engine.load(url);
  if (engine.rootObjects().isEmpty()) return -1;

  return app.exec();
}
