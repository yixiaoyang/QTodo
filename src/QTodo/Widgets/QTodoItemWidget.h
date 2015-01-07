/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    QTodoItemWidget.h
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-6
 */

#ifndef QTODOITEMWIDGET_H
#define QTODOITEMWIDGET_H

#include <QWidget>
#include <QString>

#include "types.h"
#include "Data/TodoData.h"
#include <QMap>

#include "Widgets/QTodoItemDetailWidget.h"

namespace Ui {
class QTodoItemWidget;
}

typedef QMap<int,QWidget*> WidgetsMap;

class QTodoItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QTodoItemWidget(QWidget *parent = 0);
    ~QTodoItemWidget();

public:
    QString title;
    int todoCnt;
    int bkgColor;
    QString colorStyle;

    void resetView(int widgetIndex);
    void updateView();

private:
    Ui::QTodoItemWidget *ui;
    TodoData* data;
    WidgetsMap widgets;
    QDate date;

    QTodoItemDetailWidget *insertNewItem(int id, QString &content);
signals:
    void itemInserted(int index, int id);
private slots:
    void on_lineEditTpyeIn_returnPressed();
    void itemDone(int id);
};

#endif // QTODOITEMWIDGET_H
