#include "font8x8_basic.h"

int LED[8][8];
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15};

void setup() {
  for (int i = 0; i < 54; i ++) {
    pinMode(i, OUTPUT);
  }
  for (int i = 0; i < 16; i++) {
    pinMode(analog_pins[i], OUTPUT);
  }

  int counter1 = 0;
  int counter2 = 0;
  for (int i = 0; i < 8; i ++) {
    for (int j = 0; j < 8; j ++) {
      if(counter1 < 54) {
        LED[j][i] = counter1;
        counter1++;
      }
      else {
        LED[j][i] = analog_pins[counter2];
        counter2++;
      }
    }
  }

//  Serial.begin(9600);

}

void loop() {
  topToBottom();
  delay(1000);
  snake();
  delay(1000);
  randomLED();
  delay(1000);
  rainDrop();
  delay(1000);
//  message("HELLO");
//  delay(1000);
  flashThroughLayers("Hello");
  delay(1000);
}

void flashThroughLayers(String s) {
  byte bmp[8];
  int temp[8][8];
  int tmp[8][8];
  for (int i = 0; i < s.length(); i ++) {
    for (int k = 7; k >= 0; k -= 1) {
      if (k == 0) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, LOW);
        digitalWrite(A15, LOW);
      }
      else if (k == 1) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, LOW);
        digitalWrite(A15, LOW);
      }
      else if (k == 2){
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, LOW);
      }
      else if (k == 3) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, LOW);
      }
      else if (k == 4) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
      }
      else if (k == 5) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
      }
      else if (k == 6) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, HIGH);
      }
      else if (k == 7) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, HIGH);
      }
      int printchar = s.charAt(i);
      //Serial.print(printchar);
      //Serial.println("hi");
      if (printchar > 127 || printchar < 0) {
          break;
      }
      else {
        for (int i = 0; i < 8; i += 1) {
          bmp[i] = font8x8_basic[printchar][i];
          //Serial.println(bmp[i]);
        }
        for (int i = 0; i < 8; i += 1) {
          for (int j = 0; j < 8; j += 1) {
            temp[i][j] = bitRead(bmp[i], j);
          }
        }
        for (int i = 0; i < 8; i += 1) {
          for (int j = 0; j < 8; j += 1) {
            tmp[i][j] = temp[7-i][j];
          }
        }
        for (int i = 0; i < 8; i += 1) {
          for (int j = 0; j < 8; j += 1) {
            if (tmp[i][j] == 1) {
              digitalWrite(LED[i][j], HIGH);
            }
          }
        }
      }
      delay(50);
    }
    delay(200);
    for (int i = 0; i < 8; i += 1) {
      for (int j = 0; j < 8; j += 1) {
        digitalWrite(LED[i][j], LOW);
        temp[i][j] = 0;
      }
    }
    delay(10);
  }
}


void message(String s) {
  byte bmp[8];
  int temp[8][8];
  int tmp[8][8];
  for (int i = 0; i < s.length(); i ++) {
    int printchar = s.charAt(i);
    //Serial.print(printchar);
    //Serial.println("hi");
    if (printchar > 127 || printchar < 0) {
        break;
    }
    else {
      for (int i = 0; i < 8; i += 1) {
        bmp[i] = font8x8_basic[printchar][i];
        //Serial.println(bmp[i]);
      }
      for (int i = 0; i < 8; i += 1) {
        for (int j = 0; j < 8; j += 1) {
          temp[i][j] = bitRead(bmp[i], j);
        }
      }
      for (int i = 0; i < 8; i += 1) {
        for (int j = 0; j < 8; j += 1) {
          tmp[i][j] = temp[7-i][j];
        }
      }
      for (int i = 0; i < 8; i += 1) {
        for (int j = 0; j < 8; j += 1) {
          if (tmp[i][j] == 1) {
            digitalWrite(LED[i][j], HIGH);
          }
          Serial.print(tmp[i][j]);
        }
        Serial.println(" ");
      }
//      for (int i = 0; i < 8; i += 1) {
//        for (int j = 0; j < 8; j += 1) {
//          if (temp[i][j] == 1) {
//            digitalWrite(LED[i][j], HIGH);
//          }
//          //Serial.print(temp[i][j]);
//        }
//        //Serial.println(" ");
//      }
    }
    delay(500);
    for (int i = 0; i < 8; i += 1) {
      for (int j = 0; j < 8; j += 1) {
        digitalWrite(LED[i][j], LOW);
        temp[i][j] = 0;
      }
    }
  }
}

