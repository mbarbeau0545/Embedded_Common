/**
 * @file        LIBRamp.h
 * @brief       Memomry access control for DMA & user access\n.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef LIBRAMP_H_INCLUDED
#define LIBRAMP_H_INCLUDED

    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************
    #define LIBRAMP_MAX_REGISTRATION ((t_uint8)14)
    // ********************************************************************
    // *                      Types
    // ********************************************************************

    //-----------------------------ENUM TYPES-----------------------------//
    typedef enum 
    {
        LIBRAMP_MODE_LINEAR = 0x00,              /**< Compute Ramp based on linear calculation */
        LIBRAMP_MODE_EXPONENTIAL,               /**< Compute Ramp based on exponentional calculation */
        LIBRAMP_MODE_SIGMOIDALE,
        LIBRAMP_MODE_NB
    } t_eLIBRamp_Mode;

    typedef enum 
    {
        LIBRAMP_SIGMOID_SLOPE_SLOW = 0x00,
        LIBRAMP_SIGMOID_SLOP_MEDIUM,
        LIBRAMP_SIGMOID_SLOPE_HIGH,

        LIBRAMP_SIGMOID_SLOPE_NB
    } t_eLIBRamp_SigmoidSlope;
    /* CAUTION : Automatic generated code section for Enum: Start */

    /* CAUTION : Automatic generated code section for Enum: End */
   
    //-----------------------------STRUCT TYPES---------------------------//
    typedef struct {
        t_float32 accelerationMax_f32;  /**< Maximum increment per update (for acceleration). */
        t_float32 decelerationMax_f32;  /**< Maximum decrement per update (for deceleration). */
    } t_sLIBRamp_LinearCfg;
    
    typedef struct {
        t_float32 expFactor_f32;        /**< Exponential factor applied during acceleration or deceleration. */
        t_float32 smoothingFactor_f32;  /**< Smoothing threshold below which the target value is directly reached. */
    } t_sLIBRamp_ExpCfg;
    
    typedef struct {
        t_float32 slopSpeed_f32;            /**< Slope speed used to calculate the kFactor. */
        t_float32 kFactor_f32;              /**< Derived factor (calculated when the target changes). */
    } t_sLIBRamp_SigmoidaleCfg;
    
    typedef union {
        t_sLIBRamp_LinearCfg        linearCfg_s;
        t_sLIBRamp_ExpCfg           expCfg_s;
        t_sLIBRamp_SigmoidaleCfg    sigmoidaleCfg_s;
    } t_uLIBRamp_RampCfg;
    

    typedef struct 
    {
        t_eLIBRamp_Mode rampMode_e;         /**< Specifies the mode of the ramp.  */
        t_uLIBRamp_RampCfg rampInfo_u;
        t_float32 startValue_f32;           /**< Starting value of the ramp when the target changes */
        t_uint32 totalSteps_u32;
    } t_sLIBRamp_RampCfg;
    /* CAUTION : Automatic generated code section for Structure: Start */

    /* CAUTION : Automatic generated code section for Structure: End */

    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    /**
    *	@brief
    *	@note   
    *
    *
    *	@param[in] 
    *	@param[in]
    *	 
    *
    *
    */
    t_eReturnCode LIBRamp_Init(t_sLIBRamp_RampCfg f_rampCfg_s, t_uint8 *f_rampID_pu8);
    /**
    *	@brief
    *	@note   
    *
    *
    *	@param[in] 
    *	@param[in]
    *	 
    *
    *
    */
    t_eReturnCode LIBRamp_Compute(  t_uint8 f_rampID_u8, 
                                    t_float32 f_rawValue_f32,
                                    t_float32 * f_computeValue_pf32);


    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************
    
#endif // LIBRAMP_H_INCLUDED
//************************************************************************************
// End of File
//************************************************************************************

/**
 *	@brief
 *	@note   
 *
 *
 *	@param[in] 
 *	@param[in]
 *	 
 *
 *
 */
