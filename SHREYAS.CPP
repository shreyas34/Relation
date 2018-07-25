#include <iostream.h>
#include <stdio.h>
#include <ctype.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
// max size of the matrix is set to 10
# define size 10

class MENU
{
	int A[size][size];
	char ifile[100],ofile[100];
	int m,n;// matrix is of size m x n;
	ofstream out;
	ifstream in;
	public :
			void input();
			void display();
			void output();
			
			
			
			MENU(char* ,char *,int,int);
			
			
			void main_menu(void) ;
			void introduction(void) ;
			void properties_of_relation(void); 
			void properties_of_matrices(void);

			// properties_of_relation
			void Reflexive(void) ;
			void Irreflexive(void) ;
			void Equality(void) ;
			void Inequality(void) ;
			void Symmetric(void) ;
			//void Asymmetric(void) ;
			void Transitive_closure(void) ;


			//properties_of_matrices

			void Union(void);
			void Intersection(void);
			void Compliment(void);
			void Inverse(void);

} ;


// functions of Properties of Relation

MENU:: MENU(char* ifname,char* ofname, int m1, int n1)
{ strcpy(ifile,ifname);
  strcpy(ofile,ofname);
  m=m1; n=n1;
}



void MENU::input()
{ in.open(ifile);
  int i=0,j=0;
  while(in>>A[i][j])
  {
   j++;
   if(j==n)   {j=0; i++;}
   if(i==m) break;
  }//end while
  in.close();
 }// end inputdata
 
 
void MENU::display()
{
    for(int i=0;i<m;i++)
    {
	for(int j=0;j<n;j++)
	 {
	   cout<<A[i][j]<<"\t";
	 } //end for j
	   cout<<"\n";
    }// end for i
}// end display()


void MENU::output()
{
 out.open(ofile);
  for(int i=0;i<m;i++)
  {
	for(int j=0;j<n;j++)
	 {
	  out<<A[i][j]<<"\t";
	 } //end for j
	  out<<"\n";
  }// end for i
}



void MENU :: Reflexive(void)
{
	clrscr();
	int ld=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<"\t";
			if(i==j)
			{
				ld=ld*A[i][j];
			}
	 } //end for j
	  cout<<"\n";
  }// end for i
  if (ld == 1 )
	    {
		cout<<"It is reflexive matrix \n";
	    }
	    else
	    {
		cout<<"It is not a reflexive matrix \n";
	    }
	    getch();
}
void MENU :: Irreflexive(void)
{
	clrscr();
	int ld=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<"\t";
			if(i==j)
			{
				ld=ld+A[i][j];
			}
		} //end for j
			cout<<"\n";
	}// end for i
	if (ld == 0 )
	    {
		cout<<"It is Irreflexive matrix \n";
	    }
	    else
	    {
		cout<<"It is not a Irreflexive matrix \n";
	    }
	   
	getch();
}

void MENU :: Equality(void) 
{
	clrscr();
	int flag;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<"\t";
			if (A[i][j] != 1 && A[j][i] != 0)
	            {
	                flag = 0;
					//break;
	            }
		} //end for j
			cout<<"\n";
	}// end for i
	if (flag == 1 )
	    {
		cout<<"It is Equality matrix \n";
	    }
	    else
	    {
		cout<<"It is not a Equality matrix \n";
	    }
	getch();
			
}

void MENU :: Inequality(void) 
{
	clrscr();
	int flag;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<"\t";
			if (A[i][j] != 0 && A[j][i] != 1)
	            {
	                flag = 0;
					//break;
	            }
		} //end for j
				cout<<"\n";
	}// end for i
		if (flag == 1 )
	    {
		cout<<"It is inequality matrix \n";
	    }
	    else
	    {
		cout<<"It is not a inequality matrix \n";
	    }
	getch();
			
}

void MENU :: Symmetric(void)
{
	clrscr();
	int flag;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<"\t";
			if (A[i][j] != A[j][i])
	            {
	                flag = 0;
					break;
	            }
		} //end for j
			cout<<"\n";
	}// end for i
	if (flag == 1 )
	    {
		cout<<"It is symetric matrix \n";
	    }
	    else
	    {
		cout<<"It is not a symmetric matrix \n";
	    }
	getch();
				
}

