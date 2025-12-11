/*
 * Teach_Pendant_Task_Space_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_phantom_properties)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_phantom_properties"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Teach_Pendant_Task_Space_B.UnitDelay[0]), 0, 0, 89 },

  { (char_T *)(&Teach_Pendant_Task_Space_B.Phantom_o1), 6, 0, 2 },

  { (char_T *)(&Teach_Pendant_Task_Space_B.reached), 8, 0, 1 }
  ,

  { (char_T *)(&Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[0]), 0, 0, 407 },

  { (char_T *)(&Teach_Pendant_Task_Space_DW.Phantom_Phantom), 14, 0, 1 },

  { (char_T *)(&Teach_Pendant_Task_Space_DW.Scope_PWORK.LoggedData[0]), 11, 0, 5
  },

  { (char_T *)(&Teach_Pendant_Task_Space_DW.method), 7, 0, 629 },

  { (char_T *)(&Teach_Pendant_Task_Space_DW.Integrator1_IWORK), 10, 0, 1 },

  { (char_T *)(&Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE), 3, 0, 1 },

  { (char_T *)(&Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC), 2, 0, 6 },

  { (char_T *)(&Teach_Pendant_Task_Space_DW.initialized_not_empty), 8, 0, 6 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Teach_Pendant_Task_Space_P.starting_point[0]), 0, 0, 17578 },

  { (char_T *)(&Teach_Pendant_Task_Space_P.FixPtUnitDelay2_InitialConditio), 3,
    0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] Teach_Pendant_Task_Space_dt.h */
