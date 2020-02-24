#pragma once
// MESSAGE HYDRADRONE_STATUS PACKING

#define MAVLINK_MSG_ID_HYDRADRONE_STATUS 45001

MAVPACKED(
typedef struct __mavlink_hydradrone_status_t {
 uint8_t status; /*<  Hydradrone Status*/
}) mavlink_hydradrone_status_t;

#define MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN 1
#define MAVLINK_MSG_ID_HYDRADRONE_STATUS_MIN_LEN 1
#define MAVLINK_MSG_ID_45001_LEN 1
#define MAVLINK_MSG_ID_45001_MIN_LEN 1

#define MAVLINK_MSG_ID_HYDRADRONE_STATUS_CRC 90
#define MAVLINK_MSG_ID_45001_CRC 90



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HYDRADRONE_STATUS { \
    45001, \
    "HYDRADRONE_STATUS", \
    1, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_hydradrone_status_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HYDRADRONE_STATUS { \
    "HYDRADRONE_STATUS", \
    1, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_hydradrone_status_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a hydradrone_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param status  Hydradrone Status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hydradrone_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN);
#else
    mavlink_hydradrone_status_t packet;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HYDRADRONE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HYDRADRONE_STATUS_MIN_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_CRC);
}

/**
 * @brief Pack a hydradrone_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param status  Hydradrone Status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hydradrone_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN);
#else
    mavlink_hydradrone_status_t packet;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HYDRADRONE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HYDRADRONE_STATUS_MIN_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_CRC);
}

/**
 * @brief Encode a hydradrone_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hydradrone_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hydradrone_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hydradrone_status_t* hydradrone_status)
{
    return mavlink_msg_hydradrone_status_pack(system_id, component_id, msg, hydradrone_status->status);
}

/**
 * @brief Encode a hydradrone_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hydradrone_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hydradrone_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hydradrone_status_t* hydradrone_status)
{
    return mavlink_msg_hydradrone_status_pack_chan(system_id, component_id, chan, msg, hydradrone_status->status);
}

/**
 * @brief Send a hydradrone_status message
 * @param chan MAVLink channel to send the message
 *
 * @param status  Hydradrone Status
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hydradrone_status_send(mavlink_channel_t chan, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HYDRADRONE_STATUS, buf, MAVLINK_MSG_ID_HYDRADRONE_STATUS_MIN_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_CRC);
#else
    mavlink_hydradrone_status_t packet;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HYDRADRONE_STATUS, (const char *)&packet, MAVLINK_MSG_ID_HYDRADRONE_STATUS_MIN_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_CRC);
#endif
}

/**
 * @brief Send a hydradrone_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_hydradrone_status_send_struct(mavlink_channel_t chan, const mavlink_hydradrone_status_t* hydradrone_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_hydradrone_status_send(chan, hydradrone_status->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HYDRADRONE_STATUS, (const char *)hydradrone_status, MAVLINK_MSG_ID_HYDRADRONE_STATUS_MIN_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_hydradrone_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HYDRADRONE_STATUS, buf, MAVLINK_MSG_ID_HYDRADRONE_STATUS_MIN_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_CRC);
#else
    mavlink_hydradrone_status_t *packet = (mavlink_hydradrone_status_t *)msgbuf;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HYDRADRONE_STATUS, (const char *)packet, MAVLINK_MSG_ID_HYDRADRONE_STATUS_MIN_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN, MAVLINK_MSG_ID_HYDRADRONE_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE HYDRADRONE_STATUS UNPACKING


/**
 * @brief Get field status from hydradrone_status message
 *
 * @return  Hydradrone Status
 */
static inline uint8_t mavlink_msg_hydradrone_status_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a hydradrone_status message into a struct
 *
 * @param msg The message to decode
 * @param hydradrone_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_hydradrone_status_decode(const mavlink_message_t* msg, mavlink_hydradrone_status_t* hydradrone_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    hydradrone_status->status = mavlink_msg_hydradrone_status_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN? msg->len : MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN;
        memset(hydradrone_status, 0, MAVLINK_MSG_ID_HYDRADRONE_STATUS_LEN);
    memcpy(hydradrone_status, _MAV_PAYLOAD(msg), len);
#endif
}
