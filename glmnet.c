#include "glmnet_GLMNet.h"
#include <stdlib.h>

extern void elnet_(
            const int* cov_updating,
            const double* alpha,
            const int* num_observations,
            const int* num_predictors,

            const double* vals,

            double* observations,              // vector, overwritten
            double* weights,                   // vector, overwritten
            const int* flags,                  // vector
            const double* predictor_penalties, // vector
            const int* max_final_features,
            const int* max_path_features,
            const int* num_lambdas,
            const double* lambda_min_ratio,
            const double* user_defined_lambdas, // vector
            const double* convergence_threshold,
            const int* standardize_flag, // standardize observations
            const int* maxit,           // maximum iterations
            // Outputs
            int* num_fits,              // actual number of lambdas used 
            double* intercepts,         // vector of intercepts 
            double* coeffs,             // compressed matrix values
            int* coeffs_ptrs,           // compressed matrix ptrs
            int* coeff_counts,          // number non-zero per sol
            double* r_squareds,         // r squared statistic vector
            double* lambdas_used,       // actual lambda values vector
            int* num_passes,            // total iterations
            int* error_flag             // errors
           );
          

JNIEXPORT jint JNICALL Java_glmnet_GLMNet_elnet
  (JNIEnv *env, jobject thiz, jint covUpdating, jdouble alpha, jdoubleArray y, jdoubleArray w, jdoubleArray x, jintArray mFlags, jdoubleArray penalties, jint maxFinal, jint maxPath, jint numLambdas, jdouble lambdaMinRatio, jdoubleArray userLambdas, jdouble convThreshold, jint standardize, jint maxit, jintArray outNumFits, jdoubleArray outIntercepts, jdoubleArray outCoeffs, jintArray outCoeffPtrs, jintArray outCoeffCnts, jdoubleArray outRsq, jdoubleArray outLambdas, jintArray outNumPasses)
{
  jsize yl = (*env)->GetArrayLength(env, y);
  jsize xl = (*env)->GetArrayLength(env, x);
  jsize pl = xl / yl;
  jdouble *yv = (*env)->GetDoubleArrayElements(env, y, NULL);
  jdouble *wv = (*env)->GetDoubleArrayElements(env, w, NULL);
  jdouble *xv = (*env)->GetDoubleArrayElements(env, x, NULL);
  jint *mFlagsV = (*env)->GetIntArrayElements(env, mFlags, NULL);
  jdouble *penaltiesV = (*env)->GetDoubleArrayElements(env, penalties, NULL);
  jdouble *userLambdasV = (*env)->GetDoubleArrayElements(env, userLambdas, NULL);
  jint *numFitsV = (*env)->GetIntArrayElements(env, outNumFits, NULL);
  jdouble *interceptsV = (*env)->GetDoubleArrayElements(env, outIntercepts, NULL);
  jdouble *coeffsV = (*env)->GetDoubleArrayElements(env, outCoeffs, NULL);
  jint* coeffPtrsV = (*env)->GetIntArrayElements(env, outCoeffPtrs, NULL);
  jint* coeffCntsV = (*env)->GetIntArrayElements(env, outCoeffCnts, NULL);
  jdouble* rSquaredsV = (*env)->GetDoubleArrayElements(env, outRsq, NULL);
  jdouble* lambdasUsedV = (*env)->GetDoubleArrayElements(env, outLambdas, NULL);
  jint* numPassesV = (*env)->GetIntArrayElements(env, outNumPasses, NULL);
  jint error = 0;

  elnet_(
	   &covUpdating, 
	   &alpha,
	   &yl,
	   &pl,        
	   xv,
	   yv,
	   wv,
	   mFlagsV,
	   penaltiesV,
	   &maxFinal,
	   &maxPath,
	   &numLambdas,
	   &lambdaMinRatio,
	   userLambdasV,
	   &convThreshold,
	   &standardize,
	   &maxit,
	   numFitsV,
	   interceptsV,
	   coeffsV,
	   coeffPtrsV,
	   coeffCntsV,
	   rSquaredsV,
	   lambdasUsedV,
	   numPassesV,
	   &error
   );

  (*env)->ReleaseDoubleArrayElements(env, y, yv, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, w, wv, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, x, xv, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, mFlags, mFlagsV, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, penalties, penaltiesV, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, userLambdas, userLambdasV, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, outNumFits, numFitsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outIntercepts, interceptsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outCoeffs, coeffsV, 0);
  (*env)->ReleaseIntArrayElements(env, outCoeffPtrs, coeffPtrsV, 0);
  (*env)->ReleaseIntArrayElements(env, outCoeffCnts, coeffCntsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outRsq, rSquaredsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outLambdas, lambdasUsedV, 0);
  (*env)->ReleaseIntArrayElements(env, outNumPasses, numPassesV, 0);
  
  return error;
}

