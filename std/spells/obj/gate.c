#include <lib.h>
inherit LIB_DUMMY;

string GateTarget = "";
int LifeSpan = -1;

static void create() {
  ::create();
  SetKeyName("gate");
  SetShort("a swirling magical gate");
  SetId( ({ "gate", "magic_gate" }) );
  SetAdjectives( ({ "swirling", "magical" }) );
  SetLong("This swirling gate of magic seems to connect two points on Kailie.");
  set_heart_beat(1);
  SetInvis(0);
  
}

string SetGateTarget(string target) {
  GateTarget = target;
  if (environment()) {
    environment()->AddEnter("gate", target);
  }
  return GateTarget;
}

int SetLifeSpan(int x) { 
  return LifeSpan = x;
}

int GetLifeSpan() { return LifeSpan; }
string GetGateTarget() { GateTarget; }

void heart_beat() {
  LifeSpan--;
  if (LifeSpan <= 0) {
    if (environment()) {
      environment()->RemoveEnter("gate");
      environment()->eventPrint(
        "%^MAGENTA%^The swirling magical gate dissipates with an audible *POP*.%^RESET%^"
        );
    }
    eventDestruct();
    return;
  }
}

string GetAffectLong() { return "\n%^MAGENTA%^There is a swirling magical gate here.%^RESET%^"; }