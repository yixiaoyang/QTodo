/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    QTodoItemDetailWidget.h
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-7
 */

#ifndef QTODOITEMDETAILWIDGET_H
#define QTODOITEMDETAILWIDGET_H

#include <QWidget>

namespace Ui {
class QTodoItemDetailWidget;
}

class QTodoItemDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QTodoItemDetailWidget(int id,QWidget *parent);
    ~QTodoItemDetailWidget();

    int getId() const;
    void setContent(QString& str);
    void setBkgColor(QString& colorStr);
private slots:
    void on_checkBox_done_clicked();

private:
    Ui::QTodoItemDetailWidget *ui;
    int id;
signals:
    void itemDone(int id);
};

#endif // QTODOITEMDETAILWIDGET_H
