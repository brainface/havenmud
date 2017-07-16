#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("Chantarn");
  SetShort("Chantarn, a Grymxorian merchant");
  SetId( ({
    "grymxorian merchant",
    "chantarn",
    "merchant",
  }) );
  SetLong(
    "Chantarn is a middle aged nosferatu. He has seen "
    "Grymxoria in it's better days and might be willing to "
    "help others bring prosperity back to the city."
  );
  SetRace("nosferatu");
  SetClass("merchant");
  SetLevel(40);
    
  SetGender("male");
  SetTown("Grymxoria");
  SetMorality(-1000);
  SetCurrency("bloodgems", 20000);  
  SetUniqueSkills(  ([
    "metal working" : 1,
    "melee combat" : 2,
    "mithril working" : 4,
    "armour smithing" : 1,
    "weapon smithing" : 4,
    "natural working" : 3,
    "leather working" : 3,
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the tax collector", 
    "mortal" : "the Grymxorian Money Lender", 
    "hm" : "the Exotic Importer", 
    "legend" : "the Master of Commerce", 
    "avatar" : "the Warlord's Procurer", 
    "fighter" : "the Grymxorian Caravanner", 
    "cleric" : "the Evangalist of the Dark Goddess", 
  ]) );
  SetFreeEquip( ([
    STD_FISHING + "pole" : 1,
    STD_KNIFE + "small_kife" : 1,
  ]) );
}
