#ifndef __mqtt_H__
#define __mqtt_H__

#include <Arduino.h>
#include <credentials.h>
#include <ILIFERobot.h>
#include <http.h>

#include <PubSubClient.h>

void callback(char *topic, byte *payload, unsigned int length);
void reconnect();

extern PubSubClient mqtt;
extern const char *mqtt_server, *inTopic, *outTopic, *outTopic_debug;

#endif