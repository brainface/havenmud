// hamstring object
//  You've been hamstrung. Ouch.

// similiar to chains of bonding, but you
// also occasionally collapse to ground in pain.

// eventually maybe make a "WOUND" object this inherits,
//   so healing spells can be made to cure it, show up in
//   score, etc.

// i... HOPE acid rain won't "cure" this?

#include <lib.h>
inherit LIB_ITEM;
int LifeSpan, Severity;

int SetLifeSpan(int x) { return LifeSpan = x; }
int GetLifeSpan() { return LifeSpan; }
int SetSeverity(int x) {return Severity = x; }
int GetSeverity() {return Severity; }

int ApplyWound();
int RemoveWound();

static void create() {
  ::create();
  SetKeyName("wounded hamstring");
  SetId( ({ "wounded hamstring" }) );
  SetShort("a wounded hamstring");
  SetInvis(10);
  SetPreventGet("");
  SetPreventDrop("");
  SetRetainOnDeath(0);
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
    RemoveWound();
    return;
  }
  // reserve for kneecap?
  if (!LifeSpan % 20) {
    send_messages("fall","$agent_possessive_name wounded leg "
      "can't take $agent_possessive weight!"
      env,0,environment(env) );
    env->eventCollapse();
  }
  LifeSpan--;
}

int ApplyWound() {
  object env = environment();
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }

  env->AddStatBonus("agility", -Severity, LifeSpan);
  env->AddStatBonus("coordination", -Severity, LifeSpan);

  return 1;
}

int RemoveWound() {
  object env = environment();
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }

  env->eventPrint("You can walk again without pain.");
  env->RemoveStatBonus("agility");
  env->RemoveStatBonus("coordination");
  eventDestruct();
  return 1;
}

