#include <IRremote.h>

int RECV_PIN = 11; //define input pin on Arduino
IRrecv irrecv(RECV_PIN);
decode_results results;

const char* irrecvToString (int code) {
    switch(code) {
    case 0xFDB04F: return "0"; break;
    case 0xFD00FF: return "1"; break;
    case 0xFD807F: return "2"; break;
    case 0xFD40BF: return "3"; break;
    case 0xFD20DF: return "4"; break;
    case 0xFDA05F: return "5"; break;
    case 0xFD609F: return "6"; break;
    case 0xFD10EF: return "7"; break;
    case 0xFD906F: return "8"; break;
    case 0xFD50AF: return "9"; break;

    case 0xFD30CF: return "*"; break;
    case 0xFD708F: return "#"; break;

    case 0xFD8877: return "UP"; break;
    case 0xFD6897: return "RIGHT"; break;
    case 0xFD9867: return "DOWN"; break;
    case 0xFD28D7: return "LEFT"; break;
    case 0xFDA857: return "OK"; break;

    case 0xFFFFFFFF: return "BUTTON_HOLD"; break;

    default: return "UNKNOWN";
    }
}

void setup () {
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
}

void loop () {
    if (irrecv.decode(&results)) {
        Serial.println(irrecvToString(results.value));
        irrecv.resume(); // Receive the next value
    }
}