extern void spelnet_(
            const int* cov_updating,
            const double* alpha,
            const int* num_observations,
            const int* num_predictors,

            const double* vals,         // sparse matrix
            const int* outer_pointers,  // sparse matrix
            const int* inner_indices,   // sparse matrix

            double* observations,              // vector, overwritten
            double* weights,                   // vector, overwritten
            const int* flags,                  // vector
            const double* predictor_penalties, // vector
            const int* max_final_features,
            const int* max_path_features,
            const int* num_lambdas,
            const double* lambda_min_ratio,
            const double* user_defined_lambdas, // vector
            const double* convergence_threshold,
            const int* standardize_flag, // standardize observations
            const int* maxit,           // maximum iterations
            // Outputs
            int* num_fits,              // actual number of lambdas used 
            double* intercepts,         // vector of intercepts 
            double* coeffs,             // compressed matrix values
            int* coeffs_ptrs,           // compressed matrix ptrs
            int* coeff_counts,          // number non-zero per sol
            double* r_squareds,         // r squared statistic vector
            double* lambdas_used,       // actual lambda values vector
            int* num_passes,            // total iterations
            int* error_flag             // errors
           );
          

JNIEXPORT jint JNICALL Java_glmnet_GLMNet_spelnet
  (JNIEnv *env, jobject thiz, jint covUpdating, jdouble alpha, jdoubleArray y, jdoubleArray w, jdoubleArray xx, jintArray xi, jintArray xp, jintArray mFlags, jdoubleArray penalties, jint maxFinal, jint maxPath, jint numLambdas, jdouble lambdaMinRatio, jdoubleArray userLambdas, jdouble convThreshold, jint standardize, jint maxit, jintArray outNumFits, jdoubleArray outIntercepts, jdoubleArray outCoeffs, jintArray outCoeffPtrs, jintArray outCoeffCnts, jdoubleArray outRsq, jdoubleArray outLambdas, jintArray outNumPasses)
{
  jsize yl = (*env)->GetArrayLength(env, y);
  jsize xpl = (*env)->GetArrayLength(env, xp) - 1;   /* why -1 ??? */
  jdouble *yv = (*env)->GetDoubleArrayElements(env, y, NULL);
  jdouble *wv = (*env)->GetDoubleArrayElements(env, w, NULL);
  jdouble *xxv = (*env)->GetDoubleArrayElements(env, xx, NULL);
  jint *xiv = (*env)->GetIntArrayElements(env, xi, NULL);
  jint *xpv = (*env)->GetIntArrayElements(env, xp, NULL);
  jint *mFlagsV = (*env)->GetIntArrayElements(env, mFlags, NULL);
  jdouble *penaltiesV = (*env)->GetDoubleArrayElements(env, penalties, NULL);
  jdouble *userLambdasV = (*env)->GetDoubleArrayElements(env, userLambdas, NULL);
  jint *numFitsV = (*env)->GetIntArrayElements(env, outNumFits, NULL);
  jdouble *interceptsV = (*env)->GetDoubleArrayElements(env, outIntercepts, NULL);
  jdouble *coeffsV = (*env)->GetDoubleArrayElements(env, outCoeffs, NULL);
  jint* coeffPtrsV = (*env)->GetIntArrayElements(env, outCoeffPtrs, NULL);
  jint* coeffCntsV = (*env)->GetIntArrayElements(env, outCoeffCnts, NULL);
  jdouble* rSquaredsV = (*env)->GetDoubleArrayElements(env, outRsq, NULL);
  jdouble* lambdasUsedV = (*env)->GetDoubleArrayElements(env, outLambdas, NULL);
  jint* numPassesV = (*env)->GetIntArrayElements(env, outNumPasses, NULL);
  jint error = 0;

  spelnet_(
	   &covUpdating, 
	   &alpha,
	   &yl,
	   &xpl,        
	   xxv,
	   xpv,
	   xiv,
	   yv,
	   wv,
	   mFlagsV,
	   penaltiesV,
	   &maxFinal,
	   &maxPath,
	   &numLambdas,
	   &lambdaMinRatio,
	   userLambdasV,
	   &convThreshold,
	   &standardize,
	   &maxit,
	   numFitsV,
	   interceptsV,
	   coeffsV,
	   coeffPtrsV,
	   coeffCntsV,
	   rSquaredsV,
	   lambdasUsedV,
	   numPassesV,
	   &error
   );

  (*env)->ReleaseDoubleArrayElements(env, y, yv, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, w, wv, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, xx, xxv, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, xi, xiv, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, xp, xpv, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, mFlags, mFlagsV, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, penalties, penaltiesV, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, userLambdas, userLambdasV, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, outNumFits, numFitsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outIntercepts, interceptsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outCoeffs, coeffsV, 0);
  (*env)->ReleaseIntArrayElements(env, outCoeffPtrs, coeffPtrsV, 0);
  (*env)->ReleaseIntArrayElements(env, outCoeffCnts, coeffCntsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outRsq, rSquaredsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outLambdas, lambdasUsedV, 0);
  (*env)->ReleaseIntArrayElements(env, outNumPasses, numPassesV, 0);
  
  return error;
}

