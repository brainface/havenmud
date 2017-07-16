#include <lib.h>
inherit LIB_DUMMY;

string GateTarget = "";
int LifeSpan = -1;

static void create() {
  ::create();
  SetKeyName("tunnel");
  SetShort("a roiling underwater tunnel");
  SetId( ({ "tunnel", "mosestunnel" }) );
  SetAdjectives( ({ "roiling","underwater" }) );
  SetLong("Strong winds driving at the waters here have "
    "seemingly formed a safe tunnel leading underwater. "
    "It is almost certainly unnatural.");
  set_heart_beat(1);
  SetInvis(0);

}

string SetGateTarget(string target) {
  GateTarget = target;
  if (environment()) {
    environment()->AddEnter("tunnel", target);
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
      environment()->RemoveEnter("tunnel");
      environment()->eventPrint(
        "%^BOLD%^BLUE%^The divided waters suddenly collapse in a horrible crash.%^RESET%^"
        );
    }
    eventDestruct();
    return;
  }
}

string GetAffectLong() { return "\n%^BLUE%^There is a tunnel leading under the water here.%^RESET%^"; }

