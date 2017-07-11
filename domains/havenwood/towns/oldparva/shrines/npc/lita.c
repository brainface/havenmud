/*  Portia  1-5-99
    A cleric leader for Parva.
*/

#define SOIR_OBJ "/domains/havenwood/towns/parva/shrines/obj/"
#include <lib.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Lita");
  SetShort("Lita, the Priestess of Soirin");
  SetId( ({"lita", "priestess", "priestess of soirin"}) );
  SetLong("This beautiful woman radiates an aura of power. "
    "Her golden eyes shine with sparkles of greed and lust.");
  SetRace("human");
  SetGender("female");
  SetCurrency( ([
       "oros" : random(10000) + 50,
          ]) );
  SetTown("Parva");
  SetLevel(30);
  SetInventory( ([
    SOIR_OBJ + "cler_medallion" : "wear medallion",
    SOIR_OBJ + "elf_skirt" : "wear skirt",
    SOIR_OBJ + "elf_blouse" : "wear blouse",
    SOIR_OBJ + "elf_dagger" : "wield dagger",
         ]) );
  SetClass("priest");
  SetUniqueSkills( ([
     "evokation" : 1,
     "enchantment" : 1,
     "knife combat" : 1,
     "stealth" : 2,
     "knife combat" : 2,
     "multi-weapon" : 2,
     "pierce combat" : 2,
     "pierce combat" : 3,
     "fishing" : 3,
     "bargaining" : 3,
     "healing" : 4,
       ]) );
  SetSpellBook( ([
      "bless" : 100,
    "disperse protections" : 100,
    "create detox potion" : 100,
    "revive" : 100,
     "cloak of darkness" : 100,
      "blessed water" : 100,
      "divine mana" : 100,
      "flaming arrow" : 100,
      "dark embrace" : 100,
      "dark shroud" : 100,
      "dark arrow" : 100,
      "dim" : 100,
      "poison scent" : 100,
       ]) );
  SetCombatAction(18,
    ({
       "!cast dark arrow",
       "!cast dark shroud",
       "!cast dark embrace",
       "!cast flaming arrow",
      }) );
  SetReligion("Soirin","Soirin");
  SetPlayerTitles( ([
      "newbie" : "the Tempted",
      "mortal" : "the Wielder of the Black Rose",
      "hm"     : "the Divine Theorist of Avarice",
      "legend" : "the Zealous Preacher of Lust",
      "avatar" : "the Ravenous Hierophant",
      "merchant" : "the Merchant of Darkness",
      "barbarian" : "the Dark Warrior",
      "cavalier" : "the Protector of the Dark",
      "fighter" : "the Keeper of Darkness",
      "bard" : "the Messenger of Soirin",
       ]) );
  SetFreeEquip( ([
    SOIR_OBJ + "cleric_knife" : 1,
      ]) );
  }
