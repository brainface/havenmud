/* Mepheus, scourge of the Arcanith Library
 *                                         
 * Holds a unique spell for warlocks and cloth
 *  wing armour for daemons                   
 */                                           

#include <lib.h>     
#include <std.h>     
#include <daemons.h> 
#include "../arc_library.h"
inherit LIB_NPC;           
inherit LIB_FEAR;          
                           
void PossibleAttack();     

static void create() {
  ::create();         
  SetKeyName("mepheus");
  SetRace("daemon");           
  SetClass("fighter");         
  SetClass("necromancer");     
  SetLevel(100);               
  SetGender("male");           
  SetShort("Mepheus, Holder of the Tome");
  SetId( ({ "Mepheus", "Holder", "Tome" }) );                         
  SetAdjectives( ({ "mepheus","holder","of","the" }) );               
  SetLong(                                                            
    "This horrible creature is Mepheus, Holder of the Tome; the legendary "
    "haunt of the old library kobold mothers use to scare their children. "
    "Old, dried blood cakes the tattered remnants of the archmage's robe he "
    "wears, and violet flames drip from his fiendish wings. "                
    "His demonic face is a distorted mix of rage and regret, and his eyes "  
    "burn with a madness that has been brewing for a long, long time."       
  );                                                                         
  SetAction(5, ({                                                            
    "!emote studies a tome intently.",                                       
    "!emote scribes a profane sigil along the wall.",                        
    "!emote mutters something obscene to himself.",                          
    "!emote angrily tears an old book to shreds.",                           
    "!speak Not enough, it's still not enough to change anything.",
    "!speak Betray him... I would never... why would I?",
    "!yell You can't have it! It's all I have left!",
    "!omg",
  }) );
  SetCombatAction(50, ({
    //cast my warlock spell
    "!cast vampiric touch",
    "!roar",
  }) );
  SetResistLevel(50);
  SetFearLength(10);
  SetFearType("profane aura");
  SetReligion("Saahagoth");
  SetTown("Durgoroth");
  SetMorality(-2000);
  SetInventory( ([
    ARC_LIBRARY_OBJ "shawl" : 2,
    ARC_LIBRARY_OBJ "tome" : "wield tome",
    ARC_LIBRARY_OBJ "robe" : "wear robe",
  ]) );
  SetCurrency("crystals", 2000);
  SetFirstCommands( ({
    "wear first shawl on right wing",
    "wear first shawl on left wing",
    "cast veil from beyond",
    "cast mesmer barrier",
    "cast veil from beyond",
    "cast mesmer barrier",
    "cast veil from beyond",
  }) );
}

