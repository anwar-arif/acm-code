int main()
{
    for(k = 1;k <= V;k++)
    {
       for(i = 1; i <= V;i++) V = number of nodes
       {
           for(j = 1; j <= V;j++)
           {
               if(dist[i][j] > dist[i][k] + dist[k][j])
               {
                   dist[i][j] = dist[i][k] + dist[k][j];
               }
           }
       }
    }
   return 0;
}
complexity = n^3 . n = number of nodes
