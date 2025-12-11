/*
 * Teach_Pendant_Task_Space.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Teach_Pendant_Task_Space".
 *
 * Model version              : 1.516
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Thu Dec 11 09:30:12 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Teach_Pendant_Task_Space_h_
#define RTW_HEADER_Teach_Pendant_Task_Space_h_
#include <math.h>
#include <string.h>
#include <float.h>
#ifndef Teach_Pendant_Task_Space_COMMON_INCLUDES_
# define Teach_Pendant_Task_Space_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_phantom.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                           /* Teach_Pendant_Task_Space_COMMON_INCLUDES_ */

#include "Teach_Pendant_Task_Space_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T UnitDelay[3];                 /* '<S7>/Unit Delay' */
  real_T Phantom_o2[6];                /* '<S7>/Phantom' */
  real_T JointOffsets[3];              /* '<S7>/Joint Offsets' */
  real_T Switch[3];                    /* '<S8>/Switch' */
  real_T Subtract[3];                  /* '<Root>/Subtract' */
  real_T Saturation1[3];               /* '<S7>/Saturation1' */
  real_T Saturation2[3];               /* '<S7>/Saturation2' */
  real_T Saturation[3];                /* '<S7>/Saturation' */
  real_T Sum1[3];                      /* '<S13>/Sum1' */
  real_T Product1[3];                  /* '<S13>/Product1' */
  real_T Product1_g[3];                /* '<S21>/Product1' */
  real_T ConverttoPositiveRotationConven[3];
        /* '<S7>/Convert to Positive Rotation Convension Used in Kinematics2' */
  real_T x0;                           /* '<S21>/x0' */
  real_T Product[3];                   /* '<S21>/Product' */
  real_T Ki[3];                        /* '<Root>/pid auto tuner' */
  real_T Kd[3];                        /* '<Root>/pid auto tuner' */
  real_T best_PID[9];                  /* '<Root>/pid auto tuner' */
  real_T worst_PID[9];                 /* '<Root>/pid auto tuner' */
  real_T q[3];                         /* '<S24>/MATLAB Function' */
  real_T inter[3];                     /* '<S23>/Embedded MATLAB Function' */
  real_T div[3];                       /* '<S15>/div' */
  real_T out[9];                       /* '<Root>/MATLAB Function2' */
  real_T total_cost;                   /* '<Root>/MATLAB Function' */
  real_T pos[3];                       /* '<Root>/Forward Kinematics' */
  int32_T Phantom_o1;                  /* '<S7>/Phantom' */
  int32_T Phantom_o3;                  /* '<S7>/Phantom' */
  boolean_T reached;                   /* '<Root>/MATLAB Function3' */
} B_Teach_Pendant_Task_Space_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[3];          /* '<S8>/Unit Delay' */
  real_T UnitDelay_DSTATE_b[3];        /* '<S7>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE[3];    /* '<S26>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_h;           /* '<S19>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE[3];          /* '<S15>/Sum( k=1,n-1, x(k) )' */
  real_T particles[120];               /* '<Root>/pid auto tuner' */
  real_T velocities[120];              /* '<Root>/pid auto tuner' */
  real_T pbest[120];                   /* '<Root>/pid auto tuner' */
  real_T pbest_cost[20];               /* '<Root>/pid auto tuner' */
  real_T gbest[6];                     /* '<Root>/pid auto tuner' */
  real_T gbest_cost;                   /* '<Root>/pid auto tuner' */
  real_T current_particle;             /* '<Root>/pid auto tuner' */
  real_T eval_count;                   /* '<Root>/pid auto tuner' */
  real_T idx;                          /* '<S24>/MATLAB Function' */
  real_T N;                            /* '<S24>/MATLAB Function' */
  real_T hold_count;                   /* '<S24>/MATLAB Function' */
  real_T hold_steps;                   /* '<S24>/MATLAB Function' */
  real_T cost_sum;                     /* '<Root>/MATLAB Function' */
  t_phantom_properties Phantom_Phantom;/* '<S7>/Phantom' */
  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  uint32_T method;                     /* '<Root>/pid auto tuner' */
  uint32_T state;                      /* '<Root>/pid auto tuner' */
  uint32_T state_k[2];                 /* '<Root>/pid auto tuner' */
  uint32_T state_j[625];               /* '<Root>/pid auto tuner' */
  int_T Integrator1_IWORK;             /* '<S21>/Integrator1' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S26>/FixPt Unit Delay2' */
  int8_T Traject_SubsysRanBC;          /* '<S8>/Traject' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S11>/Switch Case' */
  int8_T SwitchCaseActionSubsystem2_Subs;
                                     /* '<S11>/Switch Case Action Subsystem2' */
  int8_T SwitchCaseActionSubsystem1_Subs;
                                     /* '<S11>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                      /* '<S11>/Switch Case Action Subsystem' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S11>/Enabled Moving Average' */
  boolean_T initialized_not_empty;     /* '<Root>/pid auto tuner' */
  boolean_T in_zone_prev;              /* '<Root>/pid auto tuner' */
  boolean_T state_not_empty;           /* '<Root>/pid auto tuner' */
  boolean_T idx_not_empty;             /* '<S24>/MATLAB Function' */
  boolean_T Traject_MODE;              /* '<S8>/Traject' */
  boolean_T EnabledMovingAverage_MODE; /* '<S11>/Enabled Moving Average' */
} DW_Teach_Pendant_Task_Space_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S13>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S21>/Integrator2' */
  real_T Integrator1_CSTATE[3];        /* '<S21>/Integrator1' */
} X_Teach_Pendant_Task_Space_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S13>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S21>/Integrator2' */
  real_T Integrator1_CSTATE[3];        /* '<S21>/Integrator1' */
} XDot_Teach_Pendant_Task_Space_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S13>/Integrator' */
  boolean_T Integrator2_CSTATE[3];     /* '<S21>/Integrator2' */
  boolean_T Integrator1_CSTATE[3];     /* '<S21>/Integrator1' */
} XDis_Teach_Pendant_Task_Space_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_Teach_Pendant_Task_Space_T_ {
  real_T starting_point[3];            /* Variable: starting_point
                                        * Referenced by:
                                        *   '<Root>/Constant'
                                        *   '<Root>/Constant1'
                                        */
  real_T traj_pos[13128];              /* Variable: traj_pos
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T traj_zone[4376];              /* Variable: traj_zone
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T BiasRemoval_end_time;         /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S11>/Step: end_time'
                                        */
  real_T SecondOrderLowPassFilter_input_;
                              /* Mask Parameter: SecondOrderLowPassFilter_input_
                               * Referenced by: '<S21>/wn'
                               */
  real_T SecondOrderLowPassFilter_inpu_h;
                              /* Mask Parameter: SecondOrderLowPassFilter_inpu_h
                               * Referenced by: '<S21>/zt'
                               */
  real_T BiasRemoval_start_time;       /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S11>/Step: start_time'
                                        */
  real_T BiasRemoval_switch_id;        /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S19>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S19>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S15>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S16>/zero'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S17>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S18>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S11>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S11>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S11>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S11>/Step: end_time'
                                        */
  real_T Constant1_Value;              /* Expression: 0.001
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 5
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T UnitDelay_InitialCondition_o; /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  real_T firstpoint_Value[3];        /* Expression: [pos(1,1) pos(1,2) pos(1,3)]
                                      * Referenced by: '<S8>/first point'
                                      */
  real_T UnitDelay_InitialCondition_g; /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  real_T EncoderOffsets_Bias[6];       /* Expression: [0 659 914 0 -1000 0]
                                        * Referenced by: '<S7>/Encoder Offsets'
                                        */
  real_T Bias1_Bias[3];                /* Expression: [0 -659 -910]
                                        * Referenced by: '<S12>/Bias1'
                                        */
  real_T Encoder_Gain;                 /* Expression: 2*pi/2048
                                        * Referenced by: '<S12>/Encoder'
                                        */
  real_T GearRatio_Gain[3];            /* Expression: 1./[7.461 -7.519 7.529]
                                        * Referenced by: '<S12>/Gear Ratio'
                                        */
  real_T ConverttoPositiveRotationConven[3];/* Expression: [1 -1 -1]
                                             * Referenced by: '<S7>/Convert to Positive Rotation Convension Used in Kinematics1'
                                             */
  real_T JointOffsets_Bias[3];         /* Expression: [0 0 pi()/2]
                                        * Referenced by: '<S7>/Joint Offsets'
                                        */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: 0.0
                                          * Referenced by: '<S26>/FixPt Unit Delay1'
                                          */
  real_T speed_Value;                  /* Expression: .1
                                        * Referenced by: '<S8>/speed'
                                        */
  real_T Constant2_Value_a;            /* Expression: qc_get_step_size
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0.01
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant2_Value_h;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Saturation1_UpperSat[3];      /* Expression: [.1 .1 .025]
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Saturation1_LowerSat[3];      /* Expression: [.02 .02 0]
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Saturation2_UpperSat[3];      /* Expression: [2 2 3]
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  real_T Saturation2_LowerSat[3];      /* Expression: [0 0 0]
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  real_T Saturation_UpperSat[3];       /* Expression: [2 2 1]
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat[3];       /* Expression: [0 0 0]
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S21>/Integrator2'
                                        */
  real_T ConverttoPositiveRotationConv_g[3];/* Expression: [-1 -1 -1]
                                             * Referenced by: '<S7>/Convert to Positive Rotation Convension Used in Kinematics2'
                                             */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S21>/x0'
                                        */
  uint8_T FixPtUnitDelay2_InitialConditio;
                          /* Computed Parameter: FixPtUnitDelay2_InitialConditio
                           * Referenced by: '<S26>/FixPt Unit Delay2'
                           */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S26>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_Teach_Pendant_Task_Sp_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Teach_Pendant_Task_Space_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][9];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Teach_Pendant_Task_Space_T Teach_Pendant_Task_Space_P;

