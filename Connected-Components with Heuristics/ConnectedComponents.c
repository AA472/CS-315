#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
  node* p;
  int rank;
};
//node is a vertex

void make_set(node* x){
  x->p = x;
  x->rank = 0;
}
node* find_set(node* x){
  if( x!= x->p)
    x->p = find_set(x->p);
   return x->p;
}
void link(node* v, node* w){
  if (v->rank > w->rank){
    w->p = v;
  }
  else{
    v->p = w;
    if(v->rank == w->rank)
      w->rank = w->rank +1;
  }
}

void union_sets(node* v, node* w){
  link(find_set(v),find_set(w));
}

int main(int argc, char *argv[])
{

  if (argc != 2)
    {
      printf("Error: check arguments");
      exit(1);
    }

  FILE *file;
  file = fopen(argv[1] ,"r");
  

  int i,j,k;  // looping index
  int graphs;
  fscanf(file,"%d",&graphs); // take in number of graphs

  for(k=0; k<graphs;k++){
    int n, e;    // number of vertices and edges
    int v, w; // pairs of vertices that define the edges
    node* forest; //make array of vertices

    fscanf(file,"%d %d",&n,&e); // take in lengths
    
    forest = (node*) malloc(n*sizeof(node)); //allocate memory
    
    for(i=1;i<n+1;i++){ //take in all vertices
      make_set(&(forest[i-1]));
    }
    for(i=0; i<e; i++){
      fscanf(file,"%d %d",&v,&w); // take in pair
      union_sets(&(forest[v-1]),&(forest[w-1]));
    }
    int test;

    // output:

    printf("[ ");
    for(int h=0;h<n;h++){
      test = 1;
	if(forest[h].p == &forest[h]){
		printf("[");
		for(int f=0;f < n;f++){
			if(find_set(&forest[f]) == &forest[h]){
			  if(test==1){
				printf("%d",f+1);
				test =0;
			  }
			  else
			    printf(" %d",f+1);
			}		
		} 
		printf("] ");
	}
}
      printf("]\n");
      free(forest);
    }
    fclose(file);
    return 0;
  }


 /*printf("[ ");
    for(i=0;i<n;i++){
      if (rank==0)
	printf("[%d]",i+1);
      else if(&(forest[i]) == (forest[i]).p){
	rank = (forest[i]).rank;
	  test = 0;
	  printf("[");
	  for(j=0;j<n;j++){
	    if (rank ==-1)
	      break;
	    if((forest[j]).p== &(forest[i])){
	      if(test==0){
		printf("%d",(j+1));
		test =1;
	      }
	      else
		printf(" %d",(j+1));
	      rank--;
	      printf("] ");
	    }
	  }
	  
	}
      }
      printf("]\n");*/
