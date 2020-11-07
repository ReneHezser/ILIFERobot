#include <http.h>

const char* update_path = "/firmware";
const char* update_username = "admin";
const char* update_password = "admin";
WiFiClient espClient;
ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

void processCmdRequest() {
  if(!server.hasArg("c")) return returnFail("BAD ARGS");
  String cmd = server.arg("c");

  int robotCmd = findValidRobotCmd(cmd.c_str());

  if(robotCmd != -1) {
    IRbutton irbutton = buttonCmds[robotCmd];
    Serial.print("[HTTP] Got valid robot command: ");
    Serial.println(irbutton.name);
    
    server.send(200, "text/plain", "Robot "+String(irbutton.name));

    SendIRCode(irbutton);
  }
  else {
    returnFail("INVALID COMMAND");
  }
  
}

void returnFail(String msg) {
  server.send(200, "text/plain", msg);
}

void setupHTTP() {
//  MDNS.begin(mDNSname);
  
  httpUpdater.setup(&server, update_path, update_username, update_password);
  server.begin();

//  MDNS.addService("http", "tcp", 80);
  Serial.printf("[HTTP] HTTPUpdateServer ready! Open http://%s%s in your browser and login with username '%s' and password '%s'\n", WiFi.localIP().toString().c_str(), update_path, update_username, update_password);
  Serial.println("");
  
  server.on("/", [](){
    server.send_P(200, "text/html", PAGE_index);
  });
  
  server.on("/cmd", HTTP_GET, processCmdRequest);
}