//Selket@Haven
//2006
#include <lib.h>
#include <std.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("cosmetic maker");
  SetShort("a cosmetic maker");
  SetId( ({ "maker" }) );
  SetAdjectives( ({ "cosmetic" }) );
  SetLong(
    "This cosmetic maker journeys to the shores of Lake Rantera "
    "to dig out clay ochre and plants she mixes into cosmetics "
    "for the fair ladies of Lisht. Her hands are stained with "
    "pigments and her face is ghastily overdone, as she feels "
    "she must experiment with all her products.");
  SetClass("rogue");
  SetLevel(10);
  SetGender("female");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       STD_WEAPON "knife/stiletto" : "wield knife",
       LAKE_OBJ + "dress" : "wear dress",
         ]) );
  SetAction(6, ({
    "!say Don't you think I'm pretty?",
    "!emote rubs at her overly made up face.",
  }) );
}
