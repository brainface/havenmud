// mahkefel november 2011:

// rage object
//   basically, a barbarian rage buff.
//   Increases strength, durability, and gives
//   a certain capped amount of disorient.
// Various "berserking" verbs will add this object
//   to the user. The more special berserking attacks
//   they use, the higher the buff gets, but it degrades
//   over time.
// The value requires and relies upon berserking skill,
//   and is capped at the same level as planar strength.

// Oh yeah, this really shouldn't stack with planar like spells.

#include <lib.h>
#include <daemons.h>
inherit LIB_ITEM;

// severity is the value of the buff and a factor of the
//   enforced disorient drawback.
int Severity;

int SetSeverity(int x) { return Severity = x; }
int GetSeverity() {
  if (Severity > 0) return Severity;
  return 0;
}

int ApplyRage();
int RemoveRage();

int eventRage(object who, int severity, int lifespan);

string GetDescription();

static void create() {
  ::create();
  SetKeyName("berserker rage");
  SetId( ({ "berserker rage" }) );
  SetShort("a berserker rage");
  SetInvis(2); // i think?
  SetPreventGet("");
  SetPreventDrop("");
  SetRetainOnDeath(1);
  SetMaterials( ({ "natural" }) ); //???
  set_heart_beat(20); //???
  AddSave( ({"Severity"}) );
}

string GetCombatActionDescription() {
  return " %^BOLD%^RED%^(enraged: " + GetSeverity() + ")%^RESET%^";
}

void heart_beat() {
  object env = environment();

  Severity--;

  // do stuff if no one is holding me.
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }

  if (!GetSeverity()) {
    RemoveRage();
    return;
  }

  ApplyRage();

}

int ApplyRage() {
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
  env->AddStatBonus("strength", GetSeverity(), Severity*5);
  env->AddStatBonus("durability", GetSeverity(), Severity*5);

  // raging enforces a minimum amount of daze, of 10x its bonus
  //   i.e. if someone has +10 str/dur here, this will make sure
  //   they have 100 daze. If they have, say, 10000 daze,
  //   nothing happens.
  if (env->GetRecoveryTime() < 10 * Severity) {
    env->SetRecoveryTime(10*Severity);
  }

  // every few ticks, froth at the mouth, to make raging visible
  //   and obvious.
  if (Severity % 5 == 0) {
    send_messages("froth",
      "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ at the mouth.",
      env, 0, environment(env) );
  }

  return 1;
}

int RemoveRage() {
  object env = environment();
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }

  // send some fancy messages and end the stat bonus. (it should already be 0)
  env->eventPrint("You suddenly wonder what you were so upset about.");
  env->RemoveStatBonus("strength");
  env->RemoveStatBonus("durability");
  env->RemoveProperty("planar_strength");
  env->RemoveProperty("planar_durability");
  send_messages("wipe", "$agent_name $agent_verb the %^BOLD%^spittle%^RESET%^ "
    "from $agent_possessive mouth.",env,0, environment(env));
  if(env->GetTestChar()) debug (env->GetKeyName()+"'s rage ended.");
  eventDestruct();
  return 1;
}

int eventRage(object who ) {
  object rage;
  int maxSeverity, newSeverity;
  object *junk = all_inventory(who);

  // You're not a berserker!
  if( !who->GetSkillLevel("berserking") ) {
    who->eventPrint("You feel yourself suddenly at a precipice, standing on a "
      "cliff above a sea of boundless rancor. But the feeling receeds as soon "
      "as it began, leaving you in your harmless state of domesticity.");
    debug("Silly non-berserker tried to rage.");
    return 0;
  }

  // if dude is already raging, make their rage object
  // increase in severity, otherwise, give them a rage
  // object
  newSeverity = 2;
  foreach( object crap in junk) {
    if ( crap->GetKeyName() == "berserker rage" ) {
      rage = crap;
    }
  }

  // I am already raging
  if (rage) {
     newSeverity = rage->GetSeverity() + 2;

  // I have planar flags but am not raging
  } else if (who->GetProperty("planar_strength")
    || who->GetProperty("planar_durability") ) {
    who->eventPrint("You feel a horrible emotion struggling to build within "
      "you, but some magic affecting you seems to interfere!");
    return 0;

  // I don't have any strength boosters I shouldn't stack with
  } else {
    rage= new(base_name(this_object()));
    rage->eventMove(who);
  }

  // cap bonus according to Berserking skill
  maxSeverity = 10 + who->GetSkillLevel("berserking") / 5;
  if (newSeverity > maxSeverity) newSeverity = maxSeverity;
  rage->SetSeverity(newSeverity);
  who->SetProperty("planar_strength",1);
  who->SetProperty("planar_durability",1);
  rage->ApplyRage();

  if(who->GetTestChar()) debug( who->GetCapName() +
    " is one pissed man with a plan: " + rage->GetSeverity() );
}

void eventDeteriorate(int damage) {
  return 0;
}

