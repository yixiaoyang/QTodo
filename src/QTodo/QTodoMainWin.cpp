/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    QTodoMainWin.cpp
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-6
 */

#include "QTodoMainWin.h"
#include "ui_QTodoMainWin.h"

#include <QDir>
#include <fstream>
#include <iostream>
#include <QMessageBox>

QTodoMainWin::QTodoMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTodoMainWin)
{
    ui->setupUi(this);

    ui->widget0->resetView(WIDGET_INDEX0);
    ui->widget1->resetView(WIDGET_INDEX1);
    ui->widget2->resetView(WIDGET_INDEX2);
    ui->widget3->resetView(WIDGET_INDEX3);

    userCfgFile.append("./");
    userCfgFile.append(USERCONFIG_FILE);

    loadUserConfig();
    ui->widget0->updateView();
    ui->widget1->updateView();
    ui->widget2->updateView();
    ui->widget3->updateView();
}

QTodoMainWin::~QTodoMainWin()
{
    delete ui;
}


void QTodoMainWin::closeEvent(QCloseEvent *)
{
    saveUserConfig();
}

STATUS QTodoMainWin::saveUserConfig()
{
    TodoData* data;
    std::ofstream fout;
    fout.open (userCfgFile.c_str (),std::ios::out);

    data = getTodoData(WIDGET_INDEX0);
    root[data->getNodeName ()] = data->serialize ();

    data = getTodoData(WIDGET_INDEX1);
    root[data->getNodeName ()] = data->serialize ();

    data = getTodoData(WIDGET_INDEX2);
    root[data->getNodeName ()] = data->serialize ();

    data = getTodoData(WIDGET_INDEX3);
    root[data->getNodeName ()] = data->serialize ();

    fout << root;
    fout.close ();

    return STATUS_OK;
}

STATUS QTodoMainWin::loadUserConfig()
{
    QDir dir;
    std::ifstream fin;
    Json::Reader reader;
    Json::Value val;
    TodoData* data;

    fin.open (this->userCfgFile.c_str (), std::ios::in);
    if (!reader.parse(fin, root, false)){
        qErrnoWarning("[StockData::loadUserConfig()]: root json data null");
        return STATUS_FAILED;
    }
    fin.close ();

    data = getTodoData(WIDGET_INDEX0);
    val = root[data->getNodeName()];
    data->unSerialize(val);

    data = getTodoData(WIDGET_INDEX1);
    val = root[data->getNodeName()];
    data->unSerialize(val);

    data = getTodoData(WIDGET_INDEX2);
    val = root[data->getNodeName()];
    data->unSerialize(val);

    data = getTodoData(WIDGET_INDEX3);
    val = root[data->getNodeName()];
    data->unSerialize(val);

    return STATUS_OK;
}

void QTodoMainWin::on_actionAbout_triggered()
{
    QMessageBox::information(this,"About","by Leon on 10Jan15.\nEmail:hityixiaoyang@gmail.com");

}

void QTodoMainWin::on_actionSave_Config_triggered()
{
    saveUserConfig();
}
