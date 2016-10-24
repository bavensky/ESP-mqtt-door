extern int relay;

PubSubClient::callback_t on_message_arrived = 
[&](const MQTT::Publish & pub) -> void {
    String topic = pub.topic();
    String payload = pub.payload_string();
    String text = topic + " => " + payload;
    
    if(payload == "ON")  {
      digitalWrite(relay, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
    } else if(payload == "OFF") {
      digitalWrite(relay, LOW);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    Serial.println(payload);
 };
