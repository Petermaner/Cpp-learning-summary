#markdown loaing... (in row 279)  
1、字符串相关问题  
1.1输入，输出想要的字符串（不定个数的）   
方法一：字符数组```char  a[20]  cin>>a;  cout<<a;(输入过程中按回车及停止)```   
方法二：string类```string  a;  getline(cin,a); (输入过程中按回车及停止)```  
1.2 string类 ```cin>>a```时，是把空格当作分隔符，作为字符串a，空格后的当作下一次输入   
```cpp
getline(cin，a)不包括空格，回车作为分隔符，这样的话，a中将包括空格！    
getline(cin,a,',')把，作为分隔符
```
所以当要使用一串数字流时，不建议使用string类   
1.3 当不知道要使用的数组多大时，（动态内存分配？），但是知道结束条件。     
     可以
```cpp
for(i=0;;i++){
	cin>>a[i];
if(a[i]==1000)     //这里要用if 而不是 while？？？
	break; //因为while是循环语句，if判断语句，while为真循环，为假执行下一条
}
for(i=0;a[i]!=1000;i++){
	if(a[i]==-1)
		x++;
	if(a[i]==0)
		b++;
	if(a[i]==1)
	c++;
}
```
1.4  在while和for循环中的 ++i 和 i++ 是没有区别的。！！！     

2、闰年闰月 2月正常有28天，闰年2月有29天。   
   四年一闰，百年不闰，四百年又闰。     
```cpp
（n%4==0 && n%100!=0 || n%400==0
if（month==1||3||5||...）是错误的，要写if(month==1||month==3||month==5)
```
3、一个自然数有多少个2的因子   
//大致思路，不能整除2（求余不为0），那个数肯定为0了 ,能整除2（求余不为0），那么肯定一个保底，再看他n/2的因子里有几个2的因子（函数迭代？？）,   
用一个while循环（条件为那个因子%2==0），再加一个a++计数器。      
```cpp
#include<iostream>
using namespace std;
int main(){
	int m,n,a=1;
	cin>>n;	
	if(n%2==0){
		m=n/2;
		while(m%2==0){
			a++;
			m=m/2;
		} 
	}
	if(n%2!=0)
		a=0;
	cout<<endl<<a;
	return 0;
} 
```
//上面这个循环＋计数器，可以用for一并表示（注意for循环的可视化运行过程&&for循环的有趣之处）    
```cpp
for(i=0;n%2==0;i++){
	n/=2;
}
cout<<"整数"<<n<<"有"<<i<<"个2的因子。"; 
```

4、setw（）和cout.width()区别    
两者作用是一样的，都是设定下一次输出输入宽度，但setw是操作子，而width是成员函数！    
如 
```cpp
const char *str1 = "hello";
const char *str2 = "world";
cout.width(10);
cout<<str1;
cout.width(10);
cout<<str2<<endl;
```
或者使用：    
```cout<<setw(10)<<str1<<setw(10)<<str2<<endl;```
显然使用setw要更方便，不过要包含头文件：    
```#include <iomanip>```

5、  
10 20 30 40 50 60 70 80 90 100    
n=55，把55插入进去，100挤掉   
result: 10 20 30 40 50 55 60 70 80 90  
```cpp
#include<iostream>
using namespace std;
int main(){
	int a[10]={10,20,30,40,50,60,70,80,90,100},i,j,n;
	cin>>n;
	for(i=0;i<10;i++){
		if(a[i]>=n)
			break;   //定位 i，做个标记（这个地方准备插入）
		}
	for(j=9;j>i;j--){                      //注意j>i，有点东西，可以举简单例子想出来
		a[j]=a[j-1];            //把后面的依次后移，倒着写比较好
		}       
		a[i]=n;
	for(i=0;i<10;i++){
		cout<<a[i]<<'\t';
	}
return 0;
} 
```
6、冒泡算法 6.1   
二分法          6.2   
冒泡算法和二分法一起哦 6.3   
辗转相除求最大公约数法 6.4    
    
