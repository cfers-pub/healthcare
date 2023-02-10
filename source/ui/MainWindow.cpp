#include "MainWindow.h"
#include "MainpageWidget.h"
#include "settingWidget.h"
#include <QHBoxLayout>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	// mainPage
	ui.tabWidget->addTab(new MainPageWidget, style()->standardIcon(QStyle::SP_DesktopIcon), tr(u8"主页"));

	// SettingWidget
	ui.tabWidget->addTab(new SettingWidget, style()->standardIcon(QStyle::SP_CommandLink), tr(u8"设置"));

	// backGround
	setStyleSheet("MainWindow:{background::}");
}
