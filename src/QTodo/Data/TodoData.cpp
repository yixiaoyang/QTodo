/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    TodoData.cpp
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-7
 */

#include "TodoData.h"
#include <iostream>

TodoData::TodoData(int m_level)
{
    level = m_level;
}

TodoData::~TodoData()
{
    TodoDataMap::iterator it;
    for(it = dataMap.begin(); it != dataMap.end(); it++){
        it.value().clear();
    }
}

int TodoData::insertItem(QString str)
{
    QDate date = QDateTime::currentDateTime().date();
    TodoDataMap::iterator it = dataMap.find(date);
    int newId = -1;

    TodoItem item(str.toStdString());
    if(it != dataMap.end()){
        it.value().append(item);
        newId = item.getId();
    }else{
        TodoItemList list;
        list.append(item);
        newId = item.getId();
        dataMap.insert(date,list);
    }

    return newId;
}

STATUS TodoData::getTodoList(TodoItemList &list, QDate date)
{
    TodoDataMap::iterator it = dataMap.find(date);
    if(it != dataMap.end()){
        list = it.value();
        return STATUS_OK;
    }
    return STATUS_ERR_NOT_EXISTED;
}

STATUS TodoData::removeListItem(QDate &date, int &id)
{
    int index = 0;
    TodoDataMap::iterator it = dataMap.find(date);
    if(it != dataMap.end()){
        index = it.value().indexOf(TodoItem(id));
        if(index >= 0){
            it.value().remove(index);
        }
        return STATUS_OK;
    }
    return STATUS_FAILED;
}

Json::Value TodoData::list_serialize(TodoItemList& list)
{
    Json::Value val;
    std::string content;

    val["cnt"] = list.size();

    for(int index = 0; index < list.size(); index++){
        content = list[index].serialize();
        val["content"].append(content);
    }
    return val;
}

STATUS TodoData::list_unSerialize(TodoItemList& list, Json::Value &val)
{
    if(val == Json::nullValue)
        return STATUS_FAILED;

    Json::Value valVal = val["val"];
    Json::Value cntVal = valVal["cnt"];

    if(cntVal == Json::nullValue)
        return STATUS_FAILED;
    int cnt = cntVal.asInt();

    list.clear();
    for(int i = 0; i < cnt; i++){
        TodoItem item(valVal["content"][i].asString());
        list.append(item);
    }
    return STATUS_OK;
}


Json::Value TodoData::serialize()
{
    Json::Value val;
    Json::Value dataVal;
    Json::Value itemVal;
    TodoDataMap::iterator it;
    std::string dateStr;

    val["level"] = level;
    val["cnt"] = dataMap.size();
    for(it = dataMap.begin(); it != dataMap.end(); it++){
        dateStr = it.key().toString("yyyy-MM-dd").toStdString();
        itemVal["key"] = dateStr;
        itemVal["val"] = list_serialize(it.value());
        dataVal.append(itemVal);
    }
    val["data"] = dataVal;
    return val;
}

STATUS TodoData::unSerialize(Json::Value &val)
{
    int cnt = val["cnt"].asInt();
    Json::Value dataVal = val["data"];
    TodoItemList list;
    Json::Value itemVal;

    level = val["level"].asInt();
    if(dataVal == Json::nullValue)
        return STATUS_OK;

    for(int i = 0; i < cnt; i++){
        itemVal = dataVal[i];
        if(list_unSerialize(list,itemVal) == STATUS_OK){
            dataMap.insert(QDate::fromString(itemVal["key"].asString().c_str(),"yyyy-MM-dd"),list);
        }
    }
    return STATUS_OK;
}

std::string TodoData::getNodeName()
{
    QString str("TodoData-");
    str.append(QString::number(level));

    return str.toStdString();
}
