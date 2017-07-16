// mahkefel
// rath-cult spell
// charms an elf, dark-elf, wild-elf, or half-elf!
// will instead paralyze a player for 1-20 rounds.

#include <lib.h>
#include <magic.h>
#include <rooms.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("imperious command");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills( ([
    "faith"   : 50,
    "necromancy" : 50,
    ]) );
  SetDifficulty(40);
  SetMagicCost(125, 125);
  SetReligions("Rath-cult");
  SetHelp(
    "Calling upon ancient and forgotten laws, the cultist of Rath may command "
    "one of the elves to abandon their false gods and obey their true master. "
    "Extraordinary strong-willed souls may resist these orders, though not "
    "without a fight."
  );
}

varargs int CanCast(object who, int level, mixed limb, object *targets) {
  object t = targets[0];
  if (t->GetRace() != "elf" &&
      t->GetRace() != "half-elf" &&
      t->GetRace() != "wild-elf" &&
      t->GetRace() != "dark-elf") {
    who->eventPrint("But " + t->GetShort() + " is not of elven blood!");
    return 0;
  }
  return ::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object t = targets[0];
  int resistance, offense;

  offense    = who->GetSkillLevel("faith");
  resistance = t->GetMagicResistance() + t->GetStatLevel("wisdom");
  if (who->GetTestChar()) debug("Offense: " + offense + " vs Defense: " + resistance + " (MR: " + t->GetMagicResistance() + ")");
  if (random(offense) > resistance) {

    send_messages( ({ "shout" }),
      "$target_name%^BOLD%^BLACK%^ $target_verb%^RESET%^ words of ancient "
      "authority at $agent_name.",
      who, t, environment(t) );
    t->eventCollapse();
    t->eventForce("halt " + who->GetKeyName());
    if(!playerp(t)) {
      t->eventMove(ROOM_VOID);
      t->RemoveEnemy(who);
      t->SetWander(0);
      who->RemoveEnemy(t);
      t->ResetCurrentEnemy();
      who->ResetCurrentEnemy();
      t->eventMove(environment(who));
      t->AddFriend(who->GetKeyName());
      t->SetOwner(who->GetKeyName());
      who->AddFollower(t);
      t->SetReligion("Rath Cult");
      t->SetMorality(-1500);
      who->eventForce("lead " + t->GetKeyName());
      t->eventForce("bow " + who->GetKeyName());
      if (member_array(t, who->GetFollowers()) == -1) {
        who->eventPrint(capitalize(t->GetShort()) + " is not following you.");
      }
      t->SetParalyzed(0);
      t->eventForce("cry");
      t->eventForce("say I hear and obey you, Rath Khan!");
    } else {
      send_messages( ({"is"}),
        "$target_name $target_verb locked in inner struggle against "
        "$agent_possessive_noun infernal commands!",
        who,t, environment());      
      who->SetParalyzed(random(20)+1);
    }
    return 1;
  }
  send_messages( ({ "defy" }),
    "$target_name $target_verb the effects of $agent_possessive_noun spell!",
    who, t, environment(who) );
    t->SetAttack(who);
  return 1;
}