void MENU :: Transitive_closure(void)
{
	clrscr();
    int num_nodes, k, n;
    char i, j, res, c;
    int adj[10][10], path[10][10];
 
    cout << "\n\tMaximum number of nodes in the graph :";
    cin >> n;
    num_nodes = n;
    cout << "\n\n\tNODES ARE LABELED AS A,B,C,......\n\n";
    cout << "\nEnter 'y'for 'YES' and 'n' for 'NO' !!\n";
 
    for (i = 65; i < 65 + num_nodes; i++)
        for (j = 65; j < 65 + num_nodes; j++)
        {
            cout << "\n\tIs there an EDGE from " << i << " to " << j << " ? ";
            cin >> res;
            if (res == 'y')
                adj[i - 65][j - 65] = 1;
            else
                adj[i - 65][j - 65] = 0;
        }
    cout << "\nAdjacency Matrix:\n";
 
    cout << "\n\t\t\t   ";
    for (i = 0; i < num_nodes; i++)
    {
        c = 65 + i;
        cout << c << " ";
    }
    cout << "\n\n";
    for (i = 0; i < num_nodes; i++)
    {
        c = 65 + i;
        cout << "\t\t\t" << c << "  ";
        for (j = 0; j < num_nodes; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    for (i = 0; i < num_nodes; i++)
        for (j = 0; j < num_nodes; j++)
            path[i][j] = adj[i][j];
 
    for (k = 0; k < num_nodes; k++)
        for (i = 0; i < num_nodes; i++)
            if (path[i][k] == 1)
                for (j = 0; j < num_nodes; j++)
                    path[i][j] = path[i][j] || path[k][j];
 
    for (i = 0; i < num_nodes; i++)
        for (j = 0; j < num_nodes; j++)
            adj[i][j] = path[i][j];
 
    cout << "\nTransitive Closure of the Graph:\n";
 
    cout << "\n\t\t\t   ";
    for (i = 0; i < num_nodes; i++)
    {
        c = 65 + i;
        cout << c << " ";
    }
    cout << "\n\n";
    for (i = 0; i < num_nodes; i++)
    {
        c = 65 + i;
        cout << "\t\t\t" << c << "  ";
        for (j = 0; j < num_nodes; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
	getch();
}

void MENU :: introduction(void)
{
	clrscr() ;
	gotoxy(31,5) ;
	cout <<"Welcome to Project" ;
	textcolor(BLACK+BLINK) ; textbackground(WHITE) ;
	gotoxy(33,7) ;
	cprintf(" RELATIONS ") ;
	textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
	gotoxy(15,10) ;
	cout <<"A relation may consist of a finite number of ordered pairs " ;
	gotoxy(15,11) ;
	cout <<"or an infinite number of ordered pairs. " ;
	gotoxy(15,13) ;
	cout <<"The first item in an ordered pair is identified as the " ;
	gotoxy(15,14) ;
	cout <<"Domain." ;
	gotoxy(15,16) ;
	cout <<"The second item in the ordered pair is identified as the " ;
	gotoxy(15,17) ;
	cout <<"Range ." ;

	textcolor(LIGHTGRAY+BLINK) ;
	gotoxy(27,24) ;
	cprintf("Press any key to continue") ;
	textcolor(LIGHTGRAY) ;
	getch() ;
}

void MENU :: properties_of_relation(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(32,7) ;                        
		cout <<"PROPERTIES OF RELATIONS";
		gotoxy(32,8) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(34,10) ;
		cout <<"1. REFLEXIVE" ;
		gotoxy(34,11) ;
		cout <<"2. IRREFLEXIVE" ;
		gotoxy(34,12) ;
		cout <<"3. EQUALITY" ;
		gotoxy(34,13) ;
		cout <<"4. INEQUALITY" ;
		gotoxy(34,14) ;
		cout <<"5. SYMMETRIC" ;
		gotoxy(34,15) ;
		cout <<"6. TRANSITIVE CLOSURE" ;
		gotoxy(34,16) ;
		cout <<"0. EXIT" ;
		gotoxy(31,19) ;
		cout <<"Enter your choice : " ;
		ch = getche();
		if (ch == 27)
		break ;
		else
		if (ch =='1')
			Reflexive();
		else
		if (ch =='2')
			Irreflexive();
		else
		if (ch =='3')
			Equality();
		else
		if (ch =='4')
			Inequality();
		else
		if (ch =='5')
			Symmetric();
		else
		if (ch =='6')
			Transitive_closure();
		else
		if (ch == '0')
		break ;
	}
}

void MENU :: properties_of_matrices(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(32,7) ;
		cout <<"PROPERTIES OF MATRICES";
		gotoxy(32,8) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(34,10) ;
		cout <<"1. UNION" ;
		gotoxy(34,11) ;
		cout <<"2. INTERSECTION" ;
		gotoxy(34,12) ;
		cout <<"3. COMPLIMENT" ;
		gotoxy(34,13) ;
		cout <<"4. INVERSE" ;
		gotoxy(34,14) ;
		cout <<"0. EXIT" ;
		gotoxy(31,15) ;
		cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
		break ;
		else
		if (ch == '1')
		Union();
		else
		if (ch == '2')
		Intersection();
		else
		if (ch == '3')
		Compliment() ;
		else
		if (ch == '4')
		Inverse() ;
		else
		if (ch == '0')
		break ;
	}
}

void MENU :: Compliment(void)
{
	clrscr();
	cout<<"Compliment Is :"<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<"\t";
			if(A[i][j]==1)
			{
				A[i][j]=0;
			}
			else
			{
				A[i][j]=1;
			}
		} //end for j
			cout<<"\n";
	}// end for i
	getch();	
			
}

