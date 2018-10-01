#include <lib.h>
#include <damage_types.h>
inherit LIB_VERB;

int eventScream(object who, object target);
int do_scream_at_liv(object);

static void create() {
  ::create();
  SetVerb("scream");
  SetRules("", " at LIV");
  SetHelp("Syntax:   scream\n"
          "          scream at LIV\n\n"
          "A primal scream, which for most people is nothing more than "
          "a good way to let off some steam, in the vocal abilities of "
          "a well-motivated daemon with combat rage can be something brutally evil.");
  SetErrorMessage("Scream?  Scream at who?");
}

mixed can_scream() {
  object who = this_player();
  if (who->GetSleeping()) return "In your dream, you can't scream! AHHHHHH!";
  if (who->GetParalyzed()) return "You can't quite get your lips to move.";
  if (who->GetStaminaPoints() < 50) return "You're just too tired to let off a good yell.";
  return 1;
}

mixed can_scream_at_liv() {
  object who = this_player();
  if (who->GetSleeping()) return "In your dream, you can't scream! AHHHHHH!";
  if (who->GetParalyzed()) return "You can't quite get your lips to move.";
  if (who->GetStaminaPoints() < 50) return "You're just too tired to let off a good yell.";
  return 1;
}

mixed do_scream() {
  object who = this_player();
  object target = who->GetCurrentEnemy();
  if (target && who->GetInCombat()) return do_scream_at_liv(target);
  who->AddStaminaPoints(-50);
  if (who->GetRace() != "daemon") {
    send_messages( ({ "let" }),
      "$agent_name $agent_verb out a %^RED%^BOLD%^primal scream%^RESET%^ that is impressive but vaguely useless.",
      who, 0, environment(who) );
      return 1;
  } else {
    send_messages( ({ "let" }),
      "$agent_name $agent_verb out a %^RED%^BOLD%^primal scream%^RESET%^ that is impressive and frightening.",
      who, 0, environment(who) );
      return 1;
  }
}

mixed do_scream_at_liv(object target) {
  object who = this_player();
  
  who->AddStaminaPoints(-50);
  if (who->GetRace() != "daemon") {
    send_messages( ({ "let" }),
      "$agent_name $agent_verb out a %^RED%^BOLD%^primal scream%^RESET%^ that is impressive but vaguely useless.",
      who, 0, environment(who) );
      return 1;
  } else {
    send_messages( ({ "let" }),
      "$agent_name $agent_verb out a %^RED%^BOLD%^primal scream%^RESET%^ at $target_name!.",
      who, target, environment(who) );
    who->SetAttack(target, (: eventScream, who, target :) );
    return 1;
  }
}

int eventScream(object who, object target) {
  int level = who->GetSkillLevel("combat rage"); 
  string limb = target->GetRandomLimb(target->GetTorso());
  switch(level) {
    case 0..10:
      send_messages( ({ "" }),
        "$agent_possessive_noun scream lightly %^MAGENTA%^breezes off%^RESET%^ $target_possessive_noun " + limb + ".",
        who, target, environment(who) );
      target->eventReceiveDamage(who, SOUND, level, 0, limb);
      break;
    case 11..30:
      send_messages( ({ "" }),
        "$agent_possessive_noun scream %^MAGENTA%^bruises%^RESET%^ $target_possessive_noun " + limb + ".",
        who, target, environment(who) );
      target->eventReceiveDamage(who, SOUND, level, 0, limb);
      break;
    case 31..50:
      send_messages( ({ "" }),
        "$agent_possessive_noun scream %^MAGENTA%^tears a small hole in%^RESET%^ $target_possessive_noun " + limb + "!",
        who, target, environment(who) );
      target->eventReceiveDamage(who, SOUND, level * 2, 0, limb);
      break;
    case 51..80:
      send_messages( ({ "" }),
        "$agent_possessive_noun scream %^MAGENTA%^rends the flesh%^RESET%^ of $target_possessive_noun " + limb + ".",
        who, target, environment(who) );
      target->eventReceiveDamage(who, SOUND, level * 3, 0, limb);
      if (target->eventReceiveAttack(level/2, "magic", who)) {
        send_messages( ({ "are" }),
          "$target_name $target_verb %^BOLD%^MAGENTA%^stunned%^RESET%^ by the force of $agent_possessive_noun scream!",
          who, target, environment(who) );
        target->SetParalyzed(random(3) + 1);
      }
      break;
    case 81..10000:
      send_messages( ({ "" }),
        "$agent_possessive_noun scream %^MAGENTA%^rends the flesh%^RESET%^ of $target_possessive_noun " + limb + ".",
        who, target, environment(who) );
      target->eventReceiveDamage(who, SOUND, level * 4, 0, limb);
      if (target->eventReceiveAttack(level/2, "magic", who)) {
        send_messages( ({ "are" }),
          "$target_name $target_verb %^BOLD%^MAGENTA%^stunned%^RESET%^ by the force of $agent_possessive_noun scream!",
          who, target, environment(who) );
        target->SetParalyzed(random(3) + 1);
      }
      break;
     }
     return 1;
}