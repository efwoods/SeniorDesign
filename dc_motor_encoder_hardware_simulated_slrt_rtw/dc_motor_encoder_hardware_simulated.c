/*
 * dc_motor_encoder_hardware_simulated.c
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "dc_motor_encoder_hardware_simulated".
 *
 * Model version              : 1.129
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Apr 18 13:24:27 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "dc_motor_encoder_hardware_simulated_capi.h"
#include "dc_motor_encoder_hardware_simulated.h"
#include "dc_motor_encoder_hardware_simulated_private.h"

/* Block signals (auto storage) */
B_dc_motor_encoder_hardware_simulated_T dc_motor_encoder_hardware_simulated_B;

/* Continuous states */
X_dc_motor_encoder_hardware_simulated_T dc_motor_encoder_hardware_simulated_X;

/* Block states (auto storage) */
DW_dc_motor_encoder_hardware_simulated_T dc_motor_encoder_hardware_simulated_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_dc_motor_encoder_hardware_simulated_T dc_motor_encoder_hardware_simulated_Y;

/* Real-time model */
RT_MODEL_dc_motor_encoder_hardware_simulated_T
  dc_motor_encoder_hardware_simulated_M_;
RT_MODEL_dc_motor_encoder_hardware_simulated_T *const
  dc_motor_encoder_hardware_simulated_M =
  &dc_motor_encoder_hardware_simulated_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  dc_motor_encoder_hardware_simulated_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  dc_motor_encoder_hardware_simulated_output();
  dc_motor_encoder_hardware_simulated_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  dc_motor_encoder_hardware_simulated_output();
  dc_motor_encoder_hardware_simulated_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void dc_motor_encoder_hardware_simulated_output(void)
{
  real_T *lastU;
  real_T lastTime;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    /* set solver stop time */
    if (!(dc_motor_encoder_hardware_simulated_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                            ((dc_motor_encoder_hardware_simulated_M->Timing.clockTickH0
        + 1) * dc_motor_encoder_hardware_simulated_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                            ((dc_motor_encoder_hardware_simulated_M->Timing.clockTick0
        + 1) * dc_motor_encoder_hardware_simulated_M->Timing.stepSize0 +
        dc_motor_encoder_hardware_simulated_M->Timing.clockTickH0 *
        dc_motor_encoder_hardware_simulated_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    dc_motor_encoder_hardware_simulated_M->Timing.t[0] = rtsiGetT
      (&dc_motor_encoder_hardware_simulated_M->solverInfo);
  }

  /* Integrator: '<S5>/Integrator6' */
  dc_motor_encoder_hardware_simulated_B.Integrator6 =
    dc_motor_encoder_hardware_simulated_X.Integrator6_CSTATE;

  /* Product: '<S10>/Product2' incorporates:
   *  Constant: '<Root>/1 - Use simulated motor 0 - Use real motor'
   */
  dc_motor_encoder_hardware_simulated_B.Product2 =
    dc_motor_encoder_hardware_simulated_B.Integrator6 *
    dc_motor_encoder_hardware_simulated_P.uUsesimulatedmotor0Userealmotor;
  if (rtmIsMajorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Desired position  in degrees'
     *  Constant: '<Root>/Matlab_Input'
     */
    if (dc_motor_encoder_hardware_simulated_P.ManualSwitch_CurrentSetting == 1)
    {
      dc_motor_encoder_hardware_simulated_B.ManualSwitch =
        dc_motor_encoder_hardware_simulated_P.Desiredpositionindegrees_Value;
    } else {
      dc_motor_encoder_hardware_simulated_B.ManualSwitch =
        dc_motor_encoder_hardware_simulated_P.Matlab_Input_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* Gain: '<Root>/gain' */
    dc_motor_encoder_hardware_simulated_B.Setpoint =
      dc_motor_encoder_hardware_simulated_P.gain_Gain *
      dc_motor_encoder_hardware_simulated_B.ManualSwitch;

    /* Outport: '<Root>/setpoint_Out' */
    dc_motor_encoder_hardware_simulated_Y.setpoint_Out =
      dc_motor_encoder_hardware_simulated_B.Setpoint;

    /* Logic: '<S10>/complement the input1' incorporates:
     *  Constant: '<Root>/1 - Use simulated motor 0 - Use real motor'
     */
    dc_motor_encoder_hardware_simulated_B.complementtheinput1 =
      !(dc_motor_encoder_hardware_simulated_P.uUsesimulatedmotor0Userealmotor !=
        0.0);

    /* S-Function (encquanserq8): '<S4>/Channel 0 of  Encoder Inputs ' */

    /* Level2 S-Function Block: '<S4>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
    {
      SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[0];
      sfcnOutputs(rts,1);
    }

    /* Gain: '<S4>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    dc_motor_encoder_hardware_simulated_B.angular_positionrelative_countC =
      dc_motor_encoder_hardware_simulated_P.angular_positionrelative_countC *
      dc_motor_encoder_hardware_simulated_B.Channel0ofEncoderInputs;

    /* Product: '<S10>/Product3' */
    dc_motor_encoder_hardware_simulated_B.Product3 = (real_T)
      dc_motor_encoder_hardware_simulated_B.complementtheinput1 *
      dc_motor_encoder_hardware_simulated_B.angular_positionrelative_countC;
  }

  /* Sum: '<S10>/Sum2' */
  dc_motor_encoder_hardware_simulated_B.Sum2 =
    dc_motor_encoder_hardware_simulated_B.Product2 +
    dc_motor_encoder_hardware_simulated_B.Product3;

  /* Sum: '<Root>/Sum1' */
  dc_motor_encoder_hardware_simulated_B.ErrorSignal =
    dc_motor_encoder_hardware_simulated_B.Setpoint
    - dc_motor_encoder_hardware_simulated_B.Sum2;

  /* Outport: '<Root>/errorSignal_Out' */
  dc_motor_encoder_hardware_simulated_Y.errorSignal_Out =
    dc_motor_encoder_hardware_simulated_B.ErrorSignal;

  /* Outport: '<Root>/motorPos_Out' */
  dc_motor_encoder_hardware_simulated_Y.motorPos_Out =
    dc_motor_encoder_hardware_simulated_B.Sum2;

  /* S-Function (scblock): '<S1>/S-Function' */
  /* ok to acquire for <S1>/S-Function */
  dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK.AcquireOK = 1;
  if (rtmIsMajorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    /* S-Function (scblock): '<S3>/S-Function' */
    /* ok to acquire for <S3>/S-Function */
    dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_p.AcquireOK = 1;
  }

  /* S-Function (scblock): '<S6>/S-Function' */
  /* ok to acquire for <S6>/S-Function */
  dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_i.AcquireOK = 1;

  /* S-Function (scblock): '<S8>/S-Function' */
  /* ok to acquire for <S8>/S-Function */
  dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_it.AcquireOK = 1;
  if (rtmIsMajorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    /* S-Function (scblock): '<S9>/S-Function' */
    /* ok to acquire for <S9>/S-Function */
    dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_n.AcquireOK = 1;
  }

  /* Derivative: '<Root>/Derivative1' */
  if ((dc_motor_encoder_hardware_simulated_DW.TimeStampA >=
       dc_motor_encoder_hardware_simulated_M->Timing.t[0]) &&
      (dc_motor_encoder_hardware_simulated_DW.TimeStampB >=
       dc_motor_encoder_hardware_simulated_M->Timing.t[0])) {
    dc_motor_encoder_hardware_simulated_B.Derivative1 = 0.0;
  } else {
    lastTime = dc_motor_encoder_hardware_simulated_DW.TimeStampA;
    lastU = &dc_motor_encoder_hardware_simulated_DW.LastUAtTimeA;
    if (dc_motor_encoder_hardware_simulated_DW.TimeStampA <
        dc_motor_encoder_hardware_simulated_DW.TimeStampB) {
      if (dc_motor_encoder_hardware_simulated_DW.TimeStampB <
          dc_motor_encoder_hardware_simulated_M->Timing.t[0]) {
        lastTime = dc_motor_encoder_hardware_simulated_DW.TimeStampB;
        lastU = &dc_motor_encoder_hardware_simulated_DW.LastUAtTimeB;
      }
    } else {
      if (dc_motor_encoder_hardware_simulated_DW.TimeStampA >=
          dc_motor_encoder_hardware_simulated_M->Timing.t[0]) {
        lastTime = dc_motor_encoder_hardware_simulated_DW.TimeStampB;
        lastU = &dc_motor_encoder_hardware_simulated_DW.LastUAtTimeB;
      }
    }

    lastTime = dc_motor_encoder_hardware_simulated_M->Timing.t[0] - lastTime;
    dc_motor_encoder_hardware_simulated_B.Derivative1 =
      (dc_motor_encoder_hardware_simulated_B.ErrorSignal - *lastU) / lastTime;
  }

  /* End of Derivative: '<Root>/Derivative1' */

  /* Gain: '<Root>/Gain' */
  dc_motor_encoder_hardware_simulated_B.Gain[0] =
    dc_motor_encoder_hardware_simulated_P.Gain_Gain *
    dc_motor_encoder_hardware_simulated_B.Setpoint;
  dc_motor_encoder_hardware_simulated_B.Gain[1] =
    dc_motor_encoder_hardware_simulated_P.Gain_Gain *
    dc_motor_encoder_hardware_simulated_B.Sum2;
  dc_motor_encoder_hardware_simulated_B.Gain[2] =
    dc_motor_encoder_hardware_simulated_P.Gain_Gain *
    dc_motor_encoder_hardware_simulated_B.ErrorSignal;

  /* Integrator: '<Root>/Integrator1' */
  dc_motor_encoder_hardware_simulated_B.Integrator1 =
    dc_motor_encoder_hardware_simulated_X.Integrator1_CSTATE;

  /* Gain: '<Root>/Kd' */
  dc_motor_encoder_hardware_simulated_B.Kd =
    dc_motor_encoder_hardware_simulated_P.Kd_Gain *
    dc_motor_encoder_hardware_simulated_B.Derivative1;

  /* Gain: '<Root>/Ki' */
  dc_motor_encoder_hardware_simulated_B.Ki =
    dc_motor_encoder_hardware_simulated_P.Ki_Gain *
    dc_motor_encoder_hardware_simulated_B.Integrator1;

  /* Gain: '<Root>/Kp' */
  dc_motor_encoder_hardware_simulated_B.Kp =
    dc_motor_encoder_hardware_simulated_P.Kp_Gain *
    dc_motor_encoder_hardware_simulated_B.ErrorSignal;
  if (rtmIsMajorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    /* Constant: '<Root>/Magnet_Control' */
    dc_motor_encoder_hardware_simulated_B.Magnet_Control =
      dc_motor_encoder_hardware_simulated_P.Magnet_Control_Value;

    /* Logic: '<S7>/complement the input' incorporates:
     *  Constant: '<Root>/1 - Use simulated motor 0 - Use real motor'
     */
    dc_motor_encoder_hardware_simulated_B.complementtheinput =
      !(dc_motor_encoder_hardware_simulated_P.uUsesimulatedmotor0Userealmotor !=
        0.0);
  }

  /* Sum: '<Root>/Sum4' */
  dc_motor_encoder_hardware_simulated_B.Sum4 =
    (dc_motor_encoder_hardware_simulated_B.Kp +
     dc_motor_encoder_hardware_simulated_B.Kd) +
    dc_motor_encoder_hardware_simulated_B.Ki;

  /* Product: '<S7>/Product1' */
  dc_motor_encoder_hardware_simulated_B.Product1 = (real_T)
    dc_motor_encoder_hardware_simulated_B.complementtheinput *
    dc_motor_encoder_hardware_simulated_B.Sum4;

  /* Saturate: '<S4>/Saturation' */
  lastTime = dc_motor_encoder_hardware_simulated_B.Product1;
  u1 = dc_motor_encoder_hardware_simulated_P.Saturation_LowerSat;
  u2 = dc_motor_encoder_hardware_simulated_P.Saturation_UpperSat;
  if (lastTime > u2) {
    dc_motor_encoder_hardware_simulated_B.Saturation = u2;
  } else if (lastTime < u1) {
    dc_motor_encoder_hardware_simulated_B.Saturation = u1;
  } else {
    dc_motor_encoder_hardware_simulated_B.Saturation = lastTime;
  }

  /* End of Saturate: '<S4>/Saturation' */
  if (rtmIsMajorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    /* Constant: '<S4>/Power for Load Cell' */
    dc_motor_encoder_hardware_simulated_B.PowerforLoadCell =
      dc_motor_encoder_hardware_simulated_P.PowerforLoadCell_Value;

    /* Constant: '<S4>/Power for E Stop' */
    dc_motor_encoder_hardware_simulated_B.PowerforEStop =
      dc_motor_encoder_hardware_simulated_P.PowerforEStop_Value;

    /* S-Function (daquanserq8): '<S4>/Channel 0 -Control signal to  motor through amplifier ' */

    /* Level2 S-Function Block: '<S4>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
    {
      SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[1];
      sfcnOutputs(rts,1);
    }
  }

  /* Integrator: '<S5>/Integrator5' */
  dc_motor_encoder_hardware_simulated_B.Integrator5 =
    dc_motor_encoder_hardware_simulated_X.Integrator5_CSTATE;

  /* Gain: '<S5>/Back emf Ke1' */
  dc_motor_encoder_hardware_simulated_B.BackemfKe1 =
    dc_motor_encoder_hardware_simulated_P.BackemfKe1_Gain *
    dc_motor_encoder_hardware_simulated_B.Integrator5;

  /* Gain: '<S5>/Damping b1' */
  dc_motor_encoder_hardware_simulated_B.Dampingb1 =
    dc_motor_encoder_hardware_simulated_P.Dampingb1_Gain *
    dc_motor_encoder_hardware_simulated_B.Integrator5;

  /* Integrator: '<S5>/Integrator1' */
  dc_motor_encoder_hardware_simulated_B.Integrator1_h =
    dc_motor_encoder_hardware_simulated_X.Integrator1_CSTATE_i;

  /* Gain: '<S5>/Gain Kt2' */
  dc_motor_encoder_hardware_simulated_B.GainKt2 =
    dc_motor_encoder_hardware_simulated_P.GainKt2_Gain *
    dc_motor_encoder_hardware_simulated_B.Integrator1_h;

  /* Sum: '<S5>/Sum2' */
  dc_motor_encoder_hardware_simulated_B.Sum2_e =
    dc_motor_encoder_hardware_simulated_B.GainKt2 -
    dc_motor_encoder_hardware_simulated_B.Dampingb1;

  /* Gain: '<S5>/Gain Kt3' */
  dc_motor_encoder_hardware_simulated_B.GainKt3 =
    dc_motor_encoder_hardware_simulated_P.GainKt3_Gain *
    dc_motor_encoder_hardware_simulated_B.Sum2_e;

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<Root>/1 - Use simulated motor 0 - Use real motor'
   */
  dc_motor_encoder_hardware_simulated_B.Product =
    dc_motor_encoder_hardware_simulated_B.Sum4 *
    dc_motor_encoder_hardware_simulated_P.uUsesimulatedmotor0Userealmotor;

  /* Gain: '<S5>/Resistance R1' */
  dc_motor_encoder_hardware_simulated_B.ResistanceR1 =
    dc_motor_encoder_hardware_simulated_P.ResistanceR1_Gain *
    dc_motor_encoder_hardware_simulated_B.Integrator1_h;

  /* Sum: '<S5>/Sum1' */
  dc_motor_encoder_hardware_simulated_B.Sum1 =
    (dc_motor_encoder_hardware_simulated_B.Product -
     dc_motor_encoder_hardware_simulated_B.BackemfKe1) -
    dc_motor_encoder_hardware_simulated_B.ResistanceR1;

  /* Gain: '<S5>/Inductance' */
  dc_motor_encoder_hardware_simulated_B.Inductance =
    dc_motor_encoder_hardware_simulated_P.Inductance_Gain *
    dc_motor_encoder_hardware_simulated_B.Sum1;
  if (rtmIsMajorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    /* S-Function (adquanserq8): '<Root>/Q4 AD' */

    /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
    {
      SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[2];
      sfcnOutputs(rts,1);
    }

    /* Outport: '<Root>/Load Cell' */
    dc_motor_encoder_hardware_simulated_Y.LoadCell =
      dc_motor_encoder_hardware_simulated_B.loadcell;

    /* S-Function (scblock): '<S2>/S-Function' */
    /* ok to acquire for <S2>/S-Function */
    dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_g.AcquireOK = 1;

    /* RelationalOperator: '<Root>/Relational Operator' incorporates:
     *  Constant: '<Root>/Constant'
     */
    dc_motor_encoder_hardware_simulated_B.RelationalOperator =
      (dc_motor_encoder_hardware_simulated_B.estop >=
       dc_motor_encoder_hardware_simulated_P.Constant_Value);

    /* Stop: '<Root>/Stop Simulation' */
    if (dc_motor_encoder_hardware_simulated_B.RelationalOperator) {
      rtmSetStopRequested(dc_motor_encoder_hardware_simulated_M, 1);
    }

    /* End of Stop: '<Root>/Stop Simulation' */
  }
}

/* Model update function */
void dc_motor_encoder_hardware_simulated_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative1' */
  if (dc_motor_encoder_hardware_simulated_DW.TimeStampA == (rtInf)) {
    dc_motor_encoder_hardware_simulated_DW.TimeStampA =
      dc_motor_encoder_hardware_simulated_M->Timing.t[0];
    lastU = &dc_motor_encoder_hardware_simulated_DW.LastUAtTimeA;
  } else if (dc_motor_encoder_hardware_simulated_DW.TimeStampB == (rtInf)) {
    dc_motor_encoder_hardware_simulated_DW.TimeStampB =
      dc_motor_encoder_hardware_simulated_M->Timing.t[0];
    lastU = &dc_motor_encoder_hardware_simulated_DW.LastUAtTimeB;
  } else if (dc_motor_encoder_hardware_simulated_DW.TimeStampA <
             dc_motor_encoder_hardware_simulated_DW.TimeStampB) {
    dc_motor_encoder_hardware_simulated_DW.TimeStampA =
      dc_motor_encoder_hardware_simulated_M->Timing.t[0];
    lastU = &dc_motor_encoder_hardware_simulated_DW.LastUAtTimeA;
  } else {
    dc_motor_encoder_hardware_simulated_DW.TimeStampB =
      dc_motor_encoder_hardware_simulated_M->Timing.t[0];
    lastU = &dc_motor_encoder_hardware_simulated_DW.LastUAtTimeB;
  }

  *lastU = dc_motor_encoder_hardware_simulated_B.ErrorSignal;

  /* End of Update for Derivative: '<Root>/Derivative1' */
  if (rtmIsMajorTimeStep(dc_motor_encoder_hardware_simulated_M)) {
    rt_ertODEUpdateContinuousStates
      (&dc_motor_encoder_hardware_simulated_M->solverInfo);
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
  if (!(++dc_motor_encoder_hardware_simulated_M->Timing.clockTick0)) {
    ++dc_motor_encoder_hardware_simulated_M->Timing.clockTickH0;
  }

  dc_motor_encoder_hardware_simulated_M->Timing.t[0] = rtsiGetSolverStopTime
    (&dc_motor_encoder_hardware_simulated_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++dc_motor_encoder_hardware_simulated_M->Timing.clockTick1)) {
      ++dc_motor_encoder_hardware_simulated_M->Timing.clockTickH1;
    }

    dc_motor_encoder_hardware_simulated_M->Timing.t[1] =
      dc_motor_encoder_hardware_simulated_M->Timing.clockTick1 *
      dc_motor_encoder_hardware_simulated_M->Timing.stepSize1 +
      dc_motor_encoder_hardware_simulated_M->Timing.clockTickH1 *
      dc_motor_encoder_hardware_simulated_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void dc_motor_encoder_hardware_simulated_derivatives(void)
{
  XDot_dc_motor_encoder_hardware_simulated_T *_rtXdot;
  _rtXdot = ((XDot_dc_motor_encoder_hardware_simulated_T *)
             dc_motor_encoder_hardware_simulated_M->derivs);

  /* Derivatives for Integrator: '<S5>/Integrator6' */
  _rtXdot->Integrator6_CSTATE =
    dc_motor_encoder_hardware_simulated_B.Integrator5;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE =
    dc_motor_encoder_hardware_simulated_B.ErrorSignal;

  /* Derivatives for Integrator: '<S5>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = dc_motor_encoder_hardware_simulated_B.GainKt3;

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_i =
    dc_motor_encoder_hardware_simulated_B.Inductance;
}

/* Model initialize function */
void dc_motor_encoder_hardware_simulated_initialize(void)
{
  /* Start for S-Function (encquanserq8): '<S4>/Channel 0 of  Encoder Inputs ' */
  /* Level2 S-Function Block: '<S4>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S1>/S-Function' */

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s3"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s1"),
          "Setpoint        %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s2"),
          "Motor Position  %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s3"),
          "Error Signal    %3.2f");
        rl32eSetScope(3, 4, 200);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Gain/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 170.0);
        xpceScopeAcqOK(3,
                       &dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (scblock): '<S3>/S-Function' */

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("Magnet_Control"));
        rl32eSetScope(4, 4, 200);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("Magnet_Control"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        rl32eSetTargetScope(4, 11, 0.0);
        rl32eSetTargetScope(4, 10, 2.0);
        xpceScopeAcqOK(4,
                       &dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_p.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* Start for S-Function (scblock): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Sum1"));
        rl32eSetScope(2, 4, 500);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Sum1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 3.0);
        rl32eSetTargetScope(2, 11, -180.0);
        rl32eSetTargetScope(2, 10, 180.0);
        xpceScopeAcqOK(2,
                       &dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S8>/S-Function' */

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("switching logic/Sum2"));
        rl32eSetScope(7, 4, 500);
        rl32eSetScope(7, 5, 0);
        rl32eSetScope(7, 6, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("switching logic/Sum2"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 9, 0);
        rl32eSetTargetScope(7, 1, 3.0);
        rl32eSetTargetScope(7, 11, -180.0);
        rl32eSetTargetScope(7, 10, 180.0);
        xpceScopeAcqOK(7,
                       &dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_it.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* Start for S-Function (scblock): '<S9>/S-Function' */

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("gain"));
        rl32eSetScope(1, 4, 500);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("gain"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 3.0);
        rl32eSetTargetScope(1, 11, -180.0);
        rl32eSetTargetScope(1, 10, 180.0);
        xpceScopeAcqOK(1,
                       &dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for Constant: '<Root>/Magnet_Control' */
  dc_motor_encoder_hardware_simulated_B.Magnet_Control =
    dc_motor_encoder_hardware_simulated_P.Magnet_Control_Value;

  /* Start for Constant: '<S4>/Power for Load Cell' */
  dc_motor_encoder_hardware_simulated_B.PowerforLoadCell =
    dc_motor_encoder_hardware_simulated_P.PowerforLoadCell_Value;

  /* Start for Constant: '<S4>/Power for E Stop' */
  dc_motor_encoder_hardware_simulated_B.PowerforEStop =
    dc_motor_encoder_hardware_simulated_P.PowerforEStop_Value;

  /* Start for S-Function (daquanserq8): '<S4>/Channel 0 -Control signal to  motor through amplifier ' */
  /* Level2 S-Function Block: '<S4>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("Q4 AD/p1"));
        rl32eSetScope(5, 4, 200);
        rl32eSetScope(5, 5, 0);
        rl32eSetScope(5, 6, 1);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("Q4 AD/p1"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 9, 0);
        rl32eSetTargetScope(5, 11, 0.0);
        rl32eSetTargetScope(5, 10, 2.0);
        xpceScopeAcqOK(5,
                       &dc_motor_encoder_hardware_simulated_DW.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* InitializeConditions for Integrator: '<S5>/Integrator6' */
  dc_motor_encoder_hardware_simulated_X.Integrator6_CSTATE =
    dc_motor_encoder_hardware_simulated_P.Integrator6_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  dc_motor_encoder_hardware_simulated_DW.TimeStampA = (rtInf);
  dc_motor_encoder_hardware_simulated_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  dc_motor_encoder_hardware_simulated_X.Integrator1_CSTATE =
    dc_motor_encoder_hardware_simulated_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator5' */
  dc_motor_encoder_hardware_simulated_X.Integrator5_CSTATE =
    dc_motor_encoder_hardware_simulated_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  dc_motor_encoder_hardware_simulated_X.Integrator1_CSTATE_i =
    dc_motor_encoder_hardware_simulated_P.Integrator1_IC_j;
}

/* Model terminate function */
void dc_motor_encoder_hardware_simulated_terminate(void)
{
  /* Terminate for S-Function (encquanserq8): '<S4>/Channel 0 of  Encoder Inputs ' */
  /* Level2 S-Function Block: '<S4>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (daquanserq8): '<S4>/Channel 0 -Control signal to  motor through amplifier ' */
  /* Level2 S-Function Block: '<S4>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  dc_motor_encoder_hardware_simulated_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  dc_motor_encoder_hardware_simulated_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  dc_motor_encoder_hardware_simulated_initialize();
}

void MdlTerminate(void)
{
  dc_motor_encoder_hardware_simulated_terminate();
}

/* Registration function */
RT_MODEL_dc_motor_encoder_hardware_simulated_T
  *dc_motor_encoder_hardware_simulated(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)dc_motor_encoder_hardware_simulated_M, 0,
                sizeof(RT_MODEL_dc_motor_encoder_hardware_simulated_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                          &dc_motor_encoder_hardware_simulated_M->Timing.simTimeStep);
    rtsiSetTPtr(&dc_motor_encoder_hardware_simulated_M->solverInfo, &rtmGetTPtr
                (dc_motor_encoder_hardware_simulated_M));
    rtsiSetStepSizePtr(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                       &dc_motor_encoder_hardware_simulated_M->Timing.stepSize0);
    rtsiSetdXPtr(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                 &dc_motor_encoder_hardware_simulated_M->derivs);
    rtsiSetContStatesPtr(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                         (real_T **)
                         &dc_motor_encoder_hardware_simulated_M->contStates);
    rtsiSetNumContStatesPtr(&dc_motor_encoder_hardware_simulated_M->solverInfo,
      &dc_motor_encoder_hardware_simulated_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&dc_motor_encoder_hardware_simulated_M->solverInfo,
       &dc_motor_encoder_hardware_simulated_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&dc_motor_encoder_hardware_simulated_M->solverInfo,
       &dc_motor_encoder_hardware_simulated_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&dc_motor_encoder_hardware_simulated_M->solverInfo,
       &dc_motor_encoder_hardware_simulated_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                          (&rtmGetErrorStatus
      (dc_motor_encoder_hardware_simulated_M)));
    rtsiSetRTModelPtr(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                      dc_motor_encoder_hardware_simulated_M);
  }

  rtsiSetSimTimeStep(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                     MAJOR_TIME_STEP);
  dc_motor_encoder_hardware_simulated_M->intgData.y =
    dc_motor_encoder_hardware_simulated_M->odeY;
  dc_motor_encoder_hardware_simulated_M->intgData.f[0] =
    dc_motor_encoder_hardware_simulated_M->odeF[0];
  dc_motor_encoder_hardware_simulated_M->intgData.f[1] =
    dc_motor_encoder_hardware_simulated_M->odeF[1];
  dc_motor_encoder_hardware_simulated_M->intgData.f[2] =
    dc_motor_encoder_hardware_simulated_M->odeF[2];
  dc_motor_encoder_hardware_simulated_M->contStates = ((real_T *)
    &dc_motor_encoder_hardware_simulated_X);
  rtsiSetSolverData(&dc_motor_encoder_hardware_simulated_M->solverInfo, (void *)
                    &dc_motor_encoder_hardware_simulated_M->intgData);
  rtsiSetSolverName(&dc_motor_encoder_hardware_simulated_M->solverInfo,"ode3");
  dc_motor_encoder_hardware_simulated_M->solverInfoPtr =
    (&dc_motor_encoder_hardware_simulated_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      dc_motor_encoder_hardware_simulated_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    dc_motor_encoder_hardware_simulated_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    dc_motor_encoder_hardware_simulated_M->Timing.sampleTimes =
      (&dc_motor_encoder_hardware_simulated_M->Timing.sampleTimesArray[0]);
    dc_motor_encoder_hardware_simulated_M->Timing.offsetTimes =
      (&dc_motor_encoder_hardware_simulated_M->Timing.offsetTimesArray[0]);

    /* task periods */
    dc_motor_encoder_hardware_simulated_M->Timing.sampleTimes[0] = (0.0);
    dc_motor_encoder_hardware_simulated_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    dc_motor_encoder_hardware_simulated_M->Timing.offsetTimes[0] = (0.0);
    dc_motor_encoder_hardware_simulated_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(dc_motor_encoder_hardware_simulated_M,
             &dc_motor_encoder_hardware_simulated_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      dc_motor_encoder_hardware_simulated_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    dc_motor_encoder_hardware_simulated_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(dc_motor_encoder_hardware_simulated_M, -1);
  dc_motor_encoder_hardware_simulated_M->Timing.stepSize0 = 0.001;
  dc_motor_encoder_hardware_simulated_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    dc_motor_encoder_hardware_simulated_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(dc_motor_encoder_hardware_simulated_M->rtwLogInfo,
                          (NULL));
    rtliSetLogXSignalPtrs(dc_motor_encoder_hardware_simulated_M->rtwLogInfo,
                          (NULL));
    rtliSetLogT(dc_motor_encoder_hardware_simulated_M->rtwLogInfo, "tout");
    rtliSetLogX(dc_motor_encoder_hardware_simulated_M->rtwLogInfo, "");
    rtliSetLogXFinal(dc_motor_encoder_hardware_simulated_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(dc_motor_encoder_hardware_simulated_M->rtwLogInfo,
      "rt_");
    rtliSetLogFormat(dc_motor_encoder_hardware_simulated_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(dc_motor_encoder_hardware_simulated_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(dc_motor_encoder_hardware_simulated_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &dc_motor_encoder_hardware_simulated_Y.setpoint_Out,
        &dc_motor_encoder_hardware_simulated_Y.errorSignal_Out,
        &dc_motor_encoder_hardware_simulated_Y.motorPos_Out,
        &dc_motor_encoder_hardware_simulated_Y.LoadCell
      };

      rtliSetLogYSignalPtrs(dc_motor_encoder_hardware_simulated_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "Setpoint",
        "Error Signal",
        "name",
        "loadcell" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "dc_motor_encoder_hardware_simulated/setpoint_Out",
        "dc_motor_encoder_hardware_simulated/errorSignal_Out",
        "dc_motor_encoder_hardware_simulated/motorPos_Out",
        "dc_motor_encoder_hardware_simulated/Load Cell" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          4,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(dc_motor_encoder_hardware_simulated_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
    }

    rtliSetLogY(dc_motor_encoder_hardware_simulated_M->rtwLogInfo, "yout");
  }

  dc_motor_encoder_hardware_simulated_M->solverInfoPtr =
    (&dc_motor_encoder_hardware_simulated_M->solverInfo);
  dc_motor_encoder_hardware_simulated_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&dc_motor_encoder_hardware_simulated_M->solverInfo, 0.001);
  rtsiSetSolverMode(&dc_motor_encoder_hardware_simulated_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  dc_motor_encoder_hardware_simulated_M->blockIO = ((void *)
    &dc_motor_encoder_hardware_simulated_B);
  (void) memset(((void *) &dc_motor_encoder_hardware_simulated_B), 0,
                sizeof(B_dc_motor_encoder_hardware_simulated_T));

  /* parameters */
  dc_motor_encoder_hardware_simulated_M->defaultParam = ((real_T *)
    &dc_motor_encoder_hardware_simulated_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &dc_motor_encoder_hardware_simulated_X;
    dc_motor_encoder_hardware_simulated_M->contStates = (x);
    (void) memset((void *)&dc_motor_encoder_hardware_simulated_X, 0,
                  sizeof(X_dc_motor_encoder_hardware_simulated_T));
  }

  /* states (dwork) */
  dc_motor_encoder_hardware_simulated_M->dwork = ((void *)
    &dc_motor_encoder_hardware_simulated_DW);
  (void) memset((void *)&dc_motor_encoder_hardware_simulated_DW, 0,
                sizeof(DW_dc_motor_encoder_hardware_simulated_T));

  /* external outputs */
  dc_motor_encoder_hardware_simulated_M->outputs =
    (&dc_motor_encoder_hardware_simulated_Y);
  (void) memset((void *)&dc_motor_encoder_hardware_simulated_Y, 0,
                sizeof(ExtY_dc_motor_encoder_hardware_simulated_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  dc_motor_encoder_hardware_simulated_InitializeDataMapInfo
    (dc_motor_encoder_hardware_simulated_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.sfcnInfo;
    dc_motor_encoder_hardware_simulated_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (dc_motor_encoder_hardware_simulated_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &dc_motor_encoder_hardware_simulated_M->Sizes.numSampTimes);
    dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(dc_motor_encoder_hardware_simulated_M)[0]);
    dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(dc_motor_encoder_hardware_simulated_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart
                     (dc_motor_encoder_hardware_simulated_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal
                     (dc_motor_encoder_hardware_simulated_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (dc_motor_encoder_hardware_simulated_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &dc_motor_encoder_hardware_simulated_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (dc_motor_encoder_hardware_simulated_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &dc_motor_encoder_hardware_simulated_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &dc_motor_encoder_hardware_simulated_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &dc_motor_encoder_hardware_simulated_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &dc_motor_encoder_hardware_simulated_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &dc_motor_encoder_hardware_simulated_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &dc_motor_encoder_hardware_simulated_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &dc_motor_encoder_hardware_simulated_M->solverInfoPtr);
  }

  dc_motor_encoder_hardware_simulated_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)
                  &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  3*sizeof(SimStruct));
    dc_motor_encoder_hardware_simulated_M->childSfunctions =
      (&dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);
    dc_motor_encoder_hardware_simulated_M->childSfunctions[0] =
      (&dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.childSFunctions[0]);
    dc_motor_encoder_hardware_simulated_M->childSfunctions[1] =
      (&dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.childSFunctions[1]);
    dc_motor_encoder_hardware_simulated_M->childSfunctions[2] =
      (&dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: dc_motor_encoder_hardware_simulated/<S4>/Channel 0 of  Encoder Inputs  (encquanserq8) */
    {
      SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts, dc_motor_encoder_hardware_simulated_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &dc_motor_encoder_hardware_simulated_B.Channel0ofEncoderInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "Channel 0 of \nEncoder Inputs ");
      ssSetPath(rts,
                "dc_motor_encoder_hardware_simulated/Real motor/Channel 0 of  Encoder Inputs ");
      ssSetRTModel(rts,dc_motor_encoder_hardware_simulated_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P10_Siz);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P11_Siz);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P12_Siz);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &dc_motor_encoder_hardware_simulated_DW.Channel0ofEncoderInputs_IWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &dc_motor_encoder_hardware_simulated_DW.Channel0ofEncoderInputs_IWORK
                   [0]);
      }

      /* registration */
      encquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: dc_motor_encoder_hardware_simulated/<S4>/Channel 0 -Control signal to  motor through amplifier  (daquanserq8) */
    {
      SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      ssSetRTWSfcnInfo(rts, dc_motor_encoder_hardware_simulated_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.periodicStatesInfo
          [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &dc_motor_encoder_hardware_simulated_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &dc_motor_encoder_hardware_simulated_B.Magnet_Control;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.UPtrs2;
          sfcnUPtrs[0] = &dc_motor_encoder_hardware_simulated_B.PowerforLoadCell;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.UPtrs3;
          sfcnUPtrs[0] = &dc_motor_encoder_hardware_simulated_B.PowerforEStop;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "Channel 0 -Control signal to \nmotor through amplifier ");
      ssSetPath(rts,
                "dc_motor_encoder_hardware_simulated/Real motor/Channel 0 -Control signal to  motor through amplifier ");
      ssSetRTModel(rts,dc_motor_encoder_hardware_simulated_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotorthr);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_h);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_e);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotor_e1);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotor_cz);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_l);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_b);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_a);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotor_lv);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &dc_motor_encoder_hardware_simulated_DW.Channel0Controlsignaltomotorthr
                 [0]);
      ssSetIWork(rts, (int_T *)
                 &dc_motor_encoder_hardware_simulated_DW.Channel0Controlsignaltomotort_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &dc_motor_encoder_hardware_simulated_DW.Channel0Controlsignaltomotorthr
                   [0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &dc_motor_encoder_hardware_simulated_DW.Channel0Controlsignaltomotort_l);
      }

      /* registration */
      daquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }

    /* Level2 S-Function Block: dc_motor_encoder_hardware_simulated/<Root>/Q4 AD (adquanserq8) */
    {
      SimStruct *rts = dc_motor_encoder_hardware_simulated_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      ssSetRTWSfcnInfo(rts, dc_motor_encoder_hardware_simulated_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.periodicStatesInfo
          [2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &dc_motor_encoder_hardware_simulated_B.loadcell));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &dc_motor_encoder_hardware_simulated_B.estop));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 AD");
      ssSetPath(rts, "dc_motor_encoder_hardware_simulated/Q4 AD");
      ssSetRTModel(rts,dc_motor_encoder_hardware_simulated_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Q4AD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Q4AD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Q4AD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Q4AD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Q4AD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Q4AD_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       dc_motor_encoder_hardware_simulated_P.Q4AD_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &dc_motor_encoder_hardware_simulated_DW.Q4AD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &dc_motor_encoder_hardware_simulated_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &dc_motor_encoder_hardware_simulated_DW.Q4AD_IWORK[0]);
      }

      /* registration */
      adquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  dc_motor_encoder_hardware_simulated_M->Sizes.numContStates = (4);/* Number of continuous states */
  dc_motor_encoder_hardware_simulated_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  dc_motor_encoder_hardware_simulated_M->Sizes.numY = (4);/* Number of model outputs */
  dc_motor_encoder_hardware_simulated_M->Sizes.numU = (0);/* Number of model inputs */
  dc_motor_encoder_hardware_simulated_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  dc_motor_encoder_hardware_simulated_M->Sizes.numSampTimes = (2);/* Number of sample times */
  dc_motor_encoder_hardware_simulated_M->Sizes.numBlocks = (54);/* Number of blocks */
  dc_motor_encoder_hardware_simulated_M->Sizes.numBlockIO = (37);/* Number of block outputs */
  dc_motor_encoder_hardware_simulated_M->Sizes.numBlockPrms = (123);/* Sum of parameter "widths" */
  return dc_motor_encoder_hardware_simulated_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
