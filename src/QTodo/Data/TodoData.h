/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    TodoData.h
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-7
 */

#ifndef TODODATA_H
#define TODODATA_H

#include "types.h"
#include "Serialize.h"
#include "TodoItem.h"

#include <QVector>
#include <QDate>
#include <QMap>
#include <QDate>
#include <QDateTime>

typedef QVector<TodoItem> TodoItemList;
typedef QMap<QDate,TodoItemList> TodoDataMap;

class TodoData : public Serialize
{
private:
    int level;
    TodoDataMap dataMap;
public:
    TodoData(int m_level);
    ~TodoData();

    STATUS insertItems(QString str);
    STATUS getTodoList(TodoItemList& list,QDate date);
    // Serialize interface
public:
    static Json::Value list_serialize(TodoItemList& list);
    static STATUS list_unSerialize(TodoItemList& list,Json::Value &val);

    Json::Value serialize();
    STATUS unSerialize(Json::Value &val);
    std::string getNodeName();
};

TodoData* getTodoData(int level);

#endif // TODODATA_H