6.1   
```cpp
#include <iostream>
using namespace std;
template<typename T>                //模板
//整数或浮点数皆可使用
void bubble_sort(T arr[], int len)   //数组做形式参数，用[ ]，因为前面没有声明，要 T
{
    int i, j;  T temp;
    for (i = 0; i < len - 1; i++)         //len-1是因为，最后一位不用和后面的比
	for (j = 0; j < len - 1 - i; j++)//len-1-i是因为，这种冒泡排序，每次循环都把最大的放在了后面
	if (arr[j] > arr[j + 1])             //最后一个一定最大。两个for循环，第一个循环每个数（第i个），第二个循环比较                                                  （i和他后面的），最后几个不用比
	{
	    temp = arr[j];
	    arr[j] = arr[j + 1];
	    arr[j + 1] = temp;
	}
}
int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);     ？？？//数组长度可以这么算 ！
    bubble_sort(arr, len);
    for (int i = 0; i < len; i++)
	cout << arr[i] << ' ';

    cout << endl;

    float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
    len = (int) sizeof(arrf) / sizeof(*arrf);
    bubble_sort(arrf, len);
    for (int i = 0; i < len; i++)
	cout << arrf[i] << ' ';

    return 0;
}
```
6.1.1 数组元素个数确定    

sizeof(数组名)与sizeof(*数组名)    

举例  
```cpp
#include<stdio.h>
int main()
{
int a[5]={1,2,3,4,5};
printf("sizeof数组名=%d\n",sizeof(a));    
printf("sizeof *数组名=%d\n",sizeof(*a));
}
```

运行结果      

sizeof数组名=20      
sizeof *数组名=4      

***********************************************************************************************************************************
分析：   

a为含有5个元素的数组，数组名代表元素的首地址，所以sizeof(a)代表整个数组所占的内存空间，即5*4Byte=20Byte;而*a表示指向首地址，即表示首地址的内容，所以sizeof(*a)表示首元素所占内存空间的大小    

6.1.2    

32位环境下，int *p=new int[10];请问sizeof(p)的值为（）   
A、4              B、10              C、40               D、8   

我以为正确答案为C，int类型为32位，占四个字节，10个自然就是40了，结果正确答案为A，只是指针p占的空间。     
```cpp
#include<iostream>
using namespace std;
void fun(int *P)
{
	cout<<"在函数中"<<sizeof(P)<<endl;
}
int main()
{
	int A[10];
	int* B=new int[10];
	cout<<"数组名"<<sizeof(A)<<endl;
	cout<<"指针"<<sizeof(B)<<endl;
	fun(A);
}
```


结果输出：   

数组名40   
指针4   
在函数中4   


由此可见，数组名并不是完全等同于指针。虽然它们都可以通过指针方式访问数组。在这个博客看到他们的区别：http://blog.csdn.net/ljob2006/article/details/4872167    

但是数组在作为函数参数传递过程中，会退化成指针。这也是为什么指针作为参数传递时，经常要一个长度。   

6.2 
```cpp
#include<iostream>
#define N 10
using namespace std;
int main(){
int a[N],front,end,mid,x,i;
cout<<"请输入已排好序的a数组元素:"<<endl;
for(i=0;i<N;i++)
	cin>>a[i];
cout<<"请输入待查找的数x:"<<endl;
cin>>x;
front=0;
end=N-1;
mid=(front+end)/2;
while(front<end&&a[mid]!=x){     //可以写front<=end
	if(a[mid]<x)front=mid+1;
	if(a[mid]>x)end=mid-1;
	mid=(front+end)/2;
}
if(a[mid]!=x)
	cout<<"没找到！"<<endl;
else
	cout<<"找到了，在第"<<mid+1<<"项里"<<endl;
return 0;
}
```

