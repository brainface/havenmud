/* EnjilCode */


#include <lib.h>
#include "../ungkh.h"
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
  vendor::create();

  SetKeyName("lizaria");
  SetAdjectives( ({
    "scaly","strong"
    }) );
  SetId( ({
    "lizardman","armourer",
    }) );

  SetShort("Lizaria, the armourer");
  SetLong("Strong and well built, Lizaria stands tall and fierce.  "
          "Her creations are metal examples of herself.  Strong and "
          "long lasting.  She is constantly hammering armour "
          "together.");

  SetRace("lizardman");
  SetClass("merchant");

  SetLevel(47);
  SetSkill("armour smithing",1,65);
  SetSkill("blunt attack",1,64);
  SetSkill("bargaining",1,52);

  SetGender("female");

  RemoveLanguage("Gobyshkin");
  SetLanguage("Uruk",100,1);

  SetInventory( ([
    U_OBJ + "liz_mallet" : "wield mallet",
    U_OBJ + "liz_outfit" : "wear outfit",
    ]) );

  SetLocalCurrency("skins");
  SetStorageRoom(U_ROOM + "lizaria_store");
  SetMaxItems(65);
  SetVendorType(VT_WEAPON | VT_ARMOUR);

  SetAction(1, ({"!emote pounds some metal into submission.",
                 "!emote cools off.",
                 "!say why it always so hot in here!",
                }) );

  SetDie("Lizaria screams and falls into the stream.");
  SetMorality(-250);

}
