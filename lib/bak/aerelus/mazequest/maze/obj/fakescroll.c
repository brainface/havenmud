#include <lib.h>
inherit LIB_ITEM;

static void create() 
{
  item::create();
  SetKeyName("fakescroll");
  SetId( ({ "scroll" }) );  
  SetShort("a scroll");
  
  SetLong("This is a coiled piece of parchment with Arcane looking words on it."); 
  SetMass(1);
  SetRead("default", "");
}

varargs mixed eventRead(object who, string str) 
{
  who->eventPrint("The words on the scroll %^RED%^glow red %^RESET%^as the full force of its magic "
    "is unleashed directly at your face!");
  who->SetParalyzed(100);
  who->SetBlind(150);
  who->AddBleeding(50);  
  return 1;
}
 
