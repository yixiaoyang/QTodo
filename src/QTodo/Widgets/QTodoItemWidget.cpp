/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    QTodoItemWidget.cpp
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-6
 */

#include "QTodoItemWidget.h"
#include "ui_QTodoItemWidget.h"
#include "types.h"

static const char* l_bkg_colors[WIDGET_INDEX_MAX]={
    "#FF0000",
    "#FF00FF",
    "#0000FF",
    "#000000"
};
static const char* l_titles[WIDGET_INDEX_MAX]={
    "Important && Emergency",
    "!Important && Emergency",
    "Important && !Emergency",
    "!Important && !Emergency"
};

QTodoItemWidget::QTodoItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTodoItemWidget)
{
    ui->setupUi(this);
    data = NULL;
}

QTodoItemWidget::~QTodoItemWidget()
{
    delete ui;
}

void QTodoItemWidget::resetView(int widgetIndex)
{
    QString colorStyle("color:");
    if(widgetIndex >= WIDGET_INDEX_MAX || widgetIndex < 0)
        return ;

    data = getTodoData(widgetIndex);

    colorStyle.append(l_bkg_colors[widgetIndex]);
    ui->plainTextEdit->setStyleSheet(colorStyle);

    ui->label_title->setText(l_titles[widgetIndex]);
    ui->label_title->setStyleSheet(colorStyle);
}

void QTodoItemWidget::updateView()
{
    QDate date = QDate::currentDate();
    TodoItemList list;
    QString str;

    if(STATUS_OK == data->getTodoList(list, date)){
        ui->plainTextEdit->clear();
        for(int i = 0; i < list.size(); i++)
        {
            str = QString::number(i+1);
            str += ". ";
            str += list[i].content;
            ui->plainTextEdit->appendPlainText(str);
        }
    }
}

void QTodoItemWidget::on_lineEditTpyeIn_returnPressed()
{
    QDate date = QDate::currentDate();
    TodoItemList list;
    int count = 1;
    if(STATUS_OK != data->getTodoList(list, date)){
        count = 1;
    }else{
        count = list.size()+1;
    }

    QString str = QString::number(count);
    str += ". ";
    str += ui->lineEditTpyeIn->text();

    ui->plainTextEdit->appendPlainText(str);

    if(data){
        data->insertItems(ui->lineEditTpyeIn->text());
    }

    ui->lineEditTpyeIn->clear();
}
