/*
 * File: Kp_Effect.c
 *
 * Code generated for Simulink model 'Kp_Effect'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Jun 30 14:36:56 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Kp_Effect.h"
#include "rtwtypes.h"
#include "Kp_Effect_private.h"

/* Block signals (default storage) */
B_Kp_Effect_T Kp_Effect_B;

/* Block states (default storage) */
DW_Kp_Effect_T Kp_Effect_DW;

/* Real-time model */
static RT_MODEL_Kp_Effect_T Kp_Effect_M_;
RT_MODEL_Kp_Effect_T *const Kp_Effect_M = &Kp_Effect_M_;

/* Model step function */
void Kp_Effect_step(void)
{
  real_T u0;
  uint16_T b_varargout_1;

  /* ManualSwitch: '<Root>/Manual Switch1' */
  if (Kp_Effect_P.ManualSwitch1_CurrentSetting == 1) {
    /* Step: '<Root>/Step1' */
    if (Kp_Effect_M->Timing.t[0] < Kp_Effect_P.Step1_Time) {
      /* ManualSwitch: '<Root>/Manual Switch1' */
      Kp_Effect_B.Stepinput = Kp_Effect_P.Step1_Y0;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch1' */
      Kp_Effect_B.Stepinput = Kp_Effect_P.Step1_YFinal;
    }

    /* End of Step: '<Root>/Step1' */
  } else {
    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Kp_Effect_B.Stepinput = Kp_Effect_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* MATLABSystem: '<Root>/Analog Input1' */
  Kp_Effect_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (15UL);
  MW_AnalogInSingle_ReadResult
    (Kp_Effect_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain5' incorporates:
   *  MATLABSystem: '<Root>/Analog Input1'
   * */
  Kp_Effect_B.Sysrespclosedloop = (uint32_T)Kp_Effect_P.Gain5_Gain *
    b_varargout_1;

  /* MATLABSystem: '<Root>/PWM1' */
  Kp_Effect_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Gain: '<Root>/Gain3' incorporates:
   *  Gain: '<Root>/Gain4'
   *  Gain: '<Root>/Gain5'
   *  Gain: '<S1>/Kp'
   *  Sum: '<Root>/Sum'
   */
  u0 = (Kp_Effect_B.Stepinput - (real_T)Kp_Effect_B.Sysrespclosedloop *
        1.1920928955078125E-7) * Kp_Effect_P.Kp_Gain * Kp_Effect_P.Gain4_Gain *
    Kp_Effect_P.Gain3_Gain;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM1' */
  MW_PWM_SetDutyCycle(Kp_Effect_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, u0);

  {                                    /* Sample time: [0.0001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Kp_Effect_M->Timing.clockTick1 * 1) + 0);

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
  Kp_Effect_M->Timing.t[0] =
    ((time_T)(++Kp_Effect_M->Timing.clockTick0)) * Kp_Effect_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Kp_Effect_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Kp_Effect_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Kp_Effect_M->solverInfo,
                          &Kp_Effect_M->Timing.simTimeStep);
    rtsiSetTPtr(&Kp_Effect_M->solverInfo, &rtmGetTPtr(Kp_Effect_M));
    rtsiSetStepSizePtr(&Kp_Effect_M->solverInfo, &Kp_Effect_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Kp_Effect_M->solverInfo, (&rtmGetErrorStatus
      (Kp_Effect_M)));
    rtsiSetRTModelPtr(&Kp_Effect_M->solverInfo, Kp_Effect_M);
  }

  rtsiSetSimTimeStep(&Kp_Effect_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Kp_Effect_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Kp_Effect_M->solverInfo, false);
  rtsiSetSolverName(&Kp_Effect_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Kp_Effect_M, &Kp_Effect_M->Timing.tArray[0]);
  rtmSetTFinal(Kp_Effect_M, 13.0);
  Kp_Effect_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  Kp_Effect_M->Sizes.checksums[0] = (587391412U);
  Kp_Effect_M->Sizes.checksums[1] = (1972848909U);
  Kp_Effect_M->Sizes.checksums[2] = (3760193359U);
  Kp_Effect_M->Sizes.checksums[3] = (1202041540U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Kp_Effect_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Kp_Effect_M->extModeInfo,
      &Kp_Effect_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Kp_Effect_M->extModeInfo, Kp_Effect_M->Sizes.checksums);
    rteiSetTFinalTicks(Kp_Effect_M->extModeInfo, 130000);
  }

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  Kp_Effect_DW.obj.matlabCodegenIsDeleted = false;
  Kp_Effect_DW.obj.isInitialized = 1L;
  Kp_Effect_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (15UL);
  Kp_Effect_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  Kp_Effect_DW.obj_i.matlabCodegenIsDeleted = false;
  Kp_Effect_DW.obj_i.isInitialized = 1L;
  Kp_Effect_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  Kp_Effect_DW.obj_i.isSetupComplete = true;
}

/* Model terminate function */
void Kp_Effect_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!Kp_Effect_DW.obj.matlabCodegenIsDeleted) {
    Kp_Effect_DW.obj.matlabCodegenIsDeleted = true;
    if ((Kp_Effect_DW.obj.isInitialized == 1L) &&
        Kp_Effect_DW.obj.isSetupComplete) {
      Kp_Effect_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close(Kp_Effect_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!Kp_Effect_DW.obj_i.matlabCodegenIsDeleted) {
    Kp_Effect_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Kp_Effect_DW.obj_i.isInitialized == 1L) &&
        Kp_Effect_DW.obj_i.isSetupComplete) {
      Kp_Effect_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(Kp_Effect_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Kp_Effect_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(Kp_Effect_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
