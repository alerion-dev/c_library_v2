#pragma once
// MESSAGE REQUEST_PAYLOAD_PARAMETERS PACKING

#define MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS 45050

MAVPACKED(
typedef struct __mavlink_request_payload_parameters_t {
 uint8_t target_system; /*<  Drone System ID*/
 uint8_t target_component; /*<  Payload computer Component ID*/
 uint8_t payload_id; /*<  Payload ID*/
}) mavlink_request_payload_parameters_t;

#define MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN 3
#define MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_MIN_LEN 3
#define MAVLINK_MSG_ID_45050_LEN 3
#define MAVLINK_MSG_ID_45050_MIN_LEN 3

#define MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_CRC 114
#define MAVLINK_MSG_ID_45050_CRC 114



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_REQUEST_PAYLOAD_PARAMETERS { \
    45050, \
    "REQUEST_PAYLOAD_PARAMETERS", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_request_payload_parameters_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_request_payload_parameters_t, target_component) }, \
         { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_request_payload_parameters_t, payload_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_REQUEST_PAYLOAD_PARAMETERS { \
    "REQUEST_PAYLOAD_PARAMETERS", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_request_payload_parameters_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_request_payload_parameters_t, target_component) }, \
         { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_request_payload_parameters_t, payload_id) }, \
         } \
}
#endif

/**
 * @brief Pack a request_payload_parameters message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_payload_parameters_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, payload_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN);
#else
    mavlink_request_payload_parameters_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_MIN_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_CRC);
}

/**
 * @brief Pack a request_payload_parameters message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_payload_parameters_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, payload_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN);
#else
    mavlink_request_payload_parameters_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_MIN_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_CRC);
}

/**
 * @brief Encode a request_payload_parameters struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param request_payload_parameters C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_payload_parameters_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_request_payload_parameters_t* request_payload_parameters)
{
    return mavlink_msg_request_payload_parameters_pack(system_id, component_id, msg, request_payload_parameters->target_system, request_payload_parameters->target_component, request_payload_parameters->payload_id);
}

/**
 * @brief Encode a request_payload_parameters struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_payload_parameters C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_payload_parameters_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_request_payload_parameters_t* request_payload_parameters)
{
    return mavlink_msg_request_payload_parameters_pack_chan(system_id, component_id, chan, msg, request_payload_parameters->target_system, request_payload_parameters->target_component, request_payload_parameters->payload_id);
}

/**
 * @brief Send a request_payload_parameters message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_id  Payload ID
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_request_payload_parameters_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, payload_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS, buf, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_MIN_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_CRC);
#else
    mavlink_request_payload_parameters_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS, (const char *)&packet, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_MIN_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_CRC);
#endif
}

/**
 * @brief Send a request_payload_parameters message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_request_payload_parameters_send_struct(mavlink_channel_t chan, const mavlink_request_payload_parameters_t* request_payload_parameters)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_request_payload_parameters_send(chan, request_payload_parameters->target_system, request_payload_parameters->target_component, request_payload_parameters->payload_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS, (const char *)request_payload_parameters, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_MIN_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_CRC);
#endif
}

#if MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_request_payload_parameters_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, payload_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS, buf, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_MIN_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_CRC);
#else
    mavlink_request_payload_parameters_t *packet = (mavlink_request_payload_parameters_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->payload_id = payload_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS, (const char *)packet, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_MIN_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_CRC);
#endif
}
#endif

#endif

// MESSAGE REQUEST_PAYLOAD_PARAMETERS UNPACKING


/**
 * @brief Get field target_system from request_payload_parameters message
 *
 * @return  Drone System ID
 */
static inline uint8_t mavlink_msg_request_payload_parameters_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from request_payload_parameters message
 *
 * @return  Payload computer Component ID
 */
static inline uint8_t mavlink_msg_request_payload_parameters_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field payload_id from request_payload_parameters message
 *
 * @return  Payload ID
 */
static inline uint8_t mavlink_msg_request_payload_parameters_get_payload_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a request_payload_parameters message into a struct
 *
 * @param msg The message to decode
 * @param request_payload_parameters C-struct to decode the message contents into
 */
static inline void mavlink_msg_request_payload_parameters_decode(const mavlink_message_t* msg, mavlink_request_payload_parameters_t* request_payload_parameters)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    request_payload_parameters->target_system = mavlink_msg_request_payload_parameters_get_target_system(msg);
    request_payload_parameters->target_component = mavlink_msg_request_payload_parameters_get_target_component(msg);
    request_payload_parameters->payload_id = mavlink_msg_request_payload_parameters_get_payload_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN? msg->len : MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN;
        memset(request_payload_parameters, 0, MAVLINK_MSG_ID_REQUEST_PAYLOAD_PARAMETERS_LEN);
    memcpy(request_payload_parameters, _MAV_PAYLOAD(msg), len);
#endif
}
