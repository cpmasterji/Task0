 #include<iostream.h>
 #include<conio.h>
 void main()
 { clrscr();
 int a[50],n,min;
 cout<<"Enter total no. of elements ";
 cin>>n;                                                             `
 cout<<"Enter the elements ";
 for(int i=0;i<n;i++)
 cin>>a[i];
 min=a[0];
      for(int j=0;j<n;j++)
	if(a[j]<min)
	min=a[j];

 cout<<"Minimium element in array is "<<min;
 getch();
 }

