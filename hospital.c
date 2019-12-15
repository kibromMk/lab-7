#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct drug_store{
	int idcard;
} drug_s;

typedef struct finance{
	int idcard;
} finance;

typedef struct laboratory{
	int idcard;
} laboratory;

typedef struct patient_treatment{
	int idcard;
} patient_t;

typedef struct id_card {
    int idcard;
} id_card;

typedef struct hospital {
    id_card *idcard_p;
    patient_t *patient;
    laboratory *lab;
    finance *fin;
    drug_s *drug;
    struct hospital *next;
} hospital;


//id card of patients queue
hospital *idcard_r;
hospital *idcard_f;
hospital *idcard_tmp;

//patient treatment queue
hospital *patient_r;
hospital *patient_f;
hospital *patient_tmp;

//laboratory queue
hospital *lab_r;
hospital *lab_f;
hospital *lab_tmp;

//finance queue
hospital *fin_r;
hospital *fin_f;
hospital *fin_tmp;

//drug store queue
hospital *drug_r;
hospital *drug_f;
hospital *drug_tmp;

//temp data
hospital *cur;


//prototype
void add_patient();
void list_of_patients();
void patient_treatment_p();
void laboratory_p();
void finance_p();
void drug_store();
void search();
void s_idcard(int id_num);
void s_patientT(int id_num);
void s_lab(int id_num);
void s_finance(int id_num);
void s_drug(int id_num);

int id=10;
int main()
{
	int ch;
	do{
		printf("\n|-----------------------------------------------------------------------------------------------------------------|\n");
		printf("\nEnter 1 to add patient\nEnter 2 for list of patients\n"
		"Enter 3 for patient treatment\nEnter 4 for laboratory\n"
		"Enter 5 for finance\nEnter 6 for drug store\n"
		"Enter 7 for search id number in the queues\n"
		"Enter 8 for exit\n");
		printf("|--------------------------------------------------------------------------------------------------------------------|\n");

	    scanf("%d",&ch);
		switch(ch){
			case 1:
				add_patient();
				break;
			case 2:
				list_of_patients();
				break;
			case 3:
				patient_treatment_p();
				break;
			case 4:
			    laboratory_p();
				break;
			case 5:
				finance_p();
				break;
			case 6:
				drug_store();
				break;
			case 7:
				search();
				break;
//				s_idcard(id_num);
//				break;
//			case 8:
//				s_patientT(id_num);
//				break;
//			case 9:
//				s_lab(id_num);
//				break;
//			case 10:
//			    s_finance(id_num);
//				break;
//			case 11:
//				s_drug(id_num);
//				break;
			case 8:
				exit(1);
				break;
			default:
				printf("wrong choice\n");
				break;
		};
		
	}while(ch!=8);
}


//add room
void add_patient(){
	idcard_tmp = (hospital *)malloc(sizeof(hospital));
    idcard_tmp->idcard_p = (id_card *)malloc(sizeof(id_card));
    printf("\n a patient with id card number %d is registered.\n",id);
//    scanf("%d",&idcard_tmp->idcard_p->idcard);
    idcard_tmp->idcard_p->idcard=id;
    id++;
    idcard_tmp->next = NULL;
    if(idcard_r==NULL){
    	idcard_r = idcard_tmp;
	}
	else{
		cur=idcard_r;
		while(cur->next!=NULL){
			cur = cur->next;
		}
		cur->next=idcard_tmp;
	}
}


//display available room
void list_of_patients(){
	cur=idcard_r;
	if(cur==NULL){
		printf("there are no patients.");
	}
	else{
		printf("these are the patients.\n");
		while(cur!=NULL){
			printf("%d->",cur->idcard_p->idcard);
			cur = cur->next;
		}
	}
	
}

