/*

派生类的构造函数声明一般语法

派生类类名::派生类类名(参数表): 基类名1(参数表1), ...基类名m(参数表m),
			内嵌对象名1(内嵌对象参数表1), ...内嵌对象n(内嵌对象参数表n)
{
	派生成员新增成员初始化; 
} 


1.调用基类的构造函数完成从基类继承的数据成员的初始化,调用顺序按照基类被继承的先后顺序
2.调用内嵌对象的构造函数完成内嵌对象数据成员的初始化,调用顺序按照内嵌对象在派生类中声明的先后顺序
3.执行派生类构造函数的函数体,完成派生类新增成员的初始化

什么时候派生类需要声明构造函数?
如果基类定义了带参数的构造函数,派生类就必须定义构造函数,这样就可将参数传递给基类的构造函数,完成从基类继承那部分的成员的初始化.
如果基类没有定义构造函数,但是派生类新增数据成员需要传递参数初始化,派生类也必须定义构造函数完成新增成员的初始化. 

派生类的析构函数
从基类继承的那部分数据成员的清理工作由基类的析构函数完成,
派生类内嵌对象成员的清理工作由内嵌对象的析构函数完成,
派生类新增的数据成员的清理工作由派生类的析构函数完成.

栈的先进后出
释放顺序是 派生类新增的一般数据成员->派生类内嵌对象成员->基类继承的成员 
默认的析构啥也不会做 
 


*/ 