void rainDrop() {
  for (int l = 0; l < 20; l += 1) {
    int col = random(0,7);
    int row = random(0,7);
    for (int k = 0; k < 8; k += 1) {
      if (k == 0) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, LOW);
        digitalWrite(A15, LOW);
      }
      else if (k == 1) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, LOW);
        digitalWrite(A15, LOW);
      }
      else if (k == 2){
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, LOW);
      }
      else if (k == 3) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, LOW);
      }
      else if (k == 4) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
      }
      else if (k == 5) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
      }
      else if (k == 6) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, HIGH);
      }
      else if (k == 7) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, HIGH);
      }
      digitalWrite(LED[row][col], HIGH);
      delay(20);
      digitalWrite(LED[row][col], LOW);
    }
    delay(50);
  }
}

void randomLED() {
  for (int l = 0; l < 30; l += 1) {
    int col = random(0,7);
    int row = random(0,7);
    int layer = random(0,7);
    if (layer == 0) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, LOW);
        digitalWrite(A15, LOW);
      }
      else if (layer == 1) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, LOW);
        digitalWrite(A15, LOW);
      }
      else if (layer == 2){
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, LOW);
      }
      else if (layer == 3) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, LOW);
      }
      else if (layer == 4) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
      }
      else if (layer == 5) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
      }
      else if (layer == 6) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, HIGH);
      }
      else if (layer == 7) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, HIGH);
      }
      digitalWrite(LED[row][col], HIGH);
      delay(50);
      digitalWrite(LED[row][col], LOW);
      delay(10);
  }
}

void snake() {
  for (int k = 0; k < 8; k += 1) {
    if (k == 0) {
      digitalWrite(A13, LOW);
      digitalWrite(A14, LOW);
      digitalWrite(A15, LOW);
    }
    else if (k == 1) {
      digitalWrite(A13, HIGH);
      digitalWrite(A14, LOW);
      digitalWrite(A15, LOW);
    }
    else if (k == 2){
      digitalWrite(A13, LOW);
      digitalWrite(A14, HIGH);
      digitalWrite(A15, LOW);
    }
    else if (k == 3) {
      digitalWrite(A13, HIGH);
      digitalWrite(A14, HIGH);
      digitalWrite(A15, LOW);
    }
    else if (k == 4) {
      digitalWrite(A13, LOW);
      digitalWrite(A14, LOW);
      digitalWrite(A15, HIGH);
    }
    else if (k == 5) {
      digitalWrite(A13, HIGH);
      digitalWrite(A14, LOW);
      digitalWrite(A15, HIGH);
    }
    else if (k == 6) {
      digitalWrite(A13, LOW);
      digitalWrite(A14, HIGH);
      digitalWrite(A15, HIGH);
    }
    else if (k == 7) {
      digitalWrite(A13, HIGH);
      digitalWrite(A14, HIGH);
      digitalWrite(A15, HIGH);
    }
    for (int i = 0; i < 8; i += 1) {
      for (int j = 0; j < 8; j += 1) {
        digitalWrite(LED[j][i], HIGH);
        delay(10);
      }
    }
    delay(10);
    for (int i = 0; i < 8; i += 1) {
      for (int j = 0; j < 8; j += 1) {
        digitalWrite(LED[j][i], LOW);
        delay(10);
      }
    }
  }
}

void topToBottom() {
  for (int l = 0; l < 20; l +=1) {
    for (int k = 0; k < 8; k += 1) {
      if (k == 0) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, LOW);
        digitalWrite(A15, LOW);
      }
      else if (k == 1) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, LOW);
        digitalWrite(A15, LOW);
      }
      else if (k == 2){
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, LOW);
      }
      else if (k == 3) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, LOW);
      }
      else if (k == 4) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
      }
      else if (k == 5) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
      }
      else if (k == 6) {
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, HIGH);
      }
      else if (k == 7) {
        digitalWrite(A13, HIGH);
        digitalWrite(A14, HIGH);
        digitalWrite(A15, HIGH);
      }
      for (int i = 0; i < 8; i += 1) {
        for (int j = 0; j < 8; j += 1) {
          digitalWrite(LED[j][i], HIGH);
        }
      }
      delay(50);
      for (int i = 0; i < 8; i += 1) {
        for (int j = 0; j < 8; j += 1) {
          digitalWrite(LED[j][i], LOW);
        }
      }
      //delay(7);
    }
  }
}
