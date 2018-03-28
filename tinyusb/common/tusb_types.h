/**************************************************************************/
/*!
    @file     tusb_types.h
    @author   hathach (tinyusb.org)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, hathach (tinyusb.org)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    This file is part of the tinyusb stack.
*/
/**************************************************************************/

/** \ingroup group_usb_definitions
 *  \defgroup USBDef_Type USB Types
 *  @{ */

#ifndef _TUSB_TYPES_H_
#define _TUSB_TYPES_H_

#include <stdbool.h>
#include <stdint.h>
#include "tusb_compiler.h"

#ifdef __cplusplus
 extern "C" {
#endif

/*------------------------------------------------------------------*/
/* CONSTANTS
 *------------------------------------------------------------------*/

/// defined base on EHCI specs value for Endpoint Speed
typedef enum
{
  TUSB_SPEED_FULL = 0,
  TUSB_SPEED_LOW     ,
  TUSB_SPEED_HIGH
}tusb_speed_t;

/// defined base on USB Specs Endpoint's bmAttributes
typedef enum
{
  TUSB_XFER_CONTROL = 0 ,
  TUSB_XFER_ISOCHRONOUS ,
  TUSB_XFER_BULK        ,
  TUSB_XFER_INTERRUPT
}tusb_xfer_type_t;

typedef enum
{
  TUSB_DIR_OUT = 0,
  TUSB_DIR_IN  = 1,

  TUSB_DIR_IN_MASK = 0x80
}tusb_dir_t;


/// USB Descriptor Types (section 9.4 table 9-5)
typedef enum
{
  TUSB_DESC_DEVICE                = 0x01 ,
  TUSB_DESC_CONFIGURATION         = 0x02 ,
  TUSB_DESC_STRING                = 0x03 ,
  TUSB_DESC_INTERFACE             = 0x04 ,
  TUSB_DESC_ENDPOINT              = 0x05 ,
  TUSB_DESC_DEVICE_QUALIFIER      = 0x06 ,
  TUSB_DESC_OTHER_SPEED_CONFIG    = 0x07 ,
  TUSB_DESC_INTERFACE_POWER       = 0x08 ,
  TUSB_DESC_OTG                   = 0x09 ,
  TUSB_DESC_DEBUG                 = 0x0A ,
  TUSB_DESC_INTERFACE_ASSOCIATION = 0x0B ,
  TUSB_DESC_CLASS_SPECIFIC        = 0x24
}tusb_desc_type_t;

typedef enum
{
  TUSB_REQ_GET_STATUS =0     , ///< 0
  TUSB_REQ_CLEAR_FEATURE     , ///< 1
  TUSB_REQ_RESERVED          , ///< 2
  TUSB_REQ_SET_FEATURE       , ///< 3
  TUSB_REQ_RESERVED2         , ///< 4
  TUSB_REQ_SET_ADDRESS       , ///< 5
  TUSB_REQ_GET_DESCRIPTOR    , ///< 6
  TUSB_REQ_SET_DESCRIPTOR    , ///< 7
  TUSB_REQ_GET_CONFIGURATION , ///< 8
  TUSB_REQ_SET_CONFIGURATION , ///< 9
  TUSB_REQ_GET_INTERFACE     , ///< 10
  TUSB_REQ_SET_INTERFACE     , ///< 11
  TUSB_REQ_SYNCH_FRAME         ///< 12
}tusb_request_code_t;

typedef enum
{
  TUSB_REQ_TYPE_STANDARD = 0,
  TUSB_REQ_TYPE_CLASS,
  TUSB_REQ_TYPE_VENDOR
} tusb_request_type_t;

typedef enum
{
  TUSB_REQ_RCPT_DEVICE =0,
  TUSB_REQ_RCPT_INTERFACE,
  TUSB_REQ_RCPT_ENDPOINT,
  TUSB_REQ_RCPT_OTHER
} tusb_request_recipient_t;

typedef enum
{
  TUSB_CLASS_UNSPECIFIED          = 0    , ///< 0
  TUSB_CLASS_AUDIO                = 1    , ///< 1
  TUSB_CLASS_CDC                  = 2    , ///< 2
  TUSB_CLASS_HID                  = 3    , ///< 3
  TUSB_CLASS_RESERVED_4           = 4    , ///< 4
  TUSB_CLASS_PHYSICAL             = 5    , ///< 5
  TUSB_CLASS_IMAGE                = 6    , ///< 6
  TUSB_CLASS_PRINTER              = 7    , ///< 7
  TUSB_CLASS_MSC                  = 8    , ///< 8
  TUSB_CLASS_HUB                  = 9    , ///< 9
  TUSB_CLASS_CDC_DATA             = 10   , ///< 10
  TUSB_CLASS_SMART_CARD           = 11   , ///< 11
  TUSB_CLASS_RESERVED_12          = 12   , ///< 12
  TUSB_CLASS_CONTENT_SECURITY     = 13   , ///< 13
  TUSB_CLASS_VIDEO                = 14   , ///< 14
  TUSB_CLASS_PERSONAL_HEALTHCARE  = 15   , ///< 15
  TUSB_CLASS_AUDIO_VIDEO          = 16   , ///< 16

  TUSB_CLASS_MAPPED_INDEX_START   = 17   , // TODO Map DIAGNOSTIC, WIRELESS_CONTROLLER, MISC, VENDOR_SPECIFIC to this to minimize the array

  TUSB_CLASS_DIAGNOSTIC           = 0xDC ,
  TUSB_CLASS_WIRELESS_CONTROLLER  = 0xE0 ,
  TUSB_CLASS_MISC                 = 0xEF ,
  TUSB_CLASS_APPLICATION_SPECIFIC = 0xFE ,
  TUSB_CLASS_VENDOR_SPECIFIC      = 0xFF
}tusb_class_code_t;

typedef enum
{
  MISC_SUBCLASS_COMMON = 2
}misc_subclass_type_t;

typedef enum
{
  MISC_PROTOCOL_IAD = 1
}misc_protocol_type_t;

enum {
  TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP = BIT_(5),
  TUSB_DESC_CONFIG_ATT_SELF_POWER    = BIT_(6),
  TUSB_DESC_CONFIG_ATT_BUS_POWER     = BIT_(7)
};

#define TUSB_DESC_CONFIG_POWER_MA(x)  ((x)/2)

/// Device State
typedef enum
{
  TUSB_DEVICE_STATE_UNPLUG = 0  ,
  TUSB_DEVICE_STATE_ADDRESSED   ,
  TUSB_DEVICE_STATE_CONFIGURED  ,
  TUSB_DEVICE_STATE_SUSPENDED   ,

  TUSB_DEVICE_STATE_REMOVING    ,
  TUSB_DEVICE_STATE_SAFE_REMOVE ,

  TUSB_DEVICE_STATE_INVALID_PARAMETER
}tusb_device_state_t;

typedef enum
{
  TUSB_EVENT_NONE = 0,
  TUSB_EVENT_XFER_COMPLETE,
  TUSB_EVENT_XFER_ERROR,
  TUSB_EVENT_XFER_STALLED,

  TUSB_EVENT_BUS_RESET, // TODO refractor
  TUSB_EVENT_SETUP_RECEIVED,
}tusb_event_t;

enum {
  DESCRIPTOR_OFFSET_LENGTH = 0,
  DESCRIPTOR_OFFSET_TYPE   = 1
};

enum {
  INTERFACE_INVALID_NUMBER = 0xff
};

static inline uint8_t std_class_code_to_index(uint8_t std_class_code)
{
  return  (std_class_code <= TUSB_CLASS_AUDIO_VIDEO          ) ? std_class_code                    :
          (std_class_code == TUSB_CLASS_DIAGNOSTIC           ) ? TUSB_CLASS_MAPPED_INDEX_START     :
          (std_class_code == TUSB_CLASS_WIRELESS_CONTROLLER  ) ? TUSB_CLASS_MAPPED_INDEX_START + 1 :
          (std_class_code == TUSB_CLASS_MISC                 ) ? TUSB_CLASS_MAPPED_INDEX_START + 2 :
          (std_class_code == TUSB_CLASS_APPLICATION_SPECIFIC ) ? TUSB_CLASS_MAPPED_INDEX_START + 3 :
          (std_class_code == TUSB_CLASS_VENDOR_SPECIFIC      ) ? TUSB_CLASS_MAPPED_INDEX_START + 4 : 0;
}

//--------------------------------------------------------------------+
// STANDARD DESCRIPTORS
//--------------------------------------------------------------------+

/// USB Standard Device Descriptor (section 9.6.1, table 9-8)
typedef struct ATTR_PACKED
{
  uint8_t  bLength            ; ///< Size of this descriptor in bytes.
  uint8_t  bDescriptorType    ; ///< DEVICE Descriptor Type.
  uint16_t bcdUSB             ; ///< BUSB Specification Release Number in Binary-Coded Decimal (i.e., 2.10 is 210H). This field identifies the release of the USB Specification with which the device and its descriptors are compliant.

  uint8_t  bDeviceClass       ; ///< Class code (assigned by the USB-IF). \li If this field is reset to zero, each interface within a configuration specifies its own class information and the various interfaces operate independently. \li If this field is set to a value between 1 and FEH, the device supports different class specifications on different interfaces and the interfaces may not operate independently. This value identifies the class definition used for the aggregate interfaces. \li If this field is set to FFH, the device class is vendor-specific.
  uint8_t  bDeviceSubClass    ; ///< Subclass code (assigned by the USB-IF). These codes are qualified by the value of the bDeviceClass field. \li If the bDeviceClass field is reset to zero, this field must also be reset to zero. \li If the bDeviceClass field is not set to FFH, all values are reserved for assignment by the USB-IF.
  uint8_t  bDeviceProtocol    ; ///< Protocol code (assigned by the USB-IF). These codes are qualified by the value of the bDeviceClass and the bDeviceSubClass fields. If a device supports class-specific protocols on a device basis as opposed to an interface basis, this code identifies the protocols that the device uses as defined by the specification of the device class. \li If this field is reset to zero, the device does not use class-specific protocols on a device basis. However, it may use classspecific protocols on an interface basis. \li If this field is set to FFH, the device uses a vendor-specific protocol on a device basis.
  uint8_t  bMaxPacketSize0    ; ///< Maximum packet size for endpoint zero (only 8, 16, 32, or 64 are valid). For HS devices is fixed to 64.

  uint16_t idVendor           ; ///< Vendor ID (assigned by the USB-IF).
  uint16_t idProduct          ; ///< Product ID (assigned by the manufacturer).
  uint16_t bcdDevice          ; ///< Device release number in binary-coded decimal.
  uint8_t  iManufacturer      ; ///< Index of string descriptor describing manufacturer.
  uint8_t  iProduct           ; ///< Index of string descriptor describing product.
  uint8_t  iSerialNumber      ; ///< Index of string descriptor describing the device's serial number.

  uint8_t  bNumConfigurations ; ///< Number of possible configurations.
} tusb_desc_device_t;

/// USB Standard Configuration Descriptor (section 9.6.1 table 9-10) */
typedef struct ATTR_PACKED
{
  uint8_t  bLength             ; ///< Size of this descriptor in bytes
  uint8_t  bDescriptorType     ; ///< CONFIGURATION Descriptor Type
  uint16_t wTotalLength        ; ///< Total length of data returned for this configuration. Includes the combined length of all descriptors (configuration, interface, endpoint, and class- or vendor-specific) returned for this configuration.

  uint8_t  bNumInterfaces      ; ///< Number of interfaces supported by this configuration
  uint8_t  bConfigurationValue ; ///< Value to use as an argument to the SetConfiguration() request to select this configuration.
  uint8_t  iConfiguration      ; ///< Index of string descriptor describing this configuration
  uint8_t  bmAttributes        ; ///< Configuration characteristics \n D7: Reserved (set to one)\n D6: Self-powered \n D5: Remote Wakeup \n D4...0: Reserved (reset to zero) \n D7 is reserved and must be set to one for historical reasons. \n A device configuration that uses power from the bus and a local source reports a non-zero value in bMaxPower to indicate the amount of bus power required and sets D6. The actual power source at runtime may be determined using the GetStatus(DEVICE) request (see USB 2.0 spec Section 9.4.5). \n If a device configuration supports remote wakeup, D5 is set to one.
  uint8_t  bMaxPower           ; ///< Maximum power consumption of the USB device from the bus in this specific configuration when the device is fully operational. Expressed in 2 mA units (i.e., 50 = 100 mA).
} tusb_desc_configuration_t;

/// USB Standard Interface Descriptor (section 9.6.1 table 9-12)
typedef struct ATTR_PACKED
{
  uint8_t  bLength            ; ///< Size of this descriptor in bytes
  uint8_t  bDescriptorType    ; ///< INTERFACE Descriptor Type

  uint8_t  bInterfaceNumber   ; ///< Number of this interface. Zero-based value identifying the index in the array of concurrent interfaces supported by this configuration.
  uint8_t  bAlternateSetting  ; ///< Value used to select this alternate setting for the interface identified in the prior field
  uint8_t  bNumEndpoints      ; ///< Number of endpoints used by this interface (excluding endpoint zero). If this value is zero, this interface only uses the Default Control Pipe.
  uint8_t  bInterfaceClass    ; ///< Class code (assigned by the USB-IF). \li A value of zero is reserved for future standardization. \li If this field is set to FFH, the interface class is vendor-specific. \li All other values are reserved for assignment by the USB-IF.
  uint8_t  bInterfaceSubClass ; ///< Subclass code (assigned by the USB-IF). \n These codes are qualified by the value of the bInterfaceClass field. \li If the bInterfaceClass field is reset to zero, this field must also be reset to zero. \li If the bInterfaceClass field is not set to FFH, all values are reserved for assignment by the USB-IF.
  uint8_t  bInterfaceProtocol ; ///< Protocol code (assigned by the USB). \n These codes are qualified by the value of the bInterfaceClass and the bInterfaceSubClass fields. If an interface supports class-specific requests, this code identifies the protocols that the device uses as defined by the specification of the device class. \li If this field is reset to zero, the device does not use a class-specific protocol on this interface. \li If this field is set to FFH, the device uses a vendor-specific protocol for this interface.
  uint8_t  iInterface         ; ///< Index of string descriptor describing this interface
} tusb_desc_interface_t;

/// USB Standard Endpoint Descriptor (section 9.6.1 table 9-13)
typedef struct ATTR_PACKED
{
  uint8_t  bLength          ; ///< Size of this descriptor in bytes
  uint8_t  bDescriptorType  ; ///< ENDPOINT Descriptor Type

  uint8_t  bEndpointAddress ; ///< The address of the endpoint on the USB device described by this descriptor. The address is encoded as follows: \n Bit 3...0: The endpoint number \n Bit 6...4: Reserved, reset to zero \n Bit 7: Direction, ignored for control endpoints 0 = OUT endpoint 1 = IN endpoint.

  struct ATTR_PACKED {
    uint8_t xfer  : 2;
    uint8_t sync  : 2;
    uint8_t usage : 2;
    uint8_t       : 2;
  } bmAttributes     ; ///< This field describes the endpoint's attributes when it is configured using the bConfigurationValue. \n Bits 1..0: Transfer Type \n- 00 = Control \n- 01 = Isochronous \n- 10 = Bulk \n- 11 = Interrupt \n If not an isochronous endpoint, bits 5..2 are reserved and must be set to zero. If isochronous, they are defined as follows: \n Bits 3..2: Synchronization Type \n- 00 = No Synchronization \n- 01 = Asynchronous \n- 10 = Adaptive \n- 11 = Synchronous \n Bits 5..4: Usage Type \n- 00 = Data endpoint \n- 01 = Feedback endpoint \n- 10 = Implicit feedback Data endpoint \n- 11 = Reserved \n Refer to Chapter 5 of USB 2.0 specification for more information. \n All other bits are reserved and must be reset to zero. Reserved bits must be ignored by the host.

  struct ATTR_PACKED {
    uint16_t size           : 11; ///< Maximum packet size this endpoint is capable of sending or receiving when this configuration is selected. \n For isochronous endpoints, this value is used to reserve the bus time in the schedule, required for the per-(micro)frame data payloads. The pipe may, on an ongoing basis, actually use less bandwidth than that reserved. The device reports, if necessary, the actual bandwidth used via its normal, non-USB defined mechanisms. \n For all endpoints, bits 10..0 specify the maximum packet size (in bytes). \n For high-speed isochronous and interrupt endpoints: \n Bits 12..11 specify the number of additional transaction opportunities per microframe: \n- 00 = None (1 transaction per microframe) \n- 01 = 1 additional (2 per microframe) \n- 10 = 2 additional (3 per microframe) \n- 11 = Reserved \n Bits 15..13 are reserved and must be set to zero.
    uint16_t hs_period_mult : 2;
    uint16_t : 0;
  }wMaxPacketSize;

  uint8_t  bInterval        ; ///< Interval for polling endpoint for data transfers. Expressed in frames or microframes depending on the device operating speed (i.e., either 1 millisecond or 125 us units). \n- For full-/high-speed isochronous endpoints, this value must be in the range from 1 to 16. The bInterval value is used as the exponent for a \f$ 2^(bInterval-1) \f$ value; e.g., a bInterval of 4 means a period of 8 (\f$ 2^(4-1) \f$). \n- For full-/low-speed interrupt endpoints, the value of this field may be from 1 to 255. \n- For high-speed interrupt endpoints, the bInterval value is used as the exponent for a \f$ 2^(bInterval-1) \f$ value; e.g., a bInterval of 4 means a period of 8 (\f$ 2^(4-1) \f$) . This value must be from 1 to 16. \n- For high-speed bulk/control OUT endpoints, the bInterval must specify the maximum NAK rate of the endpoint. A value of 0 indicates the endpoint never NAKs. Other values indicate at most 1 NAK each bInterval number of microframes. This value must be in the range from 0 to 255. \n Refer to Chapter 5 of USB 2.0 specification for more information.
} tusb_desc_endpoint_t;

/// USB Other Speed Configuration Descriptor (section 9.6.1 table 9-11)
typedef struct ATTR_PACKED
{
  uint8_t  bLength             ; ///< Size of descriptor
  uint8_t  bDescriptorType     ; ///< Other_speed_Configuration Type
  uint16_t wTotalLength        ; ///< Total length of data returned

  uint8_t  bNumInterfaces      ; ///< Number of interfaces supported by this speed configuration
  uint8_t  bConfigurationValue ; ///< Value to use to select configuration
  uint8_t  IConfiguration      ; ///< Index of string descriptor
  uint8_t  bmAttributes        ; ///< Same as Configuration descriptor
  uint8_t  bMaxPower           ; ///< Same as Configuration descriptor
} tusb_desc_other_speed_t;

/// USB Device Qualifier Descriptor (section 9.6.1 table 9-9)
typedef struct ATTR_PACKED
{
  uint8_t  bLength            ; ///< Size of descriptor
  uint8_t  bDescriptorType    ; ///< Device Qualifier Type
  uint16_t bcdUSB             ; ///< USB specification version number (e.g., 0200H for V2.00)

  uint8_t  bDeviceClass       ; ///< Class Code
  uint8_t  bDeviceSubClass    ; ///< SubClass Code
  uint8_t  bDeviceProtocol    ; ///< Protocol Code
  uint8_t  bMaxPacketSize0    ; ///< Maximum packet size for other speed
  uint8_t  bNumConfigurations ; ///< Number of Other-speed Configurations
  uint8_t  bReserved          ; ///< Reserved for future use, must be zero
} tusb_desc_device_qualifier_t;

/// USB Interface Association Descriptor (IAD ECN)
typedef struct ATTR_PACKED
{
  uint8_t bLength           ; ///< Size of descriptor
  uint8_t bDescriptorType   ; ///< Other_speed_Configuration Type

  uint8_t bFirstInterface   ; ///< Index of the first associated interface.
  uint8_t bInterfaceCount   ; ///< Total number of associated interfaces.

  uint8_t bFunctionClass    ; ///< Interface class ID.
  uint8_t bFunctionSubClass ; ///< Interface subclass ID.
  uint8_t bFunctionProtocol ; ///< Interface protocol ID.

  uint8_t iFunction         ; ///< Index of the string descriptor describing the interface association.
} tusb_desc_interface_assoc_t;

/// USB Header Descriptor
typedef struct ATTR_PACKED
{
  uint8_t  bLength         ; ///< Size of this descriptor in bytes
  uint8_t  bDescriptorType ; ///< Descriptor Type
} tusb_desc_header_t;

typedef struct ATTR_PACKED
{
  uint8_t  bLength         ; ///< Size of this descriptor in bytes
  uint8_t  bDescriptorType ; ///< Descriptor Type
  uint16_t unicode_string[];
} tusb_desc_string_t;


/*------------------------------------------------------------------*/
/* Types
 *------------------------------------------------------------------*/

typedef struct ATTR_PACKED{
  union {
    struct ATTR_PACKED {
      uint8_t recipient :  5; ///< Recipient type tusb_request_recipient_t.
      uint8_t type      :  2; ///< Request type tusb_request_type_t.
      uint8_t direction :  1; ///< Direction type. tusb_dir_t
    } bmRequestType_bit;
    uint8_t bmRequestType;
  };

  uint8_t  bRequest;
  uint16_t wValue;
  uint16_t wIndex;
  uint16_t wLength;
} tusb_control_request_t;

VERIFY_STATIC( sizeof(tusb_control_request_t) == 8, "mostly compiler option issue");

// TODO move to somewhere suitable
static inline uint8_t bm_request_type(uint8_t direction, uint8_t type, uint8_t recipient)
{
  return ((uint8_t) (direction << 7)) | ((uint8_t) (type << 5)) | (recipient);
}

// Get direction from Endpoint address
static inline tusb_dir_t edpt_dir(uint8_t addr)
{
  return (addr & TUSB_DIR_IN_MASK) ? TUSB_DIR_IN : TUSB_DIR_OUT;
}

// Get Endpoint number from address
static inline uint8_t edpt_number(uint8_t addr)
{
  return addr & (~TUSB_DIR_IN_MASK);
}

static inline uint8_t edpt_addr(uint8_t num, tusb_dir_t dir)
{
  return num | (dir == TUSB_DIR_IN ? TUSB_DIR_IN_MASK : 0);
}

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_TYPES_H_ */

/** @} */
