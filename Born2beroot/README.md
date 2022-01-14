# B2BR info
 
 Гайд Александра @stycho:  
 https://github.com/lesnoyleshyi/born_to_be_root/blob/main/guide
 
### Virtual Box  
   
 Кроссплатформенное приложение для запуска гостевых ОС на хосте. Может использоваться для запуска серверов, создания серверных приложений, для тестирования ПО, тестирования настроек системы и безопасного использования небезопасных источников, для оптимального использования дискового пространства и электричества, исключающего приобретение дополнительных физических машин.  
   
 Виртуальные машины можно разворачивать внутри различных ОС и без какого-либо изменения использовать созданные под одной системой машины на другой ОС. Виртуальные машины можно импортировать и экспортировать из OVF формата, размещать на облачных сервисах.  
   
 На маках установлена поддерживаемая Virtual Box хост-система Mac OS Mojave 10.14 с процессором Intel Core i5. Линейка процессоров Intel Core относится к процессорам, использующим SSE2, а это одно из условий использования Virtual Box.  
   
 Расширения Virtual Box на маках не установлены.
 
### Начало работы  
   
 1.	Загрузка debian 11.1.0.  
   
 https://www.debian.org  
   
 2.	Создание первой виртуальной машины в Virtual Box.  
   
 Для нормальной установки Debian необходимо минимум 256 МБ оперативной памяти и 2 ГБ места на жестком диске.  
 NEW -> my_first_VM | goinfre/dedelmir | Linux | Debian (64-bit) | RAM 1024 MB  
   
 3.	Создание виртуального жесткого диска.  
   
 VDI (VirtualBox Disk Image) - собственный формат Virtual Box для хранения виртуального диска гостевой системы.  
 VHD (Virtual Hard Disk) - формат для хранения виртуального диска от компании Microsoft.  
 VMDK (Virtual Machine Disk) - распространенный использующийся различными программами формат, разработанный VMware.  
 Можно выбрать любой формат, если нет задачи после использовать Disk Image в других программах, иначе следует выбрать подходящий для этих программ формат. Virtual Box читает все.  
   
 4.	Разметка дискового пространства (добавляем разделы).  
 
 MBR (Master Boot Record / главная загрузочная запись) - код и данные, позволяющие перед загрузкой ОС перейти в нужный раздел памяти. BIOS после предварительного теста загружает код и данные в оперативную память и передает управление загрузочному коду.  
 GPT (GUID Partition Table / таблица разделов со статистически уникальным идентификатором) - часть интерфейса для управления оборудованием UEFL, улучшенный новый стандарт, пришедший на смену BIOS и MBR. Исключает важные ограничения MBR на разделение до 2 ТБ дискового пространства и на 4 фактических раздела.  
 При этом MBR работает с UEFI и BIOS, а также поддерживает больше ОС.  
 На Debian по умолчанию установлена GPT, но нумерация разделов как в MBR.  
   
 Каждый новый диск в Linux называется по порядку букв в алфавите:  sda, sdb, sdc … sdAa, sdAb … sdZz (sd - SCSI device, в настоящее время обозначает любое доступное блочное устройство aka микроконтроллер).  
 Разделы диска (тома) идентифицируются цифрами (sda1, sda2 …), при чем 1-4 используются для фактических томов в MBR, остальные - для логических томов. Первый найденный SCSI CD-ROM называется sr0 или scd0. Все блочные устройства перечислены в директории dev (devices / устройства), каждое из них представлено в виде файла.  
 Какое блочное устройство (в том числе тома разделов) имеет мажорный и минорный номер. Первый отображает тип устройства, второй - номер устройства в системе или режим его работы. Команда lsblk выводит имя устройства, мажорный и минорный номер, является ли устройство съемным (RM), его размер, права доступа, тип (диск или том), точку монтирования.  
   
 Разделение диска для бонусной части: https://www.youtube.com/watch?v=2w-2MX5QrQw  
 Установить размеры разделов в соответствии с таблицей Рамиля @krulindi:  
   <img width="337" alt="Screen Shot 2021-12-04 at 5 25 12 PM" src="https://user-images.githubusercontent.com/36924982/144713080-855ebcda-8d90-4304-9ad8-8f6fb343070d.png">

   
 @stycho: https://www.8host.com/blog/osnovy-upravleniya-ustrojstvami-xraneniya-dannyx-v-linux/  
   
 5.	Разрешение загрузки GRUB.  
   
 Основной Единый Загрузчик GRUB (Grand Unified Bootloader) - загрузчик операционных систем. Самый популярный загрузчик в Linux, на Debian, как и на большинстве других дистрибутивов, является загрузчиком по умолчанию (GRUB 2).
 
