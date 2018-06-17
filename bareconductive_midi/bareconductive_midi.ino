/*******************************************************************************

 Bare Conductive Touch and Proximity USB MIDI interface
 ------------------------------------------------------
 
 Midi_interface_generic.ino - USB MIDI touch and proximity example

 Allows the mapping of each electrode to a key or control modulator in a 
 (relatively) simple manner. See the comments for details and experiment
 for best results.
 
 Remember to select Bare Conductive Touch Board (USB MIDI, iPad compatible) 
 in the Tools -> Board menu
 
 Bare Conductive code written by Stefan Dzisiewski-Smith.
 
 This work is licensed under a Creative Commons Attribution-ShareAlike 3.0 
 Unported License (CC BY-SA 3.0) http://creativecommons.org/licenses/by-sa/3.0/
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.

*******************************************************************************/

// compiler error handling
#include "Compiler_Errors.h"

#include <MPR121.h>
#include <Wire.h>
#include "Midi_object.h"

MIDIEvent e;

// Define variables

int mnote = 24; // middle C0
int tnote = 35; // touchThreshold
int rnote = 30; // releaseThreshold

//int mcontrol = 54; // midi control number
//int vmincontrol = 500; // input min value
//int vmaxcontrol = 400; // input max value

#define numElectrodes 12
midi_object_t MIDIobjects[numElectrodes]; // create an array of MIDI objects to use (one for each electrode)

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  MPR121.begin(0x5C);
  MPR121.setInterruptPin(4);

  // *************************
  // Proximity (CC) electrodes
  // *************************

  // set up electrode 0 as a proxmity mapped controller attached to controller declare before as "mcontrol"
//  MIDIobjects[0].type = MIDI_CONTROL;
//  MIDIobjects[0].controllerNumber = mcontrol; // 102..119 are undefined in the MIDI specification
//  MIDIobjects[0].inputMin = vmincontrol; 
//  MIDIobjects[0].inputMax = vmaxcontrol;  
//  MIDIobjects[0].outputMin = 0;   
//  MIDIobjects[0].outputMax = 127; 
//  
//  // set up electrode 1 as a proxmity mapped controller attached to controller before as "mcontrol+1"
//  MIDIobjects[1].type = MIDI_CONTROL;
//  MIDIobjects[1].controllerNumber = mnote+1; 
//  MIDIobjects[1].inputMin = vmincontrol;  
//  MIDIobjects[1].inputMax = vmaxcontrol;  
//  MIDIobjects[1].outputMin = 0;   
//  MIDIobjects[1].outputMax = 127; 
//
//  // set up electrode 2 as a proxmity mapped controller attached to controller before as "mcontrol+2"
//  MIDIobjects[2].type = MIDI_CONTROL;
//  MIDIobjects[2].controllerNumber = mnote+2; 
//  MIDIobjects[2].inputMin = vmincontrol;  
//  MIDIobjects[2].inputMax = vmaxcontrol;  
//  MIDIobjects[2].outputMin = 0;  
//  MIDIobjects[2].outputMax = 127; 
//
//  // set up electrode 3 as a proxmity mapped controller attached to controller before as "mcontrol+3"
//  MIDIobjects[3].type = MIDI_CONTROL;
//  MIDIobjects[3].controllerNumber = mnote+3; 
//  MIDIobjects[3].inputMin = vmincontrol;  
//  MIDIobjects[3].inputMax = vmaxcontrol;  
//  MIDIobjects[3].outputMin = 0;  
//  MIDIobjects[3].outputMax = 127; 
//
//  // set up electrode 4 as a proxmity mapped controller attached to controller before as "mcontrol+4"
//  MIDIobjects[4].type = MIDI_CONTROL;
//  MIDIobjects[4].controllerNumber = mnote+4;
//  MIDIobjects[4].inputMin = vmincontrol;  
//  MIDIobjects[4].inputMax = vmaxcontrol;  
//  MIDIobjects[4].outputMin = 0;   
//  MIDIobjects[4].outputMax = 127; 
//
//  // set up electrode 5 as a proxmity mapped controller attached to controller before as "mcontrol+5"
//  MIDIobjects[5].type = MIDI_CONTROL;
//  MIDIobjects[5].controllerNumber = mnote+5; 
//  MIDIobjects[5].inputMin = vmincontrol;  
//  MIDIobjects[5].inputMax = vmaxcontrol;  
//  MIDIobjects[5].outputMin = 0;  
//  MIDIobjects[5].outputMax = 127; 
//
//  // set up electrode 6 as a proxmity mapped controller attached to controller before as "mcontrol+6"
//  MIDIobjects[6].type = MIDI_CONTROL;
//  MIDIobjects[6].controllerNumber = mnote+6;
//  MIDIobjects[6].inputMin = vmincontrol;  
//  MIDIobjects[6].inputMax = vmaxcontrol;  
//  MIDIobjects[6].outputMin = 0;   
//  MIDIobjects[6].outputMax = 127; 
//  
//  // set up electrode 7 as a proxmity mapped controller attached to controller before as "mcontrol+7"
//  MIDIobjects[7].type = MIDI_CONTROL;
//  MIDIobjects[7].controllerNumber = mnote+7;
//  MIDIobjects[7].inputMin = vmincontrol; 
//  MIDIobjects[7].inputMax = vmaxcontrol;  
//  MIDIobjects[7].outputMin = 0;   
//  MIDIobjects[7].outputMax = 127; 
//  
//  // set up electrode 8 as a proxmity mapped controller attached to controller before as "mcontrol+8"
//  MIDIobjects[8].type = MIDI_CONTROL;
//  MIDIobjects[8].controllerNumber = mnote+8;
//  MIDIobjects[8].inputMin = vmincontrol; 
//  MIDIobjects[8].inputMax = vmaxcontrol;  
//  MIDIobjects[8].outputMin = 0;   
//  MIDIobjects[8].outputMax = 127; 
//  
//  // set up electrode 9 as a proxmity mapped controller attached to controller before as "mcontrol+9"
//  MIDIobjects[9].type = MIDI_CONTROL;
//  MIDIobjects[9].controllerNumber = mnote+9;
//  MIDIobjects[9].inputMin = vmincontrol; 
//  MIDIobjects[9].inputMax = vmaxcontrol;  
//  MIDIobjects[9].outputMin = 0;   
//  MIDIobjects[9].outputMax = 127; 
//  
//  // set up electrode 10 as a proxmity mapped controller attached to controller before as "mcontrol+10"
//  MIDIobjects[10].type = MIDI_CONTROL;
//  MIDIobjects[10].controllerNumber = mnote+10;
//  MIDIobjects[10].inputMin = vmincontrol; 
//  MIDIobjects[10].inputMax = vmaxcontrol; 
//  MIDIobjects[10].outputMin = 0;   
//  MIDIobjects[10].outputMax = 127; 
//
//  // set up electrode 11 as a proxmity mapped controller attached to controller before as "mcontrol+11"
//  MIDIobjects[11].type = MIDI_CONTROL;
//  MIDIobjects[11].controllerNumber = mnote+11;
//  MIDIobjects[11].inputMin = vmincontrol; 
//  MIDIobjects[11].inputMax = vmaxcontrol;  
//  MIDIobjects[11].outputMin = 0;   
//  MIDIobjects[11].outputMax = 127; 

