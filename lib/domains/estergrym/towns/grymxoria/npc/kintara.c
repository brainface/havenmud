#include <lib.h>
#include "../grymxoria.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create()

{
  vendor::create();
  SetKeyName("kintara");
  SetShort("Kintara Axegrinder, the shopkeep");
  SetLong(
    "Kintara is the owner and proprietor of this business "
    "establishment. It is also rumored that she is one of "
    "Gunthar's generals. It would probably be best to "
    "conduct one's busines with her quickly."
  );
	
	SetRace("nosferatu");   
  SetGender("female");  
  SetClass("fighter");
  SetSkill("bargaining",1,1);
  SetSkill("melee combat",1,1);
  SetLevel(26);
  
  SetMorality(-2000);
  SetTown("Grymxoria"); 
  SetVendorType(VT_ALL);
  SetLocalCurrency("bloodgems");
  SetStorageRoom(G_ROOM + "sr_kintara");
  SetMaxSingleItem(12);
}
