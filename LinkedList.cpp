#include <bits/stdc++.h>
using namespace std;
// buoi 24
struct Node{
	//data
	int x;
	// reference, la mot con tro kieu node
	Node* next;
};

//tao mot node moi tu thong tin da co
Node* taoNode(int data){
	// cap phat dong 1 node
	Node* temp = new Node();
	temp->x = data;
	temp->next = NULL;
	return temp;
}

int Size(Node* head){
	int dem = 0;
	while(head!=NULL){
		dem++;
		head = head->next; // dia chi cua node tiep theo trong dslk
	}
	return dem;
}

void display(Node* head){
	cout <<"In ra danh sach lien ket:\n";
	while(head != NULL){
		cout << head->x<<" ";
		head = head->next;
	}
}

void themdau(Node* &head, int data){
	Node* moi = taoNode(data);
	if(head == NULL){
		head = moi;
	}else{
		//b1: cap nhat tham chieu
		moi->next = head;
		head = moi; 
	}
}

void themcuoi(Node* head, int data){
	Node* moi = taoNode(data);
	if(head == NULL){
		head = moi;
	}else{
		Node* temp = head;
		while(temp->next !=NULL){
			temp = temp->next;
		}
		temp->next = moi;
	}
}

void themgiua(Node* &head, int data, int vitri){
	int n = Size(head);
	if(vitri <1 or vitri >n+1){
		cout <<"Vi tri khong hop le\n";
		return;
	}
	if(vitri == 1){
		themdau(head,data);
	}else if(vitri == n+1){
		themcuoi(head,data);
	}else{
		Node* temp = head;
		for(int i =1; i<= vitri-2; i++){
			temp = temp->next;
		}
		Node* moi = taoNode(data);
		moi->next = temp->next;
		temp->next = moi;
	}
}
void xoadau(Node* &head){
	if(head == NULL){
		cout<<"DSLK rong\n";
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
}
void xoacuoi(Node* &head){
	if(head==NULL){
		cout<<"DSLK rong\n";
		return;
	}
	Node* p = head;
	Node* q = NULL;
	while(p -> next != NULL){
		q = p;
		p = p->next;
	}
	delete p;
	if(q == NULL){
		head = NULL;
	}else{
		q->next = NULL;
	}
}

void xoagiua(Node* head, int vitri){
	int n = Size(head);
	if(vitri <1 or vitri > n){
		cout <<"Vi tri khong hop le\n";
		return;
	}
	Node* p=head;
	Node* q= NULL;
	for(int i=1; i<vitri; i++){
		q =p;
		p = p->next;
	}
	if(q !=NULL){
		q->next = p->next;
	}else head = head->next;
	delete p;
}

bool timkiem(Node* head, int val){
	while(head != NULL){
		if(head->x == val){
			return true;
		}else head = head->next;
	}
	return false;	
}

void sapxep(Node* &head){
	for(Node* i = head; i!= NULL; i = i->next){
		Node* min = i;
		for(Node* j =i->next; j!=NULL; j=j->next){
			if(j->x < min->x){
				min = j;
			}
		}
		// swap(min->x, i->x)
		int temp = min->x;
		min->x = i->x;
		i->x = temp;
		
	}	
}

void dao(Node* &head){
	vector<int> temp;
	Node* p =head;
	while(p!=NULL){
		temp.push_back(p->x);
		p = p->next;
	}
	reverse(temp.begin(), temp.end());
	Node* tmp = head;
	int i = 0;
	while(tmp != NULL){
		tmp->x = temp[i++];
		tmp = tmp->next;
	}
}
int main(){
	Node* head =NULL;
	while(1){
		cout <<"-----------MENU----------\n";
		cout <<"1. Them vao dau dslk\n";
		cout <<"2. Them vao cuoi dslk\n";
		cout <<"3. Them vao giua dslk\n";
		cout <<"4. Xoa dau dslk\n";
		cout <<"5. Xoa cuoi dslk\n";
		cout <<"6. Xoa vi tri o giua\n";
		cout <<"7. Tim kiem\n";
		cout <<"8. Sap xep\n";
		cout <<"9. Lat nguoc dslk\n";
		cout <<"10. Hien thi dslk\n";
		cout <<"0. Ket thuc dslk\n";
		cout<<"--------------------------\n";
		int n; cin>>n;
		if(n==1){
			int x; cout <<"Nhap gia tri can them dau: "; cin>>x;
			themdau(head,x);
		}else if(n==2){
			int x; cout<<"Nhap gia tri can them cuoi: "; cin>>x;
			themcuoi(head,x);
		}else if(n==3){
			int x; cout<<"Nhap gia tri can them giua: "; cin>>x;
			int y; cout<<"Nhap vi tri can them: "; cin>>y;
			themgiua(head,x,y);
		}else if(n==4){
			xoadau(head);
		}else if(n==5){
			xoacuoi(head);
		}else if(n==6){
			int vitri; cout<<"Nhap vao vao vi tri can xoa"; cin>>vitri;
			xoagiua(head, vitri);
		}else if(n==7){
			int x; cout <<"Nhap gia tri can tim: "; cin>>x;
			if(timkiem(head,x)){
				cout <<"Gia tri ton tai trong dslk\n";
			}else cout<<"Gia tri khong ton tai trong dslk\n";
		}else if(n==8){
			cout<<"Danh sach da duoc sap xep\n";
			sapxep(head);
		}else if(n==9){
			cout <<"DSLK da lat nguoc\n";
			dao(head);
		}else if(n==10){
			display(head);
			cout <<endl;
		}else if(n==0){
			break;
		}
	}	
}
