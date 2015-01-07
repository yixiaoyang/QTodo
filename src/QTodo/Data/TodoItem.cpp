/*
 * (C) Copyright 2013-2015 Gaoee. All rights reserved.
 *
 * @brief
 * @file    TodoItem.cpp
 * @version 1.0
 * @author  Leon
 * @note
 *      -Create by Leon<hityixiaoyang@gmail.com> on 2015-1-7
 */

#include "TodoItem.h"
#include <cstdlib>
#include <QTextCodec>

static int l_count = 0;

TodoItem::TodoItem()
{
    this->id = l_count++;
}

TodoItem::TodoItem(std::string c)
{
    QTextCodec* gbk_codec = QTextCodec::codecForName("GBK");
    QString gbk_string = gbk_codec->toUnicode(c.c_str());

    content.clear();
    content.append(gbk_string);
    this->id = l_count++;
}

#if 0
Json::Value TodoItem::serialize()
{
    val["content"] = content;
}

STATUS TodoItem::unSerialize(Json::Value &val)
{
    cotnent = val["content"];
}

std::string TodoItem::getNodeName()
{
    return std::string(itoa(level));
}
#else
std::string TodoItem::serialize()
{
    return content.toStdString();
}
#endif
