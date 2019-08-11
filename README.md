# datamaker.h
一个造数据的C++库，支持int,long long,char,string,[]。

举个例子：

```
#include<datamaker>
#inclued<iostream>
using namespace std;
int main()
{
	fileo("testdata.in",'a');//打开文件
	int n;
	brand(n);//随机数据赋值给n
	for(int i=1,t;i<=n;i++)
	{
		brand(t);随机数据赋值给t
		fprint("%d ",t);//在文件里输入t
	}
	filec('a');关闭文件
	return 0;
}
```

