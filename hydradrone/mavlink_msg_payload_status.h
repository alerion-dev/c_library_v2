#pragma once
// MESSAGE PAYLOAD_STATUS PACKING

#define MAVLINK_MSG_ID_PAYLOAD_STATUS 45014

MAVPACKED(
typedef struct __mavlink_payload_status_t {
 uint8_t payload_id; /*<  Payload ID*/
 uint8_t status; /*<  Payload status*/
}) mavlink_payload_status_t;

#define MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN 2
#define MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN 2
#define MAVLINK_MSG_ID_45014_LEN 2
#define MAVLINK_MSG_ID_45014_MIN_LEN 2

#define MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC 206
#define MAVLINK_MSG_ID_45014_CRC 206



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PAYLOAD_STATUS { \
    45014, \
    "PAYLOAD_STATUS", \
    2, \
    {  { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_payload_status_t, payload_id) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_payload_status_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PAYLOAD_STATUS { \
    "PAYLOAD_STATUS", \
    2, \
    {  { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_payload_status_t, payload_id) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_payload_status_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a payload_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param payload_id  Payload ID
 * @param status  Payload status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_payload_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t payload_id, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, payload_id);
    _mav_put_uint8_t(buf, 1, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
#else
    mavlink_payload_status_t packet;
    packet.payload_id = payload_id;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PAYLOAD_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
}

/**
 * @brief Pack a payload_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param payload_id  Payload ID
 * @param status  Payload status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_payload_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t payload_id,uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, payload_id);
    _mav_put_uint8_t(buf, 1, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
#else
    mavlink_payload_status_t packet;
    packet.payload_id = payload_id;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PAYLOAD_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
}

/**
 * @brief Encode a payload_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param payload_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_payload_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_payload_status_t* payload_status)
{
    return mavlink_msg_payload_status_pack(system_id, component_id, msg, payload_status->payload_id, payload_status->status);
}

/**
 * @brief Encode a payload_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param payload_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_payload_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_payload_status_t* payload_status)
{
    return mavlink_msg_payload_status_pack_chan(system_id, component_id, chan, msg, payload_status->payload_id, payload_status->status);
}

/**
 * @brief Send a payload_status message
 * @param chan MAVLink channel to send the message
 *
 * @param payload_id  Payload ID
 * @param status  Payload status
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_payload_status_send(mavlink_channel_t chan, uint8_t payload_id, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, payload_id);
    _mav_put_uint8_t(buf, 1, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, buf, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#else
    mavlink_payload_status_t packet;
    packet.payload_id = payload_id;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, (const char *)&packet, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#endif
}

/**
 * @brief Send a payload_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_payload_status_send_struct(mavlink_channel_t chan, const mavlink_payload_status_t* payload_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_payload_status_send(chan, payload_status->payload_id, payload_status->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, (const char *)payload_status, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_payload_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t payload_id, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, payload_id);
    _mav_put_uint8_t(buf, 1, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, buf, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#else
    mavlink_payload_status_t *packet = (mavlink_payload_status_t *)msgbuf;
    packet->payload_id = payload_id;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, (const char *)packet, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE PAYLOAD_STATUS UNPACKING


/**
 * @brief Get field payload_id from payload_status message
 *
 * @return  Payload ID
 */
static inline uint8_t mavlink_msg_payload_status_get_payload_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field status from payload_status message
 *
 * @return  Payload status
 */
static inline uint8_t mavlink_msg_payload_status_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a payload_status message into a struct
 *
 * @param msg The message to decode
 * @param payload_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_payload_status_decode(const mavlink_message_t* msg, mavlink_payload_status_t* payload_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    payload_status->payload_id = mavlink_msg_payload_status_get_payload_id(msg);
    payload_status->status = mavlink_msg_payload_status_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN? msg->len : MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN;
        memset(payload_status, 0, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
    memcpy(payload_status, _MAV_PAYLOAD(msg), len);
#endif
}
