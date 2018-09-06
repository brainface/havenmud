// mahkefel :

// this one applies to allies, stacks with everything, and isn't very big.

//   it increases mental stats as you overcome fear blah,blah something

// it gives the target a large bonus, then decreases over time. reusing the verb
//   that applies it refreshes the buff.


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
int GetSeverity() { return Severity; }

int ApplyRage();
int RemoveRage();

int eventRage(object who, object source);

static void create() {
  ::create();
  SetKeyName("conspiracy");
  SetId( ({ "clever conspiracy" }) );
  SetShort("a clever conspiracy");
  SetInvis(2); // i think?
  SetPreventGet("");
  SetPreventDrop("");
  SetRetainOnDeath(1);
  SetMaterials( ({ "natural" }) ); //???
  set_heart_beat(20); //???
  AddSave( ({"Severity"}) );
}

string GetCombatActionDescription() {
  return " %^BOLD%^BLACK%^(conspiracy: " + GetSeverity() + ")%^RESET%^";
}

void heart_beat() {
  object env = environment();

  // do stuff if no one is holding me.
  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;
  }
  if (!Severity) {
    RemoveRage();
    return;
  }

  ApplyRage();
  Severity--;
}

int ApplyRage() {
  object env = environment();
  int amt = 0;

  if (!env) {
    eventDestruct();
    return;
  }
  if (!living(env)) {
    eventDestruct();
    return;

  }

  // I'm not sure if the "duration" here does anything.
  env->AddStatBonus("intelligence", Severity, Severity*5);

  if (env->GetRecoveryTime() > 1) {
    amt = random(Severity/2*5)+5;
    if (amt > env->GetRecoveryTime()) amt = env->GetRecoveryTime();
    env->AddRecoveryTime(amt);
    env->eventPrint("You focus on the plan.");
  }

  // every few ticks, froth at the mouth, to make raging visible
  //   and obvious.
  if (Severity % 5 == 0) {
    send_messages("grin",
      "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ deviously.",
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
  env->eventPrint("You suddenly wonder why you were feeling so clever.");
  env->RemoveStatBonus("intelligence");
  send_messages("look", "$agent_name%^BOLD%^ $agent_verb%^RESET%^ confused and a little bit lost.",
    env,0, environment(env));
  if(env->GetTestChar()) debug (env->GetKeyName()+"'s rage ended.");
  eventDestruct();
  return 1;
}

int eventRage(object who, object source  ) {
  object rage;
  int maxSeverity, newSeverity;
  object *junk = all_inventory(who);

  // if dude is already raging, make their rage object
  // increase in severity, otherwise, give them a rage
  // object
  newSeverity = 3 + source->GetSkillLevel("dirty tricks") / 25;
  foreach( object crap in junk) {
    if ( crap->GetKeyName() == "conspiracy" ) {
      rage = crap;
    }
  }

  // I am already raging
  if (rage) {
     if (rage->GetSeverity() > newSeverity) newSeverity = rage->GetSeverity();
  // I don't have any strength boosters I shouldn't stack with
  } else {
    rage= new(base_name(this_object()));
    rage->eventMove(who);
  }

  // cap bonus according to Berserking skill
  rage->SetSeverity(newSeverity);
  rage->ApplyRage();

  if(who->GetProperty("action_debug")) debug( who->GetCapName() +
    " is the (wo)man with the plan: " + rage->GetSeverity() );
}

void eventDeteriorate(int damage) {
  return 0;
}
