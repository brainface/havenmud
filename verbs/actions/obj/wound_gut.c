// your guts are hanging out, jim.

// eventually maybe make a "WOUND" object this inherits,
//   so healing spells can be made to cure it, show up in
//   score, etc.

// i... HOPE acid rain won't "cure" this?

#include <lib.h>
#include <damage_types.h>
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
  SetKeyName("eviscerated belly");
  SetId( ({ "eviscerated belly" }) );
  SetShort("an eviscerated belly");
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
    RemoveWound();
    return;
  }
  if (!LifeSpan % 20) {
    send_messages(({"scramble","tear"}), "$agent_name $agent_verb "
      "to pull $agent_possessive guts back in and "
      "%^BOLD%^RED%^tear%^RESET%^ something!",
      env, 0, environment(env) );

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

  env->AddStatBonus("durability", -Severity, LifeSpan);

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
  send_messages(({"have"}), "%^YELLOW%^$agent_name $agent_verb "
    "managed to stich $agent_possessive guts back in, more or less.%^RESET%^",
    env, 0, environment(env) );

  // does this_object work?
  // disease==bleeding damage type.
  env->eventRecieveDamage(this_object(), DISEASE, random(50), 1);
  env->RemoveStatBonus("durability");
  eventDestruct();
  return 1;
}

