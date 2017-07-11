
/* a satyr
   Elasandria 4/19/98
*/

#include <lib.h>
#include <std.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("satyr");
  SetShort("a satyr");
  SetId( ({"satyr","reveler"}) );
  SetAdjectives( ({"musical","pleasure loving"}) );
  SetLong("Like all members of his race, this satyr is a pleasure loving, "
         "musical reveler of the forest.  He has the upper body of a human and "
         "the hind legs of a goat. Two sharp horns poke through his coarse, "
         "curly black hair. His beard is wild and dark black eyes survey the "
         "forest in search of females. ");
  SetGender("male");
  SetRace("satyr");
  SetClass("bard");
  SetLevel(10);
  SetSongBook( ([
         "protective note"    : 75,
         "song of sorrow"     : 75,
         ]) );
  SetAction(5, ({
  	 		 "!emote looks you over drunkenly.",
         "!emote plays his fife and dances around merrily.",
         "!sing protective note",
         }) );
  SetCombatAction(75, ({
         "!sing protective note",
         "!sing song of sorrow",
         }) );         
  SetInventory( ([
  	 STD_INSTRUMENTS + "fife" : 1,	   
     ]) );
}
