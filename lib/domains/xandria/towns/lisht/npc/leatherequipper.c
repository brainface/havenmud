//Illura@Haven
//Leather Equipper
#include <lib.h>
#include <std.h>
#include "/domains/southern_coast/areas/leatherstore/store.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Khepri");
   SetId( ({ "Khepri", "equipper" }) );
   SetShort("Khepri the Unselfish One");   
   SetAdjectives("unselfish");
   SetLong(
      "Khepri, dour-faced but fair, is charged with giving out "
      "tired, used items to those in need. His permanent "
      "scowl seems to stem from the fact that his is a government "
      "appointed position and title, and he does not seem "
      "overly generous by nature."
   );              
   SetRace("gnoll");
   SetGender("male");
   SetBaseLanguage("rehshai");      
   SetMorality(-200);
   SetClass("fighter");
   SetLevel(10);
   SetFreeEquipment( ([
     "vest" : STORE_DIR + "oldvest",
      "torch" : STD_LIGHT + "torch",
     "pants" : STORE_DIR + "oldpants",
     "boots" : STORE_DIR + "oldboots",
     "glove" : STORE_DIR + "oldglove",
     "helmet" : STORE_DIR + "oldhelmet",     
   ]) );
   SetLevelLimit(10);   
   SetAction(1, ({ "!say Free equipment for those needing it..." }) );    
}

