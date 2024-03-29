﻿/*
*   Copyright 2021 ChenFei
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*/

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
