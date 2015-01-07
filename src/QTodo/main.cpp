/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    main.cpp
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-6
 */

#include "QTodoMainWin.h"
#include <QApplication>
#include <QTextCodec>

#include "types.h"
#include "Data/TodoData.h"

TodoData l_todo_data0(WIDGET_INDEX0);
TodoData l_todo_data1(WIDGET_INDEX1);
TodoData l_todo_data2(WIDGET_INDEX2);
TodoData l_todo_data3(WIDGET_INDEX3);
TodoData* l_todo_datas[]={
    &l_todo_data0,
    &l_todo_data1,
    &l_todo_data2,
    &l_todo_data3
};

TodoData* getTodoData(int level)
{
    if(level < 0 || level >  WIDGET_INDEX3)
        return NULL;
    return l_todo_datas[level];
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTodoMainWin w;

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    w.show();

    return a.exec();
}
