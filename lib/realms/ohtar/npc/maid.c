#include <lib.h>
#include <std.h>
inherit LIB_BARKEEP;

static void create() {
    barkeep::create();
    SetKeyName("galad");
    SetId( ({ "maid", "ohtars maid", "galad", }) );
    SetShort("Galad, Ohtar's Maid");
    SetLong("This well dressed long legged, blond hair young lady seems very excited "
       "to see you. Her beautiful green eyes gaze around the room ever so sharply "
       "looking for anything dirty or out of place. However she always seems to "
       "stay away from the desk against the back wall.");
    SetClass("dancer");    
    SetLevel(250+random(5));
    SetRace("human");
    SetGender("female");
    SetMorality(1500);
    SetSkill("conjuring", 500 ,1);
    SetSkill("evokation", 500 , 1);
    SetSkill("pole attack", 500 ,1);
  SetSpellBook ( ([
      "aetheric rift" : 100,
   ]) );
  SetSongBook( ([
      "star strike" : 100,
   ]) );
  SetCombatAction(9, ({
    "!cast aetheric rift",
    "!cast aetheric rift",
    "!sing star strike",
    "!yell Its time to dust you!",
    "!sing star strike",
    }) );
    SetAction(1, ({ "!glance", "!say Would anyone like a drink or maybe a steak?
"}));
    SetCurrency("dinar", random(100000000)+30);
    SetDie("!say I've been dusted!");
  SetInventory( ([
        "/realms/ohtar/obj/clothing/maid_dress" : "wear dress",
        "/realms/ohtar/obj/weapons/feathermop" : "wield mop",
       "/realms/ohtar/obj/clothing/highheel" : "wear heels",
       "/realms/ohtar/obj/clothing/maidhat" : "wear hat",
   ]) );
  SetMenuItems( ([
    "steak" : STD_MEAL + "/food/steak",
    "beer" : STD_MEAL + "/beer",
 ]) );

}





