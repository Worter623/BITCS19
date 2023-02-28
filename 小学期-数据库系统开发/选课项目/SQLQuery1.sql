


USE  LessonChoice
--table!!!!!!!
create table Student (
ID int NOT NULL primary key,
[name] varchar(255),
gender varchar(10),
class int NOT NULL
)

create table Teacher (
ID int NOT NULL primary key,
[name] varchar(255) NOT NULL
)

create table Lessons ( 
[name] varchar(1024) NOT NULL primary key,
credit float NOT NULL,
teacherID int NOT NULL,
[time] varchar(1024)
)

alter table Lessons
   add constraint FK_Lessons_Teacher foreign key (teacherID)
      references Teacher (ID)
go

create table TakeLesson ( 
StudentID int NOT NULL,
Lessonname varchar(1024) NOT NULL
)

alter table TakeLesson
   add constraint FK_TakeLesson_Lesson foreign key (Lessonname)
      references Lessons ([name])
go

alter table TakeLesson
   add constraint FK_TakeLesson_Student foreign key (StudentID)
      references Student (ID)
go

create table TempTakeLesson ( 
StudentID int NOT NULL,
Lessonname varchar(1024) NOT NULL
)

alter table TempTakeLesson
   add constraint FK_TempTakeLesson_Lesson foreign key (Lessonname)
      references Lessons ([name])
go

alter table TempTakeLesson
   add constraint FK_TempTakeLesson_Student foreign key (StudentID)
      references Student (ID)
go


--insert!!!!!!!!!!
insert into Student values(1120190699,' 关晓宇','female',30141901);
insert into Student values(1120190219,' 张三','male',30141901);
insert into Student values(1120191034,' 李四','male',30141901);
insert into Student values(1120190124,' 小红','female',30141901);
insert into Student values(1120191535,' 小明','male',30141901);
insert into Student values(1120195272,' 狗蛋','male',30141901);
insert into Student values(1120191345,' 阿paul','male',30141901);
insert into Student values(1120192521,' 桶同','female',30141901);
insert into Student values(1120190629,' 史莱姆','male',30141901);
insert into Student values(1120190612,' 鸭鸭','male',30141901);
insert into Student values(1120190214,' 家乐福野鸭','male',30141901);
select * from Student



insert into Teacher values(331201,'李长省');
insert into Teacher values(331202,'宋清辉');
insert into Teacher values(331203,'胡静镜');
insert into Teacher values(331204,'张禹龙');
insert into Teacher values(331205,'马博');
insert into Teacher values(331206,'王书亮');
insert into Teacher values(331207,'傅莹');
insert into Teacher values(331208,'汪娟');
insert into Teacher values(331209,'余跃');
insert into Teacher values(331210,'魏胜军');
insert into Teacher values(331211,'杨嵩');
insert into Teacher values(331212,'刘慧');
insert into Teacher values(331213,'王岸');
insert into Teacher values(331214,'金许良');
insert into Teacher values(331215,'钟晓施');
select * from Teacher



insert into Lessons values('数据库开发设计',1.5,331212,'每周一2-5节');
insert into Lessons values('知识工程',2,331201,'每周三2-5节');
insert into Lessons values('机器学习初步',2,331204,'每周一6-7节');
insert into Lessons values('人工智能基础',2.5,331211,'每周二3-5节');
insert into Lessons values('最优化方法',2,331202,'每周五2-5节');
insert into Lessons values('组合数学',2,331208,'每周四9-10节');
insert into Lessons values('Linux系统编程',2,331207,'每周一11-13节');
insert into Lessons values('计算机新技术专题',2,331206,'每周二6-7节');
insert into Lessons values('密码学基础',2.5,331212,'每周五6-7节');
insert into Lessons values('计算机图形学',2.5,331209,'每周四6-7节');
insert into Lessons values('嵌入式计算系统',2.5,331205,'每周三6-8节');
insert into Lessons values('计算机仿真与Matlab',2,331203,'每周一8-9节');
insert into Lessons values('数字图像处理',2.5,331213,'每周四1-2节');
insert into Lessons values('现代人机交互',2,331214,'每周二1-2节');
select * from Lessons

insert into TakeLesson values(1120190699,'计算机仿真与Matlab');
insert into TakeLesson values(1120190699,'现代人机交互');
insert into TakeLesson values(1120190214,'现代人机交互');
insert into TakeLesson values(1120190214,'数字图像处理');

--procedure!!!!!!!!!!!
IF EXISTS (SELECT name FROM sysobjects 
         WHERE name = 'SelectTakenLesson' AND type = 'P')
   DROP PROCEDURE SelectTakenLesson
GO
CREATE PROCEDURE SelectTakenLesson
	@n int
AS
BEGIN
	SELECT Lessons.[name] as '课程名称', Lessons.credit as '学分', Teacher.[name] as '授课教师', Lessons.[time] as '上课时间'
	FROM Lessons INNER JOIN Teacher 
		ON Lessons.teacherID = Teacher.ID INNER JOIN TakeLesson
		ON TakeLesson.Lessonname = Lessons.[name] INNER JOIN Student
		ON TakeLesson.StudentID = Student.ID
	WHERE Student.ID = @n
END
GO

execute SelectTakenLesson 1120190214

IF EXISTS (SELECT name FROM sysobjects 
         WHERE name = 'SelectUntakeLesson' AND type = 'P')
   DROP PROCEDURE SelectUntakeLesson
GO
CREATE PROCEDURE SelectUntakeLesson
	@n int
AS
BEGIN
	SELECT Lessons.[name] as '课程名称', Lessons.credit as '学分', Teacher.[name] as '授课教师', Lessons.[time] as '上课时间'
	FROM Lessons INNER JOIN Teacher 
		ON Lessons.teacherID = Teacher.ID 
	WHERE Lessons.[name] NOT IN (SELECT Lessonname FROM TakeLesson WHERE StudentID = @n)
END
GO

execute SelectUntakeLesson 1120190699


