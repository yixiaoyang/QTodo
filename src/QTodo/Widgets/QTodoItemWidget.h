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

namespace Ui {
class QTodoItemWidget;
}

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

    void resetView(int widgetIndex);
    void updateView();

private:
    Ui::QTodoItemWidget *ui;
    TodoData* data;
signals:
    void itemInserted(int index, int id);
private slots:
    void on_lineEditTpyeIn_returnPressed();
};

#endif // QTODOITEMWIDGET_H
