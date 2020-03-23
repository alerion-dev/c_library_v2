#pragma once
// MESSAGE PAYLOAD_ACTION_DONE PACKING

#define MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE 45018

MAVPACKED(
typedef struct __mavlink_payload_action_done_t {
 int32_t result; /*<  Inline result*/
 uint8_t target_system; /*<  Drone System ID*/
 uint8_t target_component; /*<  Payload computer Component ID*/
 uint8_t payload_id; /*<  Payload ID*/
 uint8_t action; /*<  Action*/
 uint8_t error; /*<  Error*/
}) mavlink_payload_action_done_t;

#define MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN 9
#define MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN 9
#define MAVLINK_MSG_ID_45018_LEN 9
#define MAVLINK_MSG_ID_45018_MIN_LEN 9

#define MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC 130
#define MAVLINK_MSG_ID_45018_CRC 130



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PAYLOAD_ACTION_DONE { \
    45018, \
    "PAYLOAD_ACTION_DONE", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_payload_action_done_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_payload_action_done_t, target_component) }, \
         { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_payload_action_done_t, payload_id) }, \
         { "action", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_payload_action_done_t, action) }, \
         { "error", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_payload_action_done_t, error) }, \
         { "result", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_payload_action_done_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PAYLOAD_ACTION_DONE { \
    "PAYLOAD_ACTION_DONE", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_payload_action_done_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_payload_action_done_t, target_component) }, \
         { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_payload_action_done_t, payload_id) }, \
         { "action", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_payload_action_done_t, action) }, \
         { "error", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_payload_action_done_t, error) }, \
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
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 * @param action  Action
 * @param error  Error
 * @param result  Inline result
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_payload_action_done_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t payload_id, uint8_t action, uint8_t error, int32_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN];
    _mav_put_int32_t(buf, 0, result);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_uint8_t(buf, 6, payload_id);
    _mav_put_uint8_t(buf, 7, action);
    _mav_put_uint8_t(buf, 8, error);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN);
#else
    mavlink_payload_action_done_t packet;
    packet.result = result;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    packet.action = action;
    packet.error = error;

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
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 * @param action  Action
 * @param error  Error
 * @param result  Inline result
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_payload_action_done_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t payload_id,uint8_t action,uint8_t error,int32_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN];
    _mav_put_int32_t(buf, 0, result);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_uint8_t(buf, 6, payload_id);
    _mav_put_uint8_t(buf, 7, action);
    _mav_put_uint8_t(buf, 8, error);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN);
#else
    mavlink_payload_action_done_t packet;
    packet.result = result;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    packet.action = action;
    packet.error = error;

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
    return mavlink_msg_payload_action_done_pack(system_id, component_id, msg, payload_action_done->target_system, payload_action_done->target_component, payload_action_done->payload_id, payload_action_done->action, payload_action_done->error, payload_action_done->result);
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
    return mavlink_msg_payload_action_done_pack_chan(system_id, component_id, chan, msg, payload_action_done->target_system, payload_action_done->target_component, payload_action_done->payload_id, payload_action_done->action, payload_action_done->error, payload_action_done->result);
}

/**
 * @brief Send a payload_action_done message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 * @param action  Action
 * @param error  Error
 * @param result  Inline result
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_payload_action_done_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t payload_id, uint8_t action, uint8_t error, int32_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN];
    _mav_put_int32_t(buf, 0, result);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_uint8_t(buf, 6, payload_id);
    _mav_put_uint8_t(buf, 7, action);
    _mav_put_uint8_t(buf, 8, error);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE, buf, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
#else
    mavlink_payload_action_done_t packet;
    packet.result = result;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    packet.action = action;
    packet.error = error;

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
    mavlink_msg_payload_action_done_send(chan, payload_action_done->target_system, payload_action_done->target_component, payload_action_done->payload_id, payload_action_done->action, payload_action_done->error, payload_action_done->result);
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
static inline void mavlink_msg_payload_action_done_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t payload_id, uint8_t action, uint8_t error, int32_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, result);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_uint8_t(buf, 6, payload_id);
    _mav_put_uint8_t(buf, 7, action);
    _mav_put_uint8_t(buf, 8, error);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE, buf, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
#else
    mavlink_payload_action_done_t *packet = (mavlink_payload_action_done_t *)msgbuf;
    packet->result = result;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->payload_id = payload_id;
    packet->action = action;
    packet->error = error;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE, (const char *)packet, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_CRC);
#endif
}
#endif

#endif

// MESSAGE PAYLOAD_ACTION_DONE UNPACKING


/**
 * @brief Get field target_system from payload_action_done message
 *
 * @return  Drone System ID
 */
static inline uint8_t mavlink_msg_payload_action_done_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field target_component from payload_action_done message
 *
 * @return  Payload computer Component ID
 */
static inline uint8_t mavlink_msg_payload_action_done_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field payload_id from payload_action_done message
 *
 * @return  Payload ID
 */
static inline uint8_t mavlink_msg_payload_action_done_get_payload_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field action from payload_action_done message
 *
 * @return  Action
 */
static inline uint8_t mavlink_msg_payload_action_done_get_action(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field error from payload_action_done message
 *
 * @return  Error
 */
static inline uint8_t mavlink_msg_payload_action_done_get_error(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
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
    payload_action_done->target_system = mavlink_msg_payload_action_done_get_target_system(msg);
    payload_action_done->target_component = mavlink_msg_payload_action_done_get_target_component(msg);
    payload_action_done->payload_id = mavlink_msg_payload_action_done_get_payload_id(msg);
    payload_action_done->action = mavlink_msg_payload_action_done_get_action(msg);
    payload_action_done->error = mavlink_msg_payload_action_done_get_error(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN? msg->len : MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN;
        memset(payload_action_done, 0, MAVLINK_MSG_ID_PAYLOAD_ACTION_DONE_LEN);
    memcpy(payload_action_done, _MAV_PAYLOAD(msg), len);
#endif
}