### sudo  
   
 sudo (substitude user and do / сменить пользователя и выполнить) - выполняет команду с правами указанного пользователя.   Существует ограничение на список команд, которые доступны для выполнения с sudo для выбранного пользователеля. По умолчанию права меняются на права root пользователя. Можно сохранить пользовательское окружение, используя флаг E, или выполнить от имени группы с флагом g.  
   
 Для установки: apt install sudo (под root)  
 Добавить пользователя dedelmir в группу adduser dedelmir sudo (под root)  
 Эквиваленты (не проверяла):  
 sudo usermod -aG sudo username  
 sudo gpasswd -a username sudo  
 Удалить: sudo deluser dedelmir sudo (или под root без sudo в начале)  
 Список пользователей в группе: cat /etc/group | grep sudo  
   
 Просмотрим файл конфигураций /etc/sudoers. В нем указано, что он может быть отредактирован только с помощью команды visudo.  
 Используем visudo, чтобы настроить sudo. Visudo по умолчанию использует редактор nano, для выхода из него нажать control + X (далее подтвердить изменения Y или отменить N). Можно также временно сменить редактор для visudo на vim (установить vim: apt install vim) с помощью следующей команды:  
 sudo EDITOR=vim visudo  
 Используем мануал для изменения настроек sudo в соответствии с subject:  
 https://blog.sedicomm.com/2018/03/21/poleznye-nastrojki-sudoers-dlya-sudo-v-linux/
 
### AppArmor  
   
 AppArmor - это система обязательного контроля доступа для защиты системы от известных и еще неизвестных уязвимостей. Она позволяет определить права программ и запретить им выполнять действия, для которых им прав не хватает.  
 Она по умолчанию установлена и запущена на версиях Debian начиная с 10. Для проверки состояния AppArmor необходимо выполнить команду:  
 cat /sys/module/apparmor/parameters/enabled  
 Она распечатывает в терминале “Y”, если AppArmor активна.  
 Список загруженных AppArmor профилей с указанием статуса работы (enforced, complain, unconfined): sudo aa-status
 
### SSH  
   
 SSH расшифровывается как Secure Shell, это криптографический сетевой протокол (набор правил для передачи данных), используемый для удаленного подключения к серверам Linux/Unix через интерфейс командной строки. Программа SSH была разработана для повышения безопасности приложений, которые использовались ранее.  
 Во время подключения клиента к серверу через SSH сначала проверяется подключение клиента к серверу, затем соединение шифруется, происходит аутентификация клиента на сервере. Если ни на одном из шагов не обнаруживается ошибок, клиент и сервер могут далее обменяться информацией.  
   
 SSH поставляется в виде метапакета (файла зависимостей от нескольких других инструментов: ssh, scp, ssh-keygen), поэтому для установки (если установка SSH не была выполнена в процессе установки ОС) необходимо выполнить всего одну команду:  
 sudo apt-get install ssh  
 По завершении установки SSH сервер запускается на виртуальной машине в режиме демона(“daemon”, в фоновом режиме, без взаимодействия с пользователем, иногда такие процессы называются службами). Проверка запуска: systemctl status sshd
 Если SSH не установлен, возвращается “Unit sushi.service could not be found.”  
 После установки статус меняется на активный, выводится информация о процессе.  
   
 Изменение порта по умолчанию(22) в файле конфигурации:   
 /etc/ssh/sshd_config - файл настроек (конфигурации) демона  
 https://itproffi.ru/ustanovka-i-nastrojka-servera-ssh-v-linux/ - про файл конфигурации и его изменение  
 Проверка порта: cat /etc/ssh/sshd_config | grep ^Port   
 Изменение порта из командной строки: sudo sed -i ’s/#Port 22/Port 4242/‘ /etc/ssh/sshd_config  
 Можно изменить вручную строчку c номером порта в файле /etc/ssh/sshd_config, раскомментировав ее и изменив значение.  
 Проверим возможность подключаться по SSH под root: cat /etc/ssh/sshd_config | grep ^PermitRootLogin  
 Можно раскомментировать строку и установить значение “no” вместо “prohibit-password” также вручную через vim (установить apt install vim) или с помощью команды:  
 sudo sed -i ’s/#PermitRootLogin prohibit-password/PermitRootLogin no/‘ /etc/ssh/sshd_config  
   
 Изменение порта по умолчанию и запрет на аутентификацию пользователя root необходимы для безопасного функционирования системы.   Использование стандартных настроек облегчает роботам и злоумышленникам задачу подбора персональных данных, необходимых для аутентификации. Им остается подобрать только пароль.  
 После изменений можно сохранить систему и произвести перезагрузку или выполнить перезагрузку демона:  
 sudo systemctl restart ssh.service
 
