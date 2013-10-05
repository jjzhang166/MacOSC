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


#ifndef CONSTSTRINGS_H
#define CONSTSTRINGS_H

//common convert
#define CONVERT_TO_C_CHAR(text) \
    QString(text).toStdString().c_str()
//texts
#define REGISTER_TEXT \
    tr("<a href=\"https://www.oschina.net/home/reg/\">还没有账号现在注册一个?</a>")
#define FORGETPASSWORD_TEXT \
    tr("<a href=\"http://www.oschina.net/home/reset-pwd/\">忘记登录密码?</a>")
#define CLEAR_TEXT tr("")
#define RICH_TEXT(color,text) \
    QString(tr("<font color='")).append(tr(color)).append("'>").append(tr(text)).append(tr("</font>"))
#define EMPTY_TEXT CONVERT_TO_C_CHAR(tr("用户名或密码不能为空"))
#define INVALID_TEXT CONVERT_TO_C_CHAR(tr("用户名或密码错误"))
//colors
#define RED_COLOR CONVERT_TO_C_CHAR(tr("red"))       //red
#define GREEN_COLOR CONVERT_TO_C_CHAR(tr("green"))   //green
#define BLUE_COLOR CONVERT_TO_C_CHAR(tr("blue"))     //blue
#define GRAY_COLOR CONVERT_TO_C_CHAR(tr("gray"))     //gray
#define WHITE_COLOR CONVERT_TO_C_CHAR(tr("white"))   //white

#endif // CONSTSTRINGS_H
