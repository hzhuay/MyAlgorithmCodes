#include<cstdio>
#include<cmath>
const double pi=3.141592654; 
int main(){
	//freopen("in3766.txt","r",stdin);
	double R,s0,s1,s2,s3,s4,s5,S,s,p1,p2,p3;
	int N,M,K,kase=1;
	while(scanf("%d %d %d",&N,&M,&K),N!=0){
		scanf("%lf",&R);
		s0=sqrt(3)/4*(1-2*R/sqrt(3))*(1-2*R/sqrt(3))*6;
		s1=5*sqrt(3)/4*(1-2*R/sqrt(3))*(1-2*R/sqrt(3))+sqrt(3)/4-pi*R*R/3;
		s2=6*sqrt(3)/4*(1-2*R/sqrt(3))*(1-2*R/sqrt(3));
		s3=R*R*((1+sqrt(3))/3-pi/12)-R*(5*sqrt(3)+2)/4+(3*sqrt(3)+5)/4;
		s4=(sqrt(3)-pi/6)*R*R-4*R+3*sqrt(3)/2;
		s5=3*sqrt(3)/4*(1-2*R/sqrt(3))*(1-2*R/sqrt(3))+3*sqrt(3)/4-pi*R*R/3-sqrt(3)/4*(2*R/sqrt(3))*(2*R/sqrt(3))-pi*R*R/6;
		if(M%2==0){
			S=6*sqrt(3)/4*(2*N-1)*M;
			s=s0*((2*N-1)*M/2-(2*N-5+2*M))+s1*2*(M/2-1)+s2*(2*N-5)+s3*2+s4*2+s5*(M/2-1);
		}
		else{
			S=6*(sqrt(3)/4)*0.5*(2*M*N-M+1);
			if(K==N){
				//S=6*(sqrt(3)/4)*0.5*(2*M*N-M+1);
				s=s0*((M-1)/2*(2*N-1)-K-2*(N-2))+s1*2*(M-1)/2+s2*(2*K-4)+s4*4+s5*2*(M-3)/2;
			}else{
				//S=6*(sqrt(3)/4)*0.5*(2*M*N-M-1);
				s=s0*((M-1)/2*(2*N-1)-K-2*(N-2))+s1*2*(M-3)/2+s2*(2*K-4)+s3*4+s5*2*(M-1)/2;
				//p1=100*(s1*2*(M-3)/2+s2*(2*K-4)+s3*4+s5*2*(M-1))/2/S;
			}
		}
		p1=100*s/S;
		p3=100*pi*R*R*(M-1)*(2*N-3)/S;
		p2=100-p1-p3; 
		printf("Case %d:\n",kase++);
		printf("Probability of covering 1 hexagon   = %.3f percent.\n",p1);
		printf("Probability of covering 2 hexagons   = %.3f percent.\n",p2);
		printf("Probability of covering 3 hexagons   = %.3f percent.\n\n",p3);
	}
	return 0;
 } 
