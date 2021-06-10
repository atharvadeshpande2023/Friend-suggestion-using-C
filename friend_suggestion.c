#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int represent(int n,char name[],int adj[n][n])
{
    int i,j;
    for(i=0;i<n;i++)//adjacency matrix representation
    {
        printf("\t%c",name[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%c\t",name[i]);
        for(j=0;j<n;j++)
            {
                printf("%d\t",adj[i][j]);
            }
        printf("\n");
    }
}
void friend(int n,char name[],int adj[n][n])
{

    int i,j,k,no;
    char temp[n];
    for(i=0;i<n;i++)
        temp[i]='\0';
    for(i=0;i<n;i++)//entry of friends
    {
        printf("\nEnter the number of friends of %c:",name[i]);
        scanf("%d",&no);
        printf("\nEnter %d friends of %c\n",no,name[i]);
        for(j=0;j<no;j++)
        {
            scanf("%s",&temp[j]);

        }
        for(k=0;k<no;k++)
        {
            for(j=0;j<strlen(name);j++)
            {
                if(temp[k]==name[j])
                {
                        adj[i][j]=1;
                        adj[j][i]=1;
                }
            }
        }
        for(j=0;j<n;j++)
            temp[j]='\0';
        //friendlist(n,i,no,temp,name);
    }
    printf("\n");

}
void move(int i,int n,int j,char name[],int adj[n][n],char ch)
{
    int k;
    printf("\n Friends suggested with reference to %c are::",name[j]);
    for(k=0;k<n;k++)
    {
        if(adj[j][k]==1 && name[k]!=ch && adj[i][k]!=1)
        {
             printf("\t%c",name[k]);
        }
    }
}
int new_friend(int t,int n,char name[n],int adj[n][n])
{
    int i,j,k,no;
    char temp[n];
    for(i=0;i<n;i++)
        temp[i]='\0';
    printf("\nEnter the number of friends of %c:",name[t]);
    scanf("%d",&no);
    printf("\nEnter %d friends of %c\n",no,name[t]);
    for(j=0;j<no;j++)
    {
        scanf("%s",&temp[j]);
    }
    for(k=0;k<no;k++)
    {
        for(j=0;j<strlen(name);j++)
        {
            if(temp[k]==name[j])
            {
                adj[t][j]=1;
                adj[j][t]=1;
            }
        }
    }
}
int main()
{
    int n,i,j,k,no,t;
    printf("\nEnter no profiles:");
    scanf("%d",&n);
    int adj[n][n];
    //char temp[n];
    char ch;
    char name[n];
        for(i=0;i<n;i++)
    {
        //temp[i]='\0';
        for(j=0;j<n;j++)
            {
                adj[i][j]=0;
            }
    }
    for(i=0;i<n;i++)//entry of profiles
    {
        printf("\nEnter %d profile name: ",i+1);
        scanf("%s",&name[i]);
    }
    friend(n,name,adj);
    represent(n,name,adj);

    printf("\nEnter name for whom u want to suggest friend\n");
    scanf("%s",&ch);
    //printf("\n%c",ch);
    for(i=0;i<n;i++)
    {
            if(name[i]==ch)
            {
                t=i;
                break;
            }
    }
    for(j=0;j<n;j++)
    {
        if(adj[i][j]==1)
        {
            move(i,n,j,name,adj,ch);
        }
    }
    while(1)
    {   printf("\nAre their any acceptance of friendship from the list of suggestion\nIf yes->1\nIf no->2\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                new_friend(t,n,name,adj);
                represent(n,name,adj);
                printf("\nDo you want suggest friend?\n1:Yes\n2:No\n");
                scanf("%d",&i);
                if(i==1)
                {

                    printf("\nEnter name for whom u want to suggest friend\n");
                    scanf("%s",&ch);
                    //printf("\n%c",ch);
                    for(i=0;i<n;i++)
                    {
                            if(name[i]==ch)
                            {
                                break;
                            }
                    }
                    for(j=0;j<n;j++)
                    {
                        if(adj[i][j]==1)
                        {
                            move(i,n,j,name,adj,ch);
                        }
                    }
                }
                else
                    return 0;
            break;
            case 2:
                return 0;
            break;
        }
    }
}
