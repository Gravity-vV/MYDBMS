# myDBMS
## New features  
- 将bash的界面做了调整，支持连续读入sql语句
- 添加了double类型，支持对double类型的比较，插入，修改
- 将两表链接查询扩展至多表链接查询
- 添加了批处理文件runsql.sh
## for run :  
  RE:  
  WSL:
  - Distributor ID: Ubuntu
  - Description:    Ubuntu 22.04.1 LTS
  - Release:        22.04
  - Codename:       jammy  
  
  command:  
  cd MYDBMS  
  ./runsql.sh  

## for test :  

//测试CREATE DATABASE SHOW DATABASES DROP DATABASE USE DATABASE  
CREATE DATABASE XJGL;  
CREATE DATABASE JUST_FOR_TEST;  
CREATE DATABASE JUST_FOR_TEST;  
SHOW DATABASES;  
DROP DATABASE JUST_FOR_TEST;  
SHOW DATABASES;  
USE XJGL;  

//测试CREATE TABLE SHOW TABLES DROP TABLE  
CREATE TABLE STUDENT(SNAME CHAR(20),SAGE INT,SSEX INT);  
CREATE TABLE COURSE(CNAME CHAR(20),CID INT);  
CREATE TABLE CS(SNAME CHAR(20),CID INT,GRADE DOUBLE);  
CREATE TABLE TESTTABLE(COL1 CHAR(22),COL2 INT,COL3 CHAR(22));  
CREATE TABLE TEST_TABLE(COL1 CHAR(22),COL2 INT,COL3 CHAR(22));  
SHOW TABLES;  
DROP TABLE TEST_TABLE;  
SHOW TABLES;  

//测试INSERT INTO VALUES  
INSERT INTO STUDENT(SNAME,SAGE,SSEX) VALUES ('ZHANGSAN',22,1);  
INSERT INTO STUDENT VALUES ('LISI',23,0);  
INSERT INTO STUDENT(SNAME,SAGE) VALUES ('WANGWU',21);  
INSERT INTO STUDENT VALUES ('ZHAOLIU',22,1);  
INSERT INTO STUDENT VALUES ('XIAOBAI',23,0);  
INSERT INTO STUDENT VALUES ('XIAOHEI',19,0);  
INSERT INTO CS VALUES ('LISI',1,89.9);
INSERT INTO COURSE(CNAME,CID) VALUES ('DB',1);  
INSERT INTO COURSE (CNAME,CID) VALUES('COMPILER',2);  
insert into course (CNAME,CID) VALUES('C',3);  
insert into COURSE (CNAME,CID) VALUES('C',3);  

//测试单表查询  
SELECT * FROM COURSE;  
SELECT * FROM STUDENT;  
SELECT SNAME,SAGE,SSEX FROM STUDENT;  
SELECT SNAME,SAGE FROM STUDENT;  
SELECT SNAME,SAGE FROM STUDENT WHERE SAGE=22;  
SELECT SNAME,SAGE FROM STUDENT WHERE (((SAGE=21)));  
SELECT SNAME,SAGE FROM STUDENT WHERE SAGE>21 AND SSEX=0;  
SELECT SNAME,SAGE FROM STUDENT WHERE SAGE>21 OR SSEX=0;  
SELECT SNAME,SAGE FROM STUDENT WHERE SAGE>21 OR SSEX=0 AND SNAME = 'LISI';  
SELECT SNAME,SAGE FROM STUDENT WHERE (SAGE>21 OR SSEX=0) AND SNAME = 'LISI';  
SELECT * FROM STUDENT WHERE SSEX!=1;  

// 测试多表查询  
SELECT * FROM STUDENT;  
SELECT * FROM COURSE;  
select * from student,course;  
SELECT * FROM STUDENT,COURSE WHERE (SSEX=0) AND (CID=1);  

//测试DELETE语句  
SELECT * FROM STUDENT;  
DELETE FROM STUDENT WHERE (SAGE>21) AND (SSEX=0);  
SELECT * FROM STUDENT;  

//测试UPDATE  
SELECT * FROM STUDENT;  
UPDATE STUDENT SET SAGE=21 WHERE SSEX=1;  
SELECT * FROM STUDENT;  
UPDATE STUDENT SET SAGE=27,SSEX=1 WHERE SNAME='ZHANGSAN';  
SELECT * FROM STUDENT;  

//再次测试DROP  
SHOW TABLES;  
DROP TABLE STUDENT;  
SHOW TABLES;  
DROP TABLE CS;  
SHOW TABLES;  
DROP TABLE TESTTABLE;  
SHOW TABLES;  
SHOW DATABASES;  
DROP DATABASE XJGL;  
SHOW DATABASES;  

//正常退出  
EXIT;  

//多表链接查询（超过两个表）

CREATE DATABASE XJGL;
CREATE TABLE STUDENT(SNAME CHAR(20),SAGE INT,SSEX INT);  
CREATE TABLE COURSE(CNAME CHAR(20),CID INT);  
CREATE TABLE CS(SNAME CHAR(20),CID INT,GRADE DOUBLE);  
INSERT INTO STUDENT VALUES ('LISI',23,0);  
INSERT INTO COURSE(CNAME,CID) VALUES ('DB',1);  
INSERT INTO CS VALUES ('LISI',1,89.9); 
SELECT * FROM CS;
SELECT * FROM COURSE;  
SELECT * FROM STUDENT;  
SELECT * FROM STUDENT,CS,COURSE WHERE (SSEX=0) AND (CID=1); 
SELECT * FROM STUDENT,CS WHERE (SSEX=0) AND (CID=1);


//测试浮点数
CREATE DATABASE XJGL;
CREATE TABLE CS(SNAME CHAR(20),CID INT,GRADE DOUBLE);
INSERT INTO CS VALUES ('LISI',1,89.9);
SELECT * FROM CS;