6.3  
```cpp
#include<iostream>
using namespace std;
void sort(int a[],int len){
	for(int i=0;i<len-1;i++){
	for(int j=0;j<len-1-i;j++){
		if(a[j]>a[j+1]){
			int t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		} 
	}
}
}
int main(){
int arr[]={10,30,20,50,100,60,80,70,40,90},n;
cout<<"排序前：";
for(int i=0;i<10;i++){
cout<<arr[i]<<'\t';
}
int len=sizeof(arr)/sizeof(*arr);
sort(arr,len);
cout<<endl<<"排序后：";
for(int i=0;i<10;i++){
cout<<arr[i]<<'\t';
}
cout<<endl<<"请输入一个整数：";
cin>>n;
int low=0,high=len-1,mid;
while(low<=high){
mid=(low+high)/2;
if(arr[mid]==n)break;            //
if(arr[mid]>n)high=mid-1;    //这三个排比句怎么样？
if(arr[mid]<n)low=mid+1;
}
if(low>high)
cout<<"这个数不存在";
else
cout<<"就是它第"<<mid+1<<"个数！"<<endl;
return 0;
}
```
6.4    

7   
函数是类的函数，变量是函数的变量。   
函数在类的内存地址 中，变量在对象的内存地址中。   

8    
一个程序要有两部分：.h  .cpp  头文件和代码   
9    
没有打扫（清理）内存，电脑会说烫烫烫   

10   
10.1构造函数是初始化变量，(a=0)   
      复制构造函数是用变量初始化变量（a=b）   
10.2   
构造函数的实现：   
	Clock::Clock(int newH, int newM, int newS): hour(newH),  minute(newM), second(newS) {
		}
10.3  
```cpp
#include "iostream.h"
class A{
public: int x;
	A(){};
	 A(A &p){x=p.x;}        //class 类名 {
public :
	类名（形参）；//构造函数
	类名（const  类名 &对象名）；//复制构造函数
	 ...
	 }；
	类名::类（ const  类名 &对象名）//复制构造函数的实现
	{    函数体    }

	 //A(A &p){x=p.x+200;}
};

void main()
{A a1;
a1.x=100;
 A a2=a1;
 cout<<a2.x<<endl;
}
```
10.4   
复制构造函数被调用的三种情况   
定义一个对象时，以本类另一个对象作为初始值，发生复制构造；   
如果函数的形参是类的对象，调用函数时，将使用实参对象初始化形参对象，发生复制构造；   
如果函数的返回值是类的对象，函数执行完成返回主调函数时，将使用return语句中的对象初始化一个临时无名对象，传递给主调函数，此时发生复制构造。    

11    
11.1   
结构体是一种特殊形态的类   
与类的唯一区别：类的缺省访问权限是private，结构体的缺省访问权限是public    
结构体存在的主要原因：与C语言保持兼容   
11.2  联合体    
声明形式 
```cpp
union 联合体名称 {
    公有成员
protected:
    保护型成员
private:
    私有成员
};
```
特点：   
成员共用相同的内存单元   
任何两个成员不会同时有效    

12   
注：C++随机数函数有：     
 void srand(unsigned seed)   功能：函数可以设置 rand 函数所用得到随机数产生算法的种子值。任何大于 1 的种子值都 会将 rand随机数产生函数所产生的虚拟随机数序列重新设置一个起始点。     
 int rand(void) 功能：此函数可以产生介于 0 到 32767 间的虚拟随机数，所谓虚拟随机数的意思就是因为 当只设置相同的启动种子值，所产生的数值序列都是可预测的。要产生不可预测的数值序列，必 须通过srand函数不断改变随机数的启始种子值，已产生最佳的随机数。 头文件：stdlib.h     
