// mahkefel november 2021
// spell effect inheritable
// because i'm dumb and still coding here.


#include <lib.h>
#include <daemons.h>
inherit LIB_ITEM;

// Potency is the value of the effect
int Potency;

// Duration is the timing of the effect!
int Duration;

// The level of the effect, in case of dispel
int Level;

int SetPotency(int x) { return Potency = x; }
int GetPotency() {
  return Potency;
}

int SetDuration(int x) { return Duration = x; }
int GetDuration() {
  if (Duration > 0) return Duration;
  return 0;
}

int SetLevel(int x) { return Level = x; }
int GetLevel() {
  if (Level > 1) return Level;
  return 1;
}


int ApplySpellEffect();
int RemoveSpellEffect();

int startingPotency = 5;

static void create() {
  ::create();
  SetKeyName("spell effect");
  SetId( ({ "spell", "effect" }) );
  SetShort("Spell Effect");
  SetInvis(2); // i think?
  SetPreventGet("");
  SetPreventDrop("");
  SetRetainOnDeath(1);
  SetMaterials( ({ "natural" }) ); //???
  set_heart_beat(20); // value probably in flux.
  AddSave( ({"Potency", "Duration", "Level"}) );
}


void heart_beat() {
  object env = environment();
  Duration--;

  // do stuff if no one is holding me.
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }
  if (!GetDuration()) {
    RemoveSpellEffect();
    return;
  }

  ApplySpellEffect();
}

int ApplySpellEffect() {
  object env = environment();
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }

  // I'm not sure if the "duration" here does anything.
  env->AddStatBonus("strength", GetPotency(), GetDuration() );
  env->AddStatBonus("agility", GetPotency(), GetDuration() );

  return 1;
}

int RemoveSpellEffect() {
  object env = environment();
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }

  env->RemoveStatBonus("strength");
  env->RemoveStatBonus("agility");
  if(env->GetTestChar()) debug (env->GetKeyName()+"'s " + GetShort() + " ended.");
  //eventDestruct();
  return 1;
}

int eventMove(mixed dest) {
  mixed val;

  RemoveSpellEffect();
  val = move::eventMove(dest);
  if (val) {
    call_out( (:ApplySpellEffect:), 1);
  }
  return val;
}

void eventDeteriorate(int damage) {
  return 0;
}

