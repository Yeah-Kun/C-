#include "MainPage.h"
#include <QtWidgets/QApplication>
#include "ColorRecognition.h"
#include "ObjectCatcher.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainPage w;
	w.show();
	return a.exec();
}
