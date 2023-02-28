use bit_pc

--管理员查询售票情况的存储过程
go
create procedure select_sells
@t date
as
begin
	delete from sells where number<=0
	delete from sells where buystatus=0  --initialization
	select
	"演出地点"=place,
	"演出时间"=showtime,
	"演出票价"=price,
	"总票数"=ticket,
	"余票"=case when buystatus=1 then ticket-sum(number) else ticket end,
	"演出名称"=title,
	"标识id"=id
	from shows
	left join sells on pid=id
	group by ticket,place,showtime,title,price,buystatus,id
	having showtime>@t
	order by showtime
end

exec select_sells '2021-6-1'

--查询演出信息的存储过程
go
create procedure show_ifo
@t int
as begin
	select
	"演出地点"=place,
	"演出时间"=showtime,
	"演出票价"=price,
	"总票数"=ticket,
	"余票"=case when buystatus=1 then ticket-sum(number) else ticket end,
	"演出名称"=title
	from shows
	left join sells on pid=id
	group by ticket,place,showtime,title,price,buystatus,id
	having id=@t
end

exec show_ifo 1

--准确查询生日的存储过程
go
create procedure select_birthday
@t int
as
begin
select pname as "演员姓名",birthday as "生日",
"年龄"=
(
	case when (
	(datepart(m,getdate())>datepart(m,birthday))
	or(
		(datepart(m,getdate())=datepart(m,birthday))
		and
		(datepart(d,getdate())>datepart(d,birthday))
		)
	)
	then (year(getdate())-year(birthday))
	else (year(getdate())-year(birthday)-1)
	end
),id as "标识id"
from performer
where datepart(m,birthday)=@t
end

go
create procedure select_birthday_null
as
begin
select pname as "演员姓名",birthday as "生日",
"年龄"=
(
	case when (
	(datepart(m,getdate())>datepart(m,birthday))
	or(
		(datepart(m,getdate())=datepart(m,birthday))
		and
		(datepart(d,getdate())>datepart(d,birthday))
		)
	)
	then (year(getdate())-year(birthday))
	else (year(getdate())-year(birthday)-1)
	end
),id as "标识id"
from performer
end

exec select_birthday 8

go
create procedure arrange_se
@t int
as begin
select "上场顺序"=onsequence,
"演出时间"=showtime,
"演员姓名"=pname
from who_onshow
left join shows on shows.id =pid
left join performer on performer.id =onid
where pid=@t
order by onsequence
end

exec arrange_se 3
 
 select * from sells
 update users set pw='1' where id=1520511410