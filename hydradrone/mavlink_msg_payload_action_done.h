#pragma once
// MESSAGE PAYLOAD_ACTION_DONE PACKING

#define MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE 45006

MAVPACKED(
typedef struct __mavlink_payload_action_done_t {
 int32_t result; /*<  Inline result*/
 char payload_type[10]; /*<  Payload Type*/
 uint8_t action; /*<  Action*/
 uint8_t error; /*<  Error*/
}) mavlink_payload_action_done_t;

#define MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN 16
#define MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN 16
#define MAVLINK_MSG_ID_45006_LEN 16
#define MAVLINK_MSG_ID_45006_MIN_LEN 16

#define MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC 172
#define MAVLINK_MSG_ID_45006_CRC 172

#define MAVLINK_MSG_PAYLOAD_ACTION_DONE_FIELD_PAYLOAD_TYPE_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PAYLOAD_ACTION_DONE { \
    45006, \
    "PAYLOAD_ACTION_DONE", \
    4, \
    {  { "payload_type", NULL, MAVLINK_TYPE_CHAR, 10, 4, offsetof(mavlink_payload_action_done_t, payload_type) }, \
         { "action", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_payload_action_done_t, action) }, \
         { "error", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_payload_action_done_t, error) }, \
         { "result", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_payload_action_done_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PAYLOAD_ACTION_DONE { \
    "PAYLOAD_ACTION_DONE", \
    4, \
    {  { "payload_type", NULL, MAVLINK_TYPE_CHAR, 10, 4, offsetof(mavlink_payload_action_done_t, payload_type) }, \
         { "action", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_payload_action_done_t, action) }, \
         { "error", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_payload_action_done_t, error) }, \
         { "result", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_payload_action_done_t, result) }, \
         } \
}
#endif

/**
 * @brief Pack a payload_action_done message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param payload_type  Payload Type
 * @param action  Action
 * @param error  Error
 * @param result  Inline result
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_payload_action_done_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *payload_type, uint8_t action, uint8_t error, int32_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN];
    _mav_put_int32_t(buf, 0, result);
    _mav_put_uint8_t(buf, 14, action);
    _mav_put_uint8_t(buf, 15, error);
    _mav_put_char_array(buf, 4, payload_type, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN);
#else
    mavlink_payload_action_done_t packet;
    packet.result = result;
    packet.action = action;
    packet.error = error;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
}

/**
 * @brief Pack a payload_action_done message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param payload_type  Payload Type
 * @param action  Action
 * @param error  Error
 * @param result  Inline result
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_payload_action_done_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *payload_type,uint8_t action,uint8_t error,int32_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN];
    _mav_put_int32_t(buf, 0, result);
    _mav_put_uint8_t(buf, 14, action);
    _mav_put_uint8_t(buf, 15, error);
    _mav_put_char_array(buf, 4, payload_type, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN);
#else
    mavlink_payload_action_done_t packet;
    packet.result = result;
    packet.action = action;
    packet.error = error;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
}

/**
 * @brief Encode a payload_action_done struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param payload_action_done C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_payload_action_done_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_payload_action_done_t* payload_action_done)
{
    return mavlink_msg_payload_action_done_pack(system_id, component_id, msg, payload_action_done->payload_type, payload_action_done->action, payload_action_done->error, payload_action_done->result);
}

/**
 * @brief Encode a payload_action_done struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param payload_action_done C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_payload_action_done_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_payload_action_done_t* payload_action_done)
{
    return mavlink_msg_payload_action_done_pack_chan(system_id, component_id, chan, msg, payload_action_done->payload_type, payload_action_done->action, payload_action_done->error, payload_action_done->result);
}

/**
 * @brief Send a payload_action_done message
 * @param chan MAVLink channel to send the message
 *
 * @param payload_type  Payload Type
 * @param action  Action
 * @param error  Error
 * @param result  Inline result
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_payload_action_done_send(mavlink_channel_t chan, const char *payload_type, uint8_t action, uint8_t error, int32_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN];
    _mav_put_int32_t(buf, 0, result);
    _mav_put_uint8_t(buf, 14, action);
    _mav_put_uint8_t(buf, 15, error);
    _mav_put_char_array(buf, 4, payload_type, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE, buf, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
#else
    mavlink_payload_action_done_t packet;
    packet.result = result;
    packet.action = action;
    packet.error = error;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE, (const char *)&packet, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
#endif
}

/**
 * @brief Send a payload_action_done message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_payload_action_done_send_struct(mavlink_channel_t chan, const mavlink_payload_action_done_t* payload_action_done)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_payload_action_done_send(chan, payload_action_done->payload_type, payload_action_done->action, payload_action_done->error, payload_action_done->result);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE, (const char *)payload_action_done, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
#endif
}

#if MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_payload_action_done_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *payload_type, uint8_t action, uint8_t error, int32_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, result);
    _mav_put_uint8_t(buf, 14, action);
    _mav_put_uint8_t(buf, 15, error);
    _mav_put_char_array(buf, 4, payload_type, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE, buf, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
#else
    mavlink_payload_action_done_t *packet = (mavlink_payload_action_done_t *)msgbuf;
    packet->result = result;
    packet->action = action;
    packet->error = error;
    mav_array_memcpy(packet->payload_type, payload_type, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE, (const char *)packet, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
#endif
}
#endif

#endif

// MESSAGE PAYLOAD_ACTION_DONE UNPACKING


/**
 * @brief Get field payload_type from payload_action_done message
 *
 * @return  Payload Type
 */
static inline uint16_t mavlink_msg_payload_action_done_get_payload_type(const mavlink_message_t* msg, char *payload_type)
{
    return _MAV_RETURN_char_array(msg, payload_type, 10,  4);
}

/**
 * @brief Get field action from payload_action_done message
 *
 * @return  Action
 */
static inline uint8_t mavlink_msg_payload_action_done_get_action(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field error from payload_action_done message
 *
 * @return  Error
 */
static inline uint8_t mavlink_msg_payload_action_done_get_error(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field result from payload_action_done message
 *
 * @return  Inline result
 */
static inline int32_t mavlink_msg_payload_action_done_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a payload_action_done message into a struct
 *
 * @param msg The message to decode
 * @param payload_action_done C-struct to decode the message contents into
 */
static inline void mavlink_msg_payload_action_done_decode(const mavlink_message_t* msg, mavlink_payload_action_done_t* payload_action_done)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    payload_action_done->result = mavlink_msg_payload_action_done_get_result(msg);
    mavlink_msg_payload_action_done_get_payload_type(msg, payload_action_done->payload_type);
    payload_action_done->action = mavlink_msg_payload_action_done_get_action(msg);
    payload_action_done->error = mavlink_msg_payload_action_done_get_error(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN? msg->len : MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN;
        memset(payload_action_done, 0, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN);
    memcpy(payload_action_done, _MAV_PAYLOAD(msg), len);
#endif
}
