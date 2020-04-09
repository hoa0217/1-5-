#include <stdio.h>
#include <string.h>

#define MAX_NUM 100

//���� ���� ����ü
typedef struct{
	char name [30];
	char number[30];
	char address[30];
	char email[30];
}User; 
void add(User*ptr,int*num);
int deleted(User*ptr,int*num);
int search(User*ptr,int*num);
void list(User*ptr,int*num);
int edit(User*ptr,int*num);
void egg(User*ptr,int*num);

int main(void) {
	int input;
	User user[MAX_NUM];//���� ���� ����ü �迭 
	int person = 0;
	
	//�޴�����
	while(1){
		printf("**** Welcome to Contact Management System ****\n\n");
		printf("MAIN MENU\n");
		printf("=========================================================\n");
		printf("[1] Add a new Contact\n");
		printf("[2] List all Contacts\n");
		printf("[3] Search for contact\n");
		printf("[4] Edit a Contact\n");
		printf("[5] Delete a Contact\n");
		printf("[6] Eater Egg\n");
		printf("[0] Exit\n");
		printf("=========================================================\n");
		printf("Enter the choice: \n");
		scanf("%d", &input);
		
		if (input == 1){
			printf("\n[Add]\n");
			add(user,&person);
		}
		else if (input == 2){
			printf("\n[List]\n");
			list(user,&person);
		}
		else if (input == 3){
			printf("\n[Search]\n");
			search(user,&person);
		}
		else if (input == 4){
			printf("\n[Edit]\n");
			edit(user,&person);
		}
		else if (input == 5){
			printf("\n[Deleted]\n");
			deleted(user,&person);
		}
		else if (input == 6){
			printf("\n[Egg]\n");
			egg(user,&person);
		}
		else if (input == 0){
			printf("\n[Exit]\n");
			return 0;
		}
		else
			printf("\nerror! Please retry! \n\n");
		} 
	return 0;
}

//1�� ������  �߰� 
void add(User* ptr, int*num){
	if (*num < MAX_NUM){
          printf("Input Name: ");
          scanf("%s", ptr[*num].name);
          printf("Input Phone number: ");
          scanf("%s", ptr[*num].number);
          printf("Input Address: ");
          scanf("%s", ptr[*num].address);
          printf("Input Email: ");
          scanf("%s", ptr[*num].email);

          (*num)++;
          printf("=========================================================\n");
          printf("\tSuccessful Data Inserted \n\n");
     }
     
     else
          printf("\tData Full \n\n");
    }

//2�� ����Ʈ ���  
void list(User* ptr, int*num){
	int i = 0;
	 if (*num > 0){
          for (i = 0; i < *num; i++){
               printf("Name: %s", ptr[i].name);
               printf("\tPhone: %s", ptr[i].number);
               printf("\tAddress: %s", ptr[i].address);
               printf("\tEmail: %s\n", ptr[i].email);
          }
          printf("=========================================================\n");
          printf("\tSuccessful Data Print \n\n");
     }
     else{
     	printf("=========================================================\n");
        printf("\tNo Data \n\n");
    }
}

//3�� �˻����  
int search(User* ptr, int*num){
	char name[30];
	int i;
	
	//����� �����Ͱ� �ִٸ�
	if(*num>0){
		printf("Input Name: ");
		scanf("%s", name);
		for(i=0;i<MAX_NUM;i++){
			if(!strcmp(name,ptr[i].name)){
				printf("Name: %s", ptr[i].name);
				printf("\tPhone: %s", ptr[i].number);
				printf("\tAddress: %s", ptr[i].address);
				printf("\tEmail: %s\n", ptr[i].email);
				printf("=========================================================\n");
				printf("\tSuccessful Data Found\n\n");
				return 0;
			}
		}
		printf("=========================================================\n");
		printf("\tNot Found\n\n");
		return 0;
	} 
	//����� �����Ͱ� ���ٸ� 
	else{
		printf("=========================================================\n");
		printf("\tNo Data\n\n");
	}
}

