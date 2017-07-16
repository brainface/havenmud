#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("corpser");
   SetShort("a corpser");
   SetId( ({ "corpser","c" }) );
   SetLong("It's a corpser, k?");
}

void init() {
   ::init();
   add_action("corpser","corpser");
}

int corpser(string blah) {
   object who = find_living(blah);
   object ob = new(LIB_CORPSE);
   ob->SetCorpse(who);
   ob->SetStrength(2000000);
   ob->SetRace("balrog");
   who->eventPrint("%^RED%^Oops.  You die.%^RESET%^");
   ob->eventMove(environment(who));
   this_player()->eventPrint("Haha.  They died.");
   message("blah",who->GetCapName() + " dies.",environment(who),
           ({ who,this_player() }));
   return 1;
}
