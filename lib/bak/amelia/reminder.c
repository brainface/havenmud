#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("reminder");
   SetId( ({ "reminder" }) );
   SetShort("reminder");
   SetLong("GO BUY DUNE, moron.");
   SetMass(1);
   SetValue(20);
   SetDamagePoints(5000);
}

void init() {
   int i = 0;
   item::init();
   while(i < 100) {
   this_player()->eventPrint("%^BOLD%^%^RED%^G%^ORANGE%^O %^YELLOW%^B"
		"%^GREEN%^U%^CYAN%^Y %^BLUE%^D%^MAGENTA%^U%^RED%^N%^ORANGE%^E"
		"%^YELLOW%^!%^GREEN%^!%^CYAN%^!%^BLUE%^!%^MAGENTA%^!%^RESET%^");
   i++;
   }
}
