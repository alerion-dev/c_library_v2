#pragma once
// MESSAGE ASSOCIATE_PAYLOAD_ID PACKING

#define MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID 45010

MAVPACKED(
typedef struct __mavlink_associate_payload_id_t {
 uint8_t target_system; /*<  Drone System ID*/
 uint8_t target_component; /*<  Payload computer Component ID*/
 char payload_name[13]; /*<  Payload name*/
 uint8_t payload_id; /*<  Payload ID assigned to this payload*/
}) mavlink_associate_payload_id_t;

#define MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN 16
#define MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_MIN_LEN 16
#define MAVLINK_MSG_ID_45010_LEN 16
#define MAVLINK_MSG_ID_45010_MIN_LEN 16

#define MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_CRC 196
#define MAVLINK_MSG_ID_45010_CRC 196

#define MAVLINK_MSG_ASSOCIATE_PAYLOAD_ID_FIELD_PAYLOAD_NAME_LEN 13

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ASSOCIATE_PAYLOAD_ID { \
    45010, \
    "ASSOCIATE_PAYLOAD_ID", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_associate_payload_id_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_associate_payload_id_t, target_component) }, \
         { "payload_name", NULL, MAVLINK_TYPE_CHAR, 13, 2, offsetof(mavlink_associate_payload_id_t, payload_name) }, \
         { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_associate_payload_id_t, payload_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ASSOCIATE_PAYLOAD_ID { \
    "ASSOCIATE_PAYLOAD_ID", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_associate_payload_id_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_associate_payload_id_t, target_component) }, \
         { "payload_name", NULL, MAVLINK_TYPE_CHAR, 13, 2, offsetof(mavlink_associate_payload_id_t, payload_name) }, \
         { "payload_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_associate_payload_id_t, payload_id) }, \
         } \
}
#endif

/**
 * @brief Pack a associate_payload_id message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_name  Payload name
 * @param payload_id  Payload ID assigned to this payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_associate_payload_id_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *payload_name, uint8_t payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 15, payload_id);
    _mav_put_char_array(buf, 2, payload_name, 13);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN);
#else
    mavlink_associate_payload_id_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    mav_array_memcpy(packet.payload_name, payload_name, sizeof(char)*13);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_MIN_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_CRC);
}

/**
 * @brief Pack a associate_payload_id message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_name  Payload name
 * @param payload_id  Payload ID assigned to this payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_associate_payload_id_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const char *payload_name,uint8_t payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 15, payload_id);
    _mav_put_char_array(buf, 2, payload_name, 13);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN);
#else
    mavlink_associate_payload_id_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    mav_array_memcpy(packet.payload_name, payload_name, sizeof(char)*13);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_MIN_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_CRC);
}

/**
 * @brief Encode a associate_payload_id struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param associate_payload_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_associate_payload_id_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_associate_payload_id_t* associate_payload_id)
{
    return mavlink_msg_associate_payload_id_pack(system_id, component_id, msg, associate_payload_id->target_system, associate_payload_id->target_component, associate_payload_id->payload_name, associate_payload_id->payload_id);
}

/**
 * @brief Encode a associate_payload_id struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param associate_payload_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_associate_payload_id_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_associate_payload_id_t* associate_payload_id)
{
    return mavlink_msg_associate_payload_id_pack_chan(system_id, component_id, chan, msg, associate_payload_id->target_system, associate_payload_id->target_component, associate_payload_id->payload_name, associate_payload_id->payload_id);
}

/**
 * @brief Send a associate_payload_id message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  Drone System ID
 * @param target_component  Payload computer Component ID
 * @param payload_name  Payload name
 * @param payload_id  Payload ID assigned to this payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_associate_payload_id_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const char *payload_name, uint8_t payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 15, payload_id);
    _mav_put_char_array(buf, 2, payload_name, 13);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID, buf, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_MIN_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_CRC);
#else
    mavlink_associate_payload_id_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.payload_id = payload_id;
    mav_array_memcpy(packet.payload_name, payload_name, sizeof(char)*13);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID, (const char *)&packet, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_MIN_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_CRC);
#endif
}

/**
 * @brief Send a associate_payload_id message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_associate_payload_id_send_struct(mavlink_channel_t chan, const mavlink_associate_payload_id_t* associate_payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_associate_payload_id_send(chan, associate_payload_id->target_system, associate_payload_id->target_component, associate_payload_id->payload_name, associate_payload_id->payload_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID, (const char *)associate_payload_id, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_MIN_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_CRC);
#endif
}

#if MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_associate_payload_id_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, const char *payload_name, uint8_t payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 15, payload_id);
    _mav_put_char_array(buf, 2, payload_name, 13);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID, buf, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_MIN_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_CRC);
#else
    mavlink_associate_payload_id_t *packet = (mavlink_associate_payload_id_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->payload_id = payload_id;
    mav_array_memcpy(packet->payload_name, payload_name, sizeof(char)*13);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID, (const char *)packet, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_MIN_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_CRC);
#endif
}
#endif

#endif

// MESSAGE ASSOCIATE_PAYLOAD_ID UNPACKING


/**
 * @brief Get field target_system from associate_payload_id message
 *
 * @return  Drone System ID
 */
static inline uint8_t mavlink_msg_associate_payload_id_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from associate_payload_id message
 *
 * @return  Payload computer Component ID
 */
static inline uint8_t mavlink_msg_associate_payload_id_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field payload_name from associate_payload_id message
 *
 * @return  Payload name
 */
static inline uint16_t mavlink_msg_associate_payload_id_get_payload_name(const mavlink_message_t* msg, char *payload_name)
{
    return _MAV_RETURN_char_array(msg, payload_name, 13,  2);
}

/**
 * @brief Get field payload_id from associate_payload_id message
 *
 * @return  Payload ID assigned to this payload
 */
static inline uint8_t mavlink_msg_associate_payload_id_get_payload_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Decode a associate_payload_id message into a struct
 *
 * @param msg The message to decode
 * @param associate_payload_id C-struct to decode the message contents into
 */
static inline void mavlink_msg_associate_payload_id_decode(const mavlink_message_t* msg, mavlink_associate_payload_id_t* associate_payload_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    associate_payload_id->target_system = mavlink_msg_associate_payload_id_get_target_system(msg);
    associate_payload_id->target_component = mavlink_msg_associate_payload_id_get_target_component(msg);
    mavlink_msg_associate_payload_id_get_payload_name(msg, associate_payload_id->payload_name);
    associate_payload_id->payload_id = mavlink_msg_associate_payload_id_get_payload_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN? msg->len : MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN;
        memset(associate_payload_id, 0, MAVLINK_MSG_ID_ASSOCIATE_PAYLOAD_ID_LEN);
    memcpy(associate_payload_id, _MAV_PAYLOAD(msg), len);
#endif
}
