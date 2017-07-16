#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;

 static void create() {
  ::create();
  SetKeyName("tissue");

  switch(random(6)) {
    case 0:
      SetId( ({ "vampony tissue", "tissue", "vampire pony tissue", "pony tissue" }) );
      SetShort("a %^RED%^%^BOLD%^vampire pony%^RESET%^ tissue");
      SetLong("This tissue has a long-toothed %^RED%^BOLD%^vampire pony%^RESET%^ "
        "embroidered on it! Spooky!");
      break;
    case 1:
      SetId( ({ "green tissue", "tissue" }) );
      SetShort("a %^GREEN%^%^BOLD%^green%^RESET%^ tissue");
      SetLong("This is a simple %^GREEN%^BOLD%^green%^RESET%^ tissue.");
      break;
    case 2:
      SetId( ({ "blue tissue", "tissue" }) );
      SetShort("a %^BLUE%^%^BOLD%^blue%^RESET%^ tissue");
      SetLong("This is a simple %^BLUE%^BOLD%^blue%^RESET%^ tissue.");
      break;
    case 3:
      SetId( ({ "happy face tissue", "tissue", "happy tissue", "face tissue" }) );
      SetShort("a %^YELLOW%^happy face%^RESET%^ tissue");
      SetLong("This tissue has a big %^YELLOW%^happy face%^RESET%^ "
        "embroidered on it!");
      break;
    case 4:
      SetId( ({ "sparkly tissue", "tissue" }) );
      SetShort("a %^BOLD%^s%^YELLOW%^p%^RESET%^BOLD%^a%^YELLOW%^r%^RESET%^BOLD%^k%^YELLOW%^l%^RESET%^%^BOLD%^y%^RESET%^ tissue");
      SetLong("This tissue is %^BOLD%^s%^YELLOW%^p%^RESET%^BOLD%^a%^YELLOW%^r%^RESET%^%^BOLD%^k%^YELLOW%^"
        "l%^RESET%^BOLD%^y%^RESET%^ and %^BOLD%^glimmers%^RESET%^ in the light!");
      break;
    default:
      SetId( ({ "tissue" }) );
      SetShort("a plain white tissue");
      SetLong("This is a simple plain white tissue.");
      break;
    }
  SetMass(0);
}
