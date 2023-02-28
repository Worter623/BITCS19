create database bit_pc
use bit_pc

create table user_type
(
	id int NOT NULL primary key,
	typename varchar(12) NOT NULL,
)
EXECUTE sp_addextendedproperty   N'MS_Description','用户类型表',N'user',N'dbo',N'table',N'user_type',NULL,NULL
EXECUTE sp_addextendedproperty   N'MS_Description','用户类型标识编号',N'user',N'dbo',N'table',N'user_type',N'column',N'id'
EXECUTE sp_addextendedproperty   N'MS_Description','用户类型类型名(观众/普通用户、主办方/管理员)',N'user',N'dbo',N'table',N'user_type',N'column',N'typename'

create table users
(
	id int NOT NULL primary key,
	typeid int NOT NULL,
	username varchar(12),
	pw varchar(12) NOT NULL,
	birthday date NOT NULL
)
EXECUTE sp_addextendedproperty   N'MS_Description','用户信息表',N'user',N'dbo',N'table',N'users',NULL,NULL
EXECUTE sp_addextendedproperty   N'MS_Description','用户账号',N'user',N'dbo',N'table',N'users',N'column',N'id'
EXECUTE sp_addextendedproperty   N'MS_Description','用户类型标识编号',N'user',N'dbo',N'table',N'users',N'column',N'typeid'
EXECUTE sp_addextendedproperty   N'MS_Description','用户姓名',N'user',N'dbo',N'table',N'users',N'column',N'username'
EXECUTE sp_addextendedproperty   N'MS_Description','账号密码',N'user',N'dbo',N'table',N'users',N'column',N'pw'
EXECUTE sp_addextendedproperty   N'MS_Description','用户出生日期',N'user',N'dbo',N'table',N'users',N'column',N'birthday'

create table shows
(
	id int NOT NULL primary key,
	showtime date NOT NULL,
	place varchar(12) NOT NULL,
	price int NOT NULL,
	title varchar(50),
	ticket int NOT NULL
)
EXECUTE sp_addextendedproperty   N'MS_Description','演出信息表',N'user',N'dbo',N'table',N'shows',NULL,NULL
EXECUTE sp_addextendedproperty   N'MS_Description','演出场次标识id',N'user',N'dbo',N'table',N'shows',N'column',N'id'
EXECUTE sp_addextendedproperty   N'MS_Description','演出时间',N'user',N'dbo',N'table',N'shows',N'column',N'showtime'
EXECUTE sp_addextendedproperty   N'MS_Description','演出地点',N'user',N'dbo',N'table',N'shows',N'column',N'place'
EXECUTE sp_addextendedproperty   N'MS_Description','演出票价',N'user',N'dbo',N'table',N'shows',N'column',N'price'
EXECUTE sp_addextendedproperty   N'MS_Description','演出名称',N'user',N'dbo',N'table',N'shows',N'column',N'title'
EXECUTE sp_addextendedproperty   N'MS_Description','演出票总数',N'user',N'dbo',N'table',N'shows',N'column',N'ticket'

create table performer
(
	id int NOT NULL primary key,
	pname varchar(12) NOT NULL,
	birthday date
)
EXECUTE sp_addextendedproperty   N'MS_Description','演出人员信息表',N'user',N'dbo',N'table',N'performer',NULL,NULL
EXECUTE sp_addextendedproperty   N'MS_Description','演出人员编号',N'user',N'dbo',N'table',N'performer',N'column',N'id'
EXECUTE sp_addextendedproperty   N'MS_Description','演出人员姓名',N'user',N'dbo',N'table',N'performer',N'column',N'pname'
EXECUTE sp_addextendedproperty   N'MS_Description','演出人员出生日期',N'user',N'dbo',N'table',N'performer',N'column',N'birthday'

create table who_onshow
(
	pid int NOT NULL,
	onid int NOT NULL,
	onsequence int NOT NULL
)
EXECUTE sp_addextendedproperty   N'MS_Description','参演表',N'user',N'dbo',N'table',N'who_onshow',NULL,NULL
EXECUTE sp_addextendedproperty   N'MS_Description','演出场次标识id',N'user',N'dbo',N'table',N'who_onshow',N'column',N'pid'
EXECUTE sp_addextendedproperty   N'MS_Description','演出人员编号',N'user',N'dbo',N'table',N'who_onshow',N'column',N'onid'
EXECUTE sp_addextendedproperty   N'MS_Description','上场顺序',N'user',N'dbo',N'table',N'who_onshow',N'column',N'onsequence'

create table sells
(
	aid int NOT NULL,
	pid int NOT NULL,
	number int NOT NULL,
	buystatus bit NOT NULL
)
EXECUTE sp_addextendedproperty   N'MS_Description','购票信息表',N'user',N'dbo',N'table',N'sells',NULL,NULL
EXECUTE sp_addextendedproperty   N'MS_Description','用户账号',N'user',N'dbo',N'table',N'sells',N'column',N'aid'
EXECUTE sp_addextendedproperty   N'MS_Description','演出场次标识id',N'user',N'dbo',N'table',N'sells',N'column',N'pid'
EXECUTE sp_addextendedproperty   N'MS_Description','购票数量',N'user',N'dbo',N'table',N'sells',N'column',N'number'
EXECUTE sp_addextendedproperty   N'MS_Description','购票是否成功',N'user',N'dbo',N'table',N'sells',N'column',N'buystatus'

--查询该数据库的数据字典
SELECT  
表名=case when a.colorder=1 then d.name else '' end, 
表说明=case when a.colorder=1 then isnull(f.value,'') else '' end,
字段序号=a.colorder, 
字段名=a.name, 
字段说明=isnull(g.[value],'') ,
主键=case when exists(SELECT 1 FROM sysobjects where xtype='PK' and name in (
   SELECT name FROM sysindexes WHERE indid in(
   SELECT indid FROM sysindexkeys WHERE id = a.id AND colid=a.colid 
   ))) then '√' else '' end, 
外键=case when exists(SELECT 1 FROM sysforeignkeys WHERE fkeyid = d.id and fkey=a.colid) then '√' else '' end, 
类型=b.name, 
长度=COLUMNPROPERTY(a.id,a.name,'PRECISION'), 
允许空=case when a.isnullable=1 then 'YES'else 'NO' end
FROM syscolumns a 
left join systypes b on a.xtype=b.xusertype 
inner join sysobjects d on a.id=d.id and d.xtype='U' and d.name<>'dtproperties' 
left join syscomments e on a.cdefault=e.id 
left join sys.extended_properties g on a.id=g.major_id and a.colid=g.minor_id 
left join sys.extended_properties f on d.id=f.major_id and f.minor_id =0    
order by a.id,a.colorder


