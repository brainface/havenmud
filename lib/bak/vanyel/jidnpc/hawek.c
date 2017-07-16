/* Hawek -- Ranger Leader
 * Dylanthalus@Haven
 */
#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetReligion("Magildan","Magildan");
  SetShort("Hawek, the Lord of Jidoor's Forests");
  SetKeyName("hawek");
  SetId( ({"hawek","ranger"}) );
  SetLong("Hawek is a young and energetic sprite, who seems "
          "filled with a love of nature.  He looks capable of "
          "defending himself but looks quite friendly.");
  SetRace("sprite");
  SetTown("Jidoor");  
  SetClass("ranger");
  SetGender("male");
  SetLevel(50);
SetTaughtSpheres( ({"natural","natural evokation", "natural enchantment", "natural healing"}) );
  SetSpellBook( ([
/*01*/    "cleanse flesh" : 100,
/*02*/    "regrowth" : 100,
/*03*/    "invigorate" : 100,
/*04*/    "tend wounds" : 100,
/*05*/    "condense air" : 100,
/*06*/    "feast" : 100,
/*07*/    "heat" : 100,
/*08*/    "lunar blast" : 100,
/*09*/    "plant strike" : 100,
/*10*/    "summon animal" : 100,                        
/*11*/    "enhanced natural shield" : 100,
/*12*/    "freeze" : 100,
/*13*/    "hydrate" : 100,
/*14*/    "natural shield" : 100,
/*15*/    "tangle" : 100,
/*16*/    "solar blast" : 100,
/*17*/
/*18*/
/*19*/
/*20*/
              ]) );
  SetAction(1, ({
    "!say So are you interested becoming a ranger?",
    "!emote smiles at you.",
    }) );
  SetPlayerTitles( ([
     "newbie" : "the Forester of Jidoor ",
     "mortal" : "the Ranger of Jidoor",
     "hm" : "the Grand Ranger of Jidoor",
     "legend" : "the Lord of Jidoor's Forests",
     "avatar" : "the Protector of Nature",
     ]) );
   SetFreeEquip( ([ 
      STD_PROJECTILE + "bow_long_newbie" : 1,
   ]) );    
   SetInventory( ([ 
      STD_PROJECTILE + "long_bow" : "wield bow",
      STD_CLOTHING + "pant/brown_pants" : "wear pants",
      STD_CLOTHING + "shirt/brown_shirt" : "wear shirt",      
      STD_CLOTHING + "boot/high_boots.c" : "wear boots",
   ]) );
  }
