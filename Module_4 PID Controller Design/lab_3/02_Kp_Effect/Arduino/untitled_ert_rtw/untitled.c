/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Jun 29 20:45:43 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include "untitled_private.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  real_T u0;
  uint16_T b_varargout_1;

  /* ManualSwitch: '<Root>/Manual Switch1' */
  if (untitled_P.ManualSwitch1_CurrentSetting == 1) {
    /* Step: '<Root>/Step1' */
    if (untitled_M->Timing.t[0] < untitled_P.Step1_Time) {
      /* ManualSwitch: '<Root>/Manual Switch1' */
      untitled_B.Stepinput = untitled_P.Step1_Y0;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch1' */
      untitled_B.Stepinput = untitled_P.Step1_YFinal;
    }

    /* End of Step: '<Root>/Step1' */
  } else {
    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    untitled_B.Stepinput = untitled_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* MATLABSystem: '<Root>/Analog Input1' */
  untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (15UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain5' incorporates:
   *  MATLABSystem: '<Root>/Analog Input1'
   * */
  untitled_B.Sysrespclosedloop = (uint32_T)untitled_P.Gain5_Gain * b_varargout_1;

  /* MATLABSystem: '<Root>/PWM1' */
  untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Gain: '<Root>/Gain3' incorporates:
   *  Gain: '<Root>/Gain4'
   *  Gain: '<Root>/Gain5'
   *  Gain: '<S1>/Gain4'
   *  Sum: '<Root>/Sum'
   */
  u0 = (untitled_B.Stepinput - (real_T)untitled_B.Sysrespclosedloop *
        1.1920928955078125E-7) * untitled_P.Gain4_Gain * untitled_P.Gain4_Gain_c
    * untitled_P.Gain3_Gain;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM1' */
  MW_PWM_SetDutyCycle(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, u0);

  {                                    /* Sample time: [0.0001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((untitled_M->Timing.clockTick1 * 1) + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.t[0] =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&untitled_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&untitled_M->solverInfo, false);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, 10.0);
  untitled_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (2213620436U);
  untitled_M->Sizes.checksums[1] = (493837941U);
  untitled_M->Sizes.checksums[2] = (814360734U);
  untitled_M->Sizes.checksums[3] = (1900113587U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTFinalTicks(untitled_M->extModeInfo, 100000);
  }

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isInitialized = 1L;
  untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (15UL);
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  untitled_DW.obj_i.matlabCodegenIsDeleted = false;
  untitled_DW.obj_i.isInitialized = 1L;
  untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  untitled_DW.obj_i.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1L) && untitled_DW.obj.isSetupComplete)
    {
      untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close(untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!untitled_DW.obj_i.matlabCodegenIsDeleted) {
    untitled_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_i.isInitialized == 1L) &&
        untitled_DW.obj_i.isSetupComplete) {
      untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