//register Guest
 void patient_treatment_p(){
    patient_tmp = (hospital *)malloc(sizeof(hospital));
    patient_tmp->patient = (patient_t *)malloc(sizeof(patient_t));
 	
//   insert the patient from the id card queue into patient treatment queue and remove it from id card queue.
 	idcard_f = idcard_r;
	if(idcard_r == NULL) {
		printf("There is no patient in id card room.\n");
		return;
	}
	if(idcard_tmp == idcard_r) {
		patient_tmp->patient->idcard=idcard_r->idcard_p->idcard;
		idcard_tmp= idcard_r = NULL;
	}
	else {
		patient_tmp->patient->idcard=idcard_r->idcard_p->idcard;
		idcard_r = idcard_r->next;
	}
	free(idcard_f);
 	patient_tmp->next=NULL;
// 	end
 	if(patient_r==NULL){
 		patient_r=patient_tmp;
	}
	else{
	 	cur = patient_r;
	 	while(cur->next!=NULL){
	 		cur = cur->next;
		}
		cur->next=patient_tmp;
	 }
	 printf("A patient with id card number %d is arrived into patient treatment.\n",patient_tmp->patient->idcard);
 }
 
// display guests
 void laboratory_p(){
 	lab_tmp = (hospital *)malloc(sizeof(hospital));
    lab_tmp->lab = (laboratory *)malloc(sizeof(laboratory));
 	
//   insert the patient from the patient_t queue into lab queue and remove it from patient_t queue.
 	patient_f = patient_r;
	if(patient_r == NULL) {
		printf("There is no patients in patient treatment room.\n");
		return;
	}
	if(patient_tmp == patient_r) {
		lab_tmp->lab->idcard=patient_r->patient->idcard;
		patient_tmp= patient_r = NULL;
	}
	else {
		lab_tmp->lab->idcard=patient_r->patient->idcard;
		patient_r = patient_r->next;
	}
	free(patient_f);
 	lab_tmp->next=NULL;
// 	end
 	if(lab_r==NULL){
 		lab_r=lab_tmp;
	}
	else{
	 	cur = lab_r;
	 	while(cur->next!=NULL){
	 		cur = cur->next;
		}
		cur->next=lab_tmp;
	 }
	 printf("A patient with id card number %d is arrived into laboratory after patient treatment.\n",lab_tmp->lab->idcard);
 }
 
// delete the guest from the guests queue.
void finance_p(){
	fin_tmp = (hospital *)malloc(sizeof(hospital));
    fin_tmp->fin= (finance *)malloc(sizeof(finance));
 	
//   insert the patient from the patient_t queue into lab queue and remove it from patient_t queue.
 	lab_f = lab_r;
	if(lab_r == NULL) {
		printf("There is no patints in laboratory.\n");
		return;
	}
	if(lab_tmp == lab_r) {
		fin_tmp->fin->idcard=lab_r->lab->idcard;
		lab_tmp= lab_r = NULL;
	}
	else {
		fin_tmp->fin->idcard=lab_r->lab->idcard;
		lab_r = lab_r->next;
	}
	free(lab_f);
 	fin_tmp->next=NULL;
// 	end
 	if(fin_r==NULL){
 		fin_r=fin_tmp;
	}
	else{
	 	cur = fin_r;
	 	while(cur->next!=NULL){
	 		cur = cur->next;
		}
		cur->next=fin_tmp;
	 }
	 printf("A patient with id card number %d is arrived into finance room after laboratory.\n",fin_tmp->fin->idcard);

}

//remove room from the room queue
void drug_store(){
	drug_tmp = (hospital *)malloc(sizeof(hospital));
    drug_tmp->drug = (drug_s *)malloc(sizeof(drug_s));
 	
//   insert the patient from the patient_t queue into lab queue and remove it from patient_t queue.
 	fin_f = fin_r;
	if(fin_r == NULL) {
		printf("There is no available room.please find another room.\n");
		return;
	}
	if(fin_tmp == fin_r) {
		drug_tmp->drug->idcard=fin_r->fin->idcard;
		fin_tmp= fin_r = NULL;
	}
	else {
		drug_tmp->drug->idcard=fin_r->fin->idcard;
		fin_r = fin_r->next;
	}
	free(fin_f);
 	drug_tmp->next=NULL;
// 	end
 	if(drug_r==NULL){
 		drug_r=drug_tmp;
	}
	else{
	 	cur = drug_r;
	 	while(cur->next!=NULL){
	 		cur = cur->next;
		}
		cur->next=drug_tmp;
	 }
	 printf("A patient with id card number %d is arrived into drug store room after finance.\n",drug_tmp->drug->idcard);

}