```cpp
#include<iostream>
#include<cstdlib>
#include <ctime>
using namespace std;
int main(){
	srand((int)time(0));
	for(int i=0;i<100;i++){
		cout<<rand()%26<<' ';
	}
	return 0;
} 
```
13    
file >> c是什么意思？    
文件流是输入输出流。数据在程序中以流的形式出现，    
比如cin就是个输入流   
cin 搭配上>>流操作符 就是从缓冲区流里提取数据，由于对>>进行了重载，所以可以提取不同形式的数据。    
fstream等可以定义文件流，同样是数据流。   
file >> c;就是从这个文件流里面提取字符c。file << 就是写到文件里。除了用重载的流操作符也可用成员函数进行流的操作，如getline等成员函数。    
很多小朋友对<<,>>的方向很糊涂，其实cout 或cin把他们看做一个流（他们本来就是流），那么cout这个输出流要将数据送到这个流，所以是cout <<。而cin是输入流，要流向待接收的数据，所以是cin >>。同理向文件写入是file <<。写出是file >>     
14     
1）组合(has-a)关系可以显式地获得被包含类（继承中称为父类）的对象，而继承(is-a)则是隐式地获得父类的对象，被包含类和父类对应，而组合外部类和子类对应。     
2）组合关系在运行期决定，而继承关系在编译期就已经决定了。   
3）组合是在组合类和被包含类之间的一种松耦合关系，而继承则是父类和子类之间的一种紧耦合关系。    
4）当选择使用组合关系时，在组合类中包含了外部类的对象，组合类可以调用外部类必须的方法，而使用继承关系时，父类的所有方法和变量都被子类无条件继承，子类不能选择。    
5）最重要的一点，使用继承关系时，可以实现类型的回溯，即用父类变量引用子类对象，这样便可以实现多态，而组合没有这个特性。   
6）还有一点需要注意，如果你确定复用另外一个类的方法永远不需要改变时，应该使用组合，因为组合只是简单地复用被包含类的接口，而继承除了复用父类的接口外，它甚至还可以覆盖这些接口，修改父类接口的默认实现，这个特性是组合所不具有的。    
7）从逻辑上看，组合最主要地体现的是一种整体和部分的思想，例如在电脑类是由内存类，CPU类，硬盘类等等组成的，而继承则体现的是一种可以回溯的父子关系，子类也是父类的一个对象。   
8）这两者的区别主要体现在类的抽象阶段，在分析类之间的关系时就应该确定是采用组合还是采用继承。   
9）引用网友的一句很经典的话应该更能让大家分清继承和组合的区别：组合可以被说成“我请了个老头在我家里干活” ，继承则是“我父亲在家里帮我干活   
15   
继承是类与类之间的关系，是一个很简单很直观的概念，与现实世界中的继承类似，例如儿子继承父亲的财产。    

继承（Inheritance）可以理解为一个类从另一个类获取成员变量和成员函数的过程。例如类 B 继承于类 A，那么 B 就拥有 A 的成员变量和成员函数。被继承的类称为父类或基类，继承的类称为子类或派生类。     

派生类除了拥有基类的成员，还可以定义自己的新成员，以增强类的功能。     

以下是两种典型的使用继承的场景：   
1) 当你创建的新类与现有的类相似，只是多出若干成员变量或成员函数时，可以使用继承，这样不但会减少代码量，而且新类会拥有基类的所有功能。     

2) 当你需要创建多个类，它们拥有很多相似的成员变量或成员函数时，也可以使用继承。可以将这些类的共同成员提取出来，定义为基类，然后从基类继承，既可以节省代码，也方便后续修改成员。    

下面我们定义一个基类 People，然后由此派生出 Student 类： 
```cpp
#include<iostream>
using namespace std;
//基类 Pelple
class People{
public:
    void setname(char *name);
    void setage(int age);
    char *getname();
    int getage();
private:
    char *m_name;
    int m_age;
};
void People::setname(char *name){ m_name = name; }
void People::setage(int age){ m_age = age; }
char* People::getname(){ return m_name; }
int People::getage(){ return m_age;}
//派生类 Student
class Student: public People{
public:
    void setscore(float score);
    float getscore();
private:
    float m_score;
};
void Student::setscore(float score){ m_score = score; }
float Student::getscore(){ return m_score; }
int main(){
    Student stu;
    stu.setname("小明");
    stu.setage(16);
    stu.setscore(95.5f);
    cout<<stu.getname()<<"的年龄是 "<<stu.getage()<<"，成绩是 "<<stu.getscore()<<endl;
    return 0;
}
```
运行结果：   
小明的年龄是 16，成绩是 95.5   

