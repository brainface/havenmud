/* ----------------------------------------------------------------------- */
// Mahkefel 2011.
// I stole dylanthus's code. I also stole his code COMMENT BLOCK.
// TAKE THAT, DYLANTHUS.
//
// Actually heavily modified. The goal is, like clairvoyance, but better,
//   but it tells you info of a RANDOM other player. I.E. your god tells
//   you info about someone else for you to act upon.
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

// DO NOT start any of these with
// vowels. Unless you want to put
// a/an in front of all of them.
mapping skillsThatMatter = ([
  "armour smithing"     : "champion armourer",
  "bargaining"          : "notable merchant",
  "blunt combat"        : "master of bludgeoning",
  "brawling"            : "winner of brawls",
  "conjuring"           : "supreme conjurer",
  "cooking"             : "talented cook",
  "disarm"              : "skilled fencer",
  "disorient"           : "wily harrier",
  "enchantment"         : "skilled enchanter",
  "evokation"           : "dangerous battlemage",
  "faith"               : "pious cleric",
  "farming"             : "notable farmer",
  "fishing"             : "passable fisherman",
  "hack combat"         : "master of the axe",
  "healing"             : "merciful healer",
  "illusion"            : "wily illusionist",
  "instrumental music"  : "talented musician",
  "knife combat"        : "master of the knife",
  "lockpicking"         : "skilled locksmith",
  "melee combat"        : "veteran pugilist",
  "mining"              : "weary miner",
  "natural magic"       : "priest of the wild",
  "necromancy"          : "necromancer",
  "pierce combat"       : "master duelist",
  "pole combat"         : "master of the staff",
  "practical magic"     : "hedgewizard",
  "projectile combat"   : "cunning archer",
  "sailing"             : "veteran sailor",
  "slash combat"        : "master of the blade",
  "stealing"            : "shameless thief",
  "stealth"             : "cunning skulk",
  "vocal music"         : "pleasant vocalist",
  "weapon smithing"     : "dependable weaponsmith",
]);

static void create() {
  spell::create();
  SetSpell("prophecy");
  SetDifficulty(50);
  SetRules("");
  SetGlobalSpell(1);
  SetRequiredMagic(100);
  SetMagicCost(50, 50);
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "faith" : 15,
     "enchantment" : 15,
     ]) );
  SetReligions("Anteky");
  SetHelp(
    "With the casting of this spell, the faithful Anteky "
    "cleric can commune with the One God who may reveal to "
    "them a prophecy. These usually entail information on "
    "righteous and wicked souls."
    );
  }

/* CanCast is from discern location, originally
   coded by Vanyel@Haven */
/*
int CanCast(object who, int level, mixed limb, object *targets) {
  if (creatorp(targets[0])) {
      message("system", "Cast it on whom?", who);
      return 0;
     }
  // ANTKEY CAN SEE YOU EVEN ON YOUR SHIP, THERE IS NO ESCAPE
  if (vehiclep(environment(targets[0]))) {
    who->eventPrint("That person is on a ship and clouds prevent your conjuring.");
    return 0;
  }

  return spell::CanCast(who, level, limb, targets);
}*/

varargs int eventCast(object who, int level, mixed n, object *t) {
  object target;
  string *skills = ({ });
  string morality = "";
  object* users = users();
  object* players = users;

  // okay, now we make an array of all users, filter out non players
  // (no spying on duuk, or test characters)
  // and pick one randomly as a target. if none remain, fail.
  foreach(object user in users) {
    if (who->GetTestChar()) debug(user);
    // don't let duuk be a target
    if (!playerp(user)) players -= ({user});
    // you know who you are.
    if (user == who) players -= ({user});
    // don't let yanna be a target.
    if (user->GetTestChar()) players -= ({user});
  }

  // if there's actually any other player online.
  if ( sizeof(players) ) {
    target = players[random(sizeof(players))];
  } else {
    who->eventPrint("The One God has no one to reveal to you at this time.");
    return 0;
  }

  message("scry", "In your mind's eye "
                  "the One God reveals to you:", who);
  message("scry",
    environment(who)->GetRemoteDescription(base_name(environment(target)), 1),
    who);

  // NOW we tell crazy skill stuff.
  skills = target->GetPrimarySkills();
  foreach( string skill in skills ) {
    if ( skillsThatMatter[skill] ) {
      who->eventPrint(target->GetName() + " is a " +skillsThatMatter[skill] + ".");
    }
  }

  morality = target->GetName() + " is ";
  if (target->GetMorality() < -1000 ) {
    morality += "a wicked ";
  } else if (target->GetMorality() > 1000) {
    morality += "a righteous ";
  } else {
    morality = "a wayward ";
  }
  if (target->GetReligion() == "Anteky") {
    morality += "follower of the One God.";
  } else if (target->GetReligion() == "Kylin") {
    morality += "but misguided follower of the One God.";
  } else if (target->GetReligion() == "Enniae") {
    morality += "minion of the Serpent.";
  } else {
    morality += "unbeliever.";
  }
  who->eventPrint(morality);

  send_messages("gaze", "$agent_name $agent_verb very far away at something "
    "only $agent_nominative can see.",
    who, 0, environment(who));
  return 1;
}

