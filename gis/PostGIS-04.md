#chapter 4:Using PostGIS 

4.1 GIS Objects
4.2 PostGIS Geography Type
4.3 Using OpenGIS Standards
4.4 Loading GIS Data
4.5 Retrieving GIS Data
4.6 Building Indexes
4.7 Complex Queries
4.1 GIS Objects（GIS对象）

##4.1 GIS Objects

PostGIS支持的GIS对象是OGC(OpenGIS 委员会)规定的”Simple Features“的超集。PostGIS不仅支持标准的”Simple Features for SQL“，而且还扩展支持3DZ,3DM和4D坐标

###4.1.1 OpenGIS的对象格式（WKB和WKT）

OpenGIS规范定义了两种描述空间对象的方法：

* WKT=Well-Know Text
* WKB=Well-Know Binary

OpenGIS规范还要求空间对象的内部存储格式应该包含一个空间索引id（SRID）

###4.1.2 PostGIS的对象格式（EWKB、EWKT、Canonical Forms)

OGC定义的格式（也就是OpenGIS定义的格式）只支持二维集合，相关的SRID（空间索引号）也没有嵌入在输入/输出表示中；
目前来说PostGIS扩展格式是OGC格式的超集（每一个有效的WKB,WKT都是一个有效的EWKB,EWKT），但是因为不知道OGC以后会不会加入一些新的格式，所以这种超集关系在未来不一定继续成立；
PostGIS EWKB/EWKT增加了3dm，3dz，4d坐标的支持，并且嵌入了SRID信息到其中；

###4.1.3 SQL-MM part3

NULL currently

##4.2 PostGIS Geography Type（PostGIS地理类型）vs. Geometry Type

* 地理类型（the geography type）为本地的spatial Features 提供地理坐标，这些地理坐标用角度单位（度）来表示；
* **PostGIS几何类型（PostGIS geometry type）的基础是平面，最短距离是两点间直线距离**；
* **PostGIS地理类型（PostGIS geographic type）的基础是球形，最短路径是球体上的圆弧**，这就意味着地理上面的计算要更复杂的多，要考虑到球体的形状。由于底层的数学计算更为复杂，地理类型的函数则比几何类型的函数要少很多，不过随着新算法的增加，地理类型的功能也会增强；
* 一个限制是地理数据类型只支持WGS 84 long lat（SRID），没有一个GEOS函数支持地理类型数据，它作为一种能够在几何类型和地理类型之间自由转换的变通方案；

###4.2.1 Geography Basics

* 地理类型（geography type）只支持最简单的Simple Features，如果标准的几何类型数据的SRID是4326，它会自动转换为地理类型，你也可以用通常的EWKT/EWKB的方法去插入数据；

可以看到上面的location类型是GEOGRAPHY
你可以用CREATE TABLE语法创建一个有GEOGRAPHY列的表，不像GEOMETRY，创建这个表不用去运行一个单独的类似AddGeometryColumns()进程去在元数据中注册登记这一列；

		  注意：location这一列使用GEOGRAPHY类型，Geography类型支持两种可选modifier：

		  * 一个是type modifier，用来限制列所允许的维度和形状的种类；
		  * 一个是SRID modifier，限制坐标的索引id为特定值

		  type modifier允许的值是：

		  * POINT
		  * LINESTRING
		  * POLYGON
		  * MULTIPOINT
		  * MULTILINESTRING
		  * MULTIPOLYGON

		  SRID modifier目前的使用比较局限，只允许值为4326（WGS84），如果不指定的话，值会为0（意为未指定球状体），并且所有的计算都会用WG84来处理。


		  如果你使用的是GEOMETRY类型的列的话，这样插入数据依然行得通：


		  建立索引的步骤跟GEOMETRY一样，PostGIS会注意到这一列是GEOGRAPHY类型，并且建立一个对应的基于球体的索引，而不是GEOMETRY用的以往的基于平面的索引


		  查询和测量函数的单位都是米，所以距离参数应该是米，返回值也应该是米（面积为平方米）


		  通过下面的例子你可以看到GEOGRAPHY的强大力量: 



		  GEOGRAPHY类型计算出了我们想要的最短距离，从Reykjavik到航线路径的弧线距离
		  GEOMETRY类型计算出来的是一个没有意义的笛卡尔距离，平面直线距离，名义上的结果的单位是度，结果跟点差之间的度数并不一致。所以叫度并不确切。

###4.2.2 when to use geography data type over geometry data type

		  GEOGRAPHY类型可以让你存经纬度坐标数据，但是代价就是，可用的函数比GEOMETRY少很多，而且函数执行比GEOMATRE更耗时。
		  选择哪种类型应该根据你的应用使用的区域范围情况，你的数据是全球的或者是一个很大的跨洲区域，还是一个本国，本市本县的小区域？

		  * 如果你的数据只包含一个小的地理范围，你会发现就变现和功能可用来讲，选择一个合适的投射方案并且使用GEOMETRY是最好的解决方案。
		  * 如果你的地理数据是全球范围的或者是覆盖一个洲的地区，那么使用GEOGRAPHY构建的系统不会让你担心投射的细节。存入经纬度数据，使用GEOGRAPHY中定义的函数。
		  * 如果你不知道投射原理，也不想学，那你只能接受GEOGRAPHY可用函数较少的限制，因为选用它对你来说更简单一点。

###4.2.3 Geography Advanced FAQ


##4.3 Using OpenGIS Standards



