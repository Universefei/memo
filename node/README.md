Roadmap of mastering MEAN
=========================

MEAN = 
MongoDB \n
Express \n
AngularJS \n
Node\n

Node.js
-------

[Introduction to Node.js with Ryan Dahl](https://www.youtube.com/watch?v=jo_B4LTHi3I)

这个是Node 创始人的一个视频，node是09年时候出来，有一些视频是他10年的演讲，显得很青涩，这个他跟他之前的视频比较起来显然好了很多。


[7天学Node](http://www.nodebeginner.org/index-zh-cn.html)

用Node实现了一个非常简单的站点，对入门着想用Node搞web开发的人来说很合适，没有用过多的MVC框架

[Node执行过程](http://www.zhihu.com/question/20156099)

Node.js中的回调函数一般是指异步操作完成之后调用的函数。

基于异步事件模型的Node.js大致是这样运行的：

向Node.js提交异步操作，比如建立网络连接，读取网络流数据，向文件写入数据，请求数据库服务等，同时针对这些异步操作注册回调函数。这些异步操作会提交给IO线程池或者工作线程池。
在线程池中，操作是并发的执行，也就是读网络流和向文件写数据，或者请求数据库服务都是并发的（可能是这样子的，具体的操作怎么完成，是node的事） ，执行完毕后会将就绪事件放入完成队列中。
Node.js 在提交完操作请求之后，进入循环(或叫事件循环吧)。循环的过程如下：

1. 检查有没有计时器超时(setTimeout/setInterval)
2. 检查当前是否为空闲状态，执行空闲任务(process.nextTick)
3. 检查IO完成队列（各种网络流读写、文件读写、标准输入输出上的事件都会进入这个队列）是否有就绪事件，
    若完成队列中有就绪事件，就把队列里的所有事件（可能有多个操作已经完成）信息都取出来，对这些事件信息，挨个地调用与其相关的回调函数。这个过程是同步的，执行“写数据完成”事件的回调函数完成之后，才会去调用“读到网络数据”事件的回调函数；
    若是队列中没有就绪事件，而且没有空闲(idle)任务，就会做一段时间的等待（线程被阻塞在此处），等待的超时时间由计时器周期决定。（不能因为等待而耽误timer和idle的事件处理）。
4. 进入下一轮循环。

    从上面这个过程可以看出，你脚本中注册的所有回调函数都是在这个循环过程中被依次调用的。若有一个回调函数执行大的计算任务，很长时间不返回的话，就会让整个循环停顿下来，其它回调函数就不能在事件到来时即时被回调。因此，建议长任务处理过程中，即时将剩下的处理通过process.nextTick丢入下一轮循环中有idle事件中，或者process.spawn一个进程来执行。

    总之，除了你的代码是同步执行的以外，其它所有的事情都是并发的。

[exports和module.exports的区别](http://weizhifeng.net/node-js-exports-vs-module-exports.html)

exports所做的事情是收集属性，如果module.exports当前没有任何属性的话，
exports会把这些属性赋予module.exports。如果module.exports已经存在一些
属性的话，那么exports中所有的东西会被忽略。



MongoDB
-------

[Introduction to NoSQL by Martin Fowler](https://www.youtube.com/watch?v=qI_g07C_Q5I)

非常好的关于NoSQL的介绍，讲了数据库的发展历史，要处理的问题，难点,关于为什么NoSQL的出现非常精彩。
Martin Fowler 还写了一遍影响非常大的关于依赖注入的文章-[Inversion of Control Containers and the Dependency Injection pattern](http://martinfowler.com/articles/injection.html)

[为什么要用非关系型数据库](http://robbin.iteye.com/blog/524977)

对比了关系型数据库和NoSQL的优缺点，适用场景，非常不错，必读！

[W3CSchool MongoDB教程](http://www.w3cschool.cc/mongodb/mongodb-tutorial.html)

很好的入门教程，分两个部分:基础教程和高级教程。2个小时可以看完，看完之后基本操作就都会了

[Node.js MongoDB tutorial using Mongoose](https://www.youtube.com/watch?v=5e1NEdfs4is&list=FLosiY9tRc9X4ExAeWrY0TtQ&index=3)




Express
-------

[an introduction to Node.js with Express.js](https://www.youtube.com/watch?v=FqMIyTH9wSg&list=FLosiY9tRc9X4ExAeWrY0TtQ&index=4)

短小精悍的使用Express的例子和介绍


Angular.js
----------

[Learn Angular.js using UI-Router](https://www.youtube.com/watch?v=QETUuZ27N0w&list=FLosiY9tRc9X4ExAeWrY0TtQ&index=1)

[Code School](https://www.codeschool.com/courses/shaping-up-with-angular-js)




MEAN 综合
--------



Topics:
-------

### Node 事件

http://www.csdn.net/article/2012-04-25/2804994
http://sunspot.blog.51cto.com/372554/1266428
htttp://www.infoq.com/cn/articles/tyq-nodejs-event
http://www.toolmao.com/nodejs-zhongwen-events-shijian

有一点不明白的是：知道异步事件函数是一个参数是事件，一个是回调
1. 可不可以不用时间，直接是回调。
2. 事件是谁发出的。

### 阻塞/非阻塞
http://www.zhihu.com/question/20156099

### 同步/异步

