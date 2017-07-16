#include <lib.h>
inherit LIB_NPC;

static void create() 
{
  npc::create();
  SetKeyName("gelfling");
  SetShort("a gelfling lumberjack");
  SetId( ({ "lumberjack","gelfling" }) );
  SetAdjectives( ({ "gelfling" }) );
  SetRace("gelfling");
  SetClass("barbarian");
  SetSkill("hack attack",15,1);
  SetLevel(10);
  SetCurrency("imperials",random(50)+15);
  SetMorality(75);
  SetReligion("Eclat","Eclatish");
  SetLong("This gelfling is a lumberjack.  He is dressed in flannel "
    "and lomg johns and wears a beard uncommon to his race.");
  SetGender("male");
  SetAction(8, ({
    "!emote swings his axe about cutting trees down.",
    "!emote mills about the trees.",
    "!emote walks about and surveys what to cut down next.",
  }) );
  SetInventory( ([
    "/domains/westwood/virtual/transit/wood_axe" : "wield axe",
  ]) );
}
