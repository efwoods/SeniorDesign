/*
 * System.c
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

#include "rt_logging_mmi.h"
#include "System_capi.h"
#include "System.h"
#include "System_private.h"

/* Block signals (auto storage) */
B_System_T System_B;

/* Block states (auto storage) */
DW_System_T System_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_System_T System_Y;

/* Real-time model */
RT_MODEL_System_T System_M_;
RT_MODEL_System_T *const System_M = &System_M_;

/* Model output function */
static void System_output(void)
{
  /* S-Function (adquanserq8): '<Root>/Q4 AD' */

  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = System_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Outport: '<Root>/Out1' */
  System_Y.Out1 = System_B.Q4AD;

  /* S-Function (scblock): '<S2>/S-Function' */
  /* ok to acquire for <S2>/S-Function */
  System_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S1>/S-Function' */
  /* ok to acquire for <S1>/S-Function */
  System_DW.SFunction_IWORK_d.AcquireOK = 1;

  /* Constant: '<Root>/Magnet_Control' */
  System_B.Magnet_Control = System_P.Magnet_Control_Value;

  /* S-Function (daquanserq8): '<Root>/Q4 DA ' */

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = System_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
static void System_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++System_M->Timing.clockTick0)) {
    ++System_M->Timing.clockTickH0;
  }

  System_M->Timing.t[0] = System_M->Timing.clockTick0 *
    System_M->Timing.stepSize0 + System_M->Timing.clockTickH0 *
    System_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void System_initialize(void)
{
  /* Start for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = System_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(1, 4, 200);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 30.0);
        xpceScopeAcqOK(1, &System_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for S-Function (scblock): '<S1>/S-Function' */

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Magnet_Control"));
        rl32eSetScope(2, 4, 200);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Magnet_Control"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 11, 0.0);
        rl32eSetTargetScope(2, 10, 2.0);
        xpceScopeAcqOK(2, &System_DW.SFunction_IWORK_d.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for Constant: '<Root>/Magnet_Control' */
  System_B.Magnet_Control = System_P.Magnet_Control_Value;

  /* Start for S-Function (daquanserq8): '<Root>/Q4 DA ' */
  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = System_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void System_terminate(void)
{
  /* Terminate for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = System_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (daquanserq8): '<Root>/Q4 DA ' */
  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = System_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  System_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  System_update();
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
  System_initialize();
}

void MdlTerminate(void)
{
  System_terminate();
}

/* Registration function */
RT_MODEL_System_T *System(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)System_M, 0,
                sizeof(RT_MODEL_System_T));
  rtsiSetSolverName(&System_M->solverInfo,"FixedStepDiscrete");
  System_M->solverInfoPtr = (&System_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = System_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    System_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    System_M->Timing.sampleTimes = (&System_M->Timing.sampleTimesArray[0]);
    System_M->Timing.offsetTimes = (&System_M->Timing.offsetTimesArray[0]);

    /* task periods */
    System_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    System_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(System_M, &System_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = System_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    System_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(System_M, -1);
  System_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    System_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(System_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(System_M->rtwLogInfo, (NULL));
    rtliSetLogT(System_M->rtwLogInfo, "tout");
    rtliSetLogX(System_M->rtwLogInfo, "");
    rtliSetLogXFinal(System_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(System_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(System_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(System_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(System_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &System_Y.Out1
      };

      rtliSetLogYSignalPtrs(System_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "System/Out1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
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

      rtliSetLogYSignalInfo(System_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(System_M->rtwLogInfo, "yout");
  }

  System_M->solverInfoPtr = (&System_M->solverInfo);
  System_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&System_M->solverInfo, 0.001);
  rtsiSetSolverMode(&System_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  System_M->blockIO = ((void *) &System_B);
  (void) memset(((void *) &System_B), 0,
                sizeof(B_System_T));

  /* parameters */
  System_M->defaultParam = ((real_T *)&System_P);

  /* states (dwork) */
  System_M->dwork = ((void *) &System_DW);
  (void) memset((void *)&System_DW, 0,
                sizeof(DW_System_T));

  /* external outputs */
  System_M->outputs = (&System_Y);
  System_Y.Out1 = 0.0;

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  System_InitializeDataMapInfo(System_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &System_M->NonInlinedSFcns.sfcnInfo;
    System_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(System_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &System_M->Sizes.numSampTimes);
    System_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(System_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,System_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(System_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(System_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(System_M));
    rtssSetStepSizePtr(sfcnInfo, &System_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(System_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &System_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &System_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &System_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &System_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &System_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &System_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &System_M->solverInfoPtr);
  }

  System_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&System_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    System_M->childSfunctions = (&System_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    System_M->childSfunctions[0] = (&System_M->NonInlinedSFcns.childSFunctions[0]);
    System_M->childSfunctions[1] = (&System_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: System/<Root>/Q4 AD (adquanserq8) */
    {
      SimStruct *rts = System_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = System_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = System_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = System_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &System_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, System_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &System_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &System_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &System_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &System_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &System_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &System_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &System_B.Q4AD));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 AD");
      ssSetPath(rts, "System/Q4 AD");
      ssSetRTModel(rts,System_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &System_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)System_P.Q4AD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)System_P.Q4AD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)System_P.Q4AD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)System_P.Q4AD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)System_P.Q4AD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)System_P.Q4AD_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)System_P.Q4AD_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &System_DW.Q4AD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &System_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &System_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &System_DW.Q4AD_IWORK[0]);
      }

      /* registration */
      adquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: System/<Root>/Q4 DA  (daquanserq8) */
    {
      SimStruct *rts = System_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = System_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = System_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = System_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &System_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, System_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &System_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &System_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &System_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &System_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &System_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &System_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &System_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &System_B.Magnet_Control;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 DA ");
      ssSetPath(rts, "System/Q4 DA ");
      ssSetRTModel(rts,System_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &System_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)System_P.Q4DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)System_P.Q4DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)System_P.Q4DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)System_P.Q4DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)System_P.Q4DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)System_P.Q4DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)System_P.Q4DA_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)System_P.Q4DA_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)System_P.Q4DA_P9_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &System_DW.Q4DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &System_DW.Q4DA_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &System_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &System_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &System_DW.Q4DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &System_DW.Q4DA_IWORK);
      }

      /* registration */
      daquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  System_M->Sizes.numContStates = (0); /* Number of continuous states */
  System_M->Sizes.numY = (1);          /* Number of model outputs */
  System_M->Sizes.numU = (0);          /* Number of model inputs */
  System_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  System_M->Sizes.numSampTimes = (1);  /* Number of sample times */
  System_M->Sizes.numBlocks = (6);     /* Number of blocks */
  System_M->Sizes.numBlockIO = (2);    /* Number of block outputs */
  System_M->Sizes.numBlockPrms = (48); /* Sum of parameter "widths" */
  return System_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
