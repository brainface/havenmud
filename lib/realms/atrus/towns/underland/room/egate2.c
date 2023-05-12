// Underland inner west gate
// File gate2.c The Decent
// Atrus@HavenMud 2023

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
  SetShort("at the Gate of the Underland");
  SetExits( ([
    "west" : UNDER_ROOM "eorc",
    ]) );
  AddExit("east", UNDER_ROOM "egate", (: StatusCheck :) );
  SetItems( ([
    "wall" : "The western wall is dominated by what appears to be a solid iron "
             "door. There are large buttresses and arches reinforce the wall acting "
             "not only as perimeter and battlement of the west side of the city.",
    "gate" : "This solid iron gate appears to be made of thick iron plates riveted "
             "together and tightly bound. There seems to be a pattern of rivets that "
             "matches the banding on the outside of the gate. The facade on the "
             "exterior of wood is merely a replaceable wear layer over this heavy iron. ",
    ({"rivets", "rivet" }) : "Very large iron rivets have been sunk through the gate "
             "holding it together. They have a perfectly rounded top, which is a stark "
            "difference from their worldly appearance on the other side of the gate. "
            "These rivets were set by a very large tool.",
    ({ "ramp", "slope", "road", "tunnel", "mount", 
    "trogg", "planet", "rock", "mount trogg"}) : 
            (: GetLong :),        
    ({ "scrapes", "scrape", "marks", "mark", "score" }) : " There are very shallow "
            "and evenly spaced spiral style marks that are scored into the face of the "
            "tunnel all the way around. The pattern descends into the distance without "
            "faltering. There must have been just one tooth out of adjustment "
            "on the great machine that bored the tunnel.",
    ({ "machine", "machines" }) : "There are no boring machines left here.",
    ({ "lamp", "lamps", "glow", "globes" }) : "There are evenly spaced glass globe lamps "
            "hanging in regular intervals descing the path to the east. Each one easily "
            "illuminates the ground to the next globe's light allowing travellers "
            "to see every walkable inch of road.",
    ({ "arch", "arches", "ceiling", "roof", "up" }) : "The tunnel ceiling is a "
            "continuation of the natural curve the boring machine's working face "
            "made as it clawed and chewed its way through to the very heart of Mount "
            "Trogg. Huge buttresses of what appears to be steel have been placed at "
            "even intervals, offsetting lamps which allow the tops of the arches to "
            "be lost in just a hint of darkness. The bore would easily accomodate a "
            "large horse and stagecoach with room to spare over the driver's head.",
    ({ "piston", "pistons" }) : "Enormous steam driven pistons actuate the gate " 
            "as it opens and closes. Each are easily as big around as a maple tree trunk "
            "and look to be ancient. However they are meticulously cared for. The source "
            "of power is not evident.",
    ]) );
  SetInventory( ([
    UNDER_OBJ "lever" : 1,
    ]) );
  SetGateStatus(0);
  SetListen("The sounds of regular clatter of clockwork echoes beyond the wall.");
  SetSmell("The mild scent of old grease comes from the gate.");
}

int StatusCheck() {
  if (GateStatus) return 1;
  this_player()->eventPrint("You bump into the gate.");
  return 0;
}

int SetGateStatus(int x) {
  GateStatus = x;
  SetLong(   
    "The city gate to the east is " + (GateStatus ? "open" : "sealed") + " to the world."
    );
  return x;
}

void heart_beat() {
  ::heart_beat();
  if (GateStatus) {
    eventPrint("The gate's pistons hiss loudly as they close the immensely heavy gate.");
    SetGateStatus(0);
  }
}

void ChangeGateStatus() {
  if (!GateStatus) {
    eventPrint("The pistons pushing the gate open groan and hum under immense strain.");
    SetGateStatus(1);
  } else  {
    eventPrint("The gate's pistons hiss loudly as they close the immensely heavy gate.");
    SetGateStatus(0);
  }
}
