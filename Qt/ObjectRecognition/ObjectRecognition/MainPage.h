#pragma once 
#include <QtWidgets/QMainWindow>
#include "ui_MainPage.h"
//#include "ColorRecognition.h"
#include "VideoCatcher.h"
#include "ObjectCatcher.h"
#include "KCFSelector.h"
#include "Test.h"
class MainPage : public QMainWindow
{
	Q_OBJECT

public:
	MainPage(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainPageClass ui;

public slots:
	void ShowVideoCatcher();
	void ShowObjectCatcher();
	void showKCFSelector();
	void testModule();
};
