#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size,data;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        data = 42;
        printf("Process %d broadcasting number %d to all other processes.\n", rank, data);
    }
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received number %d\n", rank, data);
    MPI_Finalize();
    return 0;
}
