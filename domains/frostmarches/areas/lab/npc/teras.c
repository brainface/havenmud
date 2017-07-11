/* added spells 
   Zalbar 7-08
 */


#include <lib.h>
#include "../path.h"

inherit LIB_SENTIENT;

static void create()
{
::create();
  SetKeyName( "Teras" );
  SetId( ({ "teras", "alchemist" }) );
  SetShort( "Teras, the alchemist" );
  SetLong( "Teras' eyes are alert and constantly dart about her as if "
           "years of persecution have made her suspicious of her "
           "surroundings.  Yet, she stands upright with a majesty and "
           "independence with which it seems she can defy all naysayers "
           "for the sake of her science." );
  SetRace( "dwarf" );
  SetClass( "druid" );
  SetLimit(1);
  SetGender( "female" );
  SetLevel( 25 );
  SetMorality( 0 );
  SetTalkResponses( ([ "teras" : "Yes, I am Teras.  Do not disturb me.",
                       "alchemy" : "Alchemy is a science in the same "
                                   "right as magic!" ]));
  SetAction( 6, ({ "Teras mixes some chemicals together.",
                    "Teras mutters to herself in a strange tongue.",
                    "Teras paces back and forth." }) );
  SetSpellBook( ([
  	"terra" 			 : 100,
  	"natural veil" : 100,
  	]) );
  SetCombatAction( 40, ({
  	"!cast terra",
  	"!cast natural veil",
  	}) );  	
  SetWander( 32 );
  SetInventory( ([
    L_OBJ "/ebony_staff" : "wield staff",
    L_OBJ "/cloak" : "wear cloak",
    L_OBJ "/amulet" : "wear amulet",
    L_OBJ "/sandals" : "wear sandals",
    L_OBJ "/belt" : "wear belt",
  ]) );
  SetDie("As Teras is about to die, she mumbles some words in a strange "
         "language, and her body begins to slowly fade away.");
  SetNoCorpse(1);
  SetProperty("lab_wander", 1);
}
