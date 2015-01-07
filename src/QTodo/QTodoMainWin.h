/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    QTodoMainWin.h
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-6
 */

#ifndef QTODOMAINWIN_H
#define QTODOMAINWIN_H

#include <QMainWindow>
#include "types.h"

#include "json/json.h"
#include "Data/TodoData.h"

namespace Ui {
class QTodoMainWin;
}

class QTodoMainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit QTodoMainWin(QWidget *parent = 0);
    ~QTodoMainWin();

    STATUS saveUserConfig();
    STATUS loadUserConfig();
private:
    Ui::QTodoMainWin *ui;

    std::string userCfgFile;
    Json::Value root;
    Json::Reader reader;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void on_pushButton_export_clicked();
};

#endif // QTODOMAINWIN_H
