FROM	debian:buster

RUN		apt-get update
RUN		apt-get install -y \
		mariadb-server \
		php-mysql \
		vim \
		dumb-init

COPY	conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY	conf/init.sh /tmp/init.sh

# ENTRYPOINT	["/usr/bin/dumb-init"]

CMD		["bash", "/tmp/init.sh"]
