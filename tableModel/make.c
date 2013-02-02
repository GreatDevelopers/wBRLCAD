//adding header files
#include<stdio.h>
#include<string.h>
void main()
{

//name for what to be displayed
//type to choose from text,dropdown,radio
//title for the title of html file

char name[100], type[20], title[20], css[20], script[20];

//two variables i as counter and n for number of fields
int i,n;
FILE *f;

//creating file form.html
f=fopen("onform.html","w");
printf("Enter the title for your html file:");
scanf("%s", title);
printf("Enter the css file to be used:");
scanf("%s",css);
printf("Enter the name of script file to be executed:");
scanf("%s",script);
printf("How many fields you want in your table:");
scanf("%d",&n);

//fprintf for writing the things in html file

fprintf(f,"<html><head> \n <title>%s</title>",title);
fprintf(f,"<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\"> \n </head></body>\n",css);
fprintf(f,"<header><h1>%s</h1></header>",title);
fprintf(f,"<table>");
fprintf(f, "<form action=\"%s\" method=\"GET\">",script);

for(i=0; i<n; i++)
{
printf("Enter the name of field:");
scanf("%s",name);
printf("Enter the type of %s field:",name);
scanf("%s",type);
fprintf(f,"<tr> \n <td>%s</td> \n <td><input type=%s name=%s></td></tr>\n",name,type,name);
}
fprintf(f,"<center><input type=submit value=Submit></center>");
fprintf(f,"</form></body></html>");
}
