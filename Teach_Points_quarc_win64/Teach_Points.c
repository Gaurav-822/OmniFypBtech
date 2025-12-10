/*
 * Teach_Points.c
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
#include "Teach_Points_dt.h"

/* Block signals (default storage) */
B_Teach_Points_T Teach_Points_B;

/* Block states (default storage) */
DW_Teach_Points_T Teach_Points_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Teach_Points_T Teach_Points_PrevZCX;

/* Real-time model */
RT_MODEL_Teach_Points_T Teach_Points_M_;
RT_MODEL_Teach_Points_T *const Teach_Points_M = &Teach_Points_M_;

/* Model step function */
void Teach_Points_step(void)
{
  real_T tool[12];
  int8_T catArgs_f2[4];
  int32_T b_k;
  real_T rtb_GearRatio[3];
  ZCEventType zcEvent;
  real_T rtb_EncoderOffsets[6];
  real_T rtb_tool_offset[16];
  real_T tool_pos_tmp;
  real_T tool_pos_tmp_0;
  real_T tool_pos_tmp_1;
  real_T tool_pos_tmp_2;
  int8_T pos_tmp[16];
  int8_T pos_tmp_0[4];
  int8_T pos_tmp_1[16];
  int32_T i;
  real_T d[9];
  real_T tool_pos_tmp_3[9];
  real_T d_0[9];
  real_T tool_pos_tmp_4[16];
  real_T tool_pos_tmp_5[16];
  real_T tool_pos_tmp_6[16];
  real_T tool_pos_tmp_7[16];
  real_T pos_tmp_2[16];
  real_T rtb_q_idx_1;
  real_T rtb_q_idx_2;
  int32_T d_tmp;
  int32_T tool_pos_tmp_tmp;
  int32_T tool_pos_tmp_tmp_0;
  static const int8_T c[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T b[3] = { 0.039, 0.0, 0.0 };

  static const int8_T varargin_2[4] = { 0, 0, 0, 1 };

  static const int8_T A_T_z[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    1 };

  static const real_T A_T_x[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.132, 0.0, 0.0, 1.0 };

  static const real_T A_R_x[16] = { 1.0, 0.0, 0.0, 0.0, 0.0,
    6.123233995736766E-17, -1.0, 0.0, 0.0, 1.0, 6.123233995736766E-17, 0.0, 0.0,
    0.0, 0.0, 1.0 };

  /* Reset subsysRan breadcrumbs */
  srClearBC(Teach_Points_DW.TriggeredSubsystem_SubsysRanBC);

  /* SignalConversion generated from: '<Root>/Phantom' */
  Teach_Points_B.TmpSignalConversionAtPhantomInp[0] = 0.0;
  Teach_Points_B.TmpSignalConversionAtPhantomInp[1] = 0.0;
  Teach_Points_B.TmpSignalConversionAtPhantomInp[2] = 0.0;

  /* S-Function (phantom_block): '<Root>/Phantom' */

  /* S-Function Block: Teach_Points/Phantom (phantom_block) */
  {
    t_error result = 0;
    result = phantom_read(Teach_Points_DW.Phantom_Phantom,
                          &Teach_Points_B.Phantom_o1,
                          &Teach_Points_B.Phantom_o2[0], NULL, NULL,
                          &Teach_Points_B.Phantom_o3);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Teach_Points_M, _rt_error_message);
    }

    result = phantom_write(Teach_Points_DW.Phantom_Phantom,
      &Teach_Points_B.TmpSignalConversionAtPhantomInp[0], NULL);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Teach_Points_M, _rt_error_message);
    }
  }

  /* Bias: '<Root>/Encoder Offsets' */
  for (i = 0; i < 6; i++) {
    rtb_EncoderOffsets[i] = Teach_Points_B.Phantom_o2[i] +
      Teach_Points_P.EncoderOffsets_Bias[i];
  }

  /* End of Bias: '<Root>/Encoder Offsets' */

  /* Gain: '<S1>/Gear Ratio' incorporates:
   *  Bias: '<S1>/Bias1'
   *  Gain: '<S1>/Encoder'
   */
  rtb_GearRatio[1] = (rtb_EncoderOffsets[1] + Teach_Points_P.Bias1_Bias[1]) *
    Teach_Points_P.Encoder_Gain * Teach_Points_P.GearRatio_Gain[1];

  /* MATLAB Function: '<S1>/Embedded MATLAB Function' incorporates:
   *  Bias: '<S1>/Bias1'
   *  Gain: '<S1>/Encoder'
   *  Gain: '<S1>/Gear Ratio'
   */
  /* MATLAB Function 'Encoders to Joints q1, q2, q3/Embedded MATLAB Function': '<S4>:1' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  rtb_q_idx_1 = rtb_GearRatio[1];

  /* '<S4>:1:5' */
  rtb_q_idx_2 = ((rtb_EncoderOffsets[2] + Teach_Points_P.Bias1_Bias[2]) *
                 Teach_Points_P.Encoder_Gain * Teach_Points_P.GearRatio_Gain[2]
                 - rtb_GearRatio[1]) - 1.5707963267948966;

  /* MATLAB Function: '<Root>/Tool Offset' */
  /* MATLAB Function 'Tool Offset': '<S2>:1' */
  /* '<S2>:1:21' */
  /* '<S2>:1:20' */
  /* '<S2>:1:26' */
  /* '<S2>:1:32' */
  /* '<S2>:1:33' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /* '<S2>:1:10' */
  /* '<S2>:1:11' */
  /* '<S2>:1:12' */
  rtb_GearRatio[0] = -((rtb_EncoderOffsets[3] + -2048.0) * 0.0012783693402196514);
  rtb_GearRatio[1] = (rtb_EncoderOffsets[4] + -2654.0) * 0.0015339807878856412 +
    2.4434609527920612;

  /* '<S2>:1:15' */
  /* '<S2>:1:16' */
  /* '<S2>:1:20' */
  /* '<S2>:1:21' */
  /* '<S2>:1:22' */
  /* '<S2>:1:26' */
  tool_pos_tmp = sin(rtb_GearRatio[0]);
  tool_pos_tmp_0 = cos(rtb_GearRatio[0]);
  tool_pos_tmp_1 = sin(rtb_GearRatio[1]);
  tool_pos_tmp_2 = cos(rtb_GearRatio[1]);
  d[1] = 0.0;
  d[4] = tool_pos_tmp_0;
  d[7] = -tool_pos_tmp;
  d[2] = 0.0;
  d[5] = tool_pos_tmp;
  d[8] = tool_pos_tmp_0;
  tool_pos_tmp_3[0] = tool_pos_tmp_2;
  tool_pos_tmp_3[3] = -tool_pos_tmp_1;
  tool_pos_tmp_3[6] = 0.0;
  tool_pos_tmp_3[1] = tool_pos_tmp_1;
  tool_pos_tmp_3[4] = tool_pos_tmp_2;
  tool_pos_tmp_3[7] = 0.0;
  d[0] = 1.0;
  tool_pos_tmp_3[2] = 0.0;
  d[3] = 0.0;
  tool_pos_tmp_3[5] = 0.0;
  d[6] = 0.0;
  tool_pos_tmp_3[8] = 1.0;
  for (i = 0; i < 3; i++) {
    rtb_GearRatio[i] = 0.0;
    for (b_k = 0; b_k < 3; b_k++) {
      d_tmp = i + 3 * b_k;
      d_0[d_tmp] = 0.0;
      d_0[d_tmp] += tool_pos_tmp_3[3 * b_k] * d[i];
      d_0[d_tmp] += tool_pos_tmp_3[3 * b_k + 1] * d[i + 3];
      d_0[d_tmp] += tool_pos_tmp_3[3 * b_k + 2] * d[i + 6];
      rtb_GearRatio[i] += d_0[d_tmp] * b[b_k];
    }
  }

  /* '<S2>:1:32' */
  i = -1;
  for (b_k = 0; b_k < 9; b_k++) {
    i++;
    tool[i] = c[b_k];
  }

  i++;
  tool[i] = rtb_GearRatio[0];
  i++;
  tool[i] = rtb_GearRatio[1];
  i++;
  tool[i] = rtb_GearRatio[2];

  /* '<S2>:1:33' */
  for (i = 0; i < 4; i++) {
    b_k = i << 2;
    rtb_tool_offset[b_k] = tool[3 * i];
    rtb_tool_offset[b_k + 1] = tool[3 * i + 1];
    rtb_tool_offset[b_k + 2] = tool[3 * i + 2];
    rtb_tool_offset[b_k + 3] = varargin_2[i];
  }

  /* End of MATLAB Function: '<Root>/Tool Offset' */

  /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  zcEvent = rt_I32ZCFcn(RISING_ZERO_CROSSING,
                        &Teach_Points_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                        (Teach_Points_B.Phantom_o1));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S3>/In' incorporates:
     *  Bias: '<Root>/Joint Offsets'
     *  Bias: '<S1>/Bias1'
     *  Gain: '<Root>/Convert to Positive Rotation Convension'
     *  Gain: '<S1>/Encoder'
     *  Gain: '<S1>/Gear Ratio'
     */
    Teach_Points_B.In[0] = (rtb_EncoderOffsets[0] + Teach_Points_P.Bias1_Bias[0])
      * Teach_Points_P.Encoder_Gain * Teach_Points_P.GearRatio_Gain[0] *
      Teach_Points_P.ConverttoPositiveRotationConven[0] +
      Teach_Points_P.JointOffsets_Bias[0];
    Teach_Points_B.In[1] = Teach_Points_P.ConverttoPositiveRotationConven[1] *
      rtb_q_idx_1 + Teach_Points_P.JointOffsets_Bias[1];
    Teach_Points_B.In[2] = Teach_Points_P.ConverttoPositiveRotationConven[2] *
      rtb_q_idx_2 + Teach_Points_P.JointOffsets_Bias[2];

    /* MATLAB Function: '<S3>/Forward Kinematics1' */
    /* MATLAB Function 'Triggered Subsystem/Forward Kinematics1': '<S5>:1' */
    /* '<S5>:1:11' */
    /* '<S5>:1:32' */
    /* '<S5>:1:33' */
    /* '<S5>:1:35' */
    /* '<S5>:1:36' */
    /* '<S5>:1:30' */
    /* '<S5>:1:42' */
    /* '<S5>:1:47' */
    /* '<S5>:1:52' */
    /* '<S5>:1:12' */
    /* '<S5>:1:32' */
    /* '<S5>:1:33' */
    /* '<S5>:1:35' */
    /* '<S5>:1:36' */
    /* '<S5>:1:30' */
    /* '<S5>:1:42' */
    /* '<S5>:1:47' */
    /* '<S5>:1:52' */
    /* '<S5>:1:13' */
    /* '<S5>:1:32' */
    /* '<S5>:1:33' */
    /* '<S5>:1:35' */
    /* '<S5>:1:36' */
    /* '<S5>:1:30' */
    /* '<S5>:1:42' */
    /* '<S5>:1:47' */
    /* '<S5>:1:52' */
    /* '<S5>:1:17' */
    /* '<S5>:1:18' */
    /* '<S5>:1:21' */
    /* '<S5>:1:22' */
    /* '<S5>:1:23' */
    tool_pos_tmp = sin(Teach_Points_B.In[0]);
    tool_pos_tmp_0 = cos(Teach_Points_B.In[0]);
    tool_pos_tmp_1 = sin(Teach_Points_B.In[1]);
    tool_pos_tmp_2 = cos(Teach_Points_B.In[1]);
    catArgs_f2[0] = 0;
    pos_tmp_0[0] = 0;
    catArgs_f2[1] = 0;
    pos_tmp_0[1] = 0;
    catArgs_f2[2] = 1;
    pos_tmp_0[2] = 0;
    catArgs_f2[3] = 0;
    pos_tmp_0[3] = 1;
    rtb_q_idx_1 = sin(Teach_Points_B.In[2] - 1.5707963267948966);
    rtb_q_idx_2 = cos(Teach_Points_B.In[2] - 1.5707963267948966);
    for (i = 0; i < 16; i++) {
      pos_tmp[i] = A_T_z[i];
      pos_tmp_1[i] = A_T_z[i];
    }

    tool_pos_tmp_4[0] = tool_pos_tmp_0;
    tool_pos_tmp_4[4] = -tool_pos_tmp;
    tool_pos_tmp_4[8] = 0.0;
    tool_pos_tmp_4[12] = 0.0;
    tool_pos_tmp_4[1] = tool_pos_tmp;
    tool_pos_tmp_4[5] = tool_pos_tmp_0;
    tool_pos_tmp_4[9] = 0.0;
    tool_pos_tmp_4[13] = 0.0;
    tool_pos_tmp_4[2] = 0.0;
    tool_pos_tmp_4[3] = 0.0;
    tool_pos_tmp_4[6] = 0.0;
    tool_pos_tmp_4[7] = 0.0;
    tool_pos_tmp_4[10] = 1.0;
    tool_pos_tmp_4[11] = 0.0;
    tool_pos_tmp_4[14] = 0.0;
    tool_pos_tmp_4[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (b_k = 0; b_k < 4; b_k++) {
        d_tmp = b_k << 2;
        tool_pos_tmp_tmp = i + d_tmp;
        tool_pos_tmp_5[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp] *
          tool_pos_tmp_4[i];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 1] *
          tool_pos_tmp_4[i + 4];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 2] *
          tool_pos_tmp_4[i + 8];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 3] *
          tool_pos_tmp_4[i + 12];
      }

      for (b_k = 0; b_k < 4; b_k++) {
        d_tmp = b_k << 2;
        tool_pos_tmp_tmp = i + d_tmp;
        tool_pos_tmp_6[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_6[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp] *
          tool_pos_tmp_5[i];
        tool_pos_tmp_6[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 1] *
          tool_pos_tmp_5[i + 4];
        tool_pos_tmp_6[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 2] *
          tool_pos_tmp_5[i + 8];
        tool_pos_tmp_6[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 3] *
          tool_pos_tmp_5[i + 12];
      }
    }

    tool_pos_tmp_4[0] = tool_pos_tmp_2;
    tool_pos_tmp_4[4] = -tool_pos_tmp_1;
    tool_pos_tmp_4[8] = 0.0;
    tool_pos_tmp_4[12] = 0.0;
    tool_pos_tmp_4[1] = tool_pos_tmp_1;
    tool_pos_tmp_4[5] = tool_pos_tmp_2;
    tool_pos_tmp_4[9] = 0.0;
    tool_pos_tmp_4[13] = 0.0;
    tool_pos_tmp_4[2] = 0.0;
    tool_pos_tmp_4[3] = 0.0;
    tool_pos_tmp_4[6] = 0.0;
    tool_pos_tmp_4[7] = 0.0;
    tool_pos_tmp_4[10] = 1.0;
    tool_pos_tmp_4[11] = 0.0;
    tool_pos_tmp_4[14] = 0.0;
    tool_pos_tmp_4[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (b_k = 0; b_k < 4; b_k++) {
        d_tmp = b_k << 2;
        tool_pos_tmp_tmp = i + d_tmp;
        tool_pos_tmp_5[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp] *
          tool_pos_tmp_4[i];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 1] *
          tool_pos_tmp_4[i + 4];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 2] *
          tool_pos_tmp_4[i + 8];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp[d_tmp + 3] *
          tool_pos_tmp_4[i + 12];
      }

      for (b_k = 0; b_k < 4; b_k++) {
        d_tmp = b_k << 2;
        tool_pos_tmp_tmp = i + d_tmp;
        tool_pos_tmp_7[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_7[tool_pos_tmp_tmp] += A_T_x[d_tmp] * tool_pos_tmp_5[i];
        tool_pos_tmp_7[tool_pos_tmp_tmp] += A_T_x[d_tmp + 1] * tool_pos_tmp_5[i
          + 4];
        tool_pos_tmp_7[tool_pos_tmp_tmp] += A_T_x[d_tmp + 2] * tool_pos_tmp_5[i
          + 8];
        tool_pos_tmp_7[tool_pos_tmp_tmp] += A_T_x[d_tmp + 3] * tool_pos_tmp_5[i
          + 12];
      }
    }

    pos_tmp_2[0] = rtb_q_idx_2;
    pos_tmp_2[4] = -rtb_q_idx_1;
    pos_tmp_2[8] = 0.0;
    pos_tmp_2[12] = 0.0;
    pos_tmp_2[1] = rtb_q_idx_1;
    pos_tmp_2[5] = rtb_q_idx_2;
    pos_tmp_2[9] = 0.0;
    pos_tmp_2[13] = 0.0;
    for (i = 0; i < 4; i++) {
      for (b_k = 0; b_k < 4; b_k++) {
        d_tmp = b_k << 2;
        tool_pos_tmp_tmp = i + d_tmp;
        tool_pos_tmp_4[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_5[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_4[tool_pos_tmp_tmp] += A_R_x[d_tmp] * tool_pos_tmp_6[i];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp_1[d_tmp] *
          tool_pos_tmp_7[i];
        tool_pos_tmp_tmp_0 = d_tmp + 1;
        tool_pos_tmp_4[tool_pos_tmp_tmp] += A_R_x[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_6[i + 4];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp_1[tool_pos_tmp_tmp_0]
          * tool_pos_tmp_7[i + 4];
        tool_pos_tmp_tmp_0 = d_tmp + 2;
        tool_pos_tmp_4[tool_pos_tmp_tmp] += A_R_x[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_6[i + 8];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp_1[tool_pos_tmp_tmp_0]
          * tool_pos_tmp_7[i + 8];
        tool_pos_tmp_tmp_0 = d_tmp + 3;
        tool_pos_tmp_4[tool_pos_tmp_tmp] += A_R_x[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_6[i + 12];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += (real_T)pos_tmp_1[tool_pos_tmp_tmp_0]
          * tool_pos_tmp_7[i + 12];
      }

      d_tmp = i << 2;
      pos_tmp_2[d_tmp + 2] = catArgs_f2[i];
      pos_tmp_2[d_tmp + 3] = pos_tmp_0[i];
    }

    for (i = 0; i < 4; i++) {
      for (b_k = 0; b_k < 4; b_k++) {
        tool_pos_tmp_tmp = b_k << 2;
        d_tmp = i + tool_pos_tmp_tmp;
        tool_pos_tmp_6[d_tmp] = 0.0;
        tool_pos_tmp_6[d_tmp] += (real_T)pos_tmp[tool_pos_tmp_tmp] * pos_tmp_2[i];
        tool_pos_tmp_6[d_tmp] += (real_T)pos_tmp[tool_pos_tmp_tmp + 1] *
          pos_tmp_2[i + 4];
        tool_pos_tmp_6[d_tmp] += (real_T)pos_tmp[tool_pos_tmp_tmp + 2] *
          pos_tmp_2[i + 8];
        tool_pos_tmp_6[d_tmp] += (real_T)pos_tmp[tool_pos_tmp_tmp + 3] *
          pos_tmp_2[i + 12];
      }

      for (b_k = 0; b_k < 4; b_k++) {
        tool_pos_tmp_tmp = b_k << 2;
        d_tmp = i + tool_pos_tmp_tmp;
        tool_pos_tmp_7[d_tmp] = 0.0;
        tool_pos_tmp_7[d_tmp] += A_T_x[tool_pos_tmp_tmp] * tool_pos_tmp_6[i];
        tool_pos_tmp_7[d_tmp] += A_T_x[tool_pos_tmp_tmp + 1] * tool_pos_tmp_6[i
          + 4];
        tool_pos_tmp_7[d_tmp] += A_T_x[tool_pos_tmp_tmp + 2] * tool_pos_tmp_6[i
          + 8];
        tool_pos_tmp_7[d_tmp] += A_T_x[tool_pos_tmp_tmp + 3] * tool_pos_tmp_6[i
          + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (b_k = 0; b_k < 4; b_k++) {
        d_tmp = i << 2;
        tool_pos_tmp_tmp = b_k + d_tmp;
        tool_pos_tmp_6[tool_pos_tmp_tmp] = 0.0;
        pos_tmp_2[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_6[tool_pos_tmp_tmp] += tool_pos_tmp_5[d_tmp] *
          tool_pos_tmp_4[b_k];
        pos_tmp_2[tool_pos_tmp_tmp] += (real_T)pos_tmp_1[d_tmp] *
          tool_pos_tmp_7[b_k];
        tool_pos_tmp_tmp_0 = d_tmp + 1;
        tool_pos_tmp_6[tool_pos_tmp_tmp] += tool_pos_tmp_5[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_4[b_k + 4];
        pos_tmp_2[tool_pos_tmp_tmp] += (real_T)pos_tmp_1[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_7[b_k + 4];
        tool_pos_tmp_tmp_0 = d_tmp + 2;
        tool_pos_tmp_6[tool_pos_tmp_tmp] += tool_pos_tmp_5[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_4[b_k + 8];
        pos_tmp_2[tool_pos_tmp_tmp] += (real_T)pos_tmp_1[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_7[b_k + 8];
        tool_pos_tmp_tmp_0 = d_tmp + 3;
        tool_pos_tmp_6[tool_pos_tmp_tmp] += tool_pos_tmp_5[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_4[b_k + 12];
        pos_tmp_2[tool_pos_tmp_tmp] += (real_T)pos_tmp_1[tool_pos_tmp_tmp_0] *
          tool_pos_tmp_7[b_k + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (b_k = 0; b_k < 4; b_k++) {
        d_tmp = b_k << 2;
        tool_pos_tmp_tmp = i + d_tmp;
        tool_pos_tmp_4[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_4[tool_pos_tmp_tmp] += pos_tmp_2[d_tmp] * tool_pos_tmp_6[i];
        tool_pos_tmp_4[tool_pos_tmp_tmp] += pos_tmp_2[d_tmp + 1] *
          tool_pos_tmp_6[i + 4];
        tool_pos_tmp_4[tool_pos_tmp_tmp] += pos_tmp_2[d_tmp + 2] *
          tool_pos_tmp_6[i + 8];
        tool_pos_tmp_4[tool_pos_tmp_tmp] += pos_tmp_2[d_tmp + 3] *
          tool_pos_tmp_6[i + 12];
      }

      for (b_k = 0; b_k < 4; b_k++) {
        d_tmp = b_k << 2;
        tool_pos_tmp_tmp = i + d_tmp;
        tool_pos_tmp_5[tool_pos_tmp_tmp] = 0.0;
        tool_pos_tmp_5[tool_pos_tmp_tmp] += rtb_tool_offset[d_tmp] *
          tool_pos_tmp_4[i];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += rtb_tool_offset[d_tmp + 1] *
          tool_pos_tmp_4[i + 4];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += rtb_tool_offset[d_tmp + 2] *
          tool_pos_tmp_4[i + 8];
        tool_pos_tmp_5[tool_pos_tmp_tmp] += rtb_tool_offset[d_tmp + 3] *
          tool_pos_tmp_4[i + 12];
      }
    }

    Teach_Points_B.pos[0] = tool_pos_tmp_5[12];
    Teach_Points_B.pos[1] = tool_pos_tmp_5[13];
    Teach_Points_B.pos[2] = tool_pos_tmp_5[14];

    /* End of MATLAB Function: '<S3>/Forward Kinematics1' */
    Teach_Points_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, (real_T)Teach_Points_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Teach_Points_M)!=-1) &&
        !((rtmGetTFinal(Teach_Points_M)-Teach_Points_M->Timing.taskTime0) >
          Teach_Points_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Teach_Points_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Teach_Points_M)) {
      rtmSetErrorStatus(Teach_Points_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Teach_Points_M->Timing.clockTick0)) {
    ++Teach_Points_M->Timing.clockTickH0;
  }

  Teach_Points_M->Timing.taskTime0 = Teach_Points_M->Timing.clockTick0 *
    Teach_Points_M->Timing.stepSize0 + Teach_Points_M->Timing.clockTickH0 *
    Teach_Points_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Teach_Points_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Teach_Points_M, 0,
                sizeof(RT_MODEL_Teach_Points_T));
  rtmSetTFinal(Teach_Points_M, -1);
  Teach_Points_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Teach_Points_M->Sizes.checksums[0] = (2789172043U);
  Teach_Points_M->Sizes.checksums[1] = (3355707363U);
  Teach_Points_M->Sizes.checksums[2] = (2382567304U);
  Teach_Points_M->Sizes.checksums[3] = (1472143410U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Teach_Points_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &Teach_Points_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Teach_Points_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Teach_Points_M->extModeInfo,
      &Teach_Points_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Teach_Points_M->extModeInfo,
                        Teach_Points_M->Sizes.checksums);
    rteiSetTPtr(Teach_Points_M->extModeInfo, rtmGetTPtr(Teach_Points_M));
  }

  /* block I/O */
  (void) memset(((void *) &Teach_Points_B), 0,
                sizeof(B_Teach_Points_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      Teach_Points_B.Phantom_o2[i] = 0.0;
    }

    Teach_Points_B.TmpSignalConversionAtPhantomInp[0] = 0.0;
    Teach_Points_B.TmpSignalConversionAtPhantomInp[1] = 0.0;
    Teach_Points_B.TmpSignalConversionAtPhantomInp[2] = 0.0;
    Teach_Points_B.In[0] = 0.0;
    Teach_Points_B.In[1] = 0.0;
    Teach_Points_B.In[2] = 0.0;
    Teach_Points_B.pos[0] = 0.0;
    Teach_Points_B.pos[1] = 0.0;
    Teach_Points_B.pos[2] = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&Teach_Points_DW, 0,
                sizeof(DW_Teach_Points_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Teach_Points_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (phantom_block): '<Root>/Phantom' */

  /* S-Function Block: Teach_Points/Phantom (phantom_block) */
  {
    t_error result;

    /* Open and initialize the device. This also schedules the device callback function. */
    result = phantom_open_device(&Teach_Points_DW.Phantom_Phantom,
      "Default Device", PHANTOM_ENCODER_OUTPUT, PHANTOM_JOINT_SPACE_INPUT, 0,
      1200, 3, 6);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Teach_Points_M, _rt_error_message);
    } else {
      /* Start the scheduler - *****TODO: change the rate to a parameter, just hardcoded at 1000Hz for now. */
      result = phantom_start_scheduler(Teach_Points_DW.Phantom_Phantom, 1000);
      if (result < 0) {
        phantom_close_device(Teach_Points_DW.Phantom_Phantom);
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Teach_Points_M, _rt_error_message);
      }
    }
  }

  Teach_Points_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void Teach_Points_terminate(void)
{
  /* Terminate for S-Function (phantom_block): '<Root>/Phantom' */

  /* S-Function Block: Teach_Points/Phantom (phantom_block) */
  {
    t_error result;
    if ((result = phantom_stop_scheduler(Teach_Points_DW.Phantom_Phantom)) < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Teach_Points_M, _rt_error_message);
    }

    if ((result = phantom_close_device(Teach_Points_DW.Phantom_Phantom)) < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Teach_Points_M, _rt_error_message);
    }
  }
}
