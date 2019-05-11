#ifndef DATAMAKER_H
#define DATAMAKER_H 1
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
}
#endif
