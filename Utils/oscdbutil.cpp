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

#include "oscdbutil.h"

OSCDbUtil* OSCDbUtil::dbHelper = NULL;

OSCDbUtil::OSCDbUtil()
{
    //create sqlite
    db = QSqlDatabase::addDatabase(DB_DRIVER);
    db.setDatabaseName(DB_NAME);
    //open sqlite and create table
    if (db.open()) {
        qDebug() << "open success";
        //create table
        QSqlQuery query;
         qDebug() << "exec" <<query.exec(DB_TABLE);
         qDebug() << "insert " << query.exec(QObject::tr("insert into osc(loginname,password) values('sss','朱丛启')"));
    }
    else{
        qDebug() << db.lastError().text();
    }
}

/**
 * the DbHelper handle
 * Common handle
 */
OSCDbUtil *OSCDbUtil::getDbHelper()
{
    if (dbHelper == NULL) {
        dbHelper = new OSCDbUtil();
    }
    return dbHelper;
}

/**
 * close the db connection
 */
void OSCDbUtil::closeDb()
{
    db.close();
}
