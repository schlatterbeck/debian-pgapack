/*
 *  
 *  ********************************************************************* 
 *  (C) COPYRIGHT 1995 UNIVERSITY OF CHICAGO 
 *  *********************************************************************
 *  
 *  This software was authored by
 *  
 *  D. Levine
 *  Mathematics and Computer Science Division Argonne National Laboratory
 *  Argonne IL 60439
 *  levine@mcs.anl.gov
 *  (708) 252-6735
 *  (708) 252-5986 (FAX)
 *  
 *  with programming assistance of participants in Argonne National 
 *  Laboratory's SERS program.
 *  
 *  This program contains material protectable under copyright laws of the 
 *  United States.  Permission is hereby granted to use it, reproduce it, 
 *  to translate it into another language, and to redistribute it to 
 *  others at no charge except a fee for transferring a copy, provided 
 *  that you conspicuously and appropriately publish on each copy the 
 *  University of Chicago's copyright notice, and the disclaimer of 
 *  warranty and Government license included below.  Further, permission 
 *  is hereby granted, subject to the same provisions, to modify a copy or 
 *  copies or any portion of it, and to distribute to others at no charge 
 *  materials containing or derived from the material.
 *  
 *  The developers of the software ask that you acknowledge its use in any 
 *  document referencing work based on the  program, such as published 
 *  research.  Also, they ask that you supply to Argonne National 
 *  Laboratory a copy of any published research referencing work based on 
 *  the software.
 *  
 *  Any entity desiring permission for further use must contact:
 *  
 *  J. Gleeson
 *  Industrial Technology Development Center Argonne National Laboratory
 *  Argonne IL 60439
 *  gleesonj@smtplink.eid.anl.gov
 *  (708) 252-6055
 *  
 *  ******************************************************************** 
 *  DISCLAIMER
 *  
 *  THIS PROGRAM WAS PREPARED AS AN ACCOUNT OF WORK SPONSORED BY AN AGENCY 
 *  OF THE UNITED STATES GOVERNMENT.  NEITHER THE UNIVERSITY OF CHICAGO, 
 *  THE UNITED STATES GOVERNMENT NOR ANY OF THEIR EMPLOYEES MAKE ANY 
 *  WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY LEGAL LIABILITY OR 
 *  RESPONSIBILITY FOR THE ACCURACY, COMPLETENESS, OR USEFULNESS OF ANY 
 *  INFORMATION OR PROCESS DISCLOSED, OR REPRESENTS THAT ITS USE WOULD NOT 
 *  INFRINGE PRIVATELY OWNED RIGHTS.
 *  
 *  ********************************************************************** 
 *  GOVERNMENT LICENSE
 *  
 *  The Government is granted for itself and others acting on its behalf a 
 *  paid-up, non-exclusive, irrevocable worldwide license in this computer 
 *  software to reproduce, prepare derivative works, and perform publicly 
 *  and display publicly.
 */

/******************************************************************************
*     FILE: mpi_stub.c:  MPI stubs needed for PGAPack operation without
*                        linking with a real MPI.
*
*     Authors: Brian P. Walenz
******************************************************************************/

#include "pgapack.h"


#if defined(FORTRANCAP)
#define mpi_address_      MPI_ADDRESS
#define mpi_bcast_        MPI_BCAST
#define mpi_comm_dup_     MPI_COMM_DUP
#define mpi_comm_free_    MPI_COMM_FREE
#define mpi_comm_rank_    MPI_COMM_RANK
#define mpi_comm_size_    MPI_COMM_SIZE
#define mpi_finalize_     MPI_FINALIZE
#define mpi_init_         MPI_INIT
#define mpi_initialized_  MPI_INITIALIZED
#define mpi_probe_        MPI_PROBE
#define mpi_send_         MPI_SEND
#define mpi_recv_         MPI_RECV
#define mpi_sendrecv_     MPI_SENDRECV
#define mpi_type_commit_  MPI_TYPE_COMMIT
#define mpi_type_free_    MPI_TYPE_FREE
#define mpi_type_struct_  MPI_TYPE_STRUCT
#elif !defined(FORTRANUNDERSCORE)
#define mpi_address_      mpi_address
#define mpi_bcast_        mpi_bcast
#define mpi_comm_dup_     mpi_comm_dup
#define mpi_comm_free_    mpi_comm_free
#define mpi_comm_rank_    mpi_comm_rank
#define mpi_comm_size_    mpi_comm_size
#define mpi_finalize_     mpi_finalize
#define mpi_init_         mpi_init
#define mpi_initialized_  mpi_initialized
#define mpi_probe_        mpi_probe
#define mpi_send_         mpi_send
#define mpi_recv_         mpi_recv
#define mpi_sendrecv_     mpi_sendrecv
#define mpi_type_commit_  mpi_type_commit
#define mpi_type_free_    mpi_type_free
#define mpi_type_struct_  mpi_type_struct
#endif



/*  Places the address of "location" into "address"
 *  In FORTRAN, does not return anything.
 */
int MPI_Address(void *location, MPI_Aint *address) {
    *address = (MPI_Aint)NULL;
    return(0);
}


/*  Broadcast "buf" to all processes.
 *  FORTRAN adds integer ierror to the end of the parameters.
 */
int MPI_Bcast(void *buf, int count, MPI_Datatype datatype, int root, MPI_Comm comm) {
    return(0);
}


