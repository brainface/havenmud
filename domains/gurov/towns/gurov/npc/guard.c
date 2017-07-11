#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_TOWNGUARD;
int eventSpecialAttack();
int eventEndScuffle(object ob);
int CheckCombat();

static void create() {
  ::create();
  SetRace("human");
  SetTown("Gurov");
  RemoveLanguage("Enlan");
  SetLanguage("Gurovian", 100, 1);
  SetGender("male");
  SetKeyName("gurovian guard");
  SetShort("a member of the Prince's Own guard");
  SetId( ({ "guard", "member" }) );
  SetAdjectives( ({ "prince", "prince's", "princes", "gurov", "gurovian", "guard", }) );
  SetClass("fighter");
  SetLevel(20);
  SetInventory( ([
    STD_SLASH "shortsword" : "wield sword",
    STD_CLOTHING "cloak/surcoat" : "wear surcoat",
    ]) );
  SetLong("This guard is wearing the tabard of one of the Prince's Own, "
          "the hardiest bunch of soldiers in the Principality of Gurov. "
          "He is charged with enforcing the peace and will often get "
          "involved in a scuffle to settle the brawl peacefully."
          );
  SetAction(6, ({
    "!say The Prince is a man of peace.",
    "!say The borders of the Principality are secure.",
    "!say Friggin Goden pirates.",
    "!say Move along, nothing to see here.",
  }) );
  SetCombatAction(60, (: eventSpecialAttack :) );
  SetFriends( ({ "gurov_npc" }) );
}

int eventSpecialAttack() {
  object ob;
  eventForce("yell Hey now, break it up!");
  SetAttack(ob = ResetCurrentEnemy(), (: eventEndScuffle, (ob) :));
  return 1;
}
  
int CheckCombat() {
  if (this_player()->GetInCombat()) {
    eventForce("yell Break it up I say!");
    AddEnemy(this_player());
    return 1;
  }
  return 0;
}

int eventEndScuffle(object who) {
  object *e;
  if (!userp(who)) return 1;
  send_messages( ({ "bash" }),
    "%^BLUE%^With a deft move of $agent_possessive hand, $agent_name $agent_verb "
    "$target_name solidly, causing $target_possessive_noun knees to buckle.",
    this_object(), who, environment() );
  who->eventCollapse();
  who->SetSleeping(3);
  e = who->GetEnemies();
  foreach(object en in e) {
    en->RemoveEnemy(who);
    who->RemoveEnemy(en);
  }
  return 1;
}