/* Block signals (default storage) */
extern B_Teach_Pendant_Task_Space_T Teach_Pendant_Task_Space_B;

/* Continuous states (default storage) */
extern X_Teach_Pendant_Task_Space_T Teach_Pendant_Task_Space_X;

/* Block states (default storage) */
extern DW_Teach_Pendant_Task_Space_T Teach_Pendant_Task_Space_DW;

/* Model entry point functions */
extern void Teach_Pendant_Task_Space_initialize(void);
extern void Teach_Pendant_Task_Space_step(void);
extern void Teach_Pendant_Task_Space_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Teach_Pendant_Task_S_T *const Teach_Pendant_Task_Space_M;

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
 * '<Root>' : 'Teach_Pendant_Task_Space'
 * '<S1>'   : 'Teach_Pendant_Task_Space/Forward Kinematics'
 * '<S2>'   : 'Teach_Pendant_Task_Space/Inverse Kinematics'
 * '<S3>'   : 'Teach_Pendant_Task_Space/MATLAB Function'
 * '<S4>'   : 'Teach_Pendant_Task_Space/MATLAB Function1'
 * '<S5>'   : 'Teach_Pendant_Task_Space/MATLAB Function2'
 * '<S6>'   : 'Teach_Pendant_Task_Space/MATLAB Function3'
 * '<S7>'   : 'Teach_Pendant_Task_Space/PID Control'
 * '<S8>'   : 'Teach_Pendant_Task_Space/Trajectory Planning'
 * '<S9>'   : 'Teach_Pendant_Task_Space/cost function'
 * '<S10>'  : 'Teach_Pendant_Task_Space/pid auto tuner'
 * '<S11>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal'
 * '<S12>'  : 'Teach_Pendant_Task_Space/PID Control/Encoders to Joints q1, q2, q3'
 * '<S13>'  : 'Teach_Pendant_Task_Space/PID Control/PIV Controller'
 * '<S14>'  : 'Teach_Pendant_Task_Space/PID Control/Tool Offset'
 * '<S15>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Enabled Moving Average'
 * '<S16>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Switch Case Action Subsystem'
 * '<S17>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Switch Case Action Subsystem1'
 * '<S18>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Switch Case Action Subsystem2'
 * '<S19>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Enabled Moving Average/Increment'
 * '<S20>'  : 'Teach_Pendant_Task_Space/PID Control/Encoders to Joints q1, q2, q3/Embedded MATLAB Function'
 * '<S21>'  : 'Teach_Pendant_Task_Space/PID Control/PIV Controller/Second-Order Low-Pass Filter'
 * '<S22>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Forward Kinematics'
 * '<S23>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Linear Trajectory'
 * '<S24>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject'
 * '<S25>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Linear Trajectory/Embedded MATLAB Function'
 * '<S26>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Linear Trajectory/Unit Delay External IC'
 * '<S27>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/MATLAB Function'
 */
#endif                              /* RTW_HEADER_Teach_Pendant_Task_Space_h_ */