// search in id card queue.
void search(){
	
	int id_num,k=0,i=0,x,ch;
	idcard_f = idcard_r;
	printf("Enter id number to be searched for the queues:");
	scanf("%d",&id_num);
	do{
		printf("\n|-----------------------------------------------------------------------------------------------------------------|\n");
		printf("\nEnter 1 to search in id card queue\nEnter 2 to search in patient treatment queue. \n"
		"Enter 3 to search in laboratory queue\nEnter 4 to search in finance queue.\n"
		"Enter 5 to search in drug store queue.\nEnter 6 for return back.\n");
		printf("|--------------------------------------------------------------------------------------------------------------------|\n");
	
	    scanf("%d",&ch);
		switch(ch){
			case 1:
				s_idcard(id_num);
				break;
			case 2:
				s_patientT(id_num);
				break;
			case 3:
				s_lab(id_num);
				break;
			case 4:
			    s_finance(id_num);
				break;
			case 5:
				s_drug(id_num);
				break;
			case 6:
				return ;
				break;
			default:
				printf("wrong choice\n");
				break;
		} ;
		
	}while(ch!=6);
	
	
}

void s_idcard(int id_num){
	int k=0,i=0;
	idcard_f = idcard_r;
	do{
		if(idcard_f->idcard_p->idcard==id_num){
			i=1;
			printf("A patient with id number %d exist in id card queue in position %d.\n",id_num,k+1);
			break;
		}
		else{
			idcard_f=idcard_f->next;
		}
		k++;	
	}while(idcard_f!=NULL);
	
	
	if(idcard_f==NULL&&i==0){
		printf("the patient with id number %d doesn't exist in id card queue.",id_num);
	}
}
void s_patientT(int id_num){
	int k=0,i=0;
	patient_f = patient_r;
	do{
		if(patient_f->patient->idcard==id_num){
			i=1;
			printf("A patient with id number %d exist in patient treatment queue in position %d.\n",id_num,k+1);
			break;
		}
		else{
			patient_f=patient_f->next;
		}
		k++;	
	}while(patient_f!=NULL);
	if(patient_f==NULL&&i==0){
		printf("the patient with id number %d doesn't exist in patient treatment queue.",id_num);
	}

}

void s_lab(int id_num){
	int k=0,i=0;
	lab_f = lab_r;
	do{
		if(lab_f->lab->idcard==id_num){
			i=1;
			printf("A patient with id number %d exist in laboratory queue in position %d.\n",id_num,k+1);
			break;	
		}
		else{
			lab_f=lab_f->next;
		}
		k++;	
	}while(lab_f!=NULL);
	if(lab_f==NULL&&i==0){
		printf("the patient with id number %d doesn't exist in laboratory queue.",id_num);
	}
}

void s_finance(int id_num){
	int k=0,i=0;
	fin_f = fin_r;
	do{
		if(fin_f->fin->idcard==id_num){
			i=1;
			printf("A patient with id number %d exist in finance queue in position %d.\n",id_num,k+1);
			break;
			
		}
		else{
			fin_f=fin_f->next;
		}
		k++;	
	}while(fin_f!=NULL);
	if(fin_f==NULL&&i==0){
		printf("the patient with id number %d doesn't exist in finance queue.",id_num);
	}
}

void s_drug(int id_num){
	int k=0,i=0;
	drug_f = drug_r;
	do{
		if(drug_f->drug->idcard==id_num){
			i=1;
			printf("A patient with id number %d exist in drug store queue in position %d.\n",id_num,k+1);
			break;
		}
		else{
			drug_f=drug_f->next;
		}
		k++;	
	}while(drug_f!=NULL);
	if(drug_f==NULL&&i==0){
		printf("the id number %d doesn't exit in drug store queues.\n",id_num);
	}
}
