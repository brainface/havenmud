// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_NPC;

void DoSteal();

static void create() {
	npc::create();
	SetKeyName("citizen");
	SetId( ({ "citizen", "karak_wander", "orc" }) );
	SetAdjectives( ({ "karak" }) );
	SetShort("a citizen of Karak");
	SetLong(
	  "This orc is an average-appearing citizen of Karak. He is plainly "
	  "dressed and normally is found walking the streets, apparently about "
	  "his own business. Unlike most orcs, he carries a knife rather than "
	  "an axe. As he walks, he keeps a careful eye on those around him."
  );
	SetRace("orc");
	SetGender("male");
  SetClass("rogue");
  SetLevel(random(15)+10);
  SetReligion("Saahagoth");
  SetMorality(-100);
  SetInventory( ([
    KARAK_OBJ + "r_knife" : "wield knife",
    STD_CLOTHING + "lg_shirt" : "wear shirt",
    STD_CLOTHING + "lg_shoes" : "wear shoes",
    STD_CLOTHING + "lg_pants" : "wear pants",
  ]) );
	SetWander(22);
	SetAction(10, (: DoSteal :));
}

void DoSteal() {
  object array people = ({ });
  people = filter(all_inventory(environment(this_object())), (: playerp :));
  foreach(string person in people) {
    if (person->GetTown() == "Karak") people -= ({ person });
    }  
  if(sizeof(people)) {
    int number = random(sizeof(people));
    string person = (people[number]->GetKeyName());
    eventForce("steal money from "+person);
  }
}
