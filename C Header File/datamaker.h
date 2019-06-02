#ifndef ZSJ_H
#define ZSJ_H 1
#include<fstream>
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
	template<int n,int m,int wh,typename T>
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
		T e[n][n];
		bool add(int u,int v,T w)
		{
			if(u>n||v>n||u<0||v<0) return false;
			e[u][v]=w;
			return true;
		}
		#endif
		#if wh==2
		edge2 e[m];
		int head[n],p;
		bool add(int u,int v,T w)
		{
			if(u>n||v>n||u<0||v<0) return false;
			e[++p].v=v;
			e[p].w=w;
			e[p].next=head[u];
			head[u]=p;
			return true;
		}
		#endif
		#if wh==3
		edge1 e[m],p;
		bool add(int u,int v,T w)
		{
			if(u>n||v>n||u<0||v<0) return false;
			e[++p].u=u;
			e[p].v=v;
			e[p].w=w;
			return true;
		}
		#endif
	};
	long long randll()
	{
		
	}
	long long rand_l_r()
	{
		
	}
	graph rand_graph(int n,int m,bool yw)
	{
		
	}
}
#endif
