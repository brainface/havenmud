#include <lib.h>
inherit LIB_ITEM;
 
 
static void create() {
   item::create();
   SetShort("a colorful sign");
   SetLong(
     "Regular Colors:\n"
     "%^BLACK%^black%^RESET%^     : %^RED%^red%^RESET%^\n"
     "%^BLUE%^blue%^RESET%^       : %^CYAN%^cyan%^RESET%^\n"
     "%^MAGENTA%^magenta%^RESET%^ : %^ORANGE%^orange%^RESET%^\n"
     "%^YELLOW%^yellow%^RESET%^   : %^GREEN%^green%^RESET%^\n"
     "%^WHITE%^white%^RESET%^     : NO COLOR\n"
     "\n"
     "BOLD Colors:\n"
     "%^BOLD%^BLACK%^black%^RESET%^     : %^BOLD%^RED%^red%^RESET%^\n"
     "%^BOLD%^BLUE%^blue%^RESET%^       : %^BOLD%^CYAN%^cyan%^RESET%^\n"
     "%^BOLD%^MAGENTA%^magenta%^RESET%^ : %^BOLD%^ORANGE%^orange%^RESET%^\n"
     "%^BOLD%^YELLOW%^yellow%^RESET%^   : %^BOLD%^GREEN%^green%^RESET%^\n"
     "%^BOLD%^WHITE%^white%^RESET%^     : %^BOLD%^NO COLOR%^RESET%^\n"
     "\n"
     "Background Colors:\n"
     "%^B_BLACK%^black%^RESET%^     : %^B_RED%^red%^RESET%^\n"
     "%^B_BLUE%^blue%^RESET%^       : %^B_CYAN%^cyan%^RESET%^\n"
     "%^B_MAGENTA%^magenta%^RESET%^ : %^B_ORANGE%^orange%^RESET%^\n"
     "%^B_YELLOW%^yellow%^RESET%^   : %^B_GREEN%^green%^RESET%^\n"
     "%^B_WHITE%^white%^RESET%^     : NO COLOR\n"
     "\n" 
     "Extra Triggers\n"
     "(RESET must be used):\n"
     "%^FLASH%^flash%^RESET%^\n"
   );
   SetRead("default",GetLong());
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "colorful" }) );
   SetKeyName("sign");
   SetPreventGet("The sign post is imbedded too deep in the ground to get "
                 "it out.");
}

