/*
 * Code generation for system model 'ArmModelVersion2'
 *
 * Model                      : ArmModelVersion2
 * Model version              : 1.91
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Mon Mar 16 10:19:01 2015
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "ArmModelVersion2.h"
#include "ArmModelVersion2_private.h"

/* Initial conditions for referenced model: 'ArmModelVersion2' */
void ArmModelVersion2_Init(DW_ArmModelVersion2_f_T *localDW,
  X_ArmModelVersion2_n_T *localX)
{
  /* InitializeConditions for Memory: '<S2>/Memory' */
  localDW->Memory_PreviousInput = 0.0;

  /* InitializeConditions for SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
  localDW->IntegratorSecondOrder_MODE = 0;
  localDW->IntegratorSecondOrder_DWORK1 = TRUE;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  localX->Filter_CSTATE = 0.0;
}

/* Start for referenced model: 'ArmModelVersion2' */
void ArmModelVersion2_Start(DW_ArmModelVersion2_f_T *localDW)
{
  /* Start for InitialCondition: '<S2>/Initial Velocity ' */
  localDW->InitialVelocity_FirstOutputTime = TRUE;
}

/* Outputs for referenced model: 'ArmModelVersion2' */
void ArmModelVersion2(RT_MODEL_ArmModelVersion2_T * const ArmModelVersion2_M,
                      const real_T *rtu_In1, const real_T *rtu_In2, real_T
                      *rty_Out1, real_T *rty_Out2, real_T *rty_Out3,
                      B_ArmModelVersion2_c_T *localB, DW_ArmModelVersion2_f_T
                      *localDW, X_ArmModelVersion2_n_T *localX)
{
  real_T rtb_Sum;
  if (rtmIsMajorTimeStep(ArmModelVersion2_M)) {
    /* InitialCondition: '<S2>/Initial Velocity ' incorporates:
     *  Gain: '<S2>/Coefficient of  Restitution'
     *  Memory: '<S2>/Memory'
     */
    if (localDW->InitialVelocity_FirstOutputTime) {
      localDW->InitialVelocity_FirstOutputTime = FALSE;
      localB->InitialVelocity = 0.0;
    } else {
      localB->InitialVelocity = -0.3 * localDW->Memory_PreviousInput;
    }

    /* End of InitialCondition: '<S2>/Initial Velocity ' */
  }

  /* SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_DWORK1) {
    localX->IntegratorSecondOrder_CSTATE[0] = *rtu_In2;
    localX->IntegratorSecondOrder_CSTATE[1] = localB->InitialVelocity;
  }

  if (rtmIsMajorTimeStep(ArmModelVersion2_M)) {
    switch (localDW->IntegratorSecondOrder_MODE) {
     case 0:
      if (localX->IntegratorSecondOrder_CSTATE[0] <= -0.2623) {
        localX->IntegratorSecondOrder_CSTATE[0] = -0.2623;
        if (localX->IntegratorSecondOrder_CSTATE[1] > 0.0) {
          localDW->IntegratorSecondOrder_MODE = 0;
        } else {
          localX->IntegratorSecondOrder_CSTATE[1] = 0.0;
          localDW->IntegratorSecondOrder_MODE = 1;
        }

        if (localB->InitialVelocity > 0.0) {
          localX->IntegratorSecondOrder_CSTATE[1] = localB->InitialVelocity;
          localDW->IntegratorSecondOrder_MODE = 0;
        }

        rtsiSetSolverNeedsReset(ArmModelVersion2_M->solverInfo, TRUE);
      }

      if (localX->IntegratorSecondOrder_CSTATE[0] >= rtInf) {
        localX->IntegratorSecondOrder_CSTATE[0] = rtInf;
        if (localX->IntegratorSecondOrder_CSTATE[1] < 0.0) {
          localDW->IntegratorSecondOrder_MODE = 0;
        } else {
          localX->IntegratorSecondOrder_CSTATE[1] = 0.0;
          localDW->IntegratorSecondOrder_MODE = 2;
        }

        if (localB->InitialVelocity < 0.0) {
          localX->IntegratorSecondOrder_CSTATE[1] = localB->InitialVelocity;
          localDW->IntegratorSecondOrder_MODE = 0;
        }

        rtsiSetSolverNeedsReset(ArmModelVersion2_M->solverInfo, TRUE);
      }
      break;

     case 1:
      if (localX->IntegratorSecondOrder_CSTATE[0] > -0.2623) {
        if (localX->IntegratorSecondOrder_CSTATE[0] >= rtInf) {
          localDW->IntegratorSecondOrder_MODE = 2;
          localX->IntegratorSecondOrder_CSTATE[0] = rtInf;
        } else {
          localDW->IntegratorSecondOrder_MODE = 0;
        }
      } else {
        localX->IntegratorSecondOrder_CSTATE[0] = -0.2623;
        localX->IntegratorSecondOrder_CSTATE[1] = 0.0;
      }
      break;

     case 2:
      if (localX->IntegratorSecondOrder_CSTATE[0] < rtInf) {
        if (localX->IntegratorSecondOrder_CSTATE[0] <= -0.2623) {
          localDW->IntegratorSecondOrder_MODE = 1;
          localX->IntegratorSecondOrder_CSTATE[0] = -0.2623;
        } else {
          localDW->IntegratorSecondOrder_MODE = 0;
        }
      } else {
        localX->IntegratorSecondOrder_CSTATE[0] = rtInf;
        localX->IntegratorSecondOrder_CSTATE[1] = 0.0;
      }
      break;
    }
  }

  if (localX->IntegratorSecondOrder_CSTATE[0] < -0.2623) {
    *rty_Out1 = -0.2623;
  } else if (localX->IntegratorSecondOrder_CSTATE[0] > rtInf) {
    *rty_Out1 = rtInf;
  } else {
    *rty_Out1 = localX->IntegratorSecondOrder_CSTATE[0];
  }

  *rty_Out2 = localX->IntegratorSecondOrder_CSTATE[1];

  /* End of SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */

  /* Sum: '<Root>/Sum' */
  rtb_Sum = *rtu_In1 - *rty_Out1;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  localB->FilterCoefficient = (1111.0590679189593 * rtb_Sum -
    localX->Filter_CSTATE) * 200.12291335792304;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Proportional Gain'
   */
  rtb_Sum = 50000.0 * rtb_Sum + localB->FilterCoefficient;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Sum >= 200.0) {
    *rty_Out3 = 200.0;
  } else if (rtb_Sum <= -200.0) {
    *rty_Out3 = -200.0;
  } else {
    *rty_Out3 = rtb_Sum;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<Root>/damping friction coeff'
   */
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S3>:1' */
  if (fabs(*rty_Out2) > 0.001) {
    /* '<S3>:1:4' */
    /* '<S3>:1:5' */
    if (*rty_Out2 < 0.0) {
      rtb_Sum = -1.0;
    } else if (*rty_Out2 > 0.0) {
      rtb_Sum = 1.0;
    } else if (*rty_Out2 == 0.0) {
      rtb_Sum = 0.0;
    } else {
      rtb_Sum = *rty_Out2;
    }

    rtb_Sum = -rtb_Sum * 20.5 * fabs(*rty_Out2) - 10.2;

    /* A constant force always trying to decelerate the motion */
  } else {
    /* '<S3>:1:7' */
    rtb_Sum = 0.0;

    /*  when the stick is not moving there are no net forces.  */
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* Sum: '<S2>/Sum' */
  localB->Sum = *rty_Out3 + rtb_Sum;
}

/* Update for referenced model: 'ArmModelVersion2' */
void ArmModelVersion2_Update(RT_MODEL_ArmModelVersion2_T * const
  ArmModelVersion2_M, real_T *rty_Out2, B_ArmModelVersion2_c_T *localB,
  DW_ArmModelVersion2_f_T *localDW)
{
  boolean_T resetSolver;
  int32_T uMode;
  if (rtmIsMajorTimeStep(ArmModelVersion2_M)) {
    /* Update for Memory: '<S2>/Memory' */
    localDW->Memory_PreviousInput = *rty_Out2;
  }

  /* Update for SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
  localDW->IntegratorSecondOrder_DWORK1 = FALSE;
  resetSolver = FALSE;
  uMode = localDW->IntegratorSecondOrder_MODE;
  if (((localDW->IntegratorSecondOrder_MODE == 1) && (localB->Sum > 0.0)) ||
      ((localDW->IntegratorSecondOrder_MODE == 2) && (localB->Sum < 0.0))) {
    uMode = 0;
  }

  if (localDW->IntegratorSecondOrder_MODE != uMode) {
    localDW->IntegratorSecondOrder_MODE = uMode;
    resetSolver = TRUE;
  }

  if (resetSolver) {
    rtsiSetSolverNeedsReset(ArmModelVersion2_M->solverInfo, TRUE);
  }

  /* End of Update for SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
}

/* Derivatives for referenced model: 'ArmModelVersion2' */
void ArmModelVersion2_Deriv(B_ArmModelVersion2_c_T *localB,
  DW_ArmModelVersion2_f_T *localDW, X_ArmModelVersion2_n_T *localX,
  XDot_ArmModelVersion2_n_T *localXdot)
{
  /* Derivatives for SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
  switch (localDW->IntegratorSecondOrder_MODE) {
   case 0:
    localXdot->IntegratorSecondOrder_CSTATE[0] =
      localX->IntegratorSecondOrder_CSTATE[1];
    localXdot->IntegratorSecondOrder_CSTATE[1] = localB->Sum;
    break;

   case 1:
    localXdot->IntegratorSecondOrder_CSTATE[0] = 0.0;
    localXdot->IntegratorSecondOrder_CSTATE[1] = 0.0;
    break;

   case 2:
    localXdot->IntegratorSecondOrder_CSTATE[0] = 0.0;
    localXdot->IntegratorSecondOrder_CSTATE[1] = 0.0;
    break;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S1>/Filter' */
  localXdot->Filter_CSTATE = localB->FilterCoefficient;
}

/* Model initialize function */
void ArmModelVersion2_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_ArmModelVersion2_T *
  const ArmModelVersion2_M, B_ArmModelVersion2_c_T *localB,
  DW_ArmModelVersion2_f_T *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ArmModelVersion2_M, 0,
                sizeof(RT_MODEL_ArmModelVersion2_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(ArmModelVersion2_M, rt_errorStatus);

  /* initialize stop requested flag */
  rtmSetStopRequestedPtr(ArmModelVersion2_M, rt_stopRequested);

  /* initialize RTWSolverInfo */
  ArmModelVersion2_M->solverInfo = (rt_solverInfo);

  /* Set the Timing fields to the appropriate data in the RTWSolverInfo */
  rtmSetSimTimeStepPointer(ArmModelVersion2_M, rtsiGetSimTimeStepPtr
    (ArmModelVersion2_M->solverInfo));
  ArmModelVersion2_M->Timing.stepSize0 = (rtsiGetStepSize
    (ArmModelVersion2_M->solverInfo));

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(B_ArmModelVersion2_c_T));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_ArmModelVersion2_f_T));
}
