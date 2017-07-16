/*  The Old Hag in the wierd room - Level #2 Caverns */

#include <lib.h>
#include "../caves.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("old hag");
  SetId( ({ "old hag", "hag", "old woman", "woman" }) );
  SetAdjectives( ({ "old", "feeble", "harmless" }) );
  SetShort("an old hag");

  SetLong("The old hag has stringy, knotted, steely grey hair.  She probably "
          "hasn't seen herself in the mirror in years, her face is smudged "
          "from life underground.  Not even to mention the effect that the "
          "chemicals she uses has on her.  Overall she seems quite feeble and "
          "harmless really.");

  SetRace("human");
  SetGender("female");
  SetClass("enchanter");
  SetLevel(10);
 
  SetMorality(200);
  SetDie("The old hag puts a curse upon you as she dies.");

  SetSpellBook( ([
    "capsule"    : 100,
    "ice ball"   : 100,
    "aura"       : 100,
    "missile"    : 100,
    ]) );

  SetAction(5, ({ "The Old Hag mixes together two liquids, which starts "
                  "bubbling and fizzing.  Then she sets it on a stand over an "
                  "open flame.",
                  "The Old Hag reads over a sheet of parchment, then flips "
                  "through a seemingly random book off of the bench and reads "
                  "a couple pages in it.",
                  "The Old Hag jots down some notes on a sheet of parchment.",
                  "The Old Hag goes over to another bench and takes a "
                  "bottle off of the flames and sets it aside to cool.",
  }) );

  SetCombatAction(60, ({ 
  	"!cast capsule",
    "!cast ice ball",
    "!cast aura",
    "!cast missile",
    "The Old Hag spits out a curse at you.",
  	}) );

  SetTalkResponses( ([
    ({ "liquids", "liquid", "glasswear" })  :
       "These are just my different experiments, I'm trying to find out the "
       "different properties of different liquids when mixed with others.  "
       "I've already made a couple of useful potions.",
    ({ "potions", "potion" })  :
       "Oh these are nothing really, one is a healing potion and the "
       "other is a poision.  The problem is that the process to make them is "
       "so close you can't tell which you have til it's too late!",
    ({ "symbols", "symbol", "wards", "ward" })  :
       "My symbols are special wards that watch over this room.  So one should "
       "be on their best behavior while here.",
    ({ "books", "book", "paper", "papers", "parchment" })  :
       "Oh these, all of these books and papers have my notes on how to make "
       "particular potions and poisons and the such.  Maybe I'll even try "
       "selling them someday.",
    ({ "benches", "bench", "workbenches", "workbench" })  :
       "An old woman needs a good sturdy workbench, doesn't everybody?!",
    ({ "caves", "cave", "caverns", "cavern", "chasm" })  :
       "Umm...  I don't know much about that sort of thing, a nice young man "
       "seemed to know about them, I'd go ask him if he's still around.  "
       "Last time he came to visit he said something about a bridge.",
    ({ "bridge builder", "builder", "bridge" })  :
       "I'm not sure where he is now, try to the south and west, that's where "
       "I think he said he was camped out at.",
  ]) );

  SetInventory( ([ 
  	OBJS + "/robe1" : "wear robe",
    OBJS + "/broom1" : "wield broom",
    OBJS + "/necklace1" : "wear necklace",
 	 	]) );
}