// ***********************
  // Touch (note) electrodes
  // ***********************

  // If you want to configure the electrodes as note outputs (as opposed to proximity
  // CC) you need to do the following two things:
  //
  // 1. Uncomment the section below
  //
  // 2. Comment out the "Proximity (CC) electrodes" section above entirely. This makes sure
  //    that the two sections will not interfere with one another.
  //

  // You can also pick and choose between the two, for example having electrode 0 as a 
  // proximity electrode and electrode 1 as a touch electrode. You do this by:
  //
  // 1. Commenting out the lines relating to electrode 1 in the "Proximity (CC) electrodes" 
  //    section - that is the six lines beginning with "MIDIobjects[1]"
  //
  // 2. Uncommenting the lines relating to electrode 1 in the "Touch (note) electrodes"
  //    section - that is the 4 lines below that start with "MIDIobjects[1]"
  //
  // The important thing to remember is that you must not have two sections active for the 
  // same electrode.


  // // set up electrode 0 as a touch sensitive key attached to note declare before as "mnote"
   MIDIobjects[0].type = MIDI_NOTE;
   MIDIobjects[0].noteNumber = mnote;       // middle C0
   MIDIobjects[0].touchThreshold = tnote;   // always make sure that the touch threshold is
   MIDIobjects[0].releaseThreshold = rnote; // larger than the release threshold - larger values
                                         // are less sensitive (and more robust)
   
   // set up electrode 1 as a touch sensitive key attached to note declare before as "mnote+1"
   MIDIobjects[1].type = MIDI_NOTE;
   MIDIobjects[1].noteNumber = mnote+1;           
   MIDIobjects[1].touchThreshold = tnote;  
   MIDIobjects[1].releaseThreshold = rnote; 
  
   // set up electrode 2 as a touch sensitive key attached to note declare before as "mnote+2"
   MIDIobjects[2].type = MIDI_NOTE;
   MIDIobjects[2].noteNumber = mnote+2;           
   MIDIobjects[2].touchThreshold = tnote;  
   MIDIobjects[2].releaseThreshold = rnote; 
  
   // set up electrode 3 as a touch sensitive key attached to note declare before as "mnote+3"
   MIDIobjects[3].type = MIDI_NOTE;
   MIDIobjects[3].noteNumber = mnote+3;
   MIDIobjects[3].touchThreshold = tnote;  
   MIDIobjects[3].releaseThreshold = rnote; 
  
   // set up electrode 4 as a touch sensitive key attached to note declare before as "mnote+4"
   MIDIobjects[4].type = MIDI_NOTE;
   MIDIobjects[4].noteNumber = mnote+4;           
   MIDIobjects[4].touchThreshold = tnote;  
   MIDIobjects[4].releaseThreshold = rnote; 
  
   // set up electrode 5 as a touch sensitive key attached to note declare before as "mnote+5"
   MIDIobjects[5].type = MIDI_NOTE;
   MIDIobjects[5].noteNumber = mnote+5;
   MIDIobjects[5].touchThreshold = tnote;  
   MIDIobjects[5].releaseThreshold = rnote; 
  
   // set up electrode 6 as a touch sensitive key attached to note declare before as "mnote+6"
   MIDIobjects[6].type = MIDI_NOTE;
   MIDIobjects[6].noteNumber = mnote+6;
   MIDIobjects[6].touchThreshold = tnote;  
   MIDIobjects[6].releaseThreshold = rnote; 
  
   // set up electrode 7 as a touch sensitive key attached to note declare before as "mnote+7"
   MIDIobjects[7].type = MIDI_NOTE;
   MIDIobjects[7].noteNumber = mnote+7;
   MIDIobjects[7].touchThreshold = tnote;  
   MIDIobjects[7].releaseThreshold = rnote; 
  
   // set up electrode 8 as a touch sensitive key attached to note declare before as "mnote+8"
   MIDIobjects[8].type = MIDI_NOTE;
   MIDIobjects[8].noteNumber = mnote+8;
   MIDIobjects[8].touchThreshold = tnote;  
   MIDIobjects[8].releaseThreshold = rnote; 
  
   // set up electrode 9 as a touch sensitive key attached to note declare before as "mnote+9"
   MIDIobjects[9].type = MIDI_NOTE;
   MIDIobjects[9].noteNumber = mnote+9;
   MIDIobjects[9].touchThreshold = tnote;  
   MIDIobjects[9].releaseThreshold = rnote; 
  
   // set up electrode 10 as a touch sensitive key attached to note declare before as "mnote+10"
   MIDIobjects[10].type = MIDI_NOTE;
   MIDIobjects[10].noteNumber = mnote+10;
   MIDIobjects[10].touchThreshold = tnote;  
   MIDIobjects[10].releaseThreshold = rnote; 
  
   // set up electrode 11 as a touch sensitive key attached to note declare before as "mnote+11"
   MIDIobjects[11].type = MIDI_NOTE;
   MIDIobjects[11].noteNumber = mnote+11;
   MIDIobjects[11].touchThreshold = tnote;  
   MIDIobjects[11].releaseThreshold = rnote; 



  // set touch and release thresholds for electrodes that require it
  for(int i=0; i<numElectrodes; i++){
    if(MIDIobjects[i].type == MIDI_NOTE){
      MPR121.setTouchThreshold(i, MIDIobjects[i].touchThreshold);
      MPR121.setReleaseThreshold(i, MIDIobjects[i].releaseThreshold);
    }
  }     

  // start with fresh data
  MPR121.updateAll();
}

