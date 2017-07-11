#include <lib.h>
#include <std.h>
#include "../yozrath.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Hanifa");
   SetId( ({ "hanifa" }) );
   SetShort("Hanifa, the Dutiful Wife");   
   SetLong(
     "Hanifa is a young woman of Yozrath giving hand outs "
     "to those young and inexperienced citizens of Yozrath.  This "
     "dutiful wife of Zalfaqar stand by her husband doing his will "
     "and the will of He Who Judges." );              
   SetRace("human");
   SetGender("female");
   SetBaseLanguage("Padashi");      
   SetMorality(900);
   SetClass("rogue");
   SetLevel(10);      
   SetFreeEquipment( ([
     "vest"   : STD_ARMOUR "free_armour/medium/oldvest",
     "pants"  : STD_ARMOUR "free_armour/medium/oldpants",
     "boots"  : STD_ARMOUR "free_armour/medium/oldboots",
     "glove"  : STD_ARMOUR "free_armour/medium/oldglove",
     "helmet" : STD_ARMOUR "free_armour/medium/oldhelmet",     
   ]) );
   SetLevelLimit(10);   
   SetInventory( ([
    YOZRATH_OBJ "abaja"  : "wear abaja",
    ]) );
   SetAction(1, ({ "!say I have a few spare pieces of armour." }) );    
}
