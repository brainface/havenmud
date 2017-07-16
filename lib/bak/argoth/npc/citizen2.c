#include <lib.h>
#include "../argoth.h"

inherit LIB_SENTIENT;

void DoSteal();

static void create() {
	sentient::create();
	SetKeyName("citizen");
	SetId( ({ "argoth citizen", "citizen" }) );
	SetShort("a citizen of Argoth");
	SetLong("This orc travels through Argoth, keeping an eye on his "
		"pockets, and on the pockets of others.");
    SetLevel(random(15)+10);
	SetRace("orc");
	SetClass("rogue");
	SetGender("male");
    SetInventory( ([
    ARGOTH_OBJ + "r_knife.c" : "wield knife",
]) );
	SetWander(22);
	SetAction(10, (: DoSteal :));
}

void DoSteal() {
   object array people = ({ });
   people = filter(all_inventory(environment(this_object())), (: playerp :));

   if(sizeof(people)) {
      int number = random(sizeof(people));
      string person = (people[number]->GetKeyName());
      eventForce("steal money from "+person);
   }
}
