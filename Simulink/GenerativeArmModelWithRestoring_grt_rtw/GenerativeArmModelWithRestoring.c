/*
 * GenerativeArmModelWithRestoring.c
 *
 * Code generation for model "GenerativeArmModelWithRestoring".
 *
 * Model version              : 1.124
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Mon Mar 16 10:19:38 2015
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "GenerativeArmModelWithRestoring.h"
#include "GenerativeArmModelWithRestoring_private.h"

/* Block signals (auto storage) */
B_GenerativeArmModelWithResto_T GenerativeArmModelWithRestori_B;

/* Continuous states */
X_GenerativeArmModelWithResto_T GenerativeArmModelWithRestori_X;

/* Block states (auto storage) */
DW_GenerativeArmModelWithRest_T GenerativeArmModelWithRestor_DW;

/* Real-time model */
RT_MODEL_GenerativeArmModelWi_T GenerativeArmModelWithRestor_M_;
RT_MODEL_GenerativeArmModelWi_T *const GenerativeArmModelWithRestor_M =
  &GenerativeArmModelWithRestor_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  GenerativeArmModelWithRestoring_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  GenerativeArmModelWithRestoring_step();
  GenerativeArmModelWithRestoring_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  GenerativeArmModelWithRestoring_step();
  GenerativeArmModelWithRestoring_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void GenerativeArmModelWithRestoring_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWorkspace;
  real_T rtb_Derivative;
  real_T rtb_FromWs[9];
  if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
    /* set solver stop time */
    if (!(GenerativeArmModelWithRestor_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&GenerativeArmModelWithRestor_M->solverInfo,
                            ((GenerativeArmModelWithRestor_M->Timing.clockTickH0
        + 1) * GenerativeArmModelWithRestor_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&GenerativeArmModelWithRestor_M->solverInfo,
                            ((GenerativeArmModelWithRestor_M->Timing.clockTick0
        + 1) * GenerativeArmModelWithRestor_M->Timing.stepSize0 +
        GenerativeArmModelWithRestor_M->Timing.clockTickH0 *
        GenerativeArmModelWithRestor_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(GenerativeArmModelWithRestor_M)) {
    GenerativeArmModelWithRestor_M->Timing.t[0] = rtsiGetT
      (&GenerativeArmModelWithRestor_M->solverInfo);
  }

  {
    real_T rtb_TrigonometricFunction;
    real_T rtb_Torqueduetogravity;

    /* InitialCondition: '<Root>/Starting angle  (rad)' */
    if ((GenerativeArmModelWithRestor_DW.Startinganglerad_FirstOutputTim ==
         (rtMinusInf)) ||
        (GenerativeArmModelWithRestor_DW.Startinganglerad_FirstOutputTim ==
         GenerativeArmModelWithRestor_M->Timing.t[0])) {
      GenerativeArmModelWithRestor_DW.Startinganglerad_FirstOutputTim =
        GenerativeArmModelWithRestor_M->Timing.t[0];
      GenerativeArmModelWithRestori_B.Startinganglerad =
        GenerativeArmModelWithRestori_P.Startinganglerad_Value;
    } else {
      GenerativeArmModelWithRestori_B.Startinganglerad = 0.0;
    }

    /* End of InitialCondition: '<Root>/Starting angle  (rad)' */
    if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
      /* InitialCondition: '<Root>/Initial angular velocity rad//s ' incorporates:
       *  Gain: '<Root>/COR for stick and drum TBD'
       *  Memory: '<Root>/Memory'
       */
      if (GenerativeArmModelWithRestor_DW.Initialangularvelocityrads_Firs) {
        GenerativeArmModelWithRestor_DW.Initialangularvelocityrads_Firs = FALSE;
        GenerativeArmModelWithRestori_B.Initialangularvelocityrads =
          GenerativeArmModelWithRestori_P.Initialangularvelocityrads_Valu;
      } else {
        GenerativeArmModelWithRestori_B.Initialangularvelocityrads =
          GenerativeArmModelWithRestori_P.CORforstickanddrumTBD_Gain *
          GenerativeArmModelWithRestor_DW.Memory_PreviousInput;
      }

      /* End of InitialCondition: '<Root>/Initial angular velocity rad//s ' */
    }

    /* SecondOrderIntegrator: '<Root>/Integrator, Second-Order1' */
    if (GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_DWORK1) {
      GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] =
        GenerativeArmModelWithRestori_B.Startinganglerad;
      GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] =
        GenerativeArmModelWithRestori_B.Initialangularvelocityrads;
    }

    if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
      switch (GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE) {
       case 0:
        if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] <=
            GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_LowerLim) {
          GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] =
            GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_LowerLim;
          if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] >
              0.0) {
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 0;
          } else {
            GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] =
              0.0;
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 1;
          }

          if (GenerativeArmModelWithRestori_B.Initialangularvelocityrads > 0.0)
          {
            GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] =
              GenerativeArmModelWithRestori_B.Initialangularvelocityrads;
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 0;
          }

          rtsiSetSolverNeedsReset(&GenerativeArmModelWithRestor_M->solverInfo,
            TRUE);
        }

        if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] >=
            GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim) {
          GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] =
            GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim;
          if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] <
              0.0) {
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 0;
          } else {
            GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] =
              0.0;
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 2;
          }

          if (GenerativeArmModelWithRestori_B.Initialangularvelocityrads < 0.0)
          {
            GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] =
              GenerativeArmModelWithRestori_B.Initialangularvelocityrads;
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 0;
          }

          rtsiSetSolverNeedsReset(&GenerativeArmModelWithRestor_M->solverInfo,
            TRUE);
        }
        break;

       case 1:
        if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] >
            GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_LowerLim) {
          if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] >=
              GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim) {
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 2;
            GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] =
              GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim;
          } else {
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 0;
          }
        } else {
          GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] =
            GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_LowerLim;
          GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] = 0.0;
        }
        break;

       case 2:
        if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] <
            GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim) {
          if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] <=
              GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_LowerLim) {
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 1;
            GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] =
              GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_LowerLim;
          } else {
            GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 0;
          }
        } else {
          GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] =
            GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim;
          GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1] = 0.0;
        }
        break;
      }
    }

    if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] <
        GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_LowerLim) {
      GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o1 =
        GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_LowerLim;
    } else if (GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0] >
               GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim)
    {
      GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o1 =
        GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim;
    } else {
      GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o1 =
        GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[0];
    }

    GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o2 =
      GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1];

    /* End of SecondOrderIntegrator: '<Root>/Integrator, Second-Order1' */

    /* ModelReference: '<Root>/Model' */
    ArmModelVersion2(&(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtm),
                     &GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o1,
                     &GenerativeArmModelWithRestori_B.Startinganglerad,
                     &GenerativeArmModelWithRestori_B.Model_o1,
                     &GenerativeArmModelWithRestori_B.Model_o2,
                     &GenerativeArmModelWithRestori_B.Model_o3,
                     &(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtb),
                     &(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtdw),
                     &(GenerativeArmModelWithRestori_X.Model_CSTATE));

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/drumHeadAngleLimit'
     *  Constant: '<Root>/l'
     *  Constant: '<Root>/lb'
     *  Constant: '<Root>/u '
     *  Constant: '<Root>/ub '
     */
    /* MATLAB Function 'MATLAB Function': '<S3>:1' */
    /* '<S3>:1:4' */
    GenerativeArmModelWithRestori_B.x =
      ((GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o1 -
        GenerativeArmModelWithRestori_P.l_Value) *
       GenerativeArmModelWithRestori_P.ub_Value +
       (GenerativeArmModelWithRestori_P.u_Value -
        GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o1) *
       GenerativeArmModelWithRestori_P.lb_Value) /
      (GenerativeArmModelWithRestori_P.u_Value -
       GenerativeArmModelWithRestori_P.l_Value);

    /* '<S3>:1:5' */
    GenerativeArmModelWithRestori_B.y =
      ((GenerativeArmModelWithRestori_B.Model_o1 -
        GenerativeArmModelWithRestori_P.l_Value) *
       GenerativeArmModelWithRestori_P.ub_Value +
       (GenerativeArmModelWithRestori_P.u_Value -
        GenerativeArmModelWithRestori_B.Model_o1) *
       GenerativeArmModelWithRestori_P.lb_Value) /
      (GenerativeArmModelWithRestori_P.u_Value -
       GenerativeArmModelWithRestori_P.l_Value);

    /* '<S3>:1:6' */
    GenerativeArmModelWithRestori_B.z =
      ((GenerativeArmModelWithRestori_P.drumHeadAngleLimit_Value -
        GenerativeArmModelWithRestori_P.l_Value) *
       GenerativeArmModelWithRestori_P.ub_Value +
       (GenerativeArmModelWithRestori_P.u_Value -
        GenerativeArmModelWithRestori_P.drumHeadAngleLimit_Value) *
       GenerativeArmModelWithRestori_P.lb_Value) /
      (GenerativeArmModelWithRestori_P.u_Value -
       GenerativeArmModelWithRestori_P.l_Value);
    if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
    }

    /* FromWorkspace: '<Root>/From Workspace' */
    {
      real_T *pDataValues = (real_T *)
        GenerativeArmModelWithRestor_DW.FromWorkspace_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        GenerativeArmModelWithRestor_DW.FromWorkspace_PWORK.TimePtr;
      int_T currTimeIndex =
        GenerativeArmModelWithRestor_DW.FromWorkspace_IWORK.PrevIndex;
      real_T t = GenerativeArmModelWithRestor_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[8000]) {
        currTimeIndex = 7999;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      GenerativeArmModelWithRestor_DW.FromWorkspace_IWORK.PrevIndex =
        currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_FromWorkspace = pDataValues[currTimeIndex];
          } else {
            rtb_FromWorkspace = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_FromWorkspace = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 8001;
        }
      }
    }

    /* FromWorkspace: '<S4>/FromWs' */
    {
      real_T *pDataValues = (real_T *)
        GenerativeArmModelWithRestor_DW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        GenerativeArmModelWithRestor_DW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex =
        GenerativeArmModelWithRestor_DW.FromWs_IWORK.PrevIndex;
      real_T t = GenerativeArmModelWithRestor_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[19]) {
        currTimeIndex = 18;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      GenerativeArmModelWithRestor_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 9; ++elIdx) {
                (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex];
                pDataValues += 20;
              }
            }
          } else {
            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 9; ++elIdx) {
                (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex + 1];
                pDataValues += 20;
              }
            }
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;

          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 9; ++elIdx) {
              d1 = pDataValues[TimeIndex];
              d2 = pDataValues[TimeIndex + 1];
              (&rtb_FromWs[0])[elIdx] = (real_T) rtInterpolate(d1, d2, f1, f2);
              pDataValues += 20;
            }
          }
        }
      }
    }

    /* Product: '<Root>/Product2' incorporates:
     *  Constant: '<S2>/Constant'
     *  RelationalOperator: '<S2>/Compare'
     */
    GenerativeArmModelWithRestori_B.Product2 = (real_T)(rtb_FromWorkspace <=
      GenerativeArmModelWithRestori_P.Constant_Value) * rtb_FromWs[0];

    /* Trigonometry: '<Root>/Trigonometric Function' */
    rtb_TrigonometricFunction = cos
      (GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o1);

    /* Gain: '<Root>/Torque due to gravity' */
    rtb_Torqueduetogravity =
      GenerativeArmModelWithRestori_P.Torqueduetogravity_Gain *
      rtb_TrigonometricFunction;

    /* Product: '<Root>/when to trigger antigravity ' incorporates:
     *  Constant: '<S1>/Constant'
     *  Gain: '<Root>/.1'
     *  RelationalOperator: '<S1>/Compare'
     */
    GenerativeArmModelWithRestori_B.whentotriggerantigravity = (real_T)
      (rtb_FromWorkspace > GenerativeArmModelWithRestori_P.Constant_Value_j) *
      (GenerativeArmModelWithRestori_P.u_Gain * rtb_Torqueduetogravity);
    if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
      /* Gain: '<Root>/.2' incorporates:
       *  Delay: '<Root>/Delay'
       */
      GenerativeArmModelWithRestori_B.u =
        GenerativeArmModelWithRestori_P.u_Gain_k *
        GenerativeArmModelWithRestor_DW.Delay_DSTATE;
    }

    /* Gain: '<Root>/.' incorporates:
     *  Gain: '<Root>/distance of finger from fulcrum'
     *  Product: '<Root>/Divide'
     *  Product: '<Root>/Product'
     *  Product: '<Root>/Product1'
     *  Sum: '<Root>/Sum'
     *  Sum: '<Root>/Sum1'
     */
    GenerativeArmModelWithRestori_B.u_l = (((((1.0 / rtb_TrigonometricFunction *
      GenerativeArmModelWithRestori_B.u + 0.0) +
      GenerativeArmModelWithRestori_B.Product2) *
      GenerativeArmModelWithRestori_P.distanceoffingerfromfulcrum_Gai *
      rtb_TrigonometricFunction +
      GenerativeArmModelWithRestori_B.whentotriggerantigravity) +
      rtb_Torqueduetogravity) + 0.0) * GenerativeArmModelWithRestori_P._Gain;
    if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
      /* ToWorkspace: '<Root>/To ' */
      rt_UpdateStructLogVar((StructLogVar *)
                            GenerativeArmModelWithRestor_DW.To_PWORK.LoggedData,
                            (NULL), &GenerativeArmModelWithRestori_B.x);

      /* ToWorkspace: '<Root>/To Workspace' */
      rt_UpdateStructLogVar((StructLogVar *)
                            GenerativeArmModelWithRestor_DW.ToWorkspace_PWORK.LoggedData,
                            (NULL),
                            &GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o2);

      /* ToWorkspace: '<Root>/To Workspace1' */
      rt_UpdateStructLogVar((StructLogVar *)
                            GenerativeArmModelWithRestor_DW.ToWorkspace1_PWORK.LoggedData,
                            (NULL),
                            &GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o1);

      /* ToWorkspace: '<Root>/To Workspace2' */
      rt_UpdateStructLogVar((StructLogVar *)
                            GenerativeArmModelWithRestor_DW.ToWorkspace2_PWORK.LoggedData,
                            (NULL), &GenerativeArmModelWithRestori_B.Model_o1);
    }

    /* Derivative: '<Root>/Derivative' */
    {
      real_T t = GenerativeArmModelWithRestor_M->Timing.t[0];
      real_T timeStampA =
        GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampA;
      real_T timeStampB =
        GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampB;
      real_T *lastU =
        &GenerativeArmModelWithRestor_DW.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        rtb_Derivative = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU =
              &GenerativeArmModelWithRestor_DW.Derivative_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &GenerativeArmModelWithRestor_DW.Derivative_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        rtb_Derivative = (rtb_FromWorkspace - *lastU++) / deltaT;
      }
    }

    /* Derivative: '<Root>/Derivative1' */
    {
      real_T t = GenerativeArmModelWithRestor_M->Timing.t[0];
      real_T timeStampA =
        GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampA;
      real_T timeStampB =
        GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampB;
      real_T *lastU =
        &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        GenerativeArmModelWithRestori_B.Derivative1 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU =
              &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU =
            &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        GenerativeArmModelWithRestori_B.Derivative1 = (rtb_Derivative - *lastU++)
          / deltaT;
      }
    }
  }

  if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(GenerativeArmModelWithRestor_M->rtwLogInfo,
                        (GenerativeArmModelWithRestor_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
    boolean_T resetSolver;
    int32_T uMode;
    if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
      /* Update for Memory: '<Root>/Memory' */
      GenerativeArmModelWithRestor_DW.Memory_PreviousInput =
        GenerativeArmModelWithRestori_B.IntegratorSecondOrder1_o2;
    }

    /* Update for SecondOrderIntegrator: '<Root>/Integrator, Second-Order1' */
    GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_DWORK1 = FALSE;
    resetSolver = FALSE;
    uMode = GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE;
    if (((GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE == 1) &&
         (GenerativeArmModelWithRestori_B.u_l > 0.0)) ||
        ((GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE == 2) &&
         (GenerativeArmModelWithRestori_B.u_l < 0.0))) {
      uMode = 0;
    }

    if (GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE != uMode) {
      GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = uMode;
      resetSolver = TRUE;
    }

    if (resetSolver) {
      rtsiSetSolverNeedsReset(&GenerativeArmModelWithRestor_M->solverInfo, TRUE);
    }

    /* End of Update for SecondOrderIntegrator: '<Root>/Integrator, Second-Order1' */
    /* Update for ModelReference: '<Root>/Model' */
    ArmModelVersion2_Update(&(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtm),
      &GenerativeArmModelWithRestori_B.Model_o2,
      &(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtb),
      &(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtdw));
    if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
      /* Update for Delay: '<Root>/Delay' */
      GenerativeArmModelWithRestor_DW.Delay_DSTATE =
        GenerativeArmModelWithRestori_B.Derivative1;
    }

    /* Update for Derivative: '<Root>/Derivative' */
    {
      real_T timeStampA =
        GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampA;
      real_T timeStampB =
        GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampB;
      real_T* lastTime =
        &GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampA;
      real_T* lastU =
        &GenerativeArmModelWithRestor_DW.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime =
            &GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampB;
          lastU = &GenerativeArmModelWithRestor_DW.Derivative_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime =
            &GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampB;
          lastU = &GenerativeArmModelWithRestor_DW.Derivative_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = GenerativeArmModelWithRestor_M->Timing.t[0];
      *lastU++ = rtb_FromWorkspace;
    }

    /* Update for Derivative: '<Root>/Derivative1' */
    {
      real_T timeStampA =
        GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampA;
      real_T timeStampB =
        GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampB;
      real_T* lastTime =
        &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampA;
      real_T* lastU =
        &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime =
            &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampB;
          lastU =
            &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime =
            &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampB;
          lastU =
            &GenerativeArmModelWithRestor_DW.Derivative1_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = GenerativeArmModelWithRestor_M->Timing.t[0];
      *lastU++ = rtb_Derivative;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(GenerativeArmModelWithRestor_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(GenerativeArmModelWithRestor_M)!=-1) &&
          !((rtmGetTFinal(GenerativeArmModelWithRestor_M)-
             (((GenerativeArmModelWithRestor_M->Timing.clockTick1+
                GenerativeArmModelWithRestor_M->Timing.clockTickH1* 4294967296.0))
              * 0.001)) > (((GenerativeArmModelWithRestor_M->Timing.clockTick1+
                             GenerativeArmModelWithRestor_M->Timing.clockTickH1*
              4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(GenerativeArmModelWithRestor_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&GenerativeArmModelWithRestor_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++GenerativeArmModelWithRestor_M->Timing.clockTick0)) {
      ++GenerativeArmModelWithRestor_M->Timing.clockTickH0;
    }

    GenerativeArmModelWithRestor_M->Timing.t[0] = rtsiGetSolverStopTime
      (&GenerativeArmModelWithRestor_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      GenerativeArmModelWithRestor_M->Timing.clockTick1++;
      if (!GenerativeArmModelWithRestor_M->Timing.clockTick1) {
        GenerativeArmModelWithRestor_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void GenerativeArmModelWithRestoring_derivatives(void)
{
  XDot_GenerativeArmModelWithRe_T *_rtXdot;
  _rtXdot = ((XDot_GenerativeArmModelWithRe_T *)
             GenerativeArmModelWithRestor_M->ModelData.derivs);

  /* Derivatives for SecondOrderIntegrator: '<Root>/Integrator, Second-Order1' */
  switch (GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE) {
   case 0:
    _rtXdot->IntegratorSecondOrder1_CSTATE[0] =
      GenerativeArmModelWithRestori_X.IntegratorSecondOrder1_CSTATE[1];
    _rtXdot->IntegratorSecondOrder1_CSTATE[1] =
      GenerativeArmModelWithRestori_B.u_l;
    break;

   case 1:
    _rtXdot->IntegratorSecondOrder1_CSTATE[0] = 0.0;
    _rtXdot->IntegratorSecondOrder1_CSTATE[1] = 0.0;
    break;

   case 2:
    _rtXdot->IntegratorSecondOrder1_CSTATE[0] = 0.0;
    _rtXdot->IntegratorSecondOrder1_CSTATE[1] = 0.0;
    break;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<Root>/Integrator, Second-Order1' */
  /* Derivatives for ModelReference: '<Root>/Model' */
  ArmModelVersion2_Deriv(&(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtb),
    &(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtdw),
    &(GenerativeArmModelWithRestori_X.Model_CSTATE),
    &(((XDot_GenerativeArmModelWithRe_T *)
       GenerativeArmModelWithRestor_M->ModelData.derivs)->Model_CSTATE));
}

/* Model initialize function */
void GenerativeArmModelWithRestoring_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  GenerativeArmModelWithRestori_P.IntegratorSecondOrder1_UpperLim = rtInf;

  /* initialize real-time model */
  (void) memset((void *)GenerativeArmModelWithRestor_M, 0,
                sizeof(RT_MODEL_GenerativeArmModelWi_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&GenerativeArmModelWithRestor_M->solverInfo,
                          &GenerativeArmModelWithRestor_M->Timing.simTimeStep);
    rtsiSetTPtr(&GenerativeArmModelWithRestor_M->solverInfo, &rtmGetTPtr
                (GenerativeArmModelWithRestor_M));
    rtsiSetStepSizePtr(&GenerativeArmModelWithRestor_M->solverInfo,
                       &GenerativeArmModelWithRestor_M->Timing.stepSize0);
    rtsiSetdXPtr(&GenerativeArmModelWithRestor_M->solverInfo,
                 &GenerativeArmModelWithRestor_M->ModelData.derivs);
    rtsiSetContStatesPtr(&GenerativeArmModelWithRestor_M->solverInfo, (real_T **)
                         &GenerativeArmModelWithRestor_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&GenerativeArmModelWithRestor_M->solverInfo,
      &GenerativeArmModelWithRestor_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&GenerativeArmModelWithRestor_M->solverInfo,
                          (&rtmGetErrorStatus(GenerativeArmModelWithRestor_M)));
    rtsiSetRTModelPtr(&GenerativeArmModelWithRestor_M->solverInfo,
                      GenerativeArmModelWithRestor_M);
  }

  rtsiSetSimTimeStep(&GenerativeArmModelWithRestor_M->solverInfo,
                     MAJOR_TIME_STEP);
  GenerativeArmModelWithRestor_M->ModelData.intgData.y =
    GenerativeArmModelWithRestor_M->ModelData.odeY;
  GenerativeArmModelWithRestor_M->ModelData.intgData.f[0] =
    GenerativeArmModelWithRestor_M->ModelData.odeF[0];
  GenerativeArmModelWithRestor_M->ModelData.intgData.f[1] =
    GenerativeArmModelWithRestor_M->ModelData.odeF[1];
  GenerativeArmModelWithRestor_M->ModelData.intgData.f[2] =
    GenerativeArmModelWithRestor_M->ModelData.odeF[2];
  GenerativeArmModelWithRestor_M->ModelData.contStates =
    ((X_GenerativeArmModelWithResto_T *) &GenerativeArmModelWithRestori_X);
  rtsiSetSolverData(&GenerativeArmModelWithRestor_M->solverInfo, (void *)
                    &GenerativeArmModelWithRestor_M->ModelData.intgData);
  rtsiSetSolverName(&GenerativeArmModelWithRestor_M->solverInfo,"ode3");
  rtmSetTPtr(GenerativeArmModelWithRestor_M,
             &GenerativeArmModelWithRestor_M->Timing.tArray[0]);
  rtmSetTFinal(GenerativeArmModelWithRestor_M, 6.0);
  GenerativeArmModelWithRestor_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    GenerativeArmModelWithRestor_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(GenerativeArmModelWithRestor_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(GenerativeArmModelWithRestor_M->rtwLogInfo, (NULL));
    rtliSetLogT(GenerativeArmModelWithRestor_M->rtwLogInfo, "tout");
    rtliSetLogX(GenerativeArmModelWithRestor_M->rtwLogInfo, "");
    rtliSetLogXFinal(GenerativeArmModelWithRestor_M->rtwLogInfo, "");
    rtliSetSigLog(GenerativeArmModelWithRestor_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(GenerativeArmModelWithRestor_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(GenerativeArmModelWithRestor_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(GenerativeArmModelWithRestor_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(GenerativeArmModelWithRestor_M->rtwLogInfo, 1);
    rtliSetLogY(GenerativeArmModelWithRestor_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(GenerativeArmModelWithRestor_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(GenerativeArmModelWithRestor_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &GenerativeArmModelWithRestori_B), 0,
                sizeof(B_GenerativeArmModelWithResto_T));

  /* states (continuous) */
  {
    (void) memset((void *)&GenerativeArmModelWithRestori_X, 0,
                  sizeof(X_GenerativeArmModelWithResto_T));
  }

  /* states (dwork) */
  (void) memset((void *)&GenerativeArmModelWithRestor_DW, 0,
                sizeof(DW_GenerativeArmModelWithRest_T));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model' */
  ArmModelVersion2_initialize(rtmGetErrorStatusPointer
    (GenerativeArmModelWithRestor_M), rtmGetStopRequestedPtr
    (GenerativeArmModelWithRestor_M),
    &(GenerativeArmModelWithRestor_M->solverInfo),
    &(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtm),
    &(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtb),
    &(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtdw));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(GenerativeArmModelWithRestor_M->rtwLogInfo,
    0.0, rtmGetTFinal(GenerativeArmModelWithRestor_M),
    GenerativeArmModelWithRestor_M->Timing.stepSize0, (&rtmGetErrorStatus
    (GenerativeArmModelWithRestor_M)));

  /* Start for InitialCondition: '<Root>/Starting angle  (rad)' */
  GenerativeArmModelWithRestori_B.Startinganglerad =
    GenerativeArmModelWithRestori_P.Startinganglerad_Value;
  GenerativeArmModelWithRestor_DW.Startinganglerad_FirstOutputTim = (rtMinusInf);

  /* Start for InitialCondition: '<Root>/Initial angular velocity rad//s ' */
  GenerativeArmModelWithRestor_DW.Initialangularvelocityrads_Firs = TRUE;

  /* Start for ModelReference: '<Root>/Model' */
  ArmModelVersion2_Start(&(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtdw));

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.001, 0.002, 0.003, 0.004, 0.005,
      0.006, 0.007, 0.008, 0.0090000000000000011, 0.01, 0.011, 0.012,
      0.013000000000000001, 0.014, 0.015, 0.016, 0.017, 0.018000000000000002,
      0.019, 0.02, 0.021, 0.022, 0.023, 0.024, 0.025, 0.026000000000000002,
      0.027, 0.028, 0.029, 0.03, 0.031, 0.032, 0.033, 0.034, 0.035,
      0.036000000000000004, 0.037, 0.038, 0.039, 0.04, 0.041, 0.042,
      0.043000000000000003, 0.044, 0.045, 0.046, 0.047, 0.048, 0.049, 0.05,
      0.051000000000000004, 0.052000000000000005, 0.053, 0.054, 0.055, 0.056,
      0.057, 0.058, 0.059000000000000004, 0.06, 0.061, 0.062, 0.063, 0.064,
      0.065, 0.066, 0.067, 0.068, 0.069, 0.07, 0.071000000000000008,
      0.072000000000000008, 0.073, 0.074, 0.075, 0.076, 0.077, 0.078, 0.079,
      0.08, 0.081, 0.082, 0.083, 0.084, 0.085, 0.086000000000000007,
      0.087000000000000008, 0.088, 0.089, 0.09, 0.091, 0.092, 0.093, 0.094,
      0.095, 0.096, 0.097, 0.098, 0.099, 0.1, 0.101, 0.10200000000000001,
      0.10300000000000001, 0.10400000000000001, 0.105, 0.106, 0.107, 0.108,
      0.109, 0.11, 0.111, 0.112, 0.113, 0.114, 0.115, 0.116, 0.117,
      0.11800000000000001, 0.11900000000000001, 0.12, 0.121, 0.122, 0.123, 0.124,
      0.125, 0.126, 0.127, 0.128, 0.129, 0.13, 0.131, 0.132, 0.133, 0.134, 0.135,
      0.136, 0.137, 0.138, 0.139, 0.14, 0.14100000000000001, 0.14200000000000002,
      0.14300000000000002, 0.14400000000000002, 0.145, 0.146, 0.147, 0.148,
      0.149, 0.15, 0.151, 0.152, 0.153, 0.154, 0.155, 0.156, 0.157, 0.158, 0.159,
      0.16, 0.161, 0.162, 0.163, 0.164, 0.165, 0.166, 0.167, 0.168, 0.169, 0.17,
      0.171, 0.17200000000000001, 0.17300000000000001, 0.17400000000000002,
      0.17500000000000002, 0.176, 0.177, 0.178, 0.179, 0.18, 0.181, 0.182, 0.183,
      0.184, 0.185, 0.186, 0.187, 0.188, 0.189, 0.19, 0.191, 0.192, 0.193, 0.194,
      0.195, 0.196, 0.197, 0.198, 0.199, 0.2, 0.201, 0.202, 0.203,
      0.20400000000000001, 0.20500000000000002, 0.20600000000000002,
      0.20700000000000002, 0.20800000000000002, 0.209, 0.21, 0.211, 0.212, 0.213,
      0.214, 0.215, 0.216, 0.217, 0.218, 0.219, 0.22, 0.221, 0.222, 0.223, 0.224,
      0.225, 0.226, 0.227, 0.228, 0.229, 0.23, 0.231, 0.232, 0.233, 0.234,
      0.23500000000000001, 0.23600000000000002, 0.23700000000000002,
      0.23800000000000002, 0.23900000000000002, 0.24, 0.241, 0.242, 0.243, 0.244,
      0.245, 0.246, 0.247, 0.248, 0.249, 0.25, 0.251, 0.252, 0.253, 0.254, 0.255,
      0.256, 0.257, 0.258, 0.259, 0.26, 0.261, 0.262, 0.263, 0.264, 0.265, 0.266,
      0.267, 0.268, 0.269, 0.27, 0.271, 0.272, 0.273, 0.274, 0.275, 0.276, 0.277,
      0.278, 0.279, 0.28, 0.281, 0.28200000000000003, 0.28300000000000003,
      0.28400000000000003, 0.28500000000000003, 0.28600000000000003,
      0.28700000000000003, 0.28800000000000003, 0.289, 0.29, 0.291, 0.292, 0.293,
      0.294, 0.295, 0.296, 0.297, 0.298, 0.299, 0.3, 0.301, 0.302, 0.303, 0.304,
      0.305, 0.306, 0.307, 0.308, 0.309, 0.31, 0.311, 0.312, 0.313, 0.314, 0.315,
      0.316, 0.317, 0.318, 0.319, 0.32, 0.321, 0.322, 0.323, 0.324, 0.325, 0.326,
      0.327, 0.328, 0.329, 0.33, 0.331, 0.332, 0.333, 0.334, 0.335, 0.336, 0.337,
      0.338, 0.339, 0.34, 0.341, 0.342, 0.343, 0.34400000000000003,
      0.34500000000000003, 0.34600000000000003, 0.34700000000000003,
      0.34800000000000003, 0.34900000000000003, 0.35000000000000003,
      0.35100000000000003, 0.352, 0.353, 0.354, 0.355, 0.356, 0.357, 0.358,
      0.359, 0.36, 0.361, 0.362, 0.363, 0.364, 0.365, 0.366, 0.367, 0.368, 0.369,
      0.37, 0.371, 0.372, 0.373, 0.374, 0.375, 0.376, 0.377, 0.378, 0.379, 0.38,
      0.381, 0.382, 0.383, 0.384, 0.385, 0.386, 0.387, 0.388, 0.389, 0.39, 0.391,
      0.392, 0.393, 0.394, 0.395, 0.396, 0.397, 0.398, 0.399, 0.4, 0.401, 0.402,
      0.403, 0.404, 0.405, 0.406, 0.40700000000000003, 0.40800000000000003,
      0.40900000000000003, 0.41000000000000003, 0.41100000000000003,
      0.41200000000000003, 0.41300000000000003, 0.41400000000000003,
      0.41500000000000004, 0.41600000000000004, 0.417, 0.418, 0.419, 0.42, 0.421,
      0.422, 0.423, 0.424, 0.425, 0.426, 0.427, 0.428, 0.429, 0.43, 0.431, 0.432,
      0.433, 0.434, 0.435, 0.436, 0.437, 0.438, 0.439, 0.44, 0.441, 0.442, 0.443,
      0.444, 0.445, 0.446, 0.447, 0.448, 0.449, 0.45, 0.451, 0.452, 0.453, 0.454,
      0.455, 0.456, 0.457, 0.458, 0.459, 0.46, 0.461, 0.462, 0.463, 0.464, 0.465,
      0.466, 0.467, 0.468, 0.46900000000000003, 0.47000000000000003,
      0.47100000000000003, 0.47200000000000003, 0.47300000000000003,
      0.47400000000000003, 0.47500000000000003, 0.47600000000000003,
      0.47700000000000004, 0.47800000000000004, 0.47900000000000004, 0.48, 0.481,
      0.482, 0.483, 0.484, 0.485, 0.486, 0.487, 0.488, 0.489, 0.49, 0.491, 0.492,
      0.493, 0.494, 0.495, 0.496, 0.497, 0.498, 0.499, 0.5, 0.501, 0.502, 0.503,
      0.504, 0.505, 0.506, 0.507, 0.508, 0.509, 0.51, 0.511, 0.512, 0.513, 0.514,
      0.515, 0.516, 0.517, 0.518, 0.519, 0.52, 0.521, 0.522, 0.523, 0.524, 0.525,
      0.526, 0.527, 0.528, 0.529, 0.53, 0.531, 0.532, 0.533, 0.534, 0.535, 0.536,
      0.537, 0.538, 0.539, 0.54, 0.541, 0.542, 0.543, 0.544, 0.545, 0.546, 0.547,
      0.548, 0.549, 0.55, 0.551, 0.552, 0.553, 0.554, 0.555, 0.556, 0.557, 0.558,
      0.559, 0.56, 0.561, 0.562, 0.56300000000000006, 0.56400000000000006,
      0.56500000000000006, 0.56600000000000006, 0.56700000000000006,
      0.56800000000000006, 0.56900000000000006, 0.57000000000000006,
      0.57100000000000006, 0.57200000000000006, 0.57300000000000006,
      0.57400000000000007, 0.57500000000000007, 0.57600000000000007, 0.577,
      0.578, 0.579, 0.58, 0.581, 0.582, 0.583, 0.584, 0.585, 0.586, 0.587, 0.588,
      0.589, 0.59, 0.591, 0.592, 0.593, 0.594, 0.595, 0.596, 0.597, 0.598, 0.599,
      0.6, 0.601, 0.602, 0.603, 0.604, 0.605, 0.606, 0.607, 0.608, 0.609, 0.61,
      0.611, 0.612, 0.613, 0.614, 0.615, 0.616, 0.617, 0.618, 0.619, 0.62, 0.621,
      0.622, 0.623, 0.624, 0.625, 0.626, 0.627, 0.628, 0.629, 0.63, 0.631, 0.632,
      0.633, 0.634, 0.635, 0.636, 0.637, 0.638, 0.639, 0.64, 0.641, 0.642, 0.643,
      0.644, 0.645, 0.646, 0.647, 0.648, 0.649, 0.65, 0.651, 0.652, 0.653, 0.654,
      0.655, 0.656, 0.657, 0.658, 0.659, 0.66, 0.661, 0.662, 0.663, 0.664, 0.665,
      0.666, 0.667, 0.668, 0.669, 0.67, 0.671, 0.672, 0.673, 0.674, 0.675, 0.676,
      0.677, 0.678, 0.679, 0.68, 0.681, 0.682, 0.683, 0.684, 0.685, 0.686, 0.687,
      0.68800000000000006, 0.68900000000000006, 0.69000000000000006,
      0.69100000000000006, 0.69200000000000006, 0.69300000000000006,
      0.69400000000000006, 0.69500000000000006, 0.69600000000000006,
      0.69700000000000006, 0.69800000000000006, 0.69900000000000007,
      0.70000000000000007, 0.70100000000000007, 0.70200000000000007,
      0.70300000000000007, 0.704, 0.705, 0.706, 0.707, 0.708, 0.709, 0.71, 0.711,
      0.712, 0.713, 0.714, 0.715, 0.716, 0.717, 0.718, 0.719, 0.72, 0.721, 0.722,
      0.723, 0.724, 0.725, 0.726, 0.727, 0.728, 0.729, 0.73, 0.731, 0.732, 0.733,
      0.734, 0.735, 0.736, 0.737, 0.738, 0.739, 0.74, 0.741, 0.742, 0.743, 0.744,
      0.745, 0.746, 0.747, 0.748, 0.749, 0.75, 0.751, 0.752, 0.753, 0.754, 0.755,
      0.756, 0.757, 0.758, 0.759, 0.76, 0.761, 0.762, 0.763, 0.764, 0.765, 0.766,
      0.767, 0.768, 0.769, 0.77, 0.771, 0.772, 0.773, 0.774, 0.775, 0.776, 0.777,
      0.778, 0.779, 0.78, 0.781, 0.782, 0.783, 0.784, 0.785, 0.786, 0.787, 0.788,
      0.789, 0.79, 0.791, 0.792, 0.793, 0.794, 0.795, 0.796, 0.797, 0.798, 0.799,
      0.8, 0.801, 0.802, 0.803, 0.804, 0.805, 0.806, 0.807, 0.808, 0.809, 0.81,
      0.811, 0.812, 0.81300000000000006, 0.81400000000000006,
      0.81500000000000006, 0.81600000000000006, 0.81700000000000006,
      0.81800000000000006, 0.81900000000000006, 0.82000000000000006,
      0.82100000000000006, 0.82200000000000006, 0.82300000000000006,
      0.82400000000000007, 0.82500000000000007, 0.82600000000000007,
      0.82700000000000007, 0.82800000000000007, 0.82900000000000007,
      0.83000000000000007, 0.83100000000000007, 0.83200000000000007, 0.833,
      0.834, 0.835, 0.836, 0.837, 0.838, 0.839, 0.84, 0.841, 0.842, 0.843, 0.844,
      0.845, 0.846, 0.847, 0.848, 0.849, 0.85, 0.851, 0.852, 0.853, 0.854, 0.855,
      0.856, 0.857, 0.858, 0.859, 0.86, 0.861, 0.862, 0.863, 0.864, 0.865, 0.866,
      0.867, 0.868, 0.869, 0.87, 0.871, 0.872, 0.873, 0.874, 0.875, 0.876, 0.877,
      0.878, 0.879, 0.88, 0.881, 0.882, 0.883, 0.884, 0.885, 0.886, 0.887, 0.888,
      0.889, 0.89, 0.891, 0.892, 0.893, 0.894, 0.895, 0.896, 0.897, 0.898, 0.899,
      0.9, 0.901, 0.902, 0.903, 0.904, 0.905, 0.906, 0.907, 0.908, 0.909, 0.91,
      0.911, 0.912, 0.913, 0.914, 0.915, 0.916, 0.917, 0.918, 0.919, 0.92, 0.921,
      0.922, 0.923, 0.924, 0.925, 0.926, 0.927, 0.928, 0.929, 0.93, 0.931, 0.932,
      0.933, 0.934, 0.935, 0.936, 0.937, 0.93800000000000006,
      0.93900000000000006, 0.94000000000000006, 0.94100000000000006,
      0.94200000000000006, 0.94300000000000006, 0.94400000000000006,
      0.94500000000000006, 0.94600000000000006, 0.94700000000000006,
      0.94800000000000006, 0.94900000000000007, 0.95000000000000007,
      0.95100000000000007, 0.95200000000000007, 0.95300000000000007,
      0.95400000000000007, 0.95500000000000007, 0.95600000000000007,
      0.95700000000000007, 0.95800000000000007, 0.95900000000000007, 0.96, 0.961,
      0.962, 0.963, 0.964, 0.965, 0.966, 0.967, 0.968, 0.969, 0.97, 0.971, 0.972,
      0.973, 0.974, 0.975, 0.976, 0.977, 0.978, 0.979, 0.98, 0.981, 0.982, 0.983,
      0.984, 0.985, 0.986, 0.987, 0.988, 0.989, 0.99, 0.991, 0.992, 0.993, 0.994,
      0.995, 0.996, 0.997, 0.998, 0.999, 1.0, 1.0010000000000001, 1.002,
      1.0030000000000001, 1.004, 1.0050000000000001, 1.006, 1.0070000000000001,
      1.008, 1.0090000000000001, 1.01, 1.0110000000000001, 1.012,
      1.0130000000000001, 1.014, 1.0150000000000001, 1.016, 1.0170000000000001,
      1.018, 1.0190000000000001, 1.02, 1.0210000000000001, 1.022,
      1.0230000000000001, 1.024, 1.025, 1.026, 1.027, 1.028, 1.029, 1.03, 1.031,
      1.032, 1.033, 1.034, 1.035, 1.036, 1.037, 1.038, 1.039, 1.04, 1.041, 1.042,
      1.043, 1.044, 1.045, 1.046, 1.047, 1.048, 1.049, 1.05, 1.051, 1.052, 1.053,
      1.054, 1.055, 1.056, 1.057, 1.058, 1.059, 1.06, 1.061, 1.062, 1.063, 1.064,
      1.065, 1.066, 1.067, 1.068, 1.069, 1.07, 1.071, 1.072, 1.073, 1.074, 1.075,
      1.076, 1.077, 1.078, 1.079, 1.08, 1.081, 1.082, 1.083, 1.084, 1.085, 1.086,
      1.087, 1.088, 1.089, 1.09, 1.091, 1.092, 1.093, 1.094, 1.095, 1.096, 1.097,
      1.098, 1.099, 1.1, 1.101, 1.102, 1.103, 1.104, 1.105, 1.106, 1.107, 1.108,
      1.109, 1.11, 1.111, 1.112, 1.113, 1.114, 1.115, 1.116, 1.117, 1.118, 1.119,
      1.12, 1.121, 1.122, 1.123, 1.124, 1.125, 1.1260000000000001, 1.127,
      1.1280000000000001, 1.129, 1.1300000000000001, 1.131, 1.1320000000000001,
      1.133, 1.1340000000000001, 1.135, 1.1360000000000001, 1.137,
      1.1380000000000001, 1.139, 1.1400000000000001, 1.141, 1.1420000000000001,
      1.143, 1.1440000000000001, 1.145, 1.1460000000000001, 1.147,
      1.1480000000000001, 1.149, 1.1500000000000001, 1.151, 1.1520000000000001,
      1.153, 1.154, 1.155, 1.156, 1.157, 1.158, 1.159, 1.16, 1.161, 1.162, 1.163,
      1.164, 1.165, 1.166, 1.167, 1.168, 1.169, 1.17, 1.171, 1.172, 1.173, 1.174,
      1.175, 1.176, 1.177, 1.178, 1.179, 1.18, 1.181, 1.182, 1.183, 1.184, 1.185,
      1.186, 1.187, 1.188, 1.189, 1.19, 1.191, 1.192, 1.193, 1.194, 1.195, 1.196,
      1.197, 1.198, 1.199, 1.2, 1.201, 1.202, 1.203, 1.204, 1.205, 1.206, 1.207,
      1.208, 1.209, 1.21, 1.211, 1.212, 1.213, 1.214, 1.215, 1.216, 1.217, 1.218,
      1.219, 1.22, 1.221, 1.222, 1.223, 1.224, 1.225, 1.226, 1.227, 1.228, 1.229,
      1.23, 1.231, 1.232, 1.233, 1.234, 1.235, 1.236, 1.237, 1.238, 1.239, 1.24,
      1.241, 1.242, 1.243, 1.244, 1.245, 1.246, 1.247, 1.248, 1.249, 1.25,
      1.2510000000000001, 1.252, 1.2530000000000001, 1.254, 1.2550000000000001,
      1.256, 1.2570000000000001, 1.258, 1.2590000000000001, 1.26,
      1.2610000000000001, 1.262, 1.2630000000000001, 1.264, 1.2650000000000001,
      1.266, 1.2670000000000001, 1.268, 1.2690000000000001, 1.27,
      1.2710000000000001, 1.272, 1.2730000000000001, 1.274, 1.2750000000000001,
      1.276, 1.2770000000000001, 1.278, 1.2790000000000001, 1.28, 1.281, 1.282,
      1.283, 1.284, 1.285, 1.286, 1.287, 1.288, 1.289, 1.29, 1.291, 1.292, 1.293,
      1.294, 1.295, 1.296, 1.297, 1.298, 1.299, 1.3, 1.301, 1.302, 1.303, 1.304,
      1.305, 1.306, 1.307, 1.308, 1.309, 1.31, 1.311, 1.312, 1.313, 1.314, 1.315,
      1.316, 1.317, 1.318, 1.319, 1.32, 1.321, 1.322, 1.323, 1.324, 1.325, 1.326,
      1.327, 1.328, 1.329, 1.33, 1.331, 1.332, 1.333, 1.334, 1.335, 1.336, 1.337,
      1.338, 1.339, 1.34, 1.341, 1.342, 1.343, 1.344, 1.345, 1.346, 1.347, 1.348,
      1.349, 1.35, 1.351, 1.352, 1.353, 1.354, 1.355, 1.356, 1.357, 1.358, 1.359,
      1.36, 1.361, 1.362, 1.363, 1.364, 1.365, 1.366, 1.367, 1.368, 1.369, 1.37,
      1.371, 1.372, 1.373, 1.374, 1.375, 1.3760000000000001, 1.377,
      1.3780000000000001, 1.379, 1.3800000000000001, 1.381, 1.3820000000000001,
      1.383, 1.3840000000000001, 1.385, 1.3860000000000001, 1.387,
      1.3880000000000001, 1.389, 1.3900000000000001, 1.391, 1.3920000000000001,
      1.393, 1.3940000000000001, 1.395, 1.3960000000000001, 1.397,
      1.3980000000000001, 1.399, 1.4000000000000001, 1.401, 1.4020000000000001,
      1.403, 1.4040000000000001, 1.405, 1.4060000000000001, 1.407, 1.408, 1.409,
      1.41, 1.411, 1.412, 1.413, 1.414, 1.415, 1.416, 1.417, 1.418, 1.419, 1.42,
      1.421, 1.422, 1.423, 1.424, 1.425, 1.426, 1.427, 1.428, 1.429, 1.43, 1.431,
      1.432, 1.433, 1.434, 1.435, 1.436, 1.437, 1.438, 1.439, 1.44, 1.441, 1.442,
      1.443, 1.444, 1.445, 1.446, 1.447, 1.448, 1.449, 1.45, 1.451, 1.452, 1.453,
      1.454, 1.455, 1.456, 1.457, 1.458, 1.459, 1.46, 1.461, 1.462, 1.463, 1.464,
      1.465, 1.466, 1.467, 1.468, 1.469, 1.47, 1.471, 1.472, 1.473, 1.474, 1.475,
      1.476, 1.477, 1.478, 1.479, 1.48, 1.481, 1.482, 1.483, 1.484, 1.485, 1.486,
      1.487, 1.488, 1.489, 1.49, 1.491, 1.492, 1.493, 1.494, 1.495, 1.496, 1.497,
      1.498, 1.499, 1.5, 1.5010000000000001, 1.502, 1.5030000000000001, 1.504,
      1.5050000000000001, 1.506, 1.5070000000000001, 1.508, 1.5090000000000001,
      1.51, 1.5110000000000001, 1.512, 1.5130000000000001, 1.514,
      1.5150000000000001, 1.516, 1.5170000000000001, 1.518, 1.5190000000000001,
      1.52, 1.5210000000000001, 1.522, 1.5230000000000001, 1.524,
      1.5250000000000001, 1.526, 1.5270000000000001, 1.528, 1.5290000000000001,
      1.53, 1.5310000000000001, 1.532, 1.5330000000000001, 1.534,
      1.5350000000000001, 1.536, 1.537, 1.538, 1.539, 1.54, 1.541, 1.542, 1.543,
      1.544, 1.545, 1.546, 1.547, 1.548, 1.549, 1.55, 1.551, 1.552, 1.553, 1.554,
      1.555, 1.556, 1.557, 1.558, 1.559, 1.56, 1.561, 1.562, 1.563, 1.564, 1.565,
      1.566, 1.567, 1.568, 1.569, 1.57, 1.571, 1.572, 1.573, 1.574, 1.575, 1.576,
      1.577, 1.578, 1.579, 1.58, 1.581, 1.582, 1.583, 1.584, 1.585, 1.586, 1.587,
      1.588, 1.589, 1.59, 1.591, 1.592, 1.593, 1.594, 1.595, 1.596, 1.597, 1.598,
      1.599, 1.6, 1.601, 1.602, 1.603, 1.604, 1.605, 1.606, 1.607, 1.608, 1.609,
      1.61, 1.611, 1.612, 1.613, 1.614, 1.615, 1.616, 1.617, 1.618, 1.619, 1.62,
      1.621, 1.622, 1.623, 1.624, 1.625, 1.6260000000000001, 1.627,
      1.6280000000000001, 1.629, 1.6300000000000001, 1.631, 1.6320000000000001,
      1.633, 1.6340000000000001, 1.635, 1.6360000000000001, 1.637,
      1.6380000000000001, 1.639, 1.6400000000000001, 1.641, 1.6420000000000001,
      1.643, 1.6440000000000001, 1.645, 1.6460000000000001, 1.647,
      1.6480000000000001, 1.649, 1.6500000000000001, 1.651, 1.6520000000000001,
      1.653, 1.6540000000000001, 1.655, 1.6560000000000001, 1.657,
      1.6580000000000001, 1.659, 1.6600000000000001, 1.661, 1.6620000000000001,
      1.663, 1.6640000000000001, 1.665, 1.666, 1.667, 1.668, 1.669, 1.67, 1.671,
      1.672, 1.673, 1.674, 1.675, 1.676, 1.677, 1.678, 1.679, 1.68, 1.681, 1.682,
      1.683, 1.684, 1.685, 1.686, 1.687, 1.688, 1.689, 1.69, 1.691, 1.692, 1.693,
      1.694, 1.695, 1.696, 1.697, 1.698, 1.699, 1.7, 1.701, 1.702, 1.703, 1.704,
      1.705, 1.706, 1.707, 1.708, 1.709, 1.71, 1.711, 1.712, 1.713, 1.714, 1.715,
      1.716, 1.717, 1.718, 1.719, 1.72, 1.721, 1.722, 1.723, 1.724, 1.725, 1.726,
      1.727, 1.728, 1.729, 1.73, 1.731, 1.732, 1.733, 1.734, 1.735, 1.736, 1.737,
      1.738, 1.739, 1.74, 1.741, 1.742, 1.743, 1.744, 1.745, 1.746, 1.747, 1.748,
      1.749, 1.75, 1.7510000000000001, 1.752, 1.7530000000000001, 1.754,
      1.7550000000000001, 1.756, 1.7570000000000001, 1.758, 1.7590000000000001,
      1.76, 1.7610000000000001, 1.762, 1.7630000000000001, 1.764,
      1.7650000000000001, 1.766, 1.7670000000000001, 1.768, 1.7690000000000001,
      1.77, 1.7710000000000001, 1.772, 1.7730000000000001, 1.774,
      1.7750000000000001, 1.776, 1.7770000000000001, 1.778, 1.7790000000000001,
      1.78, 1.7810000000000001, 1.782, 1.7830000000000001, 1.784,
      1.7850000000000001, 1.786, 1.7870000000000001, 1.788, 1.7890000000000001,
      1.79, 1.7910000000000001, 1.792, 1.793, 1.794, 1.795, 1.796, 1.797, 1.798,
      1.799, 1.8, 1.801, 1.802, 1.803, 1.804, 1.805, 1.806, 1.807, 1.808, 1.809,
      1.81, 1.811, 1.812, 1.813, 1.814, 1.815, 1.816, 1.817, 1.818, 1.819, 1.82,
      1.821, 1.822, 1.823, 1.824, 1.825, 1.826, 1.827, 1.828, 1.829, 1.83, 1.831,
      1.832, 1.833, 1.834, 1.835, 1.836, 1.837, 1.838, 1.839, 1.84, 1.841, 1.842,
      1.843, 1.844, 1.845, 1.846, 1.847, 1.848, 1.849, 1.85, 1.851, 1.852, 1.853,
      1.854, 1.855, 1.856, 1.857, 1.858, 1.859, 1.86, 1.861, 1.862, 1.863, 1.864,
      1.865, 1.866, 1.867, 1.868, 1.869, 1.87, 1.871, 1.872, 1.873, 1.874, 1.875,
      1.8760000000000001, 1.877, 1.8780000000000001, 1.879, 1.8800000000000001,
      1.881, 1.8820000000000001, 1.883, 1.8840000000000001, 1.885,
      1.8860000000000001, 1.887, 1.8880000000000001, 1.889, 1.8900000000000001,
      1.891, 1.8920000000000001, 1.893, 1.8940000000000001, 1.895,
      1.8960000000000001, 1.897, 1.8980000000000001, 1.899, 1.9000000000000001,
      1.901, 1.9020000000000001, 1.903, 1.9040000000000001, 1.905,
      1.9060000000000001, 1.907, 1.9080000000000001, 1.909, 1.9100000000000001,
      1.911, 1.9120000000000001, 1.913, 1.9140000000000001, 1.915,
      1.9160000000000001, 1.917, 1.9180000000000001, 1.919, 1.92, 1.921, 1.922,
      1.923, 1.924, 1.925, 1.926, 1.927, 1.928, 1.929, 1.93, 1.931, 1.932, 1.933,
      1.934, 1.935, 1.936, 1.937, 1.938, 1.939, 1.94, 1.941, 1.942, 1.943, 1.944,
      1.945, 1.946, 1.947, 1.948, 1.949, 1.95, 1.951, 1.952, 1.953, 1.954, 1.955,
      1.956, 1.957, 1.958, 1.959, 1.96, 1.961, 1.962, 1.963, 1.964, 1.965, 1.966,
      1.967, 1.968, 1.969, 1.97, 1.971, 1.972, 1.973, 1.974, 1.975, 1.976, 1.977,
      1.978, 1.979, 1.98, 1.981, 1.982, 1.983, 1.984, 1.985, 1.986, 1.987, 1.988,
      1.989, 1.99, 1.991, 1.992, 1.993, 1.994, 1.995, 1.996, 1.997, 1.998, 1.999,
      2.0, 2.001, 2.0020000000000002, 2.003, 2.004, 2.005, 2.0060000000000002,
      2.007, 2.008, 2.009, 2.0100000000000002, 2.011, 2.012, 2.013,
      2.0140000000000002, 2.015, 2.016, 2.017, 2.0180000000000002, 2.019, 2.02,
      2.021, 2.0220000000000002, 2.023, 2.024, 2.025, 2.0260000000000002, 2.027,
      2.028, 2.029, 2.0300000000000002, 2.031, 2.032, 2.033, 2.0340000000000003,
      2.035, 2.036, 2.037, 2.0380000000000003, 2.039, 2.04, 2.041,
      2.0420000000000003, 2.043, 2.044, 2.045, 2.0460000000000003, 2.047, 2.048,
      2.049, 2.05, 2.051, 2.052, 2.053, 2.054, 2.055, 2.056, 2.057, 2.058, 2.059,
      2.06, 2.061, 2.062, 2.063, 2.064, 2.065, 2.066, 2.067, 2.068, 2.069, 2.07,
      2.071, 2.072, 2.073, 2.074, 2.075, 2.076, 2.077, 2.078, 2.079, 2.08, 2.081,
      2.082, 2.083, 2.084, 2.085, 2.086, 2.087, 2.088, 2.089, 2.09, 2.091, 2.092,
      2.093, 2.094, 2.095, 2.096, 2.097, 2.098, 2.099, 2.1, 2.101, 2.102, 2.103,
      2.104, 2.105, 2.106, 2.107, 2.108, 2.109, 2.11, 2.111, 2.112, 2.113, 2.114,
      2.115, 2.116, 2.117, 2.118, 2.119, 2.12, 2.121, 2.122, 2.123, 2.124, 2.125,
      2.126, 2.1270000000000002, 2.128, 2.129, 2.13, 2.1310000000000002, 2.132,
      2.133, 2.134, 2.1350000000000002, 2.136, 2.137, 2.138, 2.1390000000000002,
      2.14, 2.141, 2.142, 2.1430000000000002, 2.144, 2.145, 2.146,
      2.1470000000000002, 2.148, 2.149, 2.15, 2.1510000000000002, 2.152, 2.153,
      2.154, 2.1550000000000002, 2.156, 2.157, 2.158, 2.1590000000000003, 2.16,
      2.161, 2.162, 2.1630000000000003, 2.164, 2.165, 2.166, 2.1670000000000003,
      2.168, 2.169, 2.17, 2.1710000000000003, 2.172, 2.173, 2.174,
      2.1750000000000003, 2.176, 2.177, 2.178, 2.179, 2.18, 2.181, 2.182, 2.183,
      2.184, 2.185, 2.186, 2.187, 2.188, 2.189, 2.19, 2.191, 2.192, 2.193, 2.194,
      2.195, 2.196, 2.197, 2.198, 2.199, 2.2, 2.201, 2.202, 2.203, 2.204, 2.205,
      2.206, 2.207, 2.208, 2.209, 2.21, 2.211, 2.212, 2.213, 2.214, 2.215, 2.216,
      2.217, 2.218, 2.219, 2.22, 2.221, 2.222, 2.223, 2.224, 2.225, 2.226, 2.227,
      2.228, 2.229, 2.23, 2.231, 2.232, 2.233, 2.234, 2.235, 2.236, 2.237, 2.238,
      2.239, 2.24, 2.241, 2.242, 2.243, 2.244, 2.245, 2.246, 2.247, 2.248, 2.249,
      2.25, 2.251, 2.2520000000000002, 2.253, 2.254, 2.255, 2.2560000000000002,
      2.257, 2.258, 2.259, 2.2600000000000002, 2.261, 2.262, 2.263,
      2.2640000000000002, 2.265, 2.266, 2.267, 2.2680000000000002, 2.269, 2.27,
      2.271, 2.2720000000000002, 2.273, 2.274, 2.275, 2.2760000000000002, 2.277,
      2.278, 2.279, 2.2800000000000002, 2.281, 2.282, 2.283, 2.2840000000000003,
      2.285, 2.286, 2.287, 2.2880000000000003, 2.289, 2.29, 2.291,
      2.2920000000000003, 2.293, 2.294, 2.295, 2.2960000000000003, 2.297, 2.298,
      2.299, 2.3000000000000003, 2.301, 2.302, 2.303, 2.3040000000000003, 2.305,
      2.306, 2.307, 2.308, 2.309, 2.31, 2.311, 2.312, 2.313, 2.314, 2.315, 2.316,
      2.317, 2.318, 2.319, 2.32, 2.321, 2.322, 2.323, 2.324, 2.325, 2.326, 2.327,
      2.328, 2.329, 2.33, 2.331, 2.332, 2.333, 2.334, 2.335, 2.336, 2.337, 2.338,
      2.339, 2.34, 2.341, 2.342, 2.343, 2.344, 2.345, 2.346, 2.347, 2.348, 2.349,
      2.35, 2.351, 2.352, 2.353, 2.354, 2.355, 2.356, 2.357, 2.358, 2.359, 2.36,
      2.361, 2.362, 2.363, 2.364, 2.365, 2.366, 2.367, 2.368, 2.369, 2.37, 2.371,
      2.372, 2.373, 2.374, 2.375, 2.376, 2.3770000000000002, 2.378, 2.379, 2.38,
      2.3810000000000002, 2.382, 2.383, 2.384, 2.3850000000000002, 2.386, 2.387,
      2.388, 2.3890000000000002, 2.39, 2.391, 2.392, 2.3930000000000002, 2.394,
      2.395, 2.396, 2.3970000000000002, 2.398, 2.399, 2.4, 2.4010000000000002,
      2.402, 2.403, 2.404, 2.4050000000000002, 2.406, 2.407, 2.408,
      2.4090000000000003, 2.41, 2.411, 2.412, 2.4130000000000003, 2.414, 2.415,
      2.416, 2.4170000000000003, 2.418, 2.419, 2.42, 2.4210000000000003, 2.422,
      2.423, 2.424, 2.4250000000000003, 2.426, 2.427, 2.428, 2.4290000000000003,
      2.43, 2.431, 2.432, 2.433, 2.434, 2.435, 2.436, 2.437, 2.438, 2.439, 2.44,
      2.441, 2.442, 2.443, 2.444, 2.445, 2.446, 2.447, 2.448, 2.449, 2.45, 2.451,
      2.452, 2.453, 2.454, 2.455, 2.456, 2.457, 2.458, 2.459, 2.46, 2.461, 2.462,
      2.463, 2.464, 2.465, 2.466, 2.467, 2.468, 2.469, 2.47, 2.471, 2.472, 2.473,
      2.474, 2.475, 2.476, 2.477, 2.478, 2.479, 2.48, 2.481, 2.482, 2.483, 2.484,
      2.485, 2.486, 2.487, 2.488, 2.489, 2.49, 2.491, 2.492, 2.493, 2.494, 2.495,
      2.496, 2.497, 2.498, 2.499, 2.5, 2.501, 2.5020000000000002, 2.503, 2.504,
      2.505, 2.5060000000000002, 2.507, 2.508, 2.509, 2.5100000000000002, 2.511,
      2.512, 2.513, 2.5140000000000002, 2.515, 2.516, 2.517, 2.5180000000000002,
      2.519, 2.52, 2.521, 2.5220000000000002, 2.523, 2.524, 2.525,
      2.5260000000000002, 2.527, 2.528, 2.529, 2.5300000000000002, 2.531, 2.532,
      2.533, 2.5340000000000003, 2.535, 2.536, 2.537, 2.5380000000000003, 2.539,
      2.54, 2.541, 2.5420000000000003, 2.543, 2.544, 2.545, 2.5460000000000003,
      2.547, 2.548, 2.549, 2.5500000000000003, 2.551, 2.552, 2.553,
      2.5540000000000003, 2.555, 2.556, 2.557, 2.5580000000000003, 2.559, 2.56,
      2.561, 2.562, 2.563, 2.564, 2.565, 2.566, 2.567, 2.568, 2.569, 2.57, 2.571,
      2.572, 2.573, 2.574, 2.575, 2.576, 2.577, 2.578, 2.579, 2.58, 2.581, 2.582,
      2.583, 2.584, 2.585, 2.586, 2.587, 2.588, 2.589, 2.59, 2.591, 2.592, 2.593,
      2.594, 2.595, 2.596, 2.597, 2.598, 2.599, 2.6, 2.601, 2.602, 2.603, 2.604,
      2.605, 2.606, 2.607, 2.608, 2.609, 2.61, 2.611, 2.612, 2.613, 2.614, 2.615,
      2.616, 2.617, 2.618, 2.619, 2.62, 2.621, 2.622, 2.623, 2.624, 2.625, 2.626,
      2.6270000000000002, 2.628, 2.629, 2.63, 2.6310000000000002, 2.632, 2.633,
      2.634, 2.6350000000000002, 2.636, 2.637, 2.638, 2.6390000000000002, 2.64,
      2.641, 2.642, 2.6430000000000002, 2.644, 2.645, 2.646, 2.6470000000000002,
      2.648, 2.649, 2.65, 2.6510000000000002, 2.652, 2.653, 2.654,
      2.6550000000000002, 2.656, 2.657, 2.658, 2.6590000000000003, 2.66, 2.661,
      2.662, 2.6630000000000003, 2.664, 2.665, 2.666, 2.6670000000000003, 2.668,
      2.669, 2.67, 2.6710000000000003, 2.672, 2.673, 2.674, 2.6750000000000003,
      2.676, 2.677, 2.678, 2.6790000000000003, 2.68, 2.681, 2.682,
      2.6830000000000003, 2.684, 2.685, 2.686, 2.6870000000000003, 2.688, 2.689,
      2.69, 2.691, 2.692, 2.693, 2.694, 2.695, 2.696, 2.697, 2.698, 2.699, 2.7,
      2.701, 2.702, 2.703, 2.704, 2.705, 2.706, 2.707, 2.708, 2.709, 2.71, 2.711,
      2.712, 2.713, 2.714, 2.715, 2.716, 2.717, 2.718, 2.719, 2.72, 2.721, 2.722,
      2.723, 2.724, 2.725, 2.726, 2.727, 2.728, 2.729, 2.73, 2.731, 2.732, 2.733,
      2.734, 2.735, 2.736, 2.737, 2.738, 2.739, 2.74, 2.741, 2.742, 2.743, 2.744,
      2.745, 2.746, 2.747, 2.748, 2.749, 2.75, 2.751, 2.7520000000000002, 2.753,
      2.754, 2.755, 2.7560000000000002, 2.757, 2.758, 2.759, 2.7600000000000002,
      2.761, 2.762, 2.763, 2.7640000000000002, 2.765, 2.766, 2.767,
      2.7680000000000002, 2.769, 2.77, 2.771, 2.7720000000000002, 2.773, 2.774,
      2.775, 2.7760000000000002, 2.777, 2.778, 2.779, 2.7800000000000002, 2.781,
      2.782, 2.783, 2.7840000000000003, 2.785, 2.786, 2.787, 2.7880000000000003,
      2.789, 2.79, 2.791, 2.7920000000000003, 2.793, 2.794, 2.795,
      2.7960000000000003, 2.797, 2.798, 2.799, 2.8000000000000003, 2.801, 2.802,
      2.803, 2.8040000000000003, 2.805, 2.806, 2.807, 2.8080000000000003, 2.809,
      2.81, 2.811, 2.8120000000000003, 2.813, 2.814, 2.815, 2.816, 2.817, 2.818,
      2.819, 2.82, 2.821, 2.822, 2.823, 2.824, 2.825, 2.826, 2.827, 2.828, 2.829,
      2.83, 2.831, 2.832, 2.833, 2.834, 2.835, 2.836, 2.837, 2.838, 2.839, 2.84,
      2.841, 2.842, 2.843, 2.844, 2.845, 2.846, 2.847, 2.848, 2.849, 2.85, 2.851,
      2.852, 2.853, 2.854, 2.855, 2.856, 2.857, 2.858, 2.859, 2.86, 2.861, 2.862,
      2.863, 2.864, 2.865, 2.866, 2.867, 2.868, 2.869, 2.87, 2.871, 2.872, 2.873,
      2.874, 2.875, 2.876, 2.8770000000000002, 2.878, 2.879, 2.88,
      2.8810000000000002, 2.882, 2.883, 2.884, 2.8850000000000002, 2.886, 2.887,
      2.888, 2.8890000000000002, 2.89, 2.891, 2.892, 2.8930000000000002, 2.894,
      2.895, 2.896, 2.8970000000000002, 2.898, 2.899, 2.9, 2.9010000000000002,
      2.902, 2.903, 2.904, 2.9050000000000002, 2.906, 2.907, 2.908,
      2.9090000000000003, 2.91, 2.911, 2.912, 2.9130000000000003, 2.914, 2.915,
      2.916, 2.9170000000000003, 2.918, 2.919, 2.92, 2.9210000000000003, 2.922,
      2.923, 2.924, 2.9250000000000003, 2.926, 2.927, 2.928, 2.9290000000000003,
      2.93, 2.931, 2.932, 2.9330000000000003, 2.934, 2.935, 2.936,
      2.9370000000000003, 2.938, 2.939, 2.94, 2.9410000000000003, 2.942, 2.943,
      2.944, 2.945, 2.946, 2.947, 2.948, 2.949, 2.95, 2.951, 2.952, 2.953, 2.954,
      2.955, 2.956, 2.957, 2.958, 2.959, 2.96, 2.961, 2.962, 2.963, 2.964, 2.965,
      2.966, 2.967, 2.968, 2.969, 2.97, 2.971, 2.972, 2.973, 2.974, 2.975, 2.976,
      2.977, 2.978, 2.979, 2.98, 2.981, 2.982, 2.983, 2.984, 2.985, 2.986, 2.987,
      2.988, 2.989, 2.99, 2.991, 2.992, 2.993, 2.994, 2.995, 2.996, 2.997, 2.998,
      2.999, 3.0, 3.001, 3.0020000000000002, 3.003, 3.004, 3.005,
      3.0060000000000002, 3.007, 3.008, 3.009, 3.0100000000000002, 3.011, 3.012,
      3.013, 3.0140000000000002, 3.015, 3.016, 3.017, 3.0180000000000002, 3.019,
      3.02, 3.021, 3.0220000000000002, 3.023, 3.024, 3.025, 3.0260000000000002,
      3.027, 3.028, 3.029, 3.0300000000000002, 3.031, 3.032, 3.033,
      3.0340000000000003, 3.035, 3.036, 3.037, 3.0380000000000003, 3.039, 3.04,
      3.041, 3.0420000000000003, 3.043, 3.044, 3.045, 3.0460000000000003, 3.047,
      3.048, 3.049, 3.0500000000000003, 3.051, 3.052, 3.053, 3.0540000000000003,
      3.055, 3.056, 3.057, 3.0580000000000003, 3.059, 3.06, 3.061,
      3.0620000000000003, 3.063, 3.064, 3.065, 3.0660000000000003, 3.067, 3.068,
      3.069, 3.0700000000000003, 3.071, 3.072, 3.073, 3.074, 3.075, 3.076, 3.077,
      3.078, 3.079, 3.08, 3.081, 3.082, 3.083, 3.084, 3.085, 3.086, 3.087, 3.088,
      3.089, 3.09, 3.091, 3.092, 3.093, 3.094, 3.095, 3.096, 3.097, 3.098, 3.099,
      3.1, 3.101, 3.102, 3.103, 3.104, 3.105, 3.106, 3.107, 3.108, 3.109, 3.11,
      3.111, 3.112, 3.113, 3.114, 3.115, 3.116, 3.117, 3.118, 3.119, 3.12, 3.121,
      3.122, 3.123, 3.124, 3.125, 3.126, 3.1270000000000002, 3.128, 3.129, 3.13,
      3.1310000000000002, 3.132, 3.133, 3.134, 3.1350000000000002, 3.136, 3.137,
      3.138, 3.1390000000000002, 3.14, 3.141, 3.142, 3.1430000000000002, 3.144,
      3.145, 3.146, 3.1470000000000002, 3.148, 3.149, 3.15, 3.1510000000000002,
      3.152, 3.153, 3.154, 3.1550000000000002, 3.156, 3.157, 3.158,
      3.1590000000000003, 3.16, 3.161, 3.162, 3.1630000000000003, 3.164, 3.165,
      3.166, 3.1670000000000003, 3.168, 3.169, 3.17, 3.1710000000000003, 3.172,
      3.173, 3.174, 3.1750000000000003, 3.176, 3.177, 3.178, 3.1790000000000003,
      3.18, 3.181, 3.182, 3.1830000000000003, 3.184, 3.185, 3.186,
      3.1870000000000003, 3.188, 3.189, 3.19, 3.1910000000000003, 3.192, 3.193,
      3.194, 3.1950000000000003, 3.196, 3.197, 3.198, 3.1990000000000003, 3.2,
      3.201, 3.202, 3.203, 3.204, 3.205, 3.206, 3.207, 3.208, 3.209, 3.21, 3.211,
      3.212, 3.213, 3.214, 3.215, 3.216, 3.217, 3.218, 3.219, 3.22, 3.221, 3.222,
      3.223, 3.224, 3.225, 3.226, 3.227, 3.228, 3.229, 3.23, 3.231, 3.232, 3.233,
      3.234, 3.235, 3.236, 3.237, 3.238, 3.239, 3.24, 3.241, 3.242, 3.243, 3.244,
      3.245, 3.246, 3.247, 3.248, 3.249, 3.25, 3.251, 3.2520000000000002, 3.253,
      3.254, 3.255, 3.2560000000000002, 3.257, 3.258, 3.259, 3.2600000000000002,
      3.261, 3.262, 3.263, 3.2640000000000002, 3.265, 3.266, 3.267,
      3.2680000000000002, 3.269, 3.27, 3.271, 3.2720000000000002, 3.273, 3.274,
      3.275, 3.2760000000000002, 3.277, 3.278, 3.279, 3.2800000000000002, 3.281,
      3.282, 3.283, 3.2840000000000003, 3.285, 3.286, 3.287, 3.2880000000000003,
      3.289, 3.29, 3.291, 3.2920000000000003, 3.293, 3.294, 3.295,
      3.2960000000000003, 3.297, 3.298, 3.299, 3.3000000000000003, 3.301, 3.302,
      3.303, 3.3040000000000003, 3.305, 3.306, 3.307, 3.3080000000000003, 3.309,
      3.31, 3.311, 3.3120000000000003, 3.313, 3.314, 3.315, 3.3160000000000003,
      3.317, 3.318, 3.319, 3.3200000000000003, 3.321, 3.322, 3.323,
      3.3240000000000003, 3.325, 3.326, 3.327, 3.3280000000000003, 3.329, 3.33,
      3.331, 3.332, 3.333, 3.334, 3.335, 3.336, 3.337, 3.338, 3.339, 3.34, 3.341,
      3.342, 3.343, 3.344, 3.345, 3.346, 3.347, 3.348, 3.349, 3.35, 3.351, 3.352,
      3.353, 3.354, 3.355, 3.356, 3.357, 3.358, 3.359, 3.36, 3.361, 3.362, 3.363,
      3.364, 3.365, 3.366, 3.367, 3.368, 3.369, 3.37, 3.371, 3.372, 3.373, 3.374,
      3.375, 3.376, 3.3770000000000002, 3.378, 3.379, 3.38, 3.3810000000000002,
      3.382, 3.383, 3.384, 3.3850000000000002, 3.386, 3.387, 3.388,
      3.3890000000000002, 3.39, 3.391, 3.392, 3.3930000000000002, 3.394, 3.395,
      3.396, 3.3970000000000002, 3.398, 3.399, 3.4, 3.4010000000000002, 3.402,
      3.403, 3.404, 3.4050000000000002, 3.406, 3.407, 3.408, 3.4090000000000003,
      3.41, 3.411, 3.412, 3.4130000000000003, 3.414, 3.415, 3.416,
      3.4170000000000003, 3.418, 3.419, 3.42, 3.4210000000000003, 3.422, 3.423,
      3.424, 3.4250000000000003, 3.426, 3.427, 3.428, 3.4290000000000003, 3.43,
      3.431, 3.432, 3.4330000000000003, 3.434, 3.435, 3.436, 3.4370000000000003,
      3.438, 3.439, 3.44, 3.4410000000000003, 3.442, 3.443, 3.444,
      3.4450000000000003, 3.446, 3.447, 3.448, 3.4490000000000003, 3.45, 3.451,
      3.452, 3.4530000000000003, 3.454, 3.455, 3.456, 3.457, 3.458, 3.459, 3.46,
      3.461, 3.462, 3.463, 3.464, 3.465, 3.466, 3.467, 3.468, 3.469, 3.47, 3.471,
      3.472, 3.473, 3.474, 3.475, 3.476, 3.477, 3.478, 3.479, 3.48, 3.481, 3.482,
      3.483, 3.484, 3.485, 3.486, 3.487, 3.488, 3.489, 3.49, 3.491, 3.492, 3.493,
      3.494, 3.495, 3.496, 3.497, 3.498, 3.499, 3.5, 3.501, 3.5020000000000002,
      3.503, 3.504, 3.505, 3.5060000000000002, 3.507, 3.508, 3.509,
      3.5100000000000002, 3.511, 3.512, 3.513, 3.5140000000000002, 3.515, 3.516,
      3.517, 3.5180000000000002, 3.519, 3.52, 3.521, 3.5220000000000002, 3.523,
      3.524, 3.525, 3.5260000000000002, 3.527, 3.528, 3.529, 3.5300000000000002,
      3.531, 3.532, 3.533, 3.5340000000000003, 3.535, 3.536, 3.537,
      3.5380000000000003, 3.539, 3.54, 3.541, 3.5420000000000003, 3.543, 3.544,
      3.545, 3.5460000000000003, 3.547, 3.548, 3.549, 3.5500000000000003, 3.551,
      3.552, 3.553, 3.5540000000000003, 3.555, 3.556, 3.557, 3.5580000000000003,
      3.559, 3.56, 3.561, 3.5620000000000003, 3.563, 3.564, 3.565,
      3.5660000000000003, 3.567, 3.568, 3.569, 3.5700000000000003, 3.571, 3.572,
      3.573, 3.5740000000000003, 3.575, 3.576, 3.577, 3.5780000000000003, 3.579,
      3.58, 3.581, 3.5820000000000003, 3.583, 3.584, 3.585, 3.586, 3.587, 3.588,
      3.589, 3.59, 3.591, 3.592, 3.593, 3.594, 3.595, 3.596, 3.597, 3.598, 3.599,
      3.6, 3.601, 3.602, 3.603, 3.604, 3.605, 3.606, 3.607, 3.608, 3.609, 3.61,
      3.611, 3.612, 3.613, 3.614, 3.615, 3.616, 3.617, 3.618, 3.619, 3.62, 3.621,
      3.622, 3.623, 3.624, 3.625, 3.626, 3.6270000000000002, 3.628, 3.629, 3.63,
      3.6310000000000002, 3.632, 3.633, 3.634, 3.6350000000000002, 3.636, 3.637,
      3.638, 3.6390000000000002, 3.64, 3.641, 3.642, 3.6430000000000002, 3.644,
      3.645, 3.646, 3.6470000000000002, 3.648, 3.649, 3.65, 3.6510000000000002,
      3.652, 3.653, 3.654, 3.6550000000000002, 3.656, 3.657, 3.658,
      3.6590000000000003, 3.66, 3.661, 3.662, 3.6630000000000003, 3.664, 3.665,
      3.666, 3.6670000000000003, 3.668, 3.669, 3.67, 3.6710000000000003, 3.672,
      3.673, 3.674, 3.6750000000000003, 3.676, 3.677, 3.678, 3.6790000000000003,
      3.68, 3.681, 3.682, 3.6830000000000003, 3.684, 3.685, 3.686,
      3.6870000000000003, 3.688, 3.689, 3.69, 3.6910000000000003, 3.692, 3.693,
      3.694, 3.6950000000000003, 3.696, 3.697, 3.698, 3.6990000000000003, 3.7,
      3.701, 3.702, 3.7030000000000003, 3.704, 3.705, 3.706, 3.7070000000000003,
      3.708, 3.709, 3.71, 3.7110000000000003, 3.712, 3.713, 3.714, 3.715, 3.716,
      3.717, 3.718, 3.719, 3.72, 3.721, 3.722, 3.723, 3.724, 3.725, 3.726, 3.727,
      3.728, 3.729, 3.73, 3.731, 3.732, 3.733, 3.734, 3.735, 3.736, 3.737, 3.738,
      3.739, 3.74, 3.741, 3.742, 3.743, 3.744, 3.745, 3.746, 3.747, 3.748, 3.749,
      3.75, 3.751, 3.7520000000000002, 3.753, 3.754, 3.755, 3.7560000000000002,
      3.757, 3.758, 3.759, 3.7600000000000002, 3.761, 3.762, 3.763,
      3.7640000000000002, 3.765, 3.766, 3.767, 3.7680000000000002, 3.769, 3.77,
      3.771, 3.7720000000000002, 3.773, 3.774, 3.775, 3.7760000000000002, 3.777,
      3.778, 3.779, 3.7800000000000002, 3.781, 3.782, 3.783, 3.7840000000000003,
      3.785, 3.786, 3.787, 3.7880000000000003, 3.789, 3.79, 3.791,
      3.7920000000000003, 3.793, 3.794, 3.795, 3.7960000000000003, 3.797, 3.798,
      3.799, 3.8000000000000003, 3.801, 3.802, 3.803, 3.8040000000000003, 3.805,
      3.806, 3.807, 3.8080000000000003, 3.809, 3.81, 3.811, 3.8120000000000003,
      3.813, 3.814, 3.815, 3.8160000000000003, 3.817, 3.818, 3.819,
      3.8200000000000003, 3.821, 3.822, 3.823, 3.8240000000000003, 3.825, 3.826,
      3.827, 3.8280000000000003, 3.829, 3.83, 3.831, 3.8320000000000003, 3.833,
      3.834, 3.835, 3.8360000000000003, 3.837, 3.838, 3.839, 3.84, 3.841, 3.842,
      3.843, 3.844, 3.845, 3.846, 3.847, 3.848, 3.849, 3.85, 3.851, 3.852, 3.853,
      3.854, 3.855, 3.856, 3.857, 3.858, 3.859, 3.86, 3.861, 3.862, 3.863, 3.864,
      3.865, 3.866, 3.867, 3.868, 3.869, 3.87, 3.871, 3.872, 3.873, 3.874, 3.875,
      3.876, 3.8770000000000002, 3.878, 3.879, 3.88, 3.8810000000000002, 3.882,
      3.883, 3.884, 3.8850000000000002, 3.886, 3.887, 3.888, 3.8890000000000002,
      3.89, 3.891, 3.892, 3.8930000000000002, 3.894, 3.895, 3.896,
      3.8970000000000002, 3.898, 3.899, 3.9, 3.9010000000000002, 3.902, 3.903,
      3.904, 3.9050000000000002, 3.906, 3.907, 3.908, 3.9090000000000003, 3.91,
      3.911, 3.912, 3.9130000000000003, 3.914, 3.915, 3.916, 3.9170000000000003,
      3.918, 3.919, 3.92, 3.9210000000000003, 3.922, 3.923, 3.924,
      3.9250000000000003, 3.926, 3.927, 3.928, 3.9290000000000003, 3.93, 3.931,
      3.932, 3.9330000000000003, 3.934, 3.935, 3.936, 3.9370000000000003, 3.938,
      3.939, 3.94, 3.9410000000000003, 3.942, 3.943, 3.944, 3.9450000000000003,
      3.946, 3.947, 3.948, 3.9490000000000003, 3.95, 3.951, 3.952,
      3.9530000000000003, 3.954, 3.955, 3.956, 3.9570000000000003, 3.958, 3.959,
      3.96, 3.9610000000000003, 3.962, 3.963, 3.964, 3.9650000000000003, 3.966,
      3.967, 3.968, 3.969, 3.97, 3.971, 3.972, 3.973, 3.974, 3.975, 3.976, 3.977,
      3.978, 3.979, 3.98, 3.981, 3.982, 3.983, 3.984, 3.985, 3.986, 3.987, 3.988,
      3.989, 3.99, 3.991, 3.992, 3.993, 3.994, 3.995, 3.996, 3.997, 3.998, 3.999,
      4.0, 4.0009999999999994, 4.002, 4.003, 4.004, 4.005, 4.006, 4.007, 4.008,
      4.009, 4.01, 4.011, 4.0120000000000005, 4.013, 4.0139999999999993,
      4.0150000000000006, 4.016, 4.0169999999999995, 4.018, 4.019, 4.02, 4.021,
      4.022, 4.023, 4.024, 4.025, 4.026, 4.027, 4.0280000000000005, 4.029,
      4.0299999999999994, 4.0310000000000006, 4.032, 4.0329999999999995, 4.034,
      4.035, 4.036, 4.037, 4.038, 4.039, 4.04, 4.041, 4.042, 4.0429999999999993,
      4.0440000000000005, 4.045, 4.0459999999999994, 4.047, 4.048,
      4.0489999999999995, 4.05, 4.051, 4.052, 4.053, 4.054, 4.055, 4.056, 4.057,
      4.058, 4.0589999999999993, 4.0600000000000005, 4.061, 4.0619999999999994,
      4.063, 4.064, 4.0649999999999995, 4.066, 4.067, 4.068, 4.069, 4.07, 4.071,
      4.072, 4.073, 4.074, 4.0749999999999993, 4.0760000000000005, 4.077,
      4.0779999999999994, 4.079, 4.08, 4.0809999999999995, 4.082, 4.083, 4.084,
      4.085, 4.086, 4.087, 4.088, 4.089, 4.09, 4.0909999999999993,
      4.0920000000000005, 4.093, 4.0939999999999994, 4.095, 4.096,
      4.0969999999999995, 4.098, 4.099, 4.1, 4.101, 4.102, 4.103, 4.104, 4.105,
      4.106, 4.1069999999999993, 4.1080000000000005, 4.109, 4.1099999999999994,
      4.111, 4.112, 4.1129999999999995, 4.114, 4.115, 4.116, 4.117, 4.118, 4.119,
      4.12, 4.121, 4.122, 4.1229999999999993, 4.1240000000000006, 4.125,
      4.1259999999999994, 4.127, 4.128, 4.129, 4.13, 4.131, 4.132, 4.133, 4.134,
      4.135, 4.136, 4.1370000000000005, 4.138, 4.1389999999999993,
      4.1400000000000006, 4.141, 4.1419999999999995, 4.143, 4.144, 4.145, 4.146,
      4.147, 4.148, 4.149, 4.15, 4.151, 4.152, 4.1530000000000005, 4.154,
      4.1549999999999994, 4.1560000000000006, 4.157, 4.1579999999999995, 4.159,
      4.16, 4.161, 4.162, 4.163, 4.164, 4.165, 4.166, 4.167, 4.1679999999999993,
      4.1690000000000005, 4.17, 4.1709999999999994, 4.172, 4.173,
      4.1739999999999995, 4.175, 4.176, 4.177, 4.178, 4.179, 4.18, 4.181, 4.182,
      4.183, 4.1839999999999993, 4.1850000000000005, 4.186, 4.1869999999999994,
      4.188, 4.189, 4.1899999999999995, 4.191, 4.192, 4.193, 4.194, 4.195, 4.196,
      4.197, 4.198, 4.199, 4.1999999999999993, 4.2010000000000005, 4.202,
      4.2029999999999994, 4.204, 4.205, 4.2059999999999995, 4.207, 4.208, 4.209,
      4.21, 4.211, 4.212, 4.213, 4.214, 4.215, 4.2159999999999993,
      4.2170000000000005, 4.218, 4.2189999999999994, 4.22, 4.221,
      4.2219999999999995, 4.223, 4.224, 4.225, 4.226, 4.227, 4.228, 4.229, 4.23,
      4.231, 4.2319999999999993, 4.2330000000000005, 4.234, 4.2349999999999994,
      4.236, 4.237, 4.2379999999999995, 4.239, 4.24, 4.241, 4.242, 4.243, 4.244,
      4.245, 4.246, 4.247, 4.2479999999999993, 4.2490000000000006, 4.25,
      4.2509999999999994, 4.252, 4.253, 4.254, 4.255, 4.256, 4.257, 4.258, 4.259,
      4.26, 4.261, 4.2620000000000005, 4.263, 4.2639999999999993,
      4.2650000000000006, 4.266, 4.2669999999999995, 4.268, 4.269, 4.27, 4.271,
      4.272, 4.273, 4.274, 4.275, 4.276, 4.277, 4.2780000000000005, 4.279,
      4.2799999999999994, 4.2810000000000006, 4.282, 4.2829999999999995, 4.284,
      4.285, 4.286, 4.287, 4.288, 4.289, 4.29, 4.291, 4.292, 4.2929999999999993,
      4.2940000000000005, 4.295, 4.2959999999999994, 4.297, 4.298,
      4.2989999999999995, 4.3, 4.301, 4.302, 4.303, 4.304, 4.305, 4.306, 4.307,
      4.308, 4.3089999999999993, 4.3100000000000005, 4.311, 4.3119999999999994,
      4.313, 4.314, 4.3149999999999995, 4.316, 4.317, 4.318, 4.319, 4.32, 4.321,
      4.322, 4.323, 4.324, 4.3249999999999993, 4.3260000000000005, 4.327,
      4.3279999999999994, 4.329, 4.33, 4.3309999999999995, 4.332, 4.333, 4.334,
      4.335, 4.336, 4.337, 4.338, 4.339, 4.34, 4.3409999999999993,
      4.3420000000000005, 4.343, 4.3439999999999994, 4.345, 4.346,
      4.3469999999999995, 4.348, 4.349, 4.35, 4.351, 4.352, 4.353, 4.354, 4.355,
      4.356, 4.3569999999999993, 4.3580000000000005, 4.359, 4.3599999999999994,
      4.361, 4.362, 4.3629999999999995, 4.364, 4.365, 4.366, 4.367, 4.368, 4.369,
      4.37, 4.371, 4.372, 4.3729999999999993, 4.3740000000000006, 4.375,
      4.3759999999999994, 4.377, 4.378, 4.379, 4.38, 4.381, 4.382, 4.383, 4.384,
      4.385, 4.386, 4.3870000000000005, 4.388, 4.3889999999999993,
      4.3900000000000006, 4.391, 4.3919999999999995, 4.393, 4.394, 4.395, 4.396,
      4.397, 4.398, 4.399, 4.4, 4.401, 4.402, 4.4030000000000005, 4.404,
      4.4049999999999994, 4.4060000000000006, 4.407, 4.4079999999999995, 4.409,
      4.41, 4.411, 4.412, 4.413, 4.414, 4.415, 4.416, 4.417, 4.4179999999999993,
      4.4190000000000005, 4.42, 4.4209999999999994, 4.422, 4.423,
      4.4239999999999995, 4.425, 4.426, 4.427, 4.428, 4.429, 4.43, 4.431, 4.432,
      4.433, 4.4339999999999993, 4.4350000000000005, 4.436, 4.4369999999999994,
      4.438, 4.439, 4.4399999999999995, 4.441, 4.442, 4.443, 4.444, 4.445, 4.446,
      4.447, 4.448, 4.449, 4.4499999999999993, 4.4510000000000005, 4.452,
      4.4529999999999994, 4.454, 4.455, 4.4559999999999995, 4.457, 4.458, 4.459,
      4.46, 4.461, 4.462, 4.463, 4.464, 4.465, 4.4659999999999993,
      4.4670000000000005, 4.468, 4.4689999999999994, 4.47, 4.471,
      4.4719999999999995, 4.473, 4.474, 4.475, 4.476, 4.477, 4.478, 4.479, 4.48,
      4.481, 4.4819999999999993, 4.4830000000000005, 4.484, 4.4849999999999994,
      4.486, 4.487, 4.4879999999999995, 4.489, 4.49, 4.491, 4.492, 4.493, 4.494,
      4.495, 4.496, 4.497, 4.4979999999999993, 4.4990000000000006, 4.5,
      4.5009999999999994, 4.502, 4.503, 4.504, 4.505, 4.506, 4.507, 4.508, 4.509,
      4.51, 4.511, 4.5120000000000005, 4.513, 4.5139999999999993,
      4.5150000000000006, 4.516, 4.5169999999999995, 4.518, 4.519, 4.52, 4.521,
      4.522, 4.523, 4.524, 4.525, 4.526, 4.527, 4.5280000000000005, 4.529,
      4.5299999999999994, 4.5310000000000006, 4.532, 4.5329999999999995, 4.534,
      4.535, 4.536, 4.537, 4.538, 4.539, 4.54, 4.541, 4.542, 4.543,
      4.5440000000000005, 4.545, 4.5459999999999994, 4.547, 4.548,
      4.5489999999999995, 4.55, 4.551, 4.552, 4.553, 4.554, 4.555, 4.556, 4.557,
      4.558, 4.5589999999999993, 4.5600000000000005, 4.561, 4.5619999999999994,
      4.563, 4.564, 4.5649999999999995, 4.566, 4.567, 4.568, 4.569, 4.57, 4.571,
      4.572, 4.573, 4.574, 4.5749999999999993, 4.5760000000000005, 4.577,
      4.5779999999999994, 4.579, 4.58, 4.5809999999999995, 4.582, 4.583, 4.584,
      4.585, 4.586, 4.587, 4.588, 4.589, 4.59, 4.5909999999999993,
      4.5920000000000005, 4.593, 4.5939999999999994, 4.595, 4.596,
      4.5969999999999995, 4.598, 4.599, 4.6, 4.601, 4.602, 4.603, 4.604, 4.605,
      4.606, 4.6069999999999993, 4.6080000000000005, 4.609, 4.6099999999999994,
      4.611, 4.612, 4.6129999999999995, 4.614, 4.615, 4.616, 4.617, 4.618, 4.619,
      4.62, 4.621, 4.622, 4.6229999999999993, 4.6240000000000006, 4.625,
      4.6259999999999994, 4.627, 4.628, 4.629, 4.63, 4.631, 4.632, 4.633, 4.634,
      4.635, 4.636, 4.6370000000000005, 4.638, 4.6389999999999993,
      4.6400000000000006, 4.641, 4.6419999999999995, 4.643, 4.644, 4.645, 4.646,
      4.647, 4.648, 4.649, 4.65, 4.651, 4.652, 4.6530000000000005, 4.654,
      4.6549999999999994, 4.6560000000000006, 4.657, 4.6579999999999995, 4.659,
      4.66, 4.661, 4.662, 4.663, 4.664, 4.665, 4.666, 4.667, 4.668,
      4.6690000000000005, 4.67, 4.6709999999999994, 4.672, 4.673,
      4.6739999999999995, 4.675, 4.676, 4.677, 4.678, 4.679, 4.68, 4.681, 4.682,
      4.683, 4.6839999999999993, 4.6850000000000005, 4.686, 4.6869999999999994,
      4.688, 4.689, 4.6899999999999995, 4.691, 4.692, 4.693, 4.694, 4.695, 4.696,
      4.697, 4.698, 4.699, 4.6999999999999993, 4.7010000000000005, 4.702,
      4.7029999999999994, 4.704, 4.705, 4.7059999999999995, 4.707, 4.708, 4.709,
      4.71, 4.711, 4.712, 4.713, 4.714, 4.715, 4.7159999999999993,
      4.7170000000000005, 4.718, 4.7189999999999994, 4.72, 4.721,
      4.7219999999999995, 4.723, 4.724, 4.725, 4.726, 4.727, 4.728, 4.729, 4.73,
      4.731, 4.7319999999999993, 4.7330000000000005, 4.734, 4.7349999999999994,
      4.736, 4.737, 4.7379999999999995, 4.739, 4.74, 4.741, 4.742, 4.743, 4.744,
      4.745, 4.746, 4.747, 4.7479999999999993, 4.7490000000000006, 4.75,
      4.7509999999999994, 4.752, 4.753, 4.754, 4.755, 4.756, 4.757, 4.758, 4.759,
      4.76, 4.761, 4.7620000000000005, 4.763, 4.7639999999999993,
      4.7650000000000006, 4.766, 4.7669999999999995, 4.768, 4.769, 4.77, 4.771,
      4.772, 4.773, 4.774, 4.775, 4.776, 4.777, 4.7780000000000005, 4.779,
      4.7799999999999994, 4.7810000000000006, 4.782, 4.7829999999999995, 4.784,
      4.785, 4.786, 4.787, 4.788, 4.789, 4.79, 4.791, 4.792, 4.793,
      4.7940000000000005, 4.795, 4.7959999999999994, 4.7970000000000006, 4.798,
      4.7989999999999995, 4.8, 4.801, 4.802, 4.803, 4.804, 4.805, 4.806, 4.807,
      4.808, 4.8089999999999993, 4.8100000000000005, 4.811, 4.8119999999999994,
      4.813, 4.814, 4.8149999999999995, 4.816, 4.817, 4.818, 4.819, 4.82, 4.821,
      4.822, 4.823, 4.824, 4.8249999999999993, 4.8260000000000005, 4.827,
      4.8279999999999994, 4.829, 4.83, 4.8309999999999995, 4.832, 4.833, 4.834,
      4.835, 4.836, 4.837, 4.838, 4.839, 4.84, 4.8409999999999993,
      4.8420000000000005, 4.843, 4.8439999999999994, 4.845, 4.846,
      4.8469999999999995, 4.848, 4.849, 4.85, 4.851, 4.852, 4.853, 4.854, 4.855,
      4.856, 4.8569999999999993, 4.8580000000000005, 4.859, 4.8599999999999994,
      4.861, 4.862, 4.8629999999999995, 4.864, 4.865, 4.866, 4.867, 4.868, 4.869,
      4.87, 4.871, 4.872, 4.8729999999999993, 4.8740000000000006, 4.875,
      4.8759999999999994, 4.877, 4.878, 4.879, 4.88, 4.881, 4.882, 4.883, 4.884,
      4.885, 4.886, 4.8870000000000005, 4.888, 4.8889999999999993,
      4.8900000000000006, 4.891, 4.8919999999999995, 4.893, 4.894, 4.895, 4.896,
      4.897, 4.898, 4.899, 4.9, 4.901, 4.902, 4.9030000000000005, 4.904,
      4.9049999999999994, 4.9060000000000006, 4.907, 4.9079999999999995, 4.909,
      4.91, 4.911, 4.912, 4.913, 4.914, 4.915, 4.916, 4.917, 4.918,
      4.9190000000000005, 4.92, 4.9209999999999994, 4.9220000000000006, 4.923,
      4.9239999999999995, 4.925, 4.926, 4.927, 4.928, 4.929, 4.93, 4.931, 4.932,
      4.933, 4.9339999999999993, 4.9350000000000005, 4.936, 4.9369999999999994,
      4.938, 4.939, 4.9399999999999995, 4.941, 4.942, 4.943, 4.944, 4.945, 4.946,
      4.947, 4.948, 4.949, 4.9499999999999993, 4.9510000000000005, 4.952,
      4.9529999999999994, 4.954, 4.955, 4.9559999999999995, 4.957, 4.958, 4.959,
      4.96, 4.961, 4.962, 4.963, 4.964, 4.965, 4.9659999999999993,
      4.9670000000000005, 4.968, 4.9689999999999994, 4.97, 4.971,
      4.9719999999999995, 4.973, 4.974, 4.975, 4.976, 4.977, 4.978, 4.979, 4.98,
      4.981, 4.9819999999999993, 4.9830000000000005, 4.984, 4.9849999999999994,
      4.986, 4.987, 4.9879999999999995, 4.989, 4.99, 4.991, 4.992, 4.993, 4.994,
      4.995, 4.996, 4.997, 4.9979999999999993, 4.9990000000000006, 5.0,
      5.0009999999999994, 5.002, 5.003, 5.004, 5.005, 5.006, 5.007, 5.008, 5.009,
      5.01, 5.011, 5.0120000000000005, 5.013, 5.0139999999999993,
      5.0150000000000006, 5.016, 5.0169999999999995, 5.018, 5.019, 5.02, 5.021,
      5.022, 5.023, 5.024, 5.025, 5.026, 5.027, 5.0280000000000005, 5.029,
      5.0299999999999994, 5.0310000000000006, 5.032, 5.0329999999999995, 5.034,
      5.035, 5.036, 5.037, 5.038, 5.039, 5.04, 5.041, 5.042, 5.043,
      5.0440000000000005, 5.045, 5.0459999999999994, 5.0470000000000006, 5.048,
      5.0489999999999995, 5.05, 5.051, 5.052, 5.053, 5.054, 5.055, 5.056, 5.057,
      5.058, 5.0589999999999993, 5.0600000000000005, 5.061, 5.0619999999999994,
      5.063, 5.064, 5.0649999999999995, 5.066, 5.067, 5.068, 5.069, 5.07, 5.071,
      5.072, 5.073, 5.074, 5.0749999999999993, 5.0760000000000005, 5.077,
      5.0779999999999994, 5.079, 5.08, 5.0809999999999995, 5.082, 5.083, 5.084,
      5.085, 5.086, 5.087, 5.088, 5.089, 5.09, 5.0909999999999993,
      5.0920000000000005, 5.093, 5.0939999999999994, 5.095, 5.096,
      5.0969999999999995, 5.098, 5.099, 5.1, 5.101, 5.102, 5.103, 5.104, 5.105,
      5.106, 5.1069999999999993, 5.1080000000000005, 5.109, 5.1099999999999994,
      5.111, 5.112, 5.1129999999999995, 5.114, 5.115, 5.116, 5.117, 5.118, 5.119,
      5.12, 5.121, 5.122, 5.1229999999999993, 5.1240000000000006, 5.125,
      5.1259999999999994, 5.127, 5.128, 5.129, 5.13, 5.131, 5.132, 5.133, 5.134,
      5.135, 5.136, 5.1370000000000005, 5.138, 5.1389999999999993,
      5.1400000000000006, 5.141, 5.1419999999999995, 5.143, 5.144, 5.145, 5.146,
      5.147, 5.148, 5.149, 5.15, 5.151, 5.152, 5.1530000000000005, 5.154,
      5.1549999999999994, 5.1560000000000006, 5.157, 5.1579999999999995, 5.159,
      5.16, 5.161, 5.162, 5.163, 5.164, 5.165, 5.166, 5.167, 5.168,
      5.1690000000000005, 5.17, 5.1709999999999994, 5.1720000000000006, 5.173,
      5.1739999999999995, 5.175, 5.176, 5.177, 5.178, 5.179, 5.18, 5.181, 5.182,
      5.183, 5.184, 5.1850000000000005, 5.186, 5.1869999999999994, 5.188, 5.189,
      5.1899999999999995, 5.191, 5.192, 5.193, 5.194, 5.195, 5.196, 5.197, 5.198,
      5.199, 5.1999999999999993, 5.2010000000000005, 5.202, 5.2029999999999994,
      5.204, 5.205, 5.2059999999999995, 5.207, 5.208, 5.209, 5.21, 5.211, 5.212,
      5.213, 5.214, 5.215, 5.2159999999999993, 5.2170000000000005, 5.218,
      5.2189999999999994, 5.22, 5.221, 5.2219999999999995, 5.223, 5.224, 5.225,
      5.226, 5.227, 5.228, 5.229, 5.23, 5.231, 5.2319999999999993,
      5.2330000000000005, 5.234, 5.2349999999999994, 5.236, 5.237,
      5.2379999999999995, 5.239, 5.24, 5.241, 5.242, 5.243, 5.244, 5.245, 5.246,
      5.247, 5.2479999999999993, 5.2490000000000006, 5.25, 5.2509999999999994,
      5.252, 5.253, 5.254, 5.255, 5.256, 5.257, 5.258, 5.259, 5.26, 5.261,
      5.2620000000000005, 5.263, 5.2639999999999993, 5.2650000000000006, 5.266,
      5.2669999999999995, 5.268, 5.269, 5.27, 5.271, 5.272, 5.273, 5.274, 5.275,
      5.276, 5.277, 5.2780000000000005, 5.279, 5.2799999999999994,
      5.2810000000000006, 5.282, 5.2829999999999995, 5.284, 5.285, 5.286, 5.287,
      5.288, 5.289, 5.29, 5.291, 5.292, 5.293, 5.2940000000000005, 5.295,
      5.2959999999999994, 5.2970000000000006, 5.298, 5.2989999999999995, 5.3,
      5.301, 5.302, 5.303, 5.304, 5.305, 5.306, 5.307, 5.308, 5.309,
      5.3100000000000005, 5.311, 5.3119999999999994, 5.313, 5.314,
      5.3149999999999995, 5.316, 5.317, 5.318, 5.319, 5.32, 5.321, 5.322, 5.323,
      5.324, 5.3249999999999993, 5.3260000000000005, 5.327, 5.3279999999999994,
      5.329, 5.33, 5.3309999999999995, 5.332, 5.333, 5.334, 5.335, 5.336, 5.337,
      5.338, 5.339, 5.34, 5.3409999999999993, 5.3420000000000005, 5.343,
      5.3439999999999994, 5.345, 5.346, 5.3469999999999995, 5.348, 5.349, 5.35,
      5.351, 5.352, 5.353, 5.354, 5.355, 5.356, 5.3569999999999993,
      5.3580000000000005, 5.359, 5.3599999999999994, 5.361, 5.362,
      5.3629999999999995, 5.364, 5.365, 5.366, 5.367, 5.368, 5.369, 5.37, 5.371,
      5.372, 5.3729999999999993, 5.3740000000000006, 5.375, 5.3759999999999994,
      5.377, 5.378, 5.379, 5.38, 5.381, 5.382, 5.383, 5.384, 5.385, 5.386,
      5.3870000000000005, 5.388, 5.3889999999999993, 5.3900000000000006, 5.391,
      5.3919999999999995, 5.393, 5.394, 5.395, 5.396, 5.397, 5.398, 5.399, 5.4,
      5.401, 5.402, 5.4030000000000005, 5.404, 5.4049999999999994,
      5.4060000000000006, 5.407, 5.4079999999999995, 5.409, 5.41, 5.411, 5.412,
      5.413, 5.414, 5.415, 5.416, 5.417, 5.418, 5.4190000000000005, 5.42,
      5.4209999999999994, 5.4220000000000006, 5.423, 5.4239999999999995, 5.425,
      5.426, 5.427, 5.428, 5.429, 5.43, 5.431, 5.432, 5.433, 5.434,
      5.4350000000000005, 5.436, 5.4369999999999994, 5.4380000000000006, 5.439,
      5.4399999999999995, 5.441, 5.442, 5.443, 5.444, 5.445, 5.446, 5.447, 5.448,
      5.449, 5.4499999999999993, 5.4510000000000005, 5.452, 5.4529999999999994,
      5.454, 5.455, 5.4559999999999995, 5.457, 5.458, 5.459, 5.46, 5.461, 5.462,
      5.463, 5.464, 5.465, 5.4659999999999993, 5.4670000000000005, 5.468,
      5.4689999999999994, 5.47, 5.471, 5.4719999999999995, 5.473, 5.474, 5.475,
      5.476, 5.477, 5.478, 5.479, 5.48, 5.481, 5.4819999999999993,
      5.4830000000000005, 5.484, 5.4849999999999994, 5.486, 5.487,
      5.4879999999999995, 5.489, 5.49, 5.491, 5.492, 5.493, 5.494, 5.495, 5.496,
      5.497, 5.4979999999999993, 5.4990000000000006, 5.5, 5.5009999999999994,
      5.502, 5.503, 5.504, 5.505, 5.506, 5.507, 5.508, 5.509, 5.51, 5.511,
      5.5120000000000005, 5.513, 5.5139999999999993, 5.5150000000000006, 5.516,
      5.5169999999999995, 5.518, 5.519, 5.52, 5.521, 5.522, 5.523, 5.524, 5.525,
      5.526, 5.527, 5.5280000000000005, 5.529, 5.5299999999999994,
      5.5310000000000006, 5.532, 5.5329999999999995, 5.534, 5.535, 5.536, 5.537,
      5.538, 5.539, 5.54, 5.541, 5.542, 5.543, 5.5440000000000005, 5.545,
      5.5459999999999994, 5.5470000000000006, 5.548, 5.5489999999999995, 5.55,
      5.551, 5.552, 5.553, 5.554, 5.555, 5.556, 5.557, 5.558, 5.559,
      5.5600000000000005, 5.561, 5.5619999999999994, 5.5630000000000006, 5.564,
      5.5649999999999995, 5.566, 5.567, 5.568, 5.569, 5.57, 5.571, 5.572, 5.573,
      5.574, 5.5749999999999993, 5.5760000000000005, 5.577, 5.5779999999999994,
      5.579, 5.58, 5.5809999999999995, 5.582, 5.583, 5.584, 5.585, 5.586, 5.587,
      5.588, 5.589, 5.59, 5.5909999999999993, 5.5920000000000005, 5.593,
      5.5939999999999994, 5.595, 5.596, 5.5969999999999995, 5.598, 5.599, 5.6,
      5.601, 5.602, 5.603, 5.604, 5.605, 5.606, 5.6069999999999993,
      5.6080000000000005, 5.609, 5.6099999999999994, 5.611, 5.612,
      5.6129999999999995, 5.614, 5.615, 5.616, 5.617, 5.618, 5.619, 5.62, 5.621,
      5.622, 5.6229999999999993, 5.6240000000000006, 5.625, 5.6259999999999994,
      5.627, 5.628, 5.629, 5.63, 5.631, 5.632, 5.633, 5.634, 5.635, 5.636,
      5.6370000000000005, 5.638, 5.6389999999999993, 5.6400000000000006, 5.641,
      5.6419999999999995, 5.643, 5.644, 5.645, 5.646, 5.647, 5.648, 5.649, 5.65,
      5.651, 5.652, 5.6530000000000005, 5.654, 5.6549999999999994,
      5.6560000000000006, 5.657, 5.6579999999999995, 5.659, 5.66, 5.661, 5.662,
      5.663, 5.664, 5.665, 5.666, 5.667, 5.668, 5.6690000000000005, 5.67,
      5.6709999999999994, 5.6720000000000006, 5.673, 5.6739999999999995, 5.675,
      5.676, 5.677, 5.678, 5.679, 5.68, 5.681, 5.682, 5.683, 5.684,
      5.6850000000000005, 5.686, 5.6869999999999994, 5.6880000000000006, 5.689,
      5.6899999999999995, 5.691, 5.692, 5.693, 5.694, 5.695, 5.696, 5.697, 5.698,
      5.699, 5.6999999999999993, 5.7010000000000005, 5.702, 5.7029999999999994,
      5.704, 5.705, 5.7059999999999995, 5.707, 5.708, 5.709, 5.71, 5.711, 5.712,
      5.713, 5.714, 5.715, 5.7159999999999993, 5.7170000000000005, 5.718,
      5.7189999999999994, 5.72, 5.721, 5.7219999999999995, 5.723, 5.724, 5.725,
      5.726, 5.727, 5.728, 5.729, 5.73, 5.731, 5.7319999999999993,
      5.7330000000000005, 5.734, 5.7349999999999994, 5.736, 5.737,
      5.7379999999999995, 5.739, 5.74, 5.741, 5.742, 5.743, 5.744, 5.745, 5.746,
      5.747, 5.7479999999999993, 5.7490000000000006, 5.75, 5.7509999999999994,
      5.752, 5.753, 5.754, 5.755, 5.756, 5.757, 5.758, 5.759, 5.76, 5.761,
      5.7620000000000005, 5.763, 5.7639999999999993, 5.7650000000000006, 5.766,
      5.7669999999999995, 5.768, 5.769, 5.77, 5.771, 5.772, 5.773, 5.774, 5.775,
      5.776, 5.777, 5.7780000000000005, 5.779, 5.7799999999999994,
      5.7810000000000006, 5.782, 5.7829999999999995, 5.784, 5.785, 5.786, 5.787,
      5.788, 5.789, 5.79, 5.791, 5.792, 5.793, 5.7940000000000005, 5.795,
      5.7959999999999994, 5.7970000000000006, 5.798, 5.7989999999999995, 5.8,
      5.801, 5.802, 5.803, 5.804, 5.805, 5.806, 5.807, 5.808, 5.809,
      5.8100000000000005, 5.811, 5.8119999999999994, 5.8130000000000006, 5.814,
      5.8149999999999995, 5.816, 5.817, 5.818, 5.819, 5.82, 5.821, 5.822, 5.823,
      5.824, 5.8249999999999993, 5.8260000000000005, 5.827, 5.8279999999999994,
      5.829, 5.83, 5.8309999999999995, 5.832, 5.833, 5.834, 5.835, 5.836, 5.837,
      5.838, 5.839, 5.84, 5.8409999999999993, 5.8420000000000005, 5.843,
      5.8439999999999994, 5.845, 5.846, 5.8469999999999995, 5.848, 5.849, 5.85,
      5.851, 5.852, 5.853, 5.854, 5.855, 5.856, 5.8569999999999993,
      5.8580000000000005, 5.859, 5.8599999999999994, 5.861, 5.862,
      5.8629999999999995, 5.864, 5.865, 5.866, 5.867, 5.868, 5.869, 5.87, 5.871,
      5.872, 5.8729999999999993, 5.8740000000000006, 5.875, 5.8759999999999994,
      5.877, 5.878, 5.879, 5.88, 5.881, 5.882, 5.883, 5.884, 5.885, 5.886,
      5.8870000000000005, 5.888, 5.8889999999999993, 5.8900000000000006, 5.891,
      5.8919999999999995, 5.893, 5.894, 5.895, 5.896, 5.897, 5.898, 5.899, 5.9,
      5.901, 5.902, 5.9030000000000005, 5.904, 5.9049999999999994,
      5.9060000000000006, 5.907, 5.9079999999999995, 5.909, 5.91, 5.911, 5.912,
      5.913, 5.914, 5.915, 5.916, 5.917, 5.918, 5.9190000000000005, 5.92,
      5.9209999999999994, 5.9220000000000006, 5.923, 5.9239999999999995, 5.925,
      5.926, 5.927, 5.928, 5.929, 5.93, 5.931, 5.932, 5.933, 5.934,
      5.9350000000000005, 5.936, 5.9369999999999994, 5.9380000000000006, 5.939,
      5.9399999999999995, 5.941, 5.942, 5.943, 5.944, 5.945, 5.946, 5.947, 5.948,
      5.949, 5.95, 5.9510000000000005, 5.952, 5.9529999999999994, 5.954, 5.955,
      5.9559999999999995, 5.957, 5.958, 5.959, 5.96, 5.961, 5.962, 5.963, 5.964,
      5.965, 5.9659999999999993, 5.9670000000000005, 5.968, 5.9689999999999994,
      5.97, 5.971, 5.9719999999999995, 5.973, 5.974, 5.975, 5.976, 5.977, 5.978,
      5.979, 5.98, 5.981, 5.9819999999999993, 5.9830000000000005, 5.984,
      5.9849999999999994, 5.986, 5.987, 5.9879999999999995, 5.989, 5.99, 5.991,
      5.992, 5.993, 5.994, 5.995, 5.996, 5.997, 5.9979999999999993,
      5.9990000000000006, 6.0, 6.0009999999999994, 6.002, 6.003, 6.004, 6.005,
      6.006, 6.007, 6.008, 6.009, 6.01, 6.011, 6.0120000000000005, 6.013, 6.014,
      6.015, 6.016, 6.0169999999999995, 6.018, 6.019, 6.02, 6.021, 6.022, 6.023,
      6.024, 6.025, 6.026, 6.027, 6.0280000000000005, 6.029, 6.03, 6.031, 6.032,
      6.0329999999999995, 6.034, 6.035, 6.036, 6.037, 6.038, 6.039, 6.04, 6.041,
      6.042, 6.043, 6.0440000000000005, 6.045, 6.046, 6.047, 6.048,
      6.0489999999999995, 6.05, 6.051, 6.052, 6.053, 6.054, 6.055, 6.056, 6.057,
      6.058, 6.059, 6.0600000000000005, 6.061, 6.062, 6.063, 6.064,
      6.0649999999999995, 6.066, 6.067, 6.068, 6.069, 6.07, 6.071, 6.072, 6.073,
      6.074, 6.075, 6.0760000000000005, 6.077, 6.078, 6.079, 6.08,
      6.0809999999999995, 6.082, 6.083, 6.084, 6.085, 6.086, 6.087, 6.088, 6.089,
      6.09, 6.091, 6.092, 6.093, 6.0939999999999994, 6.095, 6.096,
      6.0969999999999995, 6.098, 6.099, 6.1, 6.101, 6.102, 6.103, 6.104, 6.105,
      6.106, 6.107, 6.108, 6.109, 6.1099999999999994, 6.111, 6.112,
      6.1129999999999995, 6.114, 6.115, 6.116, 6.117, 6.118, 6.119, 6.12, 6.121,
      6.122, 6.123, 6.124, 6.125, 6.1259999999999994, 6.127, 6.128, 6.129, 6.13,
      6.131, 6.132, 6.133, 6.134, 6.135, 6.136, 6.1370000000000005, 6.138, 6.139,
      6.14, 6.141, 6.1419999999999995, 6.143, 6.144, 6.145, 6.146, 6.147, 6.148,
      6.149, 6.15, 6.151, 6.152, 6.1530000000000005, 6.154, 6.155, 6.156, 6.157,
      6.1579999999999995, 6.159, 6.16, 6.161, 6.162, 6.163, 6.164, 6.165, 6.166,
      6.167, 6.168, 6.1690000000000005, 6.17, 6.171, 6.172, 6.173,
      6.1739999999999995, 6.175, 6.176, 6.177, 6.178, 6.179, 6.18, 6.181, 6.182,
      6.183, 6.184, 6.1850000000000005, 6.186, 6.187, 6.188, 6.189,
      6.1899999999999995, 6.191, 6.192, 6.193, 6.194, 6.195, 6.196, 6.197, 6.198,
      6.199, 6.2, 6.2010000000000005, 6.202, 6.203, 6.204, 6.205,
      6.2059999999999995, 6.207, 6.208, 6.209, 6.21, 6.211, 6.212, 6.213, 6.214,
      6.215, 6.216, 6.217, 6.218, 6.2189999999999994, 6.22, 6.221,
      6.2219999999999995, 6.223, 6.224, 6.225, 6.226, 6.227, 6.228, 6.229, 6.23,
      6.231, 6.232, 6.233, 6.234, 6.2349999999999994, 6.236, 6.237,
      6.2379999999999995, 6.239, 6.24, 6.241, 6.242, 6.243, 6.244, 6.245, 6.246,
      6.247, 6.248, 6.249, 6.25, 6.2509999999999994, 6.252, 6.253, 6.254, 6.255,
      6.256, 6.257, 6.258, 6.259, 6.26, 6.261, 6.2620000000000005, 6.263, 6.264,
      6.265, 6.266, 6.2669999999999995, 6.268, 6.269, 6.27, 6.271, 6.272, 6.273,
      6.274, 6.275, 6.276, 6.277, 6.2780000000000005, 6.279, 6.28, 6.281, 6.282,
      6.2829999999999995, 6.284, 6.285, 6.286, 6.287, 6.288, 6.289, 6.29, 6.291,
      6.292, 6.293, 6.2940000000000005, 6.295, 6.296, 6.297, 6.298,
      6.2989999999999995, 6.3, 6.301, 6.302, 6.303, 6.304, 6.305, 6.306, 6.307,
      6.308, 6.309, 6.3100000000000005, 6.311, 6.312, 6.313, 6.314,
      6.3149999999999995, 6.316, 6.317, 6.318, 6.319, 6.32, 6.321, 6.322, 6.323,
      6.324, 6.325, 6.3260000000000005, 6.327, 6.328, 6.329, 6.33,
      6.3309999999999995, 6.332, 6.333, 6.334, 6.335, 6.336, 6.337, 6.338, 6.339,
      6.34, 6.341, 6.342, 6.343, 6.3439999999999994, 6.345, 6.346,
      6.3469999999999995, 6.348, 6.349, 6.35, 6.351, 6.352, 6.353, 6.354, 6.355,
      6.356, 6.357, 6.358, 6.359, 6.3599999999999994, 6.361, 6.362,
      6.3629999999999995, 6.364, 6.365, 6.366, 6.367, 6.368, 6.369, 6.37, 6.371,
      6.372, 6.373, 6.374, 6.375, 6.3759999999999994, 6.377, 6.378, 6.379, 6.38,
      6.381, 6.382, 6.383, 6.384, 6.385, 6.386, 6.3870000000000005, 6.388, 6.389,
      6.39, 6.391, 6.3919999999999995, 6.393, 6.394, 6.395, 6.396, 6.397, 6.398,
      6.399, 6.4, 6.401, 6.402, 6.4030000000000005, 6.404, 6.405, 6.406, 6.407,
      6.4079999999999995, 6.409, 6.41, 6.411, 6.412, 6.413, 6.414, 6.415, 6.416,
      6.417, 6.418, 6.4190000000000005, 6.42, 6.421, 6.422, 6.423,
      6.4239999999999995, 6.425, 6.426, 6.427, 6.428, 6.429, 6.43, 6.431, 6.432,
      6.433, 6.434, 6.4350000000000005, 6.436, 6.437, 6.438, 6.439,
      6.4399999999999995, 6.441, 6.442, 6.443, 6.444, 6.445, 6.446, 6.447, 6.448,
      6.449, 6.45, 6.4510000000000005, 6.452, 6.453, 6.454, 6.455,
      6.4559999999999995, 6.457, 6.458, 6.459, 6.46, 6.461, 6.462, 6.463, 6.464,
      6.465, 6.466, 6.467, 6.468, 6.4689999999999994, 6.47, 6.471,
      6.4719999999999995, 6.473, 6.474, 6.475, 6.476, 6.477, 6.478, 6.479, 6.48,
      6.481, 6.482, 6.483, 6.484, 6.4849999999999994, 6.486, 6.487,
      6.4879999999999995, 6.489, 6.49, 6.491, 6.492, 6.493, 6.494, 6.495, 6.496,
      6.497, 6.498, 6.499, 6.5, 6.5009999999999994, 6.502, 6.503, 6.504, 6.505,
      6.506, 6.507, 6.508, 6.509, 6.51, 6.511, 6.5120000000000005, 6.513, 6.514,
      6.515, 6.516, 6.5169999999999995, 6.518, 6.519, 6.52, 6.521, 6.522, 6.523,
      6.524, 6.525, 6.526, 6.527, 6.5280000000000005, 6.529, 6.53, 6.531, 6.532,
      6.5329999999999995, 6.534, 6.535, 6.536, 6.537, 6.538, 6.539, 6.54, 6.541,
      6.542, 6.543, 6.5440000000000005, 6.545, 6.546, 6.547, 6.548,
      6.5489999999999995, 6.55, 6.551, 6.552, 6.553, 6.554, 6.555, 6.556, 6.557,
      6.558, 6.559, 6.5600000000000005, 6.561, 6.562, 6.563, 6.564,
      6.5649999999999995, 6.566, 6.567, 6.568, 6.569, 6.57, 6.571, 6.572, 6.573,
      6.574, 6.575, 6.5760000000000005, 6.577, 6.578, 6.579, 6.58,
      6.5809999999999995, 6.582, 6.583, 6.584, 6.585, 6.586, 6.587, 6.588, 6.589,
      6.59, 6.591, 6.5920000000000005, 6.593, 6.5939999999999994, 6.595, 6.596,
      6.5969999999999995, 6.598, 6.599, 6.6, 6.601, 6.602, 6.603, 6.604, 6.605,
      6.606, 6.607, 6.608, 6.609, 6.6099999999999994, 6.611, 6.612,
      6.6129999999999995, 6.614, 6.615, 6.616, 6.617, 6.618, 6.619, 6.62, 6.621,
      6.622, 6.623, 6.624, 6.625, 6.6259999999999994, 6.627, 6.628, 6.629, 6.63,
      6.631, 6.632, 6.633, 6.634, 6.635, 6.636, 6.6370000000000005, 6.638, 6.639,
      6.64, 6.641, 6.6419999999999995, 6.643, 6.644, 6.645, 6.646, 6.647, 6.648,
      6.649, 6.65, 6.651, 6.652, 6.6530000000000005, 6.654, 6.655, 6.656, 6.657,
      6.6579999999999995, 6.659, 6.66, 6.661, 6.662, 6.663, 6.664, 6.665, 6.666,
      6.667, 6.668, 6.6690000000000005, 6.67, 6.671, 6.672, 6.673,
      6.6739999999999995, 6.675, 6.676, 6.677, 6.678, 6.679, 6.68, 6.681, 6.682,
      6.683, 6.684, 6.6850000000000005, 6.686, 6.687, 6.688, 6.689,
      6.6899999999999995, 6.691, 6.692, 6.693, 6.694, 6.695, 6.696, 6.697, 6.698,
      6.699, 6.7, 6.7010000000000005, 6.702, 6.703, 6.704, 6.705,
      6.7059999999999995, 6.707, 6.708, 6.709, 6.71, 6.711, 6.712, 6.713, 6.714,
      6.715, 6.716, 6.7170000000000005, 6.718, 6.719, 6.72, 6.721,
      6.7219999999999995, 6.723, 6.724, 6.725, 6.726, 6.727, 6.728, 6.729, 6.73,
      6.731, 6.732, 6.733, 6.734, 6.7349999999999994, 6.736, 6.737,
      6.7379999999999995, 6.739, 6.74, 6.741, 6.742, 6.743, 6.744, 6.745, 6.746,
      6.747, 6.748, 6.749, 6.75, 6.7509999999999994, 6.752, 6.753, 6.754, 6.755,
      6.756, 6.757, 6.758, 6.759, 6.76, 6.761, 6.7620000000000005, 6.763, 6.764,
      6.765, 6.766, 6.7669999999999995, 6.768, 6.769, 6.77, 6.771, 6.772, 6.773,
      6.774, 6.775, 6.776, 6.777, 6.7780000000000005, 6.779, 6.78, 6.781, 6.782,
      6.7829999999999995, 6.784, 6.785, 6.786, 6.787, 6.788, 6.789, 6.79, 6.791,
      6.792, 6.793, 6.7940000000000005, 6.795, 6.796, 6.797, 6.798,
      6.7989999999999995, 6.8, 6.801, 6.802, 6.803, 6.804, 6.805, 6.806, 6.807,
      6.808, 6.809, 6.8100000000000005, 6.811, 6.812, 6.813, 6.814,
      6.8149999999999995, 6.816, 6.817, 6.818, 6.819, 6.82, 6.821, 6.822, 6.823,
      6.824, 6.825, 6.8260000000000005, 6.827, 6.828, 6.829, 6.83,
      6.8309999999999995, 6.832, 6.833, 6.834, 6.835, 6.836, 6.837, 6.838, 6.839,
      6.84, 6.841, 6.8420000000000005, 6.843, 6.844, 6.845, 6.846,
      6.8469999999999995, 6.848, 6.849, 6.85, 6.851, 6.852, 6.853, 6.854, 6.855,
      6.856, 6.857, 6.858, 6.859, 6.8599999999999994, 6.861, 6.862,
      6.8629999999999995, 6.864, 6.865, 6.866, 6.867, 6.868, 6.869, 6.87, 6.871,
      6.872, 6.873, 6.874, 6.875, 6.8759999999999994, 6.877, 6.878, 6.879, 6.88,
      6.881, 6.882, 6.883, 6.884, 6.885, 6.886, 6.8870000000000005, 6.888, 6.889,
      6.89, 6.891, 6.8919999999999995, 6.893, 6.894, 6.895, 6.896, 6.897, 6.898,
      6.899, 6.9, 6.901, 6.902, 6.9030000000000005, 6.904, 6.905, 6.906, 6.907,
      6.9079999999999995, 6.909, 6.91, 6.911, 6.912, 6.913, 6.914, 6.915, 6.916,
      6.917, 6.918, 6.9190000000000005, 6.92, 6.921, 6.922, 6.923,
      6.9239999999999995, 6.925, 6.926, 6.927, 6.928, 6.929, 6.93, 6.931, 6.932,
      6.933, 6.934, 6.9350000000000005, 6.936, 6.937, 6.938, 6.939,
      6.9399999999999995, 6.941, 6.942, 6.943, 6.944, 6.945, 6.946, 6.947, 6.948,
      6.949, 6.95, 6.9510000000000005, 6.952, 6.953, 6.954, 6.955,
      6.9559999999999995, 6.957, 6.958, 6.959, 6.96, 6.961, 6.962, 6.963, 6.964,
      6.965, 6.966, 6.9670000000000005, 6.968, 6.969, 6.97, 6.971,
      6.9719999999999995, 6.973, 6.974, 6.975, 6.976, 6.977, 6.978, 6.979, 6.98,
      6.981, 6.982, 6.983, 6.984, 6.9849999999999994, 6.986, 6.987,
      6.9879999999999995, 6.989, 6.99, 6.991, 6.992, 6.993, 6.994, 6.995, 6.996,
      6.997, 6.998, 6.999, 7.0, 7.001, 7.002, 7.003, 7.004, 7.005, 7.006, 7.007,
      7.008, 7.009, 7.01, 7.011, 7.0120000000000005, 7.013, 7.014, 7.015, 7.016,
      7.017, 7.018, 7.019, 7.02, 7.021, 7.022, 7.023, 7.024, 7.025, 7.026, 7.027,
      7.0280000000000005, 7.029, 7.03, 7.031, 7.032, 7.033, 7.034, 7.035, 7.036,
      7.037, 7.038, 7.039, 7.04, 7.041, 7.042, 7.043, 7.044, 7.045, 7.046, 7.047,
      7.048, 7.0489999999999995, 7.05, 7.051, 7.052, 7.053, 7.054, 7.055, 7.056,
      7.057, 7.058, 7.059, 7.06, 7.061, 7.062, 7.063, 7.064, 7.0649999999999995,
      7.066, 7.067, 7.068, 7.069, 7.07, 7.071, 7.072, 7.073, 7.074, 7.075, 7.076,
      7.077, 7.078, 7.079, 7.08, 7.0809999999999995, 7.082, 7.083, 7.084, 7.085,
      7.086, 7.087, 7.088, 7.089, 7.09, 7.091, 7.092, 7.093, 7.094, 7.095, 7.096,
      7.0969999999999995, 7.098, 7.099, 7.1, 7.101, 7.102, 7.103, 7.104, 7.105,
      7.106, 7.107, 7.108, 7.109, 7.11, 7.111, 7.112, 7.1129999999999995, 7.114,
      7.115, 7.116, 7.117, 7.118, 7.119, 7.12, 7.121, 7.122, 7.123, 7.124, 7.125,
      7.126, 7.127, 7.128, 7.129, 7.13, 7.131, 7.132, 7.133, 7.134, 7.135, 7.136,
      7.1370000000000005, 7.138, 7.139, 7.14, 7.141, 7.142, 7.143, 7.144, 7.145,
      7.146, 7.147, 7.148, 7.149, 7.15, 7.151, 7.152, 7.1530000000000005, 7.154,
      7.155, 7.156, 7.157, 7.158, 7.159, 7.16, 7.161, 7.162, 7.163, 7.164, 7.165,
      7.166, 7.167, 7.168, 7.169, 7.17, 7.171, 7.172, 7.173, 7.1739999999999995,
      7.175, 7.176, 7.177, 7.178, 7.179, 7.18, 7.181, 7.182, 7.183, 7.184, 7.185,
      7.186, 7.187, 7.188, 7.189, 7.1899999999999995, 7.191, 7.192, 7.193, 7.194,
      7.195, 7.196, 7.197, 7.198, 7.199, 7.2, 7.201, 7.202, 7.203, 7.204, 7.205,
      7.2059999999999995, 7.207, 7.208, 7.209, 7.21, 7.211, 7.212, 7.213, 7.214,
      7.215, 7.216, 7.217, 7.218, 7.219, 7.22, 7.221, 7.2219999999999995, 7.223,
      7.224, 7.225, 7.226, 7.227, 7.228, 7.229, 7.23, 7.231, 7.232, 7.233, 7.234,
      7.235, 7.236, 7.237, 7.2379999999999995, 7.239, 7.24, 7.241, 7.242, 7.243,
      7.244, 7.245, 7.246, 7.247, 7.248, 7.249, 7.25, 7.251, 7.252, 7.253, 7.254,
      7.255, 7.256, 7.257, 7.258, 7.259, 7.26, 7.261, 7.2620000000000005, 7.263,
      7.264, 7.265, 7.266, 7.267, 7.268, 7.269, 7.27, 7.271, 7.272, 7.273, 7.274,
      7.275, 7.276, 7.277, 7.2780000000000005, 7.279, 7.28, 7.281, 7.282, 7.283,
      7.284, 7.285, 7.286, 7.287, 7.288, 7.289, 7.29, 7.291, 7.292, 7.293,
      7.2940000000000005, 7.295, 7.296, 7.297, 7.298, 7.2989999999999995, 7.3,
      7.301, 7.302, 7.303, 7.304, 7.305, 7.306, 7.307, 7.308, 7.309, 7.31, 7.311,
      7.312, 7.313, 7.314, 7.3149999999999995, 7.316, 7.317, 7.318, 7.319, 7.32,
      7.321, 7.322, 7.323, 7.324, 7.325, 7.326, 7.327, 7.328, 7.329, 7.33,
      7.3309999999999995, 7.332, 7.333, 7.334, 7.335, 7.336, 7.337, 7.338, 7.339,
      7.34, 7.341, 7.342, 7.343, 7.344, 7.345, 7.346, 7.3469999999999995, 7.348,
      7.349, 7.35, 7.351, 7.352, 7.353, 7.354, 7.355, 7.356, 7.357, 7.358, 7.359,
      7.36, 7.361, 7.362, 7.3629999999999995, 7.364, 7.365, 7.366, 7.367, 7.368,
      7.369, 7.37, 7.371, 7.372, 7.373, 7.374, 7.375, 7.376, 7.377, 7.378, 7.379,
      7.38, 7.381, 7.382, 7.383, 7.384, 7.385, 7.386, 7.3870000000000005, 7.388,
      7.389, 7.39, 7.391, 7.392, 7.393, 7.394, 7.395, 7.396, 7.397, 7.398, 7.399,
      7.4, 7.401, 7.402, 7.4030000000000005, 7.404, 7.405, 7.406, 7.407, 7.408,
      7.409, 7.41, 7.411, 7.412, 7.413, 7.414, 7.415, 7.416, 7.417, 7.418,
      7.4190000000000005, 7.42, 7.421, 7.422, 7.423, 7.4239999999999995, 7.425,
      7.426, 7.427, 7.428, 7.429, 7.43, 7.431, 7.432, 7.433, 7.434, 7.435, 7.436,
      7.437, 7.438, 7.439, 7.4399999999999995, 7.441, 7.442, 7.443, 7.444, 7.445,
      7.446, 7.447, 7.448, 7.449, 7.45, 7.451, 7.452, 7.453, 7.454, 7.455,
      7.4559999999999995, 7.457, 7.458, 7.459, 7.46, 7.461, 7.462, 7.463, 7.464,
      7.465, 7.466, 7.467, 7.468, 7.469, 7.47, 7.471, 7.4719999999999995, 7.473,
      7.474, 7.475, 7.476, 7.477, 7.478, 7.479, 7.48, 7.481, 7.482, 7.483, 7.484,
      7.485, 7.486, 7.487, 7.4879999999999995, 7.489, 7.49, 7.491, 7.492, 7.493,
      7.494, 7.495, 7.496, 7.497, 7.498, 7.499, 7.5, 7.501, 7.502, 7.503, 7.504,
      7.505, 7.506, 7.507, 7.508, 7.509, 7.51, 7.511, 7.5120000000000005, 7.513,
      7.514, 7.515, 7.516, 7.517, 7.518, 7.519, 7.52, 7.521, 7.522, 7.523, 7.524,
      7.525, 7.526, 7.527, 7.528, 7.529, 7.53, 7.531, 7.532, 7.533, 7.534, 7.535,
      7.536, 7.537, 7.538, 7.539, 7.54, 7.541, 7.542, 7.543, 7.544, 7.545, 7.546,
      7.547, 7.548, 7.549, 7.55, 7.551, 7.552, 7.553, 7.554, 7.555, 7.556, 7.557,
      7.558, 7.559, 7.56, 7.561, 7.562, 7.563, 7.564, 7.565, 7.566, 7.567, 7.568,
      7.569, 7.57, 7.571, 7.572, 7.573, 7.574, 7.575, 7.576, 7.577, 7.578, 7.579,
      7.58, 7.581, 7.582, 7.583, 7.584, 7.585, 7.586, 7.587, 7.588, 7.589, 7.59,
      7.591, 7.592, 7.593, 7.594, 7.595, 7.596, 7.5969999999999995, 7.598, 7.599,
      7.6, 7.601, 7.602, 7.603, 7.604, 7.605, 7.606, 7.607, 7.608, 7.609, 7.61,
      7.611, 7.612, 7.6129999999999995, 7.614, 7.615, 7.616, 7.617, 7.618, 7.619,
      7.62, 7.621, 7.622, 7.623, 7.624, 7.625, 7.626, 7.627, 7.628, 7.629, 7.63,
      7.631, 7.632, 7.633, 7.634, 7.635, 7.636, 7.6370000000000005, 7.638, 7.639,
      7.64, 7.641, 7.642, 7.643, 7.644, 7.645, 7.646, 7.647, 7.648, 7.649, 7.65,
      7.651, 7.652, 7.653, 7.654, 7.655, 7.656, 7.657, 7.658, 7.659, 7.66, 7.661,
      7.662, 7.663, 7.664, 7.665, 7.666, 7.667, 7.668, 7.669, 7.67, 7.671, 7.672,
      7.673, 7.674, 7.675, 7.676, 7.677, 7.678, 7.679, 7.68, 7.681, 7.682, 7.683,
      7.684, 7.685, 7.686, 7.687, 7.688, 7.689, 7.69, 7.691, 7.692, 7.693, 7.694,
      7.695, 7.696, 7.697, 7.698, 7.699, 7.7, 7.701, 7.702, 7.703, 7.704, 7.705,
      7.706, 7.707, 7.708, 7.709, 7.71, 7.711, 7.712, 7.713, 7.714, 7.715, 7.716,
      7.717, 7.718, 7.719, 7.72, 7.721, 7.7219999999999995, 7.723, 7.724, 7.725,
      7.726, 7.727, 7.728, 7.729, 7.73, 7.731, 7.732, 7.733, 7.734, 7.735, 7.736,
      7.737, 7.7379999999999995, 7.739, 7.74, 7.741, 7.742, 7.743, 7.744, 7.745,
      7.746, 7.747, 7.748, 7.749, 7.75, 7.751, 7.752, 7.753, 7.754, 7.755, 7.756,
      7.757, 7.758, 7.759, 7.76, 7.761, 7.762, 7.763, 7.764, 7.765, 7.766, 7.767,
      7.768, 7.769, 7.77, 7.771, 7.772, 7.773, 7.774, 7.775, 7.776, 7.777, 7.778,
      7.779, 7.78, 7.781, 7.782, 7.783, 7.784, 7.785, 7.786, 7.787, 7.788, 7.789,
      7.79, 7.791, 7.792, 7.793, 7.794, 7.795, 7.796, 7.797, 7.798, 7.799, 7.8,
      7.801, 7.802, 7.803, 7.804, 7.805, 7.806, 7.807, 7.808, 7.809, 7.81, 7.811,
      7.812, 7.813, 7.814, 7.815, 7.816, 7.817, 7.818, 7.819, 7.82, 7.821, 7.822,
      7.823, 7.824, 7.825, 7.826, 7.827, 7.828, 7.829, 7.83, 7.831, 7.832, 7.833,
      7.834, 7.835, 7.836, 7.837, 7.838, 7.839, 7.84, 7.841, 7.842, 7.843, 7.844,
      7.845, 7.846, 7.847, 7.848, 7.849, 7.85, 7.851, 7.852, 7.853, 7.854, 7.855,
      7.856, 7.857, 7.858, 7.859, 7.86, 7.861, 7.862, 7.8629999999999995, 7.864,
      7.865, 7.866, 7.867, 7.868, 7.869, 7.87, 7.871, 7.872, 7.873, 7.874, 7.875,
      7.876, 7.877, 7.878, 7.879, 7.88, 7.881, 7.882, 7.883, 7.884, 7.885, 7.886,
      7.887, 7.888, 7.889, 7.89, 7.891, 7.892, 7.893, 7.894, 7.895, 7.896, 7.897,
      7.898, 7.899, 7.9, 7.901, 7.902, 7.903, 7.904, 7.905, 7.906, 7.907, 7.908,
      7.909, 7.91, 7.911, 7.912, 7.913, 7.914, 7.915, 7.916, 7.917, 7.918, 7.919,
      7.92, 7.921, 7.922, 7.923, 7.924, 7.925, 7.926, 7.927, 7.928, 7.929, 7.93,
      7.931, 7.932, 7.933, 7.934, 7.935, 7.936, 7.937, 7.938, 7.939, 7.94, 7.941,
      7.942, 7.943, 7.944, 7.945, 7.946, 7.947, 7.948, 7.949, 7.95, 7.951, 7.952,
      7.953, 7.954, 7.955, 7.956, 7.957, 7.958, 7.959, 7.96, 7.961, 7.962, 7.963,
      7.964, 7.965, 7.966, 7.967, 7.968, 7.969, 7.97, 7.971, 7.972, 7.973, 7.974,
      7.975, 7.976, 7.977, 7.978, 7.979, 7.98, 7.981, 7.982, 7.983, 7.984, 7.985,
      7.986, 7.987, 7.988, 7.989, 7.99, 7.991, 7.992, 7.993, 7.994, 7.995, 7.996,
      7.997, 7.998, 7.999, 8.0 } ;

    static real_T pDataValues0[] = { -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623,
      -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.2623, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999992,
      -0.26229999999999992, -0.26229999999999992, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999987,
      -0.26229999999999987, -0.26229999999999987, -0.26229999999999981,
      -0.26229999999999981, -0.26229999999999981, -0.26229999999999981,
      -0.26229999999999981, -0.26229999999999981, -0.26229999999999981,
      -0.26229999999999981, -0.26229999999999981, -0.26229999999999981,
      -0.26229999999999981, -0.26229999999999981, -0.26229999999999981,
      -0.26229999999999981, -0.26229999999999981, -0.26229999999999981,
      -0.26229999999999981, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.26229999999999976, -0.26229999999999976, -0.26229999999999976,
      -0.2622999999999997, -0.2622999999999997, -0.2622999999999997,
      -0.2622999999999997, -0.2622999999999997, -0.2622999999999997,
      -0.2622999999999997, -0.2622999999999997, -0.2622999999999997,
      -0.2622999999999997, -0.26229999999999964, -0.26229999999999964,
      -0.26229999999999964, -0.26229999999999964, -0.26229999999999964,
      -0.26229999999999964, -0.26229999999999964, -0.26229999999999964,
      -0.26229999999999964, -0.26229999999999964, -0.26229999999999964,
      -0.26229999999999964, -0.26229999999999964, -0.26229999999999964,
      -0.26229999999999964, -0.26229999999999964, -0.26229999999999964,
      -0.26229999999999964, -0.26229999999999964, -0.26229999999999964,
      -0.26229999999999964, -0.26229999999999964, -0.26229999999999964,
      -0.26229999999999964, -0.26229999999999964, -0.26229999999999959,
      -0.26229999999999959, -0.26229999999999959, -0.26229999999999959,
      -0.26229999999999959, -0.26229999999999959, -0.26229999999999959,
      -0.26229999999999953, -0.26229999999999953, -0.26229999999999953,
      -0.26229999999999953, -0.26229999999999953, -0.26229999999999953,
      -0.26229999999999953, -0.26229999999999953, -0.26229999999999953,
      -0.26229999999999953, -0.26229999999999953, -0.26229999999999953,
      -0.26229999999999953, -0.26229999999999953, -0.26229999999999953,
      -0.26229999999999953, -0.26229999999999953, -0.26229999999999953,
      -0.26229999999999953, -0.26229999999999948, -0.26229999999999948,
      -0.26229999999999948, -0.26229999999999948, -0.26229999999999948,
      -0.26229999999999948, -0.26229999999999942, -0.26229999999999942,
      -0.26229999999999942, -0.26229999999999942, -0.26229999999999942,
      -0.26229999999999942, -0.26229999999999942, -0.26229999999999942,
      -0.26229999999999942, -0.26229999999999942, -0.26229999999999942,
      -0.26229999999999942, -0.26229999999999942, -0.26229999999999942,
      -0.26229999999999942, -0.26229999999999937, -0.26229999999999937,
      -0.26229999999999937, -0.26229999999999937, -0.26229999999999931,
      -0.26229999999999931, -0.26229999999999931, -0.26229999999999931,
      -0.26229999999999931, -0.26229999999999931, -0.26229999999999931,
      -0.26229999999999931, -0.26229999999999931, -0.26229999999999931,
      -0.26229999999999931, -0.26229999999999931, -0.26229999999999931,
      -0.26229999999999926, -0.26229999999999926, -0.26229999999999926,
      -0.26229999999999926, -0.2622999999999992, -0.2622999999999992,
      -0.2622999999999992, -0.2622999999999992, -0.2622999999999992,
      -0.2622999999999992, -0.2622999999999992, -0.2622999999999992,
      -0.2622999999999992, -0.2622999999999992, -0.26229999999999914,
      -0.26229999999999914, -0.26229999999999914, -0.26229999999999914,
      -0.26229999999999909, -0.26229999999999909, -0.26229999999999909,
      -0.26229999999999909, -0.26229999999999909, -0.26229999999999909,
      -0.26229999999999909, -0.26229999999999909, -0.26229999999999909,
      -0.26229999999999903, -0.26229999999999903, -0.26229999999999903,
      -0.262299999999999, -0.262299999999999, -0.262299999999999,
      -0.262299999999999, -0.262299999999999, -0.262299999999999,
      -0.262299999999999, -0.262299999999999, -0.26229999999999892,
      -0.26229999999999892, -0.26229999999999892, -0.26229999999999887,
      -0.26229999999999887, -0.26229999999999887, -0.26229999999999887,
      -0.26229999999999887, -0.26229999999999887, -0.26229999999999887,
      -0.26229999999999887, -0.26229999999999881, -0.26229999999999881,
      -0.26229999999999876, -0.26229999999999876, -0.26229999999999876,
      -0.26229999999999876, -0.26229999999999876, -0.26229999999999876,
      -0.26229999999999876, -0.2622999999999987, -0.2622999999999987,
      -0.26229999999999865, -0.26229999999999865, -0.26229999999999865,
      -0.26229999999999865, -0.26229999999999865, -0.26229999999999865,
      -0.26229999999999859, -0.26229999999999859, -0.26229999999999853,
      -0.26229999999999853, -0.26229999999999853, -0.26229999999999853,
      -0.26229999999999853, -0.26229999999999853, -0.26229999999999848,
      -0.26229999999999848, -0.26229999999999842, -0.26229999999999842,
      -0.26229999999999842, -0.26229999999999842, -0.26229999999999842,
      -0.26229999999999837, -0.26229999999999837, -0.26229999999999831,
      -0.26229999999999831, -0.26229999999999831, -0.26229999999999831,
      -0.26229999999999831, -0.26229999999999826, -0.26229999999999826,
      -0.2622999999999982, -0.2622999999999982, -0.2622999999999982,
      -0.2622999999999982, -0.26229999999999815, -0.26229999999999815,
      -0.26229999999999809, -0.26229999999999809, -0.26229999999999809,
      -0.26229999999999809, -0.26229999999999803, -0.26229999999999803,
      -0.262299999999998, -0.262299999999998, -0.262299999999998,
      -0.262299999999998, -0.26229999999999792, -0.26229999999999787,
      -0.26229999999999787, -0.26229999999999787, -0.26229999999999787,
      -0.26229999999999781, -0.26229999999999776, -0.26229999999999776,
      -0.26229999999999776, -0.26229999999999776, -0.2622999999999977,
      -0.26229999999999765, -0.26229999999999765, -0.26229999999999765,
      -0.26229999999999765, -0.26229999999999759, -0.26229999999999754,
      -0.26229999999999754, -0.26229999999999754, -0.26229999999999748,
      -0.26229999999999748, -0.26229999999999742, -0.26229999999999742,
      -0.26229999999999742, -0.26229999999999737, -0.26229999999999731,
      -0.26229999999999731, -0.26229999999999731, -0.26229999999999726,
      -0.2622999999999972, -0.2622999999999972, -0.2622999999999972,
      -0.26229999999999715, -0.26229999999999709, -0.26229999999999709,
      -0.26229999999999709, -0.26229999999999704, -0.262299999999997,
      -0.262299999999997, -0.262299999999997, -0.26229999999999692,
      -0.26229999999999687, -0.26229999999999687, -0.26229999999999681,
      -0.26229999999999676, -0.26229999999999676, -0.26229999999999676,
      -0.2622999999999967, -0.26229999999999665, -0.26229999999999665,
      -0.26229999999999659, -0.26229999999999654, -0.26229999999999654,
      -0.26229999999999648, -0.26229999999999642, -0.26229999999999642,
      -0.26229999999999637, -0.26229999999999631, -0.26229999999999631,
      -0.26229999999999626, -0.2622999999999962, -0.2622999999999962,
      -0.26229999999999615, -0.26229999999999609, -0.26229999999999609,
      -0.26229999999999604, -0.262299999999996, -0.262299999999996,
      -0.26229999999999593, -0.26229999999999587, -0.26229999999999587,
      -0.26229999999999576, -0.26229999999999576, -0.2622999999999957,
      -0.26229999999999565, -0.26229999999999565, -0.26229999999999559,
      -0.26229999999999554, -0.26229999999999548, -0.26229999999999543,
      -0.26229999999999543, -0.26229999999999537, -0.26229999999999531,
      -0.26229999999999526, -0.2622999999999952, -0.2622999999999952,
      -0.26229999999999509, -0.26229999999999509, -0.262299999999995,
      -0.262299999999995, -0.26229999999999493, -0.26229999999999487,
      -0.26229999999999482, -0.26229999999999476, -0.2622999999999947,
      -0.26229999999999465, -0.26229999999999465, -0.26229999999999454,
      -0.26229999999999454, -0.26229999999999443, -0.26229999999999443,
      -0.26229999999999432, -0.26229999999999432, -0.2622999999999942,
      -0.26229999999999415, -0.26229999999999409, -0.26229999999999404,
      -0.262299999999994, -0.26229999999999393, -0.26229999999999387,
      -0.26229999999999382, -0.26229999999999376, -0.26229999999999365,
      -0.26229999999999365, -0.26229999999999354, -0.26229999999999348,
      -0.26229999999999343, -0.26229999999999332, -0.26229999999999332,
      -0.26229999999999321, -0.26229999999999315, -0.26229999999999309,
      -0.262299999999993, -0.262299999999993, -0.26229999999999287,
      -0.26229999999999282, -0.26229999999999276, -0.26229999999999265,
      -0.26229999999999259, -0.26229999999999254, -0.26229999999999243,
      -0.26229999999999237, -0.26229999999999232, -0.26229999999999221,
      -0.2622999999999921, -0.26229999999999204, -0.262299999999992,
      -0.26229999999999187, -0.26229999999999182, -0.26229999999999176,
      -0.26229999999999165, -0.26229999999999154, -0.26229999999999148,
      -0.26229999999999143, -0.26229999999999132, -0.26229999999999121,
      -0.2622999999999911, -0.26229999999999104, -0.262299999999991,
      -0.26229999999999087, -0.26229999999999076, -0.26229999999999065,
      -0.26229999999999054, -0.26229999999999049, -0.26229999999999043,
      -0.26229999999999032, -0.26229999999999021, -0.2622999999999901,
      -0.26229999999999, -0.26229999999998987, -0.26229999999998976,
      -0.26229999999998971, -0.2622999999999896, -0.26229999999998949,
      -0.26229999999998937, -0.26229999999998926, -0.26229999999998921,
      -0.2622999999999891, -0.262299999999989, -0.26229999999998888,
      -0.26229999999998876, -0.26229999999998865, -0.26229999999998849,
      -0.26229999999998838, -0.26229999999998826, -0.26229999999998815,
      -0.26229999999998804, -0.26229999999998788, -0.26229999999998777,
      -0.26229999999998765, -0.26229999999998754, -0.26229999999998743,
      -0.26229999999998732, -0.26229999999998715, -0.26229999999998704,
      -0.26229999999998688, -0.26229999999998677, -0.26229999999998665,
      -0.26229999999998654, -0.26229999999998638, -0.26229999999998621,
      -0.2622999999999861, -0.262299999999986, -0.26229999999998582,
      -0.26229999999998566, -0.26229999999998554, -0.26229999999998538,
      -0.26229999999998521, -0.2622999999999851, -0.26229999999998493,
      -0.26229999999998477, -0.26229999999998466, -0.26229999999998449,
      -0.26229999999998432, -0.26229999999998416, -0.262299999999984,
      -0.26229999999998388, -0.26229999999998366, -0.26229999999998355,
      -0.26229999999998332, -0.26229999999998321, -0.262299999999983,
      -0.26229999999998288, -0.26229999999998266, -0.26229999999998255,
      -0.26229999999998233, -0.26229999999998216, -0.262299999999982,
      -0.26229999999998177, -0.2622999999999816, -0.26229999999998144,
      -0.26229999999998121, -0.26229999999998105, -0.26229999999998088,
      -0.26229999999998066, -0.26229999999998044, -0.26229999999998027,
      -0.2622999999999801, -0.26229999999997988, -0.26229999999997966,
      -0.26229999999997944, -0.26229999999997927, -0.26229999999997905,
      -0.26229999999997888, -0.26229999999997866, -0.26229999999997844,
      -0.26229999999997822, -0.262299999999978, -0.26229999999997777,
      -0.26229999999997755, -0.26229999999997733, -0.26229999999997711,
      -0.26229999999997688, -0.26229999999997666, -0.26229999999997639,
      -0.26229999999997616, -0.26229999999997589, -0.26229999999997566,
      -0.26229999999997544, -0.26229999999997522, -0.26229999999997494,
      -0.26229999999997466, -0.26229999999997444, -0.26229999999997416,
      -0.26229999999997389, -0.26229999999997367, -0.26229999999997339,
      -0.26229999999997311, -0.26229999999997289, -0.26229999999997256,
      -0.26229999999997233, -0.262299999999972, -0.26229999999997178,
      -0.26229999999997144, -0.26229999999997117, -0.26229999999997089,
      -0.26229999999997056, -0.26229999999997033, -0.26229999999997,
      -0.26229999999996967, -0.26229999999996939, -0.26229999999996911,
      -0.26229999999996878, -0.26229999999996845, -0.26229999999996811,
      -0.26229999999996784, -0.2622999999999675, -0.26229999999996717,
      -0.26229999999996684, -0.2622999999999665, -0.26229999999996617,
      -0.26229999999996584, -0.26229999999996551, -0.26229999999996512,
      -0.26229999999996478, -0.26229999999996445, -0.26229999999996412,
      -0.26229999999996373, -0.26229999999996334, -0.262299999999963,
      -0.26229999999996262, -0.26229999999996223, -0.2622999999999619,
      -0.26229999999996145, -0.26229999999996112, -0.26229999999996068,
      -0.26229999999996034, -0.2622999999999599, -0.26229999999995951,
      -0.26229999999995912, -0.26229999999995868, -0.26229999999995829,
      -0.26229999999995784, -0.26229999999995746, -0.262299999999957,
      -0.26229999999995657, -0.26229999999995612, -0.26229999999995568,
      -0.26229999999995524, -0.26229999999995479, -0.26229999999995435,
      -0.2622999999999539, -0.26229999999995346, -0.26229999999995296,
      -0.26229999999995246, -0.262299999999952, -0.26229999999995152,
      -0.262299999999951, -0.26229999999995057, -0.26229999999995,
      -0.26229999999994957, -0.262299999999949, -0.26229999999994857,
      -0.262299999999948, -0.26229999999994746, -0.26229999999994696,
      -0.26229999999994646, -0.26229999999994591, -0.26229999999994535,
      -0.2622999999999448, -0.26229999999994424, -0.26229999999994369,
      -0.26229999999994313, -0.26229999999994258, -0.26229999999994197,
      -0.26229999999994136, -0.2622999999999408, -0.26229999999994025,
      -0.26229999999993958, -0.262299999999939, -0.26229999999993836,
      -0.26229999999993781, -0.26229999999993714, -0.26229999999993647,
      -0.26229999999993586, -0.26229999999993525, -0.26229999999993459,
      -0.26229999999993392, -0.26229999999993325, -0.26229999999993259,
      -0.26229999999993192, -0.26229999999993125, -0.26229999999993053,
      -0.26229999999992981, -0.26229999999992915, -0.26229999999992842,
      -0.2622999999999277, -0.262299999999927, -0.26229999999992626,
      -0.26229999999992548, -0.26229999999992476, -0.262299999999924,
      -0.26229999999992326, -0.26229999999992248, -0.26229999999992171,
      -0.26229999999992093, -0.2622999999999201, -0.26229999999991926,
      -0.26229999999991849, -0.26229999999991765, -0.26229999999991682,
      -0.26229999999991604, -0.26229999999991516, -0.26229999999991427,
      -0.26229999999991344, -0.2622999999999126, -0.26229999999991171,
      -0.26229999999991083, -0.26229999999990994, -0.26229999999990905,
      -0.26229999999990811, -0.26229999999990716, -0.26229999999990627,
      -0.26229999999990528, -0.26229999999990433, -0.26229999999990339,
      -0.26229999999990239, -0.26229999999990145, -0.26229999999990045,
      -0.26229999999989945, -0.26229999999989839, -0.26229999999989739,
      -0.26229999999989639, -0.26229999999989534, -0.26229999999989428,
      -0.26229999999989323, -0.26229999999989217, -0.26229999999989106,
      -0.26229999999988995, -0.26229999999988884, -0.26229999999988773,
      -0.26229999999988662, -0.26229999999988551, -0.26229999999988435,
      -0.26229999999988318, -0.26229999999988196, -0.26229999999988085,
      -0.26229999999987963, -0.26229999999987841, -0.26229999999987719,
      -0.26229999999987597, -0.26229999999987469, -0.26229999999987341,
      -0.26229999999987219, -0.26229999999987086, -0.26229999999986958,
      -0.26229999999986831, -0.262299999999867, -0.26229999999986564,
      -0.26229999999986431, -0.26229999999986287, -0.26229999999986153,
      -0.26229999999986015, -0.26229999999985876, -0.26229999999985731,
      -0.26229999999985587, -0.26229999999985443, -0.262299999999853,
      -0.26229999999985149, -0.26229999999985, -0.26229999999984849,
      -0.262299999999847, -0.26229999999984543, -0.26229999999984388,
      -0.26229999999984233, -0.26229999999984072, -0.26229999999983911,
      -0.2622999999998375, -0.26229999999983589, -0.26229999999983422,
      -0.26229999999983256, -0.26229999999983089, -0.26229999999982917,
      -0.26229999999982745, -0.26229999999982573, -0.262299999999824,
      -0.26229999999982223, -0.26229999999982045, -0.26229999999981862,
      -0.26229999999981679, -0.26229999999981496, -0.26229999999981313,
      -0.26229999999981124, -0.26229999999980935, -0.26229999999980741,
      -0.26229999999980547, -0.26229999999980347, -0.26229999999980153,
      -0.26229999999979953, -0.26229999999979753, -0.26229999999979547,
      -0.26229999999979342, -0.26229999999979137, -0.26229999999978926,
      -0.26229999999978715, -0.26229999999978504, -0.26229999999978282,
      -0.26229999999978065, -0.26229999999977849, -0.26229999999977627,
      -0.262299999999774, -0.26229999999977172, -0.26229999999976938,
      -0.26229999999976711, -0.26229999999976472, -0.26229999999976239,
      -0.26229999999976, -0.26229999999975762, -0.26229999999975517,
      -0.26229999999975273, -0.26229999999975018, -0.26229999999974773,
      -0.26229999999974518, -0.26229999999974263, -0.26229999999974,
      -0.26229999999973741, -0.26229999999973475, -0.26229999999973208,
      -0.26229999999972942, -0.2622999999997267, -0.262299999999724,
      -0.2622999999997212, -0.26229999999971837, -0.26229999999971554,
      -0.26229999999971265, -0.26229999999970977, -0.26229999999970688,
      -0.26229999999970394, -0.262299999999701, -0.26229999999969794,
      -0.26229999999969489, -0.26229999999969189, -0.26229999999968878,
      -0.26229999999968562, -0.26229999999968245, -0.26229999999967929,
      -0.262299999999676, -0.26229999999967279, -0.26229999999966952,
      -0.26229999999966619, -0.2622999999996628, -0.26229999999965947,
      -0.26229999999965603, -0.26229999999965259, -0.26229999999964904,
      -0.26229999999964554, -0.262299999999642, -0.26229999999963838,
      -0.26229999999963471, -0.26229999999963105, -0.26229999999962739,
      -0.26229999999962361, -0.26229999999961984, -0.26229999999961606,
      -0.26229999999961218, -0.26229999999960829, -0.26229999999960429,
      -0.26229999999960035, -0.26229999999959636, -0.2622999999995923,
      -0.2622999999995882, -0.26229999999958409, -0.26229999999957987,
      -0.26229999999957565, -0.26229999999957138, -0.2622999999995671,
      -0.26229999999956272, -0.26229999999955833, -0.26229999999955389,
      -0.26229999999954945, -0.2622999999995449, -0.26229999999954035,
      -0.26229999999953568, -0.262299999999531, -0.2622999999995263,
      -0.26229999999952158, -0.26229999999951675, -0.26229999999951192,
      -0.262299999999507, -0.26229999999950204, -0.26229999999949705,
      -0.26229999999949194, -0.26229999999948683, -0.26229999999948173,
      -0.26229999999947651, -0.26229999999947123, -0.2622999999994659,
      -0.26229999999946052, -0.26229999999945514, -0.26229999999944964,
      -0.26229999999944409, -0.26229999999943854, -0.26229999999943288,
      -0.26229999999942721, -0.26229999999942144, -0.26229999999941561,
      -0.26229999999940978, -0.26229999999940379, -0.26229999999939779,
      -0.2622999999993918, -0.26229999999938569, -0.26229999999937947,
      -0.26229999999937326, -0.26229999999936693, -0.2622999999993606,
      -0.26229999999935416, -0.26229999999934767, -0.26229999999934112,
      -0.26229999999933451, -0.26229999999932785, -0.26229999999932108,
      -0.26229999999931419, -0.26229999999930731, -0.26229999999930037,
      -0.26229999999929332, -0.26229999999928622, -0.26229999999927911,
      -0.26229999999927184, -0.26229999999926451, -0.26229999999925713,
      -0.26229999999924969, -0.26229999999924214, -0.26229999999923448,
      -0.26229999999922682, -0.26229999999921905, -0.26229999999921116,
      -0.26229999999920328, -0.26229999999919523, -0.26229999999918718,
      -0.26229999999917897, -0.26229999999917075, -0.26229999999916243,
      -0.262299999999154, -0.26229999999914549, -0.26229999999913689,
      -0.26229999999912823, -0.26229999999911946, -0.26229999999911058,
      -0.2622999999991017, -0.26229999999909265, -0.26229999999908349,
      -0.26229999999907427, -0.262299999999065, -0.26229999999905562,
      -0.26229999999904613, -0.26229999999903653, -0.26229999999902687,
      -0.2622999999990171, -0.26229999999900722, -0.26229999999899722,
      -0.26229999999898712, -0.26229999999897696, -0.26229999999896669,
      -0.26229999999895626, -0.26229999999894582, -0.26229999999893522,
      -0.2622999999989245, -0.26229999999891374, -0.26229999999890274,
      -0.26229999999889175, -0.26229999999888065, -0.26229999999886938,
      -0.262299999998858, -0.26229999999884657, -0.26229999999883491,
      -0.26229999999882325, -0.26229999999881137, -0.26229999999879949,
      -0.26229999999878739, -0.26229999999877518, -0.26229999999876286,
      -0.26229999999875048, -0.26229999999873788, -0.26229999999872522,
      -0.2622999999987124, -0.26229999999869946, -0.26229999999868636,
      -0.26229999999867321, -0.26229999999865983, -0.26229999999864639,
      -0.26229999999863279, -0.26229999999861908, -0.2622999999986052,
      -0.26229999999859116, -0.262299999998577, -0.26229999999856268,
      -0.26229999999854825, -0.26229999999853365, -0.26229999999851894,
      -0.26229999999850406, -0.26229999999848896, -0.26229999999847381,
      -0.26229999999845849, -0.262299999998443, -0.26229999999842735,
      -0.26229999999841153, -0.26229999999839559, -0.26229999999837944,
      -0.26229999999836318, -0.26229999999834674, -0.26229999999833009,
      -0.26229999999831333, -0.26229999999829634, -0.26229999999827924,
      -0.26229999999826192, -0.26229999999824449, -0.26229999999822684,
      -0.262299999998209, -0.262299999998191, -0.26229999999817283,
      -0.26229999999815445, -0.26229999999813591, -0.26229999999811715,
      -0.26229999999809828, -0.26229999999807918, -0.26229999999805986,
      -0.26229999999804032, -0.26229999999802067, -0.2622999999980008,
      -0.2622999999979807, -0.26229999999796039, -0.26229999999793985,
      -0.2622999999979192, -0.26229999999789827, -0.26229999999787712,
      -0.2622999999978558, -0.26229999999783427, -0.26229999999781251,
      -0.26229999999779052, -0.26229999999776832, -0.26229999999774589,
      -0.26229999999772324, -0.26229999999770037, -0.26229999999767722,
      -0.26229999999765385, -0.26229999999763032, -0.26229999999760645,
      -0.26229999999758247, -0.26229999999755815, -0.26229999999753362,
      -0.2622999999975088, -0.26229999999748377, -0.26229999999745846,
      -0.26229999999743292, -0.26229999999740716, -0.26229999999738107,
      -0.26229999999735476, -0.26229999999732817, -0.26229999999730136,
      -0.26229999999727416, -0.26229999999724679, -0.26229999999721915,
      -0.26229999999719122, -0.26229999999716297, -0.26229999999713444,
      -0.26229999999710563, -0.26229999999707654, -0.26229999999704717,
      -0.26229999999701747, -0.2622999999969875, -0.26229999999695724,
      -0.26229999999692666, -0.26229999999689579, -0.2622999999968646,
      -0.26229999999683307, -0.26229999999680126, -0.26229999999676912,
      -0.26229999999673659, -0.26229999999670384, -0.2622999999966707,
      -0.26229999999663722, -0.26229999999660347, -0.26229999999656928,
      -0.26229999999653486, -0.2622999999965, -0.26229999999646481,
      -0.26229999999642928, -0.26229999999639342, -0.26229999999635717,
      -0.26229999999632059, -0.26229999999628362, -0.2622999999962462,
      -0.26229999999620851, -0.26229999999617037, -0.26229999999613191,
      -0.26229999999609305, -0.2622999999960538, -0.26229999999601411,
      -0.26229999999597409, -0.26229999999593356, -0.26229999999589271,
      -0.26229999999585141, -0.26229999999580977, -0.26229999999576764,
      -0.26229999999572506, -0.26229999999568215, -0.26229999999563874,
      -0.26229999999559495, -0.26229999999555065, -0.26229999999550591,
      -0.26229999999546072, -0.26229999999541515, -0.26229999999536907,
      -0.2622999999953225, -0.26229999999527553, -0.262299999995228,
      -0.26229999999518006, -0.26229999999513165, -0.26229999999508269,
      -0.26229999999503328, -0.26229999999498338, -0.26229999999493292,
      -0.262299999994882, -0.26229999999483056, -0.2622999999947786,
      -0.2622999999947262, -0.26229999999467313, -0.26229999999461961,
      -0.26229999999456555, -0.26229999999451092, -0.26229999999445575,
      -0.2622999999944, -0.26229999999434372, -0.26229999999428688,
      -0.26229999999422948, -0.26229999999417153, -0.26229999999411291,
      -0.26229999999405373, -0.262299999993994, -0.26229999999393361,
      -0.26229999999387266, -0.26229999999381109, -0.26229999999374887,
      -0.26229999999368608, -0.26229999999362263, -0.26229999999355852,
      -0.26229999999349379, -0.2622999999934284, -0.26229999999336234,
      -0.26229999999329567, -0.26229999999322828, -0.26229999999316023,
      -0.2622999999930915, -0.262299999993022, -0.26229999999295189,
      -0.26229999999288106, -0.26229999999280951, -0.26229999999273723,
      -0.26229999999266429, -0.26229999999259057, -0.26229999999251608,
      -0.26229999999244086, -0.26229999999236486, -0.26229999999228815,
      -0.26229999999221065, -0.26229999999213238, -0.26229999999205333,
      -0.2622999999919734, -0.2622999999918928, -0.26229999999181131,
      -0.262299999991729, -0.26229999999164588, -0.26229999999156189,
      -0.26229999999147713, -0.26229999999139142, -0.26229999999130493,
      -0.26229999999121756, -0.2622999999911293, -0.26229999999104014,
      -0.26229999999095011, -0.26229999999085912, -0.26229999999076725,
      -0.26229999999067444, -0.26229999999058073, -0.26229999999048603,
      -0.26229999999039044, -0.26229999999029385, -0.26229999999019632,
      -0.26229999999009779, -0.26229999998999831, -0.26229999998989773,
      -0.26229999998979625, -0.26229999998969367, -0.26229999998959008,
      -0.2622999999894855, -0.26229999998937981, -0.26229999998927311,
      -0.26229999998916526, -0.2622999999890564, -0.26229999998894638,
      -0.2622999999888353, -0.26229999998872311, -0.26229999998860976,
      -0.26229999998849529, -0.26229999998837966, -0.26229999998826287,
      -0.26229999998814491, -0.26229999998802578, -0.26229999998790543,
      -0.26229999998778386, -0.26229999998766107, -0.26229999998753706,
      -0.26229999998741182, -0.26229999998728537, -0.26229999998715758,
      -0.26229999998702846, -0.26229999998689812, -0.26229999998676645,
      -0.26229999998663345, -0.26229999998649911, -0.26229999998636344,
      -0.26229999998622633, -0.26229999998608794, -0.26229999998594811,
      -0.26229999998580689, -0.26229999998566422, -0.26229999998552017,
      -0.26229999998537468, -0.26229999998522768, -0.26229999998507919,
      -0.26229999998492926, -0.26229999998477782, -0.26229999998462483,
      -0.26229999998447029, -0.26229999998431419, -0.26229999998415654,
      -0.26229999998399733, -0.26229999998383646, -0.26229999998367404,
      -0.26229999998350995, -0.26229999998334425, -0.26229999998317688,
      -0.26229999998300779, -0.262299999982837, -0.26229999998266451,
      -0.26229999998249032, -0.26229999998231435, -0.2622999999821366,
      -0.262299999981957, -0.26229999998177567, -0.26229999998159254,
      -0.26229999998140752, -0.26229999998122067, -0.26229999998103193,
      -0.2622999999808413, -0.26229999998064879, -0.26229999998045428,
      -0.26229999998025788, -0.26229999998005943, -0.26229999997985903,
      -0.26229999997965658, -0.26229999997945219, -0.26229999997924569,
      -0.26229999997903708, -0.26229999997882636, -0.26229999997861358,
      -0.26229999997839865, -0.26229999997818154, -0.26229999997796227,
      -0.26229999997774078, -0.26229999997751707, -0.26229999997729114,
      -0.26229999997706288, -0.2622999999768324, -0.26229999997659953,
      -0.26229999997636433, -0.26229999997612685, -0.26229999997588688,
      -0.26229999997564457, -0.26229999997539977, -0.26229999997515252,
      -0.26229999997490283, -0.26229999997465059, -0.26229999997439579,
      -0.2622999999741385, -0.26229999997387859, -0.26229999997361608,
      -0.26229999997335091, -0.26229999997308306, -0.26229999997281256,
      -0.26229999997253928, -0.26229999997226333, -0.26229999997198455,
      -0.262299999971703, -0.26229999997141862, -0.2622999999711314,
      -0.26229999997084125, -0.2622999999705482, -0.26229999997025222,
      -0.26229999996995323, -0.26229999996965125, -0.26229999996934628,
      -0.26229999996903819, -0.262299999968727, -0.26229999996841269,
      -0.26229999996809522, -0.26229999996777459, -0.26229999996745068,
      -0.26229999996712361, -0.26229999996679321, -0.26229999996645947,
      -0.26229999996612235, -0.2622999999657819, -0.26229999996543796,
      -0.26229999996509062, -0.26229999996473979, -0.26229999996438541,
      -0.26229999996402747, -0.26229999996366593, -0.26229999996330078,
      -0.26229999996293196, -0.26229999996255943, -0.26229999996218312,
      -0.26229999996180309, -0.26229999996141917, -0.26229999996103143,
      -0.2622999999606398, -0.26229999996024422, -0.26229999995984465,
      -0.26229999995944109, -0.26229999995903347, -0.26229999995862174,
      -0.26229999995820591, -0.26229999995778586, -0.26229999995736164,
      -0.26229999995693309, -0.26229999995650022, -0.26229999995606307,
      -0.26229999995562148, -0.2622999999551755, -0.26229999995472497,
      -0.26229999995427, -0.26229999995381037, -0.26229999995334619,
      -0.26229999995287728, -0.26229999995240372, -0.26229999995192532,
      -0.26229999995144215, -0.26229999995095421, -0.26229999995046127,
      -0.26229999994996339, -0.26229999994946052, -0.26229999994895259,
      -0.26229999994843956, -0.26229999994792136, -0.26229999994739794,
      -0.26229999994686926, -0.26229999994633535, -0.262299999945796,
      -0.26229999994525122, -0.262299999944701, -0.26229999994414521,
      -0.26229999994358388, -0.26229999994301689, -0.26229999994244418,
      -0.2622999999418657, -0.2622999999412815, -0.26229999994069136,
      -0.26229999994009529, -0.26229999993949327, -0.26229999993888514,
      -0.26229999993827091, -0.26229999993765052, -0.26229999993702391,
      -0.26229999993639097, -0.2622999999357517, -0.262299999935106,
      -0.2622999999344538, -0.26229999993379505, -0.26229999993312969,
      -0.26229999993245767, -0.26229999993177883, -0.26229999993109321,
      -0.26229999993040065, -0.26229999992970121, -0.26229999992899466,
      -0.262299999928281, -0.26229999992756026, -0.26229999992683223,
      -0.26229999992609687, -0.26229999992535413, -0.26229999992460395,
      -0.26229999992384623, -0.26229999992308084, -0.26229999992230779,
      -0.26229999992152697, -0.26229999992073827, -0.26229999991994168,
      -0.26229999991913711, -0.26229999991832442, -0.26229999991750358,
      -0.26229999991667446, -0.262299999915837, -0.2622999999149912,
      -0.26229999991413683, -0.26229999991327391, -0.26229999991240227,
      -0.26229999991152192, -0.26229999991063269, -0.26229999990973452,
      -0.26229999990882735, -0.26229999990791109, -0.26229999990698555,
      -0.26229999990605074, -0.26229999990510655, -0.26229999990415287,
      -0.26229999990318953, -0.26229999990221659, -0.26229999990123387,
      -0.26229999990024122, -0.26229999989923863, -0.26229999989822594,
      -0.2622999998972031, -0.26229999989617003, -0.26229999989512648,
      -0.26229999989407249, -0.2622999998930079, -0.26229999989193264,
      -0.26229999989084651, -0.2622999998897495, -0.2622999998886415,
      -0.26229999988752228, -0.26229999988639185, -0.2622999998852501,
      -0.26229999988409686, -0.262299999882932, -0.26229999988175545,
      -0.26229999988056707, -0.26229999987936675, -0.26229999987815433,
      -0.26229999987692981, -0.26229999987569291, -0.26229999987444363,
      -0.26229999987318176, -0.26229999987190722, -0.26229999987061986,
      -0.26229999986931957, -0.26229999986800623, -0.26229999986667962,
      -0.26229999986533975, -0.26229999986398639, -0.26229999986261943,
      -0.26229999986123875, -0.2622999998598442, -0.26229999985843555,
      -0.2622999998570128, -0.26229999985557578, -0.26229999985412433,
      -0.26229999985265823, -0.26229999985117741, -0.26229999984968172,
      -0.262299999848171, -0.26229999984664509, -0.26229999984510388,
      -0.26229999984354713, -0.26229999984197472, -0.26229999984038654,
      -0.26229999983878238, -0.26229999983716212, -0.2622999998355256,
      -0.26229999983387264, -0.262299999832203, -0.26229999983051666,
      -0.26229999982881325, -0.26229999982709284, -0.26229999982535512,
      -0.26229999982359986, -0.26229999982182706, -0.26229999982003638,
      -0.26229999981822771, -0.26229999981640084, -0.26229999981455565,
      -0.26229999981269192, -0.26229999981080943, -0.26229999980890806,
      -0.26229999980698748, -0.2622999998050477, -0.26229999980308838,
      -0.26229999980110941, -0.26229999979911056, -0.26229999979709157,
      -0.26229999979505231, -0.26229999979299257, -0.26229999979091212,
      -0.26229999978881069, -0.26229999978668822, -0.26229999978454444,
      -0.26229999978237906, -0.26229999978019192, -0.2622999997779828,
      -0.26229999977575147, -0.26229999977349777, -0.26229999977122137,
      -0.26229999976892215, -0.26229999976659973, -0.262299999764254,
      -0.26229999976188478, -0.26229999975949164, -0.26229999975707452,
      -0.26229999975463303, -0.26229999975216711, -0.26229999974967633,
      -0.26229999974716056, -0.26229999974461948, -0.26229999974205281,
      -0.26229999973946039, -0.26229999973684193, -0.26229999973419715,
      -0.26229999973152579, -0.26229999972882756, -0.2622999997261023,
      -0.26229999972334955, -0.26229999972056917, -0.26229999971776086,
      -0.26229999971492429, -0.2622999997120592, -0.2622999997091654,
      -0.2622999997062424, -0.2622999997032901, -0.26229999970030815,
      -0.26229999969729623, -0.262299999694254, -0.26229999969118117,
      -0.26229999968807749, -0.26229999968494261, -0.2622999996817762,
      -0.26229999967857803, -0.26229999967534767, -0.26229999967208489,
      -0.26229999966878925, -0.26229999966546058, -0.26229999966209838,
      -0.26229999965870243, -0.26229999965527229, -0.26229999965180772,
      -0.26229999964830836, -0.2622999996447738, -0.26229999964120371,
      -0.26229999963759776, -0.26229999963395556, -0.26229999963027673,
      -0.26229999962656092, -0.26229999962280781, -0.26229999961901695,
      -0.262299999615188, -0.26229999961132061, -0.26229999960741435,
      -0.26229999960346878, -0.26229999959948358, -0.26229999959545836,
      -0.26229999959139261, -0.262299999587286, -0.26229999958313821,
      -0.26229999957894867, -0.26229999957471706, -0.26229999957044287,
      -0.26229999956612571, -0.2622999995617652, -0.26229999955736089,
      -0.26229999955291228, -0.262299999548419, -0.2622999995438805,
      -0.26229999953929645, -0.26229999953466632, -0.26229999952998961,
      -0.26229999952526595, -0.26229999952049476, -0.26229999951567567,
      -0.26229999951080818, -0.26229999950589167, -0.26229999950092581,
      -0.26229999949591004, -0.26229999949084382, -0.26229999948572674,
      -0.26229999948055821, -0.26229999947533772, -0.26229999947006477,
      -0.26229999946473881, -0.26229999945935939, -0.26229999945392585,
      -0.26229999944843774, -0.26229999944289439, -0.26229999943729543,
      -0.26229999943164017, -0.26229999942592808, -0.26229999942015852,
      -0.262299999414331, -0.26229999940844495, -0.26229999940249971,
      -0.26229999939649473, -0.26229999939042942, -0.26229999938430315,
      -0.26229999937811527, -0.26229999937186521, -0.26229999936555237,
      -0.26229999935917603, -0.26229999935273568, -0.26229999934623055,
      -0.26229999933966008, -0.2622999993330235, -0.26229999932632031,
      -0.26229999931954973, -0.26229999931271109, -0.26229999930580372,
      -0.26229999929882691, -0.26229999929178005, -0.2622999992846623,
      -0.26229999927747305, -0.26229999927021153, -0.262299999262877,
      -0.26229999925546882, -0.26229999924798614, -0.26229999924042824,
      -0.26229999923279446, -0.2622999992250839, -0.26229999921729585,
      -0.26229999920942959, -0.26229999920148417, -0.262299999193459,
      -0.26229999918535313, -0.26229999917716579, -0.26229999916889613,
      -0.26229999916054342, -0.26229999915210678, -0.26229999914358526,
      -0.26229999913497815, -0.26229999912628454, -0.26229999911750357,
      -0.26229999910863433, -0.26229999909967594, -0.26229999909062751,
      -0.26229999908148821, -0.262299999072257, -0.262299999062933,
      -0.26229999905351536, -0.26229999904400303, -0.2622999990343951,
      -0.26229999902469059, -0.2622999990148886, -0.262299999004988,
      -0.262299998994988, -0.26229999898488748, -0.26229999897468542,
      -0.26229999896438083, -0.26229999895397271, -0.26229999894345996,
      -0.26229999893284156, -0.26229999892211642, -0.26229999891128353,
      -0.26229999890034172, -0.26229999888929, -0.26229999887812716,
      -0.26229999886685218, -0.26229999885546385, -0.26229999884396105,
      -0.26229999883234267, -0.26229999882060751, -0.26229999880875443,
      -0.26229999879678223, -0.26229999878468968, -0.26229999877247556,
      -0.26229999876013876, -0.26229999874767795, -0.26229999873509191,
      -0.26229999872237941, -0.26229999870953907, -0.26229999869656972,
      -0.26229999868347004, -0.26229999867023868, -0.26229999865687437,
      -0.26229999864337572, -0.2622999986297414, -0.26229999861597009,
      -0.26229999860206038, -0.26229999858801084, -0.26229999857382014,
      -0.26229999855948677, -0.26229999854500941, -0.26229999853038649,
      -0.26229999851561658, -0.26229999850069829, -0.26229999848563013,
      -0.26229999847041041, -0.26229999845503782, -0.26229999843951068,
      -0.26229999842382745, -0.26229999840798668, -0.2622999983919867,
      -0.26229999837582585, -0.26229999835950268, -0.26229999834301543,
      -0.26229999832636242, -0.26229999830954209, -0.26229999829255268,
      -0.26229999827539258, -0.26229999825805994, -0.26229999824055317,
      -0.26229999822287042, -0.26229999820501, -0.26229999818697003,
      -0.26229999816874883, -0.26229999815034444, -0.26229999813175509,
      -0.26229999811297888, -0.26229999809401405, -0.26229999807485854,
      -0.26229999805551052, -0.2622999980359681, -0.26229999801622927,
      -0.262299997996292, -0.26229999797615444, -0.26229999795581443,
      -0.26229999793527004, -0.26229999791451919, -0.26229999789355973,
      -0.26229999787238967, -0.26229999785100677, -0.26229999782940905,
      -0.26229999780759428, -0.26229999778556023, -0.2622999977633047,
      -0.26229999774082557, -0.26229999771812051, -0.26229999769518719,
      -0.2622999976720235, -0.26229999764862694, -0.26229999762499523,
      -0.26229999760112604, -0.26229999757701694, -0.26229999755266553,
      -0.26229999752806943, -0.26229999750322613, -0.26229999747813315,
      -0.262299997452788, -0.262299997427188, -0.26229999740133086,
      -0.26229999737521381, -0.26229999734883425, -0.26229999732218962,
      -0.2622999972952772, -0.26229999726809428, -0.26229999724063813,
      -0.26229999721290609, -0.26229999718489533, -0.26229999715660307,
      -0.26229999712802643, -0.26229999709916263, -0.26229999707000873,
      -0.26229999704056184, -0.26229999701081896, -0.26229999698077722,
      -0.26229999695043349, -0.26229999691978489, -0.26229999688882821,
      -0.26229999685756039, -0.26229999682597838, -0.26229999679407889,
      -0.26229999676185889, -0.26229999672931503, -0.2622999966964441,
      -0.26229999666324277, -0.26229999662970782, -0.2622999965958358,
      -0.26229999656162339, -0.26229999652706715, -0.26229999649216362,
      -0.26229999645690927, -0.26229999642130064, -0.26229999638533408,
      -0.26229999634900608, -0.262299996312313, -0.26229999627525113,
      -0.26229999623781675, -0.26229999620000621, -0.26229999616181565,
      -0.26229999612324123, -0.26229999608427912, -0.26229999604492549,
      -0.26229999600517634, -0.26229999596502773, -0.26229999592447556,
      -0.26229999588351582, -0.26229999584214447, -0.26229999580035734,
      -0.26229999575815022, -0.262299995715519, -0.26229999567245921,
      -0.26229999562896666, -0.26229999558503708, -0.26229999554066596,
      -0.26229999549584893, -0.26229999545058147, -0.26229999540485904,
      -0.2622999953586771, -0.26229999531203108, -0.26229999526491621,
      -0.26229999521732777, -0.26229999516926117, -0.26229999512071139,
      -0.26229999507167373, -0.26229999502214324, -0.262299994972115,
      -0.26229999492158385, -0.26229999487054489, -0.262299994818993,
      -0.26229999476692306, -0.26229999471432974, -0.2622999946612079,
      -0.26229999460755216, -0.26229999455335717, -0.26229999449861752,
      -0.26229999444332763, -0.26229999438748219, -0.26229999433107543,
      -0.26229999427410178, -0.26229999421655559, -0.26229999415843097,
      -0.26229999409972227, -0.26229999404042348, -0.26229999398052872,
      -0.262299993920032, -0.26229999385892733, -0.26229999379720859,
      -0.26229999373486945, -0.26229999367190382, -0.26229999360830547,
      -0.26229999354406786, -0.26229999347918465, -0.26229999341364935,
      -0.26229999334745546, -0.26229999328059628, -0.26229999321306513,
      -0.2622999931448553, -0.26229999307595997, -0.26229999300637219,
      -0.26229999293608508, -0.26229999286509154, -0.26229999279338456,
      -0.26229999272095683, -0.26229999264780124, -0.2622999925739104,
      -0.26229999249927693, -0.26229999242389346, -0.26229999234775236,
      -0.262299992270846, -0.26229999219316669, -0.26229999211470667,
      -0.26229999203545817, -0.2622999919554132, -0.26229999187456376,
      -0.26229999179290175, -0.26229999171041907, -0.26229999162710738,
      -0.26229999154295847, -0.26229999145796379, -0.2622999913721149,
      -0.26229999128540316, -0.26229999119782005, -0.26229999110935664,
      -0.26229999102000423, -0.26229999092975376, -0.26229999083859623,
      -0.26229999074652266, -0.26229999065352361, -0.26229999055958997,
      -0.26229999046471231, -0.26229999036888108, -0.26229999027208672,
      -0.2622999901743196, -0.26229999007556981, -0.26229998997582771,
      -0.26229998987508307, -0.26229998977332597, -0.26229998967054619,
      -0.26229998956673345, -0.26229998946187738, -0.26229998935596749,
      -0.26229998924899323, -0.26229998914094377, -0.26229998903180846,
      -0.26229998892157635, -0.26229998881023631, -0.26229998869777732,
      -0.26229998858418813, -0.26229998846945729, -0.26229998835357338,
      -0.26229998823652489, -0.2622999881183, -0.26229998799888693,
      -0.26229998787827374, -0.26229998775644836, -0.26229998763339868,
      -0.26229998750911221, -0.26229998738357674, -0.26229998725677961,
      -0.26229998712870806, -0.26229998699934948, -0.26229998686869077,
      -0.26229998673671895, -0.26229998660342074, -0.26229998646878289,
      -0.26229998633279189, -0.26229998619543415, -0.262299986056696,
      -0.26229998591656345, -0.26229998577502256, -0.2622999856320592,
      -0.262299985487659, -0.26229998534180754, -0.26229998519449027,
      -0.26229998504569241, -0.26229998489539919, -0.26229998474359539,
      -0.262299984590266, -0.26229998443539559, -0.26229998427896872,
      -0.26229998412096978, -0.26229998396138288, -0.26229998380019209,
      -0.26229998363738133, -0.26229998347293426, -0.26229998330683452,
      -0.26229998313906544, -0.26229998296961021, -0.262299982798452,
      -0.26229998262557358, -0.2622999824509577, -0.2622999822745869,
      -0.26229998209644356, -0.26229998191650983, -0.26229998173476776,
      -0.2622999815511991, -0.26229998136578558, -0.26229998117850861,
      -0.26229998098934953, -0.26229998079828931, -0.2622999806053089,
      -0.26229998041038904, -0.2622999802135102, -0.26229998001465271,
      -0.2622999798137966, -0.26229997961092194, -0.26229997940600835,
      -0.26229997919903525, -0.26229997898998214, -0.26229997877882794,
      -0.26229997856555165, -0.26229997835013186, -0.26229997813254713,
      -0.26229997791277559, -0.26229997769079527, -0.26229997746658407,
      -0.2622999772401195, -0.26229997701137892, -0.26229997678033945,
      -0.262299976546978, -0.26229997631127122, -0.26229997607319555,
      -0.26229997583272724, -0.26229997558984208, -0.262299975344516,
      -0.26229997509672426, -0.26229997484644219, -0.26229997459364474,
      -0.26229997433830665, -0.2622999740804024, -0.26229997381990611,
      -0.26229997355679185, -0.26229997329103322, -0.26229997302260366,
      -0.26229997275147632, -0.26229997247762415, -0.26229997220101975,
      -0.26229997192163534, -0.26229997163944313, -0.26229997135441485,
      -0.26229997106652192, -0.26229997077573564, -0.26229997048202697,
      -0.26229997018536644, -0.26229996988572446, -0.262299969583071,
      -0.26229996927737576, -0.2622999689686083, -0.26229996865673766,
      -0.26229996834173269, -0.26229996802356181, -0.26229996770219333,
      -0.26229996737759503, -0.26229996704973446, -0.2622999667185788,
      -0.26229996638409503, -0.26229996604624961, -0.2622999657050088,
      -0.26229996536033845, -0.26229996501220409, -0.26229996466057093,
      -0.26229996430540381, -0.26229996394666721, -0.26229996358432528,
      -0.2622999632183417, -0.26229996284867996, -0.262299962475303,
      -0.26229996209817363, -0.262299961717254, -0.262299961332506,
      -0.2622999609438913, -0.26229996055137095, -0.2622999601549057,
      -0.26229995975445591, -0.26229995934998152, -0.26229995894144209,
      -0.26229995852879684, -0.26229995811200435, -0.2622999576910231,
      -0.26229995726581085, -0.26229995683632518, -0.26229995640252313,
      -0.26229995596436129, -0.2622999555217958, -0.26229995507478249,
      -0.2622999546232766, -0.26229995416723306, -0.26229995370660619,
      -0.26229995324134991, -0.26229995277141777, -0.26229995229676273,
      -0.26229995181733728, -0.26229995133309358, -0.26229995084398311,
      -0.262299950349957, -0.26229994985096589, -0.26229994934695983,
      -0.26229994883788843, -0.26229994832370074, -0.2622999478043454,
      -0.26229994727977046, -0.26229994674992341, -0.26229994621475139,
      -0.26229994567420079, -0.26229994512821753, -0.26229994457674705,
      -0.26229994401973422, -0.26229994345712332, -0.26229994288885805,
      -0.26229994231488168, -0.26229994173513671, -0.26229994114956523,
      -0.26229994055810868, -0.26229993996070788, -0.26229993935730311,
      -0.262299938747834, -0.26229993813223967, -0.26229993751045849,
      -0.26229993688242831, -0.26229993624808634, -0.26229993560736908,
      -0.26229993496021253, -0.26229993430655196, -0.26229993364632204,
      -0.26229993297945664, -0.26229993230588916, -0.26229993162555221,
      -0.26229993093837778, -0.2622999302442971, -0.26229992954324083,
      -0.26229992883513881, -0.26229992811992031, -0.26229992739751362,
      -0.26229992666784674, -0.26229992593084656, -0.26229992518643941,
      -0.26229992443455086, -0.26229992367510568, -0.26229992290802795,
      -0.262299922133241, -0.26229992135066726, -0.26229992056022855,
      -0.26229991976184586, -0.26229991895543925, -0.26229991814092812,
      -0.26229991731823105, -0.26229991648726569, -0.26229991564794908,
      -0.2622999148001971, -0.26229991394392516, -0.26229991307904749,
      -0.26229991220547766, -0.26229991132312835, -0.26229991043191131,
      -0.26229990953173732, -0.26229990862251651, -0.2622999077041579,
      -0.26229990677656956, -0.26229990583965884, -0.262299904893332,
      -0.26229990393749447, -0.26229990297205064, -0.26229990199690389,
      -0.26229990101195677, -0.26229990001711079, -0.26229989901226636,
      -0.26229989799732323, -0.26229989697217965, -0.26229989593673325,
      -0.26229989489088046, -0.26229989383451668, -0.26229989276753629,
      -0.26229989168983253, -0.26229989060129766, -0.26229988950182292,
      -0.26229988839129825, -0.26229988726961262, -0.26229988613665389,
      -0.26229988499230872, -0.26229988383646274, -0.26229988266900028,
      -0.26229988148980465, -0.26229988029875795, -0.26229987909574104,
      -0.26229987788063358, -0.26229987665331411, -0.26229987541365996,
      -0.262299874161547, -0.26229987289685014, -0.2622998716194429,
      -0.26229987032919744, -0.2622998690259849, -0.26229986770967484,
      -0.26229986638013558, -0.26229986503723435, -0.26229986368083669,
      -0.26229986231080704, -0.26229986092700841, -0.26229985952930235,
      -0.26229985811754908, -0.2622998566916076, -0.26229985525133503,
      -0.2622998537965876, -0.26229985232721975, -0.26229985084308444,
      -0.26229984934403339, -0.26229984782991661, -0.26229984630058278,
      -0.26229984475587886, -0.26229984319565042, -0.26229984161974146,
      -0.26229984002799434, -0.26229983842024995, -0.2622998367963475,
      -0.26229983515612454, -0.2622998334994171, -0.26229983182605954,
      -0.26229983013588443, -0.26229982842872279, -0.26229982670440388,
      -0.26229982496275539, -0.262299823203603, -0.26229982142677088,
      -0.26229981963208138, -0.26229981781935485, -0.26229981598841023,
      -0.26229981413906434, -0.26229981227113219, -0.26229981038442707,
      -0.26229980847876028, -0.26229980655394125, -0.26229980460977748,
      -0.26229980264607455, -0.26229980066263614, -0.26229979865926389,
      -0.26229979663575742, -0.26229979459191444, -0.26229979252753044,
      -0.26229979044239915, -0.26229978833631196, -0.26229978620905825,
      -0.26229978406042531, -0.26229978189019831, -0.26229977969816021,
      -0.26229977748409183, -0.26229977524777165, -0.26229977298897617,
      -0.26229977070747945, -0.26229976840305336, -0.2622997660754674,
      -0.26229976372448888, -0.26229976134988264, -0.26229975895141133,
      -0.26229975652883497, -0.26229975408191142, -0.26229975161039587,
      -0.26229974911404119, -0.2622997465925978, -0.26229974404581358,
      -0.26229974147343382, -0.26229973887520119, -0.262299736250856,
      -0.2622997336001357, -0.26229973092277531, -0.262299728218507,
      -0.26229972548706049, -0.26229972272816249, -0.26229971994153717,
      -0.26229971712690586, -0.26229971428398713, -0.26229971141249658,
      -0.26229970851214718, -0.26229970558264881, -0.26229970262370861,
      -0.26229969963503064, -0.262299696616316, -0.26229969356726285,
      -0.26229969048756629, -0.26229968737691833, -0.26229968423500788,
      -0.2622996810615208, -0.26229967785613972, -0.26229967461854414,
      -0.26229967134841026, -0.26229966804541105, -0.26229966470921617,
      -0.26229966133949217, -0.26229965793590193, -0.26229965449810511,
      -0.26229965102575792, -0.2622996475185132, -0.26229964397602024,
      -0.26229964039792464, -0.26229963678386869, -0.262299633133491,
      -0.26229962944642649, -0.26229962572230647, -0.26229962196075851,
      -0.26229961816140651, -0.2622996143238705, -0.26229961044776673,
      -0.26229960653270756, -0.26229960257830154, -0.26229959858415319,
      -0.26229959454986307, -0.26229959047502782, -0.26229958635923989,
      -0.26229958220208777, -0.26229957800315573, -0.26229957376202379,
      -0.26229956947826794, -0.2622995651514598, -0.26229956078116662,
      -0.2622995563669514, -0.26229955190837273, -0.26229954740498485,
      -0.26229954285633722, -0.26229953826197511, -0.2622995336214391,
      -0.262299528934265, -0.26229952419998426, -0.26229951941812335,
      -0.26229951458820416, -0.26229950970974358, -0.26229950478225394,
      -0.26229949980524236, -0.26229949477821113, -0.26229948970065764,
      -0.262299484572074, -0.26229947939194753, -0.26229947415976013,
      -0.26229946887498856, -0.26229946353710432, -0.26229945814557376,
      -0.2622994526998576, -0.26229944719941134, -0.26229944164368491,
      -0.26229943603212269, -0.26229943036416359, -0.26229942463924083,
      -0.26229941885678187, -0.26229941301620852, -0.26229940711693667,
      -0.26229940115837636, -0.26229939513993189, -0.26229938906100131,
      -0.26229938292097676, -0.26229937671924419, -0.26229937045518348,
      -0.26229936412816823, -0.26229935773756574, -0.2622993512827369,
      -0.26229934476303629, -0.262299338177812, -0.26229933152640539,
      -0.26229932480815132, -0.26229931802237805, -0.262299311168407,
      -0.26229930424555281, -0.26229929725312306, -0.26229929019041864,
      -0.26229928305673328, -0.26229927585135354, -0.26229926857355895,
      -0.2622992612226217, -0.26229925379780672, -0.26229924629837154,
      -0.26229923872356625, -0.26229923107263331, -0.26229922334480771,
      -0.26229921553931657, -0.26229920765537951, -0.26229919969220794,
      -0.26229919164900573, -0.26229918352496845, -0.26229917531928376,
      -0.2622991670311311, -0.26229915865968162, -0.26229915020409822,
      -0.26229914166353541, -0.26229913303713903, -0.26229912432404651,
      -0.26229911552338653, -0.262299106634279, -0.26229909765583515,
      -0.26229908858715706, -0.26229907942733788, -0.26229907017546161,
      -0.26229906083060306, -0.26229905139182785, -0.26229904185819208,
      -0.26229903222874229, -0.26229902250251574, -0.26229901267853967,
      -0.26229900275583173, -0.26229899273339974, -0.26229898261024137,
      -0.26229897238534439, -0.26229896205768621, -0.26229895162623429,
      -0.26229894108994528, -0.2622989304477657, -0.26229891969863128,
      -0.26229890884146723, -0.26229889787518773, -0.26229888679869623,
      -0.26229887561088505, -0.26229886431063554, -0.26229885289681759,
      -0.26229884136828985, -0.26229882972389951, -0.26229881796248222,
      -0.26229880608286171, -0.26229879408385015, -0.26229878196424761,
      -0.26229876972284227, -0.2622987573584098, -0.26229874486971394,
      -0.26229873225550582, -0.26229871951452405, -0.26229870664549454,
      -0.26229869364713043, -0.26229868051813182, -0.262298667257186,
      -0.26229865386296675, -0.26229864033413475, -0.26229862666933723,
      -0.26229861286720757, -0.2622985989263657, -0.26229858484541757,
      -0.26229857062295503, -0.262298556257556, -0.26229854174778389,
      -0.26229852709218771, -0.26229851228930212, -0.26229849733764665,
      -0.26229848223572633, -0.26229846698203096, -0.26229845157503517,
      -0.26229843601319835, -0.26229842029496431, -0.26229840441876134,
      -0.26229838838300179, -0.26229837218608221, -0.26229835582638295,
      -0.262298339302268, -0.262298322612085, -0.26229830575416513,
      -0.26229828872682248, -0.26229827152835444, -0.26229825415704122,
      -0.26229823661114571, -0.26229821888891347, -0.26229820098857226,
      -0.26229818290833207, -0.26229816464638495, -0.26229814620090486,
      -0.26229812757004717, -0.262298108751949, -0.26229808974472851,
      -0.26229807054648507, -0.26229805115529892, -0.26229803156923104,
      -0.26229801178632289, -0.26229799180459623, -0.26229797162205293,
      -0.26229795123667488, -0.26229793064642359, -0.26229790984924012,
      -0.26229788884304484, -0.26229786762573715, -0.26229784619519553,
      -0.26229782454927691, -0.26229780268581682, -0.262297780602629,
      -0.26229775829750523, -0.262297735768215, -0.26229771301250571,
      -0.26229769002810166, -0.26229766681270467, -0.26229764336399319,
      -0.26229761967962251, -0.26229759575722422, -0.26229757159440636,
      -0.26229754718875264, -0.26229752253782257, -0.26229749763915133,
      -0.26229747249024904, -0.26229744708860092, -0.262297421431667,
      -0.2622973955168818, -0.26229736934165382, -0.2622973429033657,
      -0.2622973161993738, -0.26229728922700785, -0.26229726198357073,
      -0.26229723446633824, -0.26229720667255885, -0.26229717859945334,
      -0.26229715024421452, -0.262297121604007, -0.26229709267596696,
      -0.26229706345720177, -0.26229703394478976, -0.26229700413577978,
      -0.2622969740271911, -0.26229694361601319, -0.262296912899205,
      -0.262296881873695, -0.26229685053638091, -0.26229681888412915,
      -0.26229678691377478, -0.26229675462212093, -0.26229672200593857,
      -0.26229668906196646, -0.26229665578691025, -0.26229662217744276,
      -0.26229658823020319, -0.26229655394179718, -0.26229651930879605,
      -0.26229648432773678, -0.26229644899512145, -0.2622964133074171,
      -0.2622963772610552, -0.26229634085243142, -0.26229630407790516,
      -0.2622962669337992, -0.26229622941639952, -0.26229619152195449,
      -0.26229615324667516, -0.26229611458673419, -0.26229607553826595,
      -0.26229603609736585, -0.26229599626009015, -0.26229595602245542,
      -0.26229591538043828, -0.26229587432997492, -0.26229583286696057,
      -0.26229579098724931, -0.26229574868665351, -0.26229570596094354,
      -0.26229566280584715, -0.26229561921704925, -0.26229557519019131,
      -0.26229553072087114, -0.26229548580464218, -0.26229544043701325,
      -0.262295394613448, -0.26229534832936441, -0.2622953015801347,
      -0.26229525436108436, -0.26229520666749195, -0.26229515849458851,
      -0.26229510983755733, -0.26229506069153319, -0.262295011051602,
      -0.26229496091280025, -0.26229491027011465, -0.26229485911848149,
      -0.26229480745278605, -0.26229475526786239, -0.26229470255849263,
      -0.26229464931940649, -0.26229459554528045, -0.26229454123073792,
      -0.26229448637034797, -0.26229443095862526, -0.26229437499002917,
      -0.26229431845896367, -0.26229426135977618, -0.2622942036867576,
      -0.26229414543414126, -0.26229408659610265, -0.26229402716675876,
      -0.26229396714016734, -0.26229390651032658, -0.26229384527117416,
      -0.26229378341658716, -0.26229372094038078, -0.26229365783630831,
      -0.26229359409806019, -0.26229352971926345, -0.26229346469348114,
      -0.26229339901421161, -0.26229333267488786, -0.26229326566887678,
      -0.26229319798947892, -0.26229312962992724, -0.26229306058338686,
      -0.2622929908429541, -0.26229292040165597, -0.26229284925244939,
      -0.26229277738822065, -0.26229270480178435, -0.262292631485883,
      -0.26229255743318619, -0.2622924826362899, -0.26229240708771556,
      -0.26229233077990965, -0.26229225370524256, -0.26229217585600817,
      -0.26229209722442293, -0.26229201780262495, -0.26229193758267344,
      -0.26229185655654785, -0.262291774716147, -0.26229169205328828,
      -0.2622916085597069, -0.26229152422705504, -0.26229143904690094,
      -0.26229135301072826, -0.262291266109935, -0.2622911783358326,
      -0.26229108967964554, -0.26229100013250983, -0.26229090968547242,
      -0.26229081832949058, -0.26229072605543041, -0.26229063285406645,
      -0.26229053871608043, -0.26229044363206055, -0.26229034759250036,
      -0.26229025058779787, -0.26229015260825483, -0.26229005364407532,
      -0.262289953685365, -0.26228985272213035, -0.26228975074427718,
      -0.26228964774161012, -0.26228954370383106, -0.26228943862053877,
      -0.26228933248122732, -0.26228922527528531, -0.26228911699199453,
      -0.26228900762052942, -0.2622888971499554, -0.26228878556922808,
      -0.26228867286719215, -0.2622885590325803, -0.26228844405401186,
      -0.26228832791999196, -0.26228821061891011, -0.26228809213903936,
      -0.26228797246853469, -0.26228785159543233, -0.26228772950764823,
      -0.26228760619297686, -0.2622874816390901, -0.26228735583353607,
      -0.26228722876373778, -0.26228710041699166, -0.26228697078046687,
      -0.26228683984120343, -0.26228670758611122, -0.26228657400196864,
      -0.26228643907542121, -0.26228630279298037, -0.262286165141022,
      -0.26228602610578511, -0.26228588567337047, -0.26228574382973924,
      -0.2622856005607116, -0.26228545585196517, -0.26228530968903374,
      -0.26228516205730584, -0.26228501294202305, -0.26228486232827891,
      -0.26228471020101707, -0.26228455654502991, -0.26228440134495723,
      -0.26228424458528432, -0.26228408625034072, -0.26228392632429853,
      -0.26228376479117088, -0.26228360163481029, -0.26228343683890709,
      -0.26228327038698773, -0.26228310226241319, -0.26228293244837741,
      -0.26228276092790542, -0.26228258768385176, -0.26228241269889874,
      -0.26228223595555472, -0.26228205743615235, -0.2622818771228469,
      -0.26228169499761422, -0.26228151104224928, -0.26228132523836412,
      -0.26228113756738614, -0.26228094801055613, -0.26228075654892635,
      -0.262280563163359, -0.26228036783452391, -0.26228017054289676,
      -0.262279971268757, -0.26227976999218627, -0.26227956669306596,
      -0.26227936135107549, -0.26227915394569007, -0.26227894445617883,
      -0.26227873286160275, -0.26227851914081246, -0.26227830327244595,
      -0.26227808523492713, -0.26227786500646277, -0.26227764256504094,
      -0.26227741788842873, -0.26227719095416974, -0.2622769617395822,
      -0.26227673022175646, -0.26227649637755279, -0.26227626018359906,
      -0.26227602161628855, -0.26227578065177726, -0.2622755372659818,
      -0.262275291434577, -0.26227504313299332, -0.26227479233641449,
      -0.262274539019775, -0.26227428315775769, -0.26227402472479117,
      -0.26227376369504712, -0.262273500042438, -0.26227323374061418,
      -0.26227296476296147, -0.26227269308259848, -0.26227241867237383,
      -0.26227214150486344, -0.26227186155236792, -0.26227157878690982,
      -0.26227129318023051, -0.26227100470378784, -0.26227071332875285,
      -0.26227041902600734, -0.26227012176614051, -0.26226982151944633,
      -0.26226951825592065, -0.26226921194525776, -0.26226890255684787,
      -0.26226859005977371, -0.2622682744228077, -0.26226795561440869,
      -0.26226763360271876, -0.26226730835556028, -0.2622669798404324,
      -0.26226664802450805, -0.26226631287463054, -0.26226597435731025,
      -0.26226563243872142, -0.26226528708469865, -0.2622649382607336,
      -0.26226458593197127, -0.26226423006320704, -0.26226387061888257,
      -0.26226350756308281, -0.26226314085953195, -0.26226277047159008,
      -0.26226239636224957, -0.26226201849413111, -0.26226163682948023,
      -0.26226125133016354, -0.26226086195766474, -0.26226046867308089,
      -0.26226007143711871, -0.26225967021009022, -0.26225926495190932,
      -0.26225885562208739, -0.26225844217972938, -0.26225802458352987,
      -0.26225760279176885, -0.26225717676230736, -0.26225674645258368,
      -0.26225631181960884, -0.26225587281996243, -0.26225542940978813,
      -0.26225498154478954, -0.26225452918022574, -0.26225407227090669,
      -0.26225361077118869, -0.26225314463497035, -0.26225267381568718,
      -0.26225219826630763, -0.26225171793932811, -0.26225123278676821,
      -0.26225074276016624, -0.26225024781057404, -0.26224974788855215,
      -0.2622492429441653, -0.26224873292697687, -0.26224821778604424,
      -0.2622476974699135, -0.26224717192661468, -0.26224664110365609,
      -0.26224610494801948, -0.26224556340615468, -0.262245016423974,
      -0.26224446394684725, -0.26224390591959612, -0.26224334228648866,
      -0.26224277299123372, -0.26224219797697546, -0.26224161718628758,
      -0.26224103056116777, -0.26224043804303165, -0.26223983957270736,
      -0.26223923509042912, -0.26223862453583191, -0.26223800784794504,
      -0.26223738496518617, -0.26223675582535522, -0.26223612036562838,
      -0.2622354785225513, -0.26223483023203353, -0.26223417542934158,
      -0.26223351404909268, -0.26223284602524843, -0.26223217129110787,
      -0.26223148977930116, -0.2622308014217829, -0.26223010614982506,
      -0.2622294038940105, -0.26222869458422582, -0.26222797814965459,
      -0.26222725451877016, -0.26222652361932863, -0.26222578537836161,
      -0.26222503972216915, -0.26222428657631214, -0.26222352586560504,
      -0.26222275751410873, -0.26222198144512227, -0.262221197581176,
      -0.2622204058440234, -0.26221960615463347, -0.26221879843318296,
      -0.26221798259904822, -0.26221715857079742, -0.26221632626618252,
      -0.26221548560213059, -0.26221463649473642, -0.26221377885925334,
      -0.26221291261008539, -0.26221203766077861, -0.26221115392401251,
      -0.2622102613115912, -0.26220935973443504, -0.26220844910257152,
      -0.26220752932512637, -0.26220660031031462, -0.26220566196543138,
      -0.26220471419684288, -0.26220375690997694, -0.26220279000931368,
      -0.26220181339837612, -0.26220082697972047, -0.2621998306549268,
      -0.26219882432458863, -0.26219780788830394, -0.2621967812446645,
      -0.26219574429124631, -0.262194696924599, -0.26219363904023607,
      -0.26219257053262413, -0.26219149129517277, -0.26219040122022375,
      -0.26218930019904052, -0.26218818812179739, -0.26218706487756854,
      -0.26218593035431725, -0.26218478443888471, -0.26218362701697878,
      -0.26218245797316275, -0.262181277190844, -0.26218008455226216,
      -0.26217887993847772, -0.26217766322936031, -0.26217643430357673,
      -0.26217519303857867, -0.26217393931059119, -0.2621726729946,
      -0.26217139396433931, -0.26217010209227909, -0.262168797249613,
      -0.26216747930624512, -0.26216614813077732, -0.26216480359049643,
      -0.26216344555136067, -0.262162073877987, -0.26216068843363738,
      -0.26215928908020514, -0.26215787567820192, -0.26215644808674321,
      -0.26215500616353493, -0.26215354976485916, -0.26215207874556,
      -0.26215059295902937, -0.26214909225719235, -0.2621475764904927,
      -0.262146045507878, -0.26214449915678495, -0.26214293728312421,
      -0.26214135973126507, -0.26213976634402036, -0.26213815696263076,
      -0.26213653142674942, -0.26213488957442577, -0.26213323124208987,
      -0.26213155626453627, -0.26212986447490749, -0.262128155704678,
      -0.26212642978363726, -0.26212468653987314, -0.262122925799755,
      -0.26212114738791648, -0.26211935112723855, -0.26211753683883166,
      -0.26211570434201847, -0.26211385345431593, -0.26211198399141733,
      -0.26211009576717448, -0.26210818859357882, -0.26210626228074352,
      -0.2621043166368846, -0.26210235146830196, -0.26210036657936053,
      -0.26209836177247103, -0.26209633684807054, -0.2620942916046029,
      -0.26209222583849895, -0.26209013934415659, -0.26208803191392044,
      -0.26208590333806181, -0.2620837534047577, -0.26208158190007041,
      -0.26207938860792634, -0.26207717331009495, -0.26207493578616708,
      -0.26207267581353388, -0.26207039316736458, -0.26206808762058453,
      -0.2620657589438532, -0.26206340690554131, -0.26206103127170866,
      -0.26205863180608097, -0.26205620827002662, -0.2620537604225337,
      -0.26205128802018596, -0.26204879081713967, -0.26204626856509883,
      -0.26204372101329143, -0.26204114790844485, -0.262038548994761,
      -0.26203592401389153, -0.26203327270491228, -0.26203059480429836,
      -0.26202789004589777, -0.262025158160906, -0.26202239887783951,
      -0.26201961192250944, -0.26201679701799463, -0.26201395388461496,
      -0.26201108223990377, -0.26200818179858071, -0.26200525227252358,
      -0.2620022933707406, -0.26199930479934186, -0.26199628626151095,
      -0.26199323745747594, -0.26199015808448012, -0.26198704783675286,
      -0.26198390640547975, -0.26198073347877254, -0.26197752874163893,
      -0.26197429187595189, -0.26197102256041893, -0.26196772047055095,
      -0.26196438527863031, -0.26196101665367977, -0.26195761426142994,
      -0.2619541777642867, -0.26195070682129917, -0.26194720108812597,
      -0.26194366021700244, -0.26194008385670658, -0.2619364716525252,
      -0.2619328232462198, -0.26192913827599151, -0.26192541637644673,
      -0.26192165717856114, -0.26191786030964459, -0.26191402539330472,
      -0.26191015204941104, -0.26190623989405787, -0.26190228853952757,
      -0.261898297594253, -0.26189426666277993, -0.26189019534572866,
      -0.26188608323975604, -0.26188192993751613, -0.26187773502762124,
      -0.26187349809460236, -0.26186921871886937, -0.26186489647667022,
      -0.2618605309400508, -0.26185612167681327, -0.26185166825047523,
      -0.26184717022022713, -0.26184262714089057, -0.26183803856287519,
      -0.26183340403213595, -0.26182872309012928, -0.26182399527376943,
      -0.26181922011538411, -0.26181439714266963, -0.26180952587864581,
      -0.26180460584161047, -0.2617996365450932, -0.26179461749780919,
      -0.261789548203612, -0.26178442816144665, -0.26177925686530146,
      -0.26177403380415992, -0.26176875846195219, -0.26176343031750582,
      -0.26175804884449605, -0.261752613511396, -0.26174712378142606,
      -0.26174157911250256, -0.26173597895718692, -0.26173032276263297,
      -0.26172460997053526, -0.26171884001707546, -0.2617130123328692,
      -0.26170712634291227, -0.2617011814665261, -0.26169517711730272,
      -0.26168911270304929, -0.26168298762573239, -0.26167680128142146,
      -0.26167055306023157, -0.26166424234626612, -0.26165786851755873,
      -0.26165143094601467, -0.26164492899735159, -0.26163836203104007,
      -0.2616317294002431, -0.26162503045175556, -0.26161826452594256,
      -0.26161143095667805, -0.26160452907128162, -0.26159755819045627,
      -0.26159051762822405, -0.2615834066918622, -0.26157622468183839,
      -0.26156897089174519, -0.26156164460823417, -0.26155424511094938,
      -0.26154677167245977, -0.261539223558192, -0.2615316000263615,
      -0.26152390032790374, -0.26151612370640431, -0.26150826939802896,
      -0.26150033663145233, -0.26149232462778649, -0.2614842326005089,
      -0.26147605975538923, -0.26146780529041613, -0.26145946839572282,
      -0.2614510482535124, -0.26144254403798217, -0.26143395491524768,
      -0.26142528004326548, -0.26141651857175596, -0.26140766964212481,
      -0.26139873238738415, -0.26138970593207295, -0.26138058939217657,
      -0.26137138187504572, -0.26136208247931458, -0.26135269029481856,
      -0.26134320440251069, -0.26133362387437792, -0.26132394777335621,
      -0.26131417515324523, -0.261304305058622, -0.2612943365247542,
      -0.26128426857751197, -0.26127410023327985, -0.26126383049886737,
      -0.26125345837141883, -0.26124298283832281, -0.26123240287712046,
      -0.26122171745541267, -0.26121092553076752, -0.26120002605062592,
      -0.26118901795220673, -0.26117790016241138, -0.26116667159772711,
      -0.26115533116412992, -0.26114387775698644, -0.26113231026095479,
      -0.26112062754988508, -0.26110882848671857, -0.261096911923386,
      -0.26108487670070579, -0.26107272164828021, -0.26106044558439168,
      -0.26104804731589759, -0.26103552563812471, -0.26102287933476209,
      -0.26101010717775375, -0.26099720792719006, -0.26098418033119808,
      -0.26097102312583176, -0.26095773503496011, -0.26094431477015528,
      -0.26093076103057961, -0.26091707250287133, -0.26090324786102981,
      -0.26088928576629949, -0.26087518486705319, -0.26086094379867414,
      -0.26084656118343741, -0.26083203563039004, -0.26081736573523051,
      -0.26080255008018677, -0.26078758723389395, -0.26077247575127072,
      -0.26075721417339426, -0.26074180102737532, -0.26072623482623092,
      -0.26071051406875745, -0.26069463723940145, -0.26067860280813038,
      -0.26066240923030182, -0.26064605494653181, -0.26062953838256225,
      -0.26061285794912725, -0.26059601204181804, -0.2605789990409475,
      -0.26056181731141337, -0.26054446520256, -0.26052694104803986,
      -0.26050924316567314, -0.26049136985730692, -0.260473319408673,
      -0.26045509008924472, -0.26043668015209281, -0.26041808783373965,
      -0.2603993113540134, -0.2603803489159, -0.26036119870539481,
      -0.26034185889135303, -0.26032232762533863, -0.26030260304147268,
      -0.26028268325628034, -0.26026256636853662, -0.26024225045911142,
      -0.26022173359081313, -0.260201013808231, -0.26018008913757712,
      -0.26015895758652613, -0.260137617144055, -0.26011606578028079,
      -0.26009430144629786, -0.26007232207401365, -0.26005012557598334,
      -0.26002770984524348, -0.26000507275514462, -0.2599822121591826,
      -0.25995912589082848, -0.259935811763358, -0.25991226756967944,
      -0.25988849108216028, -0.25986448005245311, -0.2598402322113198,
      -0.25981574526845552, -0.25979101691231032, -0.25976604480991089,
      -0.25974082660668019, -0.25971535992625638, -0.259689642370311,
      -0.25966367151836478, -0.2596374449276041, -0.25961096013269452,
      -0.25958421464559461, -0.25955720595536791, -0.25952993152799375,
      -0.25950238880617754, -0.25947457520915934, -0.25944648813252147,
      -0.25941812494799538, -0.25938948300326686, -0.25936055962178062,
      -0.25933135210254343, -0.2593018577199267, -0.25927207372346717,
      -0.25924199733766728, -0.25921162576179407, -0.25918095616967729,
      -0.25914998570950604, -0.25911871150362487, -0.25908713064832845,
      -0.25905524021365534, -0.2590230372431811, -0.25899051875380941,
      -0.25895768173556349, -0.25892452315137537, -0.258891039936875,
      -0.25885722900017794, -0.25882308722167197, -0.2587886114538035,
      -0.25875379852086211, -0.25871864521876486, -0.25868314831483907,
      -0.25864730454760493, -0.25861111062655673, -0.25857456323194306,
      -0.25853765901454706, -0.25850039459546442, -0.25846276656588196,
      -0.25842477148685444, -0.25838640588908124, -0.25834766627268146,
      -0.25830854910696943, -0.25826905083022822, -0.25822916784948335,
      -0.25818889654027544, -0.25814823324643232, -0.2581071742798402,
      -0.25806571592021477, -0.258023854414871, -0.25798158597849297,
      -0.25793890679290266, -0.25789581300682873, -0.25785230073567433,
      -0.2578083660612846, -0.25776400503171382, -0.25771921366099182,
      -0.25767398792889074, -0.25762832378069017, -0.2575822171269434,
      -0.25753566384324211, -0.25748865976998192, -0.25744120071212651,
      -0.25739328243897275, -0.25734490068391463, -0.25729605114420773,
      -0.25724672948073346, -0.25719693131776294, -0.25714665224272126,
      -0.25709588780595144, -0.2570446335204789, -0.25699288486177546,
      -0.25694063726752386, -0.25688788613738245, -0.2568346268327501,
      -0.25678085467653111, -0.25672656495290114, -0.25667175290707256,
      -0.25661641374506122, -0.25656054263345296, -0.256504134699171,
      -0.2564471850292438, -0.25638968867057388, -0.25633164062970648,
      -0.25627303587260025, -0.25621386932439755, -0.25615413586919622,
      -0.25609383034982247, -0.25603294756760409, -0.25597148228214534,
      -0.2559094292111026, -0.25584678302996144, -0.25578353837181472,
      -0.25571968982714222, -0.25565523194359152, -0.25559015922576034,
      -0.25552446613498059, -0.25545814708910375, -0.25539119646228814,
      -0.25532360858478809, -0.25525537774274443, -0.25518649817797756,
      -0.255116964087782, -0.2550467696247235, -0.25497590889643762,
      -0.25490437596543158, -0.25483216484888749, -0.25475926951846856,
      -0.2546856839001278, -0.25461140187391923, -0.25453641727381177,
      -0.25446072388750618, -0.25438431545625473, -0.2543071856746838,
      -0.25422932819062005, -0.25415073660491921, -0.25407140447129872,
      -0.25399132529617346, -0.2539104925384954, -0.25382889960959643,
      -0.25374653987303536, -0.25366340664444886, -0.25357949319140594,
      -0.25349479273326714, -0.25340929844104754, -0.25332300343728453,
      -0.25323590079590963, -0.25314798354212542, -0.2530592446522868,
      -0.25296967705378748, -0.25287927362495155, -0.25278802719492971,
      -0.25269593054360129, -0.2526029764014816, -0.25250915744963481,
      -0.25241446631959263, -0.25231889559327875, -0.2522224378029394,
      -0.25212508543108003, -0.25202683091040867, -0.251927666623785,
      -0.25182758490417689, -0.25172657803462334, -0.2516246382482043,
      -0.251521757728018, -0.25141792860716516, -0.25131314296874097,
      -0.25120739284583449, -0.25110067022153626, -0.25099296702895307,
      -0.25088427515123207, -0.25077458642159212, -0.25066389262336425,
      -0.25055218549004094, -0.25043945670533369, -0.25032569790324039,
      -0.25021090066812152, -0.25009505653478592, -0.24997815698858622,
      -0.24986019346552421, -0.24974115735236627, -0.24962103998676882,
      -0.24949983265741474, -0.24937752660415979, -0.24925411301819056,
      -0.24912958304219307, -0.24900392777053293, -0.24887713824944685,
      -0.24874920547724594, -0.24862012040453102, -0.24848987393442,
      -0.24835845692278785, -0.24822586017851878, -0.24809207446377174,
      -0.24795709049425874, -0.24782089893953629, -0.24768349042331106,
      -0.24754485552375818, -0.24740498477385475, -0.24726386866172673,
      -0.24712149763101049, -0.24697786208122946, -0.24683295236818509,
      -0.24668675880436364, -0.24653927165935779, -0.24639048116030443,
      -0.24624037749233812, -0.24608895079906068, -0.24593619118302745,
      -0.24578208870624979, -0.24562663339071497, -0.24546981521892286,
      -0.24531162413444013, -0.24515205004247229, -0.24499108281045329,
      -0.24482871226865371, -0.24466492821080693, -0.24449972039475432,
      -0.24433307854310926, -0.24416499234394012, -0.24399545145147303,
      -0.24382444548681406, -0.24365196403869144, -0.243477996664218,
      -0.24330253288967388, -0.24312556221131018, -0.24294707409617333,
      -0.24276705798295081, -0.24258550328283818, -0.24240239938042779,
      -0.24221773563461965, -0.24203150137955409, -0.24184368592556718,
      -0.24165427856016858, -0.24146326854904246, -0.2412706451370713,
      -0.24107639754938343, -0.24088051499242369, -0.24068298665504845,
      -0.24048380170964415, -0.24028294931327049, -0.24008041860882798,
      -0.23987619872625021, -0.23967027878372105, -0.23946264788891683,
      -0.23925329514027427, -0.23904220962828343, -0.23882938043680679,
      -0.23861479664442409, -0.23839844732580323, -0.23818032155309754,
      -0.2379604083973697, -0.2377386969300419, -0.23751517622437318,
      -0.23728983535696357, -0.23706266340928525, -0.23683364946924132,
      -0.23660278263275158, -0.23637005200536615, -0.23613544670390657,
      -0.23589895585813475, -0.23566056861244988, -0.23542027412761324,
      -0.23517806158250112, -0.23493392017588594, -0.23468783912824567,
      -0.23443980768360143, -0.23418981511138365, -0.23393785070832646,
      -0.23368390380039072, -0.23342796374471544, -0.23317001993159778,
      -0.23291006178650142, -0.23264807877209367, -0.23238406039031084,
      -0.23211799618445228, -0.23184987574130264, -0.23157968869328274,
      -0.2313074247206286, -0.23103307355359853, -0.23075662497470895,
      -0.23047806882099742, -0.23019739498631425, -0.22991459342364173,
      -0.22962965414744063, -0.22934256723602481, -0.22905332283396246,
      -0.22876191115450495, -0.22846832248204235, -0.22817254717458565,
      -0.22787457566627531, -0.22757439846991623, -0.22727200617953836,
      -0.226967389472983, -0.22666053911451456, -0.2263514459574569,
      -0.22604010094685478, -0.22572649512215917, -0.22541061961993658,
      -0.22509246567660204, -0.22477202463117479, -0.22444928792805691,
      -0.22412424711983397, -0.22379689387009738, -0.22346721995628782,
      -0.22313521727255967, -0.22280087783266511, -0.22246419377285825,
      -0.22212515735481789, -0.22178376096858882, -0.22143999713554102,
      -0.22109385851134572, -0.22074533788896808, -0.2203944282016756,
      -0.22004112252606167, -0.21968541408508341, -0.21932729625111294,
      -0.21896676254900177, -0.21860380665915691, -0.21823842242062838,
      -0.21787060383420687, -0.21750034506553118, -0.21712764044820385,
      -0.21675248448691498, -0.21637487186057233, -0.21599479742543767,
      -0.21561225621826752, -0.21522724345945815, -0.21483975455619314,
      -0.21444978510559271, -0.21405733089786402, -0.21366238791945075,
      -0.21326495235618143, -0.21286502059641516, -0.21246258923418337,
      -0.21205765507232704, -0.21165021512562732, -0.21124026662392908,
      -0.21082780701525611, -0.21041283396891597, -0.20999534537859424,
      -0.20957533936543613, -0.20915281428111449, -0.20872776871088272,
      -0.20830020147661149, -0.20787011163980756, -0.20743749850461349,
      -0.20700236162078689, -0.20656470078665795, -0.20612451605206311,
      -0.20568180772125441, -0.20523657635578241, -0.20478882277735125,
      -0.20433854807064472, -0.20388575358612149, -0.20343044094277796,
      -0.20297261203087771, -0.20251226901464536, -0.20204941433492365,
      -0.20158405071179231, -0.20111618114714674, -0.20064580892723546,
      -0.20017293762515415, -0.19969757110329539, -0.19921971351575185,
      -0.19873936931067177, -0.19825654323256525, -0.19777124032455906,
      -0.19728346593059926, -0.19679322569759933, -0.19630052557753294,
      -0.19580537182946878, -0.19530777102154692, -0.19480773003289448,
      -0.194305256055479, -0.1938003565958985, -0.1932930394771061,
      -0.19278331284006789, -0.19227118514535232, -0.19175666517465029,
      -0.19123976203222309, -0.19072048514627826, -0.19019884427027056,
      -0.18967484948412744, -0.189148511195397, -0.18861984014031746,
      -0.18808884738480669, -0.18755554432536958, -0.18701994268992347,
      -0.18648205453853853, -0.18594189226409324, -0.18539946859284276,
      -0.18485479658489926, -0.18430788963462305, -0.18375876147092307,
      -0.18320742615746588, -0.1826538980927917, -0.18209819201033639,
      -0.18154032297835904, -0.18098030639977275, -0.18041815801187902,
      -0.17985389388600398, -0.17928753042703557, -0.17871908437286138,
      -0.17814857279370555, -0.17757601309136456, -0.17700142299834082,
      -0.17642482057687353, -0.17584622421786622, -0.17526565263970995,
      -0.17468312488700244, -0.17409866032916171, -0.17351227865893443,
      -0.17292399989079837, -0.17233384435925872, -0.17174183271703752,
      -0.17114798593315686, -0.17055232529091482, -0.16995487238575455,
      -0.16935564912302614, -0.16875467771564157, -0.16815198068162251,
      -0.16754758084154123, -0.16694150131585483, -0.166333765522133,
      -0.16572439717217946, -0.16511342026904768, -0.16450085910395118,
      -0.163886738253069, -0.16327108257424644, -0.16265391720359251,
      -0.162035267551974, -0.16141515930140704, -0.16079361840134768,
      -0.16017067106488092, -0.15954634376481069, -0.15892066322965079,
      -0.1582936564395177, -0.15766535062192738, -0.15703577324749615,
      -0.15640495202554744, -0.15577291489962561, -0.15513969004291819,
      -0.15450530585358785, -0.15386979095001566, -0.15323317416595733,
      -0.15259548454561361, -0.15195675133861697, -0.15131700399493575,
      -0.15067627215969814, -0.15003458566793731, -0.14939197453925979,
      -0.14874846897243865, -0.14810409933993457, -0.14745889618234481,
      -0.14681289020278471, -0.14616611226120113, -0.14551859336862241,
      -0.14487036468134551, -0.14422145749506293, -0.14357190323893232,
      -0.14292173346959003, -0.14227097986511228, -0.14161967421892488,
      -0.1409678484336655, -0.14031553451499967, -0.13966276456539373,
      -0.13900957077784715, -0.13835598542958691, -0.13770204087572596,
      -0.13704776954288916, -0.13639320392280907, -0.13573837656589402,
      -0.13508332007477125, -0.13442806709780838, -0.13377265032261493,
      -0.13311710246952771, -0.13246145628508191, -0.13180574453547128, -0.13115,
      -0.13049425546452867, -0.12983854371491807, -0.12918289753047227,
      -0.12852734967738505, -0.12787193290219162, -0.12721667992522873,
      -0.12656162343410596, -0.12590679607719088, -0.12525223045711081,
      -0.12459795912427402, -0.12394401457041307, -0.1232904292221528,
      -0.12263723543460628, -0.12198446548500033, -0.12133215156633448,
      -0.1206803257810751, -0.12002902013488773, -0.11937826653040995,
      -0.11872809676106766, -0.11807854250493702, -0.11742963531865447,
      -0.11678140663137754, -0.11613388773879887, -0.11548710979721527,
      -0.11484110381765517, -0.11419590066006544, -0.11355153102756133,
      -0.11290802546074022, -0.11226541433206264, -0.11162372784030183,
      -0.11098299600506425, -0.11034324866138301, -0.10970451545438634,
      -0.10906682583404265, -0.10843020904998429, -0.10779469414641213,
      -0.10716030995708178, -0.10652708510037437, -0.10589504797445254,
      -0.10526422675250383, -0.1046346493780726, -0.10400634356048227,
      -0.10337933677034919, -0.10275365623518926, -0.10212932893511906,
      -0.1015063815986523, -0.10088484069859291, -0.100264732448026,
      -0.099646082796407465, -0.099028917425753538, -0.098413261746930991,
      -0.0977991408960488, -0.0971865797309523, -0.096575602827820545,
      -0.09596623447786698, -0.095358498684145115, -0.094752419158458778,
      -0.09414801931837749, -0.093545322284358412, -0.092944350876973864,
      -0.092345127614245431, -0.091747674709085153, -0.091152014066843118,
      -0.090558167282962454, -0.089966155640741258, -0.0893760001092016,
      -0.088787721341065579, -0.088201339670838264, -0.087616875112997539,
      -0.08703434736029, -0.086453775782133757, -0.085875179423126446,
      -0.085298577001659159, -0.084723986908635418, -0.084151427206294427,
      -0.083580915627138569, -0.0830124695729644, -0.082446106113996,
      -0.081881841988120957, -0.081319693600227255, -0.080759677021640969,
      -0.080201807989663587, -0.079646101907208278, -0.07909257384253407,
      -0.0785412385290769, -0.077992110365376927, -0.077445203415100722,
      -0.076900531407157219, -0.076358107735906733, -0.075817945461461478,
      -0.0752800573100765, -0.0747444556746304, -0.074211152615193315,
      -0.073680159859682515, -0.07315148880460301, -0.072625150515872539,
      -0.072101155729729388, -0.071579514853721715, -0.071060237967776912,
      -0.070543334825349718, -0.070028814854647653, -0.069516687159932117,
      -0.069006960522893873, -0.0684996434041015, -0.067994743944520986,
      -0.067492269967105528, -0.066992228978453056, -0.066494628170531228,
      -0.065999474422467036, -0.06550677430240065, -0.065016534069400722,
      -0.064528759675440889, -0.064043456767434725, -0.063560630689328185,
      -0.063080286484248155, -0.062602428896704587, -0.062127062374845832,
      -0.061654191072764514, -0.061183818852853233, -0.060715949288207671,
      -0.060250585665076295, -0.059787730985354642, -0.059327387969122264,
      -0.058869559057222021, -0.058414246413878518, -0.057961451929355284,
      -0.057511177222648729, -0.0570634236442176, -0.056618192278745566,
      -0.056175483947936866, -0.055735299213342027, -0.055297638379213032,
      -0.05486250149538649, -0.054429888360192386, -0.053999798523388459,
      -0.053572231289117256, -0.053147185718885492, -0.052724660634563852,
      -0.052304654621405738, -0.051887166031083981, -0.05147219298474387,
      -0.051059733376070865, -0.050649784874372661, -0.050242344927672905,
      -0.049837410765816575, -0.04943497940358485, -0.049035047643818552,
      -0.048637612080549231, -0.048242669102135954, -0.047850214894407272,
      -0.047460245443806837, -0.0470727565405418, -0.04668774378173246,
      -0.046305202574562304, -0.045925128139427646, -0.045547515513085,
      -0.045172359551796132, -0.0447996549344688, -0.044429396165793111,
      -0.044061577579371625, -0.043696193340843043, -0.043333237450998208,
      -0.042972703748887037, -0.0426145859149166, -0.042258877473938306,
      -0.041905571798324381, -0.0415546621110319, -0.04120614148865423,
      -0.040860002864458955, -0.040516239031411161, -0.040174842645182091,
      -0.039835806227141723, -0.039499122167334866, -0.039164782727440312,
      -0.038832780043712128, -0.0385031061299026, -0.038175752880166,
      -0.037850712071943071, -0.037527975368825184, -0.037207534323397934,
      -0.036889380380063369, -0.036573504877840807, -0.036259899053145195,
      -0.035948554042543046, -0.035639460885485419, -0.035332610527016972,
      -0.035027993820461623, -0.03472560153008375, -0.034425424333724641,
      -0.034127452825414351, -0.033831677517957626, -0.033538088845495029,
      -0.033246677166037547, -0.032957432763975142, -0.032670345852559346,
      -0.032385406576358272, -0.0321026050136857, -0.031821931179002588,
      -0.031543375025291059, -0.031266926446401444, -0.030992575279371382,
      -0.030720311306717235, -0.030450124258697336, -0.030182003815547725,
      -0.029915939609689135, -0.029651921227906303, -0.029389938213498557,
      -0.0291299800684022, -0.028872036255284561, -0.028616096199609253,
      -0.028362149291673522, -0.02811018488861633, -0.027860192316398524,
      -0.027612160871754304, -0.027366079824114042, -0.027121938417498881,
      -0.026879725872386712, -0.026639431387550067, -0.026401044141865226,
      -0.026164553296093407, -0.025929947994633828, -0.025697217367248365,
      -0.025466350530758686, -0.025237336590714726, -0.025010164643036403,
      -0.024784823775626769, -0.024561303069958074, -0.024339591602630273,
      -0.024119678446902437, -0.023901552674196774, -0.023685203355575862,
      -0.023470619563193157, -0.023257790371716547, -0.023046704859725708,
      -0.022837352111083176, -0.022629721216278931, -0.022423801273749738,
      -0.022219581391171972, -0.022017050686729489, -0.021816198290355832,
      -0.02161701334495153, -0.021419485007576261, -0.02122360245061658,
      -0.021029354862928673, -0.020836731450957546, -0.020645721439831372,
      -0.020456314074432824, -0.020268498620445885, -0.020082264365380326,
      -0.019897600619572159, -0.0197144967171618, -0.019532942017049165,
      -0.019352925903826645, -0.019174437788689797, -0.0189974671103261,
      -0.018822003335781989, -0.01864803596130854, -0.018475554513185888,
      -0.01830454854852695, -0.018135007656059854, -0.017966921456890717,
      -0.017800279605245634, -0.017635071789193046, -0.017471287731346291,
      -0.017308917189546663, -0.017147949957527719, -0.016988375865559846,
      -0.016830184781077118, -0.016673366609285006, -0.016517911293750159,
      -0.016363808816972553, -0.01621104920093927, -0.01605962250766188,
      -0.015909518839695547, -0.015760728340642211, -0.015613241195636368,
      -0.015467047631814862, -0.015322137918770545, -0.015178502368989488,
      -0.015036131338273251, -0.014895015226145225, -0.014755144476241766,
      -0.014616509576688946, -0.014479101060463656, -0.014342909505741269,
      -0.014207925536228211, -0.014074139821481202, -0.013941543077212126,
      -0.013810126065579964, -0.013679879595468958, -0.013550794522754039,
      -0.013422861750553128, -0.013296072229467049, -0.01317041695780688,
      -0.01304588698180939, -0.012922473395840212, -0.012800167342585239,
      -0.012678960013231128, -0.012558842647633739, -0.012439806534475739,
      -0.012321843011413786, -0.012204943465214058, -0.012089099331878461,
      -0.011974302096759593, -0.011860543294666348, -0.011747814509959098,
      -0.011636107376635674, -0.011525413578407862, -0.011415724848767905,
      -0.011307032971046904, -0.011199329778463774, -0.011092607154165435,
      -0.010986857031259012, -0.010882071392834813, -0.01077824227198193,
      -0.01067536175179562, -0.010573421965376639, -0.010472415095823029,
      -0.010372333376214959, -0.010273169089591305, -0.010174914568919946,
      -0.010077562197060574, -0.00998110440672123, -0.009885533680407288,
      -0.0097908425503651086, -0.0096970235985183728, -0.00960406945639869,
      -0.0095119728050702679, -0.0094207263750483716, -0.0093303229462124437,
      -0.0092407553477132365, -0.0091520164578746122, -0.0090640992040902923,
      -0.0089769965627154447, -0.00889070155895244, -0.00880520726673284,
      -0.0087205068085940418, -0.0086365933555511143, -0.0085534601269646182,
      -0.0084711003904036075, -0.008389507461504575, -0.0083086747038264575,
      -0.0082285955287012547, -0.0081492633950807636, -0.0080706718093799257,
      -0.0079928143253161776, -0.00791568454374525, -0.0078392761124937427,
      -0.0077635827261882118, -0.0076885981260808034, -0.0076143160998721759,
      -0.0075407304815314768, -0.00746783515111249, -0.0073956240345683932,
      -0.0073240911035623024, -0.007253230375276476, -0.0071830359122179721,
      -0.0071135018220224722, -0.0070446222572555506, -0.0069763914152119466,
      -0.0069088035377117829, -0.0068418529108962289, -0.00677553386501939,
      -0.0067098407742395838, -0.0066447680564084566, -0.0065803101728577618,
      -0.006516461628185255, -0.0064532169700385889, -0.0063905707888973762,
      -0.0063285177178546426, -0.006267052432395892, -0.006206169650177451,
      -0.0061458641308037021, -0.0060861306756024858, -0.0060269641273997254,
      -0.0059683593702934967, -0.0059103113294260989, -0.0058528149707561816,
      -0.0057958653008290395, -0.0057394573665470183, -0.005683586254938755,
      -0.0056282470929274186, -0.00557343504709884, -0.00551914532346881,
      -0.0054653731672498762, -0.0054121138626174736, -0.0053593627324761139,
      -0.0053071151382245163, -0.0052553664795210731, -0.005204112194048538,
      -0.0051533477572787145, -0.005103068682237033, -0.0050532705192665173,
      -0.0050039488557921952, -0.0049550993160853429, -0.004906717561027174,
      -0.0048587992878734165, -0.0048113402300180574, -0.0047643361567578646,
      -0.0047177828730566307, -0.004671676219309806, -0.0046260120711092978,
      -0.0045807863390081027, -0.0045359949682861611, -0.0044916339387153781,
      -0.0044476992643256441, -0.0044041869931713, -0.0043610932070973774,
      -0.004318414021507011, -0.0042761455851289543, -0.004234284079785211,
      -0.0041928257201597208, -0.0041517667535676539, -0.0041111034597245411,
      -0.0040708321505166789, -0.0040309491697717581, -0.0039914508930305459,
      -0.0039523337273185133, -0.0039135941109187944, -0.0038752285131455344,
      -0.0038372334341180148, -0.0037996054045355554, -0.0037623409854529166,
      -0.0037254367680568667, -0.0036888893734433048, -0.0036526954523950494,
      -0.0036168516851609045, -0.0035813547812351687, -0.0035462014791378116,
      -0.0035113885461964811, -0.0034769127783280118, -0.0034427709998220979,
      -0.0034089600631249106, -0.0033754768486245479, -0.0033423182644364835,
      -0.0033094812461905154, -0.0032769627568188797, -0.0032447597863445865,
      -0.0032128693516715323, -0.003181288496375112, -0.003150014290493941,
      -0.0031190438303226875, -0.0030883742382059043, -0.0030580026623326928,
      -0.0030279262765328108, -0.0029981422800732793, -0.0029686478974565444,
      -0.00293944037821936, -0.0029105169967331146, -0.002881875052004601,
      -0.0028535118674785087, -0.002825424790840636, -0.0027976111938224357,
      -0.0027700684720062818, -0.0027427940446321242, -0.0027157853544053645,
      -0.0026890398673055094, -0.002662555072395878, -0.0026363284816351418,
      -0.0026103576296889752, -0.0025846400737435382, -0.0025591733933197913,
      -0.0025339551900890878, -0.0025089830876896535, -0.0024842547315444552,
      -0.0024597677886801228, -0.0024355199475468714, -0.0024115089178396443,
      -0.0023877324303205327, -0.0023641882366420286, -0.002340874109171498,
      -0.0023177878408174313, -0.0022949272448553604, -0.0022722901547564955,
      -0.00224987442401664, -0.0022276779259862711, -0.0022056985537021179,
      -0.0021839342197191858, -0.002162382855945, -0.0021410424134738482,
      -0.002119910862422858, -0.0020989861917689034, -0.0020782664091868464,
      -0.0020577495408885538, -0.002037433631463359, -0.0020173167437196327,
      -0.0019973969585272977, -0.0019776723746613434, -0.0019581411086469491,
      -0.0019388012946051636, -0.0019196510840999714, -0.0019006886459866368,
      -0.0018819121662603244, -0.0018633198479071633, -0.0018449099107552547,
      -0.0018266805913270123, -0.0018086301426931128, -0.0017907568343268898,
      -0.0017730589519600604, -0.0017555347974398949, -0.0017381826885866092,
      -0.0017210009590524766, -0.0017039879581819961, -0.0016871420508727808,
      -0.001670461617437724, -0.0016539450534682199, -0.0016375907696982162,
      -0.0016213971918696002, -0.0016053627605985277, -0.0015894859312425291,
      -0.0015737651737690039, -0.0015581989726246581, -0.0015427858266057193,
      -0.0015275242487292617, -0.0015124127661060305, -0.0014974499198132651,
      -0.0014826342647694668, -0.0014679643696098865, -0.0014534388165625689,
      -0.0014390562013258945, -0.0014248151329467884, -0.001410714233700483,
      -0.0013967521389701698, -0.0013829274971286498, -0.0013692389694203722,
      -0.0013556852298446942, -0.0013422649650399188, -0.001328976874168164,
      -0.0013158196688018986, -0.0013027920728099773, -0.0012898928222462303,
      -0.0012771206652378853, -0.0012644743618752674, -0.0012519526841023865,
      -0.0012395544156083016, -0.0012272783517198183, -0.0012151232992941852,
      -0.0012030880766139562, -0.0011911715132814638, -0.0011793724501148461,
      -0.0011676897390451857, -0.0011561222430135909, -0.0011446688358700552,
      -0.0011333284022728707, -0.0011220998375885971, -0.0011109820477932519,
      -0.0010999739493740557, -0.0010890744692324539, -0.0010782825445873057,
      -0.0010675971228795711, -0.0010570171616771651, -0.0010465416285811435,
      -0.0010361695011326666, -0.0010258997667200731, -0.0010157314224880087,
      -0.0010056634752457771, -0.00099569494137791148, -0.000985824846754746,
      -0.00097605222664381985, -0.00096637612562205932, -0.00095679559748929055,
      -0.00094730970518142055, -0.00093791752068533851, -0.00092861812495426133,
      -0.00091941060782341211, -0.000910294067927031, -0.00090126761261583033,
      -0.00089233035787517068, -0.00088348142824407061, -0.00087471995673449321,
      -0.00086604508475235376, -0.00085745596201780572, -0.00084895174648763616,
      -0.00084053160427721707, -0.00083219470958384445, -0.00082394024461074356,
      -0.00081576739949112964, -0.00080767537221349, -0.00079966336854769837,
      -0.00079173060197101908, -0.00078387629359566446, -0.00077609967209624209,
      -0.00076839997363853385, -0.00076077644180799764, -0.00075322832754021185,
      -0.00074575488905059828, -0.00073835539176581033, -0.00073102910825478817,
      -0.00072377531816164575, -0.00071659330813778066, -0.00070948237177598239,
      -0.00070244180954365243, -0.0006954709287183003, -0.00068856904332198487,
      -0.00068173547405736556, -0.00067496954824441957, -0.00066827059975688163,
      -0.0006616379689598495, -0.00065507100264833307, -0.000648569053985304,
      -0.00064213148244118834, -0.0006357576537338594, -0.00062944693976846322,
      -0.00062319871857852149, -0.00061701237426753375, -0.00061088729695074617,
      -0.00060482288269725348, -0.00059881853347382163, -0.00059287365708771134,
      -0.00058698766713083383, -0.00058115998292457283, -0.0005753900294647174,
      -0.00056967723736695008, -0.000564021042813112, -0.00055842088749741281,
      -0.00055287621857397218, -0.00054738648860397365, -0.000541951155503928,
      -0.00053656968249421455, -0.00053124153804778862, -0.00052596619584005522,
      -0.00052074313469852029, -0.00051557183855333033, -0.00051045179638797844,
      -0.00050538250219078762, -0.00050036345490672707, -0.00049539415838950607,
      -0.00049047412135416746, -0.00048560285733034725, -0.00048077988461586729,
      -0.00047600472623055, -0.00047127690987069926, -0.00046659596786408075,
      -0.00046196143712479154, -0.00045737285910946168, -0.00045282977977284533,
      -0.00044833174952479959, -0.00044387832318670828, -0.00043946905994923791,
      -0.00043510352332976066, -0.00043078128113061, -0.00042650190539755828,
      -0.00042226497237873861, -0.00041807006248389955, -0.00041391676024393753,
      -0.00040980465427126189, -0.00040573333722010441, -0.00040170240574699534,
      -0.00039771146047240524, -0.0003937601059421092, -0.00038984795058893962,
      -0.00038597460669526074, -0.00038213969035538753, -0.00037834282143883735,
      -0.00037458362355324848, -0.00037086172400840889, -0.00036717675378022951,
      -0.00036352834747471752, -0.00035991614329344834, -0.00035633978299748348,
      -0.00035279891187395274, -0.00034929317870086019, -0.00034582223571327786,
      -0.00034238573857009458, -0.00033898334632015414, -0.00033561472136961479,
      -0.00033227952944903105, -0.00032897743958099079, -0.00032570812404808525,
      -0.00032247125836104562, -0.00031926652122743482, -0.00031609359452022812,
      -0.0003129521632471155, -0.000309841915519915, -0.00030676254252409718,
      -0.00030371373848903094, -0.00030069520065811872, -0.00029770662925937552,
      -0.00029474772747639655, -0.00029181820141921389, -0.00028891776009620784,
      -0.00028604611538501912, -0.00028320298200534832, -0.00028038807749053429,
      -0.00027760112216040911, -0.00027484183909398663, -0.00027210995410220651,
      -0.00026940519570162191, -0.00026672729508764315, -0.0002640759861084474,
      -0.00026145100523899956, -0.00025885209155512845, -0.00025627898670860239,
      -0.00025373143490114991, -0.000251209182860368, -0.00024871197981396476,
      -0.00024623957746633396, -0.00024379172997335274, -0.00024136819391901154,
      -0.0002389687282912667, -0.00023659309445867027, -0.00023424105614683333,
      -0.00023191237941544429, -0.00022960683263539838, -0.00022732418646609354,
      -0.00022506421383289288, -0.00022282668990503129, -0.000220611392073633,
      -0.00021841809992956263, -0.00021624659524227541, -0.0002140966619381679,
      -0.00021196808607953921, -0.00020986065584344127, -0.00020777416150108419,
      -0.00020570839539707508, -0.00020366315192943407, -0.00020163822752894411,
      -0.00019963342063944456, -0.00019764853169801366, -0.00019568336311537315,
      -0.00019373771925645933, -0.00019181140642116068, -0.00018990423282555513,
      -0.00018801600858264766, -0.00018614654568405165, -0.00018429565798155911,
      -0.00018246316116832251, -0.00018064887276142416, -0.0001788526120834466,
      -0.00017707420024498655, -0.00017531346012689131, -0.00017357021636266179,
      -0.00017184429532196566, -0.0001701355250924852, -0.00016844373546365254,
      -0.00016676875791005186, -0.00016511042557415534, -0.00016346857325055808,
      -0.00016184303736921368, -0.00016023365597961359, -0.00015864026873496639,
      -0.00015706271687582207, -0.00015550084321502844, -0.000153954492121966,
      -0.00015242350950728234, -0.00015090774280768215, -0.00014940704097060609,
      -0.0001479212544399644, -0.0001464502351408159, -0.00014499383646504604,
      -0.00014355191325676753, -0.0001421243217980539, -0.00014071091979478423,
      -0.00013931156636259878, -0.00013792612201296572, -0.00013655444863930333,
      -0.00013519640950360179, -0.00013385186922265646, -0.0001325206937548562,
      -0.00013120275038697171, -0.00012989790772083287, -0.0001286060356607277,
      -0.00012732700539991315, -0.00012606068940873572, -0.00012480696142130876,
      -0.00012356569642330006, -0.00012233677063966386, -0.00012112006152231736,
      -0.00011991544773781726, -0.00011872280915597999, -0.00011754202683722514,
      -0.0001163729830211957, -0.00011521556111526721, -0.00011406964568272393,
      -0.00011293512243143455, -0.00011181187820263894, -0.0001106998009594018,
      -0.0001095987797761766, -0.00010850870482720376, -0.00010742946737585246,
      -0.00010636095976396254, -0.00010530307540096429, -0.00010425570875366441,
      -0.00010321875533547686, -0.00010219211169604225, -0.00010117567541129135,
      -0.00010016934507323105, -9.9173020279452739E-5, -9.8186601623861947E-5,
      -9.7209990686353276E-5, -9.6243090023040434E-5, -9.52858031570969E-5,
      -9.4338034568597351E-5, -9.33996896854139E-5, -9.24706748736126E-5,
      -9.1550897428460676E-5, -9.0640265564989608E-5, -8.97386884087803E-5,
      -8.8846075987525364E-5, -8.7962339221314689E-5, -8.7087389914586311E-5,
      -8.6221140746634E-5, -8.5363505263558181E-5, -8.4514397869384084E-5,
      -8.3673733817513085E-5, -8.2841429202507033E-5, -8.2017400951761577E-5,
      -8.1201566817068471E-5, -8.0393845366455441E-5, -7.9594155976581149E-5,
      -7.8802418823964437E-5, -7.8018554877712365E-5, -7.7242485891249046E-5,
      -7.6474134394877158E-5, -7.5713423687839843E-5, -7.49602778308267E-5,
      -7.4214621638368783E-5, -7.3476380671344543E-5, -7.2745481229763431E-5,
      -7.2021850345382887E-5, -7.1305415774158831E-5, -7.0596105989528812E-5,
      -6.9893850174918E-5, -6.9198578217077866E-5, -6.8510220698814184E-5,
      -6.78287088921592E-5, -6.7153974751599232E-5, -6.648595090730236E-5,
      -6.5824570658401527E-5, -6.5169767966499759E-5, -6.4521477448675757E-5,
      -6.3879634371599714E-5, -6.3244174644705442E-5, -6.2615034813806592E-5,
      -6.1992152054934913E-5, -6.1375464168011984E-5, -6.0764909570854009E-5,
      -6.01604272926215E-5, -5.956195696832367E-5, -5.8969438832212617E-5,
      -5.8382813712343218E-5, -5.780202302452242E-5, -5.7227008766258525E-5,
      -5.6657713511321095E-5, -5.6094080403801261E-5, -5.5536053152727138E-5,
      -5.4983576026013115E-5, -5.4436593845352821E-5, -5.3895051980445974E-5,
      -5.3358896343891349E-5, -5.28280733853026E-5, -5.2302530086478782E-5,
      -5.178221395579774E-5, -5.1267073023109067E-5, -5.0757055834627085E-5,
      -5.0252111447768311E-5, -4.97521894259334E-5, -4.92572398337332E-5,
      -4.876721323177069E-5, -4.8282060671922533E-5, -4.7801733692398596E-5,
      -4.7326184312801445E-5, -4.6855365029629947E-5, -4.6389228811227756E-5,
      -4.5927729093286906E-5, -4.547081977424039E-5, -4.5018455210377173E-5,
      -4.4570590211845396E-5, -4.4127180037489833E-5, -4.3688180391077136E-5,
      -4.3253547416299831E-5, -4.2823237692612981E-5, -4.239720823112636E-5,
      -4.1975416470108051E-5, -4.1557820270599066E-5, -4.1144377912583074E-5,
      -4.0735048090656534E-5, -4.0329789909754332E-5, -3.9928562881264007E-5,
      -3.9531326919028942E-5, -3.9138042335240542E-5, -3.8748669836441429E-5,
      -3.8363170519750689E-5, -3.798150586886706E-5, -3.7603637750405206E-5,
      -3.7229528409843393E-5, -3.68591404680263E-5, -3.6492436917168192E-5,
      -3.6129381117411263E-5, -3.5769936792939827E-5, -3.541406802870517E-5,
      -3.5061739266373237E-5, -3.471291530132703E-5, -3.4367561278558778E-5,
      -3.4025642689727853E-5, -3.3687125369441517E-5, -3.3351975491979768E-5,
      -3.3020159567576091E-5, -3.26916444396419E-5, -3.2366397281213821E-5,
      -3.204438559128997E-5, -3.1725577192276422E-5, -3.1409940226267974E-5,
      -3.1097443152161564E-5, -3.0788054742214577E-5, -3.0481744079324802E-5,
      -3.0178480553588738E-5, -2.9878233859470527E-5, -2.9580973992637816E-5,
      -2.9286671247130691E-5, -2.899529621214203E-5, -2.8706819769463987E-5,
      -2.8421213090157327E-5, -2.813844763205342E-5, -2.78584951365346E-5,
      -2.7581327626147178E-5, -2.7306917401548336E-5, -2.7035237038508519E-5,
      -2.6766259385857527E-5, -2.6499957561987308E-5, -2.6236304952853562E-5,
      -2.59752752088116E-5, -2.5716842242229365E-5, -2.5460980224989438E-5,
      -2.5207663585546936E-5, -2.495686700665356E-5, -2.4708565422970619E-5,
      -2.4462734018182442E-5, -2.4219348222775938E-5, -2.3978383711431572E-5,
      -2.3739816400858427E-5, -2.350362244718518E-5, -2.3269778243517614E-5,
      -2.3038260417773682E-5, -2.2809045830241015E-5, -2.2582111571245456E-5,
      -2.2357434959041633E-5, -2.2134993537259451E-5, -2.1914765072850173E-5,
      -2.1696727553977002E-5, -2.1480859187572587E-5, -2.12671383972296E-5,
      -2.1055543821091316E-5, -2.0846054309908713E-5, -2.0638648924486969E-5,
      -2.0433306933964612E-5, -2.02300078137041E-5, -2.002873124296034E-5,
      -1.9829457103215375E-5, -1.963216547601343E-5, -1.9436836640907007E-5,
      -1.9243451073569506E-5, -1.9051989443907846E-5, -1.8862432613786506E-5,
      -1.8674761635806281E-5, -1.8488957750695256E-5, -1.83050023857545E-5,
      -1.8122877153137207E-5, -1.7942563847628268E-5, -1.7764044445256477E-5,
      -1.7587301101296138E-5, -1.7412316148213147E-5, -1.7239072094499264E-5,
      -1.7067551622562682E-5, -1.6897737586785144E-5, -1.6729613012300693E-5,
      -1.6563161092886247E-5, -1.6398365189684849E-5, -1.6235208829040726E-5,
      -1.6073675701444579E-5, -1.5913749659202114E-5, -1.575541471565689E-5,
      -1.5598655042692311E-5, -1.5443454970009984E-5, -1.5289798982909275E-5,
      -1.5137671721066059E-5, -1.4987057976922902E-5, -1.4837942694134743E-5,
      -1.469031096623663E-5, -1.4544148034811855E-5, -1.439943928832621E-5,
      -1.4256170260684708E-5, -1.4114326629510732E-5, -1.3973894214924787E-5,
      -1.3834858978045705E-5, -1.3697207019602864E-5, -1.356092457877045E-5,
      -1.3425998031335595E-5, -1.3292413888754684E-5, -1.3160158796599042E-5,
      -1.3029219533111647E-5, -1.2899583008318949E-5, -1.2771236262254515E-5,
      -1.2644166463904316E-5, -1.251836090987446E-5, -1.2393807023169945E-5,
      -1.2270492351751372E-5, -1.2148404567646764E-5, -1.2027531465230723E-5,
      -1.1907860960669314E-5, -1.1789381089866158E-5, -1.1672080008018337E-5,
      -1.15559459881176E-5, -1.1440967419673598E-5, -1.1327132807825713E-5,
      -1.1214430771899764E-5, -1.1102850044630852E-5, -1.0992379470553537E-5,
      -1.0883008005391215E-5, -1.0774724714668338E-5, -1.0667518772600193E-5,
      -1.0561379461204723E-5, -1.0456296168914747E-5, -1.0352258389911828E-5,
      -1.0249255722794004E-5, -1.0147277869632099E-5, -1.0046314634970521E-5,
      -9.946355924717043E-6, -9.8473917451435966E-6, -9.74941220210912E-6,
      -9.6524074996717779E-6, -9.5563679394228274E-6, -9.4612839195429288E-6,
      -9.36714593352539E-6, -9.27394456956554E-6, -9.1816705093950013E-6,
      -9.09031452756004E-6, -8.9998674901448084E-6, -8.9103203544382836E-6,
      -8.82166416737995E-6, -8.73389006500469E-6, -8.64698927172114E-6,
      -8.56095309903493E-6, -8.4757729449380648E-6, -8.3914402930762577E-6,
      -8.3079467116942141E-6, -8.2252838530250116E-6, -8.1434434520688548E-6,
      -8.0624173265375632E-6, -7.9821973750227038E-6, -7.9027755770511021E-6,
      -7.8241439918080857E-6, -7.74629475741584E-6, -7.6692200903782926E-6,
      -7.5929122844153873E-6, -7.5173637101300095E-6, -7.442566813786744E-6,
      -7.3685141170343194E-6, -7.295198215684362E-6, -7.2226117793783295E-6,
      -7.15074755058831E-6, -7.0795983440063992E-6, -7.0091570458785668E-6,
      -6.9394166131164781E-6, -6.8703700727423822E-6, -6.8020105210564452E-6,
      -6.7343311231926606E-6, -6.6673251121196486E-6, -6.6009857883631007E-6,
      -6.5353065187845338E-6, -6.4702807364702686E-6, -6.4059019397877393E-6,
      -6.3421636916638491E-6, -6.2790596191963921E-6, -6.2165834128213859E-6,
      -6.1547288258134714E-6, -6.093489673397734E-6, -6.0328598326386818E-6,
      -5.972833241219E-6, -5.9134038973285286E-6, -5.8545658587205729E-6,
      -5.7963132423788366E-6, -5.7386402237957768E-6, -5.68154103630647E-6,
      -5.6250099707555457E-6, -5.56904137472003E-6, -5.5136296520097439E-6,
      -5.4587692620566841E-6, -5.4044547195264414E-6, -5.3506805935410462E-6,
      -5.2974415073459014E-6, -5.2447321375326261E-6, -5.1925472139280338E-6,
      -5.14088151853942E-6, -5.0897298852770056E-6, -5.0390871996763842E-6,
      -4.9889483979548288E-6, -4.9393084667892495E-6, -4.8901624426500589E-6,
      -4.8415054114125944E-6, -4.7933325080240508E-6, -4.7456389156153023E-6,
      -4.6984198652788578E-6, -4.6516706355692605E-6, -4.6053865520034876E-6,
      -4.5595629867278831E-6, -4.5141953577965133E-6, -4.4692791288380995E-6,
      -4.4248098086119292E-6, -4.3807829507303E-6, -4.3371941528813629E-6,
      -4.2940390564405462E-6, -4.2513133464705533E-6, -4.2090127507221631E-6,
      -4.1671330394121853E-6, -4.1256700250014156E-6, -4.0846195616395242E-6,
      -4.0439775444989223E-6, -4.003739909885784E-6, -3.9639026341853345E-6,
      -3.9244617340283838E-6, -3.8854132657917262E-6, -3.846753324820984E-6,
      -3.8084780454861189E-6, -3.7705836005152982E-6, -3.73306620077285E-6,
      -3.6959220948151739E-6, -3.6591475685576746E-6, -3.6227389447751612E-6,
      -3.5866925828798024E-6, -3.5510048785325488E-6, -3.5156722632545545E-6,
      -3.4806912039275772E-6, -3.4460582027384667E-6, -3.4117697967350757E-6,
      -3.3778225572156373E-6, -3.3442130897842759E-6, -3.3109380335183403E-6,
      -3.2779940613569813E-6, -3.2453778790464405E-6, -3.2130862251955605E-6,
      -3.1811158707761855E-6, -3.1494636190676495E-6, -3.1181263049906427E-6,
      -3.0871007949961893E-6, -3.0563839868436027E-6, -3.0259728088788407E-6,
      -2.9958642202010388E-6, -2.9660552102184212E-6, -2.9365427981487002E-6,
      -2.9073240329635652E-6, -2.8783959929445935E-6, -2.8497557855167166E-6,
      -2.821400546637598E-6, -2.7933274410751885E-6, -2.7655336617415927E-6,
      -2.7380164292489795E-6, -2.710772992131627E-6, -2.6838006262353E-6,
      -2.6570966342731595E-6, -2.6306583461588318E-6, -2.6044831182292505E-6,
      -2.5785683329115905E-6, -2.5529113990563346E-6, -2.5275097509380728E-6,
      -2.5023608486440807E-6, -2.4774621773526739E-6, -2.4528112473332087E-6,
      -2.4284055936130144E-6, -2.4042427756998386E-6, -2.3803203774708237E-6,
      -2.356636006839441E-6, -2.3331872953114008E-6, -2.3099718982622086E-6,
      -2.2869874942710311E-6, -2.2642317848986515E-6, -2.2417024947429809E-6,
      -2.2193973709949688E-6, -2.1973141831610477E-6, -2.1754507230631326E-6,
      -2.1538048044500435E-6, -2.1323742628309716E-6, -2.1111569551424125E-6,
      -2.0901507598591884E-6, -2.0693535763838256E-6, -2.0487633251020654E-6,
      -2.0283779470497976E-6, -2.0081954037465266E-6, -1.9882136770843495E-6,
      -1.9684307689393776E-6, -1.9488447010607146E-6, -1.9294535149039227E-6,
      -1.9102552714644894E-6, -1.8912480510002716E-6, -1.8724299528094512E-6,
      -1.8537990951750238E-6, -1.8353536150317318E-6, -1.8170916679105531E-6,
      -1.799011427772168E-6, -1.7811110865073587E-6, -1.763388854270076E-6,
      -1.7458429587557944E-6, -1.7284716455345794E-6, -1.7112731774959755E-6,
      -1.6942458348490064E-6, -1.6773879149556414E-6, -1.660697731997729E-6,
      -1.6441736170880183E-6, -1.6278139177705597E-6, -1.6116169981872375E-6,
      -1.5955812386891921E-6, -1.5797050356702869E-6, -1.56398680167813E-6,
      -1.548424964803452E-6, -1.533017969068684E-6, -1.5177642736508012E-6,
      -1.5026623532699013E-6, -1.4877106978561372E-6, -1.4729078122721617E-6,
      -1.4582522160910827E-6, -1.443742443985041E-6, -1.4293770449480547E-6,
      -1.4151545824070411E-6, -1.4010736342773278E-6, -1.3871327924075416E-6,
      -1.3733306628016528E-6, -1.3596658651748861E-6, -1.3461370332312761E-6,
      -1.3327428139975339E-6, -1.3194818681561138E-6, -1.306352869601124E-6,
      -1.2933545054383266E-6, -1.2804854759296269E-6, -1.2677444941600058E-6,
      -1.255130285982009E-6, -1.2426415901822807E-6, -1.2302771577599181E-6,
      -1.2180357523705609E-6, -1.2059161498267912E-6, -1.1939171382646663E-6,
      -1.1820375178106524E-6, -1.1702761004150908E-6, -1.1586317101297539E-6,
      -1.1471031824417111E-6, -1.1356893644398625E-6, -1.1243891149259611E-6,
      -1.1132013037484789E-6, -1.1021248122466965E-6, -1.091158532751102E-6,
      -1.0803013686944141E-6, -1.0695522342785146E-6, -1.0589100546964936E-6,
      -1.0483737656885594E-6, -1.0379423137640842E-6, -1.0276146555909804E-6,
      -1.0173897586063241E-6, -1.0072666002391983E-6, -9.972441682437605E-7,
      -9.8732146025515277E-7, -9.7749748423359151E-7, -9.677712576317E-7,
      -9.5814180794961956E-7, -9.4860817212438775E-7, -9.3916939686300438E-7,
      -9.2982453842038737E-7, -9.2057266209977229E-7, -9.1141284291884617E-7,
      -9.0234416477708024E-7, -8.9336572089981914E-7, -8.8447661344970285E-7,
      -8.7567595347115557E-7, -8.6696286094589681E-7, -8.5833646457089685E-7,
      -8.4979590175837671E-7, -8.413403183582524E-7, -8.3296886888017951E-7,
      -8.2468071621599748E-7, -8.1647503158421841E-7, -8.0835099430798252E-7,
      -8.0030779203710267E-7, -7.9234462052601984E-7, -7.844606833562473E-7,
      -7.7665519226943758E-7, -7.689273666122709E-7, -7.6127643372503329E-7,
      -7.53701628386505E-7, -7.4620219320253867E-7, -7.3877737827299228E-7,
      -7.3142644102519583E-7, -7.2414864643599586E-7, -7.1694326669868857E-7,
      -7.0980958133404215E-7, -7.02746876912741E-7, -6.95754447221919E-7,
      -6.8883159298760432E-7, -6.8197762187471866E-7, -6.7519184865361126E-7,
      -6.68473594589436E-7, -6.6182218805277415E-7, -6.55236963686967E-7,
      -6.4871726307424993E-7, -6.4226243429166274E-7, -6.3587183174451667E-7,
      -6.29544816499461E-7, -6.23280755784883E-7, -6.1707902321295194E-7,
      -6.1093899866859758E-7, -6.04860068087465E-7, -5.9884162362244808E-7,
      -5.9288306336613417E-7, -5.86983791517337E-7, -5.8114321810354141E-7,
      -5.7536075914743634E-7, -5.6963583644487059E-7, -5.6396787734280807E-7,
      -5.5835631512790584E-7, -5.5280058869344728E-7, -5.4730014237280855E-7,
      -5.4185442621701441E-7, -5.3646289560616012E-7, -5.3112501141594493E-7,
      -5.2584023985113859E-7, -5.2060805244558139E-7, -5.1542792595116182E-7,
      -5.1029934239332775E-7, -5.0522178884904179E-7, -5.0019475761331478E-7,
      -4.9521774608818347E-7, -4.9029025633862133E-7, -4.8541179581418348E-7,
      -4.8058187662736174E-7, -4.758000157201181E-7, -4.71065734974907E-7,
      -4.663785609371196E-7, -4.6173802481508375E-7, -4.5714366275761975E-7,
      -4.5259501518790657E-7, -4.4809162719205986E-7, -4.43633048519132E-7,
      -4.3921883335906742E-7, -4.348485402316804E-7, -4.3052173204216615E-7,
      -4.2623797619212311E-7, -4.2199684430199724E-7, -4.17797912211082E-7,
      -4.1364076008854056E-7, -4.0952497221136142E-7, -4.05450136908847E-7,
      -4.0141584684016962E-7, -3.9742169849477094E-7, -3.934672924144067E-7,
      -3.8955223324865784E-7, -3.8567612947737473E-7, -3.8183859341067716E-7,
      -3.7803924146651013E-7, -3.7427769350451E-7, -3.7055357349213836E-7,
      -3.6686650900508155E-7, -3.63216131282762E-7, -3.5960207539487143E-7,
      -3.560239797417708E-7, -3.52481486776135E-7, -3.4897424205926342E-7,
      -3.4550189487170258E-7, -3.4206409804671267E-7, -3.3866050785924529E-7,
      -3.3529078374838761E-7, -3.3195458892798513E-7, -3.2865158977601894E-7,
      -3.2538145583460576E-7, -3.2214386025408714E-7, -3.1893847918240681E-7,
      -3.1576499209817754E-7, -3.1262308169965891E-7, -3.0951243368271264E-7,
      -3.0643273712938068E-7, -3.0338368400828486E-7, -3.003649693411603E-7,
      -2.9737629136938892E-7, -2.9441735110991019E-7, -2.9148785279931033E-7,
      -2.88587503394222E-7, -2.8571601284888004E-7, -2.8287309417063256E-7,
      -2.8005846280931834E-7, -2.7727183748993411E-7, -2.7451293949098954E-7,
      -2.71781492922063E-7, -2.6907722472380158E-7, -2.6639986427934303E-7,
      -2.6374914402493843E-7, -2.6112479878381833E-7, -2.5852656615477088E-7,
      -2.5595418634560829E-7, -2.5340740211765578E-7, -2.5088595878575148E-7,
      -2.4838960416273537E-7, -2.4591808861496034E-7, -2.4347116500678112E-7,
      -2.4104858864504308E-7, -2.3865011727908225E-7, -2.3627551110072531E-7,
      -2.3392453257775614E-7, -2.3159694667596042E-7, -2.292925205815699E-7,
      -2.2701102386779581E-7, -2.2475222832829544E-7, -2.2251590819921674E-7,
      -2.2030183977062023E-7, -2.1810980166403482E-7, -2.1593957466592428E-7,
      -2.1379094172768731E-7, -2.1166368802116864E-7, -2.0955760082763675E-7,
      -2.0747246953778387E-7, -2.0540808559621482E-7, -2.0336424255695817E-7,
      -2.0134073608346625E-7, -1.9933736378208167E-7, -1.9735392542408192E-7,
      -1.9539022250159022E-7, -1.934460587271758E-7, -1.9152123970078705E-7,
      -1.8961557290975151E-7, -1.87728867784287E-7, -1.8586093564199047E-7,
      -1.8401158968783804E-7, -1.8218064512520726E-7, -1.8036791865627677E-7,
      -1.7857322903713779E-7, -1.7679639696677185E-7, -1.750372445874504E-7,
      -1.7329559603984634E-7, -1.7157127718547827E-7, -1.6986411560671044E-7,
      -1.6817394044021938E-7, -1.6650058287659419E-7, -1.6484387543869161E-7,
      -1.6320365248123636E-7, -1.615797500242877E-7, -1.59972005586706E-7,
      -1.5838025851921955E-7, -1.5680434956033551E-7, -1.5524412111389552E-7,
      -1.5369941724907576E-7, -1.5217008336732007E-7, -1.5065596659091796E-7,
      -1.4915691554096E-7, -1.4767278028182673E-7, -1.4620341232118861E-7,
      -1.4474866494307292E-7, -1.4330839237519655E-7, -1.4188245084367779E-7,
      -1.4047069762934683E-7, -1.3907299156734609E-7, -1.3768919293610793E-7,
      -1.3631916329082117E-7, -1.3496276562996457E-7, -1.3361986433979567E-7,
      -1.3229032513883965E-7, -1.3097401507788931E-7, -1.2967080254000507E-7,
      -1.283805571294927E-7, -1.2710314983843674E-7, -1.2583845299118934E-7,
      -1.2458634007783687E-7, -1.2334668586522213E-7, -1.2211936634143328E-7,
      -1.209042589378484E-7, -1.1970124202953514E-7, -1.1851019526831763E-7,
      -1.1733099969379879E-7, -1.1616353723375994E-7, -1.150076912037612E-7,
      -1.1386334608509685E-7, -1.1273038735826191E-7, -1.1160870172499671E-7,
      -1.1049817705277576E-7, -1.0939870226378545E-7, -1.0831016744594635E-7,
      -1.0723246368637973E-7, -1.0616548329345221E-7, -1.0510911957473112E-7,
      -1.0406326672596222E-7, -1.0302782033067004E-7, -1.0200267680504638E-7,
      -1.0098773356448376E-7, -9.9982889190108892E-8, -9.8988043206738041E-8,
      -9.800309608287705E-8, -9.7027949341743636E-8, -9.6062505505756235E-8,
      -9.5106667930000555E-8, -9.4160341135296477E-8, -9.322343041962E-8,
      -9.229584208014785E-8, -9.1377483468768617E-8, -9.0468262603504712E-8,
      -8.9568088668112722E-8, -8.86768715679942E-8, -8.7794522318773716E-8,
      -8.6920952491187364E-8, -8.6056074821705408E-8, -8.5199802879465381E-8,
      -8.4352050899738629E-8, -8.3512734283530676E-8, -8.2681768931447408E-8,
      -8.1859071854317733E-8, -8.1044560729104376E-8, -8.0238154120948479E-8,
      -7.94397713721473E-8, -7.8649332713176534E-8, -7.786675898513451E-8,
      -7.70919720283203E-8, -7.6324894349166783E-8, -7.5565449120240658E-8,
      -7.4813560568820492E-8, -7.4069153421785217E-8, -7.333215323868103E-8,
      -7.26024863006991E-8, -7.18800796661867E-8, -7.1164861170647242E-8,
      -7.0456759149184478E-8, -6.9755702880591741E-8, -6.9061622198773875E-8,
      -6.8374447770302993E-8, -6.7694110816862718E-8, -6.7020543337292793E-8,
      -6.6353677941055622E-8, -6.5693447959258577E-8, -6.5039787389142845E-8,
      -6.4392630838572273E-8, -6.3751913692566831E-8, -6.311757166921339E-8,
      -6.2489541485799549E-8, -6.1867760303702113E-8, -6.12521659504317E-8,
      -6.06426968641216E-8, -6.0039292093527763E-8, -5.9441891298028793E-8,
      -5.8850434692114817E-8, -5.8264863211920925E-8, -5.7685118293182569E-8,
      -5.711114187123556E-8, -5.6542876658571828E-8, -5.598026575626136E-8,
      -5.542325293150796E-8, -5.4871782451115791E-8, -5.4325799192511681E-8,
      -5.3785248588233969E-8, -5.3250076514910205E-8, -5.2720229515301753E-8,
      -5.2195654576259187E-8, -5.1676299239744594E-8, -5.1162111602831573E-8,
      -5.065304015117178E-8, -5.0149034036550688E-8, -4.9650042965865282E-8,
      -4.9156016868057151E-8, -4.866690639371285E-8, -4.8182662693019296E-8,
      -4.7703237249230313E-8, -4.722858226724469E-8, -4.675865006298352E-8,
      -4.6293393785035164E-8, -4.5832766859543739E-8, -4.5376723323276025E-8,
      -4.4925217435043407E-8, -4.4478204175302238E-8, -4.4035638746553474E-8,
      -4.3597476850898431E-8, -4.3163674801061092E-8, -4.2734189131810041E-8,
      -4.2308976877514226E-8, -4.1887995627654107E-8, -4.1471203138243595E-8,
      -4.1058557886941571E-8, -4.0650018406918065E-8, -4.0245544064010375E-8,
      -3.984509427956695E-8, -3.9448629030047755E-8, -3.9056108624979657E-8,
      -3.866749392900104E-8, -3.828274602879489E-8, -3.7901826399622252E-8,
      -3.7524696960833381E-8, -3.7151320075867744E-8, -3.6781658274698259E-8,
      -3.6415674697920508E-8, -3.605333276368583E-8, -3.569459616770132E-8,
      -3.5339429049763282E-8, -3.4987795882734929E-8, -3.463966152805753E-8,
      -3.4294991180239265E-8, -3.3953750366855218E-8, -3.3615904948547382E-8,
      -3.3281421174535808E-8, -3.2950265516085153E-8, -3.2622404888549283E-8,
      -3.2297806595860123E-8, -3.1976438108483052E-8, -3.1658267285461505E-8,
      -3.1343262318905829E-8, -3.1031391678482123E-8, -3.0722624222434547E-8,
      -3.0416929031051865E-8, -3.0114275517689748E-8, -2.9814633539793078E-8,
      -2.9517973010317888E-8, -2.9224264341820572E-8, -2.8933478057879825E-8,
      -2.8645585126163553E-8, -2.8360556847406571E-8, -2.8078364633365993E-8,
      -2.7798980284376995E-8, -2.7522375822819356E-8, -2.7248523604139763E-8,
      -2.6977396316851809E-8, -2.6708966760491393E-8, -2.6443208123172468E-8,
      -2.6180093815053596E-8, -2.5919597579360243E-8, -2.5661693325851331E-8,
      -2.5406355241841538E-8, -2.5153557792201298E-8, -2.49032757193568E-8,
      -2.4655483987778837E-8, -2.4410157839493962E-8, -2.4167272794084482E-8,
      -2.3926804371132704E-8, -2.3688728756354749E-8, -2.3453021968933285E-8,
      -2.3219660527651342E-8, -2.2988621062314252E-8, -2.27598804802831E-8,
      -2.2533415910963583E-8, -2.2309204705805996E-8, -2.2087224438305242E-8,
      -2.1867452904000828E-8, -2.1649868064965716E-8, -2.1434448327362077E-8,
      -2.122117204184093E-8, -2.1010017892120203E-8, -2.0800964672940125E-8,
      -2.0593991678641288E-8, -2.0389078037030828E-8, -2.0186203320005092E-8,
      -1.998534726599388E-8, -1.9786489724449297E-8, -1.9589610877890351E-8,
      -1.9394691075369508E-8, -1.9201710665939231E-8, -1.9010650498252346E-8,
      -1.8821491365450527E-8, -1.8634214338231203E-8, -1.8448800820358713E-8,
      -1.8265232271108545E-8, -1.8083490149756187E-8, -1.7903556415177491E-8,
      -1.7725413137270607E-8, -1.7549042274911386E-8, -1.7374426397598342E-8,
      -1.7201547963807684E-8, -1.7030389709571381E-8, -1.6860934537454852E-8,
      -1.6693165461045822E-8, -1.6527065715976619E-8, -1.6362618648901872E-8,
      -1.6199807884031969E-8, -1.60386171565996E-8, -1.5879030201837452E-8,
      -1.5721031254578577E-8, -1.5564604383122571E-8, -1.5409733988835939E-8,
      -1.5256404584107486E-8, -1.5104600792348322E-8, -1.4954307570036462E-8,
      -1.480550965160532E-8, -1.465819243762212E-8, -1.4512340995587181E-8,
      -1.4367940781578881E-8, -1.422497741820905E-8, -1.4083436528089521E-8,
      -1.394330401138788E-8, -1.3804565768271715E-8, -1.3667208087486671E-8,
      -1.353121709124494E-8, -1.3396579290336774E-8, -1.3263281084530121E-8,
      -1.3131309206659836E-8, -1.3000650500583077E-8, -1.2871291921179306E-8,
      -1.2743220423327983E-8, -1.2616423183953174E-8, -1.2490887713045851E-8,
      -1.2366601354063533E-8, -1.2243551616997195E-8, -1.2121726233882413E-8,
      -1.2001113047777068E-8, -1.1881700012761343E-8, -1.1763475138426571E-8,
      -1.164642654538639E-8, -1.1530542687321343E-8, -1.1415811906889672E-8,
      -1.1302222657771921E-8, -1.1189763671204389E-8, -1.1078423678423377E-8,
      -1.0968191466176336E-8, -1.0859056209788776E-8, -1.075100680703045E-8,
      -1.064403248873802E-8, -1.0538122596770449E-8, -1.0433266528497853E-8,
      -1.0329453792312648E-8, -1.0226674007629555E-8, -1.0124916904885595E-8,
      -1.0024172325540093E-8, -9.9244301665635248E-9, -9.8256803804375181E-9,
      -9.7279132527106071E-9, -9.6311189023978727E-9, -9.535287670559E-9,
      -9.4404100092759791E-9, -9.3464763151196451E-9, -9.253477317727743E-9,
      -9.1614037467380172E-9, -9.07024622076591E-9, -8.97999574700492E-9,
      -8.8906433326485512E-9, -8.80217992937915E-9, -8.7145967664348234E-9,
      -8.6278851285648273E-9, -8.5420362450072673E-9, -8.457041567044854E-9,
      -8.3728925459602976E-9, -8.2895809105920648E-9, -8.2070981677340171E-9,
      -8.1254361572469236E-9, -8.0445867745027044E-9, -7.9645418038509774E-9,
      -7.8852933071971165E-9, -7.8068332909353444E-9, -7.72915403901564E-9,
      -7.652247613343377E-9, -7.57610651991314E-9, -7.5007230426749061E-9,
      -7.4260895766009583E-9, -7.3521987387081822E-9, -7.2790431460134641E-9,
      -7.20661541553369E-9, -7.1349084418415032E-9, -7.0639149529760914E-9,
      -6.9936277879989461E-9, -6.9240400080161635E-9, -6.8551446741338395E-9,
      -6.78693484745807E-9, -6.7194037001172546E-9, -6.6525445152620932E-9,
      -6.5863506315544385E-9, -6.5208153876561425E-9, -6.455932177740209E-9,
      -6.3916945070019437E-9, -6.3280961581924089E-9, -6.2651305254846079E-9,
      -6.2027914471407541E-9, -6.1410725948896072E-9, -6.0799679180156829E-9,
      -6.0194712547811946E-9, -5.9595764989595068E-9, -5.9002777108574378E-9,
      -5.8415690062929571E-9, -5.7834443900617316E-9, -5.7258981445151846E-9,
      -5.6689245520047393E-9, -5.6125177838595164E-9, -5.5566722889643927E-9,
      -5.5013825162042451E-9, -5.4466428034416481E-9, -5.3924478216060834E-9,
      -5.3387920750935791E-9, -5.2856701793224659E-9, -5.2330768607333766E-9,
      -5.1810069567892469E-9, -5.1294550273972561E-9, -5.0784160765537933E-9,
      -5.0278849972329454E-9, -4.97785673791995E-9, -4.9283262471000455E-9,
      -4.8792885842807721E-9, -4.8307388644808213E-9, -4.782672202718885E-9,
      -4.7350838250359573E-9, -4.6879689574730321E-9, -4.6413228815822549E-9,
      -4.5951409899380735E-9, -4.5494185640926332E-9, -4.5041510521315331E-9,
      -4.4593340131626746E-9, -4.4149628952716569E-9, -4.3710332575663813E-9,
      -4.3275407701770519E-9, -4.2844810477227213E-9, -4.2418497048224424E-9,
      -4.199642633651024E-9, -4.1578554488275188E-9, -4.116484098037887E-9,
      -4.0755244179457861E-9, -4.034972245214874E-9, -3.994823638553413E-9,
      -3.9550744901362123E-9, -3.915720803160383E-9, -3.87675874735649E-9,
      -3.8381843259216453E-9, -3.7999937640975645E-9, -3.7621832316148129E-9,
      -3.7247488426928044E-9, -3.6876869891067088E-9, -3.6509938960982424E-9,
      -3.6146658999314241E-9, -3.5786993368702724E-9, -3.54309070971226E-9,
      -3.5078363547214053E-9, -3.4729328302063323E-9, -3.4383765834533619E-9,
      -3.4041641172599668E-9, -3.3702921564682242E-9, -3.3367571483644554E-9,
      -3.30355592881304E-9, -3.2706849451002995E-9, -3.2381410886017647E-9,
      -3.2059210841595132E-9, -3.1740216011044708E-9, -3.1424395308121689E-9,
      -3.1111717646581383E-9, -3.0802150829956076E-9, -3.0495664327112593E-9,
      -3.0192227606917754E-9, -2.9891810138238384E-9, -2.9594381945052817E-9,
      -2.9299912496227876E-9, -2.9008373481076433E-9, -2.8719735478688335E-9,
      -2.8433969068153431E-9, -2.8151046493896104E-9, -2.7870938890117714E-9,
      -2.7593618501242645E-9, -2.731905701658377E-9, -2.704722834590001E-9,
      -2.6778103623392724E-9, -2.6511656758820834E-9, -2.6247861661943261E-9,
      -2.5986691132295903E-9, -2.5728119079637679E-9, -2.5472119968839024E-9,
      -2.5218668264770372E-9, -2.4967738432302156E-9, -2.4719304936304809E-9,
      -2.4473344462094815E-9, -2.4229830364319582E-9, -2.3988739328295594E-9,
      -2.3750047484227821E-9, -2.3513730962321233E-9, -2.3279764782557777E-9,
      -2.3048127295588472E-9, -2.2818794631618289E-9, -2.2591744031075223E-9,
      -2.2366952179275756E-9, -2.214439742687091E-9, -2.192405756940019E-9,
      -2.1705909292180081E-9, -2.1489931500973114E-9, -2.1276103101541821E-9,
      -2.1064402999648735E-9, -2.0854807880610338E-9, -2.0647299425746724E-9,
      -2.04418554305974E-9, -2.0238455356036411E-9, -2.0037079773160826E-9,
      -1.9837707032621665E-9, -1.964031826062751E-9, -1.9444894028275428E-9,
      -1.9251414351550977E-9, -1.9059859246439714E-9, -1.8870210949373245E-9,
      -1.8682448921225614E-9, -1.8496555953539939E-9, -1.8312511507190266E-9,
      -1.8130298928831223E-9, -1.7949899899782906E-9, -1.7771294991142383E-9,
      -1.7594468104675798E-9, -1.7419399811480218E-9, -1.72460745684333E-9,
      -1.7074472946632113E-9, -1.69045788478428E-9, -1.673637561871999E-9,
      -1.656984549569529E-9, -1.6404973490757868E-9, -1.6241741285227818E-9,
      -1.6080132780871281E-9, -1.5920132989677427E-9, -1.5761725258300885E-9,
      -1.5604892933396286E-9, -1.5449622137175822E-9, -1.5295895661182612E-9,
      -1.5143699072517336E-9, -1.4993016272946136E-9, -1.4843833384681204E-9,
      -1.4696134864600197E-9, -1.4549906279803793E-9, -1.4405132087169648E-9,
      -1.4261798408909954E-9, -1.4119891367236903E-9, -1.3979395974139663E-9,
      -1.3840298906941939E-9, -1.3702585177632898E-9, -1.3566242573759268E-9,
      -1.3431256107310219E-9, -1.3297613010720966E-9, -1.31652994062037E-9,
      -1.303430197108213E-9, -1.2904609048014493E-9, -1.277620620410147E-9,
      -1.2649080671778279E-9, -1.2523220238591648E-9, -1.2398612136976794E-9,
      -1.2275243599368935E-9, -1.215310296842631E-9, -1.2032177476584138E-9,
      -1.191245546650066E-9, -1.1793924725722604E-9, -1.16765730417967E-9,
      -1.1560389312492703E-9, -1.1445361325357339E-9, -1.1331477978160365E-9,
      -1.121872761356002E-9, -1.1107100239549084E-9, -1.099658253345126E-9,
      -1.0887164503259328E-9, -1.0778835601854553E-9, -1.0671584727006689E-9,
      -1.0565400221373977E-9, -1.0460272648060709E-9, -1.035619145994815E-9,
      -1.0253145554806053E-9, -1.0151124940627199E-9, -1.0050119625404363E-9,
      -9.950119062018814E-10, -9.8511138135748411E-10, -9.75309333295371E-10,
      -9.6560487383712257E-10, -9.5599694827086523E-10, -9.4648461290702812E-10,
      -9.3706692405604031E-10, -9.2774299353948209E-10, -9.1851176664548007E-10,
      -9.0937241070676578E-10, -9.0032403754491952E-10, -8.9136564795921913E-10,
      -8.8249640928239614E-10, -8.7371543333603086E-10, -8.6502177643055234E-10,
      -8.5641471692099458E-10, -8.4789320009548419E-10, -8.3945655982020639E-10,
      -8.31103796894439E-10, -8.2283424518436732E-10, -8.1464684997811787E-10,
      -8.0654100065302714E-10, -7.9851580903067543E-10, -7.9057044244379426E-10,
      -7.8270412373626641E-10, -7.7491607575197463E-10, -7.6720552133480169E-10,
      -7.5957173883978157E-10, -7.5201384008849459E-10, -7.44531158947126E-10,
      -7.3712297377070968E-10, -7.2978845189197727E-10, -7.22526927177114E-10,
      -7.1533767798115377E-10, -7.0821998265913066E-10, -7.0117306405492741E-10,
      -6.9419625603472923E-10, -6.8728889246472136E-10, -6.8045025169993778E-10,
      -6.7367966760656373E-10, -6.6697641853963319E-10, -6.6033989387648262E-10,
      -6.5376942748329725E-10, -6.4726429771511107E-10, -6.4082389394926054E-10,
      -6.3444766107423334E-10, -6.28134766422761E-10, -6.2188471039448245E-10,
      -6.1569688236673414E-10, -6.0957056069455007E-10, -6.0350524577756914E-10,
      -5.9750021597082537E-10, -5.9155502718510888E-10, -5.8566895777545369E-10,
      -5.7984145263034748E-10, -5.7407190112712669E-10, -5.6835980366543026E-10,
      -5.6270454962259464E-10, -5.5710552837595628E-10, -5.5156224032515411E-10,
      -5.4607407484752457E-10, -5.4064058785385782E-10, -5.3526111321033909E-10,
      -5.2993520682775852E-10, -5.2466225808345257E-10, -5.1944176737706016E-10,
      -5.1427323510822021E-10, -5.0915616167657163E-10, -5.0408993645945088E-10,
      -4.9907417087879935E-10, -4.9410825431195349E-10, -4.8919179818085468E-10,
      -4.8432430288514183E-10, -4.7950515780215142E-10, -4.74734029864976E-10,
      -4.7001036396210338E-10, -4.6533366049317237E-10, -4.6070353088012439E-10,
      -4.5611942001144712E-10, -4.5158099482023317E-10, -4.4708770019497024E-10,
      -4.4263909204644847E-10, -4.38234726285458E-10, -4.3387426984509148E-10,
      -4.2955711210268532E-10, -4.2528291999133216E-10, -4.2105130493297338E-10,
      -4.1686182283839912E-10, -4.127139741072483E-10, -4.0860737016146231E-10,
      -4.0454162242298253E-10, -4.0051639782490156E-10, -3.9653119676685833E-10,
      -3.9258563067079422E-10, -3.8867936646980183E-10, -3.8481196007467133E-10,
      -3.8098296739619286E-10, -3.771921663897615E-10, -3.7343900194386492E-10,
      -3.6972325201389822E-10, -3.660444169995003E-10, -3.62402219344915E-10,
      -3.5879627047208373E-10, -3.5522618180294785E-10, -3.5169162027059997E-10,
      -3.4819219729698148E-10, -3.4472769083748744E-10, -3.4129754578060556E-10,
      -3.3790159559288213E-10, -3.3453939618510731E-10, -3.3121067000152493E-10,
      -3.2791508397522762E-10, -3.24652305039308E-10, -3.2142194461570739E-10,
      -3.1822378065982093E-10, -3.1505736908243875E-10, -3.1192248783895593E-10,
      -3.0881880386246507E-10, -3.057459840860588E-10, -3.0270380646513217E-10,
      -2.9969182691047536E-10, -2.9670987888863465E-10, -2.9375757382155143E-10,
      -2.9083463415346955E-10, -2.8794072681748162E-10, -2.8507568528013394E-10,
      -2.8223917647451913E-10, -2.7943081182257856E-10, -2.7665048030200978E-10,
      -2.7389768231245171E-10, -2.711723623427531E-10, -2.6847418732600659E-10,
      -2.6580282419530477E-10, -2.6315805090604272E-10, -2.6053958990246429E-10,
      -2.5794716362881331E-10, -2.5538055004048488E-10, -2.5283941607057159E-10,
      -2.50323650696771E-10, -2.4783292085217568E-10, -2.4536694898102951E-10,
      -2.4292551303872756E-10, -2.4050833546951367E-10, -2.3811524973993414E-10,
      -2.3574597829423283E-10, -2.3340024357665357E-10, -2.3107782354259143E-10,
      -2.2877860716974396E-10, -2.2650220588005254E-10, -2.2424845314006348E-10,
      -2.2201712690517184E-10, -2.1980806064192393E-10, -2.176209767945636E-10,
      -2.1545554229618347E-10, -2.1331170163563229E-10, -2.1118923276830515E-10,
      -2.0908785813844588E-10, -2.0700746672375203E-10, -2.0494766994616498E-10,
      -2.0290841229453349E-10, -2.0088947172425264E-10, -1.9889057067956628E-10,
      -1.9691154262702071E-10, -1.9495222103316223E-10, -1.9301249487568839E-10,
      -1.9109192006538933E-10, -1.8919055211341629E-10, -1.8730805795286187E-10,
      -1.8544438207257485E-10, -1.8359913589449661E-10, -1.8177231941862715E-10,
      -1.7996365508921031E-10, -1.7817297637279239E-10, -1.7640006122476848E-10,
      -1.7464490964513857E-10, -1.7290713305584404E-10, -1.7118667594573367E-10,
      -1.6948337178135375E-10, -1.6779694300694814E-10, -1.6612738962251683E-10,
      -1.6447437856115243E-10, -1.6283785431170372E-10, -1.6121753931841454E-10,
      -1.5961343358128488E-10, -1.5802520403340736E-10, -1.5645285067478198E-10,
      -1.5489609594965259E-10, -1.5335488434686795E-10, -1.5182899382182313E-10,
      -1.5031825784106445E-10, -1.4882256538228944E-10, -1.4734180542319564E-10,
      -1.4587570040802689E-10, -1.4442419482563196E-10, -1.4298712214255715E-10,
      -1.4156437133650002E-10, -1.4015577587400685E-10, -1.3876122473277519E-10,
      -1.3738055137935135E-10, -1.3601358928028162E-10, -1.3466022741326356E-10,
      -1.3332035475599469E-10, -1.3199374926387009E-10, -1.3068041093688976E-10,
      -1.2938011773044877E-10, -1.2809275862224467E-10, -1.26818222589975E-10,
      -1.2555634310018604E-10, -1.2430706464172658E-10, -1.230701651699917E-10,
      -1.2184564468498138E-10, -1.2063322563093948E-10, -1.19432908007866E-10,
      -1.1824452528230722E-10, -1.1706796643196071E-10, -1.15903120434524E-10,
      -1.1474987626769462E-10, -1.1360806739801887E-10, -1.1247763831434554E-10,
      -1.1135853350552338E-10, -1.1025047541579625E-10, -1.0915346404516413E-10,
      -1.0806738837132457E-10, -1.0699208186082387E-10, -1.0592748900251081E-10,
      -1.0487349877408292E-10, -1.0383000015323773E-10, -1.0279682660652156E-10,
      -1.0177397813393441E-10, -1.007613437131738E-10, -9.9758756810786053E-11,
      -9.87661064044687E-11, -9.7783392494221744E-11, -9.6810393035440256E-11,
      -9.5847163539275471E-11, -9.4893481961122461E-11, -9.3949237278678766E-11,
      -9.3014429491944384E-11, -9.2088947578616853E-11, -9.117262500524248E-11,
      -9.0265406260670034E-11, -8.9367291344899513E-11, -8.8478113724477225E-11,
      -8.7597706865949476E-11, -8.67261262804675E-11, -8.5863149923426363E-11,
      -8.5008777794826074E-11, -8.4162898872364167E-11, -8.3325513156040643E-11,
      -8.2496454112401807E-11, -8.1675555207993966E-11, -8.0862871953968352E-11,
      -8.00582933280225E-11, -7.926165279670272E-11, -7.847300587116024E-11,
      -7.7692186017941367E-11, -7.6919137725894871E-11, -7.6153805483869519E-11,
      -7.539607826956285E-11, -7.46458450606724E-11, -7.3903050346046939E-11,
      -7.31677496368377E-11, -7.2439720888439751E-11, -7.1718908589701869E-11,
      -7.100536825177528E-11, -7.0298822318903831E-11, -6.9599326302238751E-11,
      -6.890682469062881E-11, -6.8221150950620313E-11, -6.7542360593364492E-11,
      -6.6870287085407654E-11, -6.6204874915598566E-11, -6.5546179595088461E-11,
      -6.4893979079272412E-11, -6.4248273368150421E-11, -6.3608951439420025E-11,
      -6.2976068804232455E-11, -6.2349403417982785E-11, -6.1729010791822247E-11,
      -6.1114890925750842E-11, -6.0506766264012413E-11, -5.990469231775819E-11,
      -5.9308613575836944E-11, -5.8718474527097442E-11, -5.8134275171539684E-11,
      -5.7555793464558747E-11, -5.698308491730586E-11, -5.6416094018629792E-11,
      -5.5854765257379313E-11, -5.529898761125196E-11, -5.4748761080247732E-11,
      -5.42040301532154E-11, -5.36646838078525E-11, -5.31306665330078E-11,
      -5.2602033839832529E-11, -5.2078619194873E-11, -5.1560478109280439E-11,
      -5.1047388538449923E-11, -5.0539461504683914E-11, -5.0036585985679949E-11,
      -4.9538761981438029E-11, -4.9045767447353228E-11, -4.855776891687924E-11,
      -4.8074655367713603E-11, -4.7596315777553855E-11, -4.7122694635248763E-11,
      -4.6653847451949559E-11, -4.618960769420255E-11, -4.5729975362007735E-11,
      -4.5275005966516346E-11, -4.4824477463123458E-11, -4.4378500874131532E-11,
      -4.3936909666086876E-11, -4.349970383898949E-11, -4.3066938903990604E-11,
      -4.2638392816485293E-11, -4.221412108762479E-11, -4.1794068206257862E-11,
      -4.1378234172384509E-11, -4.096650796370227E-11, -4.0558889580211144E-11,
      -4.01553235107599E-11, -3.9755809755348537E-11, -3.9360181780523362E-11,
      -3.8968550608586838E-11, -3.85808052172365E-11, -3.8196945606472354E-11,
      -3.7816860753991932E-11, -3.7440550659795235E-11, -3.7068015323882264E-11,
      -3.6699199235101787E-11, -3.6334046882302573E-11, -3.5972502754333391E-11,
      -3.561456685119424E-11, -3.526018366173389E-11, -3.4909353185952341E-11,
      -3.4561964401547129E-11, -3.4218128330820718E-11, -3.3877622929168183E-11,
      -3.3540503707740754E-11, -3.3206770666538432E-11, -3.2876368294409986E-11,
      -3.2549296591355414E-11, -3.2225389023921025E-11, -3.1904701103258049E-11,
      -3.1587288340517716E-11, -3.1272984202246334E-11, -3.0961844199595134E-11,
      -3.0653757310261653E-11, -3.0348723534245892E-11, -3.0046742871547849E-11,
      -2.9747759811016294E-11, -2.9451774352651228E-11, -2.9158730985301418E-11,
      -2.8868629708966864E-11, -2.8581359501345105E-11, -2.8296975873587371E-11,
      -2.8015423314542431E-11, -2.7736646313059055E-11, -2.7460644869137241E-11,
      -2.7187474493928221E-11, -2.691691314282707E-11, -2.6649071838136251E-11,
      -2.6383950579855764E-11, -2.6121382834531914E-11, -2.5861479624467165E-11,
      -2.5604129927359054E-11, -2.5349389254358812E-11, -2.5097202094315207E-11,
      -2.4847457424925778E-11, -2.4600210757341756E-11, -2.4355406580411909E-11,
      -2.4113044894136237E-11, -2.3873181209665972E-11, -2.3635593482396189E-11,
      -2.3400392734629349E-11, -2.3167634477516685E-11, -2.2937096666453272E-11,
      -2.2708834812590339E-11, -2.2482848915927889E-11, -2.225913897646592E-11,
      -2.2037704994204432E-11, -2.1818435946840964E-11, -2.1601331834375515E-11,
      -2.1386392656808084E-11, -2.1173562902987442E-11, -2.0962898084064818E-11,
      -2.0754342688888983E-11, -2.0547841206308703E-11, -2.034333812517275E-11,
      -2.0140944467783584E-11, -1.9940549211838743E-11, -1.9742096846186996E-11,
      -1.9545698393130806E-11, -1.9351187319216478E-11, -1.9158619135595245E-11,
      -1.8967993842267106E-11, -1.877931143923206E-11, -1.8592460904187647E-11,
      -1.8407442237133864E-11, -1.8224310949221945E-11, -1.8042956018149425E-11,
      -1.7863432955067537E-11, -1.768568624882505E-11, -1.7509660388270731E-11,
      -1.7335466395707044E-11, -1.7162937737680295E-11, -1.6992185436492946E-11,
      -1.6823098469842535E-11, -1.6655732348880292E-11, -1.6490031562454988E-11,
      -1.6325940599415389E-11, -1.6163459459761498E-11, -1.6002643654644544E-11,
      -1.5843437672913296E-11, -1.5685730492265293E-11, -1.5529744157305458E-11,
      -1.5375201112277637E-11, -1.522221237948429E-11, -1.5070722447774187E-11,
      -1.492078682829856E-11, -1.4772294498754945E-11, -1.4625356481445806E-11,
      -1.4479806242917448E-11, -1.4335699294321103E-11, -1.4193091146808001E-11,
      -1.4051870778075681E-11, -1.3912038188124143E-11, -1.3773593376953386E-11,
      -1.363653634456341E-11, -1.3500867090954216E-11, -1.3366530104974572E-11,
      -1.3233525386624478E-11, -1.3101852935903935E-11, -1.2971512752812941E-11,
      -1.2842449326200267E-11, -1.2714662656065912E-11, -1.2588152742409875E-11,
      -1.2462864074080926E-11, -1.2338852162230296E-11, -1.2216117006857985E-11,
      -1.209454758566153E-11, -1.1974199409792163E-11, -1.1855072479249884E-11,
      -1.1737111282883461E-11, -1.1620315820692895E-11, -1.1504741603829416E-11,
      -1.1390222098839331E-11, -1.1276868328025103E-11, -1.116468029138673E-11,
      -1.1053546966621752E-11, -1.0943634887183862E-11, -1.0834722008468134E-11,
      -1.0726919352777031E-11, -1.0620171408959322E-11, -1.0514478177015008E-11,
      -1.0409895168095318E-11, -1.0306255848746559E-11, -1.0203782263573657E-11,
      -1.0102252367971687E-11, -1.0001721673091879E-11, -9.9021901789342337E-12,
      -9.8036578854987511E-12, -9.7060692816342E-12, -9.6095353896430424E-12,
      -9.5138896760715852E-12, -9.41924316322229E-12, -9.3255403399439274E-12,
      -9.2327256950852643E-12, -9.1408547397975326E-12, -9.0499274740807323E-12,
      -8.9598883867836321E-12, -8.870737477906232E-12, -8.7824747474485321E-12,
      -8.695044684259301E-12, -8.6085583106410013E-12, -8.52290460429117E-12,
      -8.4380835652098085E-12, -8.3540951933969154E-12, -8.2709950000037225E-12,
      -8.1886719627277671E-12, -8.1072371038715119E-12, -8.026523889981263E-12,
      -7.9466988545107142E-12, -7.8675954640061718E-12, -7.7893247407700983E-12,
      -7.7118311736512624E-12, -7.635114762649664E-12, -7.5591199966140721E-12,
      -7.4839023866957177E-12, -7.40940642174337E-12, -7.33574312405949E-12,
      -7.2626904490391553E-12, -7.1904704412872888E-12, -7.1189165673501975E-12,
      -7.0480843383791125E-12, -6.9779737543740339E-12, -6.90852930418373E-12,
      -6.8398064989594332E-12, -6.77169431639868E-12, -6.7043037788039328E-12,
      -6.6376348861751922E-12, -6.5715766162099953E-12, -6.5061844800595736E-12,
      -6.441458477723927E-12, -6.3773430980518242E-12, -6.3139493633457278E-12,
      -6.2511107401519439E-12, -6.1888827396217039E-12, -6.1273208729062389E-12,
      -6.0663696288543179E-12, -6.0059734963147093E-12, -5.9461879864386447E-12,
      -5.8870686103773551E-12, -5.8285043458283781E-12, -5.7704951927917136E-12,
      -5.7130411512673618E-12, -5.6561977324065538E-12, -5.5999649362092896E-12,
      -5.5441762292218755E-12, -5.4890536560492365E-12, -5.4344306832376787E-12,
      -5.3803628219384336E-12, -5.3268500721515011E-12, -5.27383692272565E-12,
      -5.2213788848121112E-12, -5.1694204472596539E-12, -5.1179060989170466E-12,
      -5.0670023732379832E-12, -5.0165982479200011E-12, -4.9666937229631E-12,
      -4.9172887983672808E-12, -4.8683834741325427E-12, -4.8199222391076546E-12,
      -4.7719606044438478E-12, -4.7244430589898911E-12, -4.6774251138970158E-12,
      -4.6309067691652217E-12, -4.5848325136432777E-12, -4.539257858482415E-12,
      -4.49401627022894E-12, -4.4493853046390086E-12, -4.4050318948052336E-12,
      -4.3612335964837712E-12, -4.3178238762209276E-12, -4.274858245167934E-12,
      -4.2323367033247905E-12, -4.1902592506914971E-12, -4.1485148649655912E-12,
      -4.1072700796007666E-12, -4.06635836114333E-12, -4.0259462430469739E-12,
      -3.9858671918580058E-12, -3.9462322298788877E-12, -3.9069303348071571E-12,
      -3.8680725289452766E-12, -3.829603301142015E-12, -3.7914671402461408E-12,
      -3.7537750685601168E-12, -3.716360552630249E-12, -3.6793901259102313E-12,
      -3.6428082772488324E-12, -3.606559495494821E-12, -3.5706437806481972E-12,
      -3.5351166438601922E-12, -3.499978085130806E-12, -3.4651170821575761E-12,
      -3.430644657242965E-12, -3.3965052992357414E-12, -3.3627545192871366E-12,
      -3.3292812950946882E-12, -3.2961411378096273E-12, -3.2633895585831851E-12,
      -3.230860023961668E-12, -3.1987190673987698E-12, -3.166911177743259E-12,
      -3.1354363549951358E-12, -3.1041835768519377E-12, -3.0733193767673583E-12,
      -3.0427327324389353E-12, -3.0124791550178998E-12, -2.9824476222017893E-12,
      -2.9528046674442976E-12, -2.9234392684429622E-12, -2.8943514251977831E-12,
      -2.8655411377087603E-12, -2.837063917127125E-12, -2.8088087411504148E-12,
      -2.7808311209298608E-12, -2.7531865676166944E-12, -2.7258195700596843E-12,
      -2.6986746171075993E-12, -2.6718072199116705E-12, -2.6452728896231292E-12,
      -2.6189050927882818E-12, -2.5928148517095906E-12, -2.5670021663870557E-12,
      -2.5415225479719084E-12, -2.5162094630104548E-12, -2.4911739338051575E-12,
      -2.4663604492047853E-12, -2.4418800315118006E-12, -2.4175106361212784E-12,
      -2.3934743076381437E-12, -2.3697155349111654E-12, -2.3461232956378808E-12,
      -2.3227531009695213E-12, -2.299660462057318E-12, -2.2767343565988085E-12,
      -2.2540858068964553E-12, -2.2316593017990272E-12, -2.209454841306524E-12,
      -2.1874724254189459E-12, -2.1657675652875241E-12, -2.1441737274585648E-12,
      -2.1228019342345306E-12, -2.1017076967666526E-12, -2.0808355039036996E-12,
      -2.0600743333432092E-12, -2.0395907185388751E-12, -2.019329148339466E-12,
      -1.9992341115937506E-12, -1.9793056083017291E-12, -1.9595991496146326E-12,
      -1.9401147355324611E-12, -1.9208523660552146E-12, -1.9017010188804306E-12,
      -1.8827717163105717E-12, -1.8640644583456378E-12, -1.8455237338343977E-12,
      -1.82709403162562E-12, -1.8089418851729988E-12, -1.7909562721740713E-12,
      -1.7731371926288375E-12, -1.7554846465372975E-12, -1.7379986338994513E-12,
      -1.7207901770177614E-12, -1.7036372312873027E-12, -1.6866508190105378E-12,
      -1.669886451338698E-12, -1.6532886171205519E-12, -1.6368573163560995E-12,
      -1.6205370378941097E-12, -1.6043832928858137E-12, -1.5884515924824427E-12,
      -1.5726309143815342E-12, -1.5569767697343195E-12, -1.5414891585407986E-12,
      -1.5261680808009714E-12, -1.5109580253636068E-12, -1.4959700145311672E-12,
      -1.4810375148499588E-12, -1.4663270597736755E-12, -1.4517276269998547E-12,
      -1.4372947276797277E-12, -1.4229728506620631E-12, -1.4088175070980924E-12,
      -1.3947731858365842E-12, -1.380950909180001E-12, -1.367184143674649E-12,
      -1.3535839116229909E-12, -1.3400947018737952E-12, -1.3267720255782933E-12,
      -1.3136158827364852E-12, -1.3005152510459084E-12, -1.2875811528090253E-12,
      -1.2747580768746047E-12, -1.2620460232426467E-12, -1.2495560142156137E-12,
      -1.2370660051885807E-12, -1.2247980407664727E-12, -1.212585587495596E-12,
      -1.200539667678413E-12, -1.1885492590124613E-12, -1.1767253838002034E-12,
      -1.165012530890408E-12, -1.1534107002830751E-12, -1.141975403129436E-12,
      -1.1305956171270282E-12, -1.1193823645783141E-12, -1.1082246231808313E-12,
      -1.097177904085811E-12, -1.0862977184444844E-12, -1.0754175328031579E-12,
      -1.0647593917667564E-12, -1.0542122730328174E-12, -1.0437206654501097E-12,
      -1.0332845690186332E-12, -1.0230150060408505E-12, -1.0128564653655303E-12,
      -1.0027534358414414E-12, -9.9281693977104624E-13, -9.82880443700651E-13,
      -9.7311048108394971E-13, -9.6345154076971085E-13, -9.5384811160670324E-13,
      -9.4435570474615815E-13, -9.3497432018807558E-13, -9.2564844678122427E-13,
      -9.1643359567683547E-13, -9.0732976687490918E-13, -8.9833696037544541E-13,
      -8.8934415387598165E-13, -8.8051788083021165E-13, -8.7174711893567292E-13,
      -8.6308737934359669E-13, -8.5448315090275173E-13, -8.4598994476436928E-13,
      -8.3760776092844935E-13, -8.2928108824376068E-13, -8.2100992671030326E-13,
      -8.1284978747930836E-13, -8.0474515939954472E-13, -7.9669604247101233E-13,
      -7.8875794784494246E-13, -7.8098638667256637E-13, -7.73159314348959E-13,
      -7.6549877547904543E-13, -7.5783823660913185E-13, -7.50344231192912E-13,
      -7.429057369279235E-13, -7.35467242662935E-13, -7.2813977070040892E-13,
      -7.209233210403454E-13, -7.1376238253151314E-13, -7.0665695517391214E-13,
      -6.9960703896754239E-13, -6.9261263391240391E-13, -6.8572925115972794E-13,
      -6.7895689070951448E-13, -6.72184530259301E-13, -6.6546768096031883E-13,
      -6.5886185396379915E-13, -6.5231153811851073E-13, -6.4581673342445356E-13,
      -6.3937743988162765E-13, -6.3304916864126426E-13, -6.2672089740090087E-13,
      -6.20503648463E-13, -6.1434191067633037E-13, -6.08235684040892E-13,
      -6.0218496855668491E-13, -5.9618976422370906E-13, -5.9025007104196447E-13,
      -5.8436588901145115E-13, -5.7853721813216907E-13, -5.7281956955534952E-13,
      -5.6710192097853E-13, -5.6143978355294166E-13, -5.5588866842981588E-13,
      -5.503375533066901E-13, -5.4484194933479557E-13, -5.3945736766536356E-13,
      -5.3407278599593155E-13, -5.287437154777308E-13, -5.2347015611076131E-13,
      -5.1830761904625433E-13, -5.130895708305161E-13, -5.0798254491724038E-13,
      -5.0298654130642717E-13, -4.97990537695614E-13, -4.9299453408480076E-13,
      -4.8805404162521882E-13, -4.8322457146809938E-13, -4.7839510131098E-13,
      -4.73676653456323E-13, -4.6895820560166612E-13, -4.6429526889824047E-13,
      -4.5963233219481481E-13, -4.5508041779385167E-13, -4.5058401454411978E-13,
      -4.460876112943879E-13, -4.4164671919588727E-13, -4.3720582709738665E-13,
      -4.3293146845257979E-13, -4.2860159865654168E-13, -4.2432724001173483E-13,
      -4.2010839251815923E-13, -4.1588954502458364E-13, -4.1178171983347056E-13,
      -4.0767389464235748E-13, -4.0362158060247566E-13, -3.996247777138251E-13,
      -3.9562797482517453E-13, -3.9168668308775523E-13, -3.8785641365279844E-13,
      -3.8391512191537913E-13, -3.801403636316536E-13, -3.7636560534792807E-13,
      -3.7259084706420253E-13, -3.6892711108293952E-13, -3.652633751016765E-13,
      -3.6154412796918223E-13, -3.5799141429038173E-13, -3.5438318946034997E-13,
      -3.5088598693278072E-13, -3.4738878440521148E-13, -3.4400260418010475E-13,
      -3.4056091280376677E-13, -3.3717473257866004E-13, -3.3378855235355331E-13,
      -3.3045788327967784E-13, -3.2718272535703363E-13, -3.2396307858562068E-13,
      -3.2068792066297647E-13, -3.1752378504279477E-13, -3.1435964942261307E-13,
      -3.1125102495366264E-13, -3.0808688933348094E-13, -3.05089287166993E-13,
      -3.0203617384927384E-13, -2.9903857168278591E-13, -2.96040969516298E-13,
      -2.9309887850104133E-13, -2.9015678748578466E-13, -2.8732571877299051E-13,
      -2.8443913890896511E-13, -2.8160807019617096E-13, -2.7883251263460807E-13,
      -2.7600144392181392E-13, -2.7328139751148228E-13, -2.7056135110115065E-13,
      -2.67841304690819E-13, -2.652322805829499E-13, -2.6256774532384952E-13,
      -2.599587212159804E-13, -2.5734969710811129E-13, -2.5479618415147343E-13,
      -2.5224267119483557E-13, -2.4974466938942896E-13, -2.4730217873525362E-13,
      -2.44804176929847E-13, -2.4241719742690293E-13, -2.3997470677272759E-13,
      -2.375877272697835E-13, -2.3525625891807067E-13, -2.3286927941512658E-13,
      -2.30593322214645E-13, -2.2826185386293218E-13, -2.2598589666245061E-13,
      -2.237654506132003E-13, -2.2148949341271873E-13, -2.1932455851469967E-13,
      -2.1710411246544936E-13, -2.1499468871866156E-13, -2.1282975382064251E-13,
      -2.1072033007385471E-13, -2.0861090632706691E-13, -2.0650148258027912E-13,
      -2.0450308113595383E-13, -2.024491685403973E-13, -2.0039525594484076E-13,
      -1.9845236565174673E-13, -1.9645396420742145E-13, -1.9451107391432743E-13,
      -1.9262369477246466E-13, -1.9068080447937064E-13, -1.8873791418627661E-13,
      -1.869060461956451E-13, -1.8501866705378234E-13, -1.8318679906315083E-13,
      -1.8135493107251932E-13, -1.7957857423311907E-13, -1.7774670624248756E-13,
      -1.7602586055431857E-13, -1.7424950371491832E-13, -1.7252865802674933E-13,
      -1.7080781233858033E-13, -1.6908696665041134E-13, -1.6742163211347361E-13,
      -1.6575629757653587E-13, -1.6414647419082939E-13, -1.6248113965389166E-13,
      -1.6087131626818518E-13, -1.5926149288247871E-13, -1.5765166949677223E-13,
      -1.56097357262297E-13, -1.5459855617905305E-13, -1.5298873279334657E-13,
      -1.5148993171010261E-13, -1.4999113062685865E-13, -1.4849232954361469E-13,
      -1.4699352846037073E-13, -1.4555023852835802E-13, -1.4410694859634532E-13,
      -1.4271916981556387E-13, -1.4122036873231991E-13, -1.3983258995153847E-13,
      -1.3844481117075702E-13, -1.3705703238997557E-13, -1.3572476476042539E-13,
      -1.343924971308752E-13, -1.3300471835009375E-13, -1.3167245072054357E-13,
      -1.3039569424222464E-13, -1.2906342661267445E-13, -1.2778667013435552E-13,
      -1.2656542480726785E-13, -1.2528866832894892E-13, -1.2406742300186124E-13,
      -1.2279066652354231E-13, -1.2156942119645464E-13, -1.2040368702059823E-13,
      -1.1918244169351055E-13, -1.1801670751765414E-13, -1.1685097334179773E-13,
      -1.1568523916594131E-13, -1.145195049900849E-13, -1.1335377081422848E-13,
      -1.1224354778960333E-13, -1.1113332476497817E-13, -1.1002310174035301E-13,
      -1.0891287871572786E-13, -1.078026556911027E-13, -1.067479438177088E-13,
      -1.056932319443149E-13, -1.04638520070921E-13, -1.0363931934875836E-13,
      -1.0258460747536446E-13, -1.0158540675320182E-13, -1.0053069487980792E-13,
      -9.9531494157645284E-14, -9.8532293435482643E-14, -9.753309271332E-14,
      -9.6589403142388619E-14, -9.5645713571457236E-14, -9.4702024000525853E-14,
      -9.3702823278363212E-14, -9.2759133707431829E-14, -9.1926466438962962E-14,
      -9.0982776868031578E-14, -9.00390872971002E-14, -8.915090887740007E-14,
      -8.83182416089312E-14, -8.7430063189231078E-14, -8.6541884769530952E-14,
      -8.5653706349830827E-14, -8.482103908136196E-14, -8.3988371812893092E-14,
      -8.3100193393192967E-14, -8.2323037275955357E-14, -8.149037000748649E-14,
      -8.0657702739017623E-14, -7.9825035470548755E-14, -7.91033905045424E-14,
      -7.8270723236073536E-14, -7.7493567118835927E-14, -7.6771922152829575E-14,
      -7.5994766035591965E-14, -7.5273121069585613E-14, -7.4495964952348E-14,
      -7.37188088351104E-14, -7.2997163869104043E-14, -7.2275518903097691E-14,
      -7.1553873937091339E-14, -7.0832228971084987E-14, -7.0110584005078636E-14,
      -6.9444450190303542E-14, -6.872280522429719E-14, -6.8112182560753354E-14,
      -6.7390537594747E-14, -6.6724403779971908E-14, -6.6058269965196814E-14,
      -6.539213615042172E-14, -6.4781513486877884E-14, -6.411537967210279E-14,
      -6.3504757008558954E-14, -6.283862319378386E-14, -6.2228000530240024E-14,
      -6.156186671546493E-14, -6.1006755203152352E-14, -6.0396132539608516E-14,
      -5.9729998724833422E-14, -5.9174887212520844E-14, -5.8564264548977008E-14,
      -5.8009153036664429E-14, -5.7454041524351851E-14, -5.6843418860808015E-14,
      -5.6288307348495437E-14, -5.5733195836182858E-14, -5.517808432387028E-14,
      -5.46229728115577E-14, -5.4123372450476381E-14, -5.3512749786932545E-14,
      -5.3013149425851225E-14, -5.2458037913538647E-14, -5.1958437552457326E-14,
      -5.1403326040144748E-14, -5.0959236830294685E-14, -5.0459636469213365E-14,
      -4.9904524956900786E-14, -4.9460435747050724E-14, -4.8905324234738146E-14,
      -4.8461235024888083E-14, -4.801714581503802E-14, -4.7462034302725442E-14,
      -4.7017945092875379E-14, -4.6518344731794059E-14, -4.6074255521943996E-14,
      -4.5630166312093934E-14, -4.5186077102243871E-14, -4.4741987892393809E-14,
      -4.4242387531312488E-14, -4.3853809472693683E-14, -4.3409720262843621E-14,
      -4.2965631052993558E-14, -4.2521541843143495E-14, -4.2132963784524691E-14,
      -4.1688874574674628E-14, -4.1300296516055823E-14, -4.0911718457437019E-14,
      -4.0467629247586956E-14, -4.0079051188968151E-14, -3.9690473130349346E-14,
      -3.9246383920499284E-14, -3.8913317013111737E-14, -3.8524738954492932E-14,
      -3.8080649744642869E-14, -3.7747582837255322E-14, -3.7359004778636518E-14,
      -3.6970426720017713E-14, -3.6637359812630166E-14, -3.6248781754011361E-14,
      -3.5860203695392556E-14, -3.5527136788005009E-14, -3.5194069880617462E-14,
      -3.4805491821998658E-14, -3.4472424914611111E-14, -3.4139358007223564E-14,
      -3.3806291099836017E-14, -3.347322419244847E-14, -3.3140157285060923E-14,
      -3.2807090377673376E-14, -3.2474023470285829E-14, -3.2140956562898282E-14,
      -3.1863400806741993E-14, -3.1530333899354446E-14, -3.11972669919669E-14,
      -3.0864200084579352E-14, -3.0586644328423063E-14, -3.0309088572266774E-14,
      -2.9976021664879227E-14, -2.9698465908722937E-14, -2.9420910152566648E-14,
      -2.9143354396410359E-14, -2.8810287489022812E-14, -2.8532731732866523E-14,
      -2.8255175976710234E-14, -2.7977620220553945E-14, -2.7644553313166398E-14,
      -2.7366997557010109E-14, -2.7144952952085077E-14, -2.6867397195928788E-14,
      -2.65898414397725E-14, -2.631228568361621E-14, -2.6034729927459921E-14,
      -2.581268532253489E-14, -2.5590640717609858E-14, -2.5257573810222311E-14,
      -2.503552920529728E-14, -2.4813484600372249E-14, -2.453592884421596E-14 } ;

    GenerativeArmModelWithRestor_DW.FromWorkspace_PWORK.TimePtr = (void *)
      pTimeValues0;
    GenerativeArmModelWithRestor_DW.FromWorkspace_PWORK.DataPtr = (void *)
      pDataValues0;
    GenerativeArmModelWithRestor_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S4>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.5, 0.5, 0.53, 0.53, 0.6, 0.6, 0.62,
      0.62, 0.9, 0.9, 1.18, 1.18, 1.2, 1.2, 1.22, 1.22, 1.3, 1.3, 10.0 } ;

    static real_T pDataValues0[] = { 1.0, 300.0, 300.0, 20.0, 20.0,
      19.852164730728617, 19.852164730728617, 19.809926082365362,
      19.809926082365362, 19.218585005279831, 19.218585005279831,
      18.627243928194297, 18.627243928194297, 18.585005279831044,
      18.585005279831044, 18.542766631467792, 18.542766631467792,
      18.373812038014783, 18.373812038014783, 0.0, 100.0, 95.0, 95.0, 94.7, 94.7,
      94.0, 94.0, 93.8, 93.8, 91.0, 91.0, 88.2, 88.2, 88.0, 88.0, 87.8, 87.8,
      87.0, 87.0, 0.0, 100.30000000000001, 100.30000000000001,
      100.30000000000001, 100.30000000000001, 100.30000000000001,
      100.30000000000001, 100.30000000000001, 100.30000000000001,
      100.30000000000001, 100.30000000000001, 100.30000000000001,
      100.30000000000001, 100.30000000000001, 100.30000000000001,
      100.30000000000001, 100.30000000000001, 100.30000000000001,
      100.30000000000001, 100.30000000000001, 100.30000000000001, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 200.0, 200.0, 200.0, 197.75, 197.75, 192.5, 192.5, 191.0, 191.0,
      170.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 200.0, 200.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      300.0, 300.0, 300.0, 300.0, 0.0, 0.0, 0.0, 0.0, -73.5, -73.5, -73.5, -73.5,
      -73.5, -73.5, -73.5, -73.5, -73.5, -73.5, -73.5, -73.5, -73.5, -73.5,
      -73.5, -73.5, -73.5, -73.5, -73.5, -73.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40.0, 40.0, 200.0, 200.0,
      200.0 } ;

    GenerativeArmModelWithRestor_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    GenerativeArmModelWithRestor_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    GenerativeArmModelWithRestor_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for ToWorkspace: '<Root>/To ' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "GenerativeArmModelWithRestoring/To ";
    GenerativeArmModelWithRestor_DW.To_PWORK.LoggedData = rt_CreateStructLogVar(
      GenerativeArmModelWithRestor_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(GenerativeArmModelWithRestor_M),
      GenerativeArmModelWithRestor_M->Timing.stepSize0,
      (&rtmGetErrorStatus(GenerativeArmModelWithRestor_M)),
      "scaledPositionProfile",
      0,
      0,
      1,
      0.001,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (GenerativeArmModelWithRestor_DW.To_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "GenerativeArmModelWithRestoring/To Workspace";
    GenerativeArmModelWithRestor_DW.ToWorkspace_PWORK.LoggedData =
      rt_CreateStructLogVar(
      GenerativeArmModelWithRestor_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(GenerativeArmModelWithRestor_M),
      GenerativeArmModelWithRestor_M->Timing.stepSize0,
                            (&rtmGetErrorStatus(GenerativeArmModelWithRestor_M)),
      "velProfile",
      0,
      0,
      1,
      0.001,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (GenerativeArmModelWithRestor_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "GenerativeArmModelWithRestoring/To Workspace1";
    GenerativeArmModelWithRestor_DW.ToWorkspace1_PWORK.LoggedData =
      rt_CreateStructLogVar(
      GenerativeArmModelWithRestor_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(GenerativeArmModelWithRestor_M),
      GenerativeArmModelWithRestor_M->Timing.stepSize0,
                            (&rtmGetErrorStatus(GenerativeArmModelWithRestor_M)),
      "posProfile",
      0,
      0,
      1,
      0.001,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (GenerativeArmModelWithRestor_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace2' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "GenerativeArmModelWithRestoring/To Workspace2";
    GenerativeArmModelWithRestor_DW.ToWorkspace2_PWORK.LoggedData =
      rt_CreateStructLogVar(
      GenerativeArmModelWithRestor_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(GenerativeArmModelWithRestor_M),
      GenerativeArmModelWithRestor_M->Timing.stepSize0,
                            (&rtmGetErrorStatus(GenerativeArmModelWithRestor_M)),
      "armmodeloutput",
      0,
      0,
      1,
      0.001,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (GenerativeArmModelWithRestor_DW.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Memory: '<Root>/Memory' */
  GenerativeArmModelWithRestor_DW.Memory_PreviousInput =
    GenerativeArmModelWithRestori_P.Memory_X0;

  /* InitializeConditions for SecondOrderIntegrator: '<Root>/Integrator, Second-Order1' */
  GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_MODE = 0;
  GenerativeArmModelWithRestor_DW.IntegratorSecondOrder1_DWORK1 = TRUE;

  /* InitializeConditions for ModelReference: '<Root>/Model' */
  ArmModelVersion2_Init(&(GenerativeArmModelWithRestor_DW.Model_DWORK1.rtdw),
                        &(GenerativeArmModelWithRestori_X.Model_CSTATE));

  /* InitializeConditions for Delay: '<Root>/Delay' */
  GenerativeArmModelWithRestor_DW.Delay_DSTATE =
    GenerativeArmModelWithRestori_P.Delay_InitialCondition;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampA = rtInf;
  GenerativeArmModelWithRestor_DW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampA = rtInf;
  GenerativeArmModelWithRestor_DW.Derivative1_RWORK.TimeStampB = rtInf;
}

/* Model terminate function */
void GenerativeArmModelWithRestoring_terminate(void)
{
  /* (no terminate code required) */
}
