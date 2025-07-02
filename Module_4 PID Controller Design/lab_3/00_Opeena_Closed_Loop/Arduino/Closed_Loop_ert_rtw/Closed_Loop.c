/*
 * File: Closed_Loop.c
 *
 * Code generated for Simulink model 'Closed_Loop'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Jun 29 19:53:46 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Closed_Loop.h"
#include "rtwtypes.h"
#include "Closed_Loop_private.h"

/* Block signals (default storage) */
B_Closed_Loop_T Closed_Loop_B;

/* Block states (default storage) */
DW_Closed_Loop_T Closed_Loop_DW;

/* Real-time model */
static RT_MODEL_Closed_Loop_T Closed_Loop_M_;
RT_MODEL_Closed_Loop_T *const Closed_Loop_M = &Closed_Loop_M_;

/* Model step function */
void Closed_Loop_step(void)
{
  real_T u0;
  uint16_T b_varargout_1;

  /* ManualSwitch: '<Root>/Manual Switch1' */
  if (Closed_Loop_P.ManualSwitch1_CurrentSetting == 1) {
    /* Step: '<Root>/Step1' */
    if (Closed_Loop_M->Timing.t[0] < Closed_Loop_P.Step1_Time) {
      /* ManualSwitch: '<Root>/Manual Switch1' */
      Closed_Loop_B.Stepinput = Closed_Loop_P.Step1_Y0;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch1' */
      Closed_Loop_B.Stepinput = Closed_Loop_P.Step1_YFinal;
    }

    /* End of Step: '<Root>/Step1' */
  } else {
    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Closed_Loop_B.Stepinput = Closed_Loop_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* MATLABSystem: '<Root>/Analog Input1' */
  Closed_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (Closed_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain5' incorporates:
   *  MATLABSystem: '<Root>/Analog Input1'
   * */
  Closed_Loop_B.Sysrespclosedloop = (uint32_T)Closed_Loop_P.Gain5_Gain *
    b_varargout_1;

  /* MATLABSystem: '<Root>/PWM1' */
  Closed_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Gain: '<Root>/Gain3' incorporates:
   *  Gain: '<Root>/Gain4'
   *  Gain: '<Root>/Gain5'
   *  Sum: '<Root>/Sum'
   */
  u0 = (Closed_Loop_B.Stepinput - (real_T)Closed_Loop_B.Sysrespclosedloop *
        1.1920928955078125E-7) * Closed_Loop_P.Gain4_Gain *
    Closed_Loop_P.Gain3_Gain;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM1' */
  MW_PWM_SetDutyCycle(Closed_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, u0);

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Closed_Loop_M->Timing.clockTick1 * 1) + 0);

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
  Closed_Loop_M->Timing.t[0] =
    ((time_T)(++Closed_Loop_M->Timing.clockTick0)) *
    Closed_Loop_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Closed_Loop_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Closed_Loop_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Closed_Loop_M->solverInfo,
                          &Closed_Loop_M->Timing.simTimeStep);
    rtsiSetTPtr(&Closed_Loop_M->solverInfo, &rtmGetTPtr(Closed_Loop_M));
    rtsiSetStepSizePtr(&Closed_Loop_M->solverInfo,
                       &Closed_Loop_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Closed_Loop_M->solverInfo, (&rtmGetErrorStatus
      (Closed_Loop_M)));
    rtsiSetRTModelPtr(&Closed_Loop_M->solverInfo, Closed_Loop_M);
  }

  rtsiSetSimTimeStep(&Closed_Loop_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Closed_Loop_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Closed_Loop_M->solverInfo, false);
  rtsiSetSolverName(&Closed_Loop_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Closed_Loop_M, &Closed_Loop_M->Timing.tArray[0]);
  rtmSetTFinal(Closed_Loop_M, 100.0);
  Closed_Loop_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Closed_Loop_M->Sizes.checksums[0] = (422012585U);
  Closed_Loop_M->Sizes.checksums[1] = (1041911124U);
  Closed_Loop_M->Sizes.checksums[2] = (3754437324U);
  Closed_Loop_M->Sizes.checksums[3] = (2948400785U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Closed_Loop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Closed_Loop_M->extModeInfo,
      &Closed_Loop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Closed_Loop_M->extModeInfo,
                        Closed_Loop_M->Sizes.checksums);
    rteiSetTFinalTicks(Closed_Loop_M->extModeInfo, 100000);
  }

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  Closed_Loop_DW.obj.matlabCodegenIsDeleted = false;
  Closed_Loop_DW.obj.isInitialized = 1L;
  Closed_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(15UL);
  Closed_Loop_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  Closed_Loop_DW.obj_l.matlabCodegenIsDeleted = false;
  Closed_Loop_DW.obj_l.isInitialized = 1L;
  Closed_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  Closed_Loop_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void Closed_Loop_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!Closed_Loop_DW.obj.matlabCodegenIsDeleted) {
    Closed_Loop_DW.obj.matlabCodegenIsDeleted = true;
    if ((Closed_Loop_DW.obj.isInitialized == 1L) &&
        Closed_Loop_DW.obj.isSetupComplete) {
      Closed_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close(Closed_Loop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!Closed_Loop_DW.obj_l.matlabCodegenIsDeleted) {
    Closed_Loop_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Closed_Loop_DW.obj_l.isInitialized == 1L) &&
        Closed_Loop_DW.obj_l.isSetupComplete) {
      Closed_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(Closed_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Closed_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(Closed_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
