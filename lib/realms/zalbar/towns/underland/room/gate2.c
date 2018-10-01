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
    "gate" : "This bronze gate is reinforced with iron. A small lever rests at "
             "approximately waist-height (for a human) on the right side of the gate.",
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
    "The path ends at the base of a tall cliff which wraps the hills to the east. A "
    "large arched recess houses a solid wall of bronze gears and iron girders holding "
    "the clockworks in place. Each gear glistens with well tended care and each bearing "
    "is tightly greased. The base of the arch is connected with a large iron band that "
    "easily doubles as a city wall, twice the height of any human and as impassable as "
    "the mountain itself. "
    "Set into the wall is a bronze gate which stands "
    + (GateStatus ? "open and inviting" : "closed and barred") + " to the world, "
    "protecting the Gnomish City of Underland. The road continues to the west "
    "from here."
    );
  return x;
}

void heart_beat() {
  ::heart_beat();
  if (GateStatus) {
    eventPrint("The gate quickly swings shut with an audible hiss.");
    SetGateStatus(0);
  }
}

void ChangeGateStatus() {
  if (!GateStatus) {
    eventPrint("The gate sqeeks and clicks its way open as if against great resistance.");
    SetGateStatus(1);
  } else  {
    eventPrint("The gate quickly swings shut with an audible hiss.");
    SetGateStatus(0);
  }
}
