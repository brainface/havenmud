#include <lib.h>
#include <std.h>
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Nuris");
   SetId( ({ "nuris" }) );
   SetShort("Nuris the Deranged");   
   SetLong(
     "Nuris is a black haired brown skinned dark dwarf.  He has a twinkle "
     "in his eye but his eyes do not look straight ahead.  Nuris has a "
     "large noticable scar across his forehead which goes deep under his "
     "hair.  Nuris is known to hand out pieces of armour if you ask him "
     "for help.  He is known to help the young of Dalnairn.");              
   SetRace("dark-dwarf");
   SetGender("male");
   SetMorality(900);
   SetClass("fighter");
   SetLevel(10);      
   SetFreeEquipment( ([
     "vest"   : STD_ARMOUR "free_armour/small/oldvest",
     "pants"  : STD_ARMOUR "free_armour/small/oldpants",
     "boots"  : STD_ARMOUR "free_armour/small/oldboots",
     "glove"  : STD_ARMOUR "free_armour/small/oldglove",
     "helmet" : STD_ARMOUR "free_armour/small/oldhelmet",     
   ]) );
   SetLevelLimit(10);   
   SetAction(1, ({ 
   	 "!say Where am I?",
   	 "!quirk",
   	 "!yell Why does my head hurt?",
   	 }) );    
}
