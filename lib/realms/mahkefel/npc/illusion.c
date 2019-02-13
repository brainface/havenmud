/*
 * an illusion template attempt
*/
#include <lib.h>
inherit LIB_NPC;

string SetIllusionTarget(string target);
object GetIllusionTarget();
string IllusionTarget;

static void create(){
  npc::create();
  SetShort("an obvious illusion");
  SetAdjectives(({"obvious"}));
  SetLong("This is an obvious illusion.");
  SetRace("elemental"); // meh?
  SetGender("male");
  SetClass("rogue");
  SetKeyName("illusion");
  SetId(({"illusion"}));
  SetAction(20,({"!emote continues to not exist."}));
  SetLevel(15);
}

// Set the illusion's target by name
// not checked! may hilarity
object SetIllusionTarget(object target) {
  IllusionTarget = target;
  
  // I think this does parser magic to make ids reset
  // i also think it may mean that the specific way i'm doing this doesn't
  // work. Illusions may need SetId/SetKeyname/etc run, THEN
  // parse_reset run.
}

// Get the object the illusion is targeting, 0 if it can't find them
object GetIllusionTarget() {
  object target;
  if (IllusionTarget) {
    target = find_living(IllusionTarget);
    if (target) {
      return target;
    }
  }
  return 0;
}

// make keyname match illusion target if possible
// doesn't seem to work as intended, may need to be set before
// dude is loaded?
string GetKeyName() {
  object target=GetIllusionTarget();
  if (target) {
    return target->GetKeyName();
  } else {
    return npc::GetKeyName();
  }
}

string GetName() {
  object target=GetIllusionTarget();
  if (target) {
    return target->GetName();
  } else {
    return npc::GetName();
  }
}

// make id match illusion target if possible
string array GetId() {
  object target=GetIllusionTarget();
  if (target) {
    return target->GetId() + npc::GetId();
  } else {
    return npc::GetId();
  }
}

// make adjectives match illusion target if possible
string array GetAdjectives() {
  object target=GetIllusionTarget();
  if (target) {
    return target->GetAdjectives() + npc::GetAdjectives();
  } else {
    return npc::GetId();
  }
}

// make long match illusion target if possible
// (includes armour, wielded weapons, condition)
string GetLong(string nom) {
  object target=GetIllusionTarget();
  if (target) {
    return target->GetLong(nom);
  } else {
    return npc::GetLong(nom);
  }
}

// make short match illusion target if possible
string GetShort(string nom) {
  object target=GetIllusionTarget();
  if (target) {
    return target->GetShort();
  } else {
    return npc::GetShort();
  }
}


  parse_refresh();
