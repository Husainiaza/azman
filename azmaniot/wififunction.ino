void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);


  lcd.setCursor(0,1);
  lcd.print(" Connecting to ");
  lcd.print(ssid);


  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  lcd.setCursor(0,2);
  lcd.print("WiFi connected");
  lcd.setCursor(0,3);
  lcd.print(WiFi.localIP());
  delay(5000);
}


void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
 
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();


  //----------letakkan kawalan GPIO disini-----------------------------




  //----------end------------------------------------------------------
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    //----------Nama Client ID---------------------------------------------------
    if (client.connect("azmanclient01")) {
    //-------------------------------------------------------------
      Serial.println("connected");
     
      //-------------------subscribe topik anda disini --------------------
      client.subscribe("topic1");
      client.subscribe("topic2");
      //----------------------------end------------------------------------
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}