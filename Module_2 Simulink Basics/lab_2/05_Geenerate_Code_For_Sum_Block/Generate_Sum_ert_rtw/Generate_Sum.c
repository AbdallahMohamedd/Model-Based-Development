/*
 * File: Generate_Sum.c
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

#include "Generate_Sum.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Generate_Sum_step(void)
{
  /* Outport: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/Num1'
   *  Inport: '<Root>/Num2'
   *  Sum: '<S1>/Add'
   */
  rtY.Sum = rtU.Num1 + rtU.Num2;
}

/* Model initialize function */
void Generate_Sum_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
