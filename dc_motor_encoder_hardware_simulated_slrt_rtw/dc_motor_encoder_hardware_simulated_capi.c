/*
 * dc_motor_encoder_hardware_simulated_capi.c
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "dc_motor_encoder_hardware_simulated".
 *
 * Model version              : 1.114
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Fri Apr 13 17:47:46 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "dc_motor_encoder_hardware_simulated_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "dc_motor_encoder_hardware_simulated.h"
#include "dc_motor_encoder_hardware_simulated_capi.h"
#include "dc_motor_encoder_hardware_simulated_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("Estop "),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("Magnet_Control"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("Derivative1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 3, 0, TARGET_STRING("Gain"),
    TARGET_STRING(""), 0, 0, 1, 0, 1 },

  { 4, 0, TARGET_STRING("Kd"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 5, 0, TARGET_STRING("Ki"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("Kp"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 7, 0, TARGET_STRING("gain"),
    TARGET_STRING("Setpoint"), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("Integrator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 9, 0, TARGET_STRING("Q4 AD"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("Sum1"),
    TARGET_STRING("Error Signal"), 0, 0, 0, 0, 1 },

  { 11, 0, TARGET_STRING("Sum4"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 12, 0, TARGET_STRING("Manual Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("Real motor/Power for Load Cell"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING(
    "Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("Real motor/Saturation"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 16, 0, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("Simulated motor/Back emf Ke1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 18, 0, TARGET_STRING("Simulated motor/Damping b1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 19, 0, TARGET_STRING("Simulated motor/Gain Kt2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 20, 0, TARGET_STRING("Simulated motor/Gain Kt3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 21, 0, TARGET_STRING("Simulated motor/Inductance"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 22, 0, TARGET_STRING("Simulated motor/Resistance R1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 23, 0, TARGET_STRING("Simulated motor/Integrator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 24, 0, TARGET_STRING("Simulated motor/Integrator5"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 25, 0, TARGET_STRING("Simulated motor/Integrator6"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 26, 0, TARGET_STRING("Simulated motor/Sum1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 27, 0, TARGET_STRING("Simulated motor/Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 28, 0, TARGET_STRING("input side switching logic/complement the input"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 29, 0, TARGET_STRING("input side switching logic/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 30, 0, TARGET_STRING("input side switching logic/Product1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 31, 0, TARGET_STRING("switching logic/complement the input1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 32, 0, TARGET_STRING("switching logic/Product2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 33, 0, TARGET_STRING("switching logic/Product3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 34, 0, TARGET_STRING("switching logic/Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 35, TARGET_STRING("1 - Use simulated motor 0 - Use real motor"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 36, TARGET_STRING("Desired position  in degrees"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 37, TARGET_STRING("Estop "),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 38, TARGET_STRING("Magnet_Control"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 39, TARGET_STRING("Matlab_Input"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 40, TARGET_STRING("Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 41, TARGET_STRING("Kd"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 42, TARGET_STRING("Ki"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 43, TARGET_STRING("Kp"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 44, TARGET_STRING("gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 45, TARGET_STRING("Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 46, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 47, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 48, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 49, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 50, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 51, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 52, TARGET_STRING("Manual Switch"),
    TARGET_STRING("CurrentSetting"), 2, 0, 0 },

  { 53, TARGET_STRING("Real motor/Power for Load Cell"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 54, TARGET_STRING("Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 55, TARGET_STRING("Real motor/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 56, TARGET_STRING("Real motor/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 57, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 58, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P2"), 0, 2, 0 },

  { 59, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P3"), 0, 2, 0 },

  { 60, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 61, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P5"), 0, 2, 0 },

  { 62, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P6"), 0, 2, 0 },

  { 63, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 64, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 65, TARGET_STRING("Real motor/Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 66, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 67, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 68, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 69, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 70, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 71, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 72, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 73, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 74, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 75, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 76, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 77, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P12"), 0, 0, 0 },

  { 78, TARGET_STRING("Simulated motor/Back emf Ke1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 79, TARGET_STRING("Simulated motor/Damping b1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 80, TARGET_STRING("Simulated motor/Gain Kt2"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 81, TARGET_STRING("Simulated motor/Gain Kt3"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 82, TARGET_STRING("Simulated motor/Inductance"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 83, TARGET_STRING("Simulated motor/Resistance R1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 84, TARGET_STRING("Simulated motor/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 85, TARGET_STRING("Simulated motor/Integrator5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 86, TARGET_STRING("Simulated motor/Integrator6"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &dc_motor_encoder_hardware_simulated_B.Estop,/* 0: Signal */
  &dc_motor_encoder_hardware_simulated_B.Magnet_Control,/* 1: Signal */
  &dc_motor_encoder_hardware_simulated_B.Derivative1,/* 2: Signal */
  &dc_motor_encoder_hardware_simulated_B.Gain[0],/* 3: Signal */
  &dc_motor_encoder_hardware_simulated_B.Kd,/* 4: Signal */
  &dc_motor_encoder_hardware_simulated_B.Ki,/* 5: Signal */
  &dc_motor_encoder_hardware_simulated_B.Kp,/* 6: Signal */
  &dc_motor_encoder_hardware_simulated_B.Setpoint,/* 7: Signal */
  &dc_motor_encoder_hardware_simulated_B.Integrator1,/* 8: Signal */
  &dc_motor_encoder_hardware_simulated_B.Q4AD,/* 9: Signal */
  &dc_motor_encoder_hardware_simulated_B.ErrorSignal,/* 10: Signal */
  &dc_motor_encoder_hardware_simulated_B.Sum4,/* 11: Signal */
  &dc_motor_encoder_hardware_simulated_B.ManualSwitch,/* 12: Signal */
  &dc_motor_encoder_hardware_simulated_B.PowerforLoadCell,/* 13: Signal */
  &dc_motor_encoder_hardware_simulated_B.angular_positionrelative_countC,/* 14: Signal */
  &dc_motor_encoder_hardware_simulated_B.Saturation,/* 15: Signal */
  &dc_motor_encoder_hardware_simulated_B.Channel0ofEncoderInputs,/* 16: Signal */
  &dc_motor_encoder_hardware_simulated_B.BackemfKe1,/* 17: Signal */
  &dc_motor_encoder_hardware_simulated_B.Dampingb1,/* 18: Signal */
  &dc_motor_encoder_hardware_simulated_B.GainKt2,/* 19: Signal */
  &dc_motor_encoder_hardware_simulated_B.GainKt3,/* 20: Signal */
  &dc_motor_encoder_hardware_simulated_B.Inductance,/* 21: Signal */
  &dc_motor_encoder_hardware_simulated_B.ResistanceR1,/* 22: Signal */
  &dc_motor_encoder_hardware_simulated_B.Integrator1_h,/* 23: Signal */
  &dc_motor_encoder_hardware_simulated_B.Integrator5,/* 24: Signal */
  &dc_motor_encoder_hardware_simulated_B.Integrator6,/* 25: Signal */
  &dc_motor_encoder_hardware_simulated_B.Sum1,/* 26: Signal */
  &dc_motor_encoder_hardware_simulated_B.Sum2_e,/* 27: Signal */
  &dc_motor_encoder_hardware_simulated_B.complementtheinput,/* 28: Signal */
  &dc_motor_encoder_hardware_simulated_B.Product,/* 29: Signal */
  &dc_motor_encoder_hardware_simulated_B.Product1,/* 30: Signal */
  &dc_motor_encoder_hardware_simulated_B.complementtheinput1,/* 31: Signal */
  &dc_motor_encoder_hardware_simulated_B.Product2,/* 32: Signal */
  &dc_motor_encoder_hardware_simulated_B.Product3,/* 33: Signal */
  &dc_motor_encoder_hardware_simulated_B.Sum2,/* 34: Signal */
  &dc_motor_encoder_hardware_simulated_P.uUsesimulatedmotor0Userealmotor,/* 35: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Desiredpositionindegrees_Value,/* 36: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Estop_Value,/* 37: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Magnet_Control_Value,/* 38: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Matlab_Input_Value,/* 39: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Gain_Gain,/* 40: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Kd_Gain,/* 41: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Ki_Gain,/* 42: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Kp_Gain,/* 43: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.gain_Gain,/* 44: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Integrator1_IC,/* 45: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Q4AD_P1,/* 46: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Q4AD_P2,/* 47: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Q4AD_P3,/* 48: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Q4AD_P5,/* 49: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Q4AD_P6,/* 50: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Q4AD_P7,/* 51: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.ManualSwitch_CurrentSetting,/* 52: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.PowerforLoadCell_Value,/* 53: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.angular_positionrelative_countC,/* 54: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Saturation_UpperSat,/* 55: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Saturation_LowerSat,/* 56: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_m,/* 57: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_k[0],/* 58: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_c[0],/* 59: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_d,/* 60: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_n[0],/* 61: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_g[0],/* 62: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_f,/* 63: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotor_gv,/* 64: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotor_gp,/* 65: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P1,/* 66: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P2,/* 67: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P3,/* 68: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P4,/* 69: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P5,/* 70: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P6,/* 71: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P7,/* 72: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P8,/* 73: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P9,/* 74: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P10,/* 75: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P11,/* 76: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P12,/* 77: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.BackemfKe1_Gain,/* 78: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Dampingb1_Gain,/* 79: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.GainKt2_Gain,/* 80: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.GainKt3_Gain,/* 81: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Inductance_Gain,/* 82: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.ResistanceR1_Gain,/* 83: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Integrator1_IC_j,/* 84: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Integrator5_IC,/* 85: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Integrator6_IC,/* 86: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  3,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  4                                    /* 5 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 35,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 52,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1019020914U,
    2655919994U,
    3216683979U,
    2113374267U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  dc_motor_encoder_hardware_simulated_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void dc_motor_encoder_hardware_simulated_InitializeDataMapInfo
  (RT_MODEL_dc_motor_encoder_hardware_simulated_T *const
   dc_motor_encoder_hardware_simulated_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi,
                       &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(dc_motor_encoder_hardware_simulated_M);
  dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi.staticMap->rtpSize =
    sizeof(P_dc_motor_encoder_hardware_simulated_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void dc_motor_encoder_hardware_simulated_host_InitializeDataMapInfo
    (dc_motor_encoder_hardware_simulated_host_DataMapInfo_T *dataMap, const char
     *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: dc_motor_encoder_hardware_simulated_capi.c */
