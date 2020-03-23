#pragma once
// MESSAGE SET_PAYLOAD_PARAMETER_STR PACKING

#define MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR 45053

MAVPACKED(
typedef struct __mavlink_set_payload_parameter_str_t {
 uint8_t target_system; /*<  Drone System ID*/
 uint8_t target_component; /*<  Payload computer Component ID*/
 uint8_t payload_id; /*<  Payload ID*/
 char parameter[12]; /*<  Payload parameter*/
 char value[19]; /*<  Parameter value*/
}) mavlink_set_payload_parameter_str_t;

#define MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN 34
#define MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_MIN_LEN 34
#define MAVLINK_MSG_ID_45053_LEN 34
#define MAVLINK_MSG_ID_45053_MIN_LEN 34

#define MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_CRC 61
#define MAVLINK_MSG_ID_45053_CRC 61

#define MAVLINK_MSG_SET_PAYLOAD_PARAMETER_STR_FIELD_PARAMETER_LEN 12
#define MAVLINK_MSG_SET_PAYLOAD_PARAMETER_STR_FIELD_VALUE_LEN 19

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_PAYLOAD_PARAMETER_STR { \
    45053, \
    "SET_PAYLOAD_PARAMETER_STR", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_set_payload_parameter_str_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_set_payload_parameter_str_t, target_component) }, \
         { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_set_payload_parameter_str_t, payload_id) }, \
         { "parameter", NULL, MAVLINK_TYPE_CHAR, 12, 3, offsetof(mavlink_set_payload_parameter_str_t, parameter) }, \
         { "value", NULL, MAVLINK_TYPE_CHAR, 19, 15, offsetof(mavlink_set_payload_parameter_str_t, value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_PAYLOAD_PARAMETER_STR { \
    "SET_PAYLOAD_PARAMETER_STR", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_set_payload_parameter_str_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_set_payload_parameter_str_t, target_component) }, \
         { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_set_payload_parameter_str_t, payload_id) }, \
         { "parameter", NULL, MAVLINK_TYPE_CHAR, 12, 3, offsetof(mavlink_set_payload_parameter_str_t, parameter) }, \
         { "value", NULL, MAVLINK_TYPE_CHAR, 19, 15, offsetof(mavlink_set_payload_parameter_str_t, value) }, \
         } \
}
#endif

