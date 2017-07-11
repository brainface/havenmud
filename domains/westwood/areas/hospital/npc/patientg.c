#include <lib.h>
#include <damage_types.h>
#include <std.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetMorality(10);
   SetProperty("noleavehospital",1);
   switch(random(6)) {
      case 0:
      SetRace("muezzin");
      SetReligion("Eclat","Eclatish");
      break;
      case 1:
      SetRace("halfling");
      break;
      case 2:
      SetRace("elf");
      break;
      case 3:
      SetRace("gelfling");
      break;
      case 4:
      SetRace("halfling");
      break;
      case 5:
      SetRace("dwarf");
      break;
   }
   switch(random(2)) {
      case 0:
      SetGender("female");
      break;
      case 1:
      SetGender("male");
      break;
   }
   SetClass("rogue");
   
   SetLevel(4+random(4));
   AddHealthPoints(-(GetHealthPoints()/3));
   SetKeyName("patient");
   SetShort("a patient of the oiskai flu");
   SetId( ({ "patient","sickness" }) );
   SetAdjectives( ({ "of","the","oiskai","flu","sick","ill" }) );
   SetLong("The patient has been ill for some time now, and only "
           "hopes to be able to recover from the deadly "
           "oiskai flu.  The patient had not had a very "
           "long life before recieving the disease, and looks "
           "at those around for prayers.");
   SetInventory( ([
                    STD_GERMS + "/oiskai_flu" : 1,
               ]) );
}

