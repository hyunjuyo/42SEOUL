#!bin/bash

service mysql start

echo "create database if not exists db_1;" | mysql
echo "create user if not exists 'user_1'@'mariadb:3306' identified by '1234567';" | mysql
echo "grant all privileges on db_1.* to 'user_1'@'localhost' with grant option;" | mysql
echo "flush privileges;" | mysql

service mysql stop
exec /usr/sbin/mysqld -u root
