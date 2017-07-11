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
    SetGender("male");
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
    // mahkefel jan 2011: he almost always goes right to
    // combat and never says anything, so i copied his setactions to
    // setcombatactions. Also made him wear his rings.
    SetCombatAction(5, ({
     "!scream",
     "!say How dare you come here!",
     "!say Let me rest in peace!",
    }) );
    SetFirstCommands( ({
      "wear first ring on right hand",
      "wear first ring on left hand",
    }) );
}

