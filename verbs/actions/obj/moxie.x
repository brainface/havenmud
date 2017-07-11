// mahkefel november 2011:

// moxie!

// rage object
//   basically, a dirty tricks rage buff.
//   Increases coordination, luck, and gives
//   a certain capped amount of disorient.
// A few, limited attacks add moxie, and it tends to add in large chunks.
//   This is to make it easier on spellcasters: they tend to use knives, and 
//   they can avoid certain attacks to avoid disorient. On the other hand, 
//   adding moxie to verbs can limit their usefullness to mages to balance a bit.

// shiv: 20 moxie
// hock: on success, 10 moxie.

// The value requires and relies upon dirty tricks skill,
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

static void create() {
  ::create();
  SetKeyName("moxie");
  SetId( ({ "moxie" }) );
  SetShort("a malicious moxie");
  SetInvis(2); // i think?
  SetPreventGet("");
  SetPreventDrop("");
  SetRetainOnDeath(1);
  SetMaterials( ({ "natural" }) ); //???
  set_heart_beat(20); //???
  AddSave(({Severity}));
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

string GetCombatActionDescription() {
  return " %^BOLD%^%^BLACK%^(moxie: " + GetSeverity() + ")%^RESET%^";

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
  env->AddStatBonus("coordination", GetSeverity(), Severity*5);
  env->AddStatBonus("luck", GetSeverity(), Severity*5);

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
    send_messages("grin",
      "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ toothily and glances around.",
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
  env->eventPrint("You conscience starts to bicker again.");
  env->RemoveStatBonus("coordination");
  env->RemoveStatBonus("luck");
  env->RemoveProperty("planar_coordination");
  env->RemoveProperty("planar_luck");
  send_messages( ({"frown", "slump"}), "$agent_name%^BOLD%^ "
    "$agent_verb%^RESET%^$ and%^BOLD%^ $agent_verb $agent_possessive "
    "shoulders guiltily.",env,0, environment(env));

  if(env->GetTestChar()) debug (env->GetKeyName()+"'s moxie ended.");
  eventDestruct();

  return 1;

}

int eventRage(object who ) {
  object rage;
  int maxSeverity, newSeverity;
  object *junk = all_inventory(who);

  // You're not a berserker!
  if( !who->GetSkillLevel("dirty tricks") ) {
    who->eventPrint("For a moment, you see everyone around you as "
      "simple rubes with fumbling hands and overlarge coin purses, "
      "waiting for a knife in the gullet to relieve them of all their "
      "problems. Shaking your head slightly, you continue on.");
    debug("Silly non-dirty fighter tried to moxie.");
    return 0;
  }

  // if dude is already moxing, make their rage object
  // increase in severity, otherwise, give them a rage
  // object
  newSeverity = 10;
  foreach( object crap in junk) {
    if ( crap->GetKeyName() == "moxie" ) {
      rage = crap;
    }
  }

  // I am already raging
  if (rage) {
     newSeverity = rage->GetSeverity() + 2;

  // I have planar flags but am not raging
  } else if (who->GetProperty("planar_luck")
    || who->GetProperty("planar_coordination") ) {
    who->eventPrint("You feel a murderous will struggling to free itself "
      "within you, but some magic affecting you seems to interfere!");
    return 0;

  // I don't have any strength boosters I shouldn't stack with
  } else {
    rage= new(base_name(this_object()));
    rage->eventMove(who);
  }

  // cap bonus according to Berserking skill
  maxSeverity = 10 + who->GetSkillLevel("dirty tricks") / 5;
  if (newSeverity > maxSeverity) newSeverity = maxSeverity;
  rage->SetSeverity(newSeverity);
  who->SetProperty("planar_luck",1);
  who->SetProperty("planar_coordination",1);
  rage->ApplyRage();

  if(who->GetTestChar()) debug( who->GetCapName() +
    " don't care about your ridiculous laws against silly things "
    "like larceny and murder: " + rage->GetSeverity() );
}

