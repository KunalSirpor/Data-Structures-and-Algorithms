# include <stdio.h>

int main()
{
	int n,bt[100],at[100],ft[100],tat[100],wt[100],p[100],i,j,pos,tmp;
	float avg_tat,avg_wt,s_tat=0.0,s_wt=0.0;
	printf("SHORTEST JOB FIRST(with Arrival time=0)\n");
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("....Enter the brust time and arrival time of each process....");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the bt and at of process %d =",(i+1));
		scanf("%d\n %d",&bt[i],&at[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		pos=i;
                for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
				pos=j;
		}
		tmp=bt[i];
        	bt[i]=bt[pos];
        	bt[pos]=tmp;	
        	tmp=p[i];
        	p[i]=p[pos];
        	p[pos]=tmp;
    	}
	ft[0]=0;
	for(int i=1;i<n;i++)
	{
		ft[0]=bt[0];
		ft[i]=bt[i]+ft[i-1];
	}
	for(int i=0;i<n;i++)
	{
		tat[i]=ft[i]-at[i];
		wt[i]=tat[i]-bt[i];
		s_tat+=tat[i];
		s_wt+=wt[i];
	}
	float m;
	m=n;
	avg_tat=s_tat/m;
	avg_wt=s_wt/m;
	printf("Process	b_t	a_t	f_t	t_a_t	w_t\n");
	for(int i=0;i<n;i++)
	{
		printf("%d	%d	%d	%d	%d	%d\n",p[i],bt[i],at[i],ft[i],tat[i],wt[i]);
	}
	printf("\nAverage TAT is %f and Average WT is %f\n",avg_tat,avg_wt);
	return 0;
}