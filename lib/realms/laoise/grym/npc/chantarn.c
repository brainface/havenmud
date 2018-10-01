#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("Chantarn");
  SetShort("Chantarn, a Grymxorian merchant");
  SetId( ({
    "grymxorian merchant", "chantarn", "merchant",
  }) );
  SetLong(
    "Chantarn is a middle aged nosferatu. He has seen "
    "Grymxoria in its better days and might be willing to "
    "help others bring prosperity back to the city."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetTown("Grymxoria");
  SetClass("merchant");
  SetLevel(40);
  SetCurrency("bloodgems", 20000);
  SetUniqueSkills( ([
    "metal working" : 1,
    "melee attack" : 2,
    "melee defense" : 2,
    "mithril working" : 4,
    "armour smithing" : 1,
    "weapon smithing" : 4,
    "natural working" : 3,
    "leather working" : 3,
  ]) );
  SetPlayerTitles(  ([
    "newbie" : "the tax collector",
    "mortal" : "the Grymxorian Money Lender",
    "hm" : "the Exotic Importer",
    "legend" : "the Lord Merchant of Grymxoria",
    "avatar" : "the Warlord's Procurer",
    "fighter" : "the Grymxorian Caravanner",
    "rogue" : "the Grymxorian Pirate",
    "cleric" : "the Grymxorian Evangalist",
  ]) );
  SetFreeEquip( ([
    STD_FISHING + "pole" : 1,
    STD_KNIFE + "small_kife" : 1,
  ]) );
}