本例中，People 是基类，Student 是派生类。Student 类继承了 People 类的成员，同时还新增了自己的成员变量 score 和成员函数 setscore()、getscore()。这些继承过来的成员，可以通过子类对象访问，就像自己的一样。    

请认真观察代码第21行：    
	class Student: public People

这就是声明派生类的语法。class 后面的“Student”是新声明的派生类，冒号后面的“People”是已经存在的基类。在“People”之前有一关键宇 public，用来表示是公有继承。     

由此总结出继承的一般语法为：   
	class 派生类名:［继承方式］ 基类名{
	    派生类新增加的成员
	};

继承方式包括 public（公有的）、private（私有的）和 protected（受保护的），此项是可选的，如果不写，那么默认为 private。我们将在下节详细讲解这些不同的继承方式。    

16、   
c＋＋复习指南   
1、主要（必会）   
c＋＋试卷（转专业那个群）、50上机题库、实验报告题目   
2、刷题可用   
（QQ收藏/百度文库/照片）   
3、基础知识   
main：课本   
extra：南苑复习资料   
4、做题技巧   
（1）、输出结果题，先从main函数入手，用到其他函数就进入其他函数。（模拟程序实际的运行过程，注意栈、堆等地址）   
已知考点：for循环/引用/指针/数组指针/变量生存期/求和/注意细节（换行endl or 空格）   
（2）、填空题    
一般是一个已知问题（可能从50上机题里抽取，所以要会算法），先想正常人思考的算法（自己会怎么做），因为算法清晰明了了就很简单。  
如果实在和自己的想法不一样，看填空周围给的条件，映射出什么方法（算法）。  
（3）、程序手写题   
打草稿//变量声明，循环等，留好空    
算法为先，写法为后   

17、   
变量生存期相关问题、、引用传递相关问题（现在可以达到认识，会梳理就好了）  
```cpp
#include "iostream.h"
int z=2;

void f(int x, int &y)
{
   x=x+z;   y=x%z; z++;
   cout<<x<<'\t'<<y<<'\t'<<z<<endl;
}

void main()
{ int x,y,z;
  x=3; y=6; z=9;
  f(x,y); cout<<x<<'\t'<<y<<'\t'<<z<<'\t'<<::z<<endl;
  f(y,z); cout<<x<<'\t'<<y<<'\t'<<z<<'\t'<<::z<<endl;
}
```
输出结果：   
5       1       3  
3       1       9       3   
4       1       4   
3       1       1       4   
18、  
数组指针，相关    
```cpp
#include <iostream.h>
char a[]={"Hello World!"};

void main(){
int i;
char *p=a;
for(i=0; i<5; i++){
     cout<<*p<<'\t'<<p<<endl;
     p++;
}
cout<<endl; 
} 
```
输出结果：  
H       Hello World!  
e       ello World!   
l       llo World!  
l       lo World!   
o       o World!   
19、   
给定含有m+n个元素的整型数组A（其中m>0, n>0），它分为两个互不重叠的，长度分别为m和n的子数组段，写出交换这两个子数组段的程序，要求不引入数组A以外的数组，但可引入若干中间变量。例如，数组初始内容是：   

1	2	3	4	5	6	7	8	9     

设m=4，n=5，则程序运行后，数组内容为    

