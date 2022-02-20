#include<cstdio>
#include<cstring>
#define maxl 105
char name[maxl][12],sid[maxl][12],subject[5][20]={"Chinese","Mathematics","English","Programming"};
int cid[maxl],score[maxl][5],fail[maxl],pass[maxl],p[5],ps[5],sum[5],n=0;
void print_menu(){
	printf("Welcome to Student Performance Management System (SPMS).\n\n");
	puts("1 - Add");
	puts("2 - Remove");
	puts("3 - Query");
	puts("4 - Show ranking");
	puts("5 - Show Statistics");
	puts("0 - Exit");
	puts("");
}
int rank(int x){
	int r=1;
	for(int i=0;i<n;i++){
		if(score[i][4]>score[x][4])r++;
	}
	return r;
}
void add(){
	for(;;){
		puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
		scanf("%s",sid[n]);
		if(strcmp(sid[n],"0")==0)return;
		scanf("%d%s%d%d%d%d",&cid[n],name[n],&score[n][0],&score[n][1],&score[n][2],&score[n][3]);
		bool mark=false;
		for(int j=0;j<n;j++)
			if(strcmp(sid[n],sid[j])==0){mark=true;break;}
		if(mark)puts("Duplicated SID.");
		else{
			score[n][4]=score[n][0]+score[n][1]+score[n][2]+score[n][3];
			n++;
		}
	}
}
void DQ(bool flag){//true查询，false删除
	char s[maxl];
	for(;;){
		puts("Please enter SID or name. Enter 0 to finish."); 
		scanf("%s",s);
		if(strcmp(s,"0")==0)break;
		int r=0;
		for(int i=0;i<n;i++){
			if(strcmp(sid[i],s)==0||strcmp(name[i],s)==0){
				if(flag)printf("%d %s %d %s %d %d %d %d %d %.2f\n",rank(i),sid[i],cid[i],name[i],score[i][0],score[i][1],score[i][2],score[i][3],score[i][4],score[i][4]/4.0);	
				else{
					for(int j=i;cid[j];j++){
						strcpy(sid[j],sid[j+1]);
						cid[j]=cid[j+1];
						strcpy(name[j],name[j+1]);
						for(int k=0;k<=4;k++)score[j][k]=score[j+1][k];
					}
					r++;
				}
			}
		}
		if(!flag){
			printf("%d student(s) removed.\n",r);
			n-=r;
		}
	}
}
void stat(){
	puts("Please enter class ID, 0 for the whole statistics.");
	int c;
	scanf("%d",&c);
	if(c){
		int num=0;
		for(int i=0;i<n;i++){
			if(c==cid[i]){
				num++;
				for(int j=0;j<4;j++){
					sum[j]+=score[i][j];
					if(score[i][j]>=60){
						ps[j]++;
						pass[i]++;
					}
				}
			p[pass[i]]++;
			}	
		}
		for(int i=0;i<4;i++){
			printf("%s\n",subject[i]);
			printf("Average Score: %.2f\n",sum[i]*1.0/num);
			printf("Number of passed studnets: %d\n",ps[i]);
			printf("Number of failed studnets: %d\n\n",num-ps[i]);
		}
		printf("Overall:\n");
		printf("Number of students who passed all subjects: %d\n",p[4]);
		printf("Number of students who passed 3 or more subjects: %d\n",p[3]+p[4]);
		printf("Number of students who passed 2 or more subjects: %d\n",p[2]+p[3]+p[4]);
		printf("Number of students who passed 1 or more subjects: %d\n",p[1]+p[2]+p[3]+p[4]);
		printf("Number of students who failed all subjects: %d\n",p[0]);
		memset(p,0,sizeof(p));
		memset(ps,0,sizeof(ps));
		memset(pass,0,sizeof(pass));
		memset(sum,0,sizeof(sum));
	}else{//p有几人过了n门，pass第i个人过了几门 
		for(int i=0;i<n;i++){
			for(int j=0;j<4;j++){
				if(score[i][j]>=60){
					pass[i]++;
					ps[j]++;
				}
				sum[j]+=score[i][j];
			}
			p[pass[i]]++;
		}
		for(int i=0;i<4;i++){
			printf("%s\n",subject[i]);
			printf("Average Score: %.2f\n",sum[i]*1.0/n);
			printf("Number of passed studnets: %d\n",ps[i]);
			printf("Number of failed studnets: %d\n\n",n-ps[i]);
		}
		printf("Overall:\n");
		printf("Number of students who passed all subjects: %d\n",p[4]);
		printf("Number of students who passed 3 or more subjects: %d\n",p[3]+p[4]);
		printf("Number of students who passed 2 or more subjects: %d\n",p[2]+p[3]+p[4]);
		printf("Number of students who passed 1 or more subjects: %d\n",p[1]+p[2]+p[3]+p[4]);
		printf("Number of students who failed all subjects: %d\n",p[0]);
		//printf("Number of student: %d\n\n",n);
		memset(p,0,sizeof(p));
		memset(ps,0,sizeof(ps));
		memset(pass,0,sizeof(pass));
		memset(sum,0,sizeof(sum));
		return;
	}
}
void all(){
	for(int i=0;i<n;i++){
		printf("%d %s %d %s %d %d %d %d %d %.2f\n",rank(i),sid[i],cid[i],name[i],score[i][0],score[i][1],score[i][2],score[i][3],score[i][4],score[i][4]/4.0);	
	}
	printf("%d\n",n);
}
int main(){
	freopen("shixiong.txt","r",stdin);
	for(;;){
		int choice;
		print_menu();
		scanf("%d",&choice);
		if(choice==0)break;
		if(choice==1)add();
		if(choice==2)DQ(0);
		if(choice==3)DQ(1);
		if(choice==4)puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
		if(choice==5)stat();
		if(choice==6)all();
	}
	return 0;
}