### UFW  
   
 @stycho: https://andreyex.ru/debian/kak-nastroit-brandmauer-s-ufw-v-debian-10/  
 Проверка статуса UFW: sudo ufw status verbose  
 Информация о профиле ssh: sudo ufw app info OpenSSH  
 При желании можно изменить порт 22 в настройках профилей приложений /etc/ufw/applications.d, затем необходимо обновить профиль sudo ufw app update OpenSSH
 
### Подключение к серверу по ssh  
   
 Проброс порта: https://evlanoff.wordpress.com/2017/11/23/port-forwarding-in-virtualbox/  
 Подробнее про NAT: https://wiki.merionet.ru/seti/13/nat-na-palcax-chto-eto/  
 IP виртуальной машины можно получить с помощью команды: sudo ip address (Linux)  
 IP хоста: ifconfig (Mac OS)  
 Подключение по SSH с хоста к виртуальной машине @stycho https://comp-security.net/подключиться-к-виртуальной-машине-по-ssh/  
 ssh dedelmir@localhost -p 2223 (2223 - Host Port)  
 ssh root@localhost -p 2223
 
### Политика паролей  
   
 Смена пароля от своего имени: passwd   
 От имени администратора: sudo passwd dedelmir  
   
 Конфигурации паролей (символов): /etc/pam.d/common-password  
 https://losst.ru/nastrojka-pam-v-linux  
 В указанном выше файле конфигураций пароля можно найти информацию о том, какие модули PAM (Pluggable Authentication Modules) применяются для проверки, а также в нем можно установить собственные параметры проверки.  
 Для проверки применяются pam_unix, pam_deny, pam_permit. Первый модуль можно настроить определенным образом, чтобы при проверке пароля данные о нем записывались определенным образом и в определенные места в памяти. Второй модуль призван отказывать в доступе определенным перечисленным в дополнительном файле пользователям, опции для него отсутствуют. Последний модуль просто всегда пропускает пароль, считая по умолчанию, что он очень надежный, больше он ничего не делает, настроить его нельзя.  
 Необходимо установить дополнительный модуль и прописать в указанном выше файле опции для него. Этот модуль сможет проверить пароль на надежность.  
 sudo apt install libpam-pwquality  
 Проверить установку: apt-cache policy \*pam-pwquality\*  
 Настройки: man pam_pwquality  
 Применение настроек: добавить в файл конфигураций новый запрос на проверку пароля, установить обязательность required (тест должен быть обязательно пройден, но следующие строки тоже будут проверяться) и подключить модуль для проверки pam_pwquality.so, далее перечислить настройки, включая enforce_for_root.   
 Например (не все правила настроены):  
 password		required		pam_pwquality.so minlen=10 enforce_for_root  
 Если запрос, содержащий проверку модулем pwquality уже есть, то его нужно удалить/закомментировать/отредактировать. Несколько запросов не оставлять.  
 Этот запрос необходимо прописать выше requisite запроса, потому что после requisite ничего не проверяется.  
 difok по умолчанию не применяется к паролям пользователя root.  
   
 Конфигурации паролей (сроки изменения): /etc/login.defs  
 PASS_MAX_DAYS, PASS_MIN_DAYS, PASS_WARN_AGE  
 Для созданных ранее пользователей все это нужно настроить вручную с помощью следующих команд:  
 Максимальное количество дней действия пароля: sudo chage -M 30 dedelmir  
 Минимальное количество дней действия пароля: sudo chage -m 2 dedelmir  
 Предупреждение за 7 дней до M: sudo chage -W 7 dedelmir  
 Текущие данные для пароля пользователя: sudo chage -l dedelmir  
 Для root то же самое, нужно настраивать вручную.
 
