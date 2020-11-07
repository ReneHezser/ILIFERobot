#ifndef __http_H__
#define __http_H__

#include <Arduino.h>
#include <Structs.h>
#include <ILIFERobot.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <htmlindex.h>

void processCmdRequest();
void returnFail(String msg);
void setupHTTP();

extern const char *update_path, *update_username, *update_password;

extern WiFiClient espClient;
extern ESP8266WebServer server;
extern ESP8266HTTPUpdateServer httpUpdater;

#endif