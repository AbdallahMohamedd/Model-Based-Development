/*
 * File: Generate_Saturation.h
 *
 * Code generated for Simulink model 'Generate_Saturation'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed May 28 08:27:02 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef Generate_Saturation_h_
#define Generate_Saturation_h_
#ifndef Generate_Saturation_COMMON_INCLUDES_
#define Generate_Saturation_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* Generate_Saturation_COMMON_INCLUDES_ */

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Signal;                       /* '<Root>/Signal' */
  real_T UL;                           /* '<Root>/UL' */
  real_T LL;                           /* '<Root>/LL' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T SaturationOutput;             /* '<Root>/Saturation Output' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Generate_Saturation_initialize(void);
extern void Generate_Saturation_step(void);

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
 * '<Root>' : 'Generate_Saturation'
 * '<S1>'   : 'Generate_Saturation/Saturation'
 */
#endif                                 /* Generate_Saturation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
