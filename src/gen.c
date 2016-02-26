#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
int kol;
int k=1;
char A[]={'0','1','2','3','4','5','6','7','8','9'};
char B[]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
char C[]={'!','@','#','$','%','^','&','*','(',')'};
char D[]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
int i;
int a;
srand(time(NULL));
printf ("введите количество символов: ");
scanf ("%d",&kol);

for (k;k<=kol;k++)
{
	i=random() % 4 +1;
	if (i==1) {
		a=random() % 9 +0;
		printf ("%c",A[a]);
	}
        else if (i==2) {
                a=random() % 25 +0;
                printf ("%c",B[a]);
        }
        else if (i==3) {
                a=random() % 9 +0;
                printf ("%c",C[a]);
        }
        else if (i==4) {
                a=random() % 25 +0;
                printf ("%c",D[a]);
        }
}
printf ("\n");
return 0;
}
