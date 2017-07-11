// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("fisherwoman");
   SetShort("a fisherwoman");
   SetId( ({ "woman","fisher","fisherwoman" }) );
   SetAdjectives( ({ "woman","fisher" }) );
   SetLong("Gnarled hands, roughened up from decades of catching, "
           "gutting, and cooking fish, top off the strong, muscular "
           "arms of this fisherwoman.");
   SetGender("female");
   SetRace("human");
   SetSkill("knife combat",1,1);
   SetSkill("knife combat",1,1);
   SetLevel(15);
   SetInventory( ([
                    FOREST_OBJ + "beltpouch" : "wear belt",
                    FOREST_OBJ + "knithat" : "wear hat",
                    FOREST_OBJ + "knitglove" : "wear glove on left hand",
                    FOREST_OBJ + "knitglove1" : "wear glove on right hand",
                    FOREST_OBJ + "greenskirt" : "wear skirt",
                    FOREST_OBJ + "greenjacket" : "wear jacket",
                    FOREST_OBJ + "fishingpole" : 1,
                    FOREST_OBJ + "hunterknife" : "wield knife in left hand",
               ]) );
   SetCurrency("ducats",30);
}
