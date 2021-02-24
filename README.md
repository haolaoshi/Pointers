一共405页，十八章；

快速上手

指针的类型：把指针声明的名字去掉，剩下部分；
指针所指向的类型：指针名字和左边的指针声明符*去掉，剩下的部分；
指针本身占用内存：sizeof指针类型
指针的值所代表的那个内存地址开始，长度为sizeof指针类型的区域；

逻辑注释代码【推荐】
#if  0
    Statements;
#endif 

在C语言中，数组参数是以引用形式传递的，也就是传址调用，而标量和常量是传值。
由于scanf函数实现原理，所有标量的参数前面也必须加一个&符号。

strncpy     strcpy    strcat
strchr 搜索字符   strstr 搜索字符串


第一章	基本概念

*表达的是间接访问操作
声明时星号应该靠近变量一侧；
char	 *message = “Hello Wordl”; // 声明为一个指向字符串的指针，并用字符串常量中的第1个字符的地址对该指针初始化。初始值是给 message而不是*message;
char  *message;
message = “Hello World”;

第二章	数据

int const  *pci; //指向整形常量的指针，可以修改指针， 不能修改它所指向的值 ；
int  *const pci; //指向整形的常量指针，不可以修改指针，可以修改它所指向的值；
int const  *const pci; //指向整形常量的 常量指针；

存储类型；存储变量值的内存类型；
普通内存；运行时堆栈，硬件寄存器；
任何代码块之外声明的变量存储于静态内存，不属于堆栈；是静态变量，运行之前创建。
代码块内部声明的是自动的，存储于堆栈中；
在代码块内声明 的变量，但是加上Static 使存储类型从自动变为静态，不影响它的作用域。
Register

初始化：静态变量不需要额外时间；自动变量初始化需要更多开销；前者自动初始化，后者必须显示初始化。

Static关键字
用于函数定义或者代码块外的变量声明时，修改标识符的链接属性，从external 为internal。
用于代码块内部变量声明时，用于修改存储类型，从自动变量改为静态变量。

external 全局变量； 只要是代码块外的声明，都是全局的和静态的。


第三章	语句
如果一个程序采用了有符号的右移位操作，它就是不可移植的。
sizeof(a=b+1) 判断表达式的长度并不会赋值；

关系操作符的结果是整形值，而不是布尔值；表达式符合结果是1，不符合结果是0


第四章	内存
内存中每个位置都有一个地址标识；
内存中每个位置都包含一个值；

通过名字而不是地址访问内存的位置，名字与内存位置关联不是硬件提供的，而是编译器。

变量的值就是分配给该变量的内存位置所存储的数值。

第五章	函数 数组 字符串
当函数调用一个缺省原型的函数时，编译器默认返回整形；因此，所有函数都应该有原型。
迭代vs递归： 能用迭代，不用递归

strlen
strcpy	strncpy
strcat	strncat
strcmp	strncmp
strchr	strrchr	strpbrk
strstr	
strspn	strcspn
strtok
strerror
tolower	toupper
isupper
memcpy	memove	memcpm	memchr	memset


第六章	结构和联合  

结构成员的间接访问 (*cp).f    cp->f 
联合的所有成员引用的是内存中相同的位置



 
第十一章 动态内存分配
malloc和free 
calloc和realloc
malloc不会初始化，calloc会初始化为0

第十二章 使用结构和指针

链表
双链表

第十三章 高级指针
指向指针的指针
函数指针： 回调函数
*++*argv


第十四章 预处理器
#define 和宏；
宏不可以递归；
宏与类型无关；

#if  条件编译
用来注释挺好

#inclue 文件包含


第十五章 输入输出
<stdio.h> 错误报告 perror
<stdlib.h> exit 终止执行
绝大多数IO函数在使用前要包含stdio.h
流：文本流和二进制流
<stdio.h> 声明了FILE结构，FILE是一个数据结构，用于访问一个流；
三个标准流；stdin,stdout,stderr;排泄物访谈嘉宾是一个指向FILE结构的指针；

文件使用步骤
声明一个指针变量FILE*
通过fopen函数打开
进行读取写入
通用fclose关闭

删除或者改名 remove  rename
临时文件 FILE* tmpfile( );
临时文件名； char  *tmpnam(char *name);

流错误 feof  ferror clearer
文件定位  rewind  fgetpos  fsetpos


第十六章 标准函数库
<stdlib.h>算术：abs;labs;div;idiv;
<stdlib.h>随机数;rand;srand;
<stdlib.h>字符串转换；atoi;atoll;strol;strtoul;
<stdlib.h>退出
<stdlib.h>环境
<stdlib.h>系统命令
<stdlib.h>排序和查找

<locale.h>货币和数字

<math.h>浮点型函数；
<math.h>三角函数
<math.h>双曲函数
<math.h>对数和指数
<math.h>幂
<math.h>顶数；底数；绝对值和余数

<time.h>处理器时间
<time.h>当天时间
<time.h>日期时间转换

<signal.h>处理信号
<stdarg.h>可变参数
<assert.h>断言


第十七章 ADT
为什么我还需要手写抽象数据类型？用泛型 
内存分配；
堆栈；队列 和树；查找 

第十八章 真正的高手，要会看汇编代码
判断运行时环境；静态变量和初始化；堆栈帧顺序；寄存器变量；
