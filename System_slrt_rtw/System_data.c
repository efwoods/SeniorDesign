/*
 * System_data.c
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "System".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Apr 12 20:07:43 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "System.h"
#include "System_private.h"

/* Block parameters (auto storage) */
P_System_T System_P = {
  /*  Computed Parameter: Q4AD_P1_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P2_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P3_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: index03
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P4_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: Q4AD_P5_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P6_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P7_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Q4 AD'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Magnet_Control'
                                        */

  /*  Computed Parameter: Q4DA_P1_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P2_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P3_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  -5.0,                                /* Expression: range
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P4_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P5_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P6_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P7_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P8_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P9_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  -1.0                                 /* Expression: pciSlot
                                        * Referenced by: '<Root>/Q4 DA '
                                        */
};
