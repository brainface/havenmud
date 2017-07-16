#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("bloody crypt");
   SetId( ({ "bloody crypt","crypt" }) );
   SetShort("a bloody crypt");
   SetLong("The crypt is covered with maggots and his "
           "flesh is rotting away.  Spiders crawl "
           "in and out of his eyes.");
   SetLevel(5);
   SetRace("wraith");
   SetClass("valkyr");
   SetGender("male");
}