/*  Duplicates communicator "comm" into "newcomm"
 *  FORTRAN has a third parameter, integer ie, and does not return anything.
 */
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) {
    return(0);
}


/*  Frees a communicator.   */
int MPI_Comm_free(MPI_Comm *comm) {
    return(0);
}


/*  Returns the rank of the current process in rank.  We return
 *  0 -- we are the master.
 */
int MPI_Comm_rank(MPI_Comm comm, int *rank) {
    *rank = 0;
    return(0);
}


/*  Returns the number of processors that are in communicator comm
 *  in size.  Always 1.
 */
int MPI_Comm_size(MPI_Comm comm, int *size) {
    *size = 1;
    return(0);
}

/*  Finalizes MPI.  */
int MPI_Finalize(void) {
    return(0);
}


/*  Initializes MPI.
 *  Ideally, we should parse the command-line and remove MPI arguments.
 */
int MPI_Init(int *argc, char ***argv) {
    return(0);
}


/*  Returns 1 in flag if MPI is already running.  It is.  */
int MPI_Initialized(int *flag) {
    *flag = 1;
    return(0);
}


/*  Waits for messages to us with tag "tag".  Sets status->MPI_SOURCE to the
 *  source of the message, status->MPI_TAG to the tag, and status->MPI_ERROR
 *  to 0.
 */
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) {
    status->MPI_SOURCE = source;
    status->MPI_TAG    = tag;
    status->MPI_ERROR  = 0;
    return(0);
}


/*  Send a message to a process.  */
int MPI_Send(void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) {
    return(0);
}


/*  Receive a message from a source. */
int MPI_Recv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) {
    status->MPI_SOURCE = source;
    status->MPI_TAG    = tag;
    status->MPI_ERROR  = 0;
    return(0);
}


int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 int dest, int sendtag, void *recvbuf, int recvcount,
                  MPI_Datatype recvtype, int source, int recvtag,
                  MPI_Comm comm, MPI_Status *status) {
    status->MPI_SOURCE = source;
    status->MPI_TAG    = recvtag;
    status->MPI_ERROR  = 0;
    return(0);
}


int MPI_Type_commit(MPI_Datatype *datatype) {
    return(0);
}


int MPI_Type_free(MPI_Datatype *datatype) {
    return(0);
}


int MPI_Type_struct(int count, int *array_of_blocklengths,
                    MPI_Aint *array_of_displacements,
                    MPI_Datatype *array_of_types, MPI_Datatype *newtype) {
    return(0);
}


/*  FORTRAN versions of some of the above functions.
 *  Most of these operate the same as above, we just need to make sure that 
 *  they are linked in properly, see f2c.c for details.
 */
void mpi_address_(void **location, MPI_Aint *address) {
    *address = (MPI_Aint)NULL;
}

void mpi_bcast_(void **n, int *com, MPI_Datatype *dt, int *r, MPI_Comm *c, int *ie) {
    *ie = 0;
}

void mpi_comm_dup_(MPI_Comm *comm, MPI_Comm **newcomm, int *ie) {
    *ie = 0;
}

void mpi_comm_free_(MPI_Comm **comm, int *ie) {
    *ie = 0;
}

void mpi_comm_rank_(MPI_Comm *comm, int *rank, int *ie) {
    *rank = 0;
    *ie = 0;
}

void mpi_comm_size_(MPI_Comm *comm, int *size, int *ie) {
    *size = 1;
    *ie = 0;
}

void mpi_finalize_(int *ie) {
    *ie = 0;
}

void mpi_init_(int *ie) {
    *ie = 0;
}

void mpi_initialized_(int *flag, int *ie) {
    *flag = 1;
    *ie = 0;
}

void mpi_probe_(int *source, int *tag, MPI_Comm *comm, MPI_Status *status,
               int *ie) {
    status->MPI_SOURCE = *source;
    status->MPI_TAG    = *tag;
    status->MPI_ERROR  = 0;
    *ie = 0;
}

void mpi_send_(void *buf, int *count, MPI_Datatype *datatype, int *dest,
              int *tag, MPI_Comm *comm, int *ie) {
    *ie = 0;
}


void mpi_recv_(void *buf, int *count, MPI_Datatype *datatype, int *source,
              int *tag, MPI_Comm *comm, MPI_Status *status, int *ie) {
    status->MPI_SOURCE = *source;
    status->MPI_TAG    = *tag;
    status->MPI_ERROR  = 0;
    *ie = 0;
}


void mpi_sendrecv_(void *sendbuf, int *sendcount, MPI_Datatype *sendtype,
                  int *dest, int *sendtag, void *recvbuf, int *recvcount,
                  MPI_Datatype *recvtype, int *source, int *recvtag,
                  MPI_Comm *comm, MPI_Status *status, int *ie) {
    status->MPI_SOURCE = *source;
    status->MPI_TAG    = *recvtag;
    status->MPI_ERROR  = 0;
    *ie = 0;
}

void mpi_type_commit_(MPI_Datatype **datatype, int *ie) {
    *ie = 0;
}

void mpi_type_free_(MPI_Datatype **datatype, int *ie) {
    *ie = 0;
}


void mpi_type_struct_(int *count, int **array_of_blocklengths,
                    MPI_Aint **array_of_displacements,
                    MPI_Datatype **array_of_types, MPI_Datatype **newtype, int *ie) {
    *ie = 0;
}
