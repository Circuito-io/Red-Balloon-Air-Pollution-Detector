// Include Libraries
#include "Arduino.h"
#include "MQ7.h"
#include "RGBLed.h"


// Pin Definitions
#define MQ7_PIN_B1	A3
#define RGBLedAnode_PIN_R	9
#define RGBLedAnode_PIN_G	6
#define RGBLedAnode_PIN_B	5



// Global variables and defines

// object initialization
MQ7 mq7(MQ7_PIN_B1);
RGBLed rgbLed(RGBLedAnode_PIN_R, RGBLedAnode_PIN_G, RGBLedAnode_PIN_B);



// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup()
{
  // Setup Serial which is useful for debugging
  // Use the Serial Monitor to view printed messages
  Serial.begin(9600);
  while (!Serial) ; // wait for serial port to connect. Needed for native USB
  Serial.println("start");

  rgbLed.turnOff();              // Start with RGB LED turned off
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop()
{
  //read CO levels from MQ-7 (please note that the MQ-7 requires few minutes of pre-heating)
  int mq7Val = mq7.read();
  mq7Val = map(mq7Val, 40, 120, 0, 255);
  Serial.print(F("raw: ")); Serial.println(mq7.read());
  Serial.print(F("val: ")); Serial.println(mq7Val);

  // Change the rgb colors with an interval of 100ms
  rgbLed.setRGB(255 - mq7Val, mq7Val, 0);
  delay(100);

}


/*******************************************************

     Circuito.io is an automatic generator of schematics and code for off
     the shelf hardware combinations.

     Copyright (C) 2016 Roboplan Technologies Ltd.

     This program is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation, either version 3 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.

     In addition, and without limitation, to the disclaimers of warranties
     stated above and in the GNU General Public License version 3 (or any
     later version), Roboplan Technologies Ltd. ("Roboplan") offers this
     program subject to the following warranty disclaimers and by using
     this program you acknowledge and agree to the following:
     THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND
     WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN
     HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT
     NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS
     FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY
     STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE.
     YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
     ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT
     SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES
     NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO
     SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE
     FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT
     VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
     RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN.
     YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN,
     ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF
     THE ABOVE.
********************************************************/
