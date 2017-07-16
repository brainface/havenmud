// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("robber");
   SetShort("a old grave robber");
   SetAdjectives( ({ "old","grave" }) );
   SetId( ({ "robber" }) );
   SetLong("Gnarled, calloused hands top off the muscular arms of "
           "this seedy, creepy human.  Keen eyes scrutinize his "
           "surroundings, and a crisscross of old scars mars his "
           "face and bare skin.  Wrinkles mix with the scars, "
           "forming a cacophonous collage.");
   SetGender("male");
   SetRace("human");
   SetClass("thief");
   SetSkill("knife combat",1,1);
   SetSkill("knife combat",1,1);
   SetLevel(14);
   SetInventory( ([
                    FOREST_OBJ + "painting" : 1,
//                    FOREST_OBJ + "leathergloves" : "wear gloves",
                    FOREST_OBJ + "greensock" : "wear green sock on right foot",
                    FOREST_OBJ + "bluesock" : "wear blue sock on left foot",
                    FOREST_OBJ + "tanboots" : "wear boots",
                    FOREST_OBJ + "knithat" : "wear hat",
                    FOREST_OBJ + "backpack" : "wear backpack",
                    FOREST_OBJ + "sharkknife" : "wield knife",
               ]) );
   SetCurrency("ducats",20);
   SetMorality(-800);
}
