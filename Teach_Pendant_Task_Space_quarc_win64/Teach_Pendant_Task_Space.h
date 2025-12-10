/*
 * Teach_Pendant_Task_Space.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Teach_Pendant_Task_Space".
 *
 * Model version              : 1.492
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Dec 10 19:55:29 2025
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
  real_T Add;                          /* '<Root>/Add' */
  real_T UnitDelay[3];                 /* '<S6>/Unit Delay' */
  real_T Phantom_o2[6];                /* '<S6>/Phantom' */
  real_T JointOffsets[3];              /* '<S6>/Joint Offsets' */
  real_T Switch[3];                    /* '<S7>/Switch' */
  real_T Subtract[3];                  /* '<Root>/Subtract' */
  real_T Saturation1[3];               /* '<S6>/Saturation1' */
  real_T Saturation2[3];               /* '<S6>/Saturation2' */
  real_T Saturation[3];                /* '<S6>/Saturation' */
  real_T Sum1[3];                      /* '<S12>/Sum1' */
  real_T Product1[3];                  /* '<S12>/Product1' */
  real_T Product1_g[3];                /* '<S20>/Product1' */
  real_T ConverttoPositiveRotationConven[3];
        /* '<S6>/Convert to Positive Rotation Convension Used in Kinematics2' */
  real_T x0;                           /* '<S20>/x0' */
  real_T Product[3];                   /* '<S20>/Product' */
  real_T best_Kp[3];                   /* '<Root>/pid auto tuner' */
  real_T best_Ki[3];                   /* '<Root>/pid auto tuner' */
  real_T best_Kd[3];                   /* '<Root>/pid auto tuner' */
  real_T current_seg;                  /* '<Root>/pid auto tuner' */
  real_T Out;                          /* '<S26>/Out' */
  real_T Out_i;                        /* '<S27>/Out' */
  real_T Out_p;                        /* '<S28>/Out' */
  real_T inter[3];                     /* '<S22>/Embedded MATLAB Function' */
  real_T div[3];                       /* '<S14>/div' */
  real_T Kp_p[3];                      /* '<Root>/MATLAB Function1' */
  real_T Ki_g[3];                      /* '<Root>/MATLAB Function1' */
  real_T Kd_f[3];                      /* '<Root>/MATLAB Function1' */
  real_T current_seg_b;                /* '<Root>/MATLAB Function1' */
  real_T total_cost;                   /* '<Root>/MATLAB Function' */
  real_T pos[3];                       /* '<Root>/Forward Kinematics' */
  real_T out[9];                       /* '<Root>/1 to out 1st signal' */
  int32_T Phantom_o1;                  /* '<S6>/Phantom' */
  int32_T Phantom_o3;                  /* '<S6>/Phantom' */
} B_Teach_Pendant_Task_Space_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay_DSTATE_b[3];        /* '<S6>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE[3];    /* '<S25>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_h;           /* '<S18>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE[3];          /* '<S14>/Sum( k=1,n-1, x(k) )' */
  real_T particles[1200];              /* '<Root>/pid auto tuner' */
  real_T velocities[1200];             /* '<Root>/pid auto tuner' */
  real_T pbest[1200];                  /* '<Root>/pid auto tuner' */
  real_T pbest_cost[200];              /* '<Root>/pid auto tuner' */
  real_T gbest[60];                    /* '<Root>/pid auto tuner' */
  real_T gbest_cost[10];               /* '<Root>/pid auto tuner' */
  real_T current_particle[10];         /* '<Root>/pid auto tuner' */
  real_T eval_count[10];               /* '<Root>/pid auto tuner' */
  real_T last_seg;                     /* '<Root>/MATLAB Function1' */
  real_T cost_accum[10];               /* '<Root>/MATLAB Function' */
  real_T last_seg_b;                   /* '<Root>/MATLAB Function' */
  t_phantom_properties Phantom_Phantom;/* '<S6>/Phantom' */
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
  int_T Integrator1_IWORK;             /* '<S20>/Integrator1' */
  uint16_T Output_DSTATE;              /* '<S29>/Output' */
  uint16_T Output_DSTATE_j;            /* '<S32>/Output' */
  uint16_T Output_DSTATE_c;            /* '<S35>/Output' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S25>/FixPt Unit Delay2' */
  int8_T Traject_SubsysRanBC;          /* '<S7>/Traject' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S10>/Switch Case' */
  int8_T SwitchCaseActionSubsystem2_Subs;
                                     /* '<S10>/Switch Case Action Subsystem2' */
  int8_T SwitchCaseActionSubsystem1_Subs;
                                     /* '<S10>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                      /* '<S10>/Switch Case Action Subsystem' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S10>/Enabled Moving Average' */
  boolean_T in_zone_prev[10];          /* '<Root>/pid auto tuner' */
  boolean_T initialized_not_empty;     /* '<Root>/pid auto tuner' */
  boolean_T state_not_empty;           /* '<Root>/pid auto tuner' */
  boolean_T Traject_MODE;              /* '<S7>/Traject' */
  boolean_T EnabledMovingAverage_MODE; /* '<S10>/Enabled Moving Average' */
} DW_Teach_Pendant_Task_Space_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S12>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S20>/Integrator2' */
  real_T Integrator1_CSTATE[3];        /* '<S20>/Integrator1' */
} X_Teach_Pendant_Task_Space_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S12>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S20>/Integrator2' */
  real_T Integrator1_CSTATE[3];        /* '<S20>/Integrator1' */
} XDot_Teach_Pendant_Task_Space_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S12>/Integrator' */
  boolean_T Integrator2_CSTATE[3];     /* '<S20>/Integrator2' */
  boolean_T Integrator1_CSTATE[3];     /* '<S20>/Integrator1' */
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
  real_T segment_lengths[3];           /* Variable: segment_lengths
                                        * Referenced by:
                                        *   '<Root>/gives the length of all the segments needed by const_pid to detect which segment is robot is in currently'
                                        *   '<Root>/same as of const_pid'
                                        */
  real_T starting_point[3];            /* Variable: starting_point
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T TrajectoryJoint1_OutValues[2096];
                                   /* Mask Parameter: TrajectoryJoint1_OutValues
                                    * Referenced by: '<S26>/Vector'
                                    */
  real_T TrajectoryJoint2_OutValues[2096];
                                   /* Mask Parameter: TrajectoryJoint2_OutValues
                                    * Referenced by: '<S27>/Vector'
                                    */
  real_T TrajectoryJoint3_OutValues[2096];
                                   /* Mask Parameter: TrajectoryJoint3_OutValues
                                    * Referenced by: '<S28>/Vector'
                                    */
  real_T BiasRemoval_end_time;         /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S10>/Step: end_time'
                                        */
  real_T SecondOrderLowPassFilter_input_;
                              /* Mask Parameter: SecondOrderLowPassFilter_input_
                               * Referenced by: '<S20>/wn'
                               */
  real_T SecondOrderLowPassFilter_inpu_h;
                              /* Mask Parameter: SecondOrderLowPassFilter_inpu_h
                               * Referenced by: '<S20>/zt'
                               */
  real_T BiasRemoval_start_time;       /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S10>/Step: start_time'
                                        */
  real_T BiasRemoval_switch_id;        /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint16_T LimitedCounter_uplimit;     /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S31>/FixPt Switch'
                                        */
  uint16_T LimitedCounter_uplimit_p; /* Mask Parameter: LimitedCounter_uplimit_p
                                      * Referenced by: '<S34>/FixPt Switch'
                                      */
  uint16_T LimitedCounter_uplimit_k; /* Mask Parameter: LimitedCounter_uplimit_k
                                      * Referenced by: '<S37>/FixPt Switch'
                                      */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S18>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S18>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S14>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S15>/zero'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S16>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S17>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S10>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S10>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S10>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S10>/Step: end_time'
                                        */
  real_T UnitDelay_InitialCondition_j; /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T firstpoint_Value[3];        /* Expression: [pos(1,1) pos(1,2) pos(1,3)]
                                      * Referenced by: '<S7>/first point'
                                      */
  real_T UnitDelay_InitialCondition_g; /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay'
                                        */
  real_T EncoderOffsets_Bias[6];       /* Expression: [0 659 914 0 -1000 0]
                                        * Referenced by: '<S6>/Encoder Offsets'
                                        */
  real_T Bias1_Bias[3];                /* Expression: [0 -659 -910]
                                        * Referenced by: '<S11>/Bias1'
                                        */
  real_T Encoder_Gain;                 /* Expression: 2*pi/2048
                                        * Referenced by: '<S11>/Encoder'
                                        */
  real_T GearRatio_Gain[3];            /* Expression: 1./[7.461 -7.519 7.529]
                                        * Referenced by: '<S11>/Gear Ratio'
                                        */
  real_T ConverttoPositiveRotationConven[3];/* Expression: [1 -1 -1]
                                             * Referenced by: '<S6>/Convert to Positive Rotation Convension Used in Kinematics1'
                                             */
  real_T JointOffsets_Bias[3];         /* Expression: [0 0 pi()/2]
                                        * Referenced by: '<S6>/Joint Offsets'
                                        */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: 0.0
                                          * Referenced by: '<S25>/FixPt Unit Delay1'
                                          */
  real_T speed_Value;                  /* Expression: .1
                                        * Referenced by: '<S7>/speed'
                                        */
  real_T Constant2_Value;              /* Expression: qc_get_step_size
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Constant2_Value_h;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Saturation1_UpperSat[3];      /* Expression: [.1 .1 .025]
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation1_LowerSat[3];      /* Expression: [.02 .02 0]
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation2_UpperSat[3];      /* Expression: [2 2 3]
                                        * Referenced by: '<S6>/Saturation2'
                                        */
  real_T Saturation2_LowerSat[3];      /* Expression: [0 0 0]
                                        * Referenced by: '<S6>/Saturation2'
                                        */
  real_T Saturation_UpperSat[3];       /* Expression: [2 2 1]
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat[3];       /* Expression: [0 0 0]
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S20>/Integrator2'
                                        */
  real_T ConverttoPositiveRotationConv_g[3];/* Expression: [-1 -1 -1]
                                             * Referenced by: '<S6>/Convert to Positive Rotation Convension Used in Kinematics2'
                                             */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S20>/x0'
                                        */
  int32_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<Root>/Constant4'
                                        */
  uint16_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S31>/Constant'
                                        */
  uint16_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S34>/Constant'
                                        */
  uint16_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S37>/Constant'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S30>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S29>/Output'
                                   */
  uint16_T FixPtConstant_Value_m;   /* Computed Parameter: FixPtConstant_Value_m
                                     * Referenced by: '<S33>/FixPt Constant'
                                     */
  uint16_T Output_InitialCondition_p;
                                /* Computed Parameter: Output_InitialCondition_p
                                 * Referenced by: '<S32>/Output'
                                 */
  uint16_T FixPtConstant_Value_c;   /* Computed Parameter: FixPtConstant_Value_c
                                     * Referenced by: '<S36>/FixPt Constant'
                                     */
  uint16_T Output_InitialCondition_b;
                                /* Computed Parameter: Output_InitialCondition_b
                                 * Referenced by: '<S35>/Output'
                                 */
  uint8_T FixPtUnitDelay2_InitialConditio;
                          /* Computed Parameter: FixPtUnitDelay2_InitialConditio
                           * Referenced by: '<S25>/FixPt Unit Delay2'
                           */
  uint8_T FixPtConstant_Value_l;    /* Computed Parameter: FixPtConstant_Value_l
                                     * Referenced by: '<S25>/FixPt Constant'
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
 * '<S1>'   : 'Teach_Pendant_Task_Space/1 to out 1st signal'
 * '<S2>'   : 'Teach_Pendant_Task_Space/Forward Kinematics'
 * '<S3>'   : 'Teach_Pendant_Task_Space/Inverse Kinematics'
 * '<S4>'   : 'Teach_Pendant_Task_Space/MATLAB Function'
 * '<S5>'   : 'Teach_Pendant_Task_Space/MATLAB Function1'
 * '<S6>'   : 'Teach_Pendant_Task_Space/PID Control'
 * '<S7>'   : 'Teach_Pendant_Task_Space/Trajectory Planning'
 * '<S8>'   : 'Teach_Pendant_Task_Space/cost function'
 * '<S9>'   : 'Teach_Pendant_Task_Space/pid auto tuner'
 * '<S10>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal'
 * '<S11>'  : 'Teach_Pendant_Task_Space/PID Control/Encoders to Joints q1, q2, q3'
 * '<S12>'  : 'Teach_Pendant_Task_Space/PID Control/PIV Controller'
 * '<S13>'  : 'Teach_Pendant_Task_Space/PID Control/Tool Offset'
 * '<S14>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Enabled Moving Average'
 * '<S15>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Switch Case Action Subsystem'
 * '<S16>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Switch Case Action Subsystem1'
 * '<S17>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Switch Case Action Subsystem2'
 * '<S18>'  : 'Teach_Pendant_Task_Space/PID Control/Bias Removal/Enabled Moving Average/Increment'
 * '<S19>'  : 'Teach_Pendant_Task_Space/PID Control/Encoders to Joints q1, q2, q3/Embedded MATLAB Function'
 * '<S20>'  : 'Teach_Pendant_Task_Space/PID Control/PIV Controller/Second-Order Low-Pass Filter'
 * '<S21>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Forward Kinematics'
 * '<S22>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Linear Trajectory'
 * '<S23>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject'
 * '<S24>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Linear Trajectory/Embedded MATLAB Function'
 * '<S25>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Linear Trajectory/Unit Delay External IC'
 * '<S26>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 1'
 * '<S27>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 2'
 * '<S28>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 3'
 * '<S29>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 1/LimitedCounter'
 * '<S30>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 1/LimitedCounter/Increment Real World'
 * '<S31>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 1/LimitedCounter/Wrap To Zero'
 * '<S32>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 2/LimitedCounter'
 * '<S33>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 2/LimitedCounter/Increment Real World'
 * '<S34>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 2/LimitedCounter/Wrap To Zero'
 * '<S35>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 3/LimitedCounter'
 * '<S36>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 3/LimitedCounter/Increment Real World'
 * '<S37>'  : 'Teach_Pendant_Task_Space/Trajectory Planning/Traject/Trajectory Joint 3/LimitedCounter/Wrap To Zero'
 */
#endif                              /* RTW_HEADER_Teach_Pendant_Task_Space_h_ */
