#include <lib.h>
#include <daemons.h>
#include "../../parva.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("garric");
  SetShort("Garric, Zeddicus' chosen");
  SetId( ({ "garric", "chosen" }) );
  SetLong("This is Garric, the head of the Thorian religion.  He stands 7 "
          "feet tall and unlike every other member of his race, he has "
          "hair.  It is jet black and combed back over his head.  Because "
          "of his preparations to become a Thorian religious head, and as "
          "a result of his death in Grymxoria and resurrection by Zeddicus, "
          "his body is covered by scars and he appears to be always quite "
          "unhappy.");
  SetRace("nosferatu");
  SetClass("priest");
  SetLevel(90);
  SetGender("male");
  SetMorality(-250);
  SetTown("Parva");
  SetUniqueSkills( ([
                    ]) );
  SetSkill("pole combat", 100, 1);
  SetSkill("pole combat", 195, 2);
  SetSpellBook( ([
                 "harm body" : 100,
                 "flaming arrow" : 100,
                 "bless" : 100,
                 "blessed water" : 100,
                 "divine mana" : 100,
                 "sanctify" : 100,
                 "protect" : 100,
                 "holy shield" : 100,
                 "undead pain" : 100,
                 "aura of terror" : 100,
                 "layer of spikes" : 100,
                 "disperse protections" : 100,
                 "create detox potion" : 100,
                 "pious obstructions" : 100,
                 "barrier of faith" : 100,
                 "divine field" : 100,
                 "shield of faith" : 100
                 ]) );
  SetCombatAction(20, ({
                       "!cast harm body",
                       "!cast aura of terror",
                       "!cast aura of terror",
                       "!cast mystical shield",
                       "!cast layer of spikes",
                       "!disarm",
                       "!disarm",
                       "!trip"
                       }) );
  SetInventory( ([
    PS_OBJ + "/thorian_staff" : "wield staff",
    "/std/clothing/pant/drab_pants" : "wear pants" ]) );
  SetReligion("Thorian", "Thorian");
  SetPlayerTitles( ([
                    "newbie" : "the Initiate Giver of Pain",
                    "mortal" : "the Giver of Pain",
                    "hm" : "the Agonizer",
                    "legend" : "the Master of Suffering",
                    "avatar" : "the Supreme Torturer",
                    "cavalier" : "the Paladin of Pain",
                    "fighter" : "the Tormentor",
                    "merchant" : "the Evil Financier",
                    "barbarian" : "the Sadistic Zealot"
                    ]) );
  SetFreeEquip( ([ "/std/weapon/pole/staff" : 1 ]) );
}
