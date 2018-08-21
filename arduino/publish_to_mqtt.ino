#include <BridgeClient.h>
#include <PubSubClient.h>

const char* broker = "10.10.32.169";
const int port = 1883;
const char* clientId = "change-me";
const char* topic = "a/b/c/d";

BridgeClient bridgeClient;
PubSubClient pubSubClient;

void setup() {
    Bridge.begin();
    
    pubSubClient.setClient(bridgeClient);
    pubSubClient.setServer(broker, port);
}

void loop() {
    pubSubClient.loop();

    char* payload = "payload";

    pubSubClient.connect(clientId);
    pubSubClient.publish(topic, payload);
    pubSubClient.disconnect();
}
