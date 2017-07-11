


#include <lib.h>
#include "../shrine.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

int eventBrowse();
int eventSell();
int eventPrice();

static void create() {
  ::create();
  SetKeyName("Mirogu");
  SetShort("Uto Mirogu, the Spiritual Medium");
  SetRace("human");
  SetReligion("taisoka");
  SetClass("contemplator");
  SetLevel(25);
  SetBaseLanguage("Tai");
  SetGender("male");
  SetMorality(250);
  SetId( ({ "uto", "mirogu", "medium", "cleric" }) );
  SetAdjectives( ({ "uto", "medium" }) );
  SetStorageRoom(SHRINE_ROOM "mirogu_store");
  SetLocalCurrency("koken");
  SetVendorType(VT_TREASURE);
  SetMaxSingleItem(1);
  SetMaxItems(1);
  SetLong("Uto Mirogu is the keeper of the Shrine of"
          " the Ancients. He is just the latest in a"
          " long line of Uto spiritual mediums, and as"
          " such, he has entered into the profession"
          " of settling unfinished business. One may"
          " <ask mirogu to buy token> if they have "
          " collected any.");
  SetAction(5, ({
       "!speak Surely this new flood of yurei is unusual!",
       "!speak Help the yurei to rest: vanquish them and"
       " bring me spirit tokens!",
       "!emote meditates.",
       "!speak Who can help these lost souls?",
       "!speak I will buy your spirit tokens",
    }) );
}


int eventBrowse() {
    eventForce("speak I'm sorry, I do not sell anything. But"
               " I will purchase spirit tokens from you.");
    return 1;
}

int eventSell() {
    eventForce("speak Come now. Be sensible. I do not sell"
               " anything");
    return 1;
}

int eventPrice() {
    eventForce("speak Come now. Be sensible. I do not sell"
               " anything. I purchase spirit tokens.");
    return 1;
}

mixed eventBuy(object who, object array obs) {
  foreach (object ob in obs) {
    if (base_name(ob) != SPIRIT_TOKEN_OBJ) {
      eventForce("speak I only buy spirit tokens.");
      return 1;
    }
  }
  return ::eventBuy(who, obs);
}