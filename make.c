//adding header files
#include<stdio.h>
#include<string.h>
void main()
{

//name for what to be displayed
//type to choose from text,dropdown,radio
//title for the title of html file

char name[100], type[20], title[20];

//two variables i as counter and n for number of fields
int i,n;
FILE *f;

//creating file form.html
f=fopen("onform.html","w");
printf("Enter the title for your html file:");
scanf("%s", title);
printf("How many fields you want in your table:");
scanf("%d",&n);

//fprintf for writing the things in html file

fprintf(f,"<html><head><title>%s</title>",title);
fprintf(f,"</head></body><form>");

for(i=0; i<n; i++)
{
printf("Enter the name of field:");
scanf("%s",name);
printf("Enter the type of %s field:",name);
scanf("%s",type);
fprintf(f,"%s<input type=%s></br>",name,type);
}
fprintf(f,"</form></body></html>");
}
