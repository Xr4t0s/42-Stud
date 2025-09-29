#!/bin/bash

set -e
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /var/lib/mysql

if [ ! -d /var/lib/mysql ]; then
	echo "Initializing database..."
	mariadbd-install-db --user-mysql --datadir=/var/lib/mysql --skip-test-db
fi

echo "Starting temporary MariaDB..."
mariadbd --user=mysql --datadir=/var/lib/mysql --socket=/run/mysqld/mysqld.sock --skip-networking &
pid="$!"

# Attend que ça réponde
for i in {1..30}; do
  if mysql --protocol=socket -S /run/mysqld/mysqld.sock -uroot -e "SELECT 1" &>/dev/null; then
    break
  fi
  sleep 1
done

# Création base + user
mysql --protocol=socket -S /run/mysqld/mysqld.sock -uroot <<-EOSQL
  CREATE DATABASE IF NOT EXISTS wordpress;
  CREATE USER IF NOT EXISTS 'wp_user'@'%' IDENTIFIED BY 'wp_pass';
  GRANT ALL PRIVILEGES ON wordpress.* TO 'wp_user'@'%';
  FLUSH PRIVILEGES;
EOSQL

mysqladmin --protocol=socket -S /run/mysqld/mysqld.sock -uroot shutdown
wait "$pid"