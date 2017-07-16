//Proximo@Pax Imperialis


#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include "../sulumus.h"

inherit LIB_NEWVENDOR;

static void create() {
  ::create();
  SetKeyName("young man");
  SetId( ({ "man" }) );
  SetAdjectives( ({ "adventurous", "young" }) );
  SetShort("an adventurous young man");
  SetLong(
     "This young fellow is a person who has taken himself away from the simple "
     "pleasures of a humble life to seek out new places and thrills by traveling "
     "far and wide. He walks like a swagger and talks like a haggler, always "
     "making sure he understands both sides of every conversation. He looks "
     "to have seen much and traveled far, but still has that sparkle in his "
      "eye seeking for new adventures. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetGender("male");
  SetMorality(55);
  SetClass("fighter");
  SetSkill("melee combat", 1, 2);
  SetSkill("bargaining", 1, 3);
  SetSkill("fishing", 1, 3);
  SetInventory( ([
  	"/std/weapon/slash/sword" : 1,
  	"/std/weapon/sword"       : 1,
  	]) );
  SetLevel(5 + random(12));
  SetLimit(10);
  SetWander(1);
  SetWanderSpeed(1 + random(3));
  SetFirstCommands( ({
  	"wield swords",
    }) );
}
