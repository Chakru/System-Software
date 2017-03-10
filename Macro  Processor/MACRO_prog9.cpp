#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char label[50],mnemonic[50],oper[50],str1[50],str2[50],str3[50];
	FILE *def,*name,*arg,*inp;
	inp=fopen("inputtab.txt","r");
	def=fopen("deftab.txt","r");
	arg=fopen("argtab.txt","w");
	name=fopen("nametab.txt","w");
	rewind(inp);
	rewind(def);
	while(!feof(inp))
	{
		fscanf(inp,"%s%s%s",label,mnemonic,oper);
		//printf("%s%s%s",label,mnemonic,oper);
		 if(strcmp(mnemonic,"MACRO")==0)
		 { 	
		 	strcpy(str3,oper);
		 	strcpy(str1,label);
		 	fscanf(def,"%s%s%s",label,mnemonic,oper);
		 	strcpy(str2,label);
		 	if(strcmp(str1,str2)==0)
		 	{
		 		fprintf(name,"%s",label);
		 		fprintf(arg,"%s",str3);
		 		while(strcmp(mnemonic,"MEND")!=0)
		 		{
		 			 fscanf(def,"%s%s%s",label,mnemonic,oper);
		 			 if(strcmp(mnemonic,"MEND")==0)
		 			 	break;
				 	 printf("%s\t%s\t%s\n",label,mnemonic,oper);
		 		}	
		 	}
			else
			{
				printf("No such MACRO exists");
			}
		}
		else
			printf("%s\t%s\t%s\n",label,mnemonic,oper);
			
		fscanf(inp,"%s%s%s",label,mnemonic,oper);
		printf("%s\t%s\t%s\n",label,mnemonic,oper);
	
	}
}