5	6	7	8	9	1	2	3	4     
```cpp
#include  <iostream.h>
const int  MAX=100; 
void main()
 { int a[MAX],m,n,i,j,temp;
    cin>>m>>n;
     for (i=0; i<m+n; i++)     
	cin>>     （1）    ;   //读入数组元素值                               
     for (i=     （2）    ; i>=0; i--)                            
     {
	temp=     （3）    ; 
	for (j=0; j<n; j++)           （4）    ;
	 a[i+n]=     （5）    ;
      }
      for (i=0; i<m+n; i++)    cout<<a[i]<<' ';
       cout<<endl;
  }
```

算法：基础：1 两个数交换    
           2 for循环，数组【？】下标问题    
          过程：从 4，开始，把4存到中间变量temp中，它的目标位置为 【9】，所有把5，6，7，8，9依次前移，把位置【9】空出来，4放进去。然后操作3，2，1。     
          解析：这样想是因为，（3）处temp是临时的意思，推断为中间变量（题目也有提示）   
                    （3）和（5）两个操作配合（2）把4，3，2，1分别放到位置【9】【8】【7】【6】，都是9/8/7/6/5，怎么办呢？这个时候发现（4）中循环次数为n次（5次），所有有循环往前迭代的想法，至此此题结束。    
          费曼学习法：    
          升华：填空题是带着镣铐跳舞，一个问题可以有许多不同的算法，但是普遍人的算法（出题人的算法要搞清楚），通过空格周围的条件，本格推理。 
	  

猫南北  借鉴        
编程题主要考点: 构造（拷贝）函数写法，组合类构造函数(子类)，字符串的处理方法，重载函数的写法(课件里例子要熟练掌握)，类的静态成员的使用方法，带指针成员的类的深拷贝，动态内存申请与释放等...        

20、    
```cpp
int a;

void test ()
{
  int a = ::a;//用全局变量a，给本地变量a赋值
}
```
21、   
*在定义时是指针  ，在运算时是解析   
&在定义时是引用，在运算时是取地址   
22、   
文件输入输出流   
```cpp
#include<fstream> //头文件 包括 ofstream（输出东西到txt文件里）  infstream（从文件里拿东西)
#include<iomanip>
using namespace std;

void main()
{ 	
	int x,y,z;
	 ofstream abc("myfile.txt");  //打开文件
               //还可以这样写  ofstream abc;    想起什么名字都行
                                        abc.open("myfile.txt");
	abc<<"   公鸡      母鸡      小鸡"<<endl;
	for(x=0; x<=20; x++)
	   for(y=0; y<=33; y++){
		z=100-x-y;
		if(5*x+3*y+z/3==100)		
		   abc<<setw(6)<<x<<setw(10)<<y<<setw(10)<<z<<endl; //写入文件
	   }
	abc.close(); //关闭文件   
}
```
23、某道题     
17.?编写程序，输出如下序列的前50项，此序列的第一项为0；第二项为1；以后的奇数项为其前两项之和；偶数项为其前两项之差。要求每行输出10个数。?      
答案写法：   
```cpp
#include"stdio.h"
void?main(){
int i,a=0,b=1,c,m=-1;
printf("%7d%7d",a,b);
for(i=3;i<=50;i++){
m=-m;  c=b+m*a;???
printf("%7d",c);?
if(i%10==0)????
printf("\n");?
a=b;???b=c;?
}
printf("\n");?
}
```
我的写法：  
```cpp
#include<iostream>
using namespace std;
int main() {
	int a[50],i;
	a[0] = 0;
	a[1] = 1;
	for (i = 2; i < 50; i++) {
		int t = i % 2;
		switch (t)
		{
		case 0:
			a[i] = a[i - 1] + a[i - 2]; break;
		case 1:
			a[i] = a[i - 2] - a[i - 1]; break;
        default:{}
			break;
		}
	}
	for (i = 0; i < 50; i++) {
		cout << a[i]<<' ';
		if ((i + 1) % 10 == 0)
			cout << endl;
	}

	return 0;
}
```
