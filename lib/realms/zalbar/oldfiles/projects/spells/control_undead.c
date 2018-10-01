#include <lib.h>
#include <magic.h>
#include <rooms.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("control undead");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills( ([
    "faith"      : 25,
    "necromancy" : 25,
    ]) );
  SetDifficulty(30);
  SetMagicCost(50, 50);
  SetHelp(
    "This spell allows a priest to control an undead being. "
    "Its effectiveness is dependant on many factors."
    );
}
 
varargs int CanCast(object who, int level, mixed limb, object *targets) {
  object t = targets[0];
  if (t->GetUndead() != 1) {
    who->eventPrint("But " + t->GetShort() + " is not undead!");
    return 0;
  }
  if (t->GetInCombat()) {
    who->eventPrint(capitalize(t->GetShort()) + " is too busy to be controlled!");
    return 0;
    }
  return ::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object t = targets[0];
  int resistance, offense;
  
  offense    = who->GetSkillLevel("necromancy");
  resistance = t->GetMagicResistance() + t->GetStatLevel("wisdom");;
  if (who->GetTestChar()) debug("Offense: " + offense + " vs Defense: " + resistance + " (MR: " + t->GetMagicResistance() + ")");
  if (random(offense) > resistance) {
    send_messages( ({ "slow", "halt", "gaze" }),
      "$target_name $target_verb, $target_verb and suddenly $target_verb lovingly at $agent_name.",
      who, t, environment(t) );
    t->eventCollapse();
    t->eventForce("halt " + who->GetKeyName());
    t->eventMove(ROOM_VOID);
    t->RemoveEnemy(who);
    who->RemoveEnemy(t);
    t->ResetCurrentEnemy();
    who->ResetCurrentEnemy();
    t->eventMove(environment(who));
    t->AddFriend(who->GetKeyName());
    t->SetOwner(who->GetKeyName());
    who->AddFollower(t);
    who->eventForce("lead " + t->GetKeyName());
    t->eventForce("grin " + who->GetKeyName());
    if (member_array(t, who->GetFollowers()) == -1) {
      who->eventPrint(capitalize(t->GetShort()) + " is not following you.");
      }
    t->SetParalyzed(0);
    return 1;
  }
  send_messages( ({ "ignore" }),
    "$target_name $target_verb the effects of $agent_possessive_noun spell!",
    who, t, environment(who) );
    t->SetAttack(who);
  return 1;
}

