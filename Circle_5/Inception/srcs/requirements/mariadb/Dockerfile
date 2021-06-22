FROM	debian:buster

RUN		apt-get update
RUN		apt-get install -y \
		mariadb-server \
		mariadb-client \
		php-mysql \
		vim \
		dumb-init

COPY	conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY	conf/50-client.cnf /etc/mysql/mariadb.conf.d/50-client.cnf
COPY	conf/init.sh /tmp/init.sh

EXPOSE	3306

# ENTRYPOINT	["/usr/bin/dumb-init"]

# ENTRYPOINT	["bash", "/tmp/init.sh"]
CMD		["bash", "/tmp/init.sh"]
# CMD		["mysqld_safe"]
