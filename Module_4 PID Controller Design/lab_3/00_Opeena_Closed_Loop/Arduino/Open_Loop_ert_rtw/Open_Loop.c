/*
 * File: Open_Loop.c
 *
 * Code generated for Simulink model 'Open_Loop'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Jun 29 19:45:32 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Open_Loop.h"
#include "rtwtypes.h"
#include "Open_Loop_private.h"

/* Block signals (default storage) */
B_Open_Loop_T Open_Loop_B;

/* Block states (default storage) */
DW_Open_Loop_T Open_Loop_DW;

/* Real-time model */
static RT_MODEL_Open_Loop_T Open_Loop_M_;
RT_MODEL_Open_Loop_T *const Open_Loop_M = &Open_Loop_M_;

/* Model step function */
void Open_Loop_step(void)
{
  real_T u0;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  Open_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (15UL);
  MW_AnalogInSingle_ReadResult
    (Open_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain2' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  Open_Loop_B.Sysrespopenloop = (uint32_T)Open_Loop_P.Gain2_Gain * b_varargout_1;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (Open_Loop_P.ManualSwitch_CurrentSetting == 1) {
    /* Step: '<Root>/Step' */
    if (Open_Loop_M->Timing.t[0] < Open_Loop_P.Step_Time) {
      /* ManualSwitch: '<Root>/Manual Switch' */
      Open_Loop_B.Stepinput = Open_Loop_P.Step_Y0;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch' */
      Open_Loop_B.Stepinput = Open_Loop_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Open_Loop_B.Stepinput = Open_Loop_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* MATLABSystem: '<Root>/PWM' */
  Open_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Gain: '<Root>/Gain' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  u0 = Open_Loop_P.Gain1_Gain * Open_Loop_B.Stepinput * Open_Loop_P.Gain_Gain;

  /* Start for MATLABSystem: '<Root>/PWM' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM' */
  MW_PWM_SetDutyCycle(Open_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, u0);

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Open_Loop_M->Timing.clockTick1 * 1) + 0);

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
  Open_Loop_M->Timing.t[0] =
    ((time_T)(++Open_Loop_M->Timing.clockTick0)) * Open_Loop_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Open_Loop_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Open_Loop_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Open_Loop_M->solverInfo,
                          &Open_Loop_M->Timing.simTimeStep);
    rtsiSetTPtr(&Open_Loop_M->solverInfo, &rtmGetTPtr(Open_Loop_M));
    rtsiSetStepSizePtr(&Open_Loop_M->solverInfo, &Open_Loop_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Open_Loop_M->solverInfo, (&rtmGetErrorStatus
      (Open_Loop_M)));
    rtsiSetRTModelPtr(&Open_Loop_M->solverInfo, Open_Loop_M);
  }

  rtsiSetSimTimeStep(&Open_Loop_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Open_Loop_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Open_Loop_M->solverInfo, false);
  rtsiSetSolverName(&Open_Loop_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Open_Loop_M, &Open_Loop_M->Timing.tArray[0]);
  rtmSetTFinal(Open_Loop_M, 100.0);
  Open_Loop_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Open_Loop_M->Sizes.checksums[0] = (2984028639U);
  Open_Loop_M->Sizes.checksums[1] = (984873077U);
  Open_Loop_M->Sizes.checksums[2] = (3290390665U);
  Open_Loop_M->Sizes.checksums[3] = (3449025280U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Open_Loop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Open_Loop_M->extModeInfo,
      &Open_Loop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Open_Loop_M->extModeInfo, Open_Loop_M->Sizes.checksums);
    rteiSetTFinalTicks(Open_Loop_M->extModeInfo, 100000);
  }

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  Open_Loop_DW.obj.matlabCodegenIsDeleted = false;
  Open_Loop_DW.obj.isInitialized = 1L;
  Open_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (15UL);
  Open_Loop_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  Open_Loop_DW.obj_l.matlabCodegenIsDeleted = false;
  Open_Loop_DW.obj_l.isInitialized = 1L;
  Open_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  Open_Loop_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void Open_Loop_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!Open_Loop_DW.obj.matlabCodegenIsDeleted) {
    Open_Loop_DW.obj.matlabCodegenIsDeleted = true;
    if ((Open_Loop_DW.obj.isInitialized == 1L) &&
        Open_Loop_DW.obj.isSetupComplete) {
      Open_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close(Open_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!Open_Loop_DW.obj_l.matlabCodegenIsDeleted) {
    Open_Loop_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Open_Loop_DW.obj_l.isInitialized == 1L) &&
        Open_Loop_DW.obj_l.isSetupComplete) {
      Open_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(Open_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Open_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(Open_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