/**
 * @brief Pack a set_payload_parameter_str message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 * @param parameter  Payload parameter
 * @param value  Parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_payload_parameter_str_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t payload_id, const char *parameter, const char *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, payload_id);
    _mav_put_char_array(buf, 3, parameter, 12);
    _mav_put_char_array(buf, 15, value, 19);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN);
#else
    mavlink_set_payload_parameter_str_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    mav_array_memcpy(packet.parameter, parameter, sizeof(char)*12);
    mav_array_memcpy(packet.value, value, sizeof(char)*19);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_CRC);
}

/**
 * @brief Pack a set_payload_parameter_str message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 * @param parameter  Payload parameter
 * @param value  Parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_payload_parameter_str_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t payload_id,const char *parameter,const char *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, payload_id);
    _mav_put_char_array(buf, 3, parameter, 12);
    _mav_put_char_array(buf, 15, value, 19);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN);
#else
    mavlink_set_payload_parameter_str_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    mav_array_memcpy(packet.parameter, parameter, sizeof(char)*12);
    mav_array_memcpy(packet.value, value, sizeof(char)*19);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_CRC);
}

/**
 * @brief Encode a set_payload_parameter_str struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_payload_parameter_str C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_payload_parameter_str_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_payload_parameter_str_t* set_payload_parameter_str)
{
    return mavlink_msg_set_payload_parameter_str_pack(system_id, component_id, msg, set_payload_parameter_str->target_system, set_payload_parameter_str->target_component, set_payload_parameter_str->payload_id, set_payload_parameter_str->parameter, set_payload_parameter_str->value);
}

/**
 * @brief Encode a set_payload_parameter_str struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_payload_parameter_str C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_payload_parameter_str_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_payload_parameter_str_t* set_payload_parameter_str)
{
    return mavlink_msg_set_payload_parameter_str_pack_chan(system_id, component_id, chan, msg, set_payload_parameter_str->target_system, set_payload_parameter_str->target_component, set_payload_parameter_str->payload_id, set_payload_parameter_str->parameter, set_payload_parameter_str->value);
}

/**
 * @brief Send a set_payload_parameter_str message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 * @param parameter  Payload parameter
 * @param value  Parameter value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_payload_parameter_str_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t payload_id, const char *parameter, const char *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, payload_id);
    _mav_put_char_array(buf, 3, parameter, 12);
    _mav_put_char_array(buf, 15, value, 19);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR, buf, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_CRC);
#else
    mavlink_set_payload_parameter_str_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    mav_array_memcpy(packet.parameter, parameter, sizeof(char)*12);
    mav_array_memcpy(packet.value, value, sizeof(char)*19);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR, (const char *)&packet, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_CRC);
#endif
}

/**
 * @brief Send a set_payload_parameter_str message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_payload_parameter_str_send_struct(mavlink_channel_t chan, const mavlink_set_payload_parameter_str_t* set_payload_parameter_str)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_payload_parameter_str_send(chan, set_payload_parameter_str->target_system, set_payload_parameter_str->target_component, set_payload_parameter_str->payload_id, set_payload_parameter_str->parameter, set_payload_parameter_str->value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR, (const char *)set_payload_parameter_str, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_payload_parameter_str_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t payload_id, const char *parameter, const char *value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, payload_id);
    _mav_put_char_array(buf, 3, parameter, 12);
    _mav_put_char_array(buf, 15, value, 19);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR, buf, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_CRC);
#else
    mavlink_set_payload_parameter_str_t *packet = (mavlink_set_payload_parameter_str_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->payload_id = payload_id;
    mav_array_memcpy(packet->parameter, parameter, sizeof(char)*12);
    mav_array_memcpy(packet->value, value, sizeof(char)*19);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR, (const char *)packet, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_MIN_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_PAYLOAD_PARAMETER_STR UNPACKING


/**
 * @brief Get field target_system from set_payload_parameter_str message
 *
 * @return  Drone System ID
 */
static inline uint8_t mavlink_msg_set_payload_parameter_str_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from set_payload_parameter_str message
 *
 * @return  Payload computer Component ID
 */
static inline uint8_t mavlink_msg_set_payload_parameter_str_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field payload_id from set_payload_parameter_str message
 *
 * @return  Payload ID
 */
static inline uint8_t mavlink_msg_set_payload_parameter_str_get_payload_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field parameter from set_payload_parameter_str message
 *
 * @return  Payload parameter
 */
static inline uint16_t mavlink_msg_set_payload_parameter_str_get_parameter(const mavlink_message_t* msg, char *parameter)
{
    return _MAV_RETURN_char_array(msg, parameter, 12,  3);
}

/**
 * @brief Get field value from set_payload_parameter_str message
 *
 * @return  Parameter value
 */
static inline uint16_t mavlink_msg_set_payload_parameter_str_get_value(const mavlink_message_t* msg, char *value)
{
    return _MAV_RETURN_char_array(msg, value, 19,  15);
}

/**
 * @brief Decode a set_payload_parameter_str message into a struct
 *
 * @param msg The message to decode
 * @param set_payload_parameter_str C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_payload_parameter_str_decode(const mavlink_message_t* msg, mavlink_set_payload_parameter_str_t* set_payload_parameter_str)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_payload_parameter_str->target_system = mavlink_msg_set_payload_parameter_str_get_target_system(msg);
    set_payload_parameter_str->target_component = mavlink_msg_set_payload_parameter_str_get_target_component(msg);
    set_payload_parameter_str->payload_id = mavlink_msg_set_payload_parameter_str_get_payload_id(msg);
    mavlink_msg_set_payload_parameter_str_get_parameter(msg, set_payload_parameter_str->parameter);
    mavlink_msg_set_payload_parameter_str_get_value(msg, set_payload_parameter_str->value);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN? msg->len : MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN;
        memset(set_payload_parameter_str, 0, MAVLINK_MSG_ID_SET_PAYLOAD_PARAMETER_STR_LEN);
    memcpy(set_payload_parameter_str, _MAV_PAYLOAD(msg), len);
#endif
}
