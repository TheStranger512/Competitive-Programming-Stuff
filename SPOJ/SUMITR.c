#define max(a,b)a>b?a:b
int a[110][110];main(){int t,n,x,i,j;scanf("%d",&t);while(t--){x=0;scanf("%d",&n);for(i=1;i<=n;i++)for(j=1;j<=i;j++){scanf("%d",&a[j][i]);a[j][i]+=max(a[j][i-1],a[j-1][i-1]);x=max(x,a[j][i]);}printf("%d\n",x);}return 0;}
