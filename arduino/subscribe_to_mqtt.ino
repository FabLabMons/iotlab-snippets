#include <BridgeClient.h>
#include <PubSubClient.h>

const char* broker = "10.10.32.169";
const int port = 1883;
const char* clientId = "change-me";
const char* topic = "a/b/c/d"

BridgeClient bridgeClient;
PubSubClient pubSubClient;

void setup() {
    pubSubClient.setClient(bridgeClient);
    pubSubClient.setServer(broker, port);
    pubSubClient.setCallback(onMessage);

    pubSubClient.connect(clientId);

    pubSubClient.subscribe(topic, 0);
}

void onMessage(char* topic, byte* payload, unsigned int length) {
    char content[50];
    strncpy(content, payload, length);
    content[length] = '\0';
}

void loop() {
    pubSubClient.loop();
}
