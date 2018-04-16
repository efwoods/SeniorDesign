    
  #ifndef RTW_HEADER_dc_motor_encoder_hardware_simulated_cap_host_h_
  #define RTW_HEADER_dc_motor_encoder_hardware_simulated_cap_host_h_
  
  #ifdef HOST_CAPI_BUILD
  
  #include "rtw_capi.h"
  #include "rtw_modelmap.h"
        
  
  typedef struct {
        rtwCAPI_ModelMappingInfo mmi;
    
      } dc_motor_encoder_hardware_simulated_host_DataMapInfo_T;
      
  #ifdef __cplusplus
  extern "C" {
  #endif

  void dc_motor_encoder_hardware_simulated_host_InitializeDataMapInfo(dc_motor_encoder_hardware_simulated_host_DataMapInfo_T *dataMap, const char *path);
  
  #ifdef __cplusplus
  }
  #endif
  
  #endif /* HOST_CAPI_BUILD */
  
  #endif /* RTW_HEADER_dc_motor_encoder_hardware_simulated_cap_host_h_ */

  /* EOF: dc_motor_encoder_hardware_simulated_capi_host.h */
