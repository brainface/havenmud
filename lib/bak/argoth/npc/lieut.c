#include <lib.h>
#include "../argoth.h"
inherit LIB_NPC;
static void create() {
    npc::create();
   SetKeyName("lieutenant");
    SetId( ({ "an orc lieutenant", "lieutenant", "orc" }) );
    SetShort("an orc lieutenant");
    SetLong("This lieutenant of the orcish horde has risen up through the "
    "ranks by way of valor, skill in battle, and, most likely, stabbing "
    "his commander in the back while he wasn't looking.  He looks rather "
    "uneasy");
    SetRace("orc");
    SetGender("male");
    SetLevel(23);
    SetClass("fighter");
    SetInventory( ([
    ARGOTH_OBJ + "helm.c" : "wear helm",
    ]) );

}
