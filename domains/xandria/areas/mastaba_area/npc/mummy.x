//Selket@Haven
//2006
#include <lib.h>
#include "../mastaba.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("mummy");
    SetInventory( ([
        MASTABA_OBJ "mummy_ring" : 2,
        MASTABA_OBJ "bandages" : "wear bandages",
        MASTABA_OBJ "axe" : "wield axe",
      ]) );
    SetRace("gnoll", "skeleton");
    SetShort("a mummy");
    SetUndead(1);
    SetId( ({ "skeleton", "mummy" }) );
    SetAdjectives( ({ "dead" }) );
    SetClass("fighter");
    SetLevel(random(20)+50);
    SetEncounter(100);
    SetBaseLanguage("Rehshai");
    SetLong("This mummy seems to be held together by the bandages "
      "he is swathed in. His eyes seem to burn hatefully into your "
      "soul.");
    SetMorality(-500);
    SetDie("The mummy disintegrates into dust.");
    SetNoCorpse(1);
    SetAction(5, ({
     "!scream",
     "!say How dare you come here!",
     "!say Let me rest in peace!",
    }) );
}
