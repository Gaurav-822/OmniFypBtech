/*
 * Teach_Points_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Teach_Points".
 *
 * Model version              : 1.100
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Dec 10 18:55:46 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Teach_Points.h"
#include "Teach_Points_private.h"

/* Block parameters (default storage) */
P_Teach_Points_T Teach_Points_P = {
  /* Expression: [0 659 914 0 -1000 0]
   * Referenced by: '<Root>/Encoder Offsets'
   */
  { 0.0, 659.0, 914.0, 0.0, -1000.0, 0.0 },

  /* Expression: [0 -659 -910]
   * Referenced by: '<S1>/Bias1'
   */
  { 0.0, -659.0, -910.0 },

  /* Expression: 2*pi/2048
   * Referenced by: '<S1>/Encoder'
   */
  0.0030679615757712823,

  /* Expression: 1./[7.461 -7.519 7.529]
   * Referenced by: '<S1>/Gear Ratio'
   */
  { 0.13403029084573112, -0.13299640909695437, 0.13281976358082082 },

  /* Expression: [1 -1 -1]
   * Referenced by: '<Root>/Convert to Positive Rotation Convension'
   */
  { 1.0, -1.0, -1.0 },

  /* Expression: [0 0 pi()/2]
   * Referenced by: '<Root>/Joint Offsets'
   */
  { 0.0, 0.0, 1.5707963267948966 }
};
