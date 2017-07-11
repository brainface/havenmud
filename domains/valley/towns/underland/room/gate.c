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
    "west" : VALLEY_VIRTUAL "valley/10,10",
    ]) );
  AddExit("east", UNDER_ROOM "road01", (: StatusCheck :) );
  SetItems( ([
    "wall" : "This wall is a stone beast that would be difficult to bash down.",
    "gate" : "This wooden gate is reinforced with iron. A small lever rests at "
             "approximately waist-height (for a human) on the gate.",
    ]) );
  SetInventory( ([
    UNDER_OBJ "lever" : 1,
    ]) );
  SetGateStatus(0);
  SetListen("The sounds of gnomish chatter come from beyond the wall.");
  SetSmell("The sounds of a small town waft over the wall.");
}

int StatusCheck() {
  if (GateStatus) return 1;
  this_player()->eventPrint("You bump into the gate.");
  return 0;
}

int SetGateStatus(int x) {
  GateStatus = x;
    SetLong(
    "A large wall, slightly taller than ogre-height, crosses the path here. "
    "Set into the wall is a wooden gate reinforced with iron. The gate stands "
    + (GateStatus ? "open and inviting" : "closed and barred") + " to the world, "
    "protecting the Gnomish City of Underland. The road continues to the west "
    "from here."
    );
  return x;
}

void heart_beat() {
  ::heart_beat();
  if (GateStatus) {
    eventPrint("The gate swings shut and locks with a *CLICK*.");
    SetGateStatus(0);
  }
}

void ChangeGateStatus() {
  if (!GateStatus) {
    eventPrint("The gate swings open.");
    SetGateStatus(1);
  } else  {
    eventPrint("The gate swings shut and locks with a *CLICK*.");
    SetGateStatus(0);
  }
}