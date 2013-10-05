/*****************************************************************************************
 ** The MIT License (MIT)

 ** Copyright (c) 2013 BruceZCQ
 ** http://zhucongqi.cn
 ** Contact: brucezcq@gmail.com

 ** Permission is hereby granted, free of charge, to any person obtaining a copy of
 ** this software and associated documentation files (the "Software"), to deal in
 ** the Software without restriction, including without limitation the rights to
 ** use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 ** the Software, and to permit persons to whom the Software is furnished to do so,
 ** subject to the following conditions:

 ** The above copyright notice and this permission notice shall be included in all
 ** copies or substantial portions of the Software.

 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 ** FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 ** COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 ** IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 ** CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *****************************************************************************************/

#include "oscuser.h"

OSCUser::OSCUser(QHash<QString,QString> hash)
{
    uid = hash.value(USER_UID_NODE).toInt();
    location = hash.value(USER_LOCATION_NODE);
    name = hash.value(USER_NAME_NODE);
    followers = hash.value(USER_FOLLOWERS_NODE).toInt();
    fans = hash.value(USER_FANS_NODE).toInt();
    score = hash.value(USER_SCORE_NODE).toInt();
    portrait = hash.value(USER_PORTRAIT_NODE);
}

quint32 OSCUser::getUid()
{
    return uid;
}

QString OSCUser::getLocation()
{
    return location;
}

QString OSCUser::getName()
{
    return name;
}

quint32 OSCUser::getFollowers()
{
    return followers;
}

quint32 OSCUser::getFans()
{
    return fans;
}

quint32 OSCUser::getScore()
{
    return score;
}

QString OSCUser::getPortrait()
{
    return portrait;
}
