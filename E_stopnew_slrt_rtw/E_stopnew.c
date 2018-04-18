/*
 * E_stopnew.c
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "E_stopnew".
 *
 * Model version              : 1.124
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Apr 18 10:12:00 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "E_stopnew_capi.h"
#include "E_stopnew.h"
#include "E_stopnew_private.h"

/* Block signals (auto storage) */
B_E_stopnew_T E_stopnew_B;

/* Block states (auto storage) */
DW_E_stopnew_T E_stopnew_DW;

/* Real-time model */
RT_MODEL_E_stopnew_T E_stopnew_M_;
RT_MODEL_E_stopnew_T *const E_stopnew_M = &E_stopnew_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(E_stopnew_M, 1);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (E_stopnew_M->Timing.TaskCounters.TID[1])++;
  if ((E_stopnew_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    E_stopnew_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
static void E_stopnew_output0(void)    /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Constant: '<Root>/Constant1' */
  E_stopnew_B.Constant1 = E_stopnew_P.Constant1_Value;

  /* S-Function (daquanserq8): '<Root>/Q4 DA ' */

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = E_stopnew_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }
}

/* Model update function for TID0 */
static void E_stopnew_update0(void)    /* Sample time: [0.001s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++E_stopnew_M->Timing.clockTick0)) {
    ++E_stopnew_M->Timing.clockTickH0;
  }

  E_stopnew_M->Timing.t[0] = E_stopnew_M->Timing.clockTick0 *
    E_stopnew_M->Timing.stepSize0 + E_stopnew_M->Timing.clockTickH0 *
    E_stopnew_M->Timing.stepSize0 * 4294967296.0;
}

/* Model output function for TID1 */
static void E_stopnew_output1(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (adquanserq8): '<Root>/Q4 AD' */

  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = E_stopnew_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant'
   */
  E_stopnew_B.RelationalOperator = (E_stopnew_B.Q4AD >=
    E_stopnew_P.Constant_Value);

  /* S-Function (scblock): '<S1>/S-Function' */
  /* ok to acquire for <S1>/S-Function */
  E_stopnew_DW.SFunction_IWORK.AcquireOK = 1;

  /* Stop: '<Root>/Stop Simulation' */
  if (E_stopnew_B.RelationalOperator) {
    rtmSetStopRequested(E_stopnew_M, 1);
  }

  /* End of Stop: '<Root>/Stop Simulation' */
}

/* Model update function for TID1 */
static void E_stopnew_update1(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++E_stopnew_M->Timing.clockTick1)) {
    ++E_stopnew_M->Timing.clockTickH1;
  }

  E_stopnew_M->Timing.t[1] = E_stopnew_M->Timing.clockTick1 *
    E_stopnew_M->Timing.stepSize1 + E_stopnew_M->Timing.clockTickH1 *
    E_stopnew_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
