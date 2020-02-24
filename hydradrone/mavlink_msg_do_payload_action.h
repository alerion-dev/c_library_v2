#pragma once
// MESSAGE DO_PAYLOAD_ACTION PACKING

#define MAVLINK_MSG_ID_DO_PAYLOAD_ACTION 45005

MAVPACKED(
typedef struct __mavlink_do_payload_action_t {
 char payload_type[10]; /*<  Payload Type*/
 uint8_t action; /*<  Action*/
}) mavlink_do_payload_action_t;

#define MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN 11
#define MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_MIN_LEN 11
#define MAVLINK_MSG_ID_45005_LEN 11
#define MAVLINK_MSG_ID_45005_MIN_LEN 11

#define MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_CRC 66
#define MAVLINK_MSG_ID_45005_CRC 66

#define MAVLINK_MSG_DO_PAYLOAD_ACTION_FIELD_PAYLOAD_TYPE_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DO_PAYLOAD_ACTION { \
    45005, \
    "DO_PAYLOAD_ACTION", \
    2, \
    {  { "payload_type", NULL, MAVLINK_TYPE_CHAR, 10, 0, offsetof(mavlink_do_payload_action_t, payload_type) }, \
         { "action", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_do_payload_action_t, action) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DO_PAYLOAD_ACTION { \
    "DO_PAYLOAD_ACTION", \
    2, \
    {  { "payload_type", NULL, MAVLINK_TYPE_CHAR, 10, 0, offsetof(mavlink_do_payload_action_t, payload_type) }, \
         { "action", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_do_payload_action_t, action) }, \
         } \
}
#endif

/**
 * @brief Pack a do_payload_action message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param payload_type  Payload Type
 * @param action  Action
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_do_payload_action_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *payload_type, uint8_t action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN];
    _mav_put_uint8_t(buf, 10, action);
    _mav_put_char_array(buf, 0, payload_type, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN);
#else
    mavlink_do_payload_action_t packet;
    packet.action = action;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DO_PAYLOAD_ACTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_MIN_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_CRC);
}

/**
 * @brief Pack a do_payload_action message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param payload_type  Payload Type
 * @param action  Action
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_do_payload_action_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *payload_type,uint8_t action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN];
    _mav_put_uint8_t(buf, 10, action);
    _mav_put_char_array(buf, 0, payload_type, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN);
#else
    mavlink_do_payload_action_t packet;
    packet.action = action;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DO_PAYLOAD_ACTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_MIN_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_CRC);
}

/**
 * @brief Encode a do_payload_action struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param do_payload_action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_do_payload_action_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_do_payload_action_t* do_payload_action)
{
    return mavlink_msg_do_payload_action_pack(system_id, component_id, msg, do_payload_action->payload_type, do_payload_action->action);
}

/**
 * @brief Encode a do_payload_action struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param do_payload_action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_do_payload_action_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_do_payload_action_t* do_payload_action)
{
    return mavlink_msg_do_payload_action_pack_chan(system_id, component_id, chan, msg, do_payload_action->payload_type, do_payload_action->action);
}

/**
 * @brief Send a do_payload_action message
 * @param chan MAVLink channel to send the message
 *
 * @param payload_type  Payload Type
 * @param action  Action
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_do_payload_action_send(mavlink_channel_t chan, const char *payload_type, uint8_t action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN];
    _mav_put_uint8_t(buf, 10, action);
    _mav_put_char_array(buf, 0, payload_type, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION, buf, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_MIN_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_CRC);
#else
    mavlink_do_payload_action_t packet;
    packet.action = action;
    mav_array_memcpy(packet.payload_type, payload_type, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION, (const char *)&packet, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_MIN_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_CRC);
#endif
}

/**
 * @brief Send a do_payload_action message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_do_payload_action_send_struct(mavlink_channel_t chan, const mavlink_do_payload_action_t* do_payload_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_do_payload_action_send(chan, do_payload_action->payload_type, do_payload_action->action);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION, (const char *)do_payload_action, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_MIN_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_do_payload_action_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *payload_type, uint8_t action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 10, action);
    _mav_put_char_array(buf, 0, payload_type, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION, buf, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_MIN_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_CRC);
#else
    mavlink_do_payload_action_t *packet = (mavlink_do_payload_action_t *)msgbuf;
    packet->action = action;
    mav_array_memcpy(packet->payload_type, payload_type, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION, (const char *)packet, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_MIN_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_CRC);
#endif
}
#endif

#endif

// MESSAGE DO_PAYLOAD_ACTION UNPACKING


/**
 * @brief Get field payload_type from do_payload_action message
 *
 * @return  Payload Type
 */
static inline uint16_t mavlink_msg_do_payload_action_get_payload_type(const mavlink_message_t* msg, char *payload_type)
{
    return _MAV_RETURN_char_array(msg, payload_type, 10,  0);
}

/**
 * @brief Get field action from do_payload_action message
 *
 * @return  Action
 */
static inline uint8_t mavlink_msg_do_payload_action_get_action(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Decode a do_payload_action message into a struct
 *
 * @param msg The message to decode
 * @param do_payload_action C-struct to decode the message contents into
 */
static inline void mavlink_msg_do_payload_action_decode(const mavlink_message_t* msg, mavlink_do_payload_action_t* do_payload_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_do_payload_action_get_payload_type(msg, do_payload_action->payload_type);
    do_payload_action->action = mavlink_msg_do_payload_action_get_action(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN? msg->len : MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN;
        memset(do_payload_action, 0, MAVLINK_MSG_ID_DO_PAYLOAD_ACTION_LEN);
    memcpy(do_payload_action, _MAV_PAYLOAD(msg), len);
#endif
}
