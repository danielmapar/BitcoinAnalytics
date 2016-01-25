http://curl.haxx.se/docs/install.html

brew install curl ==> -lcurl
brew install mysql
brew install mysql-connector-c++ ==> -lmysqlcppconn
brew install jsoncpp (https://github.com/cuber/homebrew-jsoncpp) ==> -ljsoncpp

mysql.server start // also mysql.server restart
mysql_secure_installation // First set up

mysql -u root -p
SHOW DATABASES;
USE test;
SHOW TABLES;

g++ mysql_test.cpp -lmysqlcppconn

mysql_upgrade -u root --force // if necessary

g++ main.cpp curly.cpp -lcurl