void loop() {
  // check note electrodes
  if(MPR121.touchStatusChanged()){
    MPR121.updateTouchData();
    for(int i=0; i<numElectrodes; i++){
      if(MIDIobjects[i].type==MIDI_NOTE){ // if this is a note type object...
        e.type = 0x08;
        e.m2 = MIDIobjects[i].noteNumber; // set note number
        e.m3 = 127;  // maximum volume
        if(MPR121.isNewTouch(i)){
          // if we have a new touch, turn on the onboard LED and
          // send a "note on" message with the appropriate note set
          digitalWrite(LED_BUILTIN, HIGH);
          e.m1 = 0x90; 
        } else if(MPR121.isNewRelease(i)){
          // if we have a new release, turn off the onboard LED and
          // send a "note off" message
          digitalWrite(LED_BUILTIN, LOW);
          e.m1 = 0x80;
        } else {
          // else set a flag to do nothing...
          e.m1 = 0x00;  
        }
        // only send a USB MIDI message if we need to
        if(e.m1 != 0x00){
          MIDIUSB.write(e);
        }
      }
    }
  }

  MPR121.updateFilteredData();

  // now check controller electrodes
  for(int i=0; i<numElectrodes; i++){
    if(MIDIobjects[i].type==MIDI_NOTE){ // if we have a control type object...
      Serial.print("E");
      Serial.print(i);
      Serial.print(":");                          // this prints some Serial debug data for ease of mapping
      Serial.println(MPR121.getFilteredData(i));  // e.g. E11:567 means E11 has value 567 (this is the input data)

      // output the correctly mapped value from the input
      e.m3 = (unsigned char)constrain(map(MPR121.getFilteredData(i), MIDIobjects[i].inputMin, MIDIobjects[i].inputMax, MIDIobjects[i].outputMin, MIDIobjects[i].outputMax), 0, 127);

      if(e.m3!=MIDIobjects[i].lastOutput){ // only output a new controller value if it has changed since last time

        MIDIobjects[i].lastOutput=e.m3;

        e.type = 0x08;
        e.m1 = 0xB0; // control change message
        e.m2 = MIDIobjects[i].controllerNumber;     // select the correct controller number - you should use numbers
                                                    // between 102 and 119 unless you know what you are doing
        MIDIUSB.write(e);
      }
    }
  }

  // flush USB buffer to ensure all notes are sent
  MIDIUSB.flush(); 

  delay(10); // 10ms delay to give the USB MIDI target time to catch up

}