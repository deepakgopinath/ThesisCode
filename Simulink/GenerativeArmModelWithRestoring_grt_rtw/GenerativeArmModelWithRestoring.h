/*
 * GenerativeArmModelWithRestoring.h
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
#ifndef RTW_HEADER_GenerativeArmModelWithRestoring_h_
#define RTW_HEADER_GenerativeArmModelWithRestoring_h_
#ifndef GenerativeArmModelWithRestoring_COMMON_INCLUDES_
# define GenerativeArmModelWithRestoring_COMMON_INCLUDES_
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#endif                                 /* GenerativeArmModelWithRestoring_COMMON_INCLUDES_ */

#include "GenerativeArmModelWithRestoring_types.h"

/* Child system includes */
#include "ArmModelVersion2.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#define GenerativeArmModelWithRestoring_M (GenerativeArmModelWithRestor_M)

/* Block signals (auto storage) */
typedef struct {
  real_T Startinganglerad;             /* '<Root>/Starting angle  (rad)' */
  real_T Initialangularvelocityrads;   /* '<Root>/Initial angular velocity rad//s ' */
  real_T IntegratorSecondOrder1_o1;    /* '<Root>/Integrator, Second-Order1' */
  real_T IntegratorSecondOrder1_o2;    /* '<Root>/Integrator, Second-Order1' */
  real_T Model_o1;                     /* '<Root>/Model' */
  real_T Model_o2;                     /* '<Root>/Model' */
  real_T Model_o3;                     /* '<Root>/Model' */
  real_T Product2;                     /* '<Root>/Product2' */
  real_T whentotriggerantigravity;     /* '<Root>/when to trigger antigravity ' */
  real_T u;                            /* '<Root>/.2' */
  real_T u_l;                          /* '<Root>/.' */
  real_T Derivative1;                  /* '<Root>/Derivative1' */
  real_T x;                            /* '<Root>/MATLAB Function' */
  real_T y;                            /* '<Root>/MATLAB Function' */
  real_T z;                            /* '<Root>/MATLAB Function' */
} B_GenerativeArmModelWithResto_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Startinganglerad_FirstOutputTim;/* '<Root>/Starting angle  (rad)' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<Root>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative1_RWORK;                 /* '<Root>/Derivative1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<Root>/From Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S4>/FromWs' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } To_PWORK;                          /* '<Root>/To ' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<Root>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S4>/FromWs' */

  int_T IntegratorSecondOrder1_MODE;   /* '<Root>/Integrator, Second-Order1' */
  boolean_T Initialangularvelocityrads_Firs;/* '<Root>/Initial angular velocity rad//s ' */
  boolean_T IntegratorSecondOrder1_DWORK1;/* '<Root>/Integrator, Second-Order1' */
  MdlrefDW_ArmModelVersion2_T Model_DWORK1;/* '<Root>/Model' */
} DW_GenerativeArmModelWithRest_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T IntegratorSecondOrder1_CSTATE[2];/* '<Root>/Integrator, Second-Order1' */
  X_ArmModelVersion2_n_T Model_CSTATE; /* '<Root>/Model' */
} X_GenerativeArmModelWithResto_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T IntegratorSecondOrder1_CSTATE[2];/* '<Root>/Integrator, Second-Order1' */
  XDot_ArmModelVersion2_n_T Model_CSTATE;/* '<Root>/Model' */
} XDot_GenerativeArmModelWithRe_T;

/* State disabled  */
typedef struct {
  boolean_T IntegratorSecondOrder1_CSTATE[2];/* '<Root>/Integrator, Second-Order1' */
  XDis_ArmModelVersion2_n_T Model_CSTATE;/* '<Root>/Model' */
} XDis_GenerativeArmModelWithRe_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_GenerativeArmModelWithResto_T_ {
  real_T Startinganglerad_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/Starting angle  (rad)'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T CORforstickanddrumTBD_Gain;   /* Expression: -0.85
                                        * Referenced by: '<Root>/COR for stick and drum TBD'
                                        */
  real_T Initialangularvelocityrads_Valu;/* Expression: 0
                                          * Referenced by: '<Root>/Initial angular velocity rad//s '
                                          */
  real_T IntegratorSecondOrder1_UpperLim;/* Expression: inf
                                          * Referenced by: '<Root>/Integrator, Second-Order1'
                                          */
  real_T IntegratorSecondOrder1_LowerLim;/* Expression: -0.2623
                                          * Referenced by: '<Root>/Integrator, Second-Order1'
                                          */
  real_T drumHeadAngleLimit_Value;     /* Expression: -0.2623
                                        * Referenced by: '<Root>/drumHeadAngleLimit'
                                        */
  real_T l_Value;                      /* Expression: -0.2623
                                        * Referenced by: '<Root>/l'
                                        */
  real_T u_Value;                      /* Expression: 0
                                        * Referenced by: '<Root>/u '
                                        */
  real_T lb_Value;                     /* Expression: -0.9
                                        * Referenced by: '<Root>/lb'
                                        */
  real_T ub_Value;                     /* Expression: 0.6
                                        * Referenced by: '<Root>/ub '
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: const
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Torqueduetogravity_Gain;      /* Expression: 0.735
                                        * Referenced by: '<Root>/Torque due to gravity'
                                        */
  real_T u_Gain;                       /* Expression: -1.
                                        * Referenced by: '<Root>/.1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T u_Gain_k;                     /* Expression: 100/-14.0056
                                        * Referenced by: '<Root>/.2'
                                        */
  real_T distanceoffingerfromfulcrum_Gai;/* Expression: 0.01
                                          * Referenced by: '<Root>/distance of finger from fulcrum'
                                          */
  real_T _Gain;                        /* Expression: -14.0056
                                        * Referenced by: '<Root>/.'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_GenerativeArmModelWit_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_GenerativeArmModelWithResto_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[5];
    real_T odeF[3][5];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_GenerativeArmModelWithResto_T GenerativeArmModelWithRestori_P;

/* Block signals (auto storage) */
extern B_GenerativeArmModelWithResto_T GenerativeArmModelWithRestori_B;

/* Continuous states (auto storage) */
extern X_GenerativeArmModelWithResto_T GenerativeArmModelWithRestori_X;

/* Block states (auto storage) */
extern DW_GenerativeArmModelWithRest_T GenerativeArmModelWithRestor_DW;

/* Model entry point functions */
extern void GenerativeArmModelWithRestoring_initialize(void);
extern void GenerativeArmModelWithRestoring_step(void);
extern void GenerativeArmModelWithRestoring_terminate(void);

/* Real-time Model object */
extern RT_MODEL_GenerativeArmModelWi_T *const GenerativeArmModelWithRestor_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'GenerativeArmModelWithRestoring'
 * '<S1>'   : 'GenerativeArmModelWithRestoring/Compare To Constant'
 * '<S2>'   : 'GenerativeArmModelWithRestoring/Compare To Constant1'
 * '<S3>'   : 'GenerativeArmModelWithRestoring/MATLAB Function'
 * '<S4>'   : 'GenerativeArmModelWithRestoring/linear a(t)due to finger pressing downwards'
 */
#endif                                 /* RTW_HEADER_GenerativeArmModelWithRestoring_h_ */
