#ifndef CONSTSTRINGS_H
#define CONSTSTRINGS_H

#define REGISTER_TEXT tr("<a href=\"https://www.oschina.net/home/reg/\">还没有账号现在注册一个?</a>")
#define FORGETPASSWORD_TEXT tr("<a href=\"http://www.oschina.net/home/reset-pwd/\">忘记登录密码?</a>")
#define CLEAR_TEXT tr("")
#define RICH_TEXT(color,text) QString(tr("<font color='")).append(tr(color)).append("'>").append(tr(text)).append(tr("</font>"))

#endif // CONSTSTRINGS_H
