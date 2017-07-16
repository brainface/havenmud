#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("undead");
   SetShort("some undead idiot");
   SetId( ({ "idiot" }) );
   SetAdjectives( ({ "undead" }) );
   SetLong("It's an undead idiot (duh).");
   SetGender("male");
   SetClass("rogue");
   SetLevel(1);
   SetRace("human");
   SetUndead(1);
   SetNoCorpse(1);
   SetCorpseItems( ([
                      "/realms/amelia/obj/cookieg" : 5,
                 ]) );
}

