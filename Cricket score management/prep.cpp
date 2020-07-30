#include<iostream>
#include <string> 
#include<fstream>
using namespace std;
int j=0;
int z=0;
int k=j+1;
class cricket
{
	
	int strike_[11],individual_score[11]={0,0,0,0,0,0,0,0,0,0,0};
	int balls_faced[11]={0,0,0,0,0,0,0,0,0,0,0};
	int fow[10]={0,0,0,0,0,0,0,0,0,0};
	//int extras=0;
	string a[11];
	public:
		int o,wik=0,extras=0,sum=0;
	
public:
	void getover()
	{
		
			cout<<"enter the no. of overs"<<endl;
			cin>>o;
			fstream myfile;
			myfile.open("summary.txt",std::fstream::app);
			myfile<<"\t\t\t\t\t\tSUMMARY\n\n\n";
	}
	void getplayers()
	{
		for (int i=0;i<11;i++)
		{
			cin>>a[i];
		}
	}
	/*void ball()
	{
		for(int i=0;i<11;i++)
		{
			if(strike_[i]==1)
			{
				balls_faced[i]++;
			}	
		}	
	}*/

	void strike(int x,int c,int b)
	{
		if(c==0&&b==1)
		{
			int j=0,k=j+1;
			strike_[j]=1;
			strike_[k]=2;
			for (int i=2;i<11;i++)
				strike_[i]=0;
		}
		if(b==6)
		{
			if(x%2==0)
			{
				int swap;
				swap=j;
				j=k;
				k=swap;
				strike_[j]=1;
				strike_[k]=2;
			}
		}
		if(b!=6&&x%2!=0)
		{
			int swap;
			swap=j;
			j=k;
			k=swap;
			strike_[j]=1;
			strike_[k]=2;
		}
		
	}
	void strike(char s,int b)
	{
		if(s=='w')
		{
			strike_[j]=0;
			j=j+2;
			if(b==6)
			{
				strike_[j]=2;
				strike_[k]=1;
			}
			else
			{
				strike_[j]=1;
				strike_[k]=2;
			}	
		}

	}
	void score(int x,int b)
	{
		
		for (int i=0;i<11;i++)
		{
			if (strike_[i]==1)
			{
				//cout<<a[i];
				individual_score[i]=individual_score[i]+x;
				balls_faced[i]++;
			}
		}
		sum=sum+x;
	}
	void score(char e)
	{
		if(e=='w')
		{
			wik++;
			for(int i=0;i<11;i++)
			{
				if(strike_[i]==1)
				{
					//cout<<a[i];
					balls_faced[i]++;
				}
			}
		}
		/*if(e=='W'||e=='n')
		{
			sum=sum+1;
		}*/
	}
	void print_score()
	{
		for(int i=0;i<11;i++)
		{
			if(individual_score[i]!=0)
			{
				cout<<a[i]<<"  "<<individual_score[i]<<"("<<balls_faced[i]<<")"<<endl;
			}
		}
		cout<<"total score   "<<sum<<"/"<<wik<<endl;
		cout<<"extras  "<<extras<<endl;
		cout<<"total number of wickets: "<<wik<<endl;
		cout<<"fall of wickets"<<endl;
		for(int i=0;i<10;i++)
		{
			if(fow[i]!=0)
				cout<<fow[i]<<"  ";
				
			else
				break;
		}
		cout<<endl;
	}
	void fall_of_wickets()
	{
		
		fow[z]=sum;
		z++;
	}
	void print_file()
	{
		std::fstream myfile;
		myfile.open("summary.txt",std::fstream::app);
		for(int i=0;i<11;i++)
		{
			if(individual_score[i]!=0)
			{
				myfile<<a[i]<<"  "<<individual_score[i]<<"("<<balls_faced[i]<<")"<<endl;
			}
		}
		myfile<<"total score   "<<sum<<"/"<<wik<<endl;
		myfile<<"extras  "<<extras<<endl;
		myfile<<"total number of wickets: "<<wik<<endl;
		myfile<<"fall of wickets"<<endl;
		for(int i=0;i<10;i++)
		{
			if(fow[i]!=0)
				myfile<<fow[i]<<"  ";
				
			else
				break;
		}
		myfile<<endl;
		myfile<<endl;
		myfile.close();
		
	}
};
int main()
{
	cricket c1,c2;
	c1.getover();
	int n;
	cout<<"enter the player names of team 1";
	c1.getplayers();
	cout<<"enter the player names of team 2";
	c2.getplayers();
	char s[c1.o][6];
	std::fstream myfile;
	myfile.open("summary.txt",std::fstream::app);
	//myfile<<"\t\t\t\t\t\tSUMMARY\n\n\n";
	//myfile<<"team 1";
	for(int i=0;i<c1.o;i++)
	{
		for(int j=1;j<7;j++)
		{    
		     
			cout<<"enter the score for"<<i<<"."<<j<<endl;
			cin>>s[i][j];
			//cout<<int(s[i][j]);
			if(int(s[i][j])<55&&int(s[i][j])>48)
			{
				//score(s[i][j]);
				//stringstream geek(s[i][j]); 
				//geek>>n;
				
				n=s[i][j]-48;
				c1.strike(n,i,j);
				c1.score(n,j);
			//	c1.ball();

			}
			else
			{
				if(s[i][j]=='W'||s[i][j]=='n')
				{
					j=j-1;
					c1.extras++;
					c1.sum++;
				}
				
				else{				
					if(s[i][j]=='w')
						{
							//c1.ball();
							c1.fall_of_wickets();
						}
					else
						{
							j=j-1;
							cout<<"invalid entry"<<endl;
						}
				}
				c1.strike(s[i][j],j);
				//c1.sum++;
				c1.score(s[i][j]);
			}
		}
	}
	j=0;
	k=j+1;
	z=0;
	//myfile<<"team 2";
	int p = c1.sum;
	c2.o = c1.o;
	//int my_count = 0;
	for(int i=0; i < c2.o; i++)
	{
		for(int j=1;j<7;j++)
		{
			
			cout<<"\nenter the score for: "<<i<<"."<<j<<endl;
			cin>>s[i][j];
			//cout<<int(s[i][j]);
			if(int(s[i][j])<55&&int(s[i][j])>48)
			{
				//score(s[i][j]);
				//stringstream geek(s[i][j]); 
				//geek>>n;
				
				n = s[i][j]-48;
				c2.strike(n,i,j);
				c2.score(n,j);				
			//	cout <<"\n"<< n <<endl;
			//	my_count += n;
			//	cout <<"\n"<< my_count << endl;
			//	c1.ball();

			}
			else
			{
				if(s[i][j]=='W'||s[i][j]=='n')
				{
					j=j-1;
					c2.extras++;
					c2.sum++;
					//cout <<"\n"<< s[i][j] <<endl;
					//my_count += n;
					//cout <<"\n"<< my_count << endl;
				}
				
				else{				
					if(s[i][j]=='w') {
							//c1.ball();
							c2.fall_of_wickets();
							//cout <<"\n"<< s[i][j] <<endl;

					} else {
							j=j-1;
							cout<<"\ninvalid entry\n"<<endl;
					}
				}
				c2.strike(s[i][j],j);
				//c1.sum++;
				c2.score(s[i][j]);
			}
		}
	}
	//myfile<<"TEAM 1";

	cout<<endl<<"score card of team 1"<<endl;
	c1.print_score();
	c1.print_file();
	cout<<"score card of team 2"<<endl;
	c2.print_score();
	//myfile<<"TEAM 2";
	c2.print_file();
	myfile<<endl;
	
	if(c1.sum>c2.sum){
		cout<<"team 1 won by "<<(c1.sum-c2.sum)<<" runs"<<endl;
		myfile<<"team 1 won by "<<(c1.sum-c2.sum)<<" runs"<<endl;
		}
	else
	{
		if(c1.sum<c2.sum)
		{
			cout<<"team 2 won by "<<10-c2.wik<<" wickets"<<endl;
			myfile<<"team 2 won by "<<10-c2.wik<<" wickets"<<endl;
		}
		else
		{
			cout<<"match drawn"<<endl;
			myfile<<"match drawn"<<endl;
			cout<<"enter the score for super over"<<endl;
			//int n=c1.sum;
			int m=c2.sum;
			int i=0;
			for(int j=1;j<7;j++)
			{
			
				cout<<"enter the score for"<<i<<"."<<j<<endl;
			cin>>s[i][j];
			//cout<<int(s[i][j]);
			if(int(s[i][j])<55&&int(s[i][j])>48)
			{
				//score(s[i][j]);
				//stringstream geek(s[i][j]); 
				//geek>>n;
				
				n=s[i][j]-48;
				c1.strike(n,i,j);
				c1.score(n,j);
			//	c1.ball();

			}
			else
			{
				if(s[i][j]=='W'||s[i][j]=='n')
				{
					j=j-1;
					c1.extras++;
					c1.sum++;
				}
				
				else{				
					if(s[i][j]=='w')
						{
							//c1.ball();
							c1.fall_of_wickets();
						}
					else
						{
							j=j-1;
							cout<<"invalid entry"<<endl;
						}
					}
				c1.strike(s[i][j],j);
				//c1.sum++;
				c1.score(s[i][j]);
				}
			}
			i=0;
			for(int j=1;j<7;j++)
			{
				cout<<"enter the score for"<<i<<"."<<j<<endl;
				cin>>s[i][j];
			//cout<<int(s[i][j]);
			if(int(s[i][j])<55&&int(s[i][j])>48)
			{
				//score(s[i][j]);
				//stringstream geek(s[i][j]); 
				//geek>>n;
				
				n=s[i][j]-48;
				c2.strike(n,i,j);
				c2.score(n,j);
			//	c1.ball();

			}
			else
			{
				if(s[i][j]=='W'||s[i][j]=='n')
				{
					j=j-1;
					c2.extras++;
					c2.sum++;
				}
				
				else{				
					if(s[i][j]=='w')
						{
							//c1.ball();
							c2.fall_of_wickets();
						}
					else
						{
							j=j-1;
							cout<<"invalid entry"<<endl;
						}
				}
				c2.strike(s[i][j],j);
				//c1.sum++;
				c2.score(s[i][j]);
			}
			}
			cout<<"team 1 score:"<<c1.sum-p<<endl;
			cout<<"team 2 score:"<<c2.sum-m<<endl;
			if(c1.sum>c2.sum)
			{
				cout<<"team 1 victory";
				myfile<<endl<<"team 1 victory";
			}
			else
			{
				if(c1.sum<c2.sum)
				{
					cout<<"team 2 victory";
					myfile<<endl<<"team 2 victory";
				}
				else
				{
					cout<<"match drawn"<<endl;
					myfile<<endl<<"match drawn ";
					
				}
			}			
		}
	}myfile.close();
}
