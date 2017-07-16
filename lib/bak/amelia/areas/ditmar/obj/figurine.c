#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("figurine");
   SetShort("an ice figurine");
   SetId( ({ "figurine","ice" }) );
   SetAdjectives( ({ "ice","little" }) );
   SetLong("The little figurine is about an inch high, and its waist is "
           "just a few centimeters thick.  It is shaped like a tiny "
           "mar, only one that stands tall and erect.  Its figure "
           "is marred by a slight melting, but the ice is remarkably "
           "preserved.");
   SetMass(10);
   SetValue(325);
   SetVendorType(VT_TREASURE|VT_MAGIC);
   SetDamagePoints(903);
   SetMaterial( ({ "natural" }) );
   SetClass(4);
   SetWeaponType("blunt");
   SetDamageType(COLD);
   SetProperty("history","The figurine is one of the many carved by "
               "skilled mar artists.  They start with a chunk of "
               "clean ice taken from a glacier so that it is thick "
               "and more solid than other types of ice.  Then, the artist "
               "takes special blessed tools of their Goddess and "
               "starts the delicate process of carving.  Upon "
               "completion, it is offered to the Goddess and a "
               "preservation spell is cast upon it.  The resulting "
               "figuring is usually kept by the artist's family.");
   SetProperty("magic","The figurine has a preservation spell "
               "cast upon it.  The spell seems to have faded some.");
}