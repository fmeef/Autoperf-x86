#include <autoperf.h>
#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(char ** argv, int argc) {
  MPI_Init(NULL,NULL);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  int worldrank;
  MPI_Comm_rank(MPI_COMM_WORLD, &worldrank);

  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);

  
  /*
  float ls[1000000];
  int x;
  for(x=0;x<1000000;x++) {
    ls[(int)rand()*999999]= rand()*50;
      }

  */
  
  MPI_Finalize();
  
}
