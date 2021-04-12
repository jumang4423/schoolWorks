drop table if exists dmap;
drop table if exists tmap;
create table dmap ( City text, Neighbor text, Distance int );

insert into dmap values ( 'A' , 'B' , 14);
insert into dmap values ( 'A' , 'C' , 9);
insert into dmap values ( 'A' , 'D' , 7);
insert into dmap values ( 'B' , 'E' , 9);
insert into dmap values ( 'B' , 'C' , 2);
insert into dmap values ( 'C' , 'D' , 10);
insert into dmap values ( 'C' , 'F' , 11);
insert into dmap values ( 'D' , 'F' , 15);
insert into dmap values ( 'E' , 'F' , 6);

insert into dmap select Neighbor,City,Distance from dmap;

create table tmap ( City text, Destination text, Distance int, Route text );
insert into tmap select City,Neighbor,Distance,'-'||Neighbor from dmap;

