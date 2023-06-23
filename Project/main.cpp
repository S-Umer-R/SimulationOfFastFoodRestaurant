#include <iostream>
#include <stdlib.h> 
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <time.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;
int max_customers=100,quan1=0,quan2=0,quan3=0,daily_sales=0,daily_waiter_sales=0;
sem_t entry,order_p,order_r,cook[3],waiter[5],bill;

void kitchen(int id,int random_cook);
void server(int id,int random_waiter);

void* manager(void *num)
{
	int id=*(int*)num;
	int price=0,quan=0,check=0,random_value=0,req;
	
	sem_wait(&entry);
	
	if(max_customers<=0)

    	{

        	cout<<"\nCustomer id: "<<id<<"STATUS: Leaving due to no space left\n";

        	sleep(3);

        	pthread_exit(NULL);

    	}
	
	cout<<"\nCustomer id: "<<id<<" Enter the restaurant";
	
	for(int i=0;req!=4;i++){
	cout<<"\nSelect from the menu: \n1. Burger\n2. French Fries\n3. Ice Cream\n";
	jump:
	if(i>0)
		cout<<"4. Exit\n";
	cin>>req;
	if(i==0 && req==4)
	{
		cout<<"Select the right option!";
		goto jump;
	}
	switch(req){
		case 1:
			cout<<"\nEnter Quantity: ";
			cin>>quan;
			quan1=quan1+quan;
			
			for(int q1=0;q1<quan;q1++)
				price=price+300;
			
			break;
		
		case 2:
			cout<<"\nEnter Quantity: ";
			cin>>quan;
			quan2=quan2+quan;
			for(int q2=0;q2<quan;q2++)
				price=price+100;
			break;
		
		case 3:
			cout<<"\nEnter Quantity: ";
			cin>>quan;
			quan3=quan3+quan;
			for(int q3=0;q3<quan;q3++)
				price=price+50;
			break;
		
		case 4:
			cout<<"Your total amount is: "<<price;
			daily_sales=daily_sales+price;
			break;
		
		default:
			cout<<"\nSelect the right option!";
			goto jump;
			break;
	}
	}
	--max_customers;
	
	sleep(2);
	
	sem_post(&entry);
	
	sem_wait(&order_p);
	
	
	srand(time(NULL));

        random_value=rand()%3;

	kitchen(id,random_value);
	
	sleep(2);
	
	sem_post(&order_p);
	sem_wait(&order_r);
	
	srand(time(NULL));

    random_value=rand()%5;

	server(id,random_value);
	
	sleep(2);
	
	sem_post(&order_r);
	sem_wait(&bill);
	
	cout<<"\nCustomer id: "<<id<<" paid: "<<price<<endl;
	daily_waiter_sales=daily_waiter_sales+price;
	sleep(1);
	
	sem_post(&bill);
	
	cout<<"\nCustomer id: "<<id<<" left the restaurant\n";
	
	return NULL;
	
}

void kitchen(int id,int random_cook)
{
	int ttime=0;
	sem_wait(&cook[random_cook]);
	
	ttime=quan1+quan2+quan3;
	quan1=0;
	quan2=0;
	quan3=0;
	sleep(ttime);
	sem_post(&cook[random_cook]);
	cout<<"\nDish of customer "<<id<<" is handed over to the server\n";
}

void server(int id,int random_waiter)
{
	sem_wait(&waiter[random_waiter]);
	
	sleep(2);
	
	sem_post(&waiter[random_waiter]);
	
	cout<<"\nThe dish is served to customer "<<id<<endl;
}

int main()
{
	int no_cust,i;
	cout<<"**********************************************************************************************************";
	cout<<"\n\t\t\t\t   Welcome to NUCES FAST FOOD\n";
	cout<<"**********************************************************************************************************\n";
	
	cout<<"Enter the total number of customers: ";
	cin>>no_cust;
	
	int idd[no_cust];
	pthread_t customer[no_cust];
	
	for(i=0;i<no_cust;i++)
	{
		idd[i]=i+1;
	}
	
	sem_init(&entry,0,1);
	sem_init(&order_p,0,1);
	sem_init(&order_r,0,1);
	
	sem_init(&cook[0],0,1);
	sem_init(&cook[1],0,1);
	sem_init(&cook[2],0,1);
	
	sem_init(&waiter[0],0,1);
	sem_init(&waiter[1],0,1);
	sem_init(&waiter[2],0,1);
	sem_init(&waiter[3],0,1);
	sem_init(&waiter[4],0,1);
	
	sem_init(&bill,0,1);
	
	for(i=0;i<no_cust;i++)
	{
		pthread_create(&customer[i],NULL,&manager,(void*) &idd[i]);
	}
	
	for(i=0;i<no_cust;i++)
	{
		pthread_join(customer[i],NULL);
	}
	
	cout<<"\nDaily sales: "<<daily_sales<<" and Daily waiter sales: "<<daily_waiter_sales<<endl;
	pthread_exit(NULL);
}
