/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    QTodoItemDetailWidget.cpp
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-7
 */

#include "QTodoItemDetailWidget.h"
#include "ui_QTodoItemDetailWidget.h"

QTodoItemDetailWidget::QTodoItemDetailWidget(int id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTodoItemDetailWidget)
{
    ui->setupUi(this);
    this->id = id;
}

QTodoItemDetailWidget::~QTodoItemDetailWidget()
{
    delete ui;
}

void QTodoItemDetailWidget::on_checkBox_done_clicked()
{
    emit itemDone(this->id);
}

int QTodoItemDetailWidget::getId() const
{
    return id;
}

void QTodoItemDetailWidget::setContent(QString &str)
{
    ui->label->setText(str);
}

void QTodoItemDetailWidget::setBkgColor(QString &colorStr)
{
    ui->label->setStyleSheet(colorStr);
}