//4�� ������ ����  
int edit(User* ptr, int*num){
	char name[30];
	int i;
	
	//����� �����Ͱ� �ִٸ�
	if(*num>0){
		printf("Input Name: ");
		scanf("%s", name);
		for(i=0;i<MAX_NUM;i++){
			if(!strcmp(name,ptr[i].name)){
				printf("=========================================================\n");
				printf("\tData found\n");
				printf("\tpleas edit start!\n");
				printf("=========================================================\n");
				printf("Input Name: ");
		        scanf("%s", ptr[i].name);
		        printf("Input Phone number: ");
		        scanf("%s", ptr[i].number);
		        printf("Input Address: ");
		        scanf("%s", ptr[i].address);
		        printf("Input Email: ");
		        scanf("%s", ptr[i].email);
		        printf("=========================================================\n");
				printf("\tData edit success!\n\n");
				return 0;
			}
		}
		printf("=========================================================\n");
		printf("\tNot Found\n\n");
		return 0;
	} 
	//����� �����Ͱ� ���ٸ� 
	else{
		printf("=========================================================\n");
		printf("\tNo Data\n\n");
	}
}
 
//5�� ������ ����  
int deleted(User* ptr, int*num){
	char name[30];
     int i, j;
     
     //���� ������ �Ѱ��� ����������
     if (*num > 0){
          printf("Input Name: ");
          scanf("%s", name);

          for (i = 0; i < MAX_NUM; i++){
               //���ڿ��̹Ƿ� ���ϱ����� strcmp���
               if (strcmp(name, ptr[i].name) == 0){
                    (*num)--;
                    printf("=========================================================\n");
                    printf("\tSuccessful Data Deleted \n\n");


                    //�����Ͱ� ���� ���� �ʾҴٸ�
                    if (i != MAX_NUM - 1){
                         for (j = i; j < MAX_NUM; j++){
                              //���ڿ��̹Ƿ� strcpy�� ����Ͽ� ������ ����
                              strcpy(ptr[j].name, ptr[j + 1].name);
                              strcpy(ptr[j].number, ptr[j + 1].number);
                              strcpy(ptr[j].address, ptr[j + 1].address);
                              strcpy(ptr[j].email, ptr[j + 1].email);
                         }

                     //����ü �迭�� �������� NULL�� �ٲ�
                     *ptr[MAX_NUM - 1].name = NULL;
                     *ptr[MAX_NUM - 1].number = NULL;
					 *ptr[MAX_NUM - 1].address = NULL;
                     *ptr[MAX_NUM - 1].email = NULL;
                }


                //�����Ͱ� ���� á�ٸ�
                else{
                     //����ü �迭�� �������� NULL�� �ٲ�
                     *ptr[MAX_NUM - 1].name = NULL;
                     *ptr[MAX_NUM - 1].number = NULL;
                     *ptr[MAX_NUM - 1].address = NULL;
                     *ptr[MAX_NUM - 1].email = NULL;
                }
                return 0;
               }
          }
          printf("=========================================================\n");
          printf("\tNot Found \n\n");
          return 0;
	}
	else{
		printf("=========================================================\n");
		printf("\tNo data \n\n");
	}
}
//�̽��Ϳ���  
void egg(User* ptr, int*num){
	if (*num < MAX_NUM){
		char name1[30]= "HAN YEON JAE";;
		char number1[30]= "01033797498";
		char address1[30]= "Wonju";
		char email1[30]="kevin7498@naver.com";
		char name2[30]= "HEO JEONG HWA";
		char number2[30]= "01033541083";
		char address2[30]= "Suncheon";
		char email2[30]="gjwjdghk123@gmail.com";
		strcpy(ptr[*num].name,name1);
		strcpy(ptr[*num].number,number1);
		strcpy(ptr[*num].address,address1);
		strcpy(ptr[*num].email,email1);
		++(*num);
		strcpy(ptr[*num].name,name2);
		strcpy(ptr[*num].number,number2);
		strcpy(ptr[*num].address,address2);
		strcpy(ptr[*num].email,email2);
        (*num)++;
        printf("=========================================================\n");
        printf("\tthis is egg!\n");
        printf("\tplease check list!\n\n");
        
     }
     
     else
          {
          	printf("=========================================================\n");
          	printf("\tSorry...full\n\n");
		  }
}

