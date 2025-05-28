/*
 * File: Generate_Saturation.c
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

#include "Generate_Saturation.h"
#include <math.h>

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Generate_Saturation_step(void)
{
  /* Outport: '<Root>/Saturation Output' incorporates:
   *  Inport: '<Root>/LL'
   *  Inport: '<Root>/Signal'
   *  Inport: '<Root>/UL'
   *  MinMax: '<S1>/Max'
   *  MinMax: '<S1>/Min'
   */
  rtY.SaturationOutput = fmax(fmin(rtU.UL, rtU.Signal), rtU.LL);
}

/* Model initialize function */
void Generate_Saturation_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
