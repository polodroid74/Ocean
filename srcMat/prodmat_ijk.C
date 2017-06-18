void DGEMM_ijk(int n, double* A, double*B, double*C) {
double* ptC( C );
for (int i = 0; i < n; ++i)
   for (int j = 0; j < n; ++j, ++ptC)  {
      int k;
      double* ptA(  &A[i*n+0] ) ;
      double* ptB(  &B[0*n+j] ) ;
      for (k = 0; k < n; ++k, ++ptA, ptB+=n)
         // C[i][j] += A[i][k] * B[k][j];
         *ptC += *ptA * *ptB ;
   }
}

// void DGEMM_ikj(int n, double* A, double* B, double* C) {
//   for (int i=0; i<n;++i){
//     for (int j=0; j<n;++j){
//       for (int k=0; k<n;++k){
//         C[i][j] += A[i][k] * B[k][j];
//       }
//     }
//   }
// }
