#include <lib.h>
inherit LIB_STORAGEBOX;

mixed CanPutInto(object who, object item);
static void create() {
  ::create();
  SetKeyName("bookcase");
  SetId( ({ "bookcase" }) );
  SetAdjectives( ({ "tall" }) );
  SetShort("a tall bookcase");
  SetLong("Reaching nearly to the ceiling, this heavy oaken bookcase "
    "has been provided by the library for the public to donate books. "
    "There doesn't seem to be any security to prevent bibliophile "
    "thieves from stealing everything, however. "
  );
  SetBoxID("mahk_bookcase");
  SetPreventGet("The bookcase seems to be affixed to the ground.");
  SetMass(5000);
  SetMaterial( ({ "wood" }) );
  SetCanClose(0);
  SetMaxCarry(1000000);
  SetOpacity(0);
}

mixed CanGetFrom(object who, object item) {
  if ( member_array("player_book", item->GetId()) != -1 )
  {
    if (item->GetAuthor()
      &&item->GetAuthor() != who->GetKeyName()) {
      who->eventPrint("That book is chained to the bookcase. "
        "Perhaps you should read it instead?");
      return 0;
    }
  }
  return ::CanGetFrom(who,item);
}

mixed CanPutInto(object who, object item) {
    object env;

    if( item == this_object() ) {
        return "#You cannot change the laws of physics.";
    }
    if( member_array("book", item->GetId()) == -1
      && member_array("player_book", item->GetId()) == -1) {
      return capitalize("The library doesn't consider " +
        item->GetShort()) + " an acceptable book.";
    }
    env = environment();
    if( env != this_player() && env != environment(this_player()) ) {
        return "It is not within reach.";
    }
    return ::CanPutInto(who,item);
}

// append internal desc to external desc
//  (it's a bookcase, you don't "look in" it.)
string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
}

