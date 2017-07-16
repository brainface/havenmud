#include <lib.h>
#include <damage_types.h>
#include "../lisht.h"
inherit LIB_NPC;

int eventCombatAct();

static void create() {
  string name, gender;
  int number;
  ::create();
  name = PHARAOH_D->GetCurrentPharaoh();
  number = PHARAOH_D->GetPharaohNumber(name);
  
  SetKeyName(name);
  SetShort("Pharaoh " + capitalize(name) + " the " + number + "" + ordinal(number) + " of the Xandrian Dynasty");
  SetId( ({ name, "pharaoh" }) );
  SetAdjectives( ({ "pharaoh", }) );
  SetRace("gnoll");
  SetTown("Lisht");
  SetClass("fighter");
  SetGender(PHARAOH_D->GetPharaohGender());
  SetLevel(400);
  SetMorality(-500);
  SetCurrency("deben", 30000);
  SetBaseLanguage("Rehshai");
  SetReligion("Enniae");
  SetLong(
    capitalize(name) + " the " + number + "" + ordinal(number) + " is the Pharaoh of the Xandrian "
    "Dynasty, making " + objective(GetGender()) + " the absolute ruler of the land. The Pharaoh's "
    "will is as law, and the Pharaoh is seen as nearly divine."
    );
  SetAction(5, ({
    "!say Silence, Pharaoh Speaks!",
    "!say I am the Morning and the Evening Star",
    "!say Xandria lives ever on",
  }) );
  SetCombatAction(40, (: eventCombatAct :) );
  SetLimit(1);
  SetInventory( ([
    LISHT_OBJ "khopesh" : "wield sword",
    ]) );
  SetFriends( ({ "guard" }) );
}

int eventDie(object agent) {
  PHARAOH_D->PharaohDied();
  return ::eventDie(agent);
}

int eventCombatAct() {
	object who = GetCurrentEnemy();
	object tmp;
	
	switch(random(3)) {
		case 0:
			eventForce("yell SILENCE NOW!  PHARAOH SPEAKS!");
			environment()->eventPrint("A thunderous clap stuns you!");
			GetEnemies()->SetParalyzed(3);
			break;
		case 1:
			eventForce("emote raises " + possessive(this_object()) + " arms and %^BOLD%^RED%^screams%^RESET%^!");
			who->eventReceiveDamage(this_object(), SHOCK, 2500, 0, who->GetTorso());
			break;
		case 2:
			eventForce("emote opens " + possessive(this_object()) + " mouth and %^GREEN%^spews forth%^ a vile substance!");
			foreach(object o in all_inventory(who)) {
				o->eventReceiveDamage(this_object(), ACID, 2500, 0, ({ }));
			}
			who->eventReceiveDamage(this_object(), ACID, 2500, 0, who->GetTorso());
			break;
		}
	return 1;
}