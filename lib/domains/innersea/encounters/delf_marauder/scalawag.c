#include <lib.h>        
#include <domains.h>    
#include <damage_types.h>
inherit LIB_PIRATE;      

static void create() {
  ::create();         
  SetRace("skaven");  
  SetGender("male");  
  SetClass("sailor"); 
  SetClass("fighter");
  SetSkill("enchantment",1,1);
  SetLevel(140);              
  SetKeyName("scalawag");     
  SetId( ({ "scalawag","skaven" }) );
  SetShort("a filthy scalawag");
  SetAdjectives( ({ "filthy", "skaven" }) );
  SetLong(
    "Filthy dark brown fur covers the scalawag's body, some small patches missing "
    "like it has fallen out or been pulled. Nicks mark up his ears and his "
    "yellowed teeth are jagged and crooked. Though slightly on the scrawny side "
    "he appears menacing."
  );
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/rigging_knife" : "wield knife",
    INNERSEA_ENCOUNTERS "obj/rat_pants" : "wear pants",
  ]) );
  SetCaptainAggressiveness(110);
  SetAction(5, ({
    "!laugh evilly",
    "!coughs up something vile.",
    "!twitches his tail.",
    "!scratches himself indiscreetly.",
  }) );
  SetResistance(ALL_ELEMENTS|MAGIC,"low");//cheeeeaaatting
  SetProperty("pirate", "pirate");
  SetShipWander(1);
  SetCurrency("rounds", 20000);
  SetReligion("Soirin");
  SetTown("Malveillant");

  SetMinLevel(200);
  SetMaxLevel(500);
  SetEncounterDifficulty(5);
}

