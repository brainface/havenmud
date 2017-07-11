#include <lib.h>
inherit LIB_ITEM;
int LifeSpan;
int SetLifeSpan(int x) { return LifeSpan = x; }
int GetLifeSpan() { return LifeSpan; }

static void create() {
  ::create();
  SetKeyName("natural_charge");
  SetId( ({ "natural_charge" }) );
  SetShort("a natural charge");
  SetInvis(10);
  SetPreventGet("");
  SetPreventDrop("");
  SetRetainOnDeath(1);
  SetMaterials( ({ "natural" }) );
  set_heart_beat(1);
}

void heart_beat() {
  object env = environment();
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }
  if (!LifeSpan) {
    env->eventPrint("Your natural charge has faded.");
    eventDestruct();
    return;
  }
  LifeSpan--;
}