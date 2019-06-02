#ifndef DATAMAKER_H
#define DATAMAKER_H 1
#include<fstream>
#include<ctime>
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
	#define MAX_GRAPH_N 10001
	template<typename T,int wh>
	struct graph{
		struct edge1{
			int u,v;
			T w;
		};
		struct edge2{
			int next,v;
			T w;
		};
		#if wh==1
		T vector<vector<int>> e;
		bool add(int u,int v,T w)
		{
			if(u>MAX_GRAPH_N||v>MAX_GRAPH_N||u<0||v<0) return false;
			e[u][v]=w;
			return true;
		}
		#endif
		#if wh==2
		vector<edge2> e;
		long long head[n];
		bool add(int u,int v,T w)
		{
			if(u>n||v>n||u<0||v<0) return false;
			edge2 c;
			c.v=v;
			c.w=w;
			c.next=head[u];
			head[u]=c.size();
			return true;
		}
		#endif
		#if wh==3
		edge1 e[m],p;
		bool add(int u,int v,T w)
		{
			if(u>n||v>n||u<0||v<0) return false;
			edge a;
			e[++p].u=u;
			e[p].v=v;
			e[p].w=w;
			return true;
		}
		#endif
	};
	long long randll()
	{
		srand(unsigned(time(NULL)));
		long long t=0,times=rand()%10;
		for(int i=1;i<=times;i++)
		{
			t=t*rand()+rand();
		}
		return t;
	}
	long long rand_l_r(long long l,long long r)
	{
		return randll()%(l-r+1)+l;
	}
	template<typename T>
	auto rand_graph(int n,int m,int wh,bool yw)->decltype(graph)
	{
		graph<T,wh> g; 
		return g;
	}
}
#endif