### Добавление и удаление пользователей и групп  
   
 Добавить пользователя: sudo adduser anna  
 Удалить пользователя: deluser --remove-home  
 Умное удаление пользователя: https://losst.ru/kak-udalit-polzovatelya-linux  
 Добавить группу: sudo addgroup user42  
 Добавить пользователя в группу:  sudo adduser anna user42  
 Просмотреть изменения: cat /etc/group или getent group (… | grep user42 для просмотра данных об определенной группе)  
 Удалить пользователя из группы: sudo deluser anna user42  
 Удалить группу: groupdel user42
 
### Мониторинг состояния системы с cron  
   
 Архитектура операционной системы и версия ядра:  
 uname -a  
 Количество физических процессоров:  
 grep 'physical id' /proc/cpuinfo | sort -u | wc -l  
 Количество виртуальных процессоров:  
 nproc или getconf \_NPROCESSORS_CONF  
 Объем доступной памяти (ОЗУ) и коэффициент ее использования:  
 free -b | awk '$1 == "Mem:" {printf("%d/%dMB (%.2f%%)", ($2-$4)/1024/1024, $2/1024/1024, ($2-$4)/$2\*100)}'  
 Объем доступной памяти (ПЗУ) и коэффициент ее использования:  
 df --total | awk '$1 == "total" {printf("%d/%dMB (%.f%%)", $4/1024/1024, $2/1024/1024, $4/$2\*100)}'  
 Коэффициент использования процессоров:  
 top -bn1 | sed -n 3p | awk '{print 100-$8"%"}'  
 Дата и время последней перезагрузки:  
 who -b | awk '{print $3" "$4}'  
 Активен ли LVM:  
 if [$(cat /etc/fstab | grep dev/mapper | wc -l) == 0]; then echo "no"; else echo "yes"; fi  
 \*все названия логических томов в таблице файловой системы fstab начинаются с dev/mapper  
 Количество активных подключений TCP:  
 cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3}'  
 Количество пользователей на сервере:  
 who | awk '{print $1}' | sort -u | wc -l  
 \*сортировать и объединять нужно для того, чтобы исключить повторяющихся пользователей при подключении с разных устройств  
 IPv4-адрес вашего сервера и его MAC-адрес:  
 hostname -I  
 ip -br link | awk '$1 == "enp0s3" {print $3}'  
 \*адрес возвратной петли используется в основном для диагностики подключения  
 Количество команд, выполняемых под sudo:  
journalctl _COMM=sudo -q | grep "COMMAND" | wc -l  
   
 cron - служба для выполнения команд по расписанию  
 Ищет crontab файлы в /var/spool/cron/crontabs и использует их как руководство к действию. Для редактирования crontab файлов
 используется команда crontab -e.  
 В crontab файле необходимо прописать правило следующего вида:  
 \* \* \* \* \*	command  
 звездочки означают последовательно минуты, часы, дни, месяцы и годы, в которые необходимо выполнить команду. Можно задавать последовательности или диапазоны значений для каждого поля. Неопределенные поля по умолчанию являются диапазонами между крайними возможными значениями (например, * в поле ДЕНЬ означает 1-31)
 
### Веб-сервер LIGHTTPD  
   
 sudo apt install lighttpd  
 sudo ufw allow 80  
 systemctl status lighttpd  
 Настройки: /etc/lighttpd/lighttpd.conf  
 Проверка порта:  
 sudo cat /etc/lighttpd/lighttpd.conf | grep ^server.port  
 или lsof -i :80 | grep LISTEN  
 Пробросить 80-ый порт хоста на 80-ый порт гостевой ОС  
 Просмотр заглушки в браузере: http://localhost:80  
 После загрузки Wordpress заглушку можно просмотреть следующим образом:  
 В папке cd /var/www/html/ создать копию файла, заменив название, например, вот так  
 sudo cp index.lighttpd.html servinfo.html  
 Теперь заглушка доступна по адресу: http://localhost:80/servinfo.html
 
### PHP  
   
 sudo apt install php php-fpm  
 В файле конфигураций sudo vim /etc/php/7.4/fpm/php.ini  раскомментировать  
 cgi.fix_pathinfo=1  
 В папке cd /etc/lighttpd/conf-available/ создать резервную копию файла  
 sudo cp 15-fastcgi-php.conf 15-fastcgi-php.conf.bak  
 В файле sudo vim 15-fastcgi-php.conf закомментировать  
 "bin-path" => "/usr/bin/php-cgi",  
 "socket" => "/var/run/lighttpd/php.socket",  
 Добавить строку  
 "socket" => "/var/run/php/php7.4-fpm.sock”,  
 Включить поддержку php на сервере:  
 	1.	sudo lighty-enable-mod fastcgi  
 	2.	sudo lighty-enable-mod fastcgi-php  
 	3.	sudo service lighttpd force-reload  
 Создать файл sudo vim /var/www/html/phpinfo.php  
 Содержимое файла:
 
     <?php phpinfo(); ?>
 
 В браузере перейти по ссылке http://localhost:80/phpinfo.php
 
### Команды для Maria DB  
   
 sudo apt install mariadb-server  
 sudo systemctl status mariadb  
 sudo mysql_secure_installation  
 sudo mariadb   
 CREATE DATABASE database;  
 SHOW DATABASES;  
 DROP DATABASE database;  
 CREATE USER 'user'@'localhost' IDENTIFIED BY ‘password’;  
 DROP USER 'user'@'localhost';  
 SHOW GRANTS FOR 'user'@'localhost';  
 GRANT <PRIV_TYPE> ON database.table TO 'user'@'localhost';  
 GRANT <PRIV_TYPE> database.* TO 'user'@'localhost';  
 REVOKE <PRIV_TYPE> ON database.table FROM 'user'@'localhost';  
 GRANT <PRIV_TYPE>, GRANT OPTION ON database.table TO 'user'@'localhost';  
 REVOKE <PRIV_TYPE>, GRANT OPTION ON database.table FROM 'user'@'localhost';  
 FLUSH PRIVILEGES;  
 exit  
 Необходимо создать базу данных, пользователя, дать пользователю права для управления базой данных (ALL), утвердить права и выйти.
 
### WordPress  
   
 sudo apt install wget  
 sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html  
 sudo tar -xzvf /var/www/html/latest.tar.gz  
 sudo rm /var/www/html/latest.tar.gz  
 sudo cp -r /var/www/html/wordpress/* /var/www/html  
 sudo rm -rf /var/www/html/wordpress  
 sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php  
 В файле sudo vim /var/www/html/wp-config.php заменить  
 23 define( 'DB_NAME', 'database_name_here' );^M  
 26 define( 'DB_USER', 'username_here' );^M  
 29 define( 'DB_PASSWORD', 'password_here' );^M  
 на настоящие названия  
 sudo apt install php-mysql  
 Сайт доступен для редактирования по адресу: http://localhost:80/wp-login.php  
 Сайт доступен для просмотра: http://localhost:80/  
  
 ![template](https://user-images.githubusercontent.com/36924982/144729786-62b862a5-7e65-444d-9233-e65409960a9d.jpg)


### Fail2Ban  
   
 apt install fail2ban  
 Создать файл с дополнительными правилами для ssh sudo vim /etc/fail2ban/jail.local:  
 https://putty.org.ru/articles/fail2ban-ssh.html  
 Перезапустить сервис: sudo service fail2ban restart и проверить:  
 sudo service fail2ban status или systemctl status fail2ban  
 Последние действия: sudo tail /var/log/fail2ban.log  
 Теперь можно пытаться подключиться по ssh, вводя неправильные пароли  
