// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("hunter");
   SetShort("a courageous hunter");
   SetId( ({ "hunter" }) );
   SetAdjectives( ({ "courageous" }) );
   SetLong("Thick, wirey brown hair covers this hunter's head, with a "
           "dark beard covering his face.  Dirt hides under the fingernails "
           "of his large, calloused hands.  His countenance suggests a man "
           "who drinks too often and snores too load.");
   SetGender("male");
   SetRace("human");
   SetClass("fighter");
   SetLevel(10);
   SetCurrency("ducats",20);
   switch(random(3)) {
      case 0:
   SetInventory( ([
                    FOREST_OBJ + "huntersword" : "wield sword",
                    FOREST_OBJ + "hunterknife" : "wield knife",
                    FOREST_OBJ + "hunterboots" : "wear boots",
                    AVERATH_OBJ + "beer" : 1,
               ]) );
      break;
      case 1:
   SetInventory( ([
                    FOREST_OBJ + "huntersword" : "wield sword",
                    FOREST_OBJ + "hunterknife" : "wield knife",
                    FOREST_OBJ + "hunterpants" : "wear pants",
                    FOREST_OBJ + "hunterbelt" : "wear belt",
               ]) );
      break;
      case 2:
   SetInventory( ([
                    FOREST_OBJ + "huntersword" : "wield sword",
                    FOREST_OBJ + "hunterknife" : "wield knife",
                    FOREST_OBJ + "hunterjerkin" : "wear jerkin",
                    FOREST_OBJ + "huntercap" : "wear hat",
               ]) );
      break;
   }
   SetAction(1, ({ "!emote crouches low and peers deep into the forest.",
                   "!emote examines the edge of his blade.",
                   "!emote grins evilly." }) );
   SetCombatAction(1, ({ "!say Idiot!  You should never have attacked me!",
                         "!say Get away, scum!","!say You're scaring away "
                         "the animals with this ruckus!" }) );
   SetMorality(-100);
}
