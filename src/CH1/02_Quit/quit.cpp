#include <QApplication>
#include <QPushButton>
#include <QObject>

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton *button = new QPushButton("quit!");
	QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
	button->show();
	return app.exec();
}
