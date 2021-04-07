

# permission setting
chmod 775 ./tmp/setting.sh
chown -R www-data:www-data ./var/www/
chmod -R 755 ./var/www/

# create ssl key and certificate 
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# nginx setting
cp -rp /tmp/default /etc/nginx/sites-available/

# wordpress setting
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data ./var/www/html/wordpress
cp -rp ./tmp/wp-config.php ./var/www/html/wordpress

# create DATABASE for wordpress 
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'hyeonkim'@'localhost' IDENTIFIED BY '0000';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'hyeonkim'@'localhost' WITH GRANT OPTION;" \
	| mysql -u root --skip-password
	
# phpMyAdmin setting
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm phpMyAdmin-5.0.2-all-languages.tar.gz
cp -rp ./tmp/config.inc.php ./var/www/html/phpmyadmin/

service nginx start
service php7.3-fpm start
service mysql restart

