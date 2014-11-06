MongoDB
=======

** MongoDB VS. SQL **

* Database: Database
* Table :Collection
* tuple/raw: BSON Document
* column: BSON field
* join: embedding and linking
* primary key : _id field
* group by : aggregation
* index : index


## Server operations
------------------

### 1.开启服务器：

 CML：`mongod [--dbpath dbfilepaht]`
 CML: `mongod --repair`(以修复模式启动)
 
### 2.关闭数据库

 mongo(JS)中：`db.shutdownServer()`

### 3.开启数据库交互终端:

 CML:`mongo`
 
### 4. 连接数据库

 **格式**：在mongo(JS)代码中下：
 `mongodb://username:password@hostname/dbname`
 
 `mongodb://localhost`
 
 `mongodb://fred:foobar@localhost`(访问本地admin数据库)
 
 `mongodb://fred:foobar@localhost/zoul`

### 5. 获取服务器元数据

 `db.version()`（查看版本）
 
 `db.getMongo()`（查看连接的Mongo服务器IP）
 
 `db.serverStatus()`(查看服务器状态)


## User and Permission
---------------------

### 1. 添加用户
 `db.addUser("zoul", "jjfjj", true)`(用户名，密码，是否只读)
 
### 2. 删除用户
 `db.removeUser("zoul")`

### 3. 查看当前DB的用户
 `show users;`
 


## DB and Collections
---------------------

因为MongoDB同大多数NoSQL一样都是Schemaless(无模式)的，所以就没有那么严格的DDL。所以相关的Collection的创建和定义就比较简单.

`show dbs`

`show collections`

`use dbname`

### 1. 创建Database
`use newdbname`
`db.student.insert({"name":"feilunzhou")`

一气呵成，如果只执行`use newdbname`不会创建，因为为空。
第二条命令创建了一个collection叫`student`，并且在其中插入了一个document。

### 2. 查看某DB的统计信息

`db.stats()`

### 3. 查看指定DB包含的Collection列表
`db.getCollectionNames()`

### 4. 创建Collection

`db.newCollectionname.insert({"name":"feilunzhou"})`

或者

`db.createCollection(name, {size:..., capped:..., max:,,,})`

### 统计Collection中的Document数
`db.collName.count()`

### 查看Collection的内存使用情况
`db.collName.storageSize()`（可用空间）

`db.collName.totalSize()`(分配的所有存储空间，包含索引)

### 删除DB
`db.dropDatabase()`



## 索引操作
----------

### 创建索引
`db.collName.ensureIndex({'field1':1, 'field2':-1})`

### 查看索引
`db.collName.getIndexes()`

### 删除索引
`db.collName.dropIndex(indexName)`	

`db.collName.dropIndexes()`(删除本Collection上的所有索引)

### 重建索引
`db.collName.reIndex()`



## DML and DQL
--------------

### 插入document（增）
`db.collName.save({"name":"feilunzhou","age":"25"})`

或者

`db.collName.insert({dict})`


### 删除document（删）
`db.collName.remove({"name":"feilunzhou"})`(其中的字典指定删除的查询)


### 修改document (改)

### 查询document (查)

`db.collName.find({"age":"25"})`(字典指定查询条件)

`db.collName.find({condition dict}).count()`(查询结果的记录数)

## Transaction
--------------


## Administration
-----------------



## Reference
------------
[CSDN](http://blog.csdn.net/shirdrn/article/details/7105539)
[Cnblog](http://www.cnblogs.com/TankMa/archive/2011/06/08/2074947.html)
[W3CSchool](http://www.w3cschool.cc/mongodb/mongodb-connections.html)


























