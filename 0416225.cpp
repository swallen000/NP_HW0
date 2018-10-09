#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc,char* argv[]){
	if(argc!=3){
		cout<<"usage: "<<argv[0]<<" [input file path] [split token]\n";
		exit(1);
	}
	ifstream file(argv[1]);
	/*if(file==NULL){
		printf("ERROR!");
		exit(2);
	}*/
	char buf[1000];
	string str;
	string token;
	int flag=0;
	int length;
	length=strlen(argv[2]);
	token=argv[2];
	cout<<"------------------Input file "<<argv[1]<<" ------------------\n";
	file>>buf;
	while(getline(file,str)){
		if(strcmp(buf,"split")==0){
			cout<<buf<<str<<endl;
			flag=1;
		}
		else if(strcmp(buf,"reverse")==0){
			cout<<buf<<str<<endl;
			flag=2;
		}
		else{
			cout<<"error";
			flag=0;
		}
		if(str[0]==' ')
			str.erase(0,1);
		if(flag==2){
			/*string temp;
			istringstream ss(str);
			while(ss>>temp){*/
				for(int i=str.length()-1;i>=0;i--)
					cout<<str[i];
			//}
		}
		else if(flag==1){
			/*string temp;
			istringstream ss(str);
			while(ss>>temp){*/
				bool flag=true;
				for(int i=0;i<str.length()-length+1;i++){
					for(int j=0;j<length;j++){
						if(str[i+j]!=token[j])
							flag=false;
					}
					if(flag==true){
						str.erase(i,length);
						str.insert(i," ");
					}
					flag=true;
				}
				cout<<str;
			//}
		}
		cout<<endl;
		file>>buf;
	}
	cout<<"---------------End of input file "<<argv[1]<<" --------------\n";
	file.close();
	cout<<"**********************User input**********************\n";
	cin>>buf;
	while(getline(cin,str)){
		if(strcmp(buf,"exit")==0)
			break;
		else if(strcmp(buf,"reverse")==0){
			flag=2;
		}
		else if(strcmp(buf,"split")==0){
			flag=1;
		}
		else{
			printf("ERROR!");
			flag=0;
		}
		if(str[0]==' ')
			str.erase(0,1);
		if(flag==2){
			/*string temp;
			istringstream ss(str);
			while(ss>>temp){*/
				for(int i=str.length()-1;i>=0;i--)
					cout<<str[i];
			//}
		}
		else if(flag==1){
			/*string temp;
			istringstream ss(str);
			while(ss>>temp){*/
				bool flag=true;
				for(int i=0;i<str.length()-length+1;i++){
					for(int j=0;j<length;j++){
						if(str[i+j]!=token[j])
							flag=false;
					}
					if(flag==true){
						str.erase(i,length);
						str.insert(i," ");
					}
					flag=true;
				}
				cout<<str;
			//}
		}
		cout<<endl;
		cin>>buf;
	}
	return 0;
}
