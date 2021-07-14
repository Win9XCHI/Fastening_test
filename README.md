# Fastening_test

The program is implemented in the C ++ programming language, Qt 5.15.0 framework and SQLite 3.24.0 database. QtCreater 4.14.0 was used as the development environment. Used compiler - MinGW81 x32.

Instructions for deploying the "Fastening test" application

1 Set up password in controller\password_form.cpp (line 19)

2 Build project for release

3 Create separate folder and move here .exe from folder such as "@dir\build-Fastening_test-Desktop_Qt_5_15_0_MinGW_32_bit-Release"

4 Run windeployqt.exe (Qt\5.15.0\mingw81_32\bin) in new folder

5 Move here "resources" folder and "DB_for_test.db"

6 Create installer (https://doc.qt.io/qtinstallerframework/index.html)