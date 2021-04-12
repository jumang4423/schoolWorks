getent passwd | awk -F: '{print $1"|"$4"|"$5"|"$7}' > users.dat
create table users (uid text, gid int, uname text, shell text);
.import users.dat users
select * from users where shell like '%/bash';
select distinct shell from users where shell not like '%/bash';
select count(*) from users where uid like 's1%';
select * from users where uname like '%ko %';



