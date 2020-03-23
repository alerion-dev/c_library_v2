#pragma once
// MESSAGE SET_PAYLOAD_PARAMETER PACKING

#define MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER 45003

MAVPACKED(
typedef struct __mavlink_set_payload_parameter_t {
 float value; /*<  Parameter value*/
 char payload_type[10]; /*<  Payload Type*/
 char parameter[18]; /*<  Payload parameter*/
}) mavlink_set_payload_parameter_t;

#define MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN 32
#define MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_MIN_LEN 32
#define MAVLINK_MSG_ID_45003_LEN 32
#define MAVLINK_MSG_ID_45003_MIN_LEN 32

#define MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_CRC 138
#define MAVLINK_MSG_ID_45003_CRC 138

#define MAVLINK_MSG_SET_PAYLOAD_PARAMETER_FIELD_PAYLOAD_TYPE_LEN 10
#define MAVLINK_MSG_SET_PAYLOAD_PARAMETER_FIELD_PARAMETER_LEN 18

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_PAYLOAD_PARAMETER { \
    45003, \
    "SET_PAYLOAD_PARAMETER", \
    3, \
    {  { "payload_type", NULL, MAVLINK_TYPE_CHAR, 10, 4, offsetof(mavlink_set_payload_parameter_t, payload_type) }, \
         { "parameter", NULL, MAVLINK_TYPE_CHAR, 18, 14, offsetof(mavlink_set_payload_parameter_t, parameter) }, \
         { "value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_payload_parameter_t, value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_PAYLOAD_PARAMETER { \
    "SET_PAYLOAD_PARAMETER", \
    3, \
    {  { "payload_type", NULL, MAVLINK_TYPE_CHAR, 10, 4, offsetof(mavlink_set_payload_parameter_t, payload_type) }, \
         { "parameter", NULL, MAVLINK_TYPE_CHAR, 18, 14, offsetof(mavlink_set_payload_parameter_t, parameter) }, \
         { "value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_payload_parameter_t, value) }, \
         } \
}
#endif

/**
 * @brief Pack a set_payload_parameter message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param payload_type  Payload Type
 * @param parameter  Payload parameter
 * @param value  Parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_payload_parameter_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *payload_type, const char *parameter, float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN];
    _mav_put_float(buf, 0, value);
    _mav_put_char_array(buf, 4, payload_type, 10);
    _mav_put_char_array(buf, 14, parameter, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN);
#else
    mavlink_set_payload_parameter_t packet;
    packet.value = value;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
    mav_array_memcpy(packet.parameter, parameter, sizeof(char)*18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_CRC);
}

/**
 * @brief Pack a set_payload_parameter message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param payload_type  Payload Type
 * @param parameter  Payload parameter
 * @param value  Parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_payload_parameter_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *payload_type,const char *parameter,float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN];
    _mav_put_float(buf, 0, value);
    _mav_put_char_array(buf, 4, payload_type, 10);
    _mav_put_char_array(buf, 14, parameter, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN);
#else
    mavlink_set_payload_parameter_t packet;
    packet.value = value;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
    mav_array_memcpy(packet.parameter, parameter, sizeof(char)*18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_CRC);
}

/**
 * @brief Encode a set_payload_parameter struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_payload_parameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_payload_parameter_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_payload_parameter_t* set_payload_parameter)
{
    return mavlink_msg_set_payload_parameter_pack(system_id, component_id, msg, set_payload_parameter->payload_type, set_payload_parameter->parameter, set_payload_parameter->value);
}

/**
 * @brief Encode a set_payload_parameter struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_payload_parameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_payload_parameter_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_payload_parameter_t* set_payload_parameter)
{
    return mavlink_msg_set_payload_parameter_pack_chan(system_id, component_id, chan, msg, set_payload_parameter->payload_type, set_payload_parameter->parameter, set_payload_parameter->value);
}

/**
 * @brief Send a set_payload_parameter message
 * @param chan MAVLink channel to send the message
 *
 * @param payload_type  Payload Type
 * @param parameter  Payload parameter
 * @param value  Parameter value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_payload_parameter_send(mavlink_channel_t chan, const char *payload_type, const char *parameter, float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN];
    _mav_put_float(buf, 0, value);
    _mav_put_char_array(buf, 4, payload_type, 10);
    _mav_put_char_array(buf, 14, parameter, 18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER, buf, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_CRC);
#else
    mavlink_set_payload_parameter_t packet;
    packet.value = value;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
    mav_array_memcpy(packet.parameter, parameter, sizeof(char)*18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER, (const char *)&packet, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_CRC);
#endif
}

/**
 * @brief Send a set_payload_parameter message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_payload_parameter_send_struct(mavlink_channel_t chan, const mavlink_set_payload_parameter_t* set_payload_parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_payload_parameter_send(chan, set_payload_parameter->payload_type, set_payload_parameter->parameter, set_payload_parameter->value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER, (const char *)set_payload_parameter, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_payload_parameter_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *payload_type, const char *parameter, float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, value);
    _mav_put_char_array(buf, 4, payload_type, 10);
    _mav_put_char_array(buf, 14, parameter, 18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER, buf, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_CRC);
#else
    mavlink_set_payload_parameter_t *packet = (mavlink_set_payload_parameter_t *)msgbuf;
    packet->value = value;
    mav_array_memcpy(packet->payload_type, payload_type, sizeof(char)*10);
    mav_array_memcpy(packet->parameter, parameter, sizeof(char)*18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER, (const char *)packet, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_PAYLOAD_PARAMETER UNPACKING


/**
 * @brief Get field payload_type from set_payload_parameter message
 *
 * @return  Payload Type
 */
static inline uint16_t mavlink_msg_set_payload_parameter_get_payload_type(const mavlink_message_t* msg, char *payload_type)
{
    return _MAV_RETURN_char_array(msg, payload_type, 10,  4);
}

/**
 * @brief Get field parameter from set_payload_parameter message
 *
 * @return  Payload parameter
 */
static inline uint16_t mavlink_msg_set_payload_parameter_get_parameter(const mavlink_message_t* msg, char *parameter)
{
    return _MAV_RETURN_char_array(msg, parameter, 18,  14);
}

/**
 * @brief Get field value from set_payload_parameter message
 *
 * @return  Parameter value
 */
static inline float mavlink_msg_set_payload_parameter_get_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a set_payload_parameter message into a struct
 *
 * @param msg The message to decode
 * @param set_payload_parameter C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_payload_parameter_decode(const mavlink_message_t* msg, mavlink_set_payload_parameter_t* set_payload_parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_payload_parameter->value = mavlink_msg_set_payload_parameter_get_value(msg);
    mavlink_msg_set_payload_parameter_get_payload_type(msg, set_payload_parameter->payload_type);
    mavlink_msg_set_payload_parameter_get_parameter(msg, set_payload_parameter->parameter);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN? msg->len : MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN;
        memset(set_payload_parameter, 0, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_LEN);
    memcpy(set_payload_parameter, _MAV_PAYLOAD(msg), len);
#endif
}
