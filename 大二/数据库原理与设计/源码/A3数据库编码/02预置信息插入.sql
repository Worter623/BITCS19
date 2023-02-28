use bit_pc

insert into user_type values(1,'管理员')
insert into user_type values(2,'普通用户')
select id as '用户类型标识编号', typename as '用户类型类型名' from user_type

insert into users values(1520511410,1,'关晓宇','1520511410','2001.6.23')
insert into users values(1523006999,2,'树Y','tree1062','2001.1.29')
insert into users values(1213389134,2,'桶同','tongtong!','2002.6.1')
select id as '用户账号',typeid as '用户类型标识编号',username as '用户姓名',pw as '密码', birthday as '用户出生日期' from users order by users.id

insert into shows values(2,'2021.7.4','北京',88,'七月四号北京',100)
insert into shows values(3,'2021.7.4','广州',88,'七月四号广州',100)
insert into shows values(4,'2021.7.4','南京',88,'七月四号南京',100)
insert into shows values(5,'2021.6.23','北京',66,'六月二十三北京',100)
insert into shows values(1,'2021.5.5','北京',55,'五月五号北京',100)
insert into shows values(6,'2021.5.5','广州',55,'五月五号广州',100)
insert into shows values(7,'2021.5.7','北京',57,'五月七号北京',100)
select id as '演出场次标识id', showtime as '演出时间',place as '演出地点',title as '演出名称',price as '演出票价', ticket as '演出票总数' from shows
select * from shows

insert into performer values(1,'庞博','1989.2.22')
insert into performer values(2,'豆豆','1996.1.22')
insert into performer values(3,'House','1992.3.20')
insert into performer values(4,'王大哥','1988.8.26')
insert into performer values(5,'CL','1985.5.8')
insert into performer values(6,'思文','1986.4.30')
insert into performer values(7,'橘莉娜','2000.1.1')
select id as '演出人员编号', pname as '演出人员姓名', birthday as '出生日期' from performer

insert into who_onshow values(5,1,1)
insert into who_onshow values(5,2,2)
insert into who_onshow values(5,3,3)
insert into who_onshow values(5,4,4)
insert into who_onshow values(5,5,5)
insert into who_onshow values(5,6,6)
insert into who_onshow values(5,7,7)
insert into who_onshow values(1,2,1)
insert into who_onshow values(2,4,1)
insert into who_onshow values(2,5,2)
insert into who_onshow values(3,6,1)
insert into who_onshow values(3,1,2)
insert into who_onshow values(4,2,1)
insert into who_onshow values(4,7,2)
insert into who_onshow values(6,7,1)
insert into who_onshow values(6,1,2)
insert into who_onshow values(6,4,3)
insert into who_onshow values(7,1,2)
insert into who_onshow values(7,5,1)
insert into who_onshow values(7,7,3)
select pid as '演出场次标识id', onid as '演出人员编号',onsequence as '上场顺序' from who_onshow

insert into sells values(1523006999,2,2,1)
insert into sells values(1523006999,1,10,1)
insert into sells values(1213389134,6,10,1)
insert into sells values(1213389134,6,10,0)
insert into sells values(1213389134,5,1,1)
select aid as "购票用户账号", pid as "演出场次标识id",number as '购票数量',buystatus as '购票是否成功' from sells

