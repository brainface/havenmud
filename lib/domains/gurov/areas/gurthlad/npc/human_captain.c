/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
#include "../gurthlad.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("captain");
    
    SetId( ({ "human", "captain", "human captain" }) );
    SetShort("a human captain");
    SetLong("A tall, muscular, stern looking human captain. He looks like "
      	"he is very experienced and violence is nothing new to him.");
    SetRace("human");
    SetClass("fighter");
    SetLevel(9);
    SetMorality(75);
    SetGender("male");
    SetAction(2, ({ 
    		"!speak Tomorrow we will march untill we get out of this wasteland.",
				"!speak What the devil are you doing here!?! GET OUT!",
				"!speak Keep alert men, the orcs could be out there anywhere." }) );
    SetCombatAction(10, ({
    		"!speak Attack men! ATTACK!",
				"!speak you will feel the cold steel of my blade against your throat "
				"afor long!"}) );
    SetInventory( ([ 
    		G_OBJ + "/fine_sword" : "wield sword in right hand",
				G_OBJ + "/studded_leather" : "wear armour" 
				]) );

    SetCurrency("imperials", 35);
}
