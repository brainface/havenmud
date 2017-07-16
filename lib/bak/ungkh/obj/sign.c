#include <lib.h>
inherit LIB_ITEM;

string DaRead();

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("A LARGE WARNING SIGN");
   SetId( ({ "sign" }) );
   SetAdjectives( ({ "large", "warning"}) );
   SetLong("%^RED%^"
           "OOC : THE NPC IN THIS ROOM IS INTENDED FOR MATURE "
           "AUDIENCES ONLY.  IF YOU HAVE PROBLEMS WITH SEXUAL "
           "MATERIAL PLEASE EXIT THIS HUT.  OTHERWISE YOU MAY "
           "'ASK ARIA TO GIVE SEX' AND SEE WHAT HAPPENS."
           "%^RESET%^");
   SetMaterial( ({ "wood" }) );
   SetPreventGet("The sign is firmly entrenched in the ground.");
   SetRead("%^RED%^"
           "OOC : THE NPC IN THIS ROOM IS INTENDED FOR MATURE "
           "AUDIENCES ONLY.  IF YOU HAVE PROBLEMS WITH SEXUAL "
           "MATERIAL PLEASE EXIT THIS HUT.  OTHERWISE YOU MAY "
           "'ASK ARIA TO GIVE SEX' AND SEE WHAT HAPPENS."
           "%^RESET%^");
  }
