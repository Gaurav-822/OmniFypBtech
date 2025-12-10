/*
 * Teach_Pendant_Task_Space.c
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
static void Teach_Pendant_Task_Space_rand(real_T r[1200]);
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
static void Teach_Pendant_Task_Space_rand(real_T r[1200])
{
  uint32_T b_r;
  int32_T mti;
  uint32_T e;
  if (Teach_Pendant_Task_Space_DW.method == 4U) {
    for (mti = 0; mti < 1200; mti++) {
      r[mti] = Teach_Pendant_eml_rand_mcg16807
        (&Teach_Pendant_Task_Space_DW.state);
    }
  } else if (Teach_Pendant_Task_Space_DW.method == 5U) {
    for (mti = 0; mti < 1200; mti++) {
      b_r = 69069U * Teach_Pendant_Task_Space_DW.state_k[0] + 1234567U;
      e = Teach_Pendant_Task_Space_DW.state_k[1] << 13 ^
        Teach_Pendant_Task_Space_DW.state_k[1];
      e ^= e >> 17;
      e ^= e << 5;
      Teach_Pendant_Task_Space_DW.state_k[0] = b_r;
      Teach_Pendant_Task_Space_DW.state_k[1] = e;
      r[mti] = (real_T)(b_r + e) * 2.328306436538696E-10;
    }
  } else {
    if (!Teach_Pendant_Task_Space_DW.state_not_empty) {
      memset(&Teach_Pendant_Task_Space_DW.state_j[0], 0, 625U * sizeof(uint32_T));
      b_r = 5489U;
      Teach_Pendant_Task_Space_DW.state_j[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r >> 30U ^ b_r) * 1812433253U + mti) + 1U;
        Teach_Pendant_Task_Space_DW.state_j[mti + 1] = b_r;
      }

      Teach_Pendant_Task_Space_DW.state_j[624] = 624U;
      Teach_Pendant_Task_Space_DW.state_not_empty = true;
    }

    for (mti = 0; mti < 1200; mti++) {
      r[mti] = Teach_Pendan_eml_rand_mt19937ar
        (Teach_Pendant_Task_Space_DW.state_j);
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
      b_r = 69069U * Teach_Pendant_Task_Space_DW.state_k[0] + 1234567U;
      e = Teach_Pendant_Task_Space_DW.state_k[1] << 13 ^
        Teach_Pendant_Task_Space_DW.state_k[1];
      e ^= e >> 17;
      e ^= e << 5;
      Teach_Pendant_Task_Space_DW.state_k[0] = b_r;
      Teach_Pendant_Task_Space_DW.state_k[1] = e;
      r[mti] = (real_T)(b_r + e) * 2.328306436538696E-10;
    }
  } else {
    if (!Teach_Pendant_Task_Space_DW.state_not_empty) {
      memset(&Teach_Pendant_Task_Space_DW.state_j[0], 0, 625U * sizeof(uint32_T));
      b_r = 5489U;
      Teach_Pendant_Task_Space_DW.state_j[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r >> 30U ^ b_r) * 1812433253U + mti) + 1U;
        Teach_Pendant_Task_Space_DW.state_j[mti + 1] = b_r;
      }

      Teach_Pendant_Task_Space_DW.state_j[624] = 624U;
      Teach_Pendant_Task_Space_DW.state_not_empty = true;
    }

    for (mti = 0; mti < 6; mti++) {
      r[mti] = Teach_Pendan_eml_rand_mt19937ar
        (Teach_Pendant_Task_Space_DW.state_j);
    }
  }
}

/* Model step function */
void Teach_Pendant_Task_Space_step(void)
{
  real_T total_length;
  boolean_T rEQ0;
  real_T q;
  real_T tool[12];
  int32_T iy;
  int8_T catArgs_f2[4];
  real_T T_tool[16];
  real_T r2[6];
  boolean_T trigger;
  real_T h_v;
  real_T i_v;
  real_T j_v;
  real_T k_v;
  real_T l_v;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T x;
  real_T d;
  real_T k;
  real_T rtb_GearRatio[3];
  real_T rtb_EncoderOffsets[6];
  int8_T rtAction;
  real_T rtb_tool_offset[16];
  uint16_T rtb_FixPtSum1;
  uint16_T rtb_FixPtSwitch;
  uint16_T rtb_FixPtSwitch_h;
  int8_T T_tool_tmp[16];
  int8_T T_tool_tmp_0[4];
  real_T T_tool_tmp_1;
  int8_T T_tool_tmp_2[16];
  int32_T i;
  real_T d_0[9];
  real_T d_1[9];
  real_T d_2[9];
  real_T k_0[16];
  real_T k_1[16];
  real_T k_2[16];
  real_T T_tool_tmp_3[16];
  real_T total_length_tmp;
  int32_T d_tmp;
  int32_T k_tmp;
  int32_T k_tmp_0;
  real_T total_length_tmp_0;
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
    /* Sum: '<Root>/Add' incorporates:
     *  Constant: '<Root>/Constant4'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    Teach_Pendant_Task_Space_B.Add = (real_T)
      Teach_Pendant_Task_Space_P.Constant4_Value +
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE;

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/gives the length of all the segments needed by const_pid to detect which segment is robot is in currently'
     *  MATLAB Function: '<Root>/MATLAB Function'
     *  MATLAB Function: '<Root>/pid auto tuner'
     */
    Teach_Pendant_Task_Space_B.Ki_g[0] = 1.629;
    Teach_Pendant_Task_Space_B.Kd_f[0] = 0.0801;
    Teach_Pendant_Task_Space_B.Ki_g[1] = 1.311;
    Teach_Pendant_Task_Space_B.Kd_f[1] = 0.04813;
    Teach_Pendant_Task_Space_B.Ki_g[2] = 1.316;
    Teach_Pendant_Task_Space_B.Kd_f[2] = 0.004055;

    /* MATLAB Function 'MATLAB Function1': '<S5>:1' */
    /* '<S5>:1:13' */
    total_length_tmp = Teach_Pendant_Task_Space_P.segment_lengths[0] +
      Teach_Pendant_Task_Space_P.segment_lengths[1];
    total_length_tmp_0 = total_length_tmp +
      Teach_Pendant_Task_Space_P.segment_lengths[2];
    iy = 2;

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/gives the length of all the segments needed by const_pid to detect which segment is robot is in currently'
     */
    /* '<S5>:1:16' */
    k = Teach_Pendant_Task_Space_B.Add - 1.0;
    if (total_length_tmp_0 == 0.0) {
      if (Teach_Pendant_Task_Space_B.Add - 1.0 == 0.0) {
        k = total_length_tmp_0;
      }
    } else if (rtIsNaN(Teach_Pendant_Task_Space_B.Add - 1.0) || rtIsNaN
               (total_length_tmp_0) || rtIsInf(Teach_Pendant_Task_Space_B.Add -
                1.0)) {
      k = (rtNaN);
    } else if (Teach_Pendant_Task_Space_B.Add - 1.0 == 0.0) {
      k = 0.0 / total_length_tmp_0;
    } else if (rtIsInf(total_length_tmp_0)) {
      if ((Teach_Pendant_Task_Space_B.Add - 1.0 < 0.0) != (total_length_tmp_0 <
           0.0)) {
        k = total_length_tmp_0;
      }
    } else {
      k = fmod(Teach_Pendant_Task_Space_B.Add - 1.0, total_length_tmp_0);
      rEQ0 = (k == 0.0);
      if ((!rEQ0) && (total_length_tmp_0 > floor(total_length_tmp_0))) {
        q = fabs((Teach_Pendant_Task_Space_B.Add - 1.0) / total_length_tmp_0);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        k = total_length_tmp_0 * 0.0;
      } else {
        if ((Teach_Pendant_Task_Space_B.Add - 1.0 < 0.0) != (total_length_tmp_0 <
             0.0)) {
          k += total_length_tmp_0;
        }
      }
    }

    /* '<S5>:1:19' */
    /* '<S5>:1:20' */
    if (k + 1.0 <= Teach_Pendant_Task_Space_P.segment_lengths[0]) {
      /* '<S5>:1:23' */
      /* '<S5>:1:24' */
      iy = 1;

      /* '<S5>:1:25' */
      Teach_Pendant_Task_Space_B.Kp_p[0] = 1.79;
      Teach_Pendant_Task_Space_B.Kp_p[1] = 1.46;
      Teach_Pendant_Task_Space_B.Kp_p[2] = 0.6;

      /* '<S5>:1:26' */
      /* '<S5>:1:27' */
    } else if (k + 1.0 <= total_length_tmp) {
      /* '<S5>:1:29' */
      /* '<S5>:1:30' */
      /* '<S5>:1:31' */
      Teach_Pendant_Task_Space_B.Kp_p[0] = 1.8;
      Teach_Pendant_Task_Space_B.Kp_p[1] = 1.46;
      Teach_Pendant_Task_Space_B.Kp_p[2] = 0.6;

      /* '<S5>:1:32' */
      /* '<S5>:1:33' */
    } else {
      /* '<S5>:1:37' */
      iy = 3;

      /* '<S5>:1:38' */
      Teach_Pendant_Task_Space_B.Kp_p[0] = 1.81;
      Teach_Pendant_Task_Space_B.Kp_p[1] = 1.46;
      Teach_Pendant_Task_Space_B.Kp_p[2] = 0.6;

      /* '<S5>:1:39' */
      /* '<S5>:1:40' */
    }

    if (iy != Teach_Pendant_Task_Space_DW.last_seg) {
      /* '<S5>:1:45' */
      /* '<S5>:1:51' */
      Teach_Pendant_Task_Space_DW.last_seg = iy;
    }

    Teach_Pendant_Task_Space_B.current_seg_b = iy;

    /* UnitDelay: '<S6>/Unit Delay' */
    Teach_Pendant_Task_Space_B.UnitDelay[0] =
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[0];
    Teach_Pendant_Task_Space_B.UnitDelay[1] =
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[1];
    Teach_Pendant_Task_Space_B.UnitDelay[2] =
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[2];

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
    k = (((Teach_Pendant_Task_Space_M->Timing.clockTick1+
           Teach_Pendant_Task_Space_M->Timing.clockTickH1* 4294967296.0)) *
         0.001);
    if (k < Teach_Pendant_Task_Space_P.BiasRemoval_start_time) {
      q = Teach_Pendant_Task_Space_P.Stepstart_time_Y0;
    } else {
      q = Teach_Pendant_Task_Space_P.Stepstart_time_YFinal;
    }

    /* End of Step: '<S10>/Step: start_time' */

    /* Step: '<S10>/Step: end_time' */
    if (k < Teach_Pendant_Task_Space_P.BiasRemoval_end_time) {
      k = Teach_Pendant_Task_Space_P.Stepend_time_Y0;
    } else {
      k = Teach_Pendant_Task_Space_P.Stepend_time_YFinal;
    }

    /* Outputs for Enabled SubSystem: '<S10>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    /* Logic: '<S10>/Logical Operator' incorporates:
     *  Logic: '<S10>/Logical Operator1'
     */
    if ((q != 0.0) && (!(k != 0.0))) {
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
      total_length = Teach_Pendant_Task_Space_P.unity_Value +
        Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h;

      /* Update for UnitDelay: '<S18>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h = total_length;

      /* Sum: '<S14>/Sum' incorporates:
       *  UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )'
       */
      k = Teach_Pendant_Task_Space_B.JointOffsets[0] +
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[0];

      /* Product: '<S14>/div' */
      Teach_Pendant_Task_Space_B.div[0] = k / total_length;

      /* Update for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
      Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[0] = k;

      /* Sum: '<S14>/Sum' incorporates:
       *  UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )'
       */
      k = Teach_Pendant_Task_Space_B.JointOffsets[1] +
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[1];

      /* Product: '<S14>/div' */
      Teach_Pendant_Task_Space_B.div[1] = k / total_length;

      /* Update for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
      Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[1] = k;

      /* Sum: '<S14>/Sum' incorporates:
       *  UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )'
       */
      k = Teach_Pendant_Task_Space_B.JointOffsets[2] +
        Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[2];

      /* Product: '<S14>/div' */
      Teach_Pendant_Task_Space_B.div[2] = k / total_length;

      /* Update for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
      Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[2] = k;
      srUpdateBC(Teach_Pendant_Task_Space_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      Teach_Pendant_Task_Space_DW.EnabledMovingAverage_MODE = false;
    }

    /* End of Logic: '<S10>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S10>/Enabled Moving Average' */

    /* SwitchCase: '<S10>/Switch Case' */
    rtAction = -1;
    if (Teach_Pendant_Task_Space_P.BiasRemoval_switch_id < 0.0) {
      k = ceil(Teach_Pendant_Task_Space_P.BiasRemoval_switch_id);
    } else {
      k = floor(Teach_Pendant_Task_Space_P.BiasRemoval_switch_id);
    }

    if (rtIsNaN(k) || rtIsInf(k)) {
      k = 0.0;
    } else {
      k = fmod(k, 4.294967296E+9);
    }

    switch (k < 0.0 ? -(int32_T)(uint32_T)-k : (int32_T)(uint32_T)k) {
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
    total_length = sin(rtb_GearRatio[0]);
    k = cos(rtb_GearRatio[0]);
    q = sin(rtb_GearRatio[1]);
    d = cos(rtb_GearRatio[1]);
    d_0[1] = 0.0;
    d_0[4] = k;
    d_0[7] = -total_length;
    d_0[2] = 0.0;
    d_0[5] = total_length;
    d_0[8] = k;
    d_1[0] = d;
    d_1[3] = -q;
    d_1[6] = 0.0;
    d_1[1] = q;
    d_1[4] = d;
    d_1[7] = 0.0;
    d_0[0] = 1.0;
    d_1[2] = 0.0;
    d_0[3] = 0.0;
    d_1[5] = 0.0;
    d_0[6] = 0.0;
    d_1[8] = 1.0;
    for (i = 0; i < 3; i++) {
      rtb_GearRatio[i] = 0.0;
      for (iy = 0; iy < 3; iy++) {
        d_tmp = i + 3 * iy;
        d_2[d_tmp] = 0.0;
        d_2[d_tmp] += d_1[3 * iy] * d_0[i];
        d_2[d_tmp] += d_1[3 * iy + 1] * d_0[i + 3];
        d_2[d_tmp] += d_1[3 * iy + 2] * d_0[i + 6];
        rtb_GearRatio[i] += d_2[d_tmp] * b[iy];
      }
    }

    /* '<S13>:1:32' */
    iy = -1;
    for (i = 0; i < 9; i++) {
      iy++;
      tool[iy] = c[i];
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
    rEQ0 = (Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE != 0);

    /* MATLAB Function: '<S7>/Forward Kinematics' */
    k = cos(Teach_Pendant_Task_Space_B.div[0]);
    k_0[0] = k;
    q = sin(Teach_Pendant_Task_Space_B.div[0]);
    k_0[4] = -q;
    k_0[8] = 0.0;
    k_0[12] = 0.0;
    k_0[1] = q;
    k_0[5] = k;
    k_0[9] = 0.0;
    k_0[13] = 0.0;
    for (iy = 0; iy < 4; iy++) {
      /* MATLAB Function: '<S6>/Tool Offset' incorporates:
       *  MATLAB Function: '<S7>/Forward Kinematics'
       */
      i = iy << 2;
      rtb_tool_offset[i] = tool[3 * iy];
      rtb_tool_offset[i + 1] = tool[3 * iy + 1];
      d_tmp = i + 2;
      rtb_tool_offset[d_tmp] = tool[3 * iy + 2];
      i += 3;
      rtb_tool_offset[i] = varargin_2[iy];

      /* MATLAB Function: '<S7>/Forward Kinematics' */
      k_0[d_tmp] = b_0[iy];
      k_0[i] = varargin_2[iy];
    }

    /* MATLAB Function: '<S7>/Forward Kinematics' */
    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        T_tool[k_tmp] = 0.0;
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp] * k_0[i];
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp + 1] * k_0[i + 4];
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp + 2] * k_0[i + 8];
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp + 3] * k_0[i + 12];
      }

      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        T_tool_tmp_3[k_tmp] = 0.0;
        T_tool_tmp_3[k_tmp] += (real_T)A_T_z[d_tmp] * T_tool[i];
        T_tool_tmp_3[k_tmp] += (real_T)A_T_z[d_tmp + 1] * T_tool[i + 4];
        T_tool_tmp_3[k_tmp] += (real_T)A_T_z[d_tmp + 2] * T_tool[i + 8];
        T_tool_tmp_3[k_tmp] += (real_T)A_T_z[d_tmp + 3] * T_tool[i + 12];
      }
    }

    k = cos(Teach_Pendant_Task_Space_B.div[1]);
    k_0[0] = k;
    q = sin(Teach_Pendant_Task_Space_B.div[1]);
    k_0[4] = -q;
    k_0[8] = 0.0;
    k_0[12] = 0.0;
    k_0[1] = q;
    k_0[5] = k;
    k_0[9] = 0.0;
    k_0[13] = 0.0;
    k_0[2] = 0.0;
    k_0[3] = 0.0;
    k_0[6] = 0.0;
    k_0[7] = 0.0;
    k_0[10] = 1.0;
    k_0[11] = 0.0;
    k_0[14] = 0.0;
    k_0[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        T_tool[k_tmp] = 0.0;
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp] * k_0[i];
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp + 1] * k_0[i + 4];
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp + 2] * k_0[i + 8];
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp + 3] * k_0[i + 12];
      }

      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        k_1[k_tmp] = 0.0;
        k_1[k_tmp] += A_T_x[d_tmp] * T_tool[i];
        k_1[k_tmp] += A_T_x[d_tmp + 1] * T_tool[i + 4];
        k_1[k_tmp] += A_T_x[d_tmp + 2] * T_tool[i + 8];
        k_1[k_tmp] += A_T_x[d_tmp + 3] * T_tool[i + 12];
      }
    }

    k = cos(Teach_Pendant_Task_Space_B.div[2] - 1.5707963267948966);
    k_2[0] = k;
    q = sin(Teach_Pendant_Task_Space_B.div[2] - 1.5707963267948966);
    k_2[4] = -q;
    k_2[8] = 0.0;
    k_2[12] = 0.0;
    k_2[1] = q;
    k_2[5] = k;
    k_2[9] = 0.0;
    k_2[13] = 0.0;
    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        k_0[k_tmp] = 0.0;
        T_tool[k_tmp] = 0.0;
        k_0[k_tmp] += A_R_x[d_tmp] * T_tool_tmp_3[i];
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp] * k_1[i];
        k_tmp_0 = d_tmp + 1;
        k_0[k_tmp] += A_R_x[k_tmp_0] * T_tool_tmp_3[i + 4];
        T_tool[k_tmp] += (real_T)A_T_z[k_tmp_0] * k_1[i + 4];
        k_tmp_0 = d_tmp + 2;
        k_0[k_tmp] += A_R_x[k_tmp_0] * T_tool_tmp_3[i + 8];
        T_tool[k_tmp] += (real_T)A_T_z[k_tmp_0] * k_1[i + 8];
        d_tmp += 3;
        k_0[k_tmp] += A_R_x[d_tmp] * T_tool_tmp_3[i + 12];
        T_tool[k_tmp] += (real_T)A_T_z[d_tmp] * k_1[i + 12];
      }

      iy = i << 2;
      k_2[iy + 2] = b_0[i];
      k_2[iy + 3] = varargin_2[i];
    }

    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        T_tool_tmp_3[k_tmp] = 0.0;
        T_tool_tmp_3[k_tmp] += (real_T)A_T_z[d_tmp] * k_2[i];
        T_tool_tmp_3[k_tmp] += (real_T)A_T_z[d_tmp + 1] * k_2[i + 4];
        T_tool_tmp_3[k_tmp] += (real_T)A_T_z[d_tmp + 2] * k_2[i + 8];
        T_tool_tmp_3[k_tmp] += (real_T)A_T_z[d_tmp + 3] * k_2[i + 12];
      }

      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        k_1[k_tmp] = 0.0;
        k_1[k_tmp] += A_T_x[d_tmp] * T_tool_tmp_3[i];
        k_1[k_tmp] += A_T_x[d_tmp + 1] * T_tool_tmp_3[i + 4];
        k_1[k_tmp] += A_T_x[d_tmp + 2] * T_tool_tmp_3[i + 8];
        k_1[k_tmp] += A_T_x[d_tmp + 3] * T_tool_tmp_3[i + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = i << 2;
        k_tmp = iy + d_tmp;
        T_tool_tmp_3[k_tmp] = 0.0;
        k_2[k_tmp] = 0.0;
        T_tool_tmp_3[k_tmp] += T_tool[d_tmp] * k_0[iy];
        k_2[k_tmp] += (real_T)A_T_z[d_tmp] * k_1[iy];
        k_tmp_0 = d_tmp + 1;
        T_tool_tmp_3[k_tmp] += T_tool[k_tmp_0] * k_0[iy + 4];
        k_2[k_tmp] += (real_T)A_T_z[k_tmp_0] * k_1[iy + 4];
        k_tmp_0 = d_tmp + 2;
        T_tool_tmp_3[k_tmp] += T_tool[k_tmp_0] * k_0[iy + 8];
        k_2[k_tmp] += (real_T)A_T_z[k_tmp_0] * k_1[iy + 8];
        d_tmp += 3;
        T_tool_tmp_3[k_tmp] += T_tool[d_tmp] * k_0[iy + 12];
        k_2[k_tmp] += (real_T)A_T_z[d_tmp] * k_1[iy + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        k_0[k_tmp] = 0.0;
        k_0[k_tmp] += k_2[d_tmp] * T_tool_tmp_3[i];
        k_0[k_tmp] += k_2[d_tmp + 1] * T_tool_tmp_3[i + 4];
        k_0[k_tmp] += k_2[d_tmp + 2] * T_tool_tmp_3[i + 8];
        k_0[k_tmp] += k_2[d_tmp + 3] * T_tool_tmp_3[i + 12];
      }

      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        T_tool[k_tmp] = 0.0;
        T_tool[k_tmp] += rtb_tool_offset[d_tmp] * k_0[i];
        T_tool[k_tmp] += rtb_tool_offset[d_tmp + 1] * k_0[i + 4];
        T_tool[k_tmp] += rtb_tool_offset[d_tmp + 2] * k_0[i + 8];
        T_tool[k_tmp] += rtb_tool_offset[d_tmp + 3] * k_0[i + 12];
      }
    }

    /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S7>/speed'
     */
    /* MATLAB Function 'Trajectory Planning/Linear Trajectory/Embedded MATLAB Function': '<S24>:1' */
    /* '<S24>:1:3' */
    total_length = Teach_Pendant_Task_Space_P.speed_Value *
      Teach_Pendant_Task_Space_P.Constant2_Value;

    /* Switch: '<S25>/Init' incorporates:
     *  MATLAB Function: '<S7>/Forward Kinematics'
     *  UnitDelay: '<S25>/FixPt Unit Delay1'
     */
    /* '<S24>:1:4' */
    /* '<S24>:1:7' */
    if (rEQ0) {
      k = T_tool[12];
    } else {
      k = Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[0];
    }

    /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S7>/first point'
     */
    q = Teach_Pendant_Task_Space_P.firstpoint_Value[0] - k;
    Teach_Pendant_Task_Space_B.inter[0] = q;
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
      total_length + k;

    /* '<S24>:1:7' */
    if (fabs(q) < total_length) {
      /* '<S24>:1:8' */
      /* '<S24>:1:9' */
      Teach_Pendant_Task_Space_B.inter[0] =
        Teach_Pendant_Task_Space_P.firstpoint_Value[0];
    }

    /* Switch: '<S25>/Init' incorporates:
     *  MATLAB Function: '<S7>/Forward Kinematics'
     *  UnitDelay: '<S25>/FixPt Unit Delay1'
     */
    if (rEQ0) {
      k = T_tool[13];
    } else {
      k = Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[1];
    }

    /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S7>/first point'
     */
    q = Teach_Pendant_Task_Space_P.firstpoint_Value[1] - k;
    Teach_Pendant_Task_Space_B.inter[1] = q;
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
      total_length + k;

    /* '<S24>:1:7' */
    if (fabs(q) < total_length) {
      /* '<S24>:1:8' */
      /* '<S24>:1:9' */
      Teach_Pendant_Task_Space_B.inter[1] =
        Teach_Pendant_Task_Space_P.firstpoint_Value[1];
    }

    /* Switch: '<S25>/Init' incorporates:
     *  MATLAB Function: '<S7>/Forward Kinematics'
     *  UnitDelay: '<S25>/FixPt Unit Delay1'
     */
    if (rEQ0) {
      k = T_tool[14];
    } else {
      k = Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[2];
    }

    /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S7>/first point'
     */
    q = Teach_Pendant_Task_Space_P.firstpoint_Value[2] - k;
    Teach_Pendant_Task_Space_B.inter[2] = q;
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
      total_length + k;

    /* '<S24>:1:7' */
    if (fabs(q) < total_length) {
      /* '<S24>:1:8' */
      /* '<S24>:1:9' */
      Teach_Pendant_Task_Space_B.inter[2] =
        Teach_Pendant_Task_Space_P.firstpoint_Value[2];
    }

    /* Logic: '<S7>/Logical Operator' incorporates:
     *  Constant: '<S7>/first point'
     *  RelationalOperator: '<S7>/Relational Operator'
     */
    rEQ0 = ((Teach_Pendant_Task_Space_P.firstpoint_Value[0] ==
             Teach_Pendant_Task_Space_B.inter[0]) &&
            (Teach_Pendant_Task_Space_P.firstpoint_Value[1] ==
             Teach_Pendant_Task_Space_B.inter[1]) &&
            (Teach_Pendant_Task_Space_P.firstpoint_Value[2] ==
             Teach_Pendant_Task_Space_B.inter[2]));

    /* Outputs for Enabled SubSystem: '<S7>/Traject' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (rtmIsMajorTimeStep(Teach_Pendant_Task_Space_M)) {
      if (rEQ0) {
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
    if (rEQ0) {
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
    /* MATLAB Function 'Forward Kinematics': '<S2>:1' */
    /* '<S2>:1:11' */
    /* '<S2>:1:32' */
    /* '<S2>:1:33' */
    /* '<S2>:1:35' */
    /* '<S2>:1:36' */
    /* '<S2>:1:30' */
    /* '<S2>:1:42' */
    /* '<S2>:1:47' */
    /* '<S2>:1:52' */
    /* '<S2>:1:12' */
    /* '<S2>:1:32' */
    /* '<S2>:1:33' */
    /* '<S2>:1:35' */
    /* '<S2>:1:36' */
    /* '<S2>:1:30' */
    /* '<S2>:1:42' */
    /* '<S2>:1:47' */
    /* '<S2>:1:52' */
    /* '<S2>:1:13' */
    /* '<S2>:1:32' */
    /* '<S2>:1:33' */
    /* '<S2>:1:35' */
    /* '<S2>:1:36' */
    /* '<S2>:1:30' */
    /* '<S2>:1:42' */
    /* '<S2>:1:47' */
    /* '<S2>:1:52' */
    /* '<S2>:1:17' */
    /* '<S2>:1:18' */
    /* '<S2>:1:21' */
    total_length = sin(Teach_Pendant_Task_Space_B.JointOffsets[0]);
    k = cos(Teach_Pendant_Task_Space_B.JointOffsets[0]);
    q = sin(Teach_Pendant_Task_Space_B.JointOffsets[1]);
    d = cos(Teach_Pendant_Task_Space_B.JointOffsets[1]);
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

    k_0[0] = k;
    k_0[4] = -total_length;
    k_0[8] = 0.0;
    k_0[12] = 0.0;
    k_0[1] = total_length;
    k_0[5] = k;
    k_0[9] = 0.0;
    k_0[13] = 0.0;
    k_0[2] = 0.0;
    k_0[3] = 0.0;
    k_0[6] = 0.0;
    k_0[7] = 0.0;
    k_0[10] = 1.0;
    k_0[11] = 0.0;
    k_0[14] = 0.0;
    k_0[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        k_1[k_tmp] = 0.0;
        k_1[k_tmp] += (real_T)T_tool_tmp[d_tmp] * k_0[i];
        k_1[k_tmp] += (real_T)T_tool_tmp[d_tmp + 1] * k_0[i + 4];
        k_1[k_tmp] += (real_T)T_tool_tmp[d_tmp + 2] * k_0[i + 8];
        k_1[k_tmp] += (real_T)T_tool_tmp[d_tmp + 3] * k_0[i + 12];
      }

      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        k_2[k_tmp] = 0.0;
        k_2[k_tmp] += (real_T)T_tool_tmp[d_tmp] * k_1[i];
        k_2[k_tmp] += (real_T)T_tool_tmp[d_tmp + 1] * k_1[i + 4];
        k_2[k_tmp] += (real_T)T_tool_tmp[d_tmp + 2] * k_1[i + 8];
        k_2[k_tmp] += (real_T)T_tool_tmp[d_tmp + 3] * k_1[i + 12];
      }
    }

    T_tool[0] = d;
    T_tool[4] = -q;
    T_tool[8] = 0.0;
    T_tool[12] = 0.0;
    T_tool[1] = q;
    T_tool[5] = d;
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
      for (iy = 0; iy < 4; iy++) {
        k_tmp = iy << 2;
        d_tmp = i + k_tmp;
        k_0[d_tmp] = 0.0;
        k_0[d_tmp] += (real_T)T_tool_tmp[k_tmp] * T_tool[i];
        k_0[d_tmp] += (real_T)T_tool_tmp[k_tmp + 1] * T_tool[i + 4];
        k_0[d_tmp] += (real_T)T_tool_tmp[k_tmp + 2] * T_tool[i + 8];
        k_0[d_tmp] += (real_T)T_tool_tmp[k_tmp + 3] * T_tool[i + 12];
      }

      for (iy = 0; iy < 4; iy++) {
        k_tmp = iy << 2;
        d_tmp = i + k_tmp;
        k_1[d_tmp] = 0.0;
        k_1[d_tmp] += A_T_x[k_tmp] * k_0[i];
        k_1[d_tmp] += A_T_x[k_tmp + 1] * k_0[i + 4];
        k_1[d_tmp] += A_T_x[k_tmp + 2] * k_0[i + 8];
        k_1[d_tmp] += A_T_x[k_tmp + 3] * k_0[i + 12];
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
      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        k_0[k_tmp] = 0.0;
        T_tool[k_tmp] = 0.0;
        k_0[k_tmp] += A_R_x[d_tmp] * k_2[i];
        T_tool[k_tmp] += (real_T)T_tool_tmp_2[d_tmp] * k_1[i];
        k_tmp_0 = d_tmp + 1;
        k_0[k_tmp] += A_R_x[k_tmp_0] * k_2[i + 4];
        T_tool[k_tmp] += (real_T)T_tool_tmp_2[k_tmp_0] * k_1[i + 4];
        k_tmp_0 = d_tmp + 2;
        k_0[k_tmp] += A_R_x[k_tmp_0] * k_2[i + 8];
        T_tool[k_tmp] += (real_T)T_tool_tmp_2[k_tmp_0] * k_1[i + 8];
        k_tmp_0 = d_tmp + 3;
        k_0[k_tmp] += A_R_x[k_tmp_0] * k_2[i + 12];
        T_tool[k_tmp] += (real_T)T_tool_tmp_2[k_tmp_0] * k_1[i + 12];
      }

      d_tmp = i << 2;
      T_tool_tmp_3[d_tmp + 2] = catArgs_f2[i];
      T_tool_tmp_3[d_tmp + 3] = T_tool_tmp_0[i];
    }

    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        k_tmp = iy << 2;
        d_tmp = i + k_tmp;
        k_1[d_tmp] = 0.0;
        k_1[d_tmp] += (real_T)T_tool_tmp[k_tmp] * T_tool_tmp_3[i];
        k_1[d_tmp] += (real_T)T_tool_tmp[k_tmp + 1] * T_tool_tmp_3[i + 4];
        k_1[d_tmp] += (real_T)T_tool_tmp[k_tmp + 2] * T_tool_tmp_3[i + 8];
        k_1[d_tmp] += (real_T)T_tool_tmp[k_tmp + 3] * T_tool_tmp_3[i + 12];
      }

      for (iy = 0; iy < 4; iy++) {
        k_tmp = iy << 2;
        d_tmp = i + k_tmp;
        k_2[d_tmp] = 0.0;
        k_2[d_tmp] += A_T_x[k_tmp] * k_1[i];
        k_2[d_tmp] += A_T_x[k_tmp + 1] * k_1[i + 4];
        k_2[d_tmp] += A_T_x[k_tmp + 2] * k_1[i + 8];
        k_2[d_tmp] += A_T_x[k_tmp + 3] * k_1[i + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = i << 2;
        k_tmp = iy + d_tmp;
        k_1[k_tmp] = 0.0;
        T_tool_tmp_3[k_tmp] = 0.0;
        k_1[k_tmp] += T_tool[d_tmp] * k_0[iy];
        T_tool_tmp_3[k_tmp] += (real_T)T_tool_tmp_2[d_tmp] * k_2[iy];
        k_tmp_0 = d_tmp + 1;
        k_1[k_tmp] += T_tool[k_tmp_0] * k_0[iy + 4];
        T_tool_tmp_3[k_tmp] += (real_T)T_tool_tmp_2[k_tmp_0] * k_2[iy + 4];
        k_tmp_0 = d_tmp + 2;
        k_1[k_tmp] += T_tool[k_tmp_0] * k_0[iy + 8];
        T_tool_tmp_3[k_tmp] += (real_T)T_tool_tmp_2[k_tmp_0] * k_2[iy + 8];
        k_tmp_0 = d_tmp + 3;
        k_1[k_tmp] += T_tool[k_tmp_0] * k_0[iy + 12];
        T_tool_tmp_3[k_tmp] += (real_T)T_tool_tmp_2[k_tmp_0] * k_2[iy + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        k_0[k_tmp] = 0.0;
        k_0[k_tmp] += T_tool_tmp_3[d_tmp] * k_1[i];
        k_0[k_tmp] += T_tool_tmp_3[d_tmp + 1] * k_1[i + 4];
        k_0[k_tmp] += T_tool_tmp_3[d_tmp + 2] * k_1[i + 8];
        k_0[k_tmp] += T_tool_tmp_3[d_tmp + 3] * k_1[i + 12];
      }

      for (iy = 0; iy < 4; iy++) {
        d_tmp = iy << 2;
        k_tmp = i + d_tmp;
        T_tool[k_tmp] = 0.0;
        T_tool[k_tmp] += rtb_tool_offset[d_tmp] * k_0[i];
        T_tool[k_tmp] += rtb_tool_offset[d_tmp + 1] * k_0[i + 4];
        T_tool[k_tmp] += rtb_tool_offset[d_tmp + 2] * k_0[i + 8];
        T_tool[k_tmp] += rtb_tool_offset[d_tmp + 3] * k_0[i + 12];
      }
    }

    /* '<S2>:1:22' */
    /* '<S2>:1:23' */
    Teach_Pendant_Task_Space_B.pos[0] = T_tool[12];

    /* Sum: '<Root>/Subtract' */
    Teach_Pendant_Task_Space_B.Subtract[0] = Teach_Pendant_Task_Space_B.pos[0] -
      Teach_Pendant_Task_Space_B.Switch[0];

    /* MATLAB Function: '<Root>/Forward Kinematics' */
    Teach_Pendant_Task_Space_B.pos[1] = T_tool[13];

    /* Sum: '<Root>/Subtract' */
    Teach_Pendant_Task_Space_B.Subtract[1] = Teach_Pendant_Task_Space_B.pos[1] -
      Teach_Pendant_Task_Space_B.Switch[1];

    /* MATLAB Function: '<Root>/Forward Kinematics' */
    Teach_Pendant_Task_Space_B.pos[2] = T_tool[14];

    /* Sum: '<Root>/Subtract' */
    Teach_Pendant_Task_Space_B.Subtract[2] = Teach_Pendant_Task_Space_B.pos[2] -
      Teach_Pendant_Task_Space_B.Switch[2];

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/same as of const_pid'
     *  MATLAB Function: '<Root>/cost function'
     */
    /* MATLAB Function 'cost function': '<S8>:1' */
    /* '<S8>:1:5' */
    /* '<S8>:1:6' */
    /* '<S8>:1:7' */
    /* '<S8>:1:10' */
    /* MATLAB Function 'MATLAB Function': '<S4>:1' */
    /* '<S4>:1:17' */
    /* '<S4>:1:18' */
    k = Teach_Pendant_Task_Space_B.Add - 1.0;
    if (total_length_tmp_0 == 0.0) {
      if (Teach_Pendant_Task_Space_B.Add - 1.0 == 0.0) {
        k = total_length_tmp_0;
      }
    } else if (rtIsNaN(Teach_Pendant_Task_Space_B.Add - 1.0) || rtIsNaN
               (total_length_tmp_0) || rtIsInf(Teach_Pendant_Task_Space_B.Add -
                1.0)) {
      k = (rtNaN);
    } else if (Teach_Pendant_Task_Space_B.Add - 1.0 == 0.0) {
      k = 0.0 / total_length_tmp_0;
    } else if (rtIsInf(total_length_tmp_0)) {
      if ((Teach_Pendant_Task_Space_B.Add - 1.0 < 0.0) != (total_length_tmp_0 <
           0.0)) {
        k = total_length_tmp_0;
      }
    } else {
      k = fmod(Teach_Pendant_Task_Space_B.Add - 1.0, total_length_tmp_0);
      rEQ0 = (k == 0.0);
      if ((!rEQ0) && (total_length_tmp_0 > floor(total_length_tmp_0))) {
        q = fabs((Teach_Pendant_Task_Space_B.Add - 1.0) / total_length_tmp_0);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        k = total_length_tmp_0 * 0.0;
      } else {
        if ((Teach_Pendant_Task_Space_B.Add - 1.0 < 0.0) != (total_length_tmp_0 <
             0.0)) {
          k += total_length_tmp_0;
        }
      }
    }

    /* '<S4>:1:19' */
    rtb_GearRatio[0] = Teach_Pendant_Task_Space_P.segment_lengths[0];
    rtb_GearRatio[1] = total_length_tmp;
    rtb_GearRatio[2] = total_length_tmp +
      Teach_Pendant_Task_Space_P.segment_lengths[2];

    /* '<S4>:1:21' */
    iy = 0;

    /* '<S4>:1:22' */
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      /* '<S4>:1:22' */
      if (k + 1.0 <= rtb_GearRatio[i]) {
        /* '<S4>:1:23' */
        /* '<S4>:1:24' */
        iy = i;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if ((real_T)iy + 1.0 != Teach_Pendant_Task_Space_DW.last_seg_b) {
      /* '<S4>:1:30' */
      /* '<S4>:1:31' */
      Teach_Pendant_Task_Space_DW.cost_accum[iy] = 0.0;
    }

    /* '<S4>:1:34' */
    Teach_Pendant_Task_Space_DW.last_seg_b = (real_T)iy + 1.0;

    /* '<S4>:1:37' */
    Teach_Pendant_Task_Space_DW.cost_accum[iy] +=
      (Teach_Pendant_Task_Space_B.Subtract[0] *
       Teach_Pendant_Task_Space_B.Subtract[0] +
       Teach_Pendant_Task_Space_B.Subtract[1] *
       Teach_Pendant_Task_Space_B.Subtract[1]) +
      Teach_Pendant_Task_Space_B.Subtract[2] *
      Teach_Pendant_Task_Space_B.Subtract[2];

    /* '<S4>:1:39' */
    Teach_Pendant_Task_Space_B.total_cost =
      Teach_Pendant_Task_Space_DW.cost_accum[iy];

    /* MATLAB Function: '<Root>/pid auto tuner' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/gives the length of all the segments needed by const_pid to detect which segment is robot is in currently'
     */
    /* MATLAB Function 'pid auto tuner': '<S9>:1' */
    /* '<S9>:1:53' */
    /* '<S9>:1:8' */
    /* '<S9>:1:11' */
    if (!Teach_Pendant_Task_Space_DW.initialized_not_empty) {
      /* '<S9>:1:21' */
      /* '<S9>:1:23' */
      Teach_Pendant_Task_Space_rand(Teach_Pendant_Task_Space_DW.particles);

      /* '<S9>:1:25' */
      memcpy(&Teach_Pendant_Task_Space_DW.pbest[0],
             &Teach_Pendant_Task_Space_DW.particles[0], 1200U * sizeof(real_T));
      Teach_Pendant_Task_Space_DW.initialized_not_empty = true;
    }

    /* '<S9>:1:39' */
    /* '<S9>:1:40' */
    k = Teach_Pendant_Task_Space_B.Add - 1.0;
    if (total_length_tmp_0 == 0.0) {
      if (Teach_Pendant_Task_Space_B.Add - 1.0 == 0.0) {
        k = total_length_tmp_0;
      }
    } else if (rtIsNaN(Teach_Pendant_Task_Space_B.Add - 1.0) || rtIsNaN
               (total_length_tmp_0) || rtIsInf(Teach_Pendant_Task_Space_B.Add -
                1.0)) {
      k = (rtNaN);
    } else if (Teach_Pendant_Task_Space_B.Add - 1.0 == 0.0) {
      k = 0.0 / total_length_tmp_0;
    } else if (rtIsInf(total_length_tmp_0)) {
      if ((Teach_Pendant_Task_Space_B.Add - 1.0 < 0.0) != (total_length_tmp_0 <
           0.0)) {
        k = total_length_tmp_0;
      }
    } else {
      k = fmod(Teach_Pendant_Task_Space_B.Add - 1.0, total_length_tmp_0);
      rEQ0 = (k == 0.0);
      if ((!rEQ0) && (total_length_tmp_0 > floor(total_length_tmp_0))) {
        q = fabs((Teach_Pendant_Task_Space_B.Add - 1.0) / total_length_tmp_0);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        k = total_length_tmp_0 * 0.0;
      } else {
        if ((Teach_Pendant_Task_Space_B.Add - 1.0 < 0.0) != (total_length_tmp_0 <
             0.0)) {
          k += total_length_tmp_0;
        }
      }
    }

    /* '<S9>:1:41' */
    rtb_GearRatio[0] = Teach_Pendant_Task_Space_P.segment_lengths[0];
    rtb_GearRatio[1] = total_length_tmp;
    rtb_GearRatio[2] = total_length_tmp +
      Teach_Pendant_Task_Space_P.segment_lengths[2];

    /* '<S9>:1:43' */
    iy = 0;

    /* '<S9>:1:44' */
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      /* '<S9>:1:44' */
      if (k + 1.0 <= rtb_GearRatio[i]) {
        /* '<S9>:1:45' */
        /* '<S9>:1:46' */
        iy = i;
        exitg1 = true;
      } else {
        i++;
      }
    }

    /* '<S9>:1:52' */
    /* '<S9>:1:53' */
    /* '<S9>:1:55' */
    /* '<S9>:1:126' */
    d_tmp = (int32_T)Teach_Pendant_Task_Space_DW.current_particle[iy];
    k_tmp = 120 * iy + d_tmp;
    k = Teach_Pendant_Task_Space_DW.particles[k_tmp - 1];

    /* '<S9>:1:141' */
    q = Teach_Pendant_Task_Space_DW.particles[k_tmp + 19];

    /* '<S9>:1:141' */
    d = Teach_Pendant_Task_Space_DW.particles[k_tmp + 39];

    /* '<S9>:1:141' */
    /* '<S9>:1:132' */
    x = Teach_Pendant_Task_Space_DW.particles[k_tmp + 59];

    /* '<S9>:1:141' */
    T_tool_tmp_1 = Teach_Pendant_Task_Space_DW.particles[k_tmp + 79];

    /* '<S9>:1:141' */
    total_length_tmp = Teach_Pendant_Task_Space_DW.particles[k_tmp + 99];

    /* '<S9>:1:141' */
    /* '<S9>:1:55' */
    /* '<S9>:1:58' */
    /* '<S9>:1:59' */
    /* '<S9>:1:126' */
    total_length_tmp_0 = Teach_Pendant_Task_Space_DW.gbest[iy];

    /* '<S9>:1:141' */
    h_v = Teach_Pendant_Task_Space_DW.gbest[iy + 10];

    /* '<S9>:1:141' */
    i_v = Teach_Pendant_Task_Space_DW.gbest[iy + 20];

    /* '<S9>:1:141' */
    /* '<S9>:1:132' */
    j_v = Teach_Pendant_Task_Space_DW.gbest[iy + 30];

    /* '<S9>:1:141' */
    k_v = Teach_Pendant_Task_Space_DW.gbest[iy + 40];

    /* '<S9>:1:141' */
    l_v = Teach_Pendant_Task_Space_DW.gbest[iy + 50];

    /* '<S9>:1:141' */
    /* '<S9>:1:59' */
    /* '<S9>:1:62' */
    scale = 3.3121686421112381E-170;
    absxk = fabs(Teach_Pendant_Task_Space_B.Switch[0] -
                 Teach_Pendant_Task_Space_P.starting_point[0]);
    if (absxk > 3.3121686421112381E-170) {
      total_length = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      total_length = t * t;
    }

    absxk = fabs(Teach_Pendant_Task_Space_B.Switch[1] -
                 Teach_Pendant_Task_Space_P.starting_point[1]);
    if (absxk > scale) {
      t = scale / absxk;
      total_length = total_length * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      total_length += t * t;
    }

    absxk = fabs(Teach_Pendant_Task_Space_B.Switch[2] -
                 Teach_Pendant_Task_Space_P.starting_point[2]);
    if (absxk > scale) {
      t = scale / absxk;
      total_length = total_length * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      total_length += t * t;
    }

    total_length = scale * sqrt(total_length);
    rEQ0 = (total_length < 0.05);
    if (rEQ0 && (!Teach_Pendant_Task_Space_DW.in_zone_prev[iy])) {
      /* '<S9>:1:63' */
      trigger = true;
    } else {
      trigger = false;
    }

    /* '<S9>:1:64' */
    Teach_Pendant_Task_Space_DW.in_zone_prev[iy] = rEQ0;
    if (trigger) {
      i = (20 * iy + d_tmp) - 1;
      if (Teach_Pendant_Task_Space_B.total_cost <
          Teach_Pendant_Task_Space_DW.pbest_cost[i]) {
        /* '<S9>:1:69' */
        /* '<S9>:1:70' */
        Teach_Pendant_Task_Space_DW.pbest_cost[i] =
          Teach_Pendant_Task_Space_B.total_cost;

        /* '<S9>:1:71' */
        for (i = 0; i < 6; i++) {
          Teach_Pendant_Task_Space_DW.pbest[((d_tmp + 20 * i) + 120 * iy) - 1] =
            Teach_Pendant_Task_Space_DW.particles[((20 * i + d_tmp) + 120 * iy)
            - 1];
        }
      }

      if (Teach_Pendant_Task_Space_B.total_cost <
          Teach_Pendant_Task_Space_DW.gbest_cost[iy]) {
        /* '<S9>:1:75' */
        /* '<S9>:1:76' */
        Teach_Pendant_Task_Space_DW.gbest_cost[iy] =
          Teach_Pendant_Task_Space_B.total_cost;

        /* '<S9>:1:77' */
        for (i = 0; i < 6; i++) {
          Teach_Pendant_Task_Space_DW.gbest[iy + 10 * i] =
            Teach_Pendant_Task_Space_DW.particles[((20 * i + d_tmp) + 120 * iy)
            - 1];
        }
      }

      /* '<S9>:1:87' */
      Teach_Pendant_Task_Space_DW.eval_count[iy]++;

      /* '<S9>:1:89' */
      total_length = Teach_Pendant_Task_Space_DW.current_particle[iy] + 1.0;
      if (Teach_Pendant_Task_Space_DW.current_particle[iy] + 1.0 > 20.0) {
        /* '<S9>:1:90' */
        /* '<S9>:1:91' */
        total_length = 1.0;
      }

      /* '<S9>:1:93' */
      Teach_Pendant_Task_Space_DW.current_particle[iy] = total_length;
      if (Teach_Pendant_Task_Space_DW.eval_count[iy] >= 20.0) {
        /* '<S9>:1:96' */
        /* '<S9>:1:98' */
        for (i = 0; i < 20; i++) {
          /* '<S9>:1:98' */
          /* '<S9>:1:99' */
          /* '<S9>:1:100' */
          /* '<S9>:1:101' */
          /* '<S9>:1:102' */
          /* '<S9>:1:104' */
          Teach_Pendant_Task_Space_rand_l(rtb_EncoderOffsets);

          /* '<S9>:1:105' */
          Teach_Pendant_Task_Space_rand_l(r2);

          /* '<S9>:1:107' */
          /* '<S9>:1:108' */
          /* '<S9>:1:109' */
          /* '<S9>:1:111' */
          /* '<S9>:1:112' */
          for (d_tmp = 0; d_tmp < 6; d_tmp++) {
            k_tmp = (20 * d_tmp + i) + 120 * iy;
            total_length = ((Teach_Pendant_Task_Space_DW.pbest[k_tmp] -
                             Teach_Pendant_Task_Space_DW.particles[k_tmp]) *
                            (1.5 * rtb_EncoderOffsets[d_tmp]) +
                            Teach_Pendant_Task_Space_DW.velocities[k_tmp] * 0.7)
              + (Teach_Pendant_Task_Space_DW.gbest[10 * d_tmp + iy] -
                 Teach_Pendant_Task_Space_DW.particles[k_tmp]) * (3.0 * r2[d_tmp]);
            scale = Teach_Pendant_Task_Space_DW.particles[k_tmp] + total_length;
            if ((1.0 < scale) || rtIsNaN(scale)) {
              absxk = 1.0;
            } else {
              absxk = scale;
            }

            if ((0.0 > absxk) || rtIsNaN(absxk)) {
              scale = 0.0;
            } else {
              scale = absxk;
            }

            Teach_Pendant_Task_Space_DW.particles[k_tmp] = scale;
            Teach_Pendant_Task_Space_DW.velocities[k_tmp] = total_length;
            rtb_EncoderOffsets[d_tmp] = total_length;
            r2[d_tmp] = absxk;
          }
        }

        /* '<S9>:1:115' */
        Teach_Pendant_Task_Space_DW.eval_count[iy] = 0.0;
      }
    }

    Teach_Pendant_Task_Space_B.best_Kp[0] = 1.79;
    Teach_Pendant_Task_Space_B.best_Kp[1] = 1.46;
    Teach_Pendant_Task_Space_B.best_Kp[2] = 0.6;
    Teach_Pendant_Task_Space_B.best_Ki[0] = total_length_tmp_0 * 2.0;
    Teach_Pendant_Task_Space_B.best_Ki[1] = h_v * 2.0;
    Teach_Pendant_Task_Space_B.best_Ki[2] = i_v * 3.0;
    Teach_Pendant_Task_Space_B.best_Kd[0] = j_v * 0.08 + 0.02;
    Teach_Pendant_Task_Space_B.best_Kd[1] = k_v * 0.08 + 0.02;
    Teach_Pendant_Task_Space_B.best_Kd[2] = l_v * 0.025;
    Teach_Pendant_Task_Space_B.current_seg = (real_T)iy + 1.0;

    /* MATLAB Function: '<Root>/1 to out 1st signal' incorporates:
     *  Constant: '<Root>/Constant2'
     *  MATLAB Function: '<Root>/pid auto tuner'
     *  SignalConversion generated from: '<S1>/ SFunction '
     */
    /* MATLAB Function '1 to out 1st signal': '<S1>:1' */
    if (Teach_Pendant_Task_Space_P.Constant2_Value_h == 1.0) {
      /* '<S1>:1:4' */
      /* '<S1>:1:5' */
      Teach_Pendant_Task_Space_B.out[0] = Teach_Pendant_Task_Space_B.Kp_p[0];
      Teach_Pendant_Task_Space_B.out[3] = Teach_Pendant_Task_Space_B.Ki_g[0];
      Teach_Pendant_Task_Space_B.out[6] = Teach_Pendant_Task_Space_B.Kd_f[0];
      Teach_Pendant_Task_Space_B.out[1] = Teach_Pendant_Task_Space_B.Kp_p[1];
      Teach_Pendant_Task_Space_B.out[4] = Teach_Pendant_Task_Space_B.Ki_g[1];
      Teach_Pendant_Task_Space_B.out[7] = Teach_Pendant_Task_Space_B.Kd_f[1];
      Teach_Pendant_Task_Space_B.out[2] = Teach_Pendant_Task_Space_B.Kp_p[2];
      Teach_Pendant_Task_Space_B.out[5] = Teach_Pendant_Task_Space_B.Ki_g[2];
      Teach_Pendant_Task_Space_B.out[8] = Teach_Pendant_Task_Space_B.Kd_f[2];
    } else {
      /* '<S1>:1:7' */
      Teach_Pendant_Task_Space_B.out[0] = 1.79;
      Teach_Pendant_Task_Space_B.out[1] = 1.46;
      Teach_Pendant_Task_Space_B.out[2] = 0.6;
      Teach_Pendant_Task_Space_B.out[3] = k * 2.0;
      Teach_Pendant_Task_Space_B.out[4] = q * 2.0;
      Teach_Pendant_Task_Space_B.out[5] = d * 3.0;
      Teach_Pendant_Task_Space_B.out[6] = x * 0.08 + 0.02;
      Teach_Pendant_Task_Space_B.out[7] = T_tool_tmp_1 * 0.08 + 0.02;
      Teach_Pendant_Task_Space_B.out[8] = total_length_tmp * 0.025;
    }

    /* End of MATLAB Function: '<Root>/1 to out 1st signal' */

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
    /* MATLAB Function 'Inverse Kinematics': '<S3>:1' */
    /* '<S3>:1:19' */
    /* '<S3>:1:22' */
    for (i = 0; i < 3; i++) {
      rtb_GearRatio[i] = T_tool[i + 8] * rtb_tool_offset[14] + (T_tool[i + 4] *
        rtb_tool_offset[13] + T_tool[i] * rtb_tool_offset[12]);
    }

    /* '<S3>:1:26' */
    x = Teach_Pendant_Task_Space_B.Switch[0] - rtb_GearRatio[0];

    /* '<S3>:1:27' */
    total_length = Teach_Pendant_Task_Space_B.Switch[1] - rtb_GearRatio[1];

    /* '<S3>:1:28' */
    q = Teach_Pendant_Task_Space_B.Switch[2] - rtb_GearRatio[2];

    /* '<S3>:1:32' */
    d = sqrt(x * x + total_length * total_length);

    /* '<S3>:1:35' */
    k = sqrt(d * d + q * q);

    /* '<S3>:1:38' */
    total_length = atan(total_length / x);

    /* '<S3>:1:41' */
    x = acos((0.034848000000000004 - k * k) / 0.034848000000000004);
    if (q < 0.0) {
      /* '<S3>:1:44' */
      /* '<S3>:1:45' */
      q = acos(d / k);
    } else {
      /* '<S3>:1:47' */
      q = -acos(d / k);
    }

    /* '<S3>:1:51' */
    /* '<S3>:1:52' */
    k = q - asin(sin(4.71238898038469 - (4.71238898038469 - x)) * 0.132 / k);

    /* Sum: '<S12>/Sum1' incorporates:
     *  MATLAB Function: '<Root>/Inverse Kinematics'
     */
    Teach_Pendant_Task_Space_B.Sum1[0] = total_length -
      Teach_Pendant_Task_Space_B.JointOffsets[0];
    Teach_Pendant_Task_Space_B.Sum1[1] = k -
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
      /* Update for UnitDelay: '<Root>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE =
        Teach_Pendant_Task_Space_B.Add;

      /* Update for UnitDelay: '<S25>/FixPt Unit Delay2' incorporates:
       *  Constant: '<S25>/FixPt Constant'
       */
      Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE =
        Teach_Pendant_Task_Space_P.FixPtConstant_Value_l;

      /* Update for UnitDelay: '<S6>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[0] =
        Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[0];

      /* Update for UnitDelay: '<S25>/FixPt Unit Delay1' */
      Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[0] =
        Teach_Pendant_Task_Space_B.inter[0];

      /* Update for UnitDelay: '<S6>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[1] =
        Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven[1];

      /* Update for UnitDelay: '<S25>/FixPt Unit Delay1' */
      Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[1] =
        Teach_Pendant_Task_Space_B.inter[1];

      /* Update for UnitDelay: '<S6>/Unit Delay' */
      Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[2] =
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
  Teach_Pendant_Task_Space_M->Sizes.checksums[0] = (3312278886U);
  Teach_Pendant_Task_Space_M->Sizes.checksums[1] = (3524803694U);
  Teach_Pendant_Task_Space_M->Sizes.checksums[2] = (409222793U);
  Teach_Pendant_Task_Space_M->Sizes.checksums[3] = (3174842057U);

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
      Teach_Pendant_Task_Space_B.out[i] = 0.0;
    }

    Teach_Pendant_Task_Space_B.Add = 0.0;
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
    Teach_Pendant_Task_Space_B.best_Kp[0] = 0.0;
    Teach_Pendant_Task_Space_B.best_Kp[1] = 0.0;
    Teach_Pendant_Task_Space_B.best_Kp[2] = 0.0;
    Teach_Pendant_Task_Space_B.best_Ki[0] = 0.0;
    Teach_Pendant_Task_Space_B.best_Ki[1] = 0.0;
    Teach_Pendant_Task_Space_B.best_Ki[2] = 0.0;
    Teach_Pendant_Task_Space_B.best_Kd[0] = 0.0;
    Teach_Pendant_Task_Space_B.best_Kd[1] = 0.0;
    Teach_Pendant_Task_Space_B.best_Kd[2] = 0.0;
    Teach_Pendant_Task_Space_B.current_seg = 0.0;
    Teach_Pendant_Task_Space_B.Out = 0.0;
    Teach_Pendant_Task_Space_B.Out_i = 0.0;
    Teach_Pendant_Task_Space_B.Out_p = 0.0;
    Teach_Pendant_Task_Space_B.inter[0] = 0.0;
    Teach_Pendant_Task_Space_B.inter[1] = 0.0;
    Teach_Pendant_Task_Space_B.inter[2] = 0.0;
    Teach_Pendant_Task_Space_B.div[0] = 0.0;
    Teach_Pendant_Task_Space_B.div[1] = 0.0;
    Teach_Pendant_Task_Space_B.div[2] = 0.0;
    Teach_Pendant_Task_Space_B.Kp_p[0] = 0.0;
    Teach_Pendant_Task_Space_B.Kp_p[1] = 0.0;
    Teach_Pendant_Task_Space_B.Kp_p[2] = 0.0;
    Teach_Pendant_Task_Space_B.Ki_g[0] = 0.0;
    Teach_Pendant_Task_Space_B.Ki_g[1] = 0.0;
    Teach_Pendant_Task_Space_B.Ki_g[2] = 0.0;
    Teach_Pendant_Task_Space_B.Kd_f[0] = 0.0;
    Teach_Pendant_Task_Space_B.Kd_f[1] = 0.0;
    Teach_Pendant_Task_Space_B.Kd_f[2] = 0.0;
    Teach_Pendant_Task_Space_B.current_seg_b = 0.0;
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
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE = 0.0;
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[0] = 0.0;
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[1] = 0.0;
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[2] = 0.0;
  Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[0] = 0.0;
  Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[1] = 0.0;
  Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE[2] = 0.0;
  Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h = 0.0;
  Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[0] = 0.0;
  Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[1] = 0.0;
  Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE[2] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 1200; i++) {
      Teach_Pendant_Task_Space_DW.particles[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 1200; i++) {
      Teach_Pendant_Task_Space_DW.velocities[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 1200; i++) {
      Teach_Pendant_Task_Space_DW.pbest[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 200; i++) {
      Teach_Pendant_Task_Space_DW.pbest_cost[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 60; i++) {
      Teach_Pendant_Task_Space_DW.gbest[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      Teach_Pendant_Task_Space_DW.gbest_cost[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      Teach_Pendant_Task_Space_DW.current_particle[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      Teach_Pendant_Task_Space_DW.eval_count[i] = 0.0;
    }
  }

  Teach_Pendant_Task_Space_DW.last_seg = 0.0;

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      Teach_Pendant_Task_Space_DW.cost_accum[i] = 0.0;
    }
  }

  Teach_Pendant_Task_Space_DW.last_seg_b = 0.0;

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

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE =
      Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S25>/FixPt Unit Delay2' */
    Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE =
      Teach_Pendant_Task_Space_P.FixPtUnitDelay2_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[0] =
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
    Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[1] =
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
    Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b[2] =
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

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
    Teach_Pendant_Task_Space_DW.last_seg = 0.0;

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
    for (i = 0; i < 10; i++) {
      Teach_Pendant_Task_Space_DW.cost_accum[i] = 0.0;
    }

    Teach_Pendant_Task_Space_DW.last_seg_b = -1.0;

    /* End of SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */

    /* SystemInitialize for MATLAB Function: '<Root>/pid auto tuner' */
    Teach_Pendant_Task_Space_DW.initialized_not_empty = false;
    Teach_Pendant_Task_Space_DW.state_not_empty = false;
    Teach_Pendant_Task_Space_DW.method = 7U;
    Teach_Pendant_Task_Space_DW.state = 1144108930U;
    Teach_Pendant_Task_Space_DW.state_k[0] = 362436069U;
    Teach_Pendant_Task_Space_DW.state_k[1] = 521288629U;
    for (i = 0; i < 1200; i++) {
      Teach_Pendant_Task_Space_DW.velocities[i] = 0.0;
    }

    for (i = 0; i < 200; i++) {
      Teach_Pendant_Task_Space_DW.pbest_cost[i] = (rtInf);
    }

    for (i = 0; i < 60; i++) {
      Teach_Pendant_Task_Space_DW.gbest[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      Teach_Pendant_Task_Space_DW.gbest_cost[i] = (rtInf);
      Teach_Pendant_Task_Space_DW.current_particle[i] = 1.0;
      Teach_Pendant_Task_Space_DW.eval_count[i] = 0.0;
      Teach_Pendant_Task_Space_DW.in_zone_prev[i] = false;
    }

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
