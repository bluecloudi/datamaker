#ifndef DATAMAKER_H
#define DATAMAKER_H 1
#include<fstream>
#include<ctime>
#include<vector>
#include<typeinfo>
#include<map>
namespace std
{
	ifstream fin;//文件输入流 
	ofstream fout;// 文件输出流
	FILE *fr,*fw;// 文件指针 
	FILE *__cdecl fileo(char *name,char c)//打开文件 
	{
		if(c=='r')
		{
			fin.open(name,ios::in);
			
			return fr=fopen(name,"r");
		} 
		if(c=='w')
		{
			fout.open(name,ios::out);
			return fw=fopen(name,"w");
		} 
		if(c=='a')
		{
			fin.open(name,ios::in);
		    fout.open(name,ios::out);
		    return fr=fopen(name,"r"),fw=fopen(name,"w");
		}
		else return nullptr;
	}
	int __cdecl filec(char *name,char c)//关闭文件
	{
		if(c=='r')
		{
			fin.close();
			return fclose(fr);
		} 
		if(c=='w')
		{
			fout.close();
			return fclose(fw);
		} 
		if(c=='a')
		{
			fin.close();
			fout.close();
			return fclose(fr),fclose(fw);
		}
		else return 0;
	}
	template<typename T1,typename T2>
	struct graph{//图 
		vector<T1> v;
		struct edge1{
			int u,v;
			T2 w;
		};
		vector<edge1> e;
		bool add(int u,int v,T2 w)
		{
			if(u<0||v<0) return false;
			edge1 p;
			p.u=u;
			p.v=v;
			p.w=w;
			e.push_back(p);
			return true;
		}
		graph()
		{
			
		}
	};
	long long randll()//Rand long long 
	{
		srand(time(NULL));
		long long t=0,times=rand()%10;
		for(int i=1;i<=times;i++)
		{
			t=t*rand()+rand();
		}
		return t;
	}
	long long rand_l_r(long long l,long long r)//Rand l~r 
	{
		return randll()%(l-r+1)+l;
	}
	template<typename T1,typename T2,typename ...Args>
	auto rand_graph(int n,int m,bool yw)->decltype(graph)
	{
		graph<T1,T2> g; 
		if(typeid(T1)==typeid(long long))
		{
			
		}
		if(typeid(T1)==typeid(double))
		{
			
		}
		auto a=forward_as_tuple(T1(Args...));
		for(int i=1;i<=n;i++)
		{
			for_each(a,[](auto x)
		    {
		        if(typeid(x)==typeid(long long))
		        {
		        	x=randll();
				}
				if(typeid(x)==typeid(double))
				{
					
				}
		    });
		}
		return g;
	}
	template<typename T1,typename T2>
	int fprintg(graph<T1,T2> g) //输出图 
	{
		
		return 1;
	} 
	template<typename ...Args>
	int __cdecl fprint(const char *format,Args... argument)//printf 文件输出 
	{
		return fprintf(fw,format,argument...);
	}
	template<typename ...Args>
	int __cdecl fscan(const char *format,Args&... argument)//scanf 文件输入 
	{
		return fscanf(fr,format,argument...);
	}
}
#endif
