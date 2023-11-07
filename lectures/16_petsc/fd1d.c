
/* petsc.h will have everything we need */
#include <petsc.h>

/* Helper function to construct matrix */
int FormMatrix(PetscInt n, PetscReal h, Mat* A)
{
  PetscInt ierr;
  ierr = MatSetValue( *A, 0, 0, 1.0, INSERT_VALUES );CHKERRQ(ierr);
  ierr = MatSetValue( *A, n-1, n-1, 1.0, INSERT_VALUES );CHKERRQ(ierr);

  for( PetscInt i = 1; i <= n-2; i++ )
    {
      /* Central difference approximation for -u'':
         ( -u(x-h) + 2*u(x) - u(x+h) )/h^2 */
      PetscReal kii = 2.0/(h*h);
      PetscReal kim1 = -1.0/(h*h);
      PetscReal kip1 = -1.0/(h*h);

      /* MatSetValues would be more efficient. */
      ierr = MatSetValue( *A, i, i, kii, INSERT_VALUES );CHKERRQ(ierr);
      ierr = MatSetValue( *A, i, i-1, kim1, INSERT_VALUES );CHKERRQ(ierr);
      ierr = MatSetValue( *A, i, i+1, kip1, INSERT_VALUES );CHKERRQ(ierr);
    }
  
  return 0;
}

/* Helper function to construct right-hand-side */
int FormRhs(PetscInt n, Vec* b)
{
  
  PetscInt ierr;
  ierr = VecSetValue( *b, 0, 0.0, INSERT_VALUES );CHKERRQ(ierr);
  ierr = VecSetValue( *b, n-1, 0.0, INSERT_VALUES );CHKERRQ(ierr);

  for( PetscInt i = 1; i <= n-2; i++ )
    {
      PetscReal f = 1.0;

      ierr = VecSetValue( *b, i, f, INSERT_VALUES );CHKERRQ(ierr);
    }
  return 0;
}

/* Helper function to output solution */
int OutputSolution( PetscInt n, Vec* x )
{
  PetscViewer viewer;

  PetscViewerASCIIOpen(PETSC_COMM_WORLD,"x.dat",&viewer);
  VecView(*x,viewer);
  PetscViewerDestroy(&viewer);

  return 0;
}

/* Main program */
int main(int argc,char **args)
{
  Mat            A; 
  PetscErrorCode ierr;
  PetscInt       nnz, n = 10;
  PetscReal      h;
  Vec            x,b;
  KSP            ksp;


  /* Only call this *once* in a program */
  PetscInitialize(&argc,&args,NULL,NULL);

  /* get problem size */
  ierr = PetscOptionsGetInt(NULL,NULL,"-n",&n,NULL); CHKERRQ(ierr);
  printf("n = %i\n",n);

  h = 1.0/(n-1);       /* mesh width */
  nnz = 3; /* # of nonzeros per row in the matrix */

  /* create stiffness matrix */
  ierr = MatCreateSeqAIJ(PETSC_COMM_SELF,n,n,nnz,NULL,&A);CHKERRQ(ierr);

  /* forms the element stiffness for the Laplacian */
  ierr = FormMatrix(n,h,&A);CHKERRQ(ierr);

  ierr = MatAssemblyBegin(A,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatAssemblyEnd(A,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);

  /* create right hand side and solution */
  ierr = VecCreateSeq(PETSC_COMM_SELF,n,&x);CHKERRQ(ierr); 
  ierr = VecDuplicate(x,&b);CHKERRQ(ierr);

  ierr = VecSet(x,0.0);CHKERRQ(ierr);
  ierr = VecSet(b,0.0);CHKERRQ(ierr);

  ierr = FormRhs(n,&b); CHKERRQ(ierr); 

  ierr = VecAssemblyBegin(b);CHKERRQ(ierr);
  ierr = VecAssemblyEnd(b);CHKERRQ(ierr);


  /* solve linear system */
  ierr = KSPCreate(PETSC_COMM_WORLD,&ksp);CHKERRQ(ierr);
  ierr = KSPSetOperators(ksp,A,A);CHKERRQ(ierr);
  ierr = KSPSetFromOptions(ksp);CHKERRQ(ierr);
  ierr = KSPSolve(ksp,b,x);CHKERRQ(ierr);

  PetscErrorCode reason;
  PetscInt nits;
  PetscReal rnorm;

  KSPGetConvergedReason(ksp, &reason);
  KSPGetIterationNumber(ksp, &nits);
  KSPGetResidualNorm(ksp, &rnorm);
  if(reason > 0)
    printf("Converged after %i iterations with a norm of the residual residual equal to %g\n", nits, rnorm);
  else
    printf("Did not converge after %i iterations\n", nits);


  /* output solution */
  ierr = OutputSolution(n,&x);CHKERRQ(ierr);

  /* Clean up */
  ierr = KSPDestroy(&ksp);CHKERRQ(ierr);
  ierr = VecDestroy(&x);CHKERRQ(ierr);
  ierr = VecDestroy(&b);CHKERRQ(ierr);
  ierr = MatDestroy(&A);CHKERRQ(ierr);

  /* Only call this *once* in a program */
  ierr = PetscFinalize();

  return 0;
}
