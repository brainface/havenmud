#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("mother");
   SetShort("a farmer mother");
   SetId( ({ "farmer mother","mother","farmer" }) );
   SetLong("The mother looks happily busy here in the kitchen.");
   SetRace("human");
   SetClass("fighter");
   SetGender("female");
   SetLevel(10);
   SetInventory( ([
                    "/std/weapon/blunt/copper_club" : "wield club",
               ]) );
   SetCurrency("imperials",200+random(50));
}