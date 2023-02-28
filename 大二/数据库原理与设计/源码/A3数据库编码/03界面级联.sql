use bit_pc

--级联操作示例如下
alter table who_onshow add constraint onid_performer_id foreign key(onid) references performer(id) on update cascade on delete cascade

ALTER TABLE [dbo].[who_onshow]  WITH CHECK ADD FOREIGN KEY([pid])
REFERENCES [dbo].[shows] ([id])
ON UPDATE CASCADE
ON DELETE CASCADE

ALTER TABLE [dbo].[users]  WITH CHECK ADD FOREIGN KEY([typeid])
REFERENCES [dbo].[user_type] ([id])
ON UPDATE CASCADE
ON DELETE CASCADE

alter table sells add constraint onid_sells_aid foreign key(aid) references users(id) on update cascade on delete cascade

alter table sells add constraint onid_sells_pid foreign key(pid) references shows(id) on update cascade on delete cascade
--尝试修改shows中的id=1至id=10

update shows set id=10 where id=1
select id as '演出场次标识id', showtime as '演出时间',place as '演出地点',title as '演出名称',price as '演出票价', ticket as '演出票总数' from shows
select aid as '购票用户账号', pid as '演出场次标识id',number as '购票数量',buystatus as '购票是否成功(1成功，0失败)' from sells

--在演出人员信息表中删除7号演员橘莉娜
delete from performer where id=7
select id as '演出人员编号', pname as '演出人员姓名', birthday as '出生日期' from performer
select pid as '演出场次标识id', onid as '演出人员编号',pname as '演出人员姓名',onsequence as '上场顺序'
from who_onshow
left join performer on performer.id=onid
where pid>=4

update shows set id=1 where id=10