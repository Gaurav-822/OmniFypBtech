/*
 * Teach_Pendant_Task_Space.c
 *
 * Code generation for model "Teach_Pendant_Task_Space".
 *
 * Model version              : 1.464
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Feb 25 17:34:48 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Teach_Pendant_Task_Space.h"
#include "Teach_Pendant_Task_Space_private.h"
#include "Teach_Pendant_Task_Space_dt.h"

/* Block signals (default storage) */
B_Teach_Pendant_Task_Space_T Teach_Pendant_Task_Space_B;

/* Continuous states */
X_Teach_Pendant_Task_Space_T Teach_Pendant_Task_Space_X;

/* Block states (default storage) */
DW_Teach_Pendant_Task_Space_T Teach_Pendant_Task_Space_DW;

/* Real-time model */
RT_MODEL_Teach_Pendant_Task_S_T Teach_Pendant_Task_Space_M_;
RT_MODEL_Teach_Pendant_Task_S_T *const Teach_Pendant_Task_Space_M =
  &Teach_Pendant_Task_Space_M_;

/* Forward declaration for local functions */
static real_T Teach_Pendan_eml_rand_mt19937ar(uint32_T state[625]);
static real_T Teach_Pendant_eml_rand_mcg16807(uint32_T *state);
static void Teach_Pendant_Task_Space_rand(real_T r[120]);
static void Teach_Pendant_Task_Space_rand_l(real_T r[6]);

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Teach_Pendant_Task_Space_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<Root>/pid auto tuner' */
static real_T Teach_Pendan_eml_rand_mt19937ar(uint32_T state[625])
{
  real_T r;
  uint32_T u[2];
  uint32_T mti;
  uint32_T y;
  int32_T kk;
  int32_T k;
  boolean_T b_isvalid;
  int32_T exitg1;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    for (k = 0; k < 2; k++) {
      mti = state[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (state[kk + 1] & 2147483647U) | (state[kk] & 2147483648U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          state[kk] = state[kk + 397] ^ y;
        }

        for (kk = 0; kk < 396; kk++) {
          y = (state[kk + 227] & 2147483648U) | (state[kk + 228] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          state[kk + 227] = state[kk] ^ y;
        }

        y = (state[623] & 2147483648U) | (state[0] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        state[623] = state[396] ^ y;
        mti = 1U;
      }

      y = state[(int32_T)mti - 1];
      state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      u[k] = y >> 18U ^ y;
    }

    r = ((real_T)(u[0] >> 5U) * 6.7108864E+7 + (real_T)(u[1] >> 6U)) *
      1.1102230246251565E-16;
    if (r == 0.0) {
      if ((state[624] >= 1U) && (state[624] < 625U)) {
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (state[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      } else {
        b_isvalid = false;
      }

      if (!b_isvalid) {
        mti = 5489U;
        state[0] = 5489U;
        for (k = 0; k < 623; k++) {
          mti = ((mti >> 30U ^ mti) * 1812433253U + k) + 1U;
          state[k + 1] = mti;
        }

        state[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

/* Function for MATLAB Function: '<Root>/pid auto tuner' */
static real_T Teach_Pendant_eml_rand_mcg16807(uint32_T *state)
{
  int32_T hi;
  uint32_T test1;
  uint32_T test2;
  hi = (int32_T)(*state / 127773U);
  test1 = (*state - hi * 127773U) * 16807U;
  test2 = 2836U * hi;
  if (test1 < test2) {
    test1 = ~(test2 - test1) & 2147483647U;
  } else {
    test1 -= test2;
  }

  *state = test1;
  return (real_T)test1 * 4.6566128752457969E-10;
}

/* Function for MATLAB Function: '<Root>/pid auto tuner' */
static void Teach_Pendant_Task_Space_rand(real_T r[120])
{
  uint32_T b_r;
  int32_T mti;
  uint32_T e;
  if (Teach_Pendant_Task_Space_DW.method == 4U) {
    for (mti = 0; mti < 120; mti++) {
      r[mti] = Teach_Pendant_eml_rand_mcg16807
        (&Teach_Pendant_Task_Space_DW.state);
    }
  } else if (Teach_Pendant_Task_Space_DW.method == 5U) {
    for (mti = 0; mti < 120; mti++) {
      b_r = 69069U * Teach_Pendant_Task_Space_DW.state_g[0] + 1234567U;
      e = Teach_Pendant_Task_Space_DW.state_g[1] << 13 ^
        Teach_Pendant_Task_Space_DW.state_g[1];
      e ^= e >> 17;
      e ^= e << 5;
      Teach_Pendant_Task_Space_DW.state_g[0] = b_r;
      Teach_Pendant_Task_Space_DW.state_g[1] = e;
      r[mti] = (real_T)(b_r + e) * 2.328306436538696E-10;
    }
  } else {
    if (!Teach_Pendant_Task_Space_DW.state_not_empty) {
      memset(&Teach_Pendant_Task_Space_DW.state_k[0], 0, 625U * sizeof(uint32_T));
      b_r = 5489U;
      Teach_Pendant_Task_Space_DW.state_k[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r >> 30U ^ b_r) * 1812433253U + mti) + 1U;
        Teach_Pendant_Task_Space_DW.state_k[mti + 1] = b_r;
      }

      Teach_Pendant_Task_Space_DW.state_k[624] = 624U;
      Teach_Pendant_Task_Space_DW.state_not_empty = true;
    }

    for (mti = 0; mti < 120; mti++) {
      r[mti] = Teach_Pendan_eml_rand_mt19937ar
        (Teach_Pendant_Task_Space_DW.state_k);
    }
  }
}

/* Function for MATLAB Function: '<Root>/pid auto tuner' */
static void Teach_Pendant_Task_Space_rand_l(real_T r[6])
{
  uint32_T b_r;
  int32_T mti;
  uint32_T e;
  if (Teach_Pendant_Task_Space_DW.method == 4U) {
    for (mti = 0; mti < 6; mti++) {
      r[mti] = Teach_Pendant_eml_rand_mcg16807
        (&Teach_Pendant_Task_Space_DW.state);
    }
  } else if (Teach_Pendant_Task_Space_DW.method == 5U) {
    for (mti = 0; mti < 6; mti++) {
      b_r = 69069U * Teach_Pendant_Task_Space_DW.state_g[0] + 1234567U;
      e = Teach_Pendant_Task_Space_DW.state_g[1] << 13 ^
        Teach_Pendant_Task_Space_DW.state_g[1];
      e ^= e >> 17;
      e ^= e << 5;
      Teach_Pendant_Task_Space_DW.state_g[0] = b_r;
      Teach_Pendant_Task_Space_DW.state_g[1] = e;
      r[mti] = (real_T)(b_r + e) * 2.328306436538696E-10;
    }
  } else {
    if (!Teach_Pendant_Task_Space_DW.state_not_empty) {
      memset(&Teach_Pendant_Task_Space_DW.state_k[0], 0, 625U * sizeof(uint32_T));
      b_r = 5489U;
      Teach_Pendant_Task_Space_DW.state_k[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r >> 30U ^ b_r) * 1812433253U + mti) + 1U;
        Teach_Pendant_Task_Space_DW.state_k[mti + 1] = b_r;
      }

      Teach_Pendant_Task_Space_DW.state_k[624] = 624U;
      Teach_Pendant_Task_Space_DW.state_not_empty = true;
    }

    for (mti = 0; mti < 6; mti++) {
      r[mti] = Teach_Pendan_eml_rand_mt19937ar
        (Teach_Pendant_Task_Space_DW.state_k);
    }
  }
}

/* Model step function */
void Teach_Pendant_Task_Space_step(void)
{
  real_T tool[12];
  int32_T iy;
  int32_T j;
  int8_T catArgs_f2[4];
  real_T T_tool[16];
  real_T r2[6];
  boolean_T trigger;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T x;
  real_T rtb_GearRatio[3];
  real_T rtb_q[3];
  boolean_T rtb_LogicalOperator;
  real_T rtb_EncoderOffsets[6];
  int8_T rtAction;
  real_T rtb_Count;
  real_T rtb_tool_offset[16];
  uint16_T rtb_FixPtSum1;
  uint16_T rtb_FixPtSwitch;
  uint16_T rtb_FixPtSwitch_h;
  int8_T T_tool_tmp[16];
  int8_T T_tool_tmp_0[4];
  real_T T_tool_tmp_1;
  int8_T T_tool_tmp_2[16];
  int32_T i;
  real_T d[9];
  real_T t_0[9];
  real_T d_0[9];
  real_T scale_0[16];
  real_T scale_1[16];
  real_T scale_2[16];
  real_T T_tool_tmp_3[16];
  int32_T scale_tmp;
  int32_T scale_tmp_0;
  static const int8_T c[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T b[3] = { 0.039, 0.0, 0.0 };

  static const int8_T varargin_2[4] = { 0, 0, 0, 1 };

  static const int8_T b_0[4] = { 0, 0, 1, 0 };

  static const int8_T A_T_z[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    1 };

  static const real_T A_T_x[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.132, 0.0, 0.0, 1.0 };

  static const real_T A_R_x[16] = { 1.0, 0.0, 0.0, 0.0, 0.0,
    6.123233995736766E-17, -1.0, 0.0, 0.0, 1.0, 6.123233995736766E-17, 0.0, 0.0,
    0.0, 0.0, 1.0 };

  boolean_T exitg1;
  if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {
    /* set solver stop time */
    if (!(Teach_Pendant_Task_Space_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Teach_Pendant_Task_Space_M->solverInfo,
                            ((Teach_Pendant_Task_Space_M->Timing.clockTickH0 + 1)
        * Teach_Pendant_Task_Space_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Teach_Pendant_Task_Space_M->solverInfo,
                            ((Teach_Pendant_Task_Space_M->Timing.clockTick0 + 1)
        * Teach_Pendant_Task_Space_M->Timing.stepSize0 +
        Teach_Pendant_Task_Space_M->Timing.clockTickH0 *
        Teach_Pendant_Task_Space_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Teach_Pendant_Task_Space_M)) {
    Teach_Pendant_Task_Space_M->Timing.t[0] = rtsiGetT
      (&Teach_Pendant_Task_Space_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Teach_Pendant_Task_Space_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem2_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC);
  if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {
    /* UnitDelay: '<S6>/Unit Delay' */
    /* MATLAB Function 'MATLAB Function1': '<S4>:1' */
    /* '<S4>:1:5' */
    /* '<S4>:1:6' */
    /* '<S4>:1:7' */
    Teach_Pendant_Task_Space_B.UnitDelay[0] =
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[0];
    Teach_Pendant_Task_Space_B.UnitDelay[1] =
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[1];
    Teach_Pendant_Task_Space_B.UnitDelay[2] =
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[2];

    /* S-Function (phantom_block): '<S6>/Phantom' */

    /* S-Function Block: Teach_Pendant_Task_Space/PID Control/Phantom (phantom_block) */
    {
      t_error result = 0;
      result = phantom_read(Teach_Pendant_Task_Space_DW.Phantom_Phantom,
                            &Teach_Pendant_Task_Space_B.Phantom_o1,
                            &Teach_Pendant_Task_Space_B.Phantom_o2[0], NULL,
                            NULL, &Teach_Pendant_Task_Space_B.Phantom_o3);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Teach_Pendant_Task_Space_M, _rt_error_message);
      }

      result = phantom_write(Teach_Pendant_Task_Space_DW.Phantom_Phantom,
        &Teach_Pendant_Task_Space_B.UnitDelay[0], NULL);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Teach_Pendant_Task_Space_M, _rt_error_message);
      }
    }

    /* Bias: '<S6>/Encoder Offsets' */
    for (i = 0; i < 6; i++) {
      rtb_EncoderOffsets[i] = Teach_Pendant_Task_Space_B.Phantom_o2[i] +
        Teach_Pendant_Task_Space_P.EncoderOffsets_Bias[i];
    }

    /* End of Bias: '<S6>/Encoder Offsets' */

    /* Gain: '<S11>/Gear Ratio' incorporates:
     *  Bias: '<S11>/Bias1'
     *  Gain: '<S11>/Encoder'
     */
    rtb_GearRatio[1] = (rtb_EncoderOffsets[1] +
                        Teach_Pendant_Task_Space_P.Bias1_Bias[1]) *
      Teach_Pendant_Task_Space_P.Encoder_Gain *
      Teach_Pendant_Task_Space_P.GearRatio_Gain[1];

    /* Bias: '<S6>/Joint Offsets' incorporates:
     *  Bias: '<S11>/Bias1'
     *  Gain: '<S11>/Encoder'
     *  Gain: '<S11>/Gear Ratio'
     *  Gain: '<S6>/Convert to Positive Rotation Convension Used in Kinematics1'
     *  MATLAB Function: '<S11>/Embedded MATLAB Function'
     */
    /* MATLAB Function 'PID Control/Encoders to Joints q1, q2, q3/Embedded MATLAB Function': '<S19>:1' */
    /* '<S19>:1:3' */
    /* '<S19>:1:4' */
    /* '<S19>:1:5' */
    Teach_Pendant_Task_Space_B.JointOffsets[0] = (rtb_EncoderOffsets[0] +
      Teach_Pendant_Task_Space_P.Bias1_Bias[0]) *
      Teach_Pendant_Task_Space_P.Encoder_Gain *
      Teach_Pendant_Task_Space_P.GearRatio_Gain[0] *
      Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConven[0] +
      Teach_Pendant_Task_Space_P.JointOffsets_Bias[0];
    Teach_Pendant_Task_Space_B.JointOffsets[1] =
      Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConven[1] *
      rtb_GearRatio[1] + Teach_Pendant_Task_Space_P.JointOffsets_Bias[1];
    Teach_Pendant_Task_Space_B.JointOffsets[2] = (((rtb_EncoderOffsets[2] +
      Teach_Pendant_Task_Space_P.Bias1_Bias[2]) *
      Teach_Pendant_Task_Space_P.Encoder_Gain *
      Teach_Pendant_Task_Space_P.GearRatio_Gain[2] - rtb_GearRatio[1]) -
      1.5707963267948966) *
      Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConven[2] +
      Teach_Pendant_Task_Space_P.JointOffsets_Bias[2];

    /* Outputs for Atomic SubSystem: '<S6>/Bias Removal' */
    /* Step: '<S10>/Step: start_time' incorporates:
     *  Step: '<S10>/Step: end_time'
     */
    rtb_Count = (((Teach_Pendant_Task_Space_M->Timing.clockTick1+
                   Teach_Pendant_Task_Space_M->Timing.clockTickH1* 4294967296.0))
                 * 0.001);
    if (rtb_Count < Teach_Pendant_Task_Space_P.BiasRemoval_start_time) {
      scale = Teach_Pendant_Task_Space_P.Stepstart_time_Y0;
    } else {
      scale = Teach_Pendant_Task_Space_P.Stepstart_time_YFinal;
    }

    /* End of Step: '<S10>/Step: start_time' */

    /* Step: '<S10>/Step: end_time' */
    if (rtb_Count < Teach_Pendant_Task_Space_P.BiasRemoval_end_time) {
      rtb_Count = Teach_Pendant_Task_Space_P.Stepend_time_Y0;
    } else {
      rtb_Count = Teach_Pendant_Task_Space_P.Stepend_time_YFinal;
    }

    /* Outputs for Enabled SubSystem: '<S10>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    /* Logic: '<S10>/Logical Operator' incorporates:
     *  Logic: '<S10>/Logical Operator1'
     */
    if ((scale != 0.0) && (!(rtb_Count != 0.0))) {
      if (!Teach_Pendant_Task_Space_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
        Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h =
          Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[0] =
          Teach_Pendant_Task_Space_P.Sumk1n1xk_InitialCondition;
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[1] =
          Teach_Pendant_Task_Space_P.Sumk1n1xk_InitialCondition;
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[2] =
          Teach_Pendant_Task_Space_P.Sumk1n1xk_InitialCondition;
        Teach_Pendant_Task_Space_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S18>/Count' incorporates:
       *  Constant: '<S18>/unity'
       *  UnitDelay: '<S18>/Unit Delay'
       */
      rtb_Count = Teach_Pendant_Task_Space_P.unity_Value +
        Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h;

      /* Update for UnitDelay: '<S18>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h = rtb_Count;

      /* Sum: '<S14>/Sum' incorporates:
       *  UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )'
       */
      x = Teach_Pendant_Task_Space_B.JointOffsets[0] +
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[0];

      /* Product: '<S14>/div' */
      Teach_Pendant_Task_Space_B.div[0] = x / rtb_Count;

      /* Update for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
      Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[0] = x;

      /* Sum: '<S14>/Sum' incorporates:
       *  UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )'
       */
      x = Teach_Pendant_Task_Space_B.JointOffsets[1] +
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[1];

      /* Product: '<S14>/div' */
      Teach_Pendant_Task_Space_B.div[1] = x / rtb_Count;

      /* Update for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
      Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[1] = x;

      /* Sum: '<S14>/Sum' incorporates:
       *  UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )'
       */
      x = Teach_Pendant_Task_Space_B.JointOffsets[2] +
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[2];

      /* Product: '<S14>/div' */
      Teach_Pendant_Task_Space_B.div[2] = x / rtb_Count;

      /* Update for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
      Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[2] = x;
      srUpdateBC(Teach_Pendant_Task_Space_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      Teach_Pendant_Task_Space_DW.EnabledMovingAverage_MODE = false;
    }

    /* End of Logic: '<S10>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S10>/Enabled Moving Average' */

    /* SwitchCase: '<S10>/Switch Case' */
    rtAction = -1;
    if (Teach_Pendant_Task_Space_P.BiasRemoval_switch_id < 0.0) {
      rtb_Count = ceil(Teach_Pendant_Task_Space_P.BiasRemoval_switch_id);
    } else {
      rtb_Count = floor(Teach_Pendant_Task_Space_P.BiasRemoval_switch_id);
    }

    if (rtIsNaN(rtb_Count) || rtIsInf(rtb_Count)) {
      rtb_Count = 0.0;
    } else {
      rtb_Count = fmod(rtb_Count, 4.294967296E+9);
    }

    switch (rtb_Count < 0.0 ? -(int32_T)(uint32_T)-rtb_Count : (int32_T)
            (uint32_T)rtb_Count) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     case 3:
      rtAction = 2;
      break;
    }

    Teach_Pendant_Task_Space_DW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S10>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      srUpdateBC(Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S10>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S10>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      srUpdateBC(Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S10>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S10>/Switch Case' */
    /* End of Outputs for SubSystem: '<S6>/Bias Removal' */

    /* MATLAB Function: '<S6>/Tool Offset' */
    /* MATLAB Function 'PID Control/Tool Offset': '<S13>:1' */
    /* '<S13>:1:21' */
    /* '<S13>:1:20' */
    /* '<S13>:1:26' */
    /* '<S13>:1:32' */
    /* '<S13>:1:33' */
    /* '<S13>:1:4' */
    /* '<S13>:1:5' */
    /* '<S13>:1:6' */
    /* '<S13>:1:10' */
    /* '<S13>:1:11' */
    /* '<S13>:1:12' */
    rtb_GearRatio[0] = -((rtb_EncoderOffsets[3] + -2048.0) *
                         0.0012783693402196514);
    rtb_GearRatio[1] = (rtb_EncoderOffsets[4] + -2654.0) * 0.0015339807878856412
      + 2.4434609527920612;

    /* '<S13>:1:15' */
    /* '<S13>:1:16' */
    /* '<S13>:1:20' */
    /* '<S13>:1:21' */
    /* '<S13>:1:22' */
    /* '<S13>:1:26' */
    rtb_Count = sin(rtb_GearRatio[0]);
    scale = cos(rtb_GearRatio[0]);
    absxk = sin(rtb_GearRatio[1]);
    t = cos(rtb_GearRatio[1]);
    d[1] = 0.0;
    d[4] = scale;
    d[7] = -rtb_Count;
    d[2] = 0.0;
    d[5] = rtb_Count;
    d[8] = scale;
    t_0[0] = t;
    t_0[3] = -absxk;
    t_0[6] = 0.0;
    t_0[1] = absxk;
    t_0[4] = t;
    t_0[7] = 0.0;
    d[0] = 1.0;
    t_0[2] = 0.0;
    d[3] = 0.0;
    t_0[5] = 0.0;
    d[6] = 0.0;
    t_0[8] = 1.0;
    for (i = 0; i < 3; i++) {
      rtb_GearRatio[i] = 0.0;
      for (j = 0; j < 3; j++) {
        iy = i + 3 * j;
        d_0[iy] = 0.0;
        d_0[iy] += t_0[3 * j] * d[i];
        d_0[iy] += t_0[3 * j + 1] * d[i + 3];
        d_0[iy] += t_0[3 * j + 2] * d[i + 6];
        rtb_GearRatio[i] += d_0[iy] * b[j];
      }
    }

    /* '<S13>:1:32' */
    iy = -1;
    for (j = 0; j < 9; j++) {
      iy++;
      tool[iy] = c[j];
    }

    iy++;
    tool[iy] = rtb_GearRatio[0];
    iy++;
    tool[iy] = rtb_GearRatio[1];
    iy++;
    tool[iy] = rtb_GearRatio[2];

    /* Switch: '<S25>/Init' incorporates:
     *  UnitDelay: '<S25>/FixPt Unit Delay2'
     */
    /* '<S13>:1:33' */
    /* MATLAB Function 'Trajectory Planning/Forward Kinematics': '<S21>:1' */
    /* '<S21>:1:11' */
    /* '<S21>:1:32' */
    /* '<S21>:1:33' */
    /* '<S21>:1:35' */
    /* '<S21>:1:36' */
    /* '<S21>:1:30' */
    /* '<S21>:1:42' */
    /* '<S21>:1:47' */
    /* '<S21>:1:52' */
    /* '<S21>:1:12' */
    /* '<S21>:1:32' */
    /* '<S21>:1:33' */
    /* '<S21>:1:35' */
    /* '<S21>:1:36' */
    /* '<S21>:1:30' */
    /* '<S21>:1:42' */
    /* '<S21>:1:47' */
    /* '<S21>:1:52' */
    /* '<S21>:1:13' */
    /* '<S21>:1:32' */
    /* '<S21>:1:33' */
    /* '<S21>:1:35' */
    /* '<S21>:1:36' */
    /* '<S21>:1:30' */
    /* '<S21>:1:42' */
    /* '<S21>:1:47' */
    /* '<S21>:1:52' */
    /* '<S21>:1:17' */
    /* '<S21>:1:18' */
    /* '<S21>:1:21' */
    /* '<S21>:1:22' */
    /* '<S21>:1:23' */
    rtb_LogicalOperator = (Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE !=
      0);

    /* MATLAB Function: '<S7>/Forward Kinematics' */
    rtb_Count = cos(Teach_Pendant_Task_Space_B.div[0]);
    scale_0[0] = rtb_Count;
    scale = sin(Teach_Pendant_Task_Space_B.div[0]);
    scale_0[4] = -scale;
    scale_0[8] = 0.0;
    scale_0[12] = 0.0;
    scale_0[1] = scale;
    scale_0[5] = rtb_Count;
    scale_0[9] = 0.0;
    scale_0[13] = 0.0;
    for (j = 0; j < 4; j++) {
      /* MATLAB Function: '<S6>/Tool Offset' incorporates:
       *  MATLAB Function: '<S7>/Forward Kinematics'
       */
      i = j << 2;
      rtb_tool_offset[i] = tool[3 * j];
      rtb_tool_offset[i + 1] = tool[3 * j + 1];
      iy = i + 2;
      rtb_tool_offset[iy] = tool[3 * j + 2];
      i += 3;
      rtb_tool_offset[i] = varargin_2[j];

      /* MATLAB Function: '<S7>/Forward Kinematics' */
      scale_0[iy] = b_0[j];
      scale_0[i] = varargin_2[j];
    }

    /* MATLAB Function: '<S7>/Forward Kinematics' */
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        T_tool[scale_tmp] = 0.0;
        T_tool[scale_tmp] += (real_T)A_T_z[iy] * scale_0[i];
        T_tool[scale_tmp] += (real_T)A_T_z[iy + 1] * scale_0[i + 4];
        T_tool[scale_tmp] += (real_T)A_T_z[iy + 2] * scale_0[i + 8];
        T_tool[scale_tmp] += (real_T)A_T_z[iy + 3] * scale_0[i + 12];
      }

      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        T_tool_tmp_3[scale_tmp] = 0.0;
        T_tool_tmp_3[scale_tmp] += (real_T)A_T_z[iy] * T_tool[i];
        T_tool_tmp_3[scale_tmp] += (real_T)A_T_z[iy + 1] * T_tool[i + 4];
        T_tool_tmp_3[scale_tmp] += (real_T)A_T_z[iy + 2] * T_tool[i + 8];
        T_tool_tmp_3[scale_tmp] += (real_T)A_T_z[iy + 3] * T_tool[i + 12];
      }
    }

    rtb_Count = cos(Teach_Pendant_Task_Space_B.div[1]);
    scale_0[0] = rtb_Count;
    scale = sin(Teach_Pendant_Task_Space_B.div[1]);
    scale_0[4] = -scale;
    scale_0[8] = 0.0;
    scale_0[12] = 0.0;
    scale_0[1] = scale;
    scale_0[5] = rtb_Count;
    scale_0[9] = 0.0;
    scale_0[13] = 0.0;
    scale_0[2] = 0.0;
    scale_0[3] = 0.0;
    scale_0[6] = 0.0;
    scale_0[7] = 0.0;
    scale_0[10] = 1.0;
    scale_0[11] = 0.0;
    scale_0[14] = 0.0;
    scale_0[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        T_tool[scale_tmp] = 0.0;
        T_tool[scale_tmp] += (real_T)A_T_z[iy] * scale_0[i];
        T_tool[scale_tmp] += (real_T)A_T_z[iy + 1] * scale_0[i + 4];
        T_tool[scale_tmp] += (real_T)A_T_z[iy + 2] * scale_0[i + 8];
        T_tool[scale_tmp] += (real_T)A_T_z[iy + 3] * scale_0[i + 12];
      }

      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_1[scale_tmp] = 0.0;
        scale_1[scale_tmp] += A_T_x[iy] * T_tool[i];
        scale_1[scale_tmp] += A_T_x[iy + 1] * T_tool[i + 4];
        scale_1[scale_tmp] += A_T_x[iy + 2] * T_tool[i + 8];
        scale_1[scale_tmp] += A_T_x[iy + 3] * T_tool[i + 12];
      }
    }

    rtb_Count = cos(Teach_Pendant_Task_Space_B.div[2] - 1.5707963267948966);
    scale_2[0] = rtb_Count;
    scale = sin(Teach_Pendant_Task_Space_B.div[2] - 1.5707963267948966);
    scale_2[4] = -scale;
    scale_2[8] = 0.0;
    scale_2[12] = 0.0;
    scale_2[1] = scale;
    scale_2[5] = rtb_Count;
    scale_2[9] = 0.0;
    scale_2[13] = 0.0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_0[scale_tmp] = 0.0;
        T_tool[scale_tmp] = 0.0;
        scale_0[scale_tmp] += A_R_x[iy] * T_tool_tmp_3[i];
        T_tool[scale_tmp] += (real_T)A_T_z[iy] * scale_1[i];
        scale_tmp_0 = iy + 1;
        scale_0[scale_tmp] += A_R_x[scale_tmp_0] * T_tool_tmp_3[i + 4];
        T_tool[scale_tmp] += (real_T)A_T_z[scale_tmp_0] * scale_1[i + 4];
        scale_tmp_0 = iy + 2;
        scale_0[scale_tmp] += A_R_x[scale_tmp_0] * T_tool_tmp_3[i + 8];
        T_tool[scale_tmp] += (real_T)A_T_z[scale_tmp_0] * scale_1[i + 8];
        iy += 3;
        scale_0[scale_tmp] += A_R_x[iy] * T_tool_tmp_3[i + 12];
        T_tool[scale_tmp] += (real_T)A_T_z[iy] * scale_1[i + 12];
      }

      j = i << 2;
      scale_2[j + 2] = b_0[i];
      scale_2[j + 3] = varargin_2[i];
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        T_tool_tmp_3[scale_tmp] = 0.0;
        T_tool_tmp_3[scale_tmp] += (real_T)A_T_z[iy] * scale_2[i];
        T_tool_tmp_3[scale_tmp] += (real_T)A_T_z[iy + 1] * scale_2[i + 4];
        T_tool_tmp_3[scale_tmp] += (real_T)A_T_z[iy + 2] * scale_2[i + 8];
        T_tool_tmp_3[scale_tmp] += (real_T)A_T_z[iy + 3] * scale_2[i + 12];
      }

      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_1[scale_tmp] = 0.0;
        scale_1[scale_tmp] += A_T_x[iy] * T_tool_tmp_3[i];
        scale_1[scale_tmp] += A_T_x[iy + 1] * T_tool_tmp_3[i + 4];
        scale_1[scale_tmp] += A_T_x[iy + 2] * T_tool_tmp_3[i + 8];
        scale_1[scale_tmp] += A_T_x[iy + 3] * T_tool_tmp_3[i + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = i << 2;
        scale_tmp = j + iy;
        T_tool_tmp_3[scale_tmp] = 0.0;
        scale_2[scale_tmp] = 0.0;
        T_tool_tmp_3[scale_tmp] += T_tool[iy] * scale_0[j];
        scale_2[scale_tmp] += (real_T)A_T_z[iy] * scale_1[j];
        scale_tmp_0 = iy + 1;
        T_tool_tmp_3[scale_tmp] += T_tool[scale_tmp_0] * scale_0[j + 4];
        scale_2[scale_tmp] += (real_T)A_T_z[scale_tmp_0] * scale_1[j + 4];
        scale_tmp_0 = iy + 2;
        T_tool_tmp_3[scale_tmp] += T_tool[scale_tmp_0] * scale_0[j + 8];
        scale_2[scale_tmp] += (real_T)A_T_z[scale_tmp_0] * scale_1[j + 8];
        iy += 3;
        T_tool_tmp_3[scale_tmp] += T_tool[iy] * scale_0[j + 12];
        scale_2[scale_tmp] += (real_T)A_T_z[iy] * scale_1[j + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_0[scale_tmp] = 0.0;
        scale_0[scale_tmp] += scale_2[iy] * T_tool_tmp_3[i];
        scale_0[scale_tmp] += scale_2[iy + 1] * T_tool_tmp_3[i + 4];
        scale_0[scale_tmp] += scale_2[iy + 2] * T_tool_tmp_3[i + 8];
        scale_0[scale_tmp] += scale_2[iy + 3] * T_tool_tmp_3[i + 12];
      }

      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        T_tool[scale_tmp] = 0.0;
        T_tool[scale_tmp] += rtb_tool_offset[iy] * scale_0[i];
        T_tool[scale_tmp] += rtb_tool_offset[iy + 1] * scale_0[i + 4];
        T_tool[scale_tmp] += rtb_tool_offset[iy + 2] * scale_0[i + 8];
        T_tool[scale_tmp] += rtb_tool_offset[iy + 3] * scale_0[i + 12];
      }
    }

    /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S7>/speed'
     */
    /* MATLAB Function 'Trajectory Planning/Linear Trajectory/Embedded MATLAB Function': '<S24>:1' */
    /* '<S24>:1:3' */
    rtb_Count = Teach_Pendant_Task_Space_P.speed_Value *
      Teach_Pendant_Task_Space_P.Constant2_Value_a;

    /* Switch: '<S25>/Init' incorporates:
     *  MATLAB Function: '<S7>/Forward Kinematics'
     *  UnitDelay: '<S25>/FixPt Unit Delay1'
     */
    /* '<S24>:1:4' */
    /* '<S24>:1:7' */
    if (rtb_LogicalOperator) {
      x = T_tool[12];
    } else {
      x = Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[0];
    }

    /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S7>/first point'
     */
    scale = Teach_Pendant_Task_Space_P.firstpoint_Value[0] - x;
    Teach_Pendant_Task_Space_B.inter[0] = scale;
    if (Teach_Pendant_Task_Space_B.inter[0] < 0.0) {
      Teach_Pendant_Task_Space_B.inter[0] = -1.0;
    } else if (Teach_Pendant_Task_Space_B.inter[0] > 0.0) {
      Teach_Pendant_Task_Space_B.inter[0] = 1.0;
    } else if (Teach_Pendant_Task_Space_B.inter[0] == 0.0) {
      Teach_Pendant_Task_Space_B.inter[0] = 0.0;
    } else {
      Teach_Pendant_Task_Space_B.inter[0] = (rtNaN);
    }

    Teach_Pendant_Task_Space_B.inter[0] = Teach_Pendant_Task_Space_B.inter[0] *
      rtb_Count + x;

    /* '<S24>:1:7' */
    if (fabs(scale) < rtb_Count) {
      /* '<S24>:1:8' */
      /* '<S24>:1:9' */
      Teach_Pendant_Task_Space_B.inter[0] =
        Teach_Pendant_Task_Space_P.firstpoint_Value[0];
    }

    /* Switch: '<S25>/Init' incorporates:
     *  MATLAB Function: '<S7>/Forward Kinematics'
     *  UnitDelay: '<S25>/FixPt Unit Delay1'
     */
    if (rtb_LogicalOperator) {
      x = T_tool[13];
    } else {
      x = Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[1];
    }

    /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S7>/first point'
     */
    scale = Teach_Pendant_Task_Space_P.firstpoint_Value[1] - x;
    Teach_Pendant_Task_Space_B.inter[1] = scale;
    if (Teach_Pendant_Task_Space_B.inter[1] < 0.0) {
      Teach_Pendant_Task_Space_B.inter[1] = -1.0;
    } else if (Teach_Pendant_Task_Space_B.inter[1] > 0.0) {
      Teach_Pendant_Task_Space_B.inter[1] = 1.0;
    } else if (Teach_Pendant_Task_Space_B.inter[1] == 0.0) {
      Teach_Pendant_Task_Space_B.inter[1] = 0.0;
    } else {
      Teach_Pendant_Task_Space_B.inter[1] = (rtNaN);
    }

    Teach_Pendant_Task_Space_B.inter[1] = Teach_Pendant_Task_Space_B.inter[1] *
      rtb_Count + x;

    /* '<S24>:1:7' */
    if (fabs(scale) < rtb_Count) {
      /* '<S24>:1:8' */
      /* '<S24>:1:9' */
      Teach_Pendant_Task_Space_B.inter[1] =
        Teach_Pendant_Task_Space_P.firstpoint_Value[1];
    }

    /* Switch: '<S25>/Init' incorporates:
     *  MATLAB Function: '<S7>/Forward Kinematics'
     *  UnitDelay: '<S25>/FixPt Unit Delay1'
     */
    if (rtb_LogicalOperator) {
      x = T_tool[14];
    } else {
      x = Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[2];
    }

    /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S7>/first point'
     */
    scale = Teach_Pendant_Task_Space_P.firstpoint_Value[2] - x;
    Teach_Pendant_Task_Space_B.inter[2] = scale;
    if (Teach_Pendant_Task_Space_B.inter[2] < 0.0) {
      Teach_Pendant_Task_Space_B.inter[2] = -1.0;
    } else if (Teach_Pendant_Task_Space_B.inter[2] > 0.0) {
      Teach_Pendant_Task_Space_B.inter[2] = 1.0;
    } else if (Teach_Pendant_Task_Space_B.inter[2] == 0.0) {
      Teach_Pendant_Task_Space_B.inter[2] = 0.0;
    } else {
      Teach_Pendant_Task_Space_B.inter[2] = (rtNaN);
    }

    Teach_Pendant_Task_Space_B.inter[2] = Teach_Pendant_Task_Space_B.inter[2] *
      rtb_Count + x;

    /* '<S24>:1:7' */
    if (fabs(scale) < rtb_Count) {
      /* '<S24>:1:8' */
      /* '<S24>:1:9' */
      Teach_Pendant_Task_Space_B.inter[2] =
        Teach_Pendant_Task_Space_P.firstpoint_Value[2];
    }

    /* Logic: '<S7>/Logical Operator' incorporates:
     *  Constant: '<S7>/first point'
     *  RelationalOperator: '<S7>/Relational Operator'
     */
    rtb_LogicalOperator = ((Teach_Pendant_Task_Space_P.firstpoint_Value[0] ==
      Teach_Pendant_Task_Space_B.inter[0]) &&
      (Teach_Pendant_Task_Space_P.firstpoint_Value[1] ==
       Teach_Pendant_Task_Space_B.inter[1]) &&
      (Teach_Pendant_Task_Space_P.firstpoint_Value[2] ==
       Teach_Pendant_Task_Space_B.inter[2]));

    /* Outputs for Enabled SubSystem: '<S7>/Traject' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {
      if (rtb_LogicalOperator) {
        if (!Teach_Pendant_Task_Space_DW.Traject_MODE) {
          /* InitializeConditions for UnitDelay: '<S29>/Output' */
          Teach_Pendant_Task_Space_DW.Output_DSTATE =
            Teach_Pendant_Task_Space_P.Output_InitialCondition;

          /* InitializeConditions for UnitDelay: '<S32>/Output' */
          Teach_Pendant_Task_Space_DW.Output_DSTATE_j =
            Teach_Pendant_Task_Space_P.Output_InitialCondition_p;

          /* InitializeConditions for UnitDelay: '<S35>/Output' */
          Teach_Pendant_Task_Space_DW.Output_DSTATE_c =
            Teach_Pendant_Task_Space_P.Output_InitialCondition_b;
          Teach_Pendant_Task_Space_DW.Traject_MODE = true;
        }
      } else {
        Teach_Pendant_Task_Space_DW.Traject_MODE = false;
      }
    }

    if (Teach_Pendant_Task_Space_DW.Traject_MODE) {
      /* Sum: '<S30>/FixPt Sum1' incorporates:
       *  Constant: '<S30>/FixPt Constant'
       *  UnitDelay: '<S29>/Output'
       */
      rtb_FixPtSum1 = (uint16_T)((uint32_T)
        Teach_Pendant_Task_Space_DW.Output_DSTATE +
        Teach_Pendant_Task_Space_P.FixPtConstant_Value);

      /* Switch: '<S31>/FixPt Switch' incorporates:
       *  Constant: '<S31>/Constant'
       */
      if (rtb_FixPtSum1 > Teach_Pendant_Task_Space_P.LimitedCounter_uplimit) {
        rtb_FixPtSwitch = Teach_Pendant_Task_Space_P.Constant_Value_h;
      } else {
        rtb_FixPtSwitch = rtb_FixPtSum1;
      }

      /* End of Switch: '<S31>/FixPt Switch' */

      /* SignalConversion: '<S26>/Out' incorporates:
       *  Constant: '<S26>/Vector'
       *  MultiPortSwitch: '<S26>/Output'
       *  UnitDelay: '<S29>/Output'
       */
      Teach_Pendant_Task_Space_B.Out =
        Teach_Pendant_Task_Space_P.TrajectoryJoint1_OutValues[Teach_Pendant_Task_Space_DW.Output_DSTATE];

      /* Sum: '<S33>/FixPt Sum1' incorporates:
       *  Constant: '<S33>/FixPt Constant'
       *  UnitDelay: '<S32>/Output'
       */
      rtb_FixPtSum1 = (uint16_T)((uint32_T)
        Teach_Pendant_Task_Space_DW.Output_DSTATE_j +
        Teach_Pendant_Task_Space_P.FixPtConstant_Value_m);

      /* Switch: '<S34>/FixPt Switch' incorporates:
       *  Constant: '<S34>/Constant'
       */
      if (rtb_FixPtSum1 > Teach_Pendant_Task_Space_P.LimitedCounter_uplimit_p) {
        rtb_FixPtSwitch_h = Teach_Pendant_Task_Space_P.Constant_Value_f;
      } else {
        rtb_FixPtSwitch_h = rtb_FixPtSum1;
      }

      /* End of Switch: '<S34>/FixPt Switch' */

      /* SignalConversion: '<S27>/Out' incorporates:
       *  Constant: '<S27>/Vector'
       *  MultiPortSwitch: '<S27>/Output'
       *  UnitDelay: '<S32>/Output'
       */
      Teach_Pendant_Task_Space_B.Out_i =
        Teach_Pendant_Task_Space_P.TrajectoryJoint2_OutValues[Teach_Pendant_Task_Space_DW.Output_DSTATE_j];

      /* Sum: '<S36>/FixPt Sum1' incorporates:
       *  Constant: '<S36>/FixPt Constant'
       *  UnitDelay: '<S35>/Output'
       */
      rtb_FixPtSum1 = (uint16_T)((uint32_T)
        Teach_Pendant_Task_Space_DW.Output_DSTATE_c +
        Teach_Pendant_Task_Space_P.FixPtConstant_Value_c);

      /* SignalConversion: '<S28>/Out' incorporates:
       *  Constant: '<S28>/Vector'
       *  MultiPortSwitch: '<S28>/Output'
       *  UnitDelay: '<S35>/Output'
       */
      Teach_Pendant_Task_Space_B.Out_p =
        Teach_Pendant_Task_Space_P.TrajectoryJoint3_OutValues[Teach_Pendant_Task_Space_DW.Output_DSTATE_c];

      /* Update for UnitDelay: '<S29>/Output' */
      Teach_Pendant_Task_Space_DW.Output_DSTATE = rtb_FixPtSwitch;

      /* Update for UnitDelay: '<S32>/Output' */
      Teach_Pendant_Task_Space_DW.Output_DSTATE_j = rtb_FixPtSwitch_h;

      /* Switch: '<S37>/FixPt Switch' */
      if (rtb_FixPtSum1 > Teach_Pendant_Task_Space_P.LimitedCounter_uplimit_k) {
        /* Update for UnitDelay: '<S35>/Output' incorporates:
         *  Constant: '<S37>/Constant'
         */
        Teach_Pendant_Task_Space_DW.Output_DSTATE_c =
          Teach_Pendant_Task_Space_P.Constant_Value_m;
      } else {
        /* Update for UnitDelay: '<S35>/Output' */
        Teach_Pendant_Task_Space_DW.Output_DSTATE_c = rtb_FixPtSum1;
      }

      /* End of Switch: '<S37>/FixPt Switch' */
      if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {
        srUpdateBC(Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S7>/Traject' */

    /* Switch: '<S7>/Switch' */
    if (rtb_LogicalOperator) {
      Teach_Pendant_Task_Space_B.Switch[0] = Teach_Pendant_Task_Space_B.Out;
      Teach_Pendant_Task_Space_B.Switch[1] = Teach_Pendant_Task_Space_B.Out_i;
      Teach_Pendant_Task_Space_B.Switch[2] = Teach_Pendant_Task_Space_B.Out_p;
    } else {
      Teach_Pendant_Task_Space_B.Switch[0] = Teach_Pendant_Task_Space_B.inter[0];
      Teach_Pendant_Task_Space_B.Switch[1] = Teach_Pendant_Task_Space_B.inter[1];
      Teach_Pendant_Task_Space_B.Switch[2] = Teach_Pendant_Task_Space_B.inter[2];
    }

    /* End of Switch: '<S7>/Switch' */

    /* MATLAB Function: '<Root>/Forward Kinematics' */
    /* MATLAB Function 'Forward Kinematics': '<S1>:1' */
    /* '<S1>:1:11' */
    /* '<S1>:1:32' */
    /* '<S1>:1:33' */
    /* '<S1>:1:35' */
    /* '<S1>:1:36' */
    /* '<S1>:1:30' */
    /* '<S1>:1:42' */
    /* '<S1>:1:47' */
    /* '<S1>:1:52' */
    /* '<S1>:1:12' */
    /* '<S1>:1:32' */
    /* '<S1>:1:33' */
    /* '<S1>:1:35' */
    /* '<S1>:1:36' */
    /* '<S1>:1:30' */
    /* '<S1>:1:42' */
    /* '<S1>:1:47' */
    /* '<S1>:1:52' */
    /* '<S1>:1:13' */
    /* '<S1>:1:32' */
    /* '<S1>:1:33' */
    /* '<S1>:1:35' */
    /* '<S1>:1:36' */
    /* '<S1>:1:30' */
    /* '<S1>:1:42' */
    /* '<S1>:1:47' */
    /* '<S1>:1:52' */
    /* '<S1>:1:17' */
    /* '<S1>:1:18' */
    /* '<S1>:1:21' */
    rtb_Count = sin(Teach_Pendant_Task_Space_B.JointOffsets[0]);
    scale = cos(Teach_Pendant_Task_Space_B.JointOffsets[0]);
    absxk = sin(Teach_Pendant_Task_Space_B.JointOffsets[1]);
    t = cos(Teach_Pendant_Task_Space_B.JointOffsets[1]);
    catArgs_f2[0] = 0;
    T_tool_tmp_0[0] = 0;
    catArgs_f2[1] = 0;
    T_tool_tmp_0[1] = 0;
    catArgs_f2[2] = 1;
    T_tool_tmp_0[2] = 0;
    catArgs_f2[3] = 0;
    T_tool_tmp_0[3] = 1;
    x = sin(Teach_Pendant_Task_Space_B.JointOffsets[2] - 1.5707963267948966);
    T_tool_tmp_1 = cos(Teach_Pendant_Task_Space_B.JointOffsets[2] -
                       1.5707963267948966);
    for (i = 0; i < 16; i++) {
      T_tool_tmp[i] = A_T_z[i];
      T_tool_tmp_2[i] = A_T_z[i];
    }

    scale_0[0] = scale;
    scale_0[4] = -rtb_Count;
    scale_0[8] = 0.0;
    scale_0[12] = 0.0;
    scale_0[1] = rtb_Count;
    scale_0[5] = scale;
    scale_0[9] = 0.0;
    scale_0[13] = 0.0;
    scale_0[2] = 0.0;
    scale_0[3] = 0.0;
    scale_0[6] = 0.0;
    scale_0[7] = 0.0;
    scale_0[10] = 1.0;
    scale_0[11] = 0.0;
    scale_0[14] = 0.0;
    scale_0[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_1[scale_tmp] = 0.0;
        scale_1[scale_tmp] += (real_T)T_tool_tmp[iy] * scale_0[i];
        scale_1[scale_tmp] += (real_T)T_tool_tmp[iy + 1] * scale_0[i + 4];
        scale_1[scale_tmp] += (real_T)T_tool_tmp[iy + 2] * scale_0[i + 8];
        scale_1[scale_tmp] += (real_T)T_tool_tmp[iy + 3] * scale_0[i + 12];
      }

      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_2[scale_tmp] = 0.0;
        scale_2[scale_tmp] += (real_T)T_tool_tmp[iy] * scale_1[i];
        scale_2[scale_tmp] += (real_T)T_tool_tmp[iy + 1] * scale_1[i + 4];
        scale_2[scale_tmp] += (real_T)T_tool_tmp[iy + 2] * scale_1[i + 8];
        scale_2[scale_tmp] += (real_T)T_tool_tmp[iy + 3] * scale_1[i + 12];
      }
    }

    T_tool[0] = t;
    T_tool[4] = -absxk;
    T_tool[8] = 0.0;
    T_tool[12] = 0.0;
    T_tool[1] = absxk;
    T_tool[5] = t;
    T_tool[9] = 0.0;
    T_tool[13] = 0.0;
    T_tool[2] = 0.0;
    T_tool[3] = 0.0;
    T_tool[6] = 0.0;
    T_tool[7] = 0.0;
    T_tool[10] = 1.0;
    T_tool[11] = 0.0;
    T_tool[14] = 0.0;
    T_tool[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_0[scale_tmp] = 0.0;
        scale_0[scale_tmp] += (real_T)T_tool_tmp[iy] * T_tool[i];
        scale_0[scale_tmp] += (real_T)T_tool_tmp[iy + 1] * T_tool[i + 4];
        scale_0[scale_tmp] += (real_T)T_tool_tmp[iy + 2] * T_tool[i + 8];
        scale_0[scale_tmp] += (real_T)T_tool_tmp[iy + 3] * T_tool[i + 12];
      }

      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_1[scale_tmp] = 0.0;
        scale_1[scale_tmp] += A_T_x[iy] * scale_0[i];
        scale_1[scale_tmp] += A_T_x[iy + 1] * scale_0[i + 4];
        scale_1[scale_tmp] += A_T_x[iy + 2] * scale_0[i + 8];
        scale_1[scale_tmp] += A_T_x[iy + 3] * scale_0[i + 12];
      }
    }

    T_tool_tmp_3[0] = T_tool_tmp_1;
    T_tool_tmp_3[4] = -x;
    T_tool_tmp_3[8] = 0.0;
    T_tool_tmp_3[12] = 0.0;
    T_tool_tmp_3[1] = x;
    T_tool_tmp_3[5] = T_tool_tmp_1;
    T_tool_tmp_3[9] = 0.0;
    T_tool_tmp_3[13] = 0.0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_0[scale_tmp] = 0.0;
        T_tool[scale_tmp] = 0.0;
        scale_0[scale_tmp] += A_R_x[iy] * scale_2[i];
        T_tool[scale_tmp] += (real_T)T_tool_tmp_2[iy] * scale_1[i];
        scale_tmp_0 = iy + 1;
        scale_0[scale_tmp] += A_R_x[scale_tmp_0] * scale_2[i + 4];
        T_tool[scale_tmp] += (real_T)T_tool_tmp_2[scale_tmp_0] * scale_1[i + 4];
        scale_tmp_0 = iy + 2;
        scale_0[scale_tmp] += A_R_x[scale_tmp_0] * scale_2[i + 8];
        T_tool[scale_tmp] += (real_T)T_tool_tmp_2[scale_tmp_0] * scale_1[i + 8];
        scale_tmp_0 = iy + 3;
        scale_0[scale_tmp] += A_R_x[scale_tmp_0] * scale_2[i + 12];
        T_tool[scale_tmp] += (real_T)T_tool_tmp_2[scale_tmp_0] * scale_1[i + 12];
      }

      iy = i << 2;
      T_tool_tmp_3[iy + 2] = catArgs_f2[i];
      T_tool_tmp_3[iy + 3] = T_tool_tmp_0[i];
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scale_tmp = j << 2;
        iy = i + scale_tmp;
        scale_1[iy] = 0.0;
        scale_1[iy] += (real_T)T_tool_tmp[scale_tmp] * T_tool_tmp_3[i];
        scale_1[iy] += (real_T)T_tool_tmp[scale_tmp + 1] * T_tool_tmp_3[i + 4];
        scale_1[iy] += (real_T)T_tool_tmp[scale_tmp + 2] * T_tool_tmp_3[i + 8];
        scale_1[iy] += (real_T)T_tool_tmp[scale_tmp + 3] * T_tool_tmp_3[i + 12];
      }

      for (j = 0; j < 4; j++) {
        scale_tmp = j << 2;
        iy = i + scale_tmp;
        scale_2[iy] = 0.0;
        scale_2[iy] += A_T_x[scale_tmp] * scale_1[i];
        scale_2[iy] += A_T_x[scale_tmp + 1] * scale_1[i + 4];
        scale_2[iy] += A_T_x[scale_tmp + 2] * scale_1[i + 8];
        scale_2[iy] += A_T_x[scale_tmp + 3] * scale_1[i + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = i << 2;
        scale_tmp = j + iy;
        scale_1[scale_tmp] = 0.0;
        T_tool_tmp_3[scale_tmp] = 0.0;
        scale_1[scale_tmp] += T_tool[iy] * scale_0[j];
        T_tool_tmp_3[scale_tmp] += (real_T)T_tool_tmp_2[iy] * scale_2[j];
        scale_tmp_0 = iy + 1;
        scale_1[scale_tmp] += T_tool[scale_tmp_0] * scale_0[j + 4];
        T_tool_tmp_3[scale_tmp] += (real_T)T_tool_tmp_2[scale_tmp_0] * scale_2[j
          + 4];
        scale_tmp_0 = iy + 2;
        scale_1[scale_tmp] += T_tool[scale_tmp_0] * scale_0[j + 8];
        T_tool_tmp_3[scale_tmp] += (real_T)T_tool_tmp_2[scale_tmp_0] * scale_2[j
          + 8];
        scale_tmp_0 = iy + 3;
        scale_1[scale_tmp] += T_tool[scale_tmp_0] * scale_0[j + 12];
        T_tool_tmp_3[scale_tmp] += (real_T)T_tool_tmp_2[scale_tmp_0] * scale_2[j
          + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        scale_0[scale_tmp] = 0.0;
        scale_0[scale_tmp] += T_tool_tmp_3[iy] * scale_1[i];
        scale_0[scale_tmp] += T_tool_tmp_3[iy + 1] * scale_1[i + 4];
        scale_0[scale_tmp] += T_tool_tmp_3[iy + 2] * scale_1[i + 8];
        scale_0[scale_tmp] += T_tool_tmp_3[iy + 3] * scale_1[i + 12];
      }

      for (j = 0; j < 4; j++) {
        iy = j << 2;
        scale_tmp = i + iy;
        T_tool[scale_tmp] = 0.0;
        T_tool[scale_tmp] += rtb_tool_offset[iy] * scale_0[i];
        T_tool[scale_tmp] += rtb_tool_offset[iy + 1] * scale_0[i + 4];
        T_tool[scale_tmp] += rtb_tool_offset[iy + 2] * scale_0[i + 8];
        T_tool[scale_tmp] += rtb_tool_offset[iy + 3] * scale_0[i + 12];
      }
    }

    /* '<S1>:1:22' */
    /* '<S1>:1:23' */
    /* MATLAB Function 'cost function': '<S8>:1' */
    /* '<S8>:1:5' */
    /* '<S8>:1:6' */
    /* '<S8>:1:7' */
    /* '<S8>:1:10' */
    /* MATLAB Function 'MATLAB Function': '<S3>:1' */
    Teach_Pendant_Task_Space_B.pos[0] = T_tool[12];

    /* Sum: '<Root>/Subtract' */
    Teach_Pendant_Task_Space_B.Subtract[0] = Teach_Pendant_Task_Space_B.pos[0] -
      Teach_Pendant_Task_Space_B.Switch[0];

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant1'
     *  MATLAB Function: '<Root>/pid auto tuner'
     */
    x = Teach_Pendant_Task_Space_B.Switch[0] -
      Teach_Pendant_Task_Space_P.starting_point[0];
    rtb_q[0] = fabs(x);
    rtb_GearRatio[0] = x;

    /* MATLAB Function: '<Root>/Forward Kinematics' */
    Teach_Pendant_Task_Space_B.pos[1] = T_tool[13];

    /* Sum: '<Root>/Subtract' */
    Teach_Pendant_Task_Space_B.Subtract[1] = Teach_Pendant_Task_Space_B.pos[1] -
      Teach_Pendant_Task_Space_B.Switch[1];

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant1'
     *  MATLAB Function: '<Root>/pid auto tuner'
     */
    x = Teach_Pendant_Task_Space_B.Switch[1] -
      Teach_Pendant_Task_Space_P.starting_point[1];
    rtb_q[1] = fabs(x);

    /* MATLAB Function: '<Root>/Forward Kinematics' */
    Teach_Pendant_Task_Space_B.pos[2] = T_tool[14];

    /* Sum: '<Root>/Subtract' */
    Teach_Pendant_Task_Space_B.Subtract[2] = Teach_Pendant_Task_Space_B.pos[2] -
      Teach_Pendant_Task_Space_B.Switch[2];

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant1'
     *  MATLAB Function: '<Root>/cost function'
     *  MATLAB Function: '<Root>/pid auto tuner'
     */
    T_tool_tmp_1 = fabs(Teach_Pendant_Task_Space_B.Switch[2] -
                        Teach_Pendant_Task_Space_P.starting_point[2]);
    rtb_q[2] = T_tool_tmp_1;
    rtb_LogicalOperator = true;
    iy = 0;
    exitg1 = false;
    while ((!exitg1) && (iy < 3)) {
      if (!(rtb_q[iy] < 1.0E-6)) {
        rtb_LogicalOperator = false;
        exitg1 = true;
      } else {
        iy++;
      }
    }

    if (rtb_LogicalOperator) {
      /* '<S3>:1:8' */
      /* '<S3>:1:9' */
      Teach_Pendant_Task_Space_DW.cost_sum = 0.0;
    } else {
      /* '<S3>:1:11' */
      Teach_Pendant_Task_Space_DW.cost_sum +=
        (Teach_Pendant_Task_Space_B.Subtract[0] *
         Teach_Pendant_Task_Space_B.Subtract[0] +
         Teach_Pendant_Task_Space_B.Subtract[1] *
         Teach_Pendant_Task_Space_B.Subtract[1]) +
        Teach_Pendant_Task_Space_B.Subtract[2] *
        Teach_Pendant_Task_Space_B.Subtract[2];
    }

    /* '<S3>:1:14' */
    Teach_Pendant_Task_Space_B.total_cost = Teach_Pendant_Task_Space_DW.cost_sum;

    /* MATLAB Function: '<Root>/pid auto tuner' */
    /* MATLAB Function 'pid auto tuner': '<S9>:1' */
    /* '<S9>:1:35' */
    /* '<S9>:1:9' */
    /* '<S9>:1:11' */
    /* '<S9>:1:13' */
    /* '<S9>:1:14' */
    if (!Teach_Pendant_Task_Space_DW.initialized_not_empty) {
      /* '<S9>:1:17' */
      /* '<S9>:1:18' */
      Teach_Pendant_Task_Space_rand(Teach_Pendant_Task_Space_DW.particles);

      /* '<S9>:1:21' */
      memcpy(&Teach_Pendant_Task_Space_DW.pbest[0],
             &Teach_Pendant_Task_Space_DW.particles[0], 120U * sizeof(real_T));

      /* '<S9>:1:24' */
      for (i = 0; i < 6; i++) {
        Teach_Pendant_Task_Space_DW.gbest[i] =
          Teach_Pendant_Task_Space_DW.particles[20 * i];
      }

      Teach_Pendant_Task_Space_DW.initialized_not_empty = true;
    }

    /* '<S9>:1:35' */
    /* '<S9>:1:105' */
    /* '<S9>:1:118' */
    j = (int32_T)Teach_Pendant_Task_Space_DW.current_particle;
    i = j - 1;
    Teach_Pendant_Task_Space_B.Ki[0] = Teach_Pendant_Task_Space_DW.particles[i] *
      2.0;

    /* '<S9>:1:106' */
    /* '<S9>:1:118' */
    Teach_Pendant_Task_Space_B.Ki[1] = Teach_Pendant_Task_Space_DW.particles[j +
      19] * 2.0;

    /* '<S9>:1:107' */
    /* '<S9>:1:118' */
    Teach_Pendant_Task_Space_B.Ki[2] = Teach_Pendant_Task_Space_DW.particles[j +
      39] * 3.0;

    /* '<S9>:1:110' */
    /* '<S9>:1:118' */
    Teach_Pendant_Task_Space_B.Kd[0] = Teach_Pendant_Task_Space_DW.particles[j +
      59] * 0.08 + 0.02;

    /* '<S9>:1:111' */
    /* '<S9>:1:118' */
    Teach_Pendant_Task_Space_B.Kd[1] = Teach_Pendant_Task_Space_DW.particles[j +
      79] * 0.08 + 0.02;

    /* '<S9>:1:112' */
    /* '<S9>:1:118' */
    Teach_Pendant_Task_Space_B.Kd[2] = Teach_Pendant_Task_Space_DW.particles[j +
      99] * 0.025;

    /* '<S9>:1:36' */
    /* '<S9>:1:37' */
    /* '<S9>:1:38' */
    /* '<S9>:1:41' */
    scale = 3.3121686421112381E-170;
    absxk = fabs(rtb_GearRatio[0]);
    if (absxk > 3.3121686421112381E-170) {
      rtb_Count = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      rtb_Count = t * t;
    }

    absxk = fabs(x);
    if (absxk > scale) {
      t = scale / absxk;
      rtb_Count = rtb_Count * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      rtb_Count += t * t;
    }

    if (T_tool_tmp_1 > scale) {
      t = scale / T_tool_tmp_1;
      rtb_Count = rtb_Count * t * t + 1.0;
      scale = T_tool_tmp_1;
    } else {
      t = T_tool_tmp_1 / scale;
      rtb_Count += t * t;
    }

    rtb_Count = scale * sqrt(rtb_Count);
    rtb_LogicalOperator = (rtb_Count < 0.05);
    if (rtb_LogicalOperator && (!Teach_Pendant_Task_Space_DW.in_zone_prev)) {
      /* '<S9>:1:42' */
      trigger = true;
    } else {
      trigger = false;
    }

    /* '<S9>:1:43' */
    Teach_Pendant_Task_Space_DW.in_zone_prev = rtb_LogicalOperator;
    if (trigger) {
      if (Teach_Pendant_Task_Space_B.total_cost <
          Teach_Pendant_Task_Space_DW.pbest_cost[i]) {
        /* '<S9>:1:48' */
        /* '<S9>:1:49' */
        Teach_Pendant_Task_Space_DW.pbest_cost[i] =
          Teach_Pendant_Task_Space_B.total_cost;

        /* '<S9>:1:50' */
        for (i = 0; i < 6; i++) {
          Teach_Pendant_Task_Space_DW.pbest[(j + 20 * i) - 1] =
            Teach_Pendant_Task_Space_DW.particles[(20 * i + j) - 1];
        }
      }

      if (Teach_Pendant_Task_Space_B.total_cost <
          Teach_Pendant_Task_Space_DW.gbest_cost) {
        /* '<S9>:1:53' */
        /* '<S9>:1:54' */
        Teach_Pendant_Task_Space_DW.gbest_cost =
          Teach_Pendant_Task_Space_B.total_cost;

        /* '<S9>:1:55' */
        i = (int32_T)Teach_Pendant_Task_Space_DW.current_particle;
        for (j = 0; j < 6; j++) {
          Teach_Pendant_Task_Space_DW.gbest[j] =
            Teach_Pendant_Task_Space_DW.particles[(20 * j + i) - 1];
        }
      }

      /* '<S9>:1:58' */
      Teach_Pendant_Task_Space_DW.eval_count++;

      /* '<S9>:1:61' */
      Teach_Pendant_Task_Space_DW.current_particle++;
      if (Teach_Pendant_Task_Space_DW.current_particle > 20.0) {
        /* '<S9>:1:62' */
        /* '<S9>:1:63' */
        Teach_Pendant_Task_Space_DW.current_particle = 1.0;
      }

      if (Teach_Pendant_Task_Space_DW.eval_count >= 20.0) {
        /* '<S9>:1:67' */
        /* '<S9>:1:68' */
        for (j = 0; j < 20; j++) {
          /* '<S9>:1:68' */
          /* '<S9>:1:70' */
          Teach_Pendant_Task_Space_rand_l(rtb_EncoderOffsets);

          /* '<S9>:1:71' */
          Teach_Pendant_Task_Space_rand_l(r2);

          /* '<S9>:1:73' */
          /* '<S9>:1:78' */
          /* '<S9>:1:79' */
          for (iy = 0; iy < 6; iy++) {
            i = 20 * iy + j;
            Teach_Pendant_Task_Space_DW.velocities[i] =
              ((Teach_Pendant_Task_Space_DW.pbest[i] -
                Teach_Pendant_Task_Space_DW.particles[i]) * (1.5 *
                rtb_EncoderOffsets[iy]) +
               Teach_Pendant_Task_Space_DW.velocities[i] * 0.7) +
              (Teach_Pendant_Task_Space_DW.gbest[iy] -
               Teach_Pendant_Task_Space_DW.particles[i]) * (3.0 * r2[iy]);
            Teach_Pendant_Task_Space_DW.particles[i] +=
              Teach_Pendant_Task_Space_DW.velocities[i];
            if ((1.0 < Teach_Pendant_Task_Space_DW.particles[i]) || rtIsNaN
                (Teach_Pendant_Task_Space_DW.particles[i])) {
              rtb_Count = 1.0;
            } else {
              rtb_Count = Teach_Pendant_Task_Space_DW.particles[i];
            }

            if ((0.0 > rtb_Count) || rtIsNaN(rtb_Count)) {
              scale = 0.0;
            } else {
              scale = rtb_Count;
            }

            Teach_Pendant_Task_Space_DW.particles[i] = scale;
            rtb_EncoderOffsets[iy] = rtb_Count;
            r2[iy] = scale;
          }
        }

        /* '<S9>:1:82' */
        Teach_Pendant_Task_Space_DW.eval_count = 0.0;
      }
    }

    /* '<S9>:1:87' */
    /* '<S9>:1:105' */
    /* '<S9>:1:118' */
    /* '<S9>:1:106' */
    /* '<S9>:1:118' */
    /* '<S9>:1:107' */
    /* '<S9>:1:118' */
    /* '<S9>:1:110' */
    /* '<S9>:1:118' */
    /* '<S9>:1:111' */
    /* '<S9>:1:118' */
    /* '<S9>:1:112' */
    /* '<S9>:1:118' */
    /* '<S9>:1:88' */
    /* '<S9>:1:91' */
    if (!rtIsNaN(Teach_Pendant_Task_Space_DW.pbest_cost[0])) {
      iy = 0;
    } else {
      iy = -1;
      j = 2;
      exitg1 = false;
      while ((!exitg1) && (j < 21)) {
        if (!rtIsNaN(Teach_Pendant_Task_Space_DW.pbest_cost[j - 1])) {
          iy = j - 1;
          exitg1 = true;
        } else {
          j++;
        }
      }
    }

    if (iy + 1 == 0) {
      iy = 0;
    } else {
      rtb_Count = Teach_Pendant_Task_Space_DW.pbest_cost[iy];
      for (j = iy + 1; j < 20; j++) {
        if (rtb_Count < Teach_Pendant_Task_Space_DW.pbest_cost[j]) {
          rtb_Count = Teach_Pendant_Task_Space_DW.pbest_cost[j];
          iy = j;
        }
      }
    }

    /* '<S9>:1:92' */
    /* '<S9>:1:105' */
    /* '<S9>:1:118' */
    /* '<S9>:1:106' */
    /* '<S9>:1:118' */
    /* '<S9>:1:107' */
    /* '<S9>:1:118' */
    /* '<S9>:1:110' */
    /* '<S9>:1:118' */
    /* '<S9>:1:111' */
    /* '<S9>:1:118' */
    /* '<S9>:1:112' */
    /* '<S9>:1:118' */
    /* '<S9>:1:93' */
    Teach_Pendant_Task_Space_B.best_PID[0] = 1.79;
    Teach_Pendant_Task_Space_B.best_PID[3] = Teach_Pendant_Task_Space_DW.gbest[0]
      * 2.0;
    Teach_Pendant_Task_Space_B.best_PID[6] = Teach_Pendant_Task_Space_DW.gbest[3]
      * 0.08 + 0.02;
    Teach_Pendant_Task_Space_B.worst_PID[0] = 1.79;
    Teach_Pendant_Task_Space_B.worst_PID[3] =
      Teach_Pendant_Task_Space_DW.pbest[iy] * 2.0;
    Teach_Pendant_Task_Space_B.worst_PID[6] =
      Teach_Pendant_Task_Space_DW.pbest[iy + 60] * 0.08 + 0.02;
    Teach_Pendant_Task_Space_B.best_PID[1] = 1.46;
    Teach_Pendant_Task_Space_B.best_PID[4] = Teach_Pendant_Task_Space_DW.gbest[1]
      * 2.0;
    Teach_Pendant_Task_Space_B.best_PID[7] = Teach_Pendant_Task_Space_DW.gbest[4]
      * 0.08 + 0.02;
    Teach_Pendant_Task_Space_B.worst_PID[1] = 1.46;
    Teach_Pendant_Task_Space_B.worst_PID[4] =
      Teach_Pendant_Task_Space_DW.pbest[iy + 20] * 2.0;
    Teach_Pendant_Task_Space_B.worst_PID[7] =
      Teach_Pendant_Task_Space_DW.pbest[iy + 80] * 0.08 + 0.02;
    Teach_Pendant_Task_Space_B.best_PID[2] = 0.6;
    Teach_Pendant_Task_Space_B.best_PID[5] = Teach_Pendant_Task_Space_DW.gbest[2]
      * 3.0;
    Teach_Pendant_Task_Space_B.best_PID[8] = Teach_Pendant_Task_Space_DW.gbest[5]
      * 0.025;
    Teach_Pendant_Task_Space_B.worst_PID[2] = 0.6;
    Teach_Pendant_Task_Space_B.worst_PID[5] =
      Teach_Pendant_Task_Space_DW.pbest[iy + 40] * 3.0;
    Teach_Pendant_Task_Space_B.worst_PID[8] =
      Teach_Pendant_Task_Space_DW.pbest[iy + 100] * 0.025;

    /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
     *  Constant: '<Root>/Constant2'
     *  MATLAB Function: '<Root>/MATLAB Function1'
     *  SignalConversion generated from: '<S5>/ SFunction '
     */
    /* MATLAB Function 'MATLAB Function2': '<S5>:1' */
    if (Teach_Pendant_Task_Space_P.Constant2_Value == 1.0) {
      /* '<S5>:1:4' */
      /* '<S5>:1:5' */
      Teach_Pendant_Task_Space_B.out[0] = 1.79;
      Teach_Pendant_Task_Space_B.out[3] = 1.0;
      Teach_Pendant_Task_Space_B.out[6] = 0.03;
      Teach_Pendant_Task_Space_B.out[1] = 1.46;
      Teach_Pendant_Task_Space_B.out[4] = 1.7;
      Teach_Pendant_Task_Space_B.out[7] = 0.045;
      Teach_Pendant_Task_Space_B.out[2] = 0.6;
      Teach_Pendant_Task_Space_B.out[5] = 2.9;
      Teach_Pendant_Task_Space_B.out[8] = 0.001;
    } else {
      /* '<S5>:1:7' */
      Teach_Pendant_Task_Space_B.out[0] = 1.79;
      Teach_Pendant_Task_Space_B.out[3] = Teach_Pendant_Task_Space_B.Ki[0];
      Teach_Pendant_Task_Space_B.out[6] = Teach_Pendant_Task_Space_B.Kd[0];
      Teach_Pendant_Task_Space_B.out[1] = 1.46;
      Teach_Pendant_Task_Space_B.out[4] = Teach_Pendant_Task_Space_B.Ki[1];
      Teach_Pendant_Task_Space_B.out[7] = Teach_Pendant_Task_Space_B.Kd[1];
      Teach_Pendant_Task_Space_B.out[2] = 0.6;
      Teach_Pendant_Task_Space_B.out[5] = Teach_Pendant_Task_Space_B.Ki[2];
      Teach_Pendant_Task_Space_B.out[8] = Teach_Pendant_Task_Space_B.Kd[2];
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function2' */

    /* Saturate: '<S6>/Saturation1' */
    if (Teach_Pendant_Task_Space_B.out[6] >
        Teach_Pendant_Task_Space_P.Saturation1_UpperSat[0]) {
      Teach_Pendant_Task_Space_B.Saturation1[0] =
        Teach_Pendant_Task_Space_P.Saturation1_UpperSat[0];
    } else if (Teach_Pendant_Task_Space_B.out[6] <
               Teach_Pendant_Task_Space_P.Saturation1_LowerSat[0]) {
      Teach_Pendant_Task_Space_B.Saturation1[0] =
        Teach_Pendant_Task_Space_P.Saturation1_LowerSat[0];
    } else {
      Teach_Pendant_Task_Space_B.Saturation1[0] =
        Teach_Pendant_Task_Space_B.out[6];
    }

    /* Saturate: '<S6>/Saturation2' */
    if (Teach_Pendant_Task_Space_B.out[3] >
        Teach_Pendant_Task_Space_P.Saturation2_UpperSat[0]) {
      Teach_Pendant_Task_Space_B.Saturation2[0] =
        Teach_Pendant_Task_Space_P.Saturation2_UpperSat[0];
    } else if (Teach_Pendant_Task_Space_B.out[3] <
               Teach_Pendant_Task_Space_P.Saturation2_LowerSat[0]) {
      Teach_Pendant_Task_Space_B.Saturation2[0] =
        Teach_Pendant_Task_Space_P.Saturation2_LowerSat[0];
    } else {
      Teach_Pendant_Task_Space_B.Saturation2[0] =
        Teach_Pendant_Task_Space_B.out[3];
    }

    /* Saturate: '<S6>/Saturation' */
    if (Teach_Pendant_Task_Space_B.out[0] >
        Teach_Pendant_Task_Space_P.Saturation_UpperSat[0]) {
      Teach_Pendant_Task_Space_B.Saturation[0] =
        Teach_Pendant_Task_Space_P.Saturation_UpperSat[0];
    } else if (Teach_Pendant_Task_Space_B.out[0] <
               Teach_Pendant_Task_Space_P.Saturation_LowerSat[0]) {
      Teach_Pendant_Task_Space_B.Saturation[0] =
        Teach_Pendant_Task_Space_P.Saturation_LowerSat[0];
    } else {
      Teach_Pendant_Task_Space_B.Saturation[0] = Teach_Pendant_Task_Space_B.out
        [0];
    }

    /* Saturate: '<S6>/Saturation1' */
    if (Teach_Pendant_Task_Space_B.out[7] >
        Teach_Pendant_Task_Space_P.Saturation1_UpperSat[1]) {
      Teach_Pendant_Task_Space_B.Saturation1[1] =
        Teach_Pendant_Task_Space_P.Saturation1_UpperSat[1];
    } else if (Teach_Pendant_Task_Space_B.out[7] <
               Teach_Pendant_Task_Space_P.Saturation1_LowerSat[1]) {
      Teach_Pendant_Task_Space_B.Saturation1[1] =
        Teach_Pendant_Task_Space_P.Saturation1_LowerSat[1];
    } else {
      Teach_Pendant_Task_Space_B.Saturation1[1] =
        Teach_Pendant_Task_Space_B.out[7];
    }

    /* Saturate: '<S6>/Saturation2' */
    if (Teach_Pendant_Task_Space_B.out[4] >
        Teach_Pendant_Task_Space_P.Saturation2_UpperSat[1]) {
      Teach_Pendant_Task_Space_B.Saturation2[1] =
        Teach_Pendant_Task_Space_P.Saturation2_UpperSat[1];
    } else if (Teach_Pendant_Task_Space_B.out[4] <
               Teach_Pendant_Task_Space_P.Saturation2_LowerSat[1]) {
      Teach_Pendant_Task_Space_B.Saturation2[1] =
        Teach_Pendant_Task_Space_P.Saturation2_LowerSat[1];
    } else {
      Teach_Pendant_Task_Space_B.Saturation2[1] =
        Teach_Pendant_Task_Space_B.out[4];
    }

    /* Saturate: '<S6>/Saturation' */
    if (Teach_Pendant_Task_Space_B.out[1] >
        Teach_Pendant_Task_Space_P.Saturation_UpperSat[1]) {
      Teach_Pendant_Task_Space_B.Saturation[1] =
        Teach_Pendant_Task_Space_P.Saturation_UpperSat[1];
    } else if (Teach_Pendant_Task_Space_B.out[1] <
               Teach_Pendant_Task_Space_P.Saturation_LowerSat[1]) {
      Teach_Pendant_Task_Space_B.Saturation[1] =
        Teach_Pendant_Task_Space_P.Saturation_LowerSat[1];
    } else {
      Teach_Pendant_Task_Space_B.Saturation[1] = Teach_Pendant_Task_Space_B.out
        [1];
    }

    /* Saturate: '<S6>/Saturation1' */
    if (Teach_Pendant_Task_Space_B.out[8] >
        Teach_Pendant_Task_Space_P.Saturation1_UpperSat[2]) {
      Teach_Pendant_Task_Space_B.Saturation1[2] =
        Teach_Pendant_Task_Space_P.Saturation1_UpperSat[2];
    } else if (Teach_Pendant_Task_Space_B.out[8] <
               Teach_Pendant_Task_Space_P.Saturation1_LowerSat[2]) {
      Teach_Pendant_Task_Space_B.Saturation1[2] =
        Teach_Pendant_Task_Space_P.Saturation1_LowerSat[2];
    } else {
      Teach_Pendant_Task_Space_B.Saturation1[2] =
        Teach_Pendant_Task_Space_B.out[8];
    }

    /* Saturate: '<S6>/Saturation2' */
    if (Teach_Pendant_Task_Space_B.out[5] >
        Teach_Pendant_Task_Space_P.Saturation2_UpperSat[2]) {
      Teach_Pendant_Task_Space_B.Saturation2[2] =
        Teach_Pendant_Task_Space_P.Saturation2_UpperSat[2];
    } else if (Teach_Pendant_Task_Space_B.out[5] <
               Teach_Pendant_Task_Space_P.Saturation2_LowerSat[2]) {
      Teach_Pendant_Task_Space_B.Saturation2[2] =
        Teach_Pendant_Task_Space_P.Saturation2_LowerSat[2];
    } else {
      Teach_Pendant_Task_Space_B.Saturation2[2] =
        Teach_Pendant_Task_Space_B.out[5];
    }

    /* Saturate: '<S6>/Saturation' */
    if (Teach_Pendant_Task_Space_B.out[2] >
        Teach_Pendant_Task_Space_P.Saturation_UpperSat[2]) {
      Teach_Pendant_Task_Space_B.Saturation[2] =
        Teach_Pendant_Task_Space_P.Saturation_UpperSat[2];
    } else if (Teach_Pendant_Task_Space_B.out[2] <
               Teach_Pendant_Task_Space_P.Saturation_LowerSat[2]) {
      Teach_Pendant_Task_Space_B.Saturation[2] =
        Teach_Pendant_Task_Space_P.Saturation_LowerSat[2];
    } else {
      Teach_Pendant_Task_Space_B.Saturation[2] = Teach_Pendant_Task_Space_B.out
        [2];
    }

    /* MATLAB Function: '<Root>/Inverse Kinematics' incorporates:
     *  MATLAB Function: '<Root>/Forward Kinematics'
     */
    /* MATLAB Function 'Inverse Kinematics': '<S2>:1' */
    /* '<S2>:1:19' */
    /* '<S2>:1:22' */
    for (i = 0; i < 3; i++) {
      rtb_GearRatio[i] = T_tool[i + 8] * rtb_tool_offset[14] + (T_tool[i + 4] *
        rtb_tool_offset[13] + T_tool[i] * rtb_tool_offset[12]);
    }

    /* '<S2>:1:26' */
    x = Teach_Pendant_Task_Space_B.Switch[0] - rtb_GearRatio[0];

    /* '<S2>:1:27' */
    rtb_Count = Teach_Pendant_Task_Space_B.Switch[1] - rtb_GearRatio[1];

    /* '<S2>:1:28' */
    absxk = Teach_Pendant_Task_Space_B.Switch[2] - rtb_GearRatio[2];

    /* '<S2>:1:32' */
    t = sqrt(x * x + rtb_Count * rtb_Count);

    /* '<S2>:1:35' */
    scale = sqrt(t * t + absxk * absxk);

    /* '<S2>:1:38' */
    rtb_Count = atan(rtb_Count / x);

    /* '<S2>:1:41' */
    x = acos((0.034848000000000004 - scale * scale) / 0.034848000000000004);
    if (absxk < 0.0) {
      /* '<S2>:1:44' */
      /* '<S2>:1:45' */
      absxk = acos(t / scale);
    } else {
      /* '<S2>:1:47' */
      absxk = -acos(t / scale);
    }

    /* '<S2>:1:51' */
    /* '<S2>:1:52' */
    scale = absxk - asin(sin(4.71238898038469 - (4.71238898038469 - x)) * 0.132 /
                         scale);

    /* Sum: '<S12>/Sum1' incorporates:
     *  MATLAB Function: '<Root>/Inverse Kinematics'
     */
    Teach_Pendant_Task_Space_B.Sum1[0] = rtb_Count -
      Teach_Pendant_Task_Space_B.JointOffsets[0];
    Teach_Pendant_Task_Space_B.Sum1[1] = scale -
      Teach_Pendant_Task_Space_B.JointOffsets[1];
    Teach_Pendant_Task_Space_B.Sum1[2] = (4.71238898038469 - x) -
      Teach_Pendant_Task_Space_B.JointOffsets[2];

    /* Product: '<S12>/Product1' */
    Teach_Pendant_Task_Space_B.Product1[0] =
      Teach_Pendant_Task_Space_B.Saturation[0] *
      Teach_Pendant_Task_Space_B.Sum1[0];
    Teach_Pendant_Task_Space_B.Product1[1] =
      Teach_Pendant_Task_Space_B.Saturation[1] *
      Teach_Pendant_Task_Space_B.Sum1[1];
    Teach_Pendant_Task_Space_B.Product1[2] =
      Teach_Pendant_Task_Space_B.Saturation[2] *
      Teach_Pendant_Task_Space_B.Sum1[2];

    /* Constant: '<S20>/x0' */
    Teach_Pendant_Task_Space_B.x0 = Teach_Pendant_Task_Space_P.x0_Value;
  }

  /* Product: '<S20>/Product1' incorporates:
   *  Constant: '<S20>/wn'
   *  Integrator: '<S20>/Integrator2'
   */
  Teach_Pendant_Task_Space_B.Product1_g[0] =
    Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_input_ *
    Teach_Pendant_Task_Space_X.Integrator2_CSTATE[0];

  /* Gain: '<S6>/Convert to Positive Rotation Convension Used in Kinematics2' incorporates:
   *  Integrator: '<S12>/Integrator'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product2'
   *  Sum: '<S12>/Add'
   */
  Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[0] =
    ((Teach_Pendant_Task_Space_X.Integrator_CSTATE[0] *
      Teach_Pendant_Task_Space_B.Saturation2[0] +
      Teach_Pendant_Task_Space_B.Product1[0]) -
     Teach_Pendant_Task_Space_B.Product1_g[0] *
     Teach_Pendant_Task_Space_B.Saturation1[0]) *
    Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConv_g[0];

  /* Product: '<S20>/Product1' incorporates:
   *  Constant: '<S20>/wn'
   *  Integrator: '<S20>/Integrator2'
   */
  Teach_Pendant_Task_Space_B.Product1_g[1] =
    Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_input_ *
    Teach_Pendant_Task_Space_X.Integrator2_CSTATE[1];

  /* Gain: '<S6>/Convert to Positive Rotation Convension Used in Kinematics2' incorporates:
   *  Integrator: '<S12>/Integrator'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product2'
   *  Sum: '<S12>/Add'
   */
  Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[1] =
    ((Teach_Pendant_Task_Space_X.Integrator_CSTATE[1] *
      Teach_Pendant_Task_Space_B.Saturation2[1] +
      Teach_Pendant_Task_Space_B.Product1[1]) -
     Teach_Pendant_Task_Space_B.Product1_g[1] *
     Teach_Pendant_Task_Space_B.Saturation1[1]) *
    Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConv_g[1];

  /* Product: '<S20>/Product1' incorporates:
   *  Constant: '<S20>/wn'
   *  Integrator: '<S20>/Integrator2'
   */
  Teach_Pendant_Task_Space_B.Product1_g[2] =
    Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_input_ *
    Teach_Pendant_Task_Space_X.Integrator2_CSTATE[2];

  /* Gain: '<S6>/Convert to Positive Rotation Convension Used in Kinematics2' incorporates:
   *  Integrator: '<S12>/Integrator'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product2'
   *  Sum: '<S12>/Add'
   */
  Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[2] =
    ((Teach_Pendant_Task_Space_X.Integrator_CSTATE[2] *
      Teach_Pendant_Task_Space_B.Saturation2[2] +
      Teach_Pendant_Task_Space_B.Product1[2]) -
     Teach_Pendant_Task_Space_B.Product1_g[2] *
     Teach_Pendant_Task_Space_B.Saturation1[2]) *
    Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConv_g[2];

  /* Integrator: '<S20>/Integrator1' */
  if (Teach_Pendant_Task_Space_DW.Integrator1_IWORK != 0) {
    Teach_Pendant_Task_Space_X.Integrator1_CSTATE[0] =
      Teach_Pendant_Task_Space_B.x0;
    Teach_Pendant_Task_Space_X.Integrator1_CSTATE[1] =
      Teach_Pendant_Task_Space_B.x0;
    Teach_Pendant_Task_Space_X.Integrator1_CSTATE[2] =
      Teach_Pendant_Task_Space_B.x0;
  }

  /* Product: '<S20>/Product' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/wn'
   *  Constant: '<S20>/zt'
   *  Integrator: '<S20>/Integrator1'
   *  Integrator: '<S20>/Integrator2'
   *  Product: '<S20>/Product2'
   *  Sum: '<S20>/Sum'
   *  Sum: '<S20>/Sum1'
   */
  Teach_Pendant_Task_Space_B.Product[0] =
    ((Teach_Pendant_Task_Space_B.JointOffsets[0] -
      Teach_Pendant_Task_Space_X.Integrator1_CSTATE[0]) -
     Teach_Pendant_Task_Space_X.Integrator2_CSTATE[0] *
     Teach_Pendant_Task_Space_P.Constant_Value *
     Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_inpu_h) *
    Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_input_;
  Teach_Pendant_Task_Space_B.Product[1] =
    ((Teach_Pendant_Task_Space_B.JointOffsets[1] -
      Teach_Pendant_Task_Space_X.Integrator1_CSTATE[1]) -
     Teach_Pendant_Task_Space_X.Integrator2_CSTATE[1] *
     Teach_Pendant_Task_Space_P.Constant_Value *
     Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_inpu_h) *
    Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_input_;
  Teach_Pendant_Task_Space_B.Product[2] =
    ((Teach_Pendant_Task_Space_B.JointOffsets[2] -
      Teach_Pendant_Task_Space_X.Integrator1_CSTATE[2]) -
     Teach_Pendant_Task_Space_X.Integrator2_CSTATE[2] *
     Teach_Pendant_Task_Space_P.Constant_Value *
     Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_inpu_h) *
    Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_input_;
  if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {
    if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {
      /* Update for UnitDelay: '<S25>/FixPt Unit Delay2' incorporates:
       *  Constant: '<S25>/FixPt Constant'
       */
      Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE =
        Teach_Pendant_Task_Space_P.FixPtConstant_Value_l;

      /* Update for UnitDelay: '<S6>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[0] =
        Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[0];

      /* Update for UnitDelay: '<S25>/FixPt Unit Delay1' */
      Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[0] =
        Teach_Pendant_Task_Space_B.inter[0];

      /* Update for UnitDelay: '<S6>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[1] =
        Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[1];

      /* Update for UnitDelay: '<S25>/FixPt Unit Delay1' */
      Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[1] =
        Teach_Pendant_Task_Space_B.inter[1];

      /* Update for UnitDelay: '<S6>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[2] =
        Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[2];

      /* Update for UnitDelay: '<S25>/FixPt Unit Delay1' */
      Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[2] =
        Teach_Pendant_Task_Space_B.inter[2];
    }

    /* Update for Integrator: '<S20>/Integrator1' */
    Teach_Pendant_Task_Space_DW.Integrator1_IWORK = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)Teach_Pendant_Task_Space_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {/* Sample time: [0.001s, 0.0s] */
      rtExtModeUpload(1, (real_T)
                      (((Teach_Pendant_Task_Space_M->Timing.clockTick1+
                         Teach_Pendant_Task_Space_M->Timing.clockTickH1*
                         4294967296.0)) * 0.001));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Teach_Pendant_Task_Space_M)!=-1) &&
          !((rtmGetTFinal(Teach_Pendant_Task_Space_M)-
             (((Teach_Pendant_Task_Space_M->Timing.clockTick1+
                Teach_Pendant_Task_Space_M->Timing.clockTickH1* 4294967296.0)) *
              0.001)) > (((Teach_Pendant_Task_Space_M->Timing.clockTick1+
                           Teach_Pendant_Task_Space_M->Timing.clockTickH1*
                           4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Teach_Pendant_Task_Space_M, "Simulation finished");
      }

      if (rtmGetStopRequested(Teach_Pendant_Task_Space_M)) {
        rtmSetErrorStatus(Teach_Pendant_Task_Space_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Teach_Pendant_Task_Space_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Teach_Pendant_Task_Space_M->Timing.clockTick0)) {
      ++Teach_Pendant_Task_Space_M->Timing.clockTickH0;
    }

    Teach_Pendant_Task_Space_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Teach_Pendant_Task_Space_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Teach_Pendant_Task_Space_M->Timing.clockTick1++;
      if (!Teach_Pendant_Task_Space_M->Timing.clockTick1) {
        Teach_Pendant_Task_Space_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Teach_Pendant_Task_Space_derivatives(void)
{
  XDot_Teach_Pendant_Task_Space_T *_rtXdot;
  _rtXdot = ((XDot_Teach_Pendant_Task_Space_T *)
             Teach_Pendant_Task_Space_M->derivs);

  /* Derivatives for Integrator: '<S12>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = Teach_Pendant_Task_Space_B.Sum1[0];

  /* Derivatives for Integrator: '<S20>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = Teach_Pendant_Task_Space_B.Product[0];

  /* Derivatives for Integrator: '<S20>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = Teach_Pendant_Task_Space_B.Product1_g[0];

  /* Derivatives for Integrator: '<S12>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = Teach_Pendant_Task_Space_B.Sum1[1];

  /* Derivatives for Integrator: '<S20>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = Teach_Pendant_Task_Space_B.Product[1];

  /* Derivatives for Integrator: '<S20>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = Teach_Pendant_Task_Space_B.Product1_g[1];

  /* Derivatives for Integrator: '<S12>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = Teach_Pendant_Task_Space_B.Sum1[2];

  /* Derivatives for Integrator: '<S20>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = Teach_Pendant_Task_Space_B.Product[2];

  /* Derivatives for Integrator: '<S20>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = Teach_Pendant_Task_Space_B.Product1_g[2];
}

/* Model initialize function */
void Teach_Pendant_Task_Space_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Teach_Pendant_Task_Space_M, 0,
                sizeof(RT_MODEL_Teach_Pendant_Task_S_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Teach_Pendant_Task_Space_M->solverInfo,
                          &Teach_Pendant_Task_Space_M->Timing.simTimeStep);
    rtsiSetTPtr(&Teach_Pendant_Task_Space_M->solverInfo, &rtmGetTPtr
                (Teach_Pendant_Task_Space_M));
    rtsiSetStepSizePtr(&Teach_Pendant_Task_Space_M->solverInfo,
                       &Teach_Pendant_Task_Space_M->Timing.stepSize0);
    rtsiSetdXPtr(&Teach_Pendant_Task_Space_M->solverInfo,
                 &Teach_Pendant_Task_Space_M->derivs);
    rtsiSetContStatesPtr(&Teach_Pendant_Task_Space_M->solverInfo, (real_T **)
                         &Teach_Pendant_Task_Space_M->contStates);
    rtsiSetNumContStatesPtr(&Teach_Pendant_Task_Space_M->solverInfo,
      &Teach_Pendant_Task_Space_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Teach_Pendant_Task_Space_M->solverInfo,
      &Teach_Pendant_Task_Space_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Teach_Pendant_Task_Space_M->solverInfo,
      &Teach_Pendant_Task_Space_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Teach_Pendant_Task_Space_M->solverInfo,
      &Teach_Pendant_Task_Space_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Teach_Pendant_Task_Space_M->solverInfo,
                          (&rtmGetErrorStatus(Teach_Pendant_Task_Space_M)));
    rtsiSetRTModelPtr(&Teach_Pendant_Task_Space_M->solverInfo,
                      Teach_Pendant_Task_Space_M);
  }

  rtsiSetSimTimeStep(&Teach_Pendant_Task_Space_M->solverInfo, MAJOR_TIME_STEP);
  Teach_Pendant_Task_Space_M->intgData.f[0] = Teach_Pendant_Task_Space_M->odeF[0];
  Teach_Pendant_Task_Space_M->contStates = ((X_Teach_Pendant_Task_Space_T *)
    &Teach_Pendant_Task_Space_X);
  rtsiSetSolverData(&Teach_Pendant_Task_Space_M->solverInfo, (void *)
                    &Teach_Pendant_Task_Space_M->intgData);
  rtsiSetSolverName(&Teach_Pendant_Task_Space_M->solverInfo,"ode1");
  rtmSetTPtr(Teach_Pendant_Task_Space_M,
             &Teach_Pendant_Task_Space_M->Timing.tArray[0]);
  rtmSetTFinal(Teach_Pendant_Task_Space_M, 100.0);
  Teach_Pendant_Task_Space_M->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(Teach_Pendant_Task_Space_M, 1);

  /* External mode info */
  Teach_Pendant_Task_Space_M->Sizes.checksums[0] = (1807107332U);
  Teach_Pendant_Task_Space_M->Sizes.checksums[1] = (3848122483U);
  Teach_Pendant_Task_Space_M->Sizes.checksums[2] = (3956050579U);
  Teach_Pendant_Task_Space_M->Sizes.checksums[3] = (2853076223U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[21];
    Teach_Pendant_Task_Space_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &Teach_Pendant_Task_Space_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[7] = (sysRanDType *)
      &Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[8] = (sysRanDType *)
      &Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[9] = (sysRanDType *)
      &Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = (sysRanDType *)
      &Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Teach_Pendant_Task_Space_M->extModeInfo,
      &Teach_Pendant_Task_Space_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Teach_Pendant_Task_Space_M->extModeInfo,
                        Teach_Pendant_Task_Space_M->Sizes.checksums);
    rteiSetTPtr(Teach_Pendant_Task_Space_M->extModeInfo, rtmGetTPtr
                (Teach_Pendant_Task_Space_M));
  }

  /* block I/O */
  (void) memset(((void *) &Teach_Pendant_Task_Space_B), 0,
                sizeof(B_Teach_Pendant_Task_Space_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      Teach_Pendant_Task_Space_B.Phantom_o2[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      Teach_Pendant_Task_Space_B.best_PID[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      Teach_Pendant_Task_Space_B.worst_PID[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      Teach_Pendant_Task_Space_B.out[i] = 0.0;
    }

    Teach_Pendant_Task_Space_B.UnitDelay[0] = 0.0;
    Teach_Pendant_Task_Space_B.UnitDelay[1] = 0.0;
    Teach_Pendant_Task_Space_B.UnitDelay[2] = 0.0;
    Teach_Pendant_Task_Space_B.JointOffsets[0] = 0.0;
    Teach_Pendant_Task_Space_B.JointOffsets[1] = 0.0;
    Teach_Pendant_Task_Space_B.JointOffsets[2] = 0.0;
    Teach_Pendant_Task_Space_B.Switch[0] = 0.0;
    Teach_Pendant_Task_Space_B.Switch[1] = 0.0;
    Teach_Pendant_Task_Space_B.Switch[2] = 0.0;
    Teach_Pendant_Task_Space_B.Subtract[0] = 0.0;
    Teach_Pendant_Task_Space_B.Subtract[1] = 0.0;
    Teach_Pendant_Task_Space_B.Subtract[2] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation1[0] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation1[1] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation1[2] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation2[0] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation2[1] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation2[2] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation[0] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation[1] = 0.0;
    Teach_Pendant_Task_Space_B.Saturation[2] = 0.0;
    Teach_Pendant_Task_Space_B.Sum1[0] = 0.0;
    Teach_Pendant_Task_Space_B.Sum1[1] = 0.0;
    Teach_Pendant_Task_Space_B.Sum1[2] = 0.0;
    Teach_Pendant_Task_Space_B.Product1[0] = 0.0;
    Teach_Pendant_Task_Space_B.Product1[1] = 0.0;
    Teach_Pendant_Task_Space_B.Product1[2] = 0.0;
    Teach_Pendant_Task_Space_B.Product1_g[0] = 0.0;
    Teach_Pendant_Task_Space_B.Product1_g[1] = 0.0;
    Teach_Pendant_Task_Space_B.Product1_g[2] = 0.0;
    Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[0] = 0.0;
    Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[1] = 0.0;
    Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[2] = 0.0;
    Teach_Pendant_Task_Space_B.x0 = 0.0;
    Teach_Pendant_Task_Space_B.Product[0] = 0.0;
    Teach_Pendant_Task_Space_B.Product[1] = 0.0;
    Teach_Pendant_Task_Space_B.Product[2] = 0.0;
    Teach_Pendant_Task_Space_B.Ki[0] = 0.0;
    Teach_Pendant_Task_Space_B.Ki[1] = 0.0;
    Teach_Pendant_Task_Space_B.Ki[2] = 0.0;
    Teach_Pendant_Task_Space_B.Kd[0] = 0.0;
    Teach_Pendant_Task_Space_B.Kd[1] = 0.0;
    Teach_Pendant_Task_Space_B.Kd[2] = 0.0;
    Teach_Pendant_Task_Space_B.Out = 0.0;
    Teach_Pendant_Task_Space_B.Out_i = 0.0;
    Teach_Pendant_Task_Space_B.Out_p = 0.0;
    Teach_Pendant_Task_Space_B.inter[0] = 0.0;
    Teach_Pendant_Task_Space_B.inter[1] = 0.0;
    Teach_Pendant_Task_Space_B.inter[2] = 0.0;
    Teach_Pendant_Task_Space_B.div[0] = 0.0;
    Teach_Pendant_Task_Space_B.div[1] = 0.0;
    Teach_Pendant_Task_Space_B.div[2] = 0.0;
    Teach_Pendant_Task_Space_B.total_cost = 0.0;
    Teach_Pendant_Task_Space_B.pos[0] = 0.0;
    Teach_Pendant_Task_Space_B.pos[1] = 0.0;
    Teach_Pendant_Task_Space_B.pos[2] = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&Teach_Pendant_Task_Space_X, 0,
                  sizeof(X_Teach_Pendant_Task_Space_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Teach_Pendant_Task_Space_DW, 0,
                sizeof(DW_Teach_Pendant_Task_Space_T));
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[0] = 0.0;
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[1] = 0.0;
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[2] = 0.0;
  Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[0] = 0.0;
  Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[1] = 0.0;
  Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[2] = 0.0;
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h = 0.0;
  Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[0] = 0.0;
  Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[1] = 0.0;
  Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[2] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      Teach_Pendant_Task_Space_DW.particles[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      Teach_Pendant_Task_Space_DW.velocities[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      Teach_Pendant_Task_Space_DW.pbest[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20; i++) {
      Teach_Pendant_Task_Space_DW.pbest_cost[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      Teach_Pendant_Task_Space_DW.gbest[i] = 0.0;
    }
  }

  Teach_Pendant_Task_Space_DW.gbest_cost = 0.0;
  Teach_Pendant_Task_Space_DW.current_particle = 0.0;
  Teach_Pendant_Task_Space_DW.eval_count = 0.0;
  Teach_Pendant_Task_Space_DW.cost_sum = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Teach_Pendant_Task_Space_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (phantom_block): '<S6>/Phantom' */

  /* S-Function Block: Teach_Pendant_Task_Space/PID Control/Phantom (phantom_block) */
  {
    t_error result;

    /* Open and initialize the device. This also schedules the device callback function. */
    result = phantom_open_device(&Teach_Pendant_Task_Space_DW.Phantom_Phantom,
      "Default Device", PHANTOM_ENCODER_OUTPUT, PHANTOM_JOINT_SPACE_INPUT, 0,
      1200, 3, 6);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Teach_Pendant_Task_Space_M, _rt_error_message);
    } else {
      /* Start the scheduler - *****TODO: change the rate to a parameter, just hardcoded at 1000Hz for now. */
      result = phantom_start_scheduler
        (Teach_Pendant_Task_Space_DW.Phantom_Phantom, 1000);
      if (result < 0) {
        phantom_close_device(Teach_Pendant_Task_Space_DW.Phantom_Phantom);
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Teach_Pendant_Task_Space_M, _rt_error_message);
      }
    }
  }

  /* Start for Atomic SubSystem: '<S6>/Bias Removal' */
  /* Start for Enabled SubSystem: '<S10>/Enabled Moving Average' */
  Teach_Pendant_Task_Space_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S10>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S10>/Switch Case' */
  Teach_Pendant_Task_Space_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S6>/Bias Removal' */

  /* Start for Enabled SubSystem: '<S7>/Traject' */
  Teach_Pendant_Task_Space_DW.Traject_MODE = false;

  /* End of Start for SubSystem: '<S7>/Traject' */

  /* Start for Constant: '<S20>/x0' */
  Teach_Pendant_Task_Space_B.x0 = Teach_Pendant_Task_Space_P.x0_Value;

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S25>/FixPt Unit Delay2' */
    Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE =
      Teach_Pendant_Task_Space_P.FixPtUnitDelay2_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[0] =
      Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S25>/FixPt Unit Delay1' */
    Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[0] =
      Teach_Pendant_Task_Space_P.FixPtUnitDelay1_InitialConditio;

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    Teach_Pendant_Task_Space_X.Integrator_CSTATE[0] =
      Teach_Pendant_Task_Space_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S20>/Integrator2' */
    Teach_Pendant_Task_Space_X.Integrator2_CSTATE[0] =
      Teach_Pendant_Task_Space_P.Integrator2_IC;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[1] =
      Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S25>/FixPt Unit Delay1' */
    Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[1] =
      Teach_Pendant_Task_Space_P.FixPtUnitDelay1_InitialConditio;

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    Teach_Pendant_Task_Space_X.Integrator_CSTATE[1] =
      Teach_Pendant_Task_Space_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S20>/Integrator2' */
    Teach_Pendant_Task_Space_X.Integrator2_CSTATE[1] =
      Teach_Pendant_Task_Space_P.Integrator2_IC;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE[2] =
      Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S25>/FixPt Unit Delay1' */
    Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[2] =
      Teach_Pendant_Task_Space_P.FixPtUnitDelay1_InitialConditio;

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    Teach_Pendant_Task_Space_X.Integrator_CSTATE[2] =
      Teach_Pendant_Task_Space_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S20>/Integrator2' */
    Teach_Pendant_Task_Space_X.Integrator2_CSTATE[2] =
      Teach_Pendant_Task_Space_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S20>/Integrator1' */
    if (rtmIsFirstInitCond(Teach_Pendant_Task_Space_M)) {
      Teach_Pendant_Task_Space_X.Integrator1_CSTATE[0] = 0.0;
      Teach_Pendant_Task_Space_X.Integrator1_CSTATE[1] = 0.0;
      Teach_Pendant_Task_Space_X.Integrator1_CSTATE[2] = 0.0;
    }

    Teach_Pendant_Task_Space_DW.Integrator1_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S20>/Integrator1' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Bias Removal' */
    /* SystemInitialize for Enabled SubSystem: '<S10>/Enabled Moving Average' */
    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
    Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h =
      Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
    Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[0] =
      Teach_Pendant_Task_Space_P.Sumk1n1xk_InitialCondition;
    Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[1] =
      Teach_Pendant_Task_Space_P.Sumk1n1xk_InitialCondition;
    Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[2] =
      Teach_Pendant_Task_Space_P.Sumk1n1xk_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S10>/Enabled Moving Average' */
    /* End of SystemInitialize for SubSystem: '<S6>/Bias Removal' */

    /* SystemInitialize for Enabled SubSystem: '<S7>/Traject' */
    /* InitializeConditions for UnitDelay: '<S29>/Output' */
    Teach_Pendant_Task_Space_DW.Output_DSTATE =
      Teach_Pendant_Task_Space_P.Output_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S32>/Output' */
    Teach_Pendant_Task_Space_DW.Output_DSTATE_j =
      Teach_Pendant_Task_Space_P.Output_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S35>/Output' */
    Teach_Pendant_Task_Space_DW.Output_DSTATE_c =
      Teach_Pendant_Task_Space_P.Output_InitialCondition_b;

    /* End of SystemInitialize for SubSystem: '<S7>/Traject' */

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    Teach_Pendant_Task_Space_DW.cost_sum = 0.0;

    /* SystemInitialize for MATLAB Function: '<Root>/pid auto tuner' */
    Teach_Pendant_Task_Space_DW.initialized_not_empty = false;
    Teach_Pendant_Task_Space_DW.state_not_empty = false;
    Teach_Pendant_Task_Space_DW.method = 7U;
    Teach_Pendant_Task_Space_DW.state = 1144108930U;
    Teach_Pendant_Task_Space_DW.state_g[0] = 362436069U;
    Teach_Pendant_Task_Space_DW.state_g[1] = 521288629U;
    for (i = 0; i < 120; i++) {
      Teach_Pendant_Task_Space_DW.velocities[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      Teach_Pendant_Task_Space_DW.pbest_cost[i] = (rtInf);
    }

    Teach_Pendant_Task_Space_DW.gbest_cost = (rtInf);
    Teach_Pendant_Task_Space_DW.current_particle = 1.0;
    Teach_Pendant_Task_Space_DW.eval_count = 0.0;
    Teach_Pendant_Task_Space_DW.in_zone_prev = false;

    /* End of SystemInitialize for MATLAB Function: '<Root>/pid auto tuner' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(Teach_Pendant_Task_Space_M)) {
      rtmSetFirstInitCond(Teach_Pendant_Task_Space_M, 0);
    }
  }
}

/* Model terminate function */
void Teach_Pendant_Task_Space_terminate(void)
{
  /* Terminate for S-Function (phantom_block): '<S6>/Phantom' */

  /* S-Function Block: Teach_Pendant_Task_Space/PID Control/Phantom (phantom_block) */
  {
    t_error result;
    if ((result = phantom_stop_scheduler
         (Teach_Pendant_Task_Space_DW.Phantom_Phantom)) < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Teach_Pendant_Task_Space_M, _rt_error_message);
    }

    if ((result = phantom_close_device
         (Teach_Pendant_Task_Space_DW.Phantom_Phantom)) < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Teach_Pendant_Task_Space_M, _rt_error_message);
    }
  }
}