static void E_stopnew_output(int_T tid)
{
  switch (tid) {
   case 0 :
    E_stopnew_output0();
    break;

   case 1 :
    E_stopnew_output1();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
static void E_stopnew_update(int_T tid)
{
  switch (tid) {
   case 0 :
    E_stopnew_update0();
    break;

   case 1 :
    E_stopnew_update1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
static void E_stopnew_initialize(void)
{
  /* Start for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = E_stopnew_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S1>/S-Function' */

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(1, 4, 500);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 3.0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 0.0);
        xpceScopeAcqOK(1, &E_stopnew_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for Constant: '<Root>/Constant1' */
  E_stopnew_B.Constant1 = E_stopnew_P.Constant1_Value;

  /* Start for S-Function (daquanserq8): '<Root>/Q4 DA ' */
  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = E_stopnew_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void E_stopnew_terminate(void)
{
  /* Terminate for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = E_stopnew_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (daquanserq8): '<Root>/Q4 DA ' */
  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = E_stopnew_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  E_stopnew_output(tid);
}

void MdlUpdate(int_T tid)
{
  E_stopnew_update(tid);
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
  E_stopnew_initialize();
}

void MdlTerminate(void)
{
  E_stopnew_terminate();
}

/* Registration function */
RT_MODEL_E_stopnew_T *E_stopnew(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)E_stopnew_M, 0,
                sizeof(RT_MODEL_E_stopnew_T));
  rtsiSetSolverName(&E_stopnew_M->solverInfo,"FixedStepDiscrete");
  E_stopnew_M->solverInfoPtr = (&E_stopnew_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = E_stopnew_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    E_stopnew_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    E_stopnew_M->Timing.sampleTimes = (&E_stopnew_M->Timing.sampleTimesArray[0]);
    E_stopnew_M->Timing.offsetTimes = (&E_stopnew_M->Timing.offsetTimesArray[0]);

    /* task periods */
    E_stopnew_M->Timing.sampleTimes[0] = (0.001);
    E_stopnew_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    E_stopnew_M->Timing.offsetTimes[0] = (0.0);
    E_stopnew_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(E_stopnew_M, &E_stopnew_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = E_stopnew_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = E_stopnew_M->Timing.perTaskSampleHitsArray;
    E_stopnew_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    E_stopnew_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(E_stopnew_M, -1);
  E_stopnew_M->Timing.stepSize0 = 0.001;
  E_stopnew_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    E_stopnew_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(E_stopnew_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(E_stopnew_M->rtwLogInfo, (NULL));
    rtliSetLogT(E_stopnew_M->rtwLogInfo, "tout");
    rtliSetLogX(E_stopnew_M->rtwLogInfo, "");
    rtliSetLogXFinal(E_stopnew_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(E_stopnew_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(E_stopnew_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(E_stopnew_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(E_stopnew_M->rtwLogInfo, 1);
    rtliSetLogY(E_stopnew_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(E_stopnew_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(E_stopnew_M->rtwLogInfo, (NULL));
  }

  E_stopnew_M->solverInfoPtr = (&E_stopnew_M->solverInfo);
  E_stopnew_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&E_stopnew_M->solverInfo, 0.001);
  rtsiSetSolverMode(&E_stopnew_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  E_stopnew_M->blockIO = ((void *) &E_stopnew_B);
  (void) memset(((void *) &E_stopnew_B), 0,
                sizeof(B_E_stopnew_T));

  /* parameters */
  E_stopnew_M->defaultParam = ((real_T *)&E_stopnew_P);

  /* states (dwork) */
  E_stopnew_M->dwork = ((void *) &E_stopnew_DW);
  (void) memset((void *)&E_stopnew_DW, 0,
                sizeof(DW_E_stopnew_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  E_stopnew_InitializeDataMapInfo(E_stopnew_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &E_stopnew_M->NonInlinedSFcns.sfcnInfo;
    E_stopnew_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(E_stopnew_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &E_stopnew_M->Sizes.numSampTimes);
    E_stopnew_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(E_stopnew_M)[0]);
    E_stopnew_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(E_stopnew_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,E_stopnew_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(E_stopnew_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(E_stopnew_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(E_stopnew_M));
    rtssSetStepSizePtr(sfcnInfo, &E_stopnew_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(E_stopnew_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &E_stopnew_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &E_stopnew_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &E_stopnew_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &E_stopnew_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &E_stopnew_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &E_stopnew_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &E_stopnew_M->solverInfoPtr);
  }

  E_stopnew_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&E_stopnew_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    E_stopnew_M->childSfunctions =
      (&E_stopnew_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    E_stopnew_M->childSfunctions[0] =
      (&E_stopnew_M->NonInlinedSFcns.childSFunctions[0]);
    E_stopnew_M->childSfunctions[1] =
      (&E_stopnew_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: E_stopnew/<Root>/Q4 AD (adquanserq8) */
    {
      SimStruct *rts = E_stopnew_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = E_stopnew_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = E_stopnew_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = E_stopnew_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &E_stopnew_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, E_stopnew_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &E_stopnew_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &E_stopnew_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &E_stopnew_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &E_stopnew_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &E_stopnew_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &E_stopnew_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &E_stopnew_B.Q4AD));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 AD");
      ssSetPath(rts, "E_stopnew/Q4 AD");
      ssSetRTModel(rts,E_stopnew_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &E_stopnew_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)E_stopnew_P.Q4AD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)E_stopnew_P.Q4AD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)E_stopnew_P.Q4AD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)E_stopnew_P.Q4AD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)E_stopnew_P.Q4AD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)E_stopnew_P.Q4AD_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)E_stopnew_P.Q4AD_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &E_stopnew_DW.Q4AD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &E_stopnew_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &E_stopnew_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &E_stopnew_DW.Q4AD_IWORK[0]);
      }

      /* registration */
      adquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: E_stopnew/<Root>/Q4 DA  (daquanserq8) */
    {
      SimStruct *rts = E_stopnew_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = E_stopnew_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = E_stopnew_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = E_stopnew_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &E_stopnew_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, E_stopnew_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &E_stopnew_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &E_stopnew_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &E_stopnew_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &E_stopnew_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &E_stopnew_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &E_stopnew_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &E_stopnew_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &E_stopnew_B.Constant1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 DA ");
      ssSetPath(rts, "E_stopnew/Q4 DA ");
      ssSetRTModel(rts,E_stopnew_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &E_stopnew_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)E_stopnew_P.Q4DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)E_stopnew_P.Q4DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)E_stopnew_P.Q4DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)E_stopnew_P.Q4DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)E_stopnew_P.Q4DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)E_stopnew_P.Q4DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)E_stopnew_P.Q4DA_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)E_stopnew_P.Q4DA_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)E_stopnew_P.Q4DA_P9_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &E_stopnew_DW.Q4DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &E_stopnew_DW.Q4DA_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &E_stopnew_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &E_stopnew_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &E_stopnew_DW.Q4DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &E_stopnew_DW.Q4DA_IWORK);
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
  E_stopnew_M->Sizes.numContStates = (0);/* Number of continuous states */
  E_stopnew_M->Sizes.numY = (0);       /* Number of model outputs */
  E_stopnew_M->Sizes.numU = (0);       /* Number of model inputs */
  E_stopnew_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  E_stopnew_M->Sizes.numSampTimes = (2);/* Number of sample times */
  E_stopnew_M->Sizes.numBlocks = (8);  /* Number of blocks */
  E_stopnew_M->Sizes.numBlockIO = (3); /* Number of block outputs */
  E_stopnew_M->Sizes.numBlockPrms = (49);/* Sum of parameter "widths" */
  return E_stopnew_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
