// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("robber");
   SetShort("a young, dirty grave robber");
   SetAdjectives( ({ "young","dirty","grave" }) );
   SetId( ({ "robber" }) );
   SetLong("Streaks of dirt mark the face of this young grave robber.  "
           "His teeth are rotting away but his physique is strong and "
           "agile.");
   SetGender("male");
   SetRace("human");
   SetClass("thief");
   SetSkill("knife attack",1,1);
   SetSkill("knife defense",1,1);
   SetLevel(18);
   SetInventory( ([
                    FOREST_OBJ + "statue" : 1,
//                    FOREST_OBJ + "leathergloves" : "wear gloves",
//                    FOREST_OBJ + "blacksocks" : "wear socks",
                    FOREST_OBJ + "blackshoes" : "wear shoes",
                    FOREST_OBJ + "knithat" : "wear hat",
                    FOREST_OBJ + "blackpants" : "wear pants",
                    FOREST_OBJ + "blackknife" : "wield knife",
                    FOREST_OBJ + "backpack" : "wear backpack",
               ]) );
   SetCurrency("ducats",20);
   SetMorality(-700);
}
