/*
	update by Ian in 2018-8-24 15:19:01
	UIÖ÷Ò³Ãæ
*/

#include "MainPage.h"

MainPage::MainPage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Test test;
	connect(ui.video, &QAction::triggered, this, &MainPage::ShowVideoCatcher);
	connect(ui.color_selector, &QAction::triggered, this, &MainPage::ShowObjectCatcher);
	connect(ui.KCF_selector, &QAction::triggered, this, &MainPage::showKCFSelector);
	connect(ui.VideoProcessor, &QAction::triggered, this, &MainPage::testModule);
}

void MainPage::ShowVideoCatcher()
{
	VideoCatcher* V = new VideoCatcher();
	ui.mdiArea->addSubWindow(V);
	V->show();
}

void MainPage::ShowObjectCatcher()
{
	ObjectCatcher* o = new ObjectCatcher();
	ui.mdiArea->addSubWindow(o);
	o->show();
}

void MainPage::showKCFSelector()
{
	KCFSelector* selector = new KCFSelector();
	ui.mdiArea->addSubWindow(selector);
	selector->show();
}

void MainPage::testModule()
{
	Test test;
	std::cout << "start test";
	//test.test_VideoProcessor();
	test.test_temp_module();
	std::cout << "end test";
}
