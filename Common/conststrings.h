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
