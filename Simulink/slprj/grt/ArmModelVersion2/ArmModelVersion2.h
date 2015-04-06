/*
 * Code generation for system model 'ArmModelVersion2'
 * For more details, see corresponding source file ArmModelVersion2.c
 *
 */
#ifndef RTW_HEADER_ArmModelVersion2_h_
#define RTW_HEADER_ArmModelVersion2_h_
#ifndef ArmModelVersion2_COMMON_INCLUDES_
# define ArmModelVersion2_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "multiword_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#endif                                 /* ArmModelVersion2_COMMON_INCLUDES_ */

#include "ArmModelVersion2_types.h"

/* Block signals for model 'ArmModelVersion2' */
typedef struct {
  real_T InitialVelocity;              /* '<S2>/Initial Velocity ' */
  real_T FilterCoefficient;            /* '<S1>/Filter Coefficient' */
  real_T Sum;                          /* '<S2>/Sum' */
} B_ArmModelVersion2_c_T;

/* Block states (auto storage) for model 'ArmModelVersion2' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  int_T IntegratorSecondOrder_MODE;    /* '<S2>/Integrator, Second-Order' */
  boolean_T InitialVelocity_FirstOutputTime;/* '<S2>/Initial Velocity ' */
  boolean_T IntegratorSecondOrder_DWORK1;/* '<S2>/Integrator, Second-Order' */
} DW_ArmModelVersion2_f_T;

/* Continuous states for model 'ArmModelVersion2' */
typedef struct {
  real_T IntegratorSecondOrder_CSTATE[2];/* '<S2>/Integrator, Second-Order' */
  real_T Filter_CSTATE;                /* '<S1>/Filter' */
} X_ArmModelVersion2_n_T;

/* State derivatives for model 'ArmModelVersion2' */
typedef struct {
  real_T IntegratorSecondOrder_CSTATE[2];/* '<S2>/Integrator, Second-Order' */
  real_T Filter_CSTATE;                /* '<S1>/Filter' */
} XDot_ArmModelVersion2_n_T;

/* State Disabled for model 'ArmModelVersion2' */
typedef struct {
  boolean_T IntegratorSecondOrder_CSTATE[2];/* '<S2>/Integrator, Second-Order' */
  boolean_T Filter_CSTATE;             /* '<S1>/Filter' */
} XDis_ArmModelVersion2_n_T;

/* Real-time Model Data Structure */
struct tag_RTM_ArmModelVersion2_T {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
    boolean_T *stopRequestedFlag;
  } Timing;
};

typedef struct {
  B_ArmModelVersion2_c_T rtb;
  DW_ArmModelVersion2_f_T rtdw;
  RT_MODEL_ArmModelVersion2_T rtm;
} MdlrefDW_ArmModelVersion2_T;

/* Model reference registration function */
extern void ArmModelVersion2_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_ArmModelVersion2_T *
  const ArmModelVersion2_M, B_ArmModelVersion2_c_T *localB,
  DW_ArmModelVersion2_f_T *localDW);
extern void ArmModelVersion2_Init(DW_ArmModelVersion2_f_T *localDW,
  X_ArmModelVersion2_n_T *localX);
extern void ArmModelVersion2_Start(DW_ArmModelVersion2_f_T *localDW);
extern void ArmModelVersion2_Deriv(B_ArmModelVersion2_c_T *localB,
  DW_ArmModelVersion2_f_T *localDW, X_ArmModelVersion2_n_T *localX,
  XDot_ArmModelVersion2_n_T *localXdot);
extern void ArmModelVersion2_Update(RT_MODEL_ArmModelVersion2_T * const
  ArmModelVersion2_M, real_T *rty_Out2, B_ArmModelVersion2_c_T *localB,
  DW_ArmModelVersion2_f_T *localDW);
extern void ArmModelVersion2(RT_MODEL_ArmModelVersion2_T * const
  ArmModelVersion2_M, const real_T *rtu_In1, const real_T *rtu_In2, real_T
  *rty_Out1, real_T *rty_Out2, real_T *rty_Out3, B_ArmModelVersion2_c_T *localB,
  DW_ArmModelVersion2_f_T *localDW, X_ArmModelVersion2_n_T *localX);

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
 * '<Root>' : 'ArmModelVersion2'
 * '<S1>'   : 'ArmModelVersion2/PID Controller1'
 * '<S2>'   : 'ArmModelVersion2/Subsystem'
 * '<S3>'   : 'ArmModelVersion2/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_ArmModelVersion2_h_ */