void MENU :: Inverse(void)
{
	clrscr();
	cout<<"Inverse Is :"<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[j][i]<<"\t";
		}
		cout<<"\n";
	}
	getch();
			
}

void MENU :: Union(void)
{
	clrscr();
	int a[10][10],b[10][10],c[10][10],row,column,i,j;
	cout<<"Enter the order of the matrix :\n";
	cin>>row>>column;
	cout<<"Enter the elements of matrix Mr :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Enter the elements of matrix Ms :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<"MATRIX Mr is  :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n\n";
	}
	cout<<"MATRIX Ms is  :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<"\n\n";
	}
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			if(a[i][j]==1 || b[i][j]==1)
			{
				c[i][j]=1;
			}
			else
			{
				c[i][j]=0;
			}

		}
	}
	cout<<"Mr Union Ms: \n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<"\n\n";
	}
	getch();
}


void MENU :: Intersection(void)
{
	clrscr();
	int a[10][10],b[10][10],c[10][10],row,column,i,j;
	cout<<"Enter the order of the matrix :\n";
	cin>>row>>column;
	cout<<"Enter the elements of matrix Mr :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Enter the elements of matrix Ms :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<"MATRIX Mr is  :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n\n";
	}
	cout<<"MATRIX Ms is  :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<"\n\n";
	}
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			if(a[i][j]==1 && b[i][j]==1)
			{
				c[i][j]=1;
			}
			else
			{
				c[i][j]=0;
			}

		}
	}
	cout<<"Mr Intersection Ms: \n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<"\n\n";
	}
	getch();
}



void MENU :: main_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(34,6) ;
		cout <<"RELATIONS" ;
		gotoxy(29,7) ;
		cout <<"~~~~~~~~~~~~~~~~~~" ;
		gotoxy(30,10) ;
		cout <<"1. INTRODUCTION" ;
		gotoxy(30,11) ;
		cout <<"2. PROPERTIES OF RELATIONS " ;
		gotoxy(30,12) ;
		cout <<"3. PROPERTIES OF MATRICES " ;
		gotoxy(30,13) ;
		cout <<"0. QUIT" ;
		gotoxy(30,20) ;
		cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch == '1')
			introduction() ;
		else
		if (ch == '2')
			properties_of_relation() ;
		else
			if (ch == '3')
			properties_of_matrices() ;
		else
		if (ch == '0')
			break ;
	}
}
//Properties of Matrices 

void main()
{
	char ifname[]="c:\\TURBOC3\\bin\\Rel.txt";
	char ofname[]="c:\\TURBOC3\\bin\\output.txt" ;
	
	
	int m1=10,n1=10;
	
	// Relation matrix is stored in Rel.txt size m1=2, n1=3;
	MENU R(ifname,ofname,m1,n1);
	clrscr();
	R.input();
	R.display();
	
	R.introduction() ;
	R.main_menu() ;
	R.output();

	
	getch();
	
}
