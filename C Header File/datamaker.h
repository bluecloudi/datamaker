#ifndef DATAMAKER_H
#define DATAMAKER_H 1
#include<fstream>
#include<ctime>
#include<vector>
#include<typeinfo>
#include<map>
namespace std
{
	ifstream fin;
	ofstream fout;
	FILE *fr,*fw; 
	FILE *__cdecl fileo(char *name,char c)
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
	int __cdecl filec(char *name,char c)
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
	struct graph{
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
	};
	void brand(int &t)
	{
		srand(time(NULL));
		int times=(rand()-1)%5+1;
		for(int i=1;i<=times;i++)
		{
			t=t*rand()+rand();
		}
	}
	void brand(long long &t)
	{
		srand(time(NULL));
		long long times=(rand()-1)%10+1;
		for(int i=1;i<=times;i++)
		{
			t=t*rand()+rand();
		}
	}
	long long brand_l_r(long long l,long long r)
	{
		long long t;
		brand(t);
		return t%(l-r+1)+l;
	} 
	template<typename ...Args>
	int __cdecl fprint(const char *format,Args... argument)
	{
		return fprintf(fw,format,argument...);
	}
	template<typename ...Args>
	int __cdecl fscan(const char *format,Args&... argument)
	{
		return fscanf(fr,format,argument...);
	}
}
#endif
