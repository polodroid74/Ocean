void DGEMM_ikj(int n, double* A, double* B, double* C) {
double* ptA( A ) ;
for (int i = 0; i < n; ++i)
   for (int k = 0; k < n; ++k, ++ptA)  {
      int j = 0;
      double* ptB( &B[k*n+0] ) ;
      double* ptC( &C[i*n+0] ) ;
      for (j = 0; j < n; ++j, ++ptC, ++ptB)
         // C[i][j] += A[i][k] * B[k][j];
         *ptC += *ptA * *ptB ;
   }
}

// void DGEMM_ikj(int n, double* A, double* B, double* C) {
//   for (int i=0; i<n;++i){
//     for (int k=0; k<n;++k){
//       for (int j=0; j<n;++j){
//         C[i][j] += A[i][k] * B[k][j];
//       }
//     }
//   }
// }
