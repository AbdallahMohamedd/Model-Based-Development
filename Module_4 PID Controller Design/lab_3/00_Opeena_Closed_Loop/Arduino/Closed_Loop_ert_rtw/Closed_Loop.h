/*
 * File: Closed_Loop.h
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

#ifndef Closed_Loop_h_
#define Closed_Loop_h_
#ifndef Closed_Loop_COMMON_INCLUDES_
#define Closed_Loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                                 /* Closed_Loop_COMMON_INCLUDES_ */

#include "Closed_Loop_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Stepinput;                    /* '<Root>/Manual Switch1' */
  uint32_T Sysrespclosedloop;          /* '<Root>/Gain5' */
} B_Closed_Loop_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  codertarget_arduinobase_int_f_T obj_l;/* '<Root>/PWM1' */
} DW_Closed_Loop_T;

/* Parameters (default storage) */
struct P_Closed_Loop_T_ {
  real_T Step1_Time;                   /* Expression: 2
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 255/5
                                        * Referenced by: '<Root>/Gain3'
                                        */
  uint16_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<Root>/Gain5'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_Closed_Loop_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Closed_Loop_T Closed_Loop_P;

/* Block signals (default storage) */
extern B_Closed_Loop_T Closed_Loop_B;

/* Block states (default storage) */
extern DW_Closed_Loop_T Closed_Loop_DW;

/* Model entry point functions */
extern void Closed_Loop_initialize(void);
extern void Closed_Loop_step(void);
extern void Closed_Loop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Closed_Loop_T *const Closed_Loop_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Closed_Loop'
 */
#endif                                 /* Closed_Loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
