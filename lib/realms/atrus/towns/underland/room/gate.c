#include <lib.h>
#include <domains.h>
#include "../underland.h"
inherit LIB_ROOM;

int GateStatus = 0;
int StatusCheck();
int SetGateStatus(int);
void ChangeGateStatus();

static void create() {
  ::create();
  SetShort("at the end of the path");
  SetExits( ([
    "west" : VALLEY_VIRTUAL "valley/10,10",
    ]) );
  AddExit("east", UNDER_ROOM "road01", (: StatusCheck :) );
  SetItems( ([
    ( { "valley", "path" } ) : (: GetLong :),
    ( { "mountain", "mount", "trogg" } ) : "Mount Trogg stands looming in the east. "
             "the peak is lost in a perpetual shroud of mist as thick as steam. "
             "The sides of the mountain are pristine white above the snow line. "
             "a continuous trickle of rivulettes feed the trees thousands of feet "
             "below. The splashing water falling down the cliffs stain dark the "
             "purple stone of the mountain, making it appear to bleed.",
    ( { "wall", "blocks", "stone", "stones", "block", "pointing" } ) : 
             "A grand and stout wall, just taller than an ogre would be, is "
             "crafted of heavy stone blocks. Each block would easily outweigh "
             "a dragon and are chisled from raw bassalt. The pointing between the "
             "stones would not fit a feather's edge.",
    ( { "tree", "trees", "wood", "woods" }) : 
             "Thousand of pine and aspen trees blanket the "
             "surrounding areas. They lead thickly off to the east past the gate. "
             "The slopes of Mount Trogg are clearly dotted with vast pines, fed "
             "from endless supplies of fresh snowmelt water from above.",
    ( { "gate", "windows" } ) : 
             "This heavy wooden gate is reinforced with iron. Intricately woven "
             "braces tie together man sized logs to form the structure of the gate. "
             "There is a small window not very far off the ground near each of the "
             "squared corners near the bottom of the door. They are closed from within. "
             "The door tapers at the top to a wide point.",
    ( { "cloud", "clouds", "mist", "swirls" } ) :
             "A thick swirling mass of clouds or mist seem to almost be placed with "
             "a purpose around the top of Mount Trogg off to the east. They eddy and "
             "undulate with the breeze, but seem to hang around the mountain resiliently.",
             
    ]) );
    
  SetItemAdjectives( ([
    "mount" : ({ "purple", "tall" }),
    "gate" : ({ "reinforced", "wooden", "iron" }),
    "wall" : ({ "tall", "white" }),
    "tree" : ({ "pine", "aspen", "green", "dotted" }),
    "cloud" : ({ "large", "white", "cotton" }),
    ]) );
    
  SetInventory( ([
    UNDER_OBJ "lever" : 1,
    ]) );
  SetGateStatus(0);
  SetListen("The faint sounds of chatter come from beyond the wall.");
  SetSmell("The pervasive smell of oil and iron lingers here."); 
 }

int StatusCheck() {
  if (GateStatus) return 1;
  this_player()->eventPrint("You bump into the gate.");
  return 0;
 }

int SetGateStatus(int x) {
  GateStatus = x;
    SetLong(
    "Rounding the end of the valley brings the path here to an abrupt halt. "
    "A large wall crosses the path here. Beyond the wall is seemingly nothing "
    "but wilderness and the side of Mount Trogg. The swirling clouds and mist which "
    "obscure most of the wild peak seem to billow and eddy around the precipice. "
    "Rich green evergreen trees dot the lower slopes of the mountainsides, and "
    "seem to decend right down to the back of the wall. "
    //gatetime
    "Set into the wall is a wide wooden gate reinforced with iron. The gate stands "
    + (GateStatus ? "open and inviting" : "closed and barred") + " to the world. "
    "The gate shows great wear from thousands of years of use and care while "
    "protecting the Gnomish City of Underland. The road to the world continues "
    "to the west from here."
    );
  return x;
 }

void heart_beat() {
  ::heart_beat();
  if (GateStatus) {
    eventPrint("The gate closes with a low humming groan and locks with a dull boom.");
    SetGateStatus(0);
  }
 }

void ChangeGateStatus() {
  if (!GateStatus) {
    eventPrint("The gate hisses softly and begins to open, creaking ponderously on vast hinges. "
               "A warm glow is emitted from within.");
    SetGateStatus(1);
  } else  {
    eventPrint("The gate closes with a low humming groan and locks with a loud boom. "
               "Once closed, no light escapes from within.");
    SetGateStatus(0);
  }
 }