extern void lognet_(
            const double* alpha,
            const int* num_observations,
            const int* num_predictors,

	    const int* num_classes,

            const double* x,

            double* observations,              // vector, overwritten
            double* offsets,                   // vector, overwritten
            const int* flags,                  // vector
            const double* predictor_penalties, // vector
            const int* max_final_features,
            const int* max_path_features,
            const int* num_lambdas,
            const double* lambda_min_ratio,
            const double* user_defined_lambdas, // vector
            const double* convergence_threshold,
            const int* standardize_flag, // standardize observations
            const int* maxit,           // maximum iterations
	    const int* kopt,            // options: 0=Newton-Raphson, 1=modified
            // Outputs
            int* num_fits,              // actual number of lambdas used 
            double* intercepts,         // vector of intercepts 
            double* coeffs,             // compressed matrix values
            int* coeffs_ptrs,           // compressed matrix ptrs
            int* coeff_counts,          // number non-zero per sol
            double* dev0,               // null deviance
	    double* fdev,               // vector, fraction of deviance.
            double* lambdas_used,       // actual lambda values vector
            int* num_passes,            // total iterations
            int* error_flag             // errors
           );


JNIEXPORT jint JNICALL Java_glmnet_GLMNet_lognet
(JNIEnv *env, jobject thiz, jdouble alpha, jint nc, jdoubleArray y, jdoubleArray offsets, jdoubleArray x, jintArray mFlags, jdoubleArray penalties, jint maxFinal, jint maxPath, jint numLambdas, jdouble lambdaMinRatio, jdoubleArray userLambdas, jdouble convThreshold, jint standardize, jint maxit, jint kopt, jintArray outNumFits, jdoubleArray outIntercepts, jdoubleArray outCoeffs, jintArray outCoeffPtrs, jintArray outCoeffCnts, jdoubleArray outDev0, jdoubleArray outFdev, jdoubleArray outLambdas, jintArray outNumPasses)
{
  jsize yl = (*env)->GetArrayLength(env, y);
  if (nc > 2) {
    yl = yl / nc;
  } else {
    yl = yl / 2;
  }
  jsize xpl = ((*env)->GetArrayLength(env, x)) / yl; 
  jdouble *yv = (*env)->GetDoubleArrayElements(env, y, NULL);
  jdouble *ov = (*env)->GetDoubleArrayElements(env, offsets, NULL);
  jdouble *xv = (*env)->GetDoubleArrayElements(env, x, NULL);
  jint *mFlagsV = (*env)->GetIntArrayElements(env, mFlags, NULL);
  jdouble *penaltiesV = (*env)->GetDoubleArrayElements(env, penalties, NULL);
  jdouble *userLambdasV = (*env)->GetDoubleArrayElements(env, userLambdas, NULL);
  jint *numFitsV = (*env)->GetIntArrayElements(env, outNumFits, NULL);
  jdouble *interceptsV = (*env)->GetDoubleArrayElements(env, outIntercepts, NULL);
  jdouble *coeffsV = (*env)->GetDoubleArrayElements(env, outCoeffs, NULL);
  jint* coeffPtrsV = (*env)->GetIntArrayElements(env, outCoeffPtrs, NULL);
  jint* coeffCntsV = (*env)->GetIntArrayElements(env, outCoeffCnts, NULL);
  jdouble* dev0V = (*env)->GetDoubleArrayElements(env, outDev0, NULL);
  jdouble* fdevV = (*env)->GetDoubleArrayElements(env, outFdev, NULL);
  jdouble* lambdasUsedV = (*env)->GetDoubleArrayElements(env, outLambdas, NULL);
  jint* numPassesV = (*env)->GetIntArrayElements(env, outNumPasses, NULL);
  jint error = 0;

  lognet_(
	   &alpha,
	   &yl,
	   &xpl,
	   &nc,
	   xv,
	   yv,
	   ov,
	   mFlagsV,
	   penaltiesV,
	   &maxFinal,
	   &maxPath,
	   &numLambdas,
	   &lambdaMinRatio,
	   userLambdasV,
	   &convThreshold,
	   &standardize,
	   &maxit,
	   &kopt,
	   numFitsV,
	   interceptsV,
	   coeffsV,
	   coeffPtrsV,
	   coeffCntsV,
	   dev0V,
	   fdevV,
	   lambdasUsedV,
	   numPassesV,
	   &error
   );

  (*env)->ReleaseDoubleArrayElements(env, y, yv, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, offsets, ov, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, x, xv, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, mFlags, mFlagsV, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, penalties, penaltiesV, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, userLambdas, userLambdasV, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, outNumFits, numFitsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outIntercepts, interceptsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outCoeffs, coeffsV, 0);
  (*env)->ReleaseIntArrayElements(env, outCoeffPtrs, coeffPtrsV, 0);
  (*env)->ReleaseIntArrayElements(env, outCoeffCnts, coeffCntsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outDev0, dev0V, 0);
  (*env)->ReleaseDoubleArrayElements(env, outFdev, fdevV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outLambdas, lambdasUsedV, 0);
  (*env)->ReleaseIntArrayElements(env, outNumPasses, numPassesV, 0);
  
  return error;
}


extern void splognet_(
            const double* alpha,
            const int* num_observations,
            const int* num_predictors,

	    const int* num_classes,

            const double* vals,         // sparse matrix
            const int* outer_pointers,  // sparse matrix
            const int* inner_indices,   // sparse matrix

            double* observations,              // vector, overwritten
            double* offsets,                   // vector, overwritten
            const int* flags,                  // vector
            const double* predictor_penalties, // vector
            const int* max_final_features,
            const int* max_path_features,
            const int* num_lambdas,
            const double* lambda_min_ratio,
            const double* user_defined_lambdas, // vector
            const double* convergence_threshold,
            const int* standardize_flag, // standardize observations
            const int* maxit,           // maximum iterations
	    const int* kopt,            // options: 0=Newton-Raphson, 1=modified
            // Outputs
            int* num_fits,              // actual number of lambdas used 
            double* intercepts,         // vector of intercepts 
            double* coeffs,             // compressed matrix values
            int* coeffs_ptrs,           // compressed matrix ptrs
            int* coeff_counts,          // number non-zero per sol
            double* dev0,               // null deviance
	    double* fdev,               // vector, fraction of deviance.
            double* lambdas_used,       // actual lambda values vector
            int* num_passes,            // total iterations
            int* error_flag             // errors
           );


JNIEXPORT jint JNICALL Java_glmnet_GLMNet_splognet
  (JNIEnv *env, jobject thiz, jdouble alpha, jint nc, jdoubleArray y, jdoubleArray offsets, jdoubleArray xx, jintArray xi, jintArray xp, jintArray mFlags, jdoubleArray penalties, jint maxFinal, jint maxPath, jint numLambdas, jdouble lambdaMinRatio, jdoubleArray userLambdas, jdouble convThreshold, jint standardize, jint maxit, jint kopt, jintArray outNumFits, jdoubleArray outIntercepts, jdoubleArray outCoeffs, jintArray outCoeffPtrs, jintArray outCoeffCnts, jdoubleArray outDev0, jdoubleArray outFdev, jdoubleArray outLambdas, jintArray outNumPasses)
{
  jsize yl = (*env)->GetArrayLength(env, y);
  if (nc > 2) {
    yl = yl / nc;
  } else {
    yl = yl / 2;
  }

  jsize xpl = (*env)->GetArrayLength(env, xp) - 1; 
  jdouble *yv = (*env)->GetDoubleArrayElements(env, y, NULL);
  jdouble *ov = (*env)->GetDoubleArrayElements(env, offsets, NULL);
  jdouble *xxv = (*env)->GetDoubleArrayElements(env, xx, NULL);
  jint *xiv = (*env)->GetIntArrayElements(env, xi, NULL);
  jint *xpv = (*env)->GetIntArrayElements(env, xp, NULL);
  jint *mFlagsV = (*env)->GetIntArrayElements(env, mFlags, NULL);
  jdouble *penaltiesV = (*env)->GetDoubleArrayElements(env, penalties, NULL);
  jdouble *userLambdasV = (*env)->GetDoubleArrayElements(env, userLambdas, NULL);
  jint *numFitsV = (*env)->GetIntArrayElements(env, outNumFits, NULL);
  jdouble *interceptsV = (*env)->GetDoubleArrayElements(env, outIntercepts, NULL);
  jdouble *coeffsV = (*env)->GetDoubleArrayElements(env, outCoeffs, NULL);
  jint* coeffPtrsV = (*env)->GetIntArrayElements(env, outCoeffPtrs, NULL);
  jint* coeffCntsV = (*env)->GetIntArrayElements(env, outCoeffCnts, NULL);
  jdouble* dev0V = (*env)->GetDoubleArrayElements(env, outDev0, NULL);
  jdouble* fdevV = (*env)->GetDoubleArrayElements(env, outFdev, NULL);
  jdouble* lambdasUsedV = (*env)->GetDoubleArrayElements(env, outLambdas, NULL);
  jint* numPassesV = (*env)->GetIntArrayElements(env, outNumPasses, NULL);
  jint error = 0;

  splognet_(
	   &alpha,
	   &yl,
	   &xpl,
	   &nc,
	   xxv,
	   xpv,
	   xiv,
	   yv,
	   ov,
	   mFlagsV,
	   penaltiesV,
	   &maxFinal,
	   &maxPath,
	   &numLambdas,
	   &lambdaMinRatio,
	   userLambdasV,
	   &convThreshold,
	   &standardize,
	   &maxit,
	   &kopt,
	   numFitsV,
	   interceptsV,
	   coeffsV,
	   coeffPtrsV,
	   coeffCntsV,
	   dev0V,
	   fdevV,
	   lambdasUsedV,
	   numPassesV,
	   &error
   );

  (*env)->ReleaseDoubleArrayElements(env, y, yv, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, offsets, ov, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, xx, xxv, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, xi, xiv, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, xp, xpv, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, mFlags, mFlagsV, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, penalties, penaltiesV, JNI_ABORT);
  (*env)->ReleaseDoubleArrayElements(env, userLambdas, userLambdasV, JNI_ABORT);
  (*env)->ReleaseIntArrayElements(env, outNumFits, numFitsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outIntercepts, interceptsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outCoeffs, coeffsV, 0);
  (*env)->ReleaseIntArrayElements(env, outCoeffPtrs, coeffPtrsV, 0);
  (*env)->ReleaseIntArrayElements(env, outCoeffCnts, coeffCntsV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outDev0, dev0V, 0);
  (*env)->ReleaseDoubleArrayElements(env, outFdev, fdevV, 0);
  (*env)->ReleaseDoubleArrayElements(env, outLambdas, lambdasUsedV, 0);
  (*env)->ReleaseIntArrayElements(env, outNumPasses, numPassesV, 0);
  
  return error;
}
