/*
 * File: Generate_Sum.h
 *
 * Code generated for Simulink model 'Generate_Sum'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed May 28 08:00:23 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef Generate_Sum_h_
#define Generate_Sum_h_
#ifndef Generate_Sum_COMMON_INCLUDES_
#define Generate_Sum_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Generate_Sum_COMMON_INCLUDES_ */

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Num1;                         /* '<Root>/Num1' */
  real_T Num2;                         /* '<Root>/Num2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Sum;                          /* '<Root>/Sum' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Generate_Sum_initialize(void);
extern void Generate_Sum_step(void);

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
 * '<Root>' : 'Generate_Sum'
 * '<S1>'   : 'Generate_Sum/Subsystem'
 */
#endif                                 /* Generate_Sum_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
