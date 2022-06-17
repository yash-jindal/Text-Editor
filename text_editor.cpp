#include <iostream>
#include <conio.h>
#include <fstream>
int flag=0;
using namespace std;

class Node{
	public:
		char val;
		Node *next;
};

class TextStack{
	private:
		Node *top;
	public:
		TextStack(){
			top = NULL;
		}
		void insert(char c){
			Node *temp = new Node;
			if(temp){
				temp->val = c;
				temp->next = top;
				top = temp;
			}
		}
		char del(){
			char x;
			if(top){
				flag=0;
				Node *p = top;
				x = top->val;
				top = top->next;
				delete p;
			}else{
				flag=1;
			}
			return x;
		}
		char del2(){
			char x;
			if(top->next){
				flag=0;
				Node *p = top;
				x = top->val;
				top = top->next;
				delete p;
			}else{
				flag=1;
			}
			return x;
		}
		string show(){
			Node *t = top;
			string s="";
			string p="";
			int length=0;
			while(t){
				s=s+t->val;
				length++;
				t=t->next;
			}
			for(int i=length-1;i>=0;i--){
				cout<<s[i];
				p=p+s[i];
			}
			return p;
		}
		string show2(){
			Node *t = top;
			string s="";
			cout<<'|';
			while(t->next){
				cout<<t->val;
				s=s+t->val;
				t=t->next;
			}
			return s;
		}
		
};
int main(){
	TextStack leftText;
	TextStack rightText;
	rightText.insert('|');
	char c1,c2,input;
	char check1='y';
    char check2='y';
    cout<<"\n";
    menu:
	cout<<"Enter your Choice\n";
	cout<<"Enter '/i' to insert characters\n";
	cout<<"Enter '/d' to delete characters\n";
	cout<<"Enter '/m' to move cursor\n";
	cout<<"Enter '/s' to save text to a file\n";
	cout<<"Enter '/r' to read a text file\n";
	cout<<"Enter '/?' exit\n";
	cout<<"\n";
	cin>>c1>>c2;
	if(c1 == '/' && c2 == 'i'){
		check1 = 'y';
		check2 = 'y';
		goto insert;
	}else if(c1 == '/' && c2 == 'd'){
		check1 = 'y';
		check2 = 'y';
		goto del;
	}else if(c1 == '/' && c2 == 'm'){
		check1 = 'y';
		check2 = 'y';
		goto move;
	}else if(c1 == '/' && c2 == 's'){
		goto save;
	}else if(c1 == '/' && c2 == 'r'){
		goto read;
	}else if(c1 == '/' && c2 == '?'){
		goto exit;
	}else{
		cout<<"Invalid Choice\n";
		cout<<"Try Again!\n";
		goto menu;
	}
    
    insert:
    	cout<<"You have entered into Insert section\n";
    while(!(check1 == '/' && check2 == '?')){
       check1 = check2;
       leftText.show();	
       rightText.show2();
       cout<<"\n";
       input = _getch();
       check2 = input;
	   if(check1 == '/' && check2 == 'd'){
	   	leftText.del();
	   	goto del;
	   }
	   if(check1 == '/' && check2 == 'm'){
	   	leftText.del();
	   	goto move;
	   }
	   if(check1 == '/' && check2 == 's'){
	   	leftText.del();
	   	goto save;
	   }
	   if(check1 == '/' && check2 == 'r'){
	   	leftText.del();
	   	goto read;
	   }
	   if(check1 == '/' && check2 == '?'){
	   	leftText.del();
	   	goto exit;
	   } 
	   leftText.insert(input);
	}
     del:
     	cout<<"You have entered into delete section\nYou can delete characters by pressing 'd'\n";
     	while(!(check1 == '/' && check2 == '?')){
       check1 = check2;
       leftText.show();	
       rightText.show2();
       cout<<"\n";
       input = _getch();
       check2 = input;
       if(input == '/'){
       	leftText.insert(input);
       	leftText.show();
       	rightText.show2();
       	cout<<"\n";
       	input = _getch();
       	if(input == 'm'){
       		leftText.del();
       		check1 = 'y';
		    check2 = 'y';
       		goto move;
		   }
		if(input == 'i'){
			leftText.del();
			check1 = 'y';
		    check2 = 'y';
			goto insert;
		}
		if(input == 's'){
			leftText.del();
			check1 = 'y';
		    check2 = 'y';
			goto save;
		}
		if(input == 'r'){
			leftText.del();
			check1 = 'y';
		    check2 = 'y';
			goto read;
		}
		if(input == '?'){
			leftText.del();
			goto exit;
		}else{
			leftText.del();
			cout<<"You have entered wrong key. Please press 'd' to delete a character\n";
	   	    continue;
		}
	   }
	   if(input != 'd'){
	   	cout<<"You have entered wrong key. Please press 'd' to delete a character\n";
	   	continue;
	   }
	   leftText.del(); 
	}
     	
     move:
     	 	cout<<"You have entered into move cursor section\nYou can move your cursor left by pressing 'a' and right by pressing 'd'\n";
     	while(!(check1 == '/' && check2 == '?')){
       check1 = check2;
       leftText.show();	
       rightText.show2();
       cout<<"\n";
       input = _getch();
       check2 = input;
       if(input == '/'){
       	leftText.insert(input);
       	leftText.show();
       	rightText.show2();
       	cout<<"\n";
       	input = _getch();
       	if(input == 'd'){
       		leftText.del();
       		check1 = 'y';
		    check2 = 'y';
       		goto del;
		   }
		if(input == 'i'){
			leftText.del();
			check1 = 'y';
		    check2 = 'y';
			goto insert;
		}
		if(input == 's'){
			leftText.del();
			check1 = 'y';
		    check2 = 'y';
			goto save;
		}
		if(input == 'r'){
			leftText.del();
			check1 = 'y';
		    check2 = 'y';
			goto read;
		}
		if(input == '?'){
			leftText.del();
			goto exit;
		}else{
			leftText.del();
			cout<<"You have entered wrong key. Please press 'a' to move your cursor in left direction or press 'd' to move your cursor in right direction\n";
	   	    continue;
		}
	   }
	   if(input != 'd' && input != 'a'){
	   	cout<<"You have entered wrong key. Please press 'a' to move your cursor in left direction or press 'd' to move your cursor in right direction\n";
	   	continue;
	   }
	   if(input == 'a'){
	   	rightText.insert(leftText.del());
	   }if(input == 'd'){
	   	leftText.insert(rightText.del2());
	   }
	}
	save:
		{
		
		cout<<"Enter the name that you want to give to your file\nIf you want to save the text in the already present file, then just enter the name of that file, \notherwise you can give any other name\n\n";
		string name;
		cin>>name;
		cout<<"\n";
		fstream FileName;
		name = name + ".txt";
		char* char_arr;
        char_arr = &name[0]; 
		FileName.open(char_arr,ios::out);
		if(!FileName){
			cout<<"Error while creating the file\n";
		}else{
			cout<<"Text Saved!\n\n";
			FileName<<leftText.show() + rightText.show2();
			cout<<"\n\n";
			FileName.close();
		}
		goto menu;
	}
	read:
		{
			cout<<"Enter the name of the file\n";
			string str_read;
			cin>>str_read;
			str_read = str_read + ".txt";
			char* char_read;
			char_read = &str_read[0];
			fstream FileRead;
			FileRead.open(char_read,ios::in);
			if(!FileRead){
				cout<<"File doesn't Exist!\n";
				goto menu;
			}else{
				char temp;
				while(1){
					FileRead>>std::noskipws>>temp;
					if(FileRead.eof()){
						break;
					}
					    cout<<temp;	
					
					
				}
				FileRead.close();
			}
			cout<<"\n";
			goto menu;
		}
    exit:

	return 0;
}
