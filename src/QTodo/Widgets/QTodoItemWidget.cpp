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
#include "Widgets/QTodoItemDetailWidget.h"

static const char* l_bkg_colors[WIDGET_INDEX_MAX]={
    "#FF0000",
    "#FF00FF",
    "#0000FF",
    "#000000"
};
static const QString l_titles[WIDGET_INDEX_MAX]={
#if 0
    "Important && Emergency",
    "!Important && Emergency",
    "Important && !Emergency",
    "!Important && !Emergency"
#else
    QString::fromUtf8("重要且紧急 —— 优先解决立即做"),
    QString::fromUtf8("重要不紧急 —— 制定计划去做"),
    QString::fromUtf8("紧急不重要 —— 有空再说"),
    QString::fromUtf8("不重要不紧急 —— 交给别人去做")
#endif
};

QTodoItemWidget::QTodoItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTodoItemWidget)
{
    ui->setupUi(this);
    data = NULL;

    ui->plainTextEdit->hide();
    date = QDate::currentDate();
}

QTodoItemWidget::~QTodoItemWidget()
{
    QWidget* w = NULL;
    WidgetsMap::iterator it = widgets.begin();
    if(it != widgets.end()){
        w = it.value();
        delete w;
        w = NULL;

        it.value() = NULL;
        it++;
    }
    widgets.clear();

    delete ui;
}

void QTodoItemWidget::resetView(int widgetIndex)
{
    if(widgetIndex >= WIDGET_INDEX_MAX || widgetIndex < 0)
        return ;

    colorStyle = QString("color:");
    data = getTodoData(widgetIndex);
    colorStyle.append(l_bkg_colors[widgetIndex]);
    ui->plainTextEdit->setStyleSheet(colorStyle);

    ui->label_title->setText(l_titles[widgetIndex]);
    ui->label_title->setStyleSheet(colorStyle);

    ui->label_count->setStyleSheet(colorStyle);
}

void QTodoItemWidget::updateView()
{
    QString str;
    TodoItemList todolist;

    if(STATUS_OK == data->getTodoList(todolist, date)){
        ui->plainTextEdit->clear();
        for(int i = 0; i < todolist.size(); i++)
        {
            str = todolist[i].content;
            insertNewItem(todolist[i].getId(), str);
            ui->plainTextEdit->appendPlainText(str);
        }
    }
}

QTodoItemDetailWidget *QTodoItemWidget::insertNewItem(int newId,QString &content)
{
    QTodoItemDetailWidget* widget = new QTodoItemDetailWidget(newId,this);
    ui->verticalLayout_details->insertWidget(0,(QWidget*)widget);
    widget->setContent(content);
    widget->setBkgColor(colorStyle);

    connect(widget,SIGNAL(itemDone(int)),this,SLOT(itemDone(int)));
    widgets.insert(widget->getId(),widget);

    int childrenCount = ui->widget_details->children().count()-2;
    ui->label_count->setText(QString::number(childrenCount+1));
    return widget;
}

void QTodoItemWidget::on_lineEditTpyeIn_returnPressed()
{
    QString str = ui->lineEditTpyeIn->text();
    int newId = -1;

    if(str.isEmpty())
        return ;

    ui->plainTextEdit->appendPlainText(str);
    if(data){
        newId = data->insertItem(ui->lineEditTpyeIn->text());
    }

    if(newId >= 0){
        insertNewItem(newId,str);
    }

    ui->lineEditTpyeIn->clear();
}

void QTodoItemWidget::itemDone(int id)
{
    WidgetsMap::iterator it = widgets.find(id);
    if(it != widgets.end()){
        int childrenCount = ui->widget_details->children().count()-2;
        ui->label_count->setText(QString::number(childrenCount));

        /* remove widget */
        QWidget* w = it.value();
        ui->verticalLayout_details->removeWidget(w);
        delete w;
        w = NULL;
        widgets.remove(id);

        /* remove data */
        data->removeListItem(date,id);
    }
}
