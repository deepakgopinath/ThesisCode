/*
 * GenerativeArmModelWithRestoring_data.c
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

/* Block parameters (auto storage) */
P_GenerativeArmModelWithResto_T GenerativeArmModelWithRestori_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Starting angle  (rad)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  -0.85,                               /* Expression: -0.85
                                        * Referenced by: '<Root>/COR for stick and drum TBD'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Initial angular velocity rad//s '
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<Root>/Integrator, Second-Order1'
                                        */
  -0.2623,                             /* Expression: -0.2623
                                        * Referenced by: '<Root>/Integrator, Second-Order1'
                                        */
  -0.2623,                             /* Expression: -0.2623
                                        * Referenced by: '<Root>/drumHeadAngleLimit'
                                        */
  -0.2623,                             /* Expression: -0.2623
                                        * Referenced by: '<Root>/l'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/u '
                                        */
  -0.9,                                /* Expression: -0.9
                                        * Referenced by: '<Root>/lb'
                                        */
  0.6,                                 /* Expression: 0.6
                                        * Referenced by: '<Root>/ub '
                                        */
  -0.262,                              /* Expression: const
                                        * Referenced by: '<S2>/Constant'
                                        */
  -0.262,                              /* Expression: const
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.735,                               /* Expression: 0.735
                                        * Referenced by: '<Root>/Torque due to gravity'
                                        */
  -1.0,                                /* Expression: -1.
                                        * Referenced by: '<Root>/.1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Delay'
                                        */
  -7.140001142400183,                  /* Expression: 100/-14.0056
                                        * Referenced by: '<Root>/.2'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<Root>/distance of finger from fulcrum'
                                        */
  -14.0056,                            /* Expression: -14.0056
                                        * Referenced by: '<Root>/.'
                                        */
  1U                                   /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
};
