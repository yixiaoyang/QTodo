/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    TodoItem.h
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-7
 */

#ifndef TODOITEM_H
#define TODOITEM_H

#include "types.h"
#include "Serialize.h"
#include <QString>

class TodoItem
{
private:
    int level;
    int id;
public:
    QString content;
public:
    TodoItem();
    TodoItem(std::string c);
public:
#if 0
    // Serialize interface

    Json::Value serialize();
    STATUS unSerialize(Json::Value &val);
    std::string getNodeName();
#else
    std::string serialize();
#endif
};

#endif // TODOITEM_H